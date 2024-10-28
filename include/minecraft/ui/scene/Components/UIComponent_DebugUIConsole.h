#pragma once

#include "../../control/object/UIControl_Label.h"
#include "../../control/util/UIString.h"
#include "../../../util/VTable_UIScene.h"

namespace mc {
    class UIComponent_DebugUIConsole : public UIScene {
    public:
		
		static void Log(const wchar_t* text)
		{
			code::Func<void, 0x0382F6B8, const char*, const wchar_t*>()("%ls\n", text);
		}
		
		void InitConsoleLines()
		{
			this->ConsoleLine1.SetLabel(*(new UIString(L"............")),  false, false);
			this->ConsoleLine2.SetLabel(*(new UIString(L"............")),  false, false);
			this->ConsoleLine3.SetLabel(*(new UIString(L"............")),  false, false);
			this->ConsoleLine4.SetLabel(*(new UIString(L"............")),  false, false);
			this->ConsoleLine5.SetLabel(*(new UIString(L"............")),  false, false);
			this->ConsoleLine6.SetLabel(*(new UIString(L"............")),  false, false);
			this->ConsoleLine7.SetLabel(*(new UIString(L"............")),  false, false);
			this->ConsoleLine8.SetLabel(*(new UIString(L"............")),  false, false);
			this->ConsoleLine9.SetLabel(*(new UIString(L"............")),  false, false);
			this->ConsoleLine10.SetLabel(*(new UIString(L"............")),  false, false);
		}
		
		void AddToConsole(wchar_t* Message)
		{
			this->ConsoleLine1.SetLabel(*(new UIString(this->ConsoleLine2.GetLabel())),  false, false);
			this->ConsoleLine2.SetLabel(*(new UIString(this->ConsoleLine3.GetLabel())),  false, false);
			this->ConsoleLine3.SetLabel(*(new UIString(this->ConsoleLine4.GetLabel())),  false, false);
			this->ConsoleLine4.SetLabel(*(new UIString(this->ConsoleLine5.GetLabel())),  false, false);
			this->ConsoleLine5.SetLabel(*(new UIString(this->ConsoleLine6.GetLabel())),  false, false);
			this->ConsoleLine6.SetLabel(*(new UIString(this->ConsoleLine7.GetLabel())),  false, false);
			this->ConsoleLine7.SetLabel(*(new UIString(this->ConsoleLine8.GetLabel())),  false, false);
			this->ConsoleLine8.SetLabel(*(new UIString(this->ConsoleLine9.GetLabel())),  false, false);
			this->ConsoleLine9.SetLabel(*(new UIString(this->ConsoleLine10.GetLabel())), false, false);
			this->ConsoleLine10.SetLabel(*(new UIString(Message)), 						 false, false);
		}
		
		
		UIControl_Label ConsoleLine1;
		UIControl_Label ConsoleLine2;
		UIControl_Label ConsoleLine3;
		UIControl_Label ConsoleLine4;
		UIControl_Label ConsoleLine5;
		UIControl_Label ConsoleLine6;
		UIControl_Label ConsoleLine7;
		UIControl_Label ConsoleLine8;
		UIControl_Label ConsoleLine9;
		UIControl_Label ConsoleLine10;
        
    };
}
