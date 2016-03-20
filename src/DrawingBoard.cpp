//
//  DrawingBoard.cpp
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#include "DrawingBoard.h"
#include "MappingState.h"
#include "PointData.h"

DrawingBoard::DrawingBoard() {
    data = new PointData;
    data->createTestData();
    getBounds();
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

void DrawingBoard::getBounds() {
    double largestX = 0, largestY = 0;
    for (int index = 0; index < data->dataPoints.size(); index++) {
        if (largestX < data->dataPoints[index].x) {
            largestX = data->dataPoints[index].x;
        }
        if (largestY < data->dataPoints[index].y) {
            largestY = data->dataPoints[index].y;
        }
    }
}