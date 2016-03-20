//
//  DrawingBoard.h
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#ifndef DrawingBoard_h
#define DrawingBoard_h

#include "Application.h"
#include "PointData.h"
#include <vector>

class PointData;

struct pointXYInt {
    int x;
    int y;
};

class DrawingBoard {
public:
    DrawingBoard();
    ~DrawingBoard();
    void drawLines();
    void drawBoard();
private:
    void makeDataPlottable();
    PointData *data;
    vector<pointXYInt> plottableData;
    void getBounds();
    double maxX;
    double maxY;
    double fitInBoardX(int);
    double fitInBoardY(int);
};
#endif /* DrawingBoard_h */
