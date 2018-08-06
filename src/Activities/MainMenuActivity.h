/*
 * MainMenuActivity.h
 *
 *  Created on: 24.06.2017
 *      Author: Jilocasin
 */

#ifndef MAINMENUACTIVITY_H_
#define MAINMENUACTIVITY_H_

#include "../Activities/MenuActivity.h"

class MainMenuActivity: public MenuActivity {
public:
	virtual ~MainMenuActivity() {};

	virtual void init();

	virtual bool isShownInBreadcrumbs();

	virtual String getActivityName();

	// Menu item delegate.

	uint8_t getMenuItemCount();

	String getMenuItemTitle(const uint8_t position);

	void didClickMenuItem(const uint8_t position);
};

#endif /* MAINMENUACTIVITY_H_ */
