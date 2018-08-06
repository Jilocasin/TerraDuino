#include "ScreenController.h"

#include "DashboardActivity.h"
#include "Globals.h"

bool ScreenController::hasValidActivity() {
	return activityCount != 0;
}

uint8_t ScreenController::getCurrentIndex() {
	return activityCount - 1;
}

void ScreenController::clearScreen() {
	GlobalScreen.fillScreen(BLACK);
}

void ScreenController::init() {
	const uint8_t LCD_CS    = A3; // Chip Select
	const uint8_t LCD_CD    = A2; // Command/Data
	const uint8_t LCD_WR    = A1; // LCD Write
	const uint8_t LCD_RD    = A0; // LCD Read
	const uint8_t LCD_RESET = A4;

	screen = new Adafruit_TFTLCD(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

	screen->reset();

	screen->begin(0x9481);

	// Create the default dashboard screen when initializing a new screen controller.

	GlobalScreenController.pushActivity(new DashboardActivity());
}

void ScreenController::tick() {
	if (!hasValidActivity()) {
		return;
	}

	activities[getCurrentIndex()]->renderElementsIfNeeded();
}

String ScreenController::getActivityBreadcrumbs() {
	String result;

	for (uint8_t i = 0; i < activityCount; i++) {
		if (activities[i]->isShownInBreadcrumbs()) {
			if (result.length() != 0) {
				result += F(" > ");
			}

			result += activities[i]->getActivityName();
		}
	}

	return result;
}

/**
 * Pops the topmost screen view from the stack, deleting it.
 * It is replaced by the previous screen view with the global input receiver set to it.
 */
void ScreenController::popActivity() {
	if (!hasValidActivity()) {
		return;
	}

	delete activities[getCurrentIndex()];

	activities[getCurrentIndex()] = NULL;

	activityCount--;

	if (!hasValidActivity()) {
		// No screen view left to show. Clear the input receiver.

		GlobalInput.setReceiver(NULL);

		return;
	}

	GlobalInput.setReceiver(activities[getCurrentIndex()]);

	clearScreen();

	activities[getCurrentIndex()]->renderElementsNow();
}

/**
 * Pushes the given screen view to the stack, replacing the current one
 * and setting the global input receiver to it.
 */
void ScreenController::pushActivity(Activity* activity) {
	if (activityCount >= arraySize) {
		Serial.print("Unable to add screen view because the array size ");
		Serial.print(arraySize);
		Serial.println(" is exhausted");

		return;
	}

	clearScreen();

	activities[activityCount] = activity;

	activityCount++;

	activity->init();

	activity->renderElementsNow();

	GlobalInput.setReceiver(activity);
}
