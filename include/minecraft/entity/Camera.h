#pragma once

#include "Entity.h"
#include "../util/Vec3.h"

namespace mc {
    class Camera : public Entity {
    public:
	
		void SetPosition(int x = 0, int y = 0, int z = 0) { 
			this->position.x = (float)x;
			this->position.y = (float)y;
			this->position.z = (float)z;
		}
		
		void SetPosition(mc::Vec3* value) { 
			this->position.x = value->x;
			this->position.y = value->y;
			this->position.z = value->z;
		}
		
		mc::Vec3* GetPosition() {
			return &this->position;
		}
		
    };
}