//
// Created by Nisim Atiya on 02/05/2023.
//

#include "Ninja.hpp"



void Ninja::move(Character *other) {
    Point new_location = Point::moveTowards(location_,other->getLocation(),speed_);
    location_ = new_location;
}

void Ninja::slash( Character *other) {
    if(other== this){
        throw runtime_error("No self harm!!");
    }
    if(!other->isAlive()){
        throw runtime_error("The enemy is dead!!");
    }
    if(!this->isAlive()){
        throw runtime_error("You're dead!!");
    }
    double distance = location_.distance(other->getLocation());
    if(distance <=1){
        other->hit(40);
    }

}


string Ninja::print() {
    return "N-" + Character::print();
}