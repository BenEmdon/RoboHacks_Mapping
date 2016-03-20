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

class DrawingBoard {
public:
    DrawingBoard();
    ~DrawingBoard();
    void drawLines();
    void drawBoard();
private:
    double maxX;
    double maxY;
};
#endif /* DrawingBoard_h */