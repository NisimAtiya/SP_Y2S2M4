//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_POINT_HPP
#define SP_Y2S2M4_POINT_HPP
namespace ariel{}


class Point {
    private:
        double x_;
        double y_;
    public:
        Point(double ,double );
        Point();
    double distance(Point);
        Point moveTowards(Point,Point ,double );

};


#endif //SP_Y2S2M4_POINT_HPP
