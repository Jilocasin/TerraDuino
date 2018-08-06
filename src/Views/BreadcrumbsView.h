/*
 * Breadcrumbs.h
 *
 *  Created on: 05.07.2017
 *      Author: Jilocasin
 */

#ifndef BREADCRUMBS_H_
#define BREADCRUMBS_H_

#include "Renderable.h"

class Breadcrumbs: public Renderable {
public:
	Breadcrumbs();

	virtual ~Breadcrumbs();

	virtual void render();
};

#endif /* BREADCRUMBS_H_ */
