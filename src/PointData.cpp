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
    for (int i = 0; i < 10; i++) {
        pointXY p={i*10.0, i*5.0};
        dataPoints.push_back(p);
    }
}