//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_CHARACTER_HPP
#define SP_Y2S2M4_CHARACTER_HPP
#include <string>
#include "Point.hpp"

using namespace std;


class Character {
    private:
        string name_;
        Point location_;
        int hit_points_;



    public:
        Character(string name, Point location,int hit_points):name_(name), location_(location),hit_points_(hit_points){}
        virtual bool isAlive()=0;
        virtual double distance(const Character *)=0;
        virtual void hit(int)=0;
        virtual string getName()=0;
        virtual Point getLocation()=0;
        virtual string print()=0;

};


#endif //SP_Y2S2M4_CHARACTER_HPP
