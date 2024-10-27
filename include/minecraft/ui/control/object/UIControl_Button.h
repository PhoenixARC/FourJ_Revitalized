#pragma once

#include <code/code.h>

#include "../UIControl_Base.h"
#include "../util/UIString.h"

namespace mc {
    class UIControl_Button : public UIControl_Base {
    public:
		UIControl_Button()
		{
			code::Func<void, 0x02DBE7B0, UIControl_Button*>()(this);
		}
		UIControl_Button(UIControl_Button* _this)
		{
			code::Func<void, 0x02DBE7B0, UIControl_Button*>()(_this);
		}
		void init(UIString string, int ID)
		{
			code::Func<void, 0x02DBE848, UIControl_Button*, UIString, int>()(this, string, ID);
		}
        uint32_t field_0x5C;
    };
}