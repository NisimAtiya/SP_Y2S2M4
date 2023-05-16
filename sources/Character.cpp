//
// Created by Nisim Atiya on 02/05/2023.
//

#include "Character.hpp"



void Character::hit(int hit) {
    if (!isAlive()) return;
    hit_points_-=hit;
}





