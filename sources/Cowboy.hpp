//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_COWBOY_HPP
#define SP_Y2S2M4_COWBOY_HPP
#include "Character.hpp"



class Cowboy : public Character{
    private:
        int amount_balls=0;
    public:
        Cowboy(string,Point);
        void shoot(Character*);
        bool hasboolets();
        void reload();
        Cowboy() = default;
	Cowboy(const Cowboy& other) = default;
	Cowboy& operator=(const Cowboy& other) = default;
	Cowboy(Cowboy&& other) = default;
	Cowboy& operator=(Cowboy&& other) = default;
	string print() override;
	    ~Cowboy() override = default;





};


#endif //SP_Y2S2M4_COWBOY_HPP
