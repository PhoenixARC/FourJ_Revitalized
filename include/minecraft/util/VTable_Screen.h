#pragma once

#include "VTable.h"

#include "../client/resource/shared_ptr.h"
#include "../util/InteractionHand.h"
#include "../util/BlockPos.h"

namespace mc {
    struct VTable_Screen : public VTable {
    public:
	
        MC_VFUNC(void,         struct Screen, __dt);
        MC_VFUNC(void,         struct Screen, render);
        MC_VFUNC(void,         struct Screen, keyPressed);
        MC_VFUNC(void,         struct Screen, mouseClicked);
        MC_VFUNC(void,         struct Screen, mouseReleased);
        MC_VFUNC(void,         struct Screen, buttonClicked);
        MC_VFUNC(void,         struct Screen, init_screen);
        MC_VFUNC(void,         struct Screen, init);
        MC_VFUNC(void,         struct Screen, setSize);
        MC_VFUNC(void,         struct Screen, updateEvents);
        MC_VFUNC(void,         struct Screen, mouseEvent);
        MC_VFUNC(void,         struct Screen, keyboardEvent);
        MC_VFUNC(void,         struct Screen, tick);
        MC_VFUNC(void,         struct Screen, removed);
        MC_VFUNC(void,         struct Screen, renderBackground);
        MC_VFUNC(void,         struct Screen, renderBackground_i);
        MC_VFUNC(void,         struct Screen, renderDirtBackground);
        MC_VFUNC(void,         struct Screen, isPauseScreen);
        MC_VFUNC(void,         struct Screen, confirmResult);
        MC_VFUNC(void,         struct Screen, tabPressed);
    };
}