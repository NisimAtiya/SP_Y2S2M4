//
// Created by Nisim Atiya on 02/05/2023.
//
#include "Cowboy.hpp"
using namespace std;
static const int damage = 10;




void Cowboy::shoot(Character *other) {
    if(other == this){
        throw runtime_error("No self harm!!");
    }
    if(!other->isAlive()){
        throw runtime_error("The enemy is dead!!");
    }
    if(!this->isAlive()){
        throw runtime_error("You're dead!!");
    }
    if( amount_balls_ > 0){
        other->hit(damage);
        amount_balls_=amount_balls_-1;
    }
}



string Cowboy::print() {
    return "C-" + Character::print();
}



