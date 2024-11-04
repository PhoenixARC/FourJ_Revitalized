#pragma once

#include <code/code.h>
#include "../Minecraft.h"
#include "../file/File.h"
#include "../file/FileOutputStream.h"
#include "../../entity/player/LocalPlayer.h"
#include "../../ui/screen/TitleScreen.h"
#include "../../ui/screen/OptionsScreen.h"

namespace mc {
	
	class DebugSetting {
	public:
		DebugSetting(wchar_t* Name, uint32_t type, uint32_t value)
		{
			this->SettingName = Name;
			this->Type = (eSettingType)type;
			this->Value = value;
		}
		DebugSetting()
		{
			this->SettingName = L"Unnamed Setting";
			this->Type = eSettingType::BOOL;
			this->Value = 0;
		}
		
		enum eSettingType : uint32_t {
			BOOL = 0,
			INT = 1,
			FLOAT = 2,
			POINTER = 3,
			FUNCTION = 4,
		};
		
		wchar_t* SettingName;
		eSettingType Type;
		uint32_t Value;
	};
	
    class GameSettings {
    public:
		
		GameSettings()
		{
			this->debugSettings = {};
			this->debugSettings.push_back(new mc::DebugSetting(L"Freeze Players", DebugSetting::eSettingType::BOOL, 0)); //
			this->debugSettings.push_back(new mc::DebugSetting(L"Mobs don't attack", DebugSetting::eSettingType::BOOL, 0)); //
			this->debugSettings.push_back(new mc::DebugSetting(L"Freeze Time", DebugSetting::eSettingType::BOOL, 0)); // 
			this->debugSettings.push_back(new mc::DebugSetting(L"Disable Weather", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Craft Anything", DebugSetting::eSettingType::BOOL, 1));
			//this->debugSettings.push_back(new mc::DebugSetting(L"Use DPad for debug", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Mobs don't tick", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Art tools", DebugSetting::eSettingType::BOOL, 1));
			this->debugSettings.push_back(new mc::DebugSetting(L"Show UI Console", DebugSetting::eSettingType::BOOL, 0));
			//this->debugSettings.push_back(new mc::DebugSetting(L"Distributable Save", DebugSetting::eSettingType::BOOL, 0));
			//this->debugSettings.push_back(new mc::DebugSetting(L"Height-Water Maps", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Biome override", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Unlock All DLC", DebugSetting::eSettingType::BOOL, 1));
			//this->debugSettings.push_back(new mc::DebugSetting(L"Unlock Camera", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Show Development Text", DebugSetting::eSettingType::BOOL, 1));
			this->debugSettings.push_back(new mc::DebugSetting(L"More Thunder When Raining", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Disable Mipmapping", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Use Java Fog", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Disable Tooltips", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Open Title Screen", DebugSetting::eSettingType::FUNCTION, (uint32_t)(&OpenTitleScreen)));
			//this->debugSettings.push_back(new mc::DebugSetting(L"Dump LocalPlayer", DebugSetting::eSettingType::FUNCTION, (uint32_t)(&DumpPlayerData)));
		}
		
		static void DumpPlayerData() {
			File* DataFile = new File(L"LocalPlayer.bin");
			FileOutputStream* stream = new FileOutputStream(*DataFile);
			LocalPlayer* playerPTR = mc::Minecraft::getInstance()->thePlayer;
			char* Data = (char*)playerPTR;
			for(int i = 0; i < sizeof(LocalPlayer); i++)
				stream->write(Data[i]);
			stream->close();
		}
		
		static void OpenTitleScreen() {
			mc::TitleScreen* title = new mc::TitleScreen();
			mc::OptionsScreen* optMenu = new mc::OptionsScreen(title, mc::Minecraft::getInstance()->options);
			mc::Minecraft::getInstance()->setScreen(optMenu);
		}
		
		uint32_t GetGameSetting(uint32_t setting)
		{
			return this->debugSettings[setting]->Value;
		}
		void SetGameSetting(uint32_t setting, uint32_t value)
		{
			this->debugSettings[setting]->Value = value;
		}
		
		bool isDebugSettingSet(uint32_t setting){
			return (this->debugSettings[setting]->Value != 0);
		}
		
		static uint32_t GetGameSettingsDebugMask(uint32_t i, bool b){
			return code::Func<uint32_t, 0x02F70968, uint32_t, bool>()(i, b);
		}
		
		static void SetGameSettingsDebugMask(uint32_t i, uint32_t b){
			code::Func<void, 0x02F70978, uint32_t, uint32_t>()(i, b);
			
		}
		
		enum eDebugSetting : uint32_t
		{
			//LoadFromLocalFolder,
			//WriteToLocalFolder,
			FreezePlayers = 0,
			MobsDontAttack,
			FreezeTime,
			DisableWeather,
			CraftAnything,
			//UseDPadForDebug,
			MobsDontTick,
			ArtTools,
			ShowUIConsole,
			//DistributableSave,
			//HeightWaterMaps,
			BiomeOverride,
			UnlockAllDLC,
			//UnlockCamera,
			ShowDevText,
			moreThunder,
			DisableMipmap,
			JavaFog,
			DisableTooltips,
			OpenTitle,
			//DumpLocalPlayer,
		};
		
		xf::Vector<DebugSetting*> debugSettings;
    };
}