/*
 * MenuActivity.h
 *
 *  Created on: 05.07.2017
 *      Author: Jilocasin
 */

#ifndef MENUACTIVITY_H_
#define MENUACTIVITY_H_

#include <BreadcrumbsView.h>
#include "../Activities/Activity.h"
#include "../Activities/DashboardActivity.h"
#include "MenuItem.h"
#include "MemoryDiag.h"

class MenuActivity: public Activity, MenuActivityDelegate {
private:
	static const uint8_t arraySize = 32;

	MenuItem* items[arraySize];

	uint8_t selectedItemIndex = 0;

	uint8_t itemCount = 0;

	/*
	 * Appends a new menu item to the bottom of the item list, setting its position and size accordingly.
	 */
	void appendMenuItem(MenuItem* newItem) {
		if (itemCount >= arraySize) {
			Serial.print("Unable to add menu item because the array size ");
			Serial.print(arraySize);
			Serial.println(" is exhausted");

			return;
		}

		newItem->setBounds(20, 50 + itemCount * 40, GlobalScreen.width() - 40, 30);

		addRenderable(newItem);

		items[itemCount] = newItem;

		itemCount++;
	}

public:
	virtual ~MenuActivity() {};

	virtual void init() {
		// Always create breadcrumbs inside a menu activity.

		Breadcrumbs* breadcrumbs = new Breadcrumbs();

		breadcrumbs->setBounds(20, 15, GlobalScreen.width() - 20, 20);

		addRenderable(breadcrumbs);

		// Always create a MemoryDiag at the bottom for debugging purposes.

		MemoryDiag* memoryDiag = new MemoryDiag();

		memoryDiag->setBounds(20, GlobalScreen.height() - 40, GlobalScreen.width() - 40, 20);

		addRenderable(memoryDiag);

		// Always create a preselected back item at the first position.

		MenuItem* item = new MenuItem(F("Back"));

		item->isSelected = true;

		appendMenuItem(item);

		// Append all buttons from the own subclass.

		for (uint8_t i = 0; i < getMenuItemCount(); i++) {
			item = new MenuItem(getMenuItemTitle(i));

			appendMenuItem(item);
		}
	}

	void didPressButton() {
		if (selectedItemIndex == 0) {
			// Return to the previous screen.

			GlobalScreenController.popActivity();
		} else {
			didClickMenuItem(selectedItemIndex - 1);
		}
	}

	void didRotateLeft() {
		if (itemCount < 2) {
			// No need to change selection if we have less than 2 items anyway.

			return;
		}

		// Deselect and render old item.

		items[selectedItemIndex]->isSelected = false;

		items[selectedItemIndex]->renderNow();

		// Increase or reset index.

		if (selectedItemIndex == 0) {
			selectedItemIndex = itemCount - 1;
		} else {
			selectedItemIndex--;
		}

		// Select and render new item.

		items[selectedItemIndex]->isSelected = true;

		items[selectedItemIndex]->renderNow();
	}

	void didRotateRight() {
		if (itemCount < 2) {
			// No need to change selection if we have less than 2 items anyway.

			return;
		}

		// Deselect and render old item.

		items[selectedItemIndex]->isSelected = false;

		items[selectedItemIndex]->renderNow();

		// Increase or reset index.

		if (selectedItemIndex == itemCount - 1) {
			selectedItemIndex = 0;
		} else {
			selectedItemIndex++;
		}

		// Select and render new item.

		items[selectedItemIndex]->isSelected = true;

		items[selectedItemIndex]->renderNow();
	}
};

#endif /* MENUACTIVITY_H_ */
