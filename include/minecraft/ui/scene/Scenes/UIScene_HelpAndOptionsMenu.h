#pragma once

#include "../../control/object/UIControl_Button.h"
#include "../../control/util/UIString.h"
#include "../../../util/VTable_UIScene.h"

namespace mc {
    class UIScene_HelpAndOptionsMenu : public UIScene {
    public:
		UIScene_HelpAndOptionsMenu(uint32_t ID ,uint32_t FuncMaybe ,uint32_t layer)
		{
			code::Func<void, 0x02E39FD8, UIScene*, uint32_t, uint32_t>()(this, ID, layer); // UIScene::UIScene
			
			this->vtbl = (VTable_UIScene*)0x103853FC;
			
			mc::UIControl_Button(&this->Button1);
			mc::UIControl_Button(&this->Button2);
			mc::UIControl_Button(&this->Button3);
			mc::UIControl_Button(&this->Button4);
			mc::UIControl_Button(&this->Button5);
			mc::UIControl_Button(&this->Button6);
			mc::UIControl_Button(&this->Button7);
			mc::UIControl_Button(&this->Button8);
			
			
			this->initialiseMovie();
			this->Flag = (mc::Minecraft::getInstance()->field_0x2c == false);
			
			this->Button1.init(*(new mc::UIString(0x5268d042)), 0); // game options
			this->Button2.init(*(new mc::UIString(0x15f695fb)), 1); // game options
			this->Button3.init(*(new mc::UIString(0x80fed3f0)), 2); // game options
			this->Button4.init(*(new mc::UIString(0xfccd64b9)), 3); // game options
			this->Button5.init(*(new mc::UIString(0x4e960eb2)), 4); // game options
			this->Button7.init(*(new mc::UIString(0x7693b9cf)), 6); // game options
			
			this->removeControl(&this->Button6, 0);
			this->removeControl(&this->Button8, 0);
			
			this->doHorizontalResizeCheck();
			((ConsoleUIController*)0x104f73e0)->TouchBoxRebuild(this);
		}
		
		static void Log(const wchar_t* text)
		{
			code::Func<void, 0x0382F6B8, const char*, const wchar_t*>()("%ls\n", text);
		}
		
		
		UIControl_Button Button1;
		UIControl_Button Button2;
		UIControl_Button Button3;
		UIControl_Button Button4;
		UIControl_Button Button5;
		UIControl_Button Button6;
		UIControl_Button Button7;
		UIControl_Button Button8;
		uint32_t Flag;
        
    };
}
