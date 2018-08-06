#ifndef TIMEHEADER_H_
#define TIMEHEADERVIEW_H_

#include <NewTime.h>

#include "Renderable.h"
#include "TextUtils.h"

class TimeHeaderView: public Renderable {
public:
	virtual unsigned long getDesiredRenderInterval() {
		return 60000;
	}

	virtual void render() {
		Renderable::render();

		Renderable::clear(BLACK);

		drawClock();

		drawDayPercentageBar();
	}

private:
	void drawClock() {
		const int topMargin = 25;

		GlobalScreen.setFont(&LargeFont);

		time_t now_ = now();

		String hourString = String(hour(now_));
		String minuteString = String(minute(now_));

		String timeString = (hourString.length() == 1 ? "0" : "") + hourString
				+ ":" + (minuteString.length() == 1 ? "0" : "") + minuteString;

		TextUtils::drawTextCenterAligned(width / 2, topMargin, timeString, WHITE);
	}

	const int barBottomMargin = 25;
	const int totalBarWidth = 150;
	const int barHeight = 10;

	void drawDayPercentageBar() {
		int16_t highlightedBarWidth = 0.25 * totalBarWidth;
		int16_t barX = GlobalScreen.width() / 2 - totalBarWidth / 2;

		GlobalScreen.fillRect(
				barX,
				height - barBottomMargin - barHeight,
				highlightedBarWidth,
				barHeight,
				LIGHTGRAY
		);

		GlobalScreen.fillRect(
				barX + highlightedBarWidth,
				height - barBottomMargin - barHeight,
				totalBarWidth - highlightedBarWidth,
				barHeight,
				DARKGRAY
		);

		GlobalScreen.drawRect(
				barX,
				height - barBottomMargin - barHeight,
				totalBarWidth,
				barHeight,
				GRAY
		);

		drawDayPercentageBarTimes();
	}

	const int barTimesMargin = 15;

	void drawDayPercentageBarTimes() {
		int16_t barX = GlobalScreen.width() / 2 - totalBarWidth / 2;

		GlobalScreen.setFont(&SmallFont);

		TextUtils::drawTextRightAligned(barX - barTimesMargin, y + height - barBottomMargin - barHeight, "7:45", LIGHTGRAY);

		TextUtils::drawTextLeftAligned(barX + totalBarWidth + barTimesMargin, y + height - barBottomMargin - barHeight, "21:15", LIGHTGRAY);
	}
};

#endif
