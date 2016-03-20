//
//  PointData.h
//  ROBO_mapping
//
//  Created by Benjamin Emdon on 2016-03-19.
//  Copyright © 2016 Ben Emdon. All rights reserved.
//

#ifndef PointData_h
#define PointData_h
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
using namespace std;

struct pointXY {
    double x;
    double y;
};

class PointData {
public:
    PointData();
    ~PointData();
    void createTestData();
    void readFromFile();
    std::vector<pointXY> dataPoints;
private:
    void addData(double x,double y);
};


#endif /* PointData_h */
