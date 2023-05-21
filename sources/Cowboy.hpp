//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_COWBOY_HPP
#define SP_Y2S2M4_COWBOY_HPP
#include "Character.hpp"



class Cowboy : public Character{
    private:
        int amount_balls_;
        static const int hp = 10;
        static const int balls = 6;

public:
    Cowboy(const string& name,  Point location)
            : Character(name, location, hp), amount_balls_(balls) {}
        void shoot(Character*);
        bool hasboolets() const{return amount_balls_>0;}
        void reload(){
            if(!isAlive()){
                throw runtime_error("Dead cowboy can not reload!!!");
            }
            amount_balls_=6;}
        int getAmountBalls(){return amount_balls_;}
        string print() override;



};


#endif //SP_Y2S2M4_COWBOY_HPP
