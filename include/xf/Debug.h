#pragma once

#include <thread>


#include <minecraft/client/app/System.h>
#include <minecraft/client/app/GameSettings.h>
#include <minecraft/rendering/Tesselator.h>
#include "DrawHelper.h"


namespace xf {
		

mc::GameSettings* DebugSettings;
uint32_t DebugConsole;
uint32_t CamController;


        class Debug {
        public:
			
			void ShowDevelopmentText(int WriteMode = 0)
			{
				xf::GUI::DrawHelper::renderSetup();
				
				mc::Tesselator* tess = mc::Tesselator::getInstance();
				
				switch(WriteMode) { 
					case 0:
						xf::GUI::DrawHelper::DisplayText(mc::Minecraft::getInstance()->defaultFonts, L"Work In Progress",   2.0, mc::toFloat((WIDTH) / 6) + 1.0f, mc::toFloat((HEIGHT) / 3) + 1.0f, 0x44000000, false, -30.0f);
						xf::GUI::DrawHelper::DisplayText(mc::Minecraft::getInstance()->defaultFonts, L"Work In Progress",   2.0, mc::toFloat((WIDTH) / 6), mc::toFloat((HEIGHT) / 3), 0x55FFFFFF, false, -30.0f);
					break;
					case 1:
						xf::GUI::DrawHelper::DisplayText(mc::Minecraft::getInstance()->defaultFonts, L"PhoenixARC",   2.0, mc::toFloat((WIDTH) / 6) + 1.0f, mc::toFloat((HEIGHT) / 3) + 1.0f, 0x33000000, false, -30.0f);
						xf::GUI::DrawHelper::DisplayText(mc::Minecraft::getInstance()->defaultFonts, L"PhoenixARC",   2.0, mc::toFloat((WIDTH) / 6), mc::toFloat((HEIGHT) / 3), 0x44FFFFFF, false, -30.0f);
					break;
				}
				
			}


    
};

}