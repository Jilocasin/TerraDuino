/*
 * MainMenuActivity.cpp
 *
 *  Created on: 24.06.2017
 *      Author: Jilocasin
 */

#include "../Activities/MainMenuActivity.h"

#include "MenuItem.h"

void MainMenuActivity::init() {
	MenuActivity::init();
}

bool MainMenuActivity::isShownInBreadcrumbs() {
	return true;
}

String MainMenuActivity::getActivityName() {
	return F("Menu");
}

uint8_t MainMenuActivity::getMenuItemCount() {
	return 2;
}

String MainMenuActivity::getMenuItemTitle(const uint8_t position) {
	switch (position) {
	case 0:
		return F("Settings");

	case 1:
		return F("Something else");
	}

	return "";
}

void MainMenuActivity::didClickMenuItem(const uint8_t position) {
	GlobalScreenController.pushActivity(new MainMenuActivity());
}
