//
// Created by Nisim Atiya on 23/05/2023.
//

#ifndef SP_Y2S2M4_SMARTTEAM_HPP
#define SP_Y2S2M4_SMARTTEAM_HPP

#include <limits>
#include "Team.hpp"
class SmartTeam : public Team{
public:
    SmartTeam(Character *leader):Team(leader){
        setSize(1);
    }
    void attack(Team *other_team) override;
    static Character* getClosestToNinja(Ninja *ninja, Team *other);
    Character* getWeakest(Team *other);




};

#endif //SP_Y2S2M4_SMARTTEAM_HPP
