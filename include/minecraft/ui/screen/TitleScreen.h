#pragma once

#include <code/code.h>

#include "Screen.h"

namespace mc {
    class TitleScreen : public Screen {
    public:
		
		TitleScreen()
		{
            code::Func<void, 0x033A22C0, TitleScreen*>()(this);
		}
		TitleScreen(TitleScreen* _this)
		{
            code::Func<void, 0x033A22C0, TitleScreen*>()(_this);
		}
		
		uint32_t field_0x34;
		uint32_t field_0x38;
		uint32_t field_0x3C;
		uint32_t field_0x40;
		uint32_t field_0x44;
		uint32_t field_0x48;
		uint32_t field_0x4C;
		uint32_t field_0x50;
		uint32_t field_0x54;
		uint32_t field_0x58;
    };
};