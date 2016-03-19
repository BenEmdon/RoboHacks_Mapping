//
//  ApplicationState.h
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#ifndef ApplicationState_h
#define ApplicationState_h

class ApplicationState{
public:
    virtual void stateEnter() = 0;
    virtual void stateEvent() = 0;
    virtual void stateUpdate() = 0;
    virtual void stateRender() = 0;
    virtual bool stateExit() = 0;
};

#endif /* ApplicationState_h */