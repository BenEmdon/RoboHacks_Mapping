//
//  DrawingBoard.cpp
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#include "DrawingBoard.h"
#include "MappingState.h"

DrawingBoard::DrawingBoard() {
    
}

DrawingBoard::~DrawingBoard() {
    
}

void DrawingBoard::drawLines() {
    
}

void DrawingBoard::drawBoard() {
    SDL_SetRenderDrawColor( gRenderer, 200, 200, 200, 200 );
    // Create the outline rect //
    SDL_Rect outLine = {100 , 100, 800, 500};
    // Call to render //
    SDL_RenderDrawRect(gRenderer, &outLine);
}