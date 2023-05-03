//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_COWBOY_HPP
#define SP_Y2S2M4_COWBOY_HPP
#include "Character.hpp"



class Cowboy : public Character{
    private:
        int amount_balls;
    public:
        Cowboy(string,Point);
        void shoot(Character*);
        bool hasboolets();
        void reload();
        string Print();
        ~Cowboy();


};


#endif //SP_Y2S2M4_COWBOY_HPP
