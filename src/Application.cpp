//
//  Application.cpp
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//


#include "../include/Application.h"
#include "../include/ApplicationState.h"
#include "../include/ApplicationStateManager.h"

SDL_Window *gWindow;
SDL_Renderer *gRenderer;
const int SCREEN_WIDTH = 1000;
const int SCREEN_HEIGHT = 700;

Application::Application(){
    gWindow=NULL;
    gRenderer=NULL;
    // Checks if init was able to excute //
    if(!init()){
        cout<<"Could not load application!"<<endl;
    }
    applicationStateManager = new ApplicationStateManager;
}

Application::~Application(){
    delete applicationStateManager;
    applicationStateManager = NULL;
    
    SDL_DestroyWindow(gWindow);
    gWindow=NULL;
    
    SDL_DestroyRenderer(gRenderer);
    gRenderer=NULL;
}

bool Application::init(){
    bool initSuccessful = true;
    
    if(SDL_Init(SDL_INIT_VIDEO)>0)
    {
        cout<<"Failed init. SDL_ERROR: %s\n"<<SDL_GetError();
        initSuccessful = false;
    }
    else
    {
        if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
        {
            cout<<"Warning: Linear texture filtering not enabled!"<<endl;
        }
        
        gWindow=SDL_CreateWindow("Checkers",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH,SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
        
        if(gWindow==NULL)
        {
            cout<<"Couldnt make window. SDL_Error: %s\n"<<SDL_GetError()<<endl;
            initSuccessful = false;
        }
        else
        {
            gRenderer=SDL_CreateRenderer(gWindow,-1,SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
            if(gRenderer==NULL)
            {
                cout<<"Renderer failed. SDL_Error: %s\n"<<SDL_GetError()<<endl;
                initSuccessful = false;
            }
            else
            {
                SDL_SetRenderDrawColor(gRenderer,0xFF,0xFF,0xFF,0xFF);
            }
        }
        
        
    }
    return initSuccessful;
}

int Application::startApplication(){
    
    while (!applicationStateManager->stateExit()) {
        applicationStateManager->stateEvent();
        applicationStateManager->stateUpdate();
        // Light wood color //
        SDL_SetRenderDrawColor(gRenderer, 0x18, 0x45, 0x8A, 0xFF);
        // Refreshs screen //
        SDL_RenderClear(gRenderer);
        applicationStateManager->stateRender();
        SDL_RenderPresent(gRenderer);
        SDL_Delay(100);
    }
    
    closeApplication();
    
    return (EXIT_SUCCESS);
    
}

void Application::closeApplication(){
    SDL_Quit();
}