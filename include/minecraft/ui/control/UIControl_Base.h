#pragma once

#include <code/code.h>
#include "./util/UIString.h"

#include "UIControl.h"

namespace mc {
    class UIControl_Base : public UIControl {
    public:
		void SetLabel(UIString string, bool flag1, bool flag2)
		{
			code::Func<void, 0x02D8E4E0, UIControl_Base*, UIString, bool, bool>()(this, string, flag1, flag2); 
		}
		wchar_t* GetLabel()
		{
			code::Func<wchar_t*, 0x02dbdd6c, UIControl_Base*>()(this); 
		}
        uint8_t _filler[0xC];
    };
}