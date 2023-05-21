//
// Created by Nisim Atiya on 02/05/2023.
//

#include "Point.hpp"
#include <iostream>
#include <math.h>
using namespace std;


void Point::print() {
    cout << "("<<getX()<<","<<getY()<<")"<<endl;
}

double Point::distance(const Point other) {
    return sqrt(pow((_x_ - other.getX()), 2) + pow((_y_ - other.getY()), 2));
}

Point Point::moveTowards(Point p1, Point p2, double r) {
    if (r < 0) {
        throw std::invalid_argument("Distance cannot be a negative number");
    }

    double current_distance = p1.distance(p2);
    if (current_distance <= r) {
        return p2;
    } else {
        double ratio = r / current_distance;
        double new_x = (1 - ratio) * p1.getX() + ratio * p2.getX();
        double new_y = (1 - ratio) * p1.getY() + ratio * p2.getY();
        return Point(new_x, new_y);
    }
}

string Point::toString() {
    return "("+ to_string(getX())+","+ to_string(getY())+")";
}


