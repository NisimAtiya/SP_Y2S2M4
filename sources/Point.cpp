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
    return sqrt(pow((x_ - other.getX()), 2) + pow((y_ - other.getY()), 2));
}

Point Point::moveTowards(Point p1, Point p2, double r) {
    double distance = p1.distance(p2);
    if (r>= distance){
        return p2;
    }
    double x = p1.getX() + ((p2.getX() - p1.getX()) * r / distance);
    double y = p1.getY() + ((p2.getY() - p1.getY()) * r / distance);
    return Point(x,y);
}

string Point::toString() {
    return "("+ to_string(getX())+","+ to_string(getY())+")";
}


