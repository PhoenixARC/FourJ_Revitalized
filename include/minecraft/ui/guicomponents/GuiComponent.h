#pragma once

#include <code/code.h>

#include "../../client/resource/wstring.h"

namespace mc {
    class GuiComponent {
    public:
        GuiComponent() {
            code::Func<void, 0x031341a4, GuiComponent*>()(this);
        }
		
		void drawCenteredString(struct Font* font, const mstd::wstring& string, int x, int y, int size)
		{
		}
		
		uint32_t field_0x0;
    };
};