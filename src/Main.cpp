/*
 * Main.cpp
 *
 *  Created on: 22.06.2017
 *      Author: Jilocasin
 */

#include "Arduino.h"
#include "Globals.h"
#include <NewTime.h>

#include <Adafruit_TFTLCD.h>

void setup() {
	Serial.begin(9600);

	setTime(19, 59, 55, 20, 6, 2017);

	Globals::init();
}

void loop() {
	Globals::tick();
}
