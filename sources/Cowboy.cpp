//
// Created by Nisim Atiya on 02/05/2023.
//
#include "Cowboy.hpp"
using namespace std;



void Cowboy::shoot(Character *other) {
    if(!other->isAlive()){
        throw runtime_error("The enemy is dead!!");
    }
    if(isAlive() && amount_balls_ > 0){
        other->hit(10);
        amount_balls_=amount_balls_-1;
    }
}



string Cowboy::print() {
    return "c" + Character::print();
}



