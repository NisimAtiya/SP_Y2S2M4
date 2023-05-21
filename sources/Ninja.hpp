//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_NINJA_HPP
#define SP_Y2S2M4_NINJA_HPP
#include "Character.hpp"


class Ninja : public Character{
private:
    int speed_;
public:

    Ninja(string name, int hit_points, Point location,  int speed)
            : Character(std::move(name), location, hit_points), speed_(speed) {}
    void move(Character *);
    void slash( Character *);
    string print() override;

};


#endif //SP_Y2S2M4_NINJA_HPP