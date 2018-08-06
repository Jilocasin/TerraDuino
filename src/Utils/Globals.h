/*
 * Globals.h
 *
 *  Created on: 24.06.2017
 *      Author: Jilocasin
 */

#ifndef GLOBALS_H_
#define GLOBALS_H_

#include "ScreenController.h"
#include "UserInputController.h"

class Globals {
public:
	static ScreenController screenController;

	static UserInputController userInputController;

	static void init();

	static void tick();

	static int getFreeMemory() {
		extern unsigned int __bss_end;
		//extern unsigned int __heap_start;
		extern void *__brkval;

		int free_memory;

		if ((int)__brkval == 0) {
			free_memory = ((int) &free_memory) - ((int) &__bss_end);
		} else {
			free_memory = ((int) &free_memory) - ((int) __brkval);
		}

		return free_memory;
	}
};

#define GlobalScreenController (Globals::screenController)

#define GlobalScreen (*GlobalScreenController.getScreen())

#define GlobalInput (Globals::userInputController)

#endif /* GLOBALS_H_ */
