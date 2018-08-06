/*
 * TextUtils.h
 *
 *  Created on: 21.06.2017
 *      Author: Jilocasin
 */

#ifndef TEXTUTILS_H_
#define TEXTUTILS_H_

#include "ScreenController.h"

class TextUtils {
public:
	static void drawTextLeftAligned(uint16_t x, uint16_t y, String text, int textColor) {
		int16_t textX, textY;
		uint16_t textWidth, textHeight;

		GlobalScreen.getTextBounds((char*) text.c_str(), 0, 0, &textX, &textY, &textWidth, &textHeight);

		GlobalScreen.setCursor(x, y + textHeight);

		GlobalScreen.setTextColor(textColor);

		GlobalScreen.print(text);
	}

	static void drawTextRightAligned(uint16_t x, uint16_t y, String text, int textColor) {
			int16_t textX, textY;
			uint16_t textWidth, textHeight;

			GlobalScreen.getTextBounds((char*) text.c_str(), 0, 0, &textX, &textY, &textWidth, &textHeight);

			GlobalScreen.setCursor(x - textWidth, y + textHeight);

			GlobalScreen.setTextColor(textColor);

			GlobalScreen.print(text);
		}

	static void drawTextCenterAligned(uint16_t x, uint16_t y, String text, int textColor) {
		int16_t textX, textY;
		uint16_t textWidth, textHeight;

		GlobalScreen.getTextBounds((char*) text.c_str(), 0, 0, &textX, &textY, &textWidth, &textHeight);

		GlobalScreen.setCursor(x - (textWidth / 2), y + textHeight);

		GlobalScreen.setTextColor(textColor);

		GlobalScreen.print(text);
	}

	static void drawTextLeftAlignedOpaque(uint16_t x, uint16_t y, String text, int textColor, int backgroundColor) {
			int16_t textX, textY;
			uint16_t textWidth, textHeight;

			GlobalScreen.getTextBounds((char*) text.c_str(), 0, 0, &textX, &textY, &textWidth, &textHeight);

			GlobalScreen.setCursor(x, y + textHeight);

			GlobalScreen.setTextColor(textColor);

			GlobalScreen.fillRect(x, y, textWidth, textHeight, backgroundColor);

			GlobalScreen.print(text);
		}

		static void drawTextRightAlignedOpaque(uint16_t x, uint16_t y, String text, int textColor, int backgroundColor) {
				int16_t textX, textY;
				uint16_t textWidth, textHeight;

				GlobalScreen.getTextBounds((char*) text.c_str(), 0, 0, &textX, &textY, &textWidth, &textHeight);

				GlobalScreen.setCursor(x - textWidth, y + textHeight);

				GlobalScreen.setTextColor(textColor);

				GlobalScreen.fillRect(x - textWidth, y, textWidth, textHeight, backgroundColor);

				GlobalScreen.print(text);
			}

		static void drawTextCenterAlignedOpaque(uint16_t x, uint16_t y, String text, int textColor, int backgroundColor) {
			int16_t textX, textY;
			uint16_t textWidth, textHeight;

			GlobalScreen.getTextBounds((char*) text.c_str(), 0, 0, &textX, &textY, &textWidth, &textHeight);

			GlobalScreen.setCursor(x - (textWidth / 2), y + textHeight);

			GlobalScreen.setTextColor(textColor);

			GlobalScreen.fillRect(x - (textWidth / 2), y, textWidth, textHeight, backgroundColor);

			GlobalScreen.print(text);
		}
};



#endif /* TEXTUTILS_H_ */
