#include <code/code.h>
#include <xf/Debug.h>

#include <minecraft/mc.h>

xf::Debug debug;

DECL_FUNCTION(uint32_t, NavigateToScene, mc::UILayer* _this, uint32_t p2, mc::UIScene::SceneID SceneID, uint32_t p4) {
	
	switch(SceneID)
	{
		case(mc::UIScene::SceneID::Debug): // Check for unused UIScene ID
		{
			mc::UIScene_DebugMenu* debug = new mc::UIScene_DebugMenu(p2, p4, (uint32_t)_this);
			uint32_t SubSceneType = debug->vtbl->getSubSceneType(debug);
			(*(mc::TelemetryManager**)0x104f6970)->Vtbl->RecordMenuShown(*((mc::TelemetryManager**)0x104f6970), p2, SceneID, SubSceneType);
		
		
			uint32_t LayerSceneStart = (uint32_t)_this->scenes.start;
			uint32_t TempValue = 0;
			uint32_t LayerSceneFinish = (uint32_t)_this->scenes.finish - LayerSceneStart >> 2;
		
		
			if ((LayerSceneStart != 0) && (LayerSceneFinish != 0)) {
				TempValue = LayerSceneStart;
				if (LayerSceneStart != 0) {
					TempValue = LayerSceneFinish;
				}
				debug->SetBackScene(*((mc::UIScene**)(LayerSceneStart + (TempValue + -1) * 4)));
			}
		
			code::Func<void, 0x02e34e18, uint32_t*, mc::UIScene_DebugMenu**>()((uint32_t*)&_this->scenes, &debug); // vector<UIScene**>.push_back
			_this->updateFocusState(false);
			debug->vtbl->tick(debug);
		return 1;
		}
		case(mc::UIScene::SceneID::HelpAndOptions): // Check for unused UIScene ID
		{
			mc::UIScene_HelpAndOptionsMenu* debug = new mc::UIScene_HelpAndOptionsMenu(p2, p4, (uint32_t)_this);
			uint32_t SubSceneType = debug->vtbl->getSubSceneType(debug);
			(*(mc::TelemetryManager**)0x104f6970)->Vtbl->RecordMenuShown(*((mc::TelemetryManager**)0x104f6970), p2, SceneID, SubSceneType);
		
		
			uint32_t LayerSceneStart = (uint32_t)_this->scenes.start;
			uint32_t TempValue = 0;
			uint32_t LayerSceneFinish = (uint32_t)_this->scenes.finish - LayerSceneStart >> 2;
		
		
			if ((LayerSceneStart != 0) && (LayerSceneFinish != 0)) {
				TempValue = LayerSceneStart;
				if (LayerSceneStart != 0) {
					TempValue = LayerSceneFinish;
				}
				debug->SetBackScene(*((mc::UIScene**)(LayerSceneStart + (TempValue + -1) * 4)));
			}
		
			code::Func<void, 0x02e34e18, uint32_t*, mc::UIScene_HelpAndOptionsMenu**>()((uint32_t*)&_this->scenes, &debug); // vector<UIScene**>.push_back
			_this->updateFocusState(false);
			debug->vtbl->tick(debug);
		return 1;
		}
		break;
		default:
			return real_NavigateToScene(_this, p2, SceneID, p4);
		break;
	}
	return real_NavigateToScene(_this, p2, SceneID, p4);
}

DECL_FUNCTION(uint32_t, GetGameSettingsDebugMask, int i, int y) {
	if(i == 0xFFABCD00 && xf::DebugSettings != nullptr) {
		return (uint32_t)xf::DebugSettings;
	}
	return real_GetGameSettingsDebugMask(i, y);
}
DECL_FUNCTION(void, MinecraftServer_tick, uint32_t server) {
	if(xf::DebugSettings->GetGameSetting(mc::GameSettings::eDebugSetting::FreezeTime) == 0)
		real_MinecraftServer_tick(server);
}
DECL_FUNCTION(void, ServerLevel_tickEntities, uint32_t serverLevel) {
	if(xf::DebugSettings->GetGameSetting(mc::GameSettings::eDebugSetting::MobsDontTick) == 0)
		real_ServerLevel_tickEntities(serverLevel);
}
DECL_FUNCTION(void, ServerLevel_tickServerPlayers, uint32_t serverLevel) {
	if(xf::DebugSettings->GetGameSetting(mc::GameSettings::eDebugSetting::FreezePlayers) == 0)
		real_ServerLevel_tickServerPlayers(serverLevel);
}
DECL_FUNCTION(bool, MobNearestPlayerTargetGoal_canUse, uint32_t serverLevel) {
	if(xf::DebugSettings->GetGameSetting(mc::GameSettings::eDebugSetting::MobsDontAttack) == 0)
		return real_MobNearestPlayerTargetGoal_canUse(serverLevel);
	return false;
}
DECL_FUNCTION(double, Level_getRainLevel, uint32_t serverLevel, float val) {
	if(xf::DebugSettings->GetGameSetting(mc::GameSettings::eDebugSetting::DisableWeather) == 0)
		return real_Level_getRainLevel(serverLevel, val);
	return 0.0d;
}
DECL_FUNCTION(bool, GameSettings_isDebugSettingEnabled, uint32_t Setting, uint32_t mask) {
	if(xf::DebugSettings->GetGameSetting(mc::GameSettings::eDebugSetting::CraftAnything) != 0 && Setting == 0xE)
		return true;
	return false;
}
DECL_FUNCTION(bool, CMinecraftApp_DebugArtToolsOn, uint32_t Setting) {
	if(xf::DebugSettings->GetGameSetting(mc::GameSettings::eDebugSetting::ArtTools) != 0)
		return true;
	return false;
}
DECL_FUNCTION(bool, DLCPack_hasPurchasedPack, uint32_t Setting) {
	if(xf::DebugSettings->GetGameSetting(mc::GameSettings::eDebugSetting::UnlockAllDLC) == 0)
		return real_DLCPack_hasPurchasedPack(Setting);
	return true;
}
DECL_FUNCTION(uint32_t, Biome_byId, uint32_t Id) {
	if(xf::DebugSettings->GetGameSetting(mc::GameSettings::eDebugSetting::BiomeOverride) == 0)
		return real_Biome_byId(Id);
	return real_Biome_byId(1);
}
DECL_FUNCTION(bool, CMinecraftApp_DebugSettingsOn, uint32_t Setting) {
	return true;
}
DECL_FUNCTION(mc::UIComponent_DebugUIConsole*, ct_UIComponent_DebugConsole, mc::UIComponent_DebugUIConsole* Val) {
	mc::UIComponent_DebugUIConsole* _this = real_ct_UIComponent_DebugConsole(Val);
	_this->InitConsoleLines();
	xf::DebugConsole = (uint32_t)_this;
	return _this;
}

int c_main(void*) {
    code::init();

    REPLACE(0x02e8461c,  NavigateToScene);
    REPLACE(0x02F70968,  GetGameSettingsDebugMask);
    REPLACE(0x03226358,  MinecraftServer_tick);
    REPLACE(0x032B3354,  ServerLevel_tickServerPlayers);
    REPLACE(0x032B32BC,  ServerLevel_tickEntities);
    REPLACE(0x026954BC,  MobNearestPlayerTargetGoal_canUse);
    REPLACE(0x025550D0,  Level_getRainLevel);
    REPLACE(0x02f70970,  GameSettings_isDebugSettingEnabled);
    REPLACE(0x02F5C874,  CMinecraftApp_DebugArtToolsOn);
    REPLACE(0x02AE8B54,  DLCPack_hasPurchasedPack);
    REPLACE(0x02E0A12C,  ct_UIComponent_DebugConsole);
    REPLACE(0x02f5c86c,  CMinecraftApp_DebugSettingsOn);
    REPLACE(0x020f66bc,  Biome_byId);

    return 0;
}

void _main() {
	
    debug = (xf::Debug());
	xf::DebugSettings = new mc::GameSettings();
	
	
    mc::C4JThreadImpl* thread = new mc::C4JThreadImpl(c_main, nullptr, "Setup Thread", 0x200);
    thread->Run();
    thread->SetDeleteOnExit(true);
}
