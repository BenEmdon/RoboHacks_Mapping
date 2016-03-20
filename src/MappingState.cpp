//
//  MappingState.cpp
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#include "MappingState.h"
#include "DrawingBoard.h"


MappingState::MappingState() {
    userQuit = false;
    Board = new DrawingBoard;
}

MappingState::~MappingState(){
    delete Board;
}

void MappingState::stateEnter(){
    
}

void MappingState::stateEvent(){
    SDL_Event event;
    
    // Event loop //
    while(SDL_PollEvent(&event)!=0){
        
        // Quits game //
        if(event.type==SDL_QUIT)
        {
            userQuit=true;
        }
    }
}

void MappingState::stateUpdate(){
    
}

void MappingState::stateRender(){
    Board->drawBoard();
    
}

bool MappingState::stateExit(){
    return userQuit;
}