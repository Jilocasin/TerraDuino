#ifndef SCREENCONTROLLER_H_
#define SCREENCONTROLLER_H_

#include <Adafruit_TFTLCD.h>

#include "ColorUtils.h"
#include "FontLarge.h"
#include "FontSmall.h"

class Activity;

class ScreenController {
private:
	static const uint8_t arraySize = 32;

	Adafruit_TFTLCD* screen;

	Activity* activities[arraySize];

	uint8_t activityCount = 0;

	inline bool hasValidActivity();

	inline uint8_t getCurrentIndex();

	void clearScreen();

public:
	void init();

	void tick();

	Adafruit_TFTLCD* getScreen() {
		return screen;
	}

	String getActivityBreadcrumbs();

	void popActivity();

	void pushActivity(Activity* activity);
};

#endif
