/*
 * MemoryDiag.cpp
 *
 *  Created on: 05.07.2017
 *      Author: Jilocasin
 */

#include "../Views/MemoryDiag.h"

#include "Globals.h"
#include "TextUtils.h"

MemoryDiag::MemoryDiag() {
	// TODO Auto-generated constructor stub

}

MemoryDiag::~MemoryDiag() {
	// TODO Auto-generated destructor stub
}

void MemoryDiag::render() {
	Renderable::render();

	int freeMemory = Globals::getFreeMemory();
	float freeMemoryPercentage = freeMemory / 8192.0;

	int filledMemory = 8192 - freeMemory;
	float filledMemoryPercentage = filledMemory / 8192.0;

	GlobalScreen.fillRect(x, y, filledMemoryPercentage * width, height, RED);

	GlobalScreen.fillRect(x + filledMemoryPercentage * width, y, freeMemoryPercentage * width, height, LIGHTGREEN);

	GlobalScreen.drawRect(x, y, width, height, LIGHTGRAY);

	TextUtils::drawTextRightAligned(x + width - 10, y + 2, String(freeMemory) + " bytes free", BLACK);
}
