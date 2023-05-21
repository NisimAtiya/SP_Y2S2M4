//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_TRAINEDNINJA_HPP
#define SP_Y2S2M4_TRAINEDNINJA_HPP
const int Trained_LIFE_ = 120;
const int Trained_SPEED_ = 12;

#include "Ninja.hpp"

class TrainedNinja : public Ninja{
public:
    TrainedNinja(string name, Point location) : Ninja(std::move(name), Trained_LIFE_, location, Trained_SPEED_) {}


};


#endif //SP_Y2S2M4_TRAINEDNINJA_HPP