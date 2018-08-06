/*
 * MemoryDiag.h
 *
 *  Created on: 05.07.2017
 *      Author: Jilocasin
 */

#ifndef MEMORYDIAG_H_
#define MEMORYDIAG_H_

#include "Renderable.h"

class MemoryDiag: public Renderable {
public:
	MemoryDiag();

	virtual ~MemoryDiag();

	void render();
};

#endif /* MEMORYDIAG_H_ */
