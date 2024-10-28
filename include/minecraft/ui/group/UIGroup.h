#pragma once

namespace mc {
    class UIGroup {
	public:
	
		void showComponent(int i, uint32_t EUIScene, uint32_t EUILayer, bool Showing)
		{
			code::Func<void, 0x02E87D6C, UIGroup*, int, uint32_t, uint32_t, bool>()(this, i, EUIScene, EUILayer, Showing); 
		}
		uint32_t AddComponent(int i, uint32_t EUIScene, uint32_t EUILayer)
		{
			return code::Func<uint32_t, 0x02E87D88, UIGroup*, int, uint32_t, uint32_t>()(this, i, EUIScene, EUILayer); 
		}
		void removeComponent(uint32_t EUIScene)
		{
			code::Func<void, 0x02E87DA4, UIGroup*, uint32_t, int>()(this, EUIScene, 0); 
		}
		
		uint32_t field_0x00;
		uint32_t field_0x04;
		uint32_t field_0x08;
		uint32_t field_0x0C;
		uint32_t field_0x10;
		uint32_t field_0x14;
		uint32_t field_0x18;
		uint32_t field_0x1C;
		uint32_t field_0x20;
		uint32_t field_0x24;
		uint32_t field_0x28;
		uint32_t field_0x2C;
    };
}