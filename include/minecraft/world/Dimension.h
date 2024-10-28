#pragma once

#include <code/code.h>

#include "Level.h"

#include "../client/resource/shared_ptr.h"

namespace mc {
    class Dimension {
    public:
	
		enum eGeneratorType : uint32_t {
			Default = 0x104c3598,
			Flat = 0x104c35a0,
			LargeBiomes = 0x104c35a4,
			Amplified = 0x104c35a8,
			Customized = 0x104c35ac,
		};
		Level* lvl;
		uint32_t GeneratorType;
		uint32_t GeneratorOptions;
		uint32_t BiomeSource;
    };
}