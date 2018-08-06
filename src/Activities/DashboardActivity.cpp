/*
 * DashboardActivity.cpp
 *
 *  Created on: 24.06.2017
 *      Author: Jilocasin
 */

#include <TimeHeaderViewView.h>
#include "../Activities/DashboardActivity.h"

#include "../Activities/MainMenuActivity.h"
#include "Chart.h"

void DashboardActivity::didPressButton() {
	GlobalScreenController.pushActivity(new MainMenuActivity());
}

void DashboardActivity::didRotateLeft() {
	// Turning the knob does nothing in the dashboard.
}

void DashboardActivity::didRotateRight(){
	// Turning the knob does nothing in the dashboard.
}

void DashboardActivity::init() {
	// Add the time header.

	TimeHeaderView* timeHeader = new TimeHeaderView();

	timeHeader->setBounds(0, 0, GlobalScreen.width(), 120);

	addRenderable(timeHeader);

	// Add a dummy chart.

	Chart* chart = new Chart();

	chart->setBounds(0, 120, GlobalScreen.width(), 120);

	addRenderable(chart);
}

bool DashboardActivity::isShownInBreadcrumbs() {
	return false;
}

String DashboardActivity::getActivityName() {
	return F("Dashboard");
}
