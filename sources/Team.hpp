//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_TEAM_HPP
#define SP_Y2S2M4_TEAM_HPP
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include <vector>
using namespace std;

class Team {
    protected:
        Character *leader_;
        vector<Character*> vector_team_;
    public:
        Team(Character *leader):leader_(leader){}
        void add(Character*);
        virtual void attack(Team*);
        int stillAlive();
        void print();
        void setLeader(Character *newLeader){leader_= newLeader;}
        ~Team();



};


#endif //SP_Y2S2M4_TEAM_HPP
