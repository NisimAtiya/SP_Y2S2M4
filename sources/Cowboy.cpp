//
// Created by Nisim Atiya on 02/05/2023.
//
#include "Cowboy.hpp"
#define DAMAGE 10
using namespace std;




void Cowboy::shoot(Character *other) {
    if(other== this){
        throw runtime_error("No self harm!!");
    }
    if(!other->isAlive()){
        throw runtime_error("The enemy is dead!!");
    }
    if(!this->isAlive()){
        throw runtime_error("You're dead!!");
    }
    if( amount_balls_ > 0){
        other->hit(DAMAGE);
        amount_balls_=amount_balls_-1;
    }
}



string Cowboy::print() {
    return "C-" + Character::print();
}


