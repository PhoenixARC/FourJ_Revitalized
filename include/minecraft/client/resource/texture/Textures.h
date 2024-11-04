#pragma once

#include <code/code.h>

#include "../wstring.h"
#include "../../file/File.h"

namespace mc {
    class Textures {
    public:
        void loadTexture(struct BufferedImage* img, int id)  {
            code::Func<void, 0x0338f694, Textures*, struct BufferedImage*, int>()(this, img, id);
        }

        void bind(int id) {
            code::Func<void, 0x0338ee78, Textures*, int>()(this, id);
        }
		
        void bindTexture(const mstd::wstring& FilePath) {
            code::Func<void, 0x0338EE94, Textures*, const mstd::wstring&>()(this, FilePath);
        }

        void bindTexture(uint32_t Location) {
            code::Func<void, 0x0338F014, Textures*, uint32_t>()(this, Location);
        }

        uint32_t loadTexture(int id) {
            code::Func<uint32_t, 0x0338eeec, Textures*, int>()(this, id);
        }

        uint32_t loadMemTexture(const mstd::wstring& str, int unk) {
            return code::Func<uint32_t, 0x03391f7c, Textures*, const mstd::wstring&, int>()(this, str, unk);
        } 

        uint32_t getTextureLocation(int ID) {
            return code::Func<uint32_t, 0x0338F438, Textures*, int>()(this, ID);
        } 

        void reloadall() {
            code::Func<void, 0x03392de0, Textures*>()(this);
        }

        void releaseTexture(int id) {
            code::Func<void, 0x03390cd4, Textures*, int>()(this, id);
        }
		
		uint32_t loadTexture(uint32_t TEXTURE_ID, const mstd::wstring& FilePath)
		{
			mc::File* file = new mc::File(FilePath);
			if(file->exists())
				return code::Func<uint32_t, 0x0338D08C, Textures*, uint32_t, const mstd::wstring&>()(this, TEXTURE_ID, FilePath);
			else
				return code::Func<uint32_t, 0x0338D08C, Textures*, uint32_t, const mstd::wstring&>()(this, TEXTURE_ID, L"missingTexture.png");
		}
    };
}