/*
 * UserInputController.cpp
 *
 *  Created on: 22.06.2017
 *      Author: Jilocasin
 */

#include "UserInputController.h"
#include "InputReceiver.h"
#include "Globals.h"

void UserInputController::init() {
	// Unfortunately we can't attach an interrupt to a class instance function.

	// We need to define a static class function and call the
	// appropriate callback of the global UserInputController instance.

	// This defeats the purpose of having a class, but there's currently no other way
	// and we are using a singleton-like structure for the controller anyway.

	pinMode(pinButton, INPUT_PULLUP);

	attachInterrupt(digitalPinToInterrupt(pinButton), buttonInterruptCallback, FALLING);

	encoder = new Encoder(pinEncoder1, pinEncoder2);
}

void UserInputController::tick() {
	// Examine and reset button status.

	if (isButtonEventScheduled) {
		if (currentInputReceiver) {
			currentInputReceiver->didPressButton();
		}

		isButtonEventScheduled = false;
	}

	// Examine encoder.

	int32_t currentEncoderTick = encoder->read() / 4;

	if (currentEncoderTick != lastEncoderTick) {
		lastEncoderTick = 0;

		encoder->write(0);

		while (currentEncoderTick < 0) {
			if (currentInputReceiver) {
				currentInputReceiver->didRotateLeft();
			}

			currentEncoderTick++;
		}

		while (currentEncoderTick > 0) {
			if (currentInputReceiver) {
				currentInputReceiver->didRotateRight();
			}

			currentEncoderTick--;
		}
	}
}

void UserInputController::buttonInterruptCallback() {
	Globals::userInputController.isButtonEventScheduled = true;
}

void UserInputController::setReceiver(InputReceiver* inputReceiver) {
	currentInputReceiver = inputReceiver;
}
