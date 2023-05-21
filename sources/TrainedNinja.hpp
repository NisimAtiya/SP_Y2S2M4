//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_TRAINEDNINJA_HPP
#define SP_Y2S2M4_TRAINEDNINJA_HPP
const int LIFE_ = 120;
const int SPEED_ = 12;

#include "Ninja.hpp"

class TrainedNinja : public Ninja{
public:
    TrainedNinja(string name, Point location) : Ninja(name, location,LIFE_,SPEED_){}

};


#endif //SP_Y2S2M4_TRAINEDNINJA_HPP