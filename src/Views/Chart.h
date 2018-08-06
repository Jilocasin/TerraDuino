#ifndef CHART_H_
#define CHART_H_

#include "Renderable.h"

class Chart: public Renderable {
public:
	unsigned long getDesiredRenderInterval() {
		return 10000;
	}

	virtual void render() {
		Renderable::render();

		int16_t descriptionWidth = 30;
		int16_t graphWidth = width - descriptionWidth;

		GlobalScreen.fillRect(1, y + 1, width - 2, height - 2, DARKGRAY);

		GlobalScreen.setFont(&SmallFont);

		GlobalScreen.setTextColor(WHITE);

		int16_t axisDescriptionStep = 30;

		for (int16_t axisDescriptionY = axisDescriptionStep; axisDescriptionY < height; axisDescriptionY += axisDescriptionStep) {
			GlobalScreen.setCursor(5, y + axisDescriptionY + 7);

			GlobalScreen.print(15 + (height - axisDescriptionY) / 6);

			drawDottedHLine(descriptionWidth, y + axisDescriptionY, width, GRAY);
		}


		int16_t lastGraphY = 0;

		for (int16_t graphX = 0; graphX < graphWidth - 1; graphX++) {
			int16_t graphY = y + valueForTemperature(graphX);

			if (lastGraphY != 0) {
				GlobalScreen.drawLine(descriptionWidth + graphX, lastGraphY, descriptionWidth + graphX + 1, graphY, ORANGE);
			}

			lastGraphY = graphY;
		}

		lastGraphY = 0;

		for (int16_t graphX = 0; graphX < graphWidth - 1; graphX++) {
			int16_t graphY = y + valueForHumidity(graphX);

			if (lastGraphY != 0) {
				GlobalScreen.drawLine(descriptionWidth + graphX, lastGraphY, descriptionWidth + graphX + 1, graphY, LIGHTBLUE);
			}

			lastGraphY = graphY;
		}

		GlobalScreen.drawRect(0, y, width, height, GRAY);
	}

private:

	int16_t valueForTemperature(const int16_t x) {
		return height / 2 + sin(1.0 * x / 20) * height * 0.45;
	}

	int16_t valueForHumidity(const int16_t x) {
		return height * 0.6 + sin(1.0 * x / 30) * height * 0.2;
	}

	void drawDottedHLine(int16_t x0, int16_t y, int16_t x1, int16_t color) {
		for (int16_t x = x0; x < x1; x += 3) {
			GlobalScreen.writePixel(x, y, color);
		}
	}
};


#endif
