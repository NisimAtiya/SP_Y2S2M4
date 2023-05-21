//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_NINJA_HPP
#define SP_Y2S2M4_NINJA_HPP
#include "Character.hpp"


class Ninja : public Character{
protected:
    int speed_;
public:

    Ninja(string name ,Point location,int hit_points, int speed): Character(name,location,hit_points),speed_(speed){}
    void move(Character *);
    void slash( Character *);
    string print();

};


#endif //SP_Y2S2M4_NINJA_HPP