#ifndef RENDERABLE_H_
#define RENDERABLE_H_

#include "Globals.h"

class Renderable {
private:
	unsigned long lastRenderTimestamp = 0;

protected:
	static const int8_t RENDER_INTERVAL_ONCE = 0;
	static const int8_t RENDER_INTERVAL_ALWAYS = 1;

	int16_t x = 0;
	int16_t y = 0;
	int16_t width = 0;
	int16_t height = 0;

	/**
	 * Fills the whole render area with the given background color.
	 */
	void clear(int backgroundColor) {
		GlobalScreen.fillRect(x, y, width, height, backgroundColor);
	};

	/**
	 * Performs all rendering operations on screen.
	 * Always make sure to call this superclass function in subclasses.
	 */
	virtual void render() {
		lastRenderTimestamp = millis();
	}

public:
	virtual ~Renderable() {}

	void setPosition(int16_t x, int16_t y) {
		this->x = x;
		this->y = y;
	}

	void setSize(int16_t width, int16_t height) {
		this->width = width;
		this->height = height;
	}

	void setBounds(int16_t x, int16_t y, int16_t width, int16_t height) {
		this->x = x;
		this->y = y;
		this->width = width;
		this->height = height;
	}

	/**
	 * Renders this object if it decides that it needs to be redrawn.
	 */
	virtual void renderIfNeeded() {
		if (isRenderRequired()) {
			render();
		}
	}

	/**
	 * Always renders this object.
	 */
	virtual void renderNow() {
		render();
	}

	/**
	 * You may use this function to return the milliseconds between two render calls
	 * or override isRenderRequired to have a more precise control over the render behavior.
	 */
	virtual unsigned long getDesiredRenderInterval() {
		return RENDER_INTERVAL_ONCE;
	}

	/**
	 * You may override this function to directly control the render process instead of using the fixed interval behavior.
	 */
	virtual bool isRenderRequired() {
		unsigned long desiredRenderInterval = getDesiredRenderInterval();

		// Always render initially or if an interval is provided.

		return (lastRenderTimestamp == 0) ||
				(desiredRenderInterval != RENDER_INTERVAL_ONCE && (millis() - lastRenderTimestamp >= desiredRenderInterval));
	}
};

#endif /* RENDERABLE_H_ */
