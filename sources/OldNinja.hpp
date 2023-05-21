//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_OLDNINJA_HPP
#define SP_Y2S2M4_OLDNINJA_HPP
#include "Ninja.hpp"
static const int DEFAULT_HIT_POINTS = 150;
static const int DEFAULT_SPEED = 8;

class OldNinja : public Ninja {
public:
    OldNinja(string name, Point location) : Ninja(std::move(name), location, DEFAULT_HIT_POINTS, DEFAULT_SPEED) {}

};


#endif //SP_Y2S2M4_OLDNINJA_HPP