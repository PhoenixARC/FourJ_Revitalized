#pragma once

#include "../../control/object/UIControl_MultiList.h"
#include "../../control/object/UIControl_ButtonList.h"
#include "../../control/object/UIControl_CheckboxButtonList.h"
#include "../../../util/VTable_UIScene.h"
#include "../../layer/UILayer.h"

namespace mc {
    class UIScene_DebugMenu : public UIScene {
    public:
		UIScene_DebugMenu(uint32_t ID ,uint32_t FuncMaybe ,uint32_t layer)
		{
			code::Func<void, 0x02E39FD8, UIScene*, uint32_t, uint32_t>()(this, ID, layer); // UIScene::UIScene
			
			VTable_UIScene* DebugUIVtbl = new VTable_UIScene;
			memcpy(DebugUIVtbl, (VTable_UIScene*)0x1038574c, sizeof(VTable_UIScene));
			DebugUIVtbl->mapElementsAndNames = 	&mapElementsAndNames;
			DebugUIVtbl->getMoviePath = 		&getMoviePath;
			DebugUIVtbl->handleCheckboxElementToggled = 		&HandleCheckboxElementToggled;
			
			this->vtbl = DebugUIVtbl;
			
			UIControl_MultiList(&this->HowToList);
			this->initialiseMovie();
			mc::GameSettings* settings = (mc::GameSettings*)mc::GameSettings::GetGameSettingsDebugMask(0xFFABCD00, 0);
			
			int i = 0;
			for(mc::DebugSetting* setting : settings->debugSettings)
			{
				if(setting->Type == mc::DebugSetting::eSettingType::BOOL) {
					this->HowToList.AddNewCheckbox(*(new mstd::wstring((setting->SettingName))), i, (bool)setting->Value);
				}
				i++;
			}
			
			this->doHorizontalResizeCheck();
			this->field_0x17C = 0;
			((ConsoleUIController*)0x104f73e0)->TouchBoxRebuild(this);
		}
		
		static void getMoviePath(UIScene* scene, mstd::wstring& string)
		{
			string.str[0] =  0;
			string.length2 = 7;
			string.length =  0;
			string.assign(L"DebugOptionsMenu", 16);
		}
		
		static int getSceneType(UIScene* scene)
		{
			return 0xD;
		}
		
		static bool mapElementsAndNames(UIScene* scene)
		{
			uint32_t fuiRoot = code::Func<uint32_t, 0x02ba8144, uint32_t>()(scene->fuiFile); // fuiFile::getRootNode
			
			mstd::wstring* HowToPlayStr = new mstd::wstring(L"");
			HowToPlayStr->assign("DebugOptionsList", 16);
			
			((UIScene_DebugMenu*)scene)->HowToList.setupControl(scene, fuiRoot, HowToPlayStr);
			
			UIControl_MultiList* ControlPTR = &((UIScene_DebugMenu*)scene)->HowToList;
			
			code::Func<void, 0x02e34e18, uint32_t*, UIControl_MultiList**>()((uint32_t*)&scene->UIControl_Vector, &ControlPTR); // vector<UIControl*>.push_back
			return true;
		}
		
		static void HandleCheckboxElementToggled(UIScene* _this, int ID, int ID2, bool State)
		{
			mc::GameSettings* settings = (mc::GameSettings*)mc::GameSettings::GetGameSettingsDebugMask(0xFFABCD00, 0);
			settings->SetGameSetting(ID2, (uint32_t)State);
			
			
			mc::ConsoleUIController* cuic = mc::ConsoleUIController::getInstance();
			
			if(ID2 == mc::GameSettings::eDebugSetting::ShowUIConsole)
			{
				cuic->ShowUIDebugConsole(State);
			}
		}
		
		static void Log(const wchar_t* text)
		{
			code::Func<void, 0x0382F6B8, const char*, const wchar_t*>()("%ls\n", text);
		}
		
		
		UIControl_MultiList HowToList;
		uint32_t field_0x17C;
        
    };
}
