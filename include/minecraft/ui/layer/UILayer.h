#pragma once

#include <code/code.h>

#include "../../client/resource/vector.h"

#include "../../util/unordered_map.h"
#include "../../util/pair.h"

namespace mc {
    class UILayer {
    public:
	
	
		void updateFocusState(bool flag)
		{
			code::Func<void, 0x02E7F95C, UILayer*, bool>()(this, flag); 
		}
		void AddComponent(int i, uint32_t EUIScene, uint32_t voidStar)
		{
			code::Func<void, 0x02E3C2F4, UILayer*, int, uint32_t, uint32_t>()(this, i, EUIScene, voidStar); 
		}
		void removeComponent(uint32_t EUIScene)
		{
			code::Func<void, 0x02E85E98, UILayer*, uint32_t>()(this, EUIScene); 
		}
		
		enum eUIComponent : uint32_t {
			TutorialPopup = 		0x19,
			Chat = 					0x24,
			HUD = 					0x31,
			WiiUDRC = 				0x41,
			Panorama = 				0x42,
			Logo = 					0x43,
			DebugUIConsole = 		0x44,
			DebugUIMarketingGuide = 0x45,
			Tooltips = 				0x46,
			PressStartToPlay = 		0x47,
			MenuBackground = 		0x48
		};
		
        mstd::vector<struct UIScene*> scenes;
        mstd::vector<struct UIScene*> components;
        mstd::vector<struct UIScene*> field_0x20;
        mstd::vector<struct UIScene*> field_0x30;
        mc_boost::unordered::unordered_map<int, mstd::pair<int, bool>> componentVisibility;
        bool field_0x58;
        bool field_0x59;
        bool field_0x5A;
        bool field_0x5B;
        int field_0x5C;
        int field_0x60;
        struct UIGroup* group;
    };
}