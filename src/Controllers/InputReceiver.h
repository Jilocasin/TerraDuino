/*
 * InputReceiver.h
 *
 *  Created on: 24.06.2017
 *      Author: Jilocasin
 */

#ifndef INPUTRECEIVER_H_
#define INPUTRECEIVER_H_

class InputReceiver {
public:
	virtual ~InputReceiver() {};

	virtual void didPressButton() = 0;

	virtual void didRotateLeft() = 0;

	virtual void didRotateRight() = 0;
};

#endif /* INPUTRECEIVER_H_ */
