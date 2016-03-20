//
//  PointData.cpp
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#include "PointData.h"

//
//  PointData.cpp
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

//#include "PointData.h"
#include "PointData.h"
#include <assert.h>


PointData::PointData() {
    readFromFile();
}

PointData::~PointData() {
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

void PointData::readFromFile()
{
    double x, y;
    
    string line;
    ifstream infile ("data/data.txt");
    
    
    if (infile.is_open())
    {
        while (getline(infile, line))
        {
            stringstream infile(line);
            infile >> x >> y;
            addData(x, y);
        }
        infile.close();
    }
    
    else cout << "Unable to open file";
}

void PointData::addData(double x, double y)
{
    pointXY p = { x, y };
    dataPoints.push_back(p);
}