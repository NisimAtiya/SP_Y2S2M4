//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_COWBOY_HPP
#define SP_Y2S2M4_COWBOY_HPP
#include "Character.hpp"



class Cowboy : public Character{
    private:
        int amount_balls_;
    public:
        Cowboy(string name,Point location):Character(name,location,110),amount_balls_(6){}
        void shoot(Character*);
        bool hasboolets() const{return amount_balls_>=6;}
        void reload(){amount_balls_=6;}
    int getAmountBalls(){return amount_balls_;}
        string print();



};


#endif //SP_Y2S2M4_COWBOY_HPP
