#pragma once

#include <code/code.h>

#include "../../client/resource/wstring.h"
#include "GuiComponent.h"

namespace mc {
    class Button : public GuiComponent {
    public:
        Button(int buttonId, int x, int y, int widthIn,int heightIn, mstd::wstring* buttonText) {
            code::Func<void, 0x0302A4B8, Button*, int, int, int, int, int, mstd::wstring*>()(this, buttonId, x, y, widthIn, heightIn, buttonText);
        }
        void init(int buttonId, int x, int y, int widthIn,int heightIn, mstd::wstring* buttonText) {
            code::Func<void, 0x0302a3b8, Button*, int, int, int, int, int, mstd::wstring*>()(this, buttonId, x, y, widthIn, heightIn, buttonText);
        }
		
		uint32_t widthIn;
		uint32_t heightIn;
		uint32_t x;
		uint32_t y;
		mstd::wstring ButtonText;
		uint32_t buttonId;
		char enabled;
		char visible;
		char hovered;
		char field_0x3B;
		uint32_t VTable;
    };
};