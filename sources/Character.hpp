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
        void(*print_fanc);
        void(*create);
protected:
    Character();

    public:
        bool isAlive();
        double distance(const Character&);
        void hit(int);
        string getName();
        Point getLocation();
        void print();

};


#endif //SP_Y2S2M4_CHARACTER_HPP
