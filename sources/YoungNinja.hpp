//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_YOUNGNINJA_HPP
#define SP_Y2S2M4_YOUNGNINJA_HPP

const int Young_LIFE = 100;
const int Young_SPEED = 14;
#include "Ninja.hpp"

class YoungNinja : public Ninja{
public:
    YoungNinja(string name, Point location) : Ninja(std::move(name), Young_LIFE, location, Young_SPEED) {}

};


#endif //SP_Y2S2M4_YOUNGNINJA_HPP