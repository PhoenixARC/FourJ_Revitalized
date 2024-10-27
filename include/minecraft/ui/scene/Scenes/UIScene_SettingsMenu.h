#pragma once

#include "../../control/object/UIControl_Button.h"
#include "../../control/util/UIString.h"
#include "../../../util/VTable_UIScene.h"

namespace mc {
    class UIScene_SettingsMenu : public UIScene {
    public:
		UIScene_SettingsMenu(uint32_t ID ,uint32_t FuncMaybe ,uint32_t layer)
		{
			code::Func<void, 0x02E39FD8, UIScene*, uint32_t, uint32_t>()(this, ID, layer); // UIScene::UIScene
			
			this->vtbl = (VTable_UIScene*)0x10393d08;
			
			mc::UIControl_Button(&this->Button1);
			mc::UIControl_Button(&this->Button2);
			mc::UIControl_Button(&this->Button3);
			mc::UIControl_Button(&this->Button4);
			mc::UIControl_Button(&this->Button5);
			mc::UIControl_Button(&this->Button6);
			mc::UIControl_Button(&this->Button7);
			
			
			this->initialiseMovie();
			mc::Minecraft::getInstance()->field_0x2c = false;
			this->Button1.init(mc::UIString(0xf2f331d5), 0); // game options
			this->Button2.init(mc::UIString(0xe13a424a), 1); // audio
			this->Button5.init(mc::UIString(0xc2b7bf99), 4); // graphics
			this->Button6.init(mc::UIString(0xfddfe517), 5); // user interface
			this->Button7.init(mc::UIString(0x337d5132), 6); // reset to defaults
			//this->Button4.init(mc::UIString(0x7693B9CF), 2); // Debug Settings
			this->removeControl(&this->Button3, 0);
			this->removeControl(&this->Button4, 0);
			
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
		uint32_t field_0x368;
        
    };
}
