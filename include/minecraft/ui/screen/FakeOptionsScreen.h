#pragma once

#include <code/code.h>

#include "Screen.h"
#include "../../client/app/Options.h"
#include "../../util/VTable_Screen.h"
#include "../guicomponents/Button.h"

namespace mc {
    class FakeOptionsScreen : public Screen {
    public:
		
		FakeOptionsScreen(Screen* PreviousScreen, Options* opt)
		{
            //code::Func<void, 0x03263bc8, FakeOptionsScreen*>()(this); // Screen::Screen
			Screen(this);
			
			VTable_Screen* FakeOptionsScreenVtbl = new VTable_Screen;
			memcpy(FakeOptionsScreenVtbl, (VTable_Screen*)0x1041cb24, sizeof(VTable_Screen));
			//FakeOptionsScreenVtbl->init = 	&init;
			
			this->VTable = FakeOptionsScreenVtbl;
			
			this->MenuTitle = *(new mstd::wstring(L""));
			
			this->MenuTitle.assign(L"Options", 7);
			this->PreviousMenu = PreviousScreen;
			this->gameOptions = opt;
		}
		
		static void init(Screen* _this) {
			Button* button1 = new Button(5, 200, 100, 150, 0x14, new mstd::wstring(L"This is a String"));
			
			code::Func<void, 0x032644CC, uint32_t*, Button**>()(&_this->vector__Button, &button1);
		}
		
		static void Log(const wchar_t* text)
		{
			code::Func<void, 0x0382F6B8, const char*, const wchar_t*>()("%ls\n", text);
		}
		
		Screen* PreviousMenu;
		mstd::wstring MenuTitle;
		Options* gameOptions;
    };
};