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
    data = new PointData;
    getBounds();
    makeDataPlottable();
}

DrawingBoard::~DrawingBoard() {
    delete data;
}

void DrawingBoard::drawLines() {
    SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    for(int index = 0; index < plottableData.size(); index++) {
        if (index +1 == plottableData.size()) {
            SDL_RenderDrawLine(gRenderer, plottableData[index].x, plottableData[index].y, plottableData[0].x, plottableData[0].y);
        }
        else {
            SDL_RenderDrawLine(gRenderer, plottableData[index].x, plottableData[index].y, plottableData[index+1].x, plottableData[index+1].y);
        }
    }
    
}

void DrawingBoard::makeDataPlottable() {
    for(int index = 0; index < data->dataPoints.size(); index++) {
        pointXYInt p = {static_cast<int>(100 + (fitInBoardX(index)*(500))), static_cast<int>(100 + (fitInBoardY(index)*(500)))};
        plottableData.push_back(p);
    }
    
}

double DrawingBoard::fitInBoardX(int index) {
    return data->dataPoints[index].x/maxX;
}

double DrawingBoard::fitInBoardY(int index) {
    return data->dataPoints[index].y/maxY;
}


void DrawingBoard::drawBoard() {
    SDL_SetRenderDrawColor( gRenderer, 150, 150, 150, 200 );
    // Create the outline rect //
    SDL_Rect outLine = {100 , 100, 800, 500};
    // Call to render //
    SDL_RenderDrawRect(gRenderer, &outLine);
    for (int x = 0; x < 800; x+=50) {
        SDL_RenderDrawLine(gRenderer, 100 + x, 100, 100 + x, 600);
    }
    for (int y = 0; y <= 500; y+=50) {
        SDL_RenderDrawLine(gRenderer, 100 , 100+ y, 900, 100 + y);
    }
}


// This function was made at a DO_NOT_CARE moment and therfore isnt effecient and requires more work
void DrawingBoard::getBounds() {
    double largestX = 0, largestY = 0, smallestX = 0, smallestY = 0;
    for (int index = 0; index < data->dataPoints.size(); index++) {
        if (smallestX > data->dataPoints[index].x) {
            smallestX = data->dataPoints[index].x;
        }
        if (smallestY > data->dataPoints[index].y) {
            smallestY = data->dataPoints[index].y;
        }
    }
    //cout << smallestY << smallestX <<endl;
    if (smallestX < 0 || smallestY < 0) {
        for (int index = 0; index < data->dataPoints.size(); index++) {
            data->dataPoints[index].x += - smallestX;
            data->dataPoints[index].y += - smallestY;
        }
    }
    
    for (int index = 0; index < data->dataPoints.size(); index++) {
        if (largestX < data->dataPoints[index].x) {
            largestX = data->dataPoints[index].x;
        }
        if (largestY < data->dataPoints[index].y) {
            largestY = data->dataPoints[index].y;
        }
    }
    
    maxX = largestX;
    maxY = largestY;
}