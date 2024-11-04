#pragma once

#include <code/code.h>

#include "Screen.h"
#include "../../client/app/Options.h"

namespace mc {
    class OptionsScreen : public Screen {
    public:
		
		OptionsScreen(Screen* PreviousScreen, Options* opt)
		{
            code::Func<void, 0x03264558, OptionsScreen*, Screen*, Options*>()(this, PreviousScreen, opt);
		}
		OptionsScreen(OptionsScreen* _this, Screen* PreviousScreen, Options* opt)
		{
            code::Func<void, 0x03264558, OptionsScreen*, Screen*, Options*>()(_this, PreviousScreen, opt);
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