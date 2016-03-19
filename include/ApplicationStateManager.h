//
//  ApplicationStateManager.h
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#ifndef ApplicationStateManager_h
#define ApplicationStateManager_h

class ApplicationState;

class ApplicationStateManager{
public:
    ApplicationStateManager();
    ~ApplicationStateManager();
    void stateEnter();
    void stateEvent();
    void stateUpdate();
    void stateRender();
    bool stateExit();
    ApplicationState *currentState;
};

#endif /* ApplicationStateManager_h */
