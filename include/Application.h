//
//  Application.hpp
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#ifndef Application_h
#define Application_h

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#ifdef _WIN32
#include <SDL.h>
#elif __APPLE__
#include <SDL2/SDL.h>
#endif

using namespace std;

class ApplicationStateManager;

class Application{
public:
    Application();
    ~Application();
    int startApplication();
    bool init();
    void closeApplication();
protected:
    ApplicationStateManager *applicationStateManager;
};

extern SDL_Window *gWindow;
extern SDL_Renderer *gRenderer;
extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

#endif /* Application_h */
