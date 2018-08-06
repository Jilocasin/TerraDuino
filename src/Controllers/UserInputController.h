/*
 * EncoderController.h
 *
 *  Created on: 22.06.2017
 *      Author: Jilocasin
 */

#ifndef USERINPUTCONTROLLER_H_
#define USERINPUTCONTROLLER_H_

#include <Encoder.h>

class InputReceiver;

class UserInputController {
private:
	static const uint8_t pinEncoder1 = 18;//19;
	static const uint8_t pinEncoder2 = 17;//18;
	static const uint8_t pinButton = 19;//20;

	Encoder* encoder;

	InputReceiver* currentInputReceiver;

	static void buttonInterruptCallback();

	bool isButtonEventScheduled = false;

	int32_t lastEncoderTick = 0;

public:
	void init();

	void tick();

	void setReceiver(InputReceiver* inputReceiver);
};

#endif /* USERINPUTCONTROLLER_H_ */
