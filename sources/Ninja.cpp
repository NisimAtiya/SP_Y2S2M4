//
// Created by Nisim Atiya on 02/05/2023.
//

#include "Ninja.hpp"



void Ninja::move(Character *other) {
    Point new_location = Point::moveTowards(location_,other->getLocation(),speed_);
    location_ = new_location;
}

void Ninja::slash( Character *other) {
    if(!other->isAlive()){
        throw runtime_error("The enemy is dead!!");
    }
    double distance = location_.distance(other->getLocation());
    if(isAlive() && distance <=1){
        other->hit(40);
    }

}


string Ninja::print() {
    return "N-" + Character::print();
}
