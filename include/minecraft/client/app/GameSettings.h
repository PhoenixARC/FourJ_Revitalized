#pragma once

#include <code/code.h>

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
			this->debugSettings.push_back(new mc::DebugSetting(L"Load Saves From Local Folder Mode", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Write Saves To Local Folder Mode", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Freeze Players", DebugSetting::eSettingType::BOOL, 0)); //
			this->debugSettings.push_back(new mc::DebugSetting(L"Mobs don't attack", DebugSetting::eSettingType::BOOL, 0)); //
			this->debugSettings.push_back(new mc::DebugSetting(L"Freeze Time", DebugSetting::eSettingType::BOOL, 0)); // 
			this->debugSettings.push_back(new mc::DebugSetting(L"Disable Weather", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Craft Anything", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Use DPad for debug", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Mobs don't tick", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Art tools", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Show UI Console", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Distributable Save", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Debug Leaderboards", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Height-Water Maps", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Superflat Nether", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"More lightning when thundering", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Biome override", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Go To Overworld", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Unlock All DLC", DebugSetting::eSettingType::BOOL, 0));
			this->debugSettings.push_back(new mc::DebugSetting(L"Show Marketing Guide", DebugSetting::eSettingType::BOOL, 0));
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
			LoadFromLocalFolder = 0,
			WriteToLocalFolder,
			FreezePlayers,
			MobsDontAttack,
			FreezeTime,
			DisableWeather,
			CraftAnything,
			UseDPadForDebug,
			MobsDontTick,
			ArtTools,
			ShowUIConsole,
			DistributableSave,
			DebugLeaderboards,
			HeightWaterMaps,
			SuperflatNether,
			MoreLightningWhenThundering,
			BiomeOverride,
			GoToOverworld,
			UnlockAllDLC,
			ShowMarketingGuide
		};
		
		xf::Vector<DebugSetting*> debugSettings;
    };
}