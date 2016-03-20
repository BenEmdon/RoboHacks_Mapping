//
//  PointData.cpp
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#include "PointData.h"

PointData::PointData() {
    
}

PointData::~PointData(){
    dataPoints.clear();
}

void PointData::createTestData() {
    pointXY p={0, 0};
    dataPoints.push_back(p);
    p={10, 0};
    dataPoints.push_back(p);
    p={10, 25};
    dataPoints.push_back(p);
    p={-10, 20};
    dataPoints.push_back(p);
    p={-10, 20};
    dataPoints.push_back(p);
    
}