#pragma once

#include <code/code.h>

#include "../client/resource/wstring.h"

namespace mc {
    class Language {
    public:
	
		
		static uint32_t getHash(wchar_t* _str, int _len) {
			uint32_t output = 0x13;
			for(int i = 0; i < _len; i++) {
				output += (output ^ ((int)_str[i]));
			}
			return output;
		}
		
        static mstd::wstring* getElement(Language* _this, mstd::wstring* target, mstd::wstring* ElementName) {
			
			switch(getHash(ElementName->pointer, ElementName->length)) {
				case(Language::StringHashes::hOPTIONS_TITLE):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::OPTIONS_TITLE));
				break;
				case(Language::StringHashes::hOPTIONS_VIDEO):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::OPTIONS_VIDEO));
				break;
				case(Language::StringHashes::hOPTIONS_CONTROLS):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::OPTIONS_CONTROLS));
				break;
				case(Language::StringHashes::hGUI_DONE):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::GUI_DONE));
				break;
				case(Language::StringHashes::hOPTIONS_MUSIC):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::OPTIONS_MUSIC));
				break;
				case(Language::StringHashes::hOPTIONS_SOUND):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::OPTIONS_SOUND));
				break;
				case(Language::StringHashes::hOPTIONS_OFF):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::OPTIONS_OFF));
				break;
				case(Language::StringHashes::hOPTIONS_INVERTMOUSE):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::OPTIONS_INVERTMOUSE));
				break;
				case(Language::StringHashes::hOPTIONS_SENSITIVITY):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::OPTIONS_SENSITIVITY));
				break;
				case(Language::StringHashes::hOPTIONS_DIFFICULTY):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::OPTIONS_DIFFICULTY));
				break;
				case(Language::StringHashes::hOPTIONS_DIFFICULTY_EASY):
					target->assign(mc::Minecraft::getString(Language::LOCKeys::OPTIONS_DIFFICULTY_EASY));
				break;
				case(Language::StringHashes::hOPTIONS_SENSITIVITY_MAX):
					target->assign(L"MAX");
				break;
				default:
					target->assign(L"Couldn't Find String", 20);
				break;
			}
			
			return target;
        }
		
		enum LOCKeys : uint32_t {
			OPTIONS_TITLE = 0xB658D2F4,
			OPTIONS_SOUND = 0x7F9DEEF5,
			OPTIONS_VIDEO = 0xC2B7BF99,
			OPTIONS_CONTROLS = 0x80FED3F0,
			GUI_DONE = 0x6D2A309C,
			OPTIONS_MUSIC = 0X67B4208F,
			OPTIONS_OFF = 0XF74DAB3B,
			OPTIONS_INVERTMOUSE = 0XA1531E06,
			OPTIONS_SENSITIVITY = 0XA5CBEBB5,
			OPTIONS_DIFFICULTY = 0XD324428D,
			OPTIONS_DIFFICULTY_EASY = 0XB558EFD9,
			OPTIONS_DIFFICULTY_NORMAL = 0X1494C206,
			OPTIONS_DIFFICULTY_HARD = 0XF70F3270,
			OPTIONS_DIFFICULTY_PEACEFUL = 0X4E52B99A,
			
		};
		enum StringHashes : uint32_t {
			hOPTIONS_TITLE = 0xE1585,
			hOPTIONS_MUSIC = 0xE1D7B,
			hOPTIONS_OFF = 0x38696,
			hOPTIONS_SOUND = 0xE1684,
			hOPTIONS_INVERTMOUSE = 0x3866B69,
			hOPTIONS_SENSITIVITY = 0x3853385,
			hOPTIONS_SENSITIVITY_MAX = 0x38533A7A,
			hOPTIONS_DIFFICULTY = 0x1C35D79,
			hOPTIONS_DIFFICULTY_EASY = 0x386BAD7D,
			hOPTIONS_VIDEO = 0xE166F,
			hOPTIONS_CONTROLS = 0x70C273,
			hGUI_DONE = 0x5485,
		};
		
        static Language* getInstance() {
            #ifdef CEMU
                return code::Mem(0x104de654).as<Language*>();
            #else
                return code::Mem(0x109e0854).as<Language*>();
            #endif
        }
    };
};