//
// Created by Nisim Atiya on 18/05/2023.
//

#ifndef SP_Y2S2M4_TEAM2_HPP
#define SP_Y2S2M4_TEAM2_HPP

#include "Team.hpp"
class Team2 : public Team{
public:
    Team2(Character *leader):Team(leader){
        setSize(1);
    }
    void attack(Team*);
    void print();
    Character* getClosest(Team *other);




};


#endif //SP_Y2S2M4_TEAM2_HPP