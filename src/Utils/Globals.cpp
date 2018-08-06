/*
 * Globals.cpp
 *
 *  Created on: 24.06.2017
 *      Author: Jilocasin
 */

#include "Globals.h"

void Globals::init() {
	Globals::screenController.init();

	Globals::userInputController.init();
}

void Globals::tick() {
	Globals::screenController.tick();

	Globals::userInputController.tick();
}

UserInputController Globals::userInputController = UserInputController();

ScreenController Globals::screenController = ScreenController();
