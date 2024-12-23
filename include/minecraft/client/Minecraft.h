#pragma once

#include <code/code.h>

#include "resource/shared_ptr.h"
#include "resource/vector.h"

namespace mc {
    class Minecraft {
	public:
		struct FixerUpper* fixerupper;
		uint32_t field_0x4;
		uint8_t field_0x8;
		uint8_t field_0x9;
		uint8_t field_0xa;
		uint8_t field_0xb;
		uint32_t field_0xc;
		uint32_t field_0x10;
		uint32_t field_0x14;
		uint32_t field_0x18;
		uint32_t field_0x1c;
		struct Timer* timer;
		uint32_t field_0x24;
		uint32_t field_0x28;
		bool field_0x2c;
		struct LevelRenderer* levelRenderer;
		struct LocalPlayer* thePlayer;
		uint32_t field_0x38;
		struct Level* lvl;
		int playerCount;
		struct mc_boost::shared_ptr<struct LocalPlayer> localPlayers[4];
		uint32_t field_0x64;
		uint32_t field_0x68;
		uint32_t field_0x6c;
		uint32_t field_0x70;
		uint32_t field_0x74;
		uint32_t field_0x78;
		uint32_t field_0x7c;
		uint32_t field_0x80;
		uint32_t field_0x84;
		uint32_t field_0x88;
		uint32_t field_0x8c;
		uint32_t field_0x90;
		uint32_t field_0x94;
		uint32_t field_0x98;
		uint32_t field_0x9c;
		uint32_t field_0xa0;
		uint32_t field_0xa4;
		uint32_t field_0xa8;
		uint32_t field_0xac;
		uint32_t field_0xb0;
		uint32_t field_0xb4;
		uint32_t field_0xb8;
		int field_0xbc;
		uint32_t field_0xc0;
		uint32_t field_0xc4;
		uint32_t field_0xc8;
		uint32_t field_0xcc;
		struct ParticleEngine* particleEngine;
		uint32_t field_0xd4;
		uint32_t field_0xd8;
		uint32_t field_0xdc;
		uint32_t field_0xe0;
		uint32_t field_0xe4;
		uint32_t field_0xe8;
		uint32_t field_0xec;
		uint32_t field_0xf0;
		uint32_t field_0xf4;
		uint32_t field_0xf8;
		uint32_t field_0xfc;
		struct Textures* textures;
		struct Font* defaultFonts;
		struct Font* alternativeFont;
		uint32_t field_0x10c;
		struct ProgressRenderer* progressRenderer;
		struct GameRenderer* gameRenderer;
		struct EntityRenderDispatcher* entityRenderDispatcher;
		struct ItemInHandRenderer* itemInHandRenderer;
		struct BlockColors* blockColors;
		struct ItemColors* itemColors;
		struct TextureAtlas* blockTextureAtlas;
		struct ItemRenderer* itemRenderer;
		struct BlockRenderDispatcher* blockRenderDispatcher;
		uint32_t field_0x134;
		uint32_t field_0x138;
		uint32_t field_0x13c;
		uint32_t field_0x140;
		struct Gui* gui;
		uint32_t field_0x148;
		uint32_t field_0x14c;
		struct Options* options;
		uint32_t field_0x154;
		struct SoundEngine* soundengine;
		uint32_t field_0x15c;
		struct TexturePackRepository* texturePackRepo;
		struct File* file;
		uint32_t field_0x168;
		uint32_t field_0x16c;
		uint32_t field_0x170;
		uint32_t field_0x174;
		uint32_t field_0x178;
		uint32_t field_0x17c;
		uint32_t field_0x180;
		struct DirectoryLevelStorage* mcRegionLevelStorage;
		struct StatsCounter* statsCounters[4];
		uint32_t field_0x198;
		uint32_t field_0x19c;
		uint32_t field_0x1a0;
		uint32_t field_0x1a4;
		uint32_t field_0x1a8;
		uint32_t field_0x1ac;
		uint32_t field_0x1b0;
		uint32_t field_0x1b4;
		uint32_t field_0x1b8;
		uint32_t field_0x1bc;
		uint32_t field_0x1c0;
		uint32_t field_0x1c4;
		uint32_t field_0x1c8;
		uint32_t field_0x1cc;
		uint32_t field_0x1d0;
		uint32_t field_0x1d4;
		uint32_t field_0x1d8;
		uint32_t field_0x1dc;
		int field_0x1e0;
		int field_0x1e4;
		uint32_t field_0x1e8;
		struct FrameTimer* frameTimer;
		uint32_t field_0x1f0;
		uint32_t field_0x1f4;
		uint32_t field_0x1f8;
		uint32_t field_0x1fc;
		uint32_t field_0x200;
		uint32_t field_0x204;
		uint32_t field_0x208;
		uint32_t field_0x20c;
		uint32_t field_0x210;
		uint32_t field_0x214;
		uint32_t field_0x218;
		uint32_t field_0x21c;
		uint32_t field_0x220;
		uint32_t field_0x224;
		uint32_t field_0x228;
		mstd::vector<void> w_vec1; // idk Need to Look Up Later
		mstd::vector<void> w_vec2; // idk Need to Look Up Later
		struct MiniGameDef* minigame;
		struct CommonMasterGameMode* clientMasterGameMode;
		uint32_t field_0x254;
		uint32_t field_0x258;
		uint32_t field_0x25c;
		uint32_t field_0x260;
		uint32_t field_0x264;

		static Minecraft* getInstance() {
            return code::Func<Minecraft*, 0x03166818>()();
        }
        
        struct Level* getLevel(int i) {
			return code::Func<struct Level*, 0x0318C878, Minecraft*, int>()(this, i);
		}
		static wchar_t* getString(uint32_t StringIDAddr)
		{
			return code::Func<wchar_t*, 0x02f24864, uint32_t>()(StringIDAddr);
		}
        
        void getCameraEntity(struct Entity** integer) {
			return code::Func<void, 0x0318E328, Minecraft*, struct Entity**>()(this, integer);
		}
		void setScreen(struct Screen* screen) {
			code::Func<void, 0x03189944, Minecraft*, struct Screen*>()(this, screen);
		}
		
		struct ClientPacketListener* getConnection(int i) {
			return code::Func<struct ClientPacketListener*, 0x031B2654, Minecraft*, int>()(this, i); 
		}

		mc_boost::shared_ptr<struct LocalPlayer>* GetPlayerByPlayerIndex(int idx, mc_boost::shared_ptr<struct LocalPlayer>* dest = 0) {
    		return code::Func<mc_boost::shared_ptr<struct LocalPlayer>*, 0x031b3644, Minecraft*, mc_boost::shared_ptr<struct LocalPlayer>*, int>()(this, dest, idx);
  		}
	};
}