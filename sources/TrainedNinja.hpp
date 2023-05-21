//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_TRAINEDNINJA_HPP
#define SP_Y2S2M4_TRAINEDNINJA_HPP
#include "Ninja.hpp"

class TrainedNinja : public Ninja{
public:
    TrainedNinja(string name, Point location) : Ninja(name, location,120,12){}

};


#endif //SP_Y2S2M4_TRAINEDNINJA_HPP