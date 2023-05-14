//
// Created by Nisim Atiya on 02/05/2023.
//

#include "Point.hpp"

Point::Point(double x, double y) {
    this->x_=x;
    this->y_=y;
}

double Point::distance(Point other) {
    return 0;
}

Point Point::moveTowards(Point src, Point dest ,double distance) {
    return Point(0, 0);
}

Point::Point() {

}

double Point::getX() const {
    return 0;
}

double Point::getY() const {
    return 0;
}

void Point::print() {

}
