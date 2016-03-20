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
#include <string>

struct pointXY {
    int x;
    int y;
};

class PointData {
public:
    PointData();
    ~PointData();
    void readFromFile(std::string);
    std::vector<pointXY> dataPoints;
private:
    void addData(int x,int y);
};


#endif /* PointData_h */
