/*
 * DashboardActivity.h
 *
 *  Created on: 24.06.2017
 *      Author: Jilocasin
 */

#ifndef DASHBOARDACTIVITY_H_
#define DASHBOARDACTIVITY_H_

#include "../Activities/Activity.h"

class DashboardActivity: public Activity {
public:
	virtual ~DashboardActivity() {};

	virtual void init();

	virtual bool isShownInBreadcrumbs();

	virtual String getActivityName();

	void didPressButton();

	void didRotateLeft();

	void didRotateRight();
};

#endif /* DASHBOARDACTIVITY_H_ */
