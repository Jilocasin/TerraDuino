/*
 * Activity.h
 *
 *  Created on: 24.06.2017
 *      Author: Jilocasin
 */

#ifndef ACTIVITY_H_
#define ACTIVITY_H_

#include "Renderable.h"
#include "InputReceiver.h"

class Activity: public InputReceiver {
private:
	static const uint8_t arraySize = 32;

	Renderable* renderables[arraySize];

	uint8_t renderableCount = 0;

public:
	virtual ~Activity() {
		for (unsigned int i = 0; i < arraySize; i++) {
			if (renderables[i]) {
				delete renderables[i];
			}
		}
	}

	virtual void init() = 0;

	virtual bool isShownInBreadcrumbs() = 0;

	virtual String getActivityName() = 0;

	void addRenderable(Renderable* renderable) {
		if (renderableCount >= arraySize) {
			Serial.print("Unable to add renderable because the array size ");
			Serial.print(arraySize);
			Serial.println(" is exhausted");

			return;
		}

		renderables[renderableCount] = renderable;

		renderableCount++;
	}

	void renderElementsNow() {
		for (unsigned int i = 0; i < renderableCount; i++) {
			renderables[i]->renderNow();
		}
	}

	void renderElementsIfNeeded() {
		for (unsigned int i = 0; i < renderableCount; i++) {
			renderables[i]->renderIfNeeded();
		}
	}
};

#endif
