//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_POINT_HPP
#define SP_Y2S2M4_POINT_HPP
namespace ariel{}
#include <string>
using namespace std;


class Point {
private:
    double _x_;
    double _y_;
public:
    Point(double x_coordinate = 0, double y_coordinate = 0):
            _x_(x_coordinate),_y_(y_coordinate){}
    double getX() const{return _x_;}
    double getY() const{return _y_;}
    double distance(Point);
    static Point moveTowards(Point, Point , double );
    void print();
    string toString();

};


#endif //SP_Y2S2M4_POINT_HPP