//
//  ApplicationStateManager.cpp
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#include "../include/ApplicationStateManager.h"
#include "../include/MappingState.h"

ApplicationStateManager::ApplicationStateManager(){
    currentState = new MappingState;
    currentState->stateEnter();
}

ApplicationStateManager::~ApplicationStateManager(){
    currentState = NULL;
}

void ApplicationStateManager::stateEnter(){
    currentState->stateEnter();
}

void ApplicationStateManager::stateEvent(){
    currentState->stateEvent();
}

void ApplicationStateManager::stateUpdate(){
    currentState->stateUpdate();
}

void ApplicationStateManager::stateRender(){
    currentState->stateRender();
}

bool ApplicationStateManager::stateExit(){
    return currentState->stateExit();
}