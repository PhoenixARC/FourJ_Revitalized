#pragma once

#include <code/code.h>

#include "Screen.h"

namespace mc {
    class CreateWorldScreen : public Screen {
    public:
		
		CreateWorldScreen(Screen* PreviousScreen)
		{
            code::Func<void, 0x030971F8, CreateWorldScreen*, Screen*>()(this, PreviousScreen);
		}
		CreateWorldScreen(CreateWorldScreen* _this, Screen* PreviousScreen)
		{
            code::Func<void, 0x030971F8, CreateWorldScreen*, Screen*>()(_this, PreviousScreen);
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
		uint32_t field_0x5C;
		uint32_t field_0x60;
    };
};