/*
 * Breadcrumbs.cpp
 *
 *  Created on: 05.07.2017
 *      Author: Jilocasin
 */

#include <BreadcrumbsView.h>
#include "TextUtils.h"

Breadcrumbs::Breadcrumbs() {
	// TODO Auto-generated constructor stub

}

Breadcrumbs::~Breadcrumbs() {
	// TODO Auto-generated destructor stub
}

void Breadcrumbs::render() {
	Renderable::render();

	Renderable::clear(BLACK);

	//GlobalScreen.setFont(&SmallFont);

	TextUtils::drawTextLeftAligned(x, y, GlobalScreenController.getActivityBreadcrumbs(), LIGHTGRAY);
}
