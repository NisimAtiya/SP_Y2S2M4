//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_OLDNINJA_HPP
#define SP_Y2S2M4_OLDNINJA_HPP
#include "Ninja.hpp"
static const int hp = 150;
static const int old_speed = 8;

class OldNinja : public Ninja {
    public:
        OldNinja(string name ,Point location) : Ninja(name, location,hp,old_speed){}

};


#endif //SP_Y2S2M4_OLDNINJA_HPP
