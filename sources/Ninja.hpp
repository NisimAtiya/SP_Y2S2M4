//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_NINJA_HPP
#define SP_Y2S2M4_NINJA_HPP
#include "Character.hpp"


class Ninja : public Character{
    private:
        int speed_;
    public:

        Ninja(string,Point);
        void move(const Character&);
        void slash( Character&);
        string Print();
        ~Ninja();
};


#endif //SP_Y2S2M4_NINJA_HPP
