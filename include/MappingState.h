//
//  MappingState.h
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#ifndef MappingState_h
#define MappingState_h

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

#include "ApplicationState.h"
#include <vector>



class DrawingBoard;

class MappingState: public ApplicationState{
public:
    MappingState();
    ~MappingState();
    void stateEnter();
    void stateEvent();
    void stateUpdate();
    void stateRender();
    bool stateExit();
private:
    DrawingBoard *Board;
    bool userQuit;
};

#endif /* MappingState_h */
