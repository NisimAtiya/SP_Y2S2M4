//
// Created by Nisim Atiya on 02/05/2023.
//

#include "Character.hpp"

bool Character::isAlive() {
    return false;
}

double Character::distance(const Character *) {
    return 0;
}

void Character::hit(int) {

}

string Character::getName() {
    return std::string();
}

Point Character::getLocation() {
    return Point(0, 0);
}

string Character::print() {
    return "";

}

Character::Character() {

}
