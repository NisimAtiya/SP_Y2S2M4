//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_TEAM_HPP
#define SP_Y2S2M4_TEAM_HPP
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "Cowboy.hpp"
#include <vector>
using namespace std;

class Team {
    private:
        Character leader_;
        vector<Ninja> Ninja_grup_;
        vector<Cowboy> Cowboy_gru_;
    public:
        Team(const Ninja&);
        Team(const Cowboy&);
        void add(const Character&);
        void attack(Team&);
        int stillAlive();
        void print();
        ~Team();



};


#endif //SP_Y2S2M4_TEAM_HPP
