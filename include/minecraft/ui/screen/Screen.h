#pragma once

#include <code/code.h>


namespace mc {
    class Screen {
    public:
		
		Screen()
		{
            code::Func<void, 0x03263BC8, Screen*>()(this);
		}
		Screen(Screen* _this)
		{
            code::Func<void, 0x03263BC8, Screen*>()(_this);
		}
		
		uint32_t field_0x0;
		uint32_t field_0x4;
		uint32_t field_0x8;
		uint32_t field_0xC;
		uint32_t vector__Button;
		uint32_t field_0x14;
		uint32_t field_0x18;
		uint32_t field_0x1C;
		uint32_t field_0x20;
		uint32_t field_0x24;
		uint32_t field_0x28;
		uint32_t field_0x2C;
		struct VTable_Screen* VTable;
    };
};