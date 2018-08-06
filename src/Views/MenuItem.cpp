/*
 * MenuItem.cpp
 *
 *  Created on: 24.06.2017
 *      Author: Jilocasin
 */

#include "MenuItem.h"
#include "TextUtils.h"

MenuItem::MenuItem(String name) :
	name(name)
{
	// TODO Auto-generated constructor stub

}

MenuItem::~MenuItem() {
	// TODO Auto-generated destructor stub
}

void MenuItem::render() {
	Renderable::render();

	switch (isSelected) {
	case true:
		GlobalScreen.fillRoundRect(x, y, width, height, 8, LIGHTGRAY);

		GlobalScreen.drawRoundRect(x, y, width, height, 8, WHITE);

		GlobalScreen.setFont(&SmallFont);

		TextUtils::drawTextCenterAligned(x + width / 2, y + height / 2 - 5, name, BLACK);

		break;

	case false:
		GlobalScreen.fillRoundRect(x, y, width, height, 8, BLACK);

		GlobalScreen.drawRoundRect(x, y, width, height, 8, GRAY);

		GlobalScreen.setFont(&SmallFont);

		TextUtils::drawTextCenterAligned(x + width / 2, y + height / 2 - 5, name, WHITE);

		break;
	}
}
