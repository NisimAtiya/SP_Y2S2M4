//
// Created by Nisim Atiya on 18/05/2023.
//

#include "Team2.hpp"
#include <iostream>
#include <limits>

using namespace std;

void Team2::attack(Team *other_team) {
    if(other_team== nullptr){
        throw invalid_argument("invalid argument");
    }
    // Checking that there is someone to attack
    if (other_team->stillAlive() == 0) {
        throw runtime_error("Attacking a dead team!!!");
    }
    // Checking that I can attack
    if (this->stillAlive() == 0) return;

    // Checking that I'm not attacking myself
    if (this->getLeader() == other_team->getLeader()) {
        throw runtime_error("You are trying to attack yourself!!!");
    }

    // Check if the leader of the attacking team is alive and if not replace him with the player closest to him
    if (!this->getLeader()->isAlive()) {
        this->setLeader(this->getNewLeader());
    }

    // Find the victim from the enemy group
    Character* victim = this->getClosest(other_team);

    // Attack the chosen victim
    for (Character* character : this->getTeamMembers()) {
        // Check if the victim is dead
        if (!victim->isAlive()) {
            if (other_team->stillAlive() == 0) return;
            // Choose a new victim, the living enemy character closest to the leader
            victim = this->getClosest(other_team);
        } else if (character->isAlive()) {
            auto* cowboy = dynamic_cast<Cowboy*>(character);
            if (cowboy != nullptr) {
                if (cowboy->hasboolets()) {
                    cowboy->shoot(victim);
                } else {
                    cowboy->reload();
                }
            }
            auto* ninja = dynamic_cast<Ninja*>(character);
            if (ninja != nullptr) {
                if (ninja->distance(victim) <= 1) {
                    ninja->slash(victim);
                } else {
                    ninja->move(victim);
                }
            }
        }
    }
}

void Team2::print() {
    size_t team_size = this->getTeamMembers().size();
    // Iterate over the team members  of Cowboy
    for (size_t i = 0; i < team_size; ++i) {
        cout<<this->getTeamMembers().at(i)->print()<<endl;  // Print team member's information
    }
}

Character *Team2::getClosest(Team *other) {
    double minDistance = numeric_limits<double>::max();
    size_t j = 0;
    size_t team_size = other->getTeamMembers().size();

    // Iterate over the team members
    for (size_t i = 0; i < team_size; ++i) {
        double tempDistance = other->getTeamMembers().at(i)->distance(this->getLeader());
        if (other->getTeamMembers().at(i)->isAlive() && tempDistance < minDistance) {
            minDistance = tempDistance;
            j = i;
        }
    }
    // Return the closest living team member
    return other->getTeamMembers().at(j);
}