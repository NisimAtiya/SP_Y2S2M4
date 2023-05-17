//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_NINJA_HPP
#define SP_Y2S2M4_NINJA_HPP
#include "Character.hpp"


class Ninja : public Character{
    private:
        int speed_=0;
    public:

        Ninja(string,Point);
        void move(const Character*);
        void slash( Character*);
	Ninja() = default;
	Ninja(const Ninja& other) = default;
	Ninja& operator=(const Ninja& other) = default;
	Ninja(Ninja&& other) = default;
	Ninja& operator=(Ninja&& other) = default;
	string print() override;
	~Ninja() override = default;


};


#endif //SP_Y2S2M4_NINJA_HPP
