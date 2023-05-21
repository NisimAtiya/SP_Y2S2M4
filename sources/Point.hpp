//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_POINT_HPP
#define SP_Y2S2M4_POINT_HPP
namespace ariel{}
#include <string>
using namespace std;


class Point {
protected:
    double x_;
    double y_;
public:
    Point(double x=0 ,double y=0 ):
            x_(x),y_(y){}
    double getX() const{return x_;}
    double getY() const{return y_;}
    double distance(Point const);
    static Point moveTowards(Point, Point , double );
    void print();
    string toString();

};


#endif //SP_Y2S2M4_POINT_HPP