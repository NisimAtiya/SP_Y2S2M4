//
// Created by Nisim Atiya on 23/05/2023.
//

#include "SmartTeam.hpp"

Character *SmartTeam::getWeakest(Team *other) {
    double min_hp = numeric_limits<double>::max();
    Character* Weakest_enemy = nullptr;
    for (Character* character : other->getTeamMembers()){
        if(character->isAlive()){
            if(character->getHitPoints()<min_hp){
                min_hp = character->getHitPoints();
                Weakest_enemy = character;
            }
        }
    }
    return Weakest_enemy;
}

Character *SmartTeam::getClosestToNinja(Ninja *ninja, Team *other) {
    double min_dis = numeric_limits<double>::max();
    Character* closest_enemy = nullptr;
    for (Character* character : other->getTeamMembers()){
        if(character->isAlive()){
            if(ninja->distance(character)<min_dis){
                min_dis = ninja->distance(character);
                closest_enemy = character;
            }
        }
    }
    return closest_enemy;
}

void SmartTeam::attack(Team *other_team) {
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
    Character* victim = this->getWeakest(other_team);

    // Attack the chosen victim with all the Cowboys
    for (Character* character : this->getTeamMembers()) {
        auto* ninja = dynamic_cast<Ninja*>(character);
        auto* cowboy = dynamic_cast<Cowboy*>(character);
        // Check if the victim is dead
        if (!victim->isAlive()) {
            if (other_team->stillAlive() == 0) return;
            // Choose a new victim, the living enemy character closest to the leader
            victim = this->getWeakest(other_team);
        }
        if (character->isAlive()) {

            if (cowboy != nullptr) {
                if (cowboy->hasboolets()) {
                    cowboy->shoot(victim);
                } else {
                    cowboy->reload();
                }
            }
            if (ninja != nullptr) {
                // Check if the victim is dead
                if (!victim->isAlive()) {
                    if (other_team->stillAlive() == 0) return;
                    victim = SmartTeam::getClosestToNinja(ninja,other_team);
                }
                if (ninja->distance(victim) <= 1) {
                    ninja->slash(victim);
                } else {
                    ninja->move(victim);

                }
            }

        }

    }

    // Attack the chosen victim with all the Ninjas
    for (Character* character : this->getTeamMembers()) {
        if (character->isAlive()) {
            auto* ninja = dynamic_cast<Ninja*>(character);
            if (ninja != nullptr) {
                // Check if the victim is dead
                if (!victim->isAlive()) {
                    if (other_team->stillAlive() == 0) return;
                    victim = SmartTeam::getClosestToNinja(ninja,other_team);
                }
                if (ninja->distance(victim) <= 1) {
                    ninja->slash(victim);
                } else {
                    ninja->move(victim);

                }
            }
        }
    }

}

