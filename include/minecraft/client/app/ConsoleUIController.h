#pragma once

#include <code/code.h>
#include "../../ui/scene/UIScene.h"
#include "../../ui/group/UIGroup.h"

namespace mc {
    class ConsoleUIController {
    public:
        static ConsoleUIController* getInstance() {
            #ifdef CEMU
                return (ConsoleUIController*) 0x104F73E0;
            #else
                return (ConsoleUIController*) 0x109F95E0;
            #endif
        }

        void PlayUISFX(struct SoundEvent* sound) {
            code::Func<void, 0x02DA7918, ConsoleUIController*, struct SoundEvent*>()(this, sound);
        }

        void TouchBoxRebuild(UIScene* scene) {
            code::Func<void, 0x02d9e69c, ConsoleUIController*, UIScene*>()(this, scene);
        }

        void NavigateToScene(uint32_t BaseSceneID, uint32_t NewSceneID) {
            code::Func<void, 0x02da0254, ConsoleUIController*, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t>()(this, BaseSceneID, NewSceneID, 0, 6, 7);
        }
		
		void ShowUIDebugMarketingGuide(bool Showing) {
			if(Showing) {
				this->field_0x4 = this->Group2->AddComponent(0, 0x45, 0);
			}
			else {
				this->Group2->removeComponent(0x45);
				this->field_0x4 = 0;
			}
        }
		
		void ShowUIDebugConsole(bool Showing) {
            code::Func<void, 0x02DABA0C, ConsoleUIController*, bool>()(this, Showing);
        }
		
		void ShowPlayerDisplayname() {
            code::Func<void, 0x02E0C8A4, uint32_t>()(this->Group2->field_0x28);
        }
		
		template<typename... Args>
		static void mc_swprintf(const wchar_t* outputPointer, uint32_t size, const wchar_t* __format, Args... args) {
			code::Func<void, 0x382C8C0, const wchar_t*, uint32_t, const wchar_t*, Args...>()(outputPointer, size, __format, args...);
		}
		static void Log(const wchar_t* text)
		{
			code::Func<void, 0x0382F6B8, const char*, const wchar_t*>()("%ls\n", text);
		}
		
	uint32_t field_0x0;
	uint32_t field_0x4;
	uint32_t field_0x8[0x3FA9];
	UIGroup* Group1;
	UIGroup* Group2;
	UIGroup* Group3;
	UIGroup* Group4;
	UIGroup* Group5;
	UIGroup* Group6;
	uint32_t field_0xFF;
    };
}