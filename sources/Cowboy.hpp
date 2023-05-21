//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_COWBOY_HPP
#define SP_Y2S2M4_COWBOY_HPP
#include "Character.hpp"
static const int DEFAULT_HIT_POINTS = 110;
static const int DEFAULT_AMOUNT_BALLS = 6;




class Cowboy : public Character{
private:
    int amount_balls_;

public:
    Cowboy(const string& name, const Point& location)
            : Character(name, location, DEFAULT_HIT_POINTS), amount_balls_(DEFAULT_AMOUNT_BALLS) {}
    void shoot(Character*);
    bool hasboolets() const{return amount_balls_>0;}
    void reload(){
        if(!isAlive()){
            throw runtime_error("Dead cowboy can not reload!!!");
        }
        amount_balls_=DEFAULT_AMOUNT_BALLS;}
    int getAmountBalls()const{return amount_balls_;}
    string print() override;



};


#endif //SP_Y2S2M4_COWBOY_HPP