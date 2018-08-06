/*
 * MenuItem.h
 *
 *  Created on: 24.06.2017
 *      Author: Jilocasin
 */

#ifndef MENUITEM_H_
#define MENUITEM_H_

#include "Renderable.h"

class MenuItem;

class MenuActivityDelegate {
public:
	virtual ~MenuActivityDelegate() {};

	virtual uint8_t getMenuItemCount() = 0;

	virtual String getMenuItemTitle(const uint8_t position) = 0;

	virtual void didClickMenuItem(const uint8_t position) = 0;
};

class MenuItem: public Renderable {
private:
	String name;

public:
	MenuItem(String name);

	virtual ~MenuItem();

	virtual void render();

	boolean isSelected = false;
};

#endif /* MENUITEM_H_ */
