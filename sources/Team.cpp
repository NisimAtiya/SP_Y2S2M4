//
// Created by Nisim Atiya on 02/05/2023.
//

#include "Team.hpp"
#include <iostream>
using namespace std;
void Team::add(Character *other) {
    // Check if the character already belongs to a team
    if (other->getInTeam()) {
        throw runtime_error("Character belongs to a team!!!");
    }

    // Check if the team is already full
    if (size_ > 10) {
        throw runtime_error("The team is full!!!");
    }

    // Add the character to the team
    vector_team_.push_back(other);

    // Set the 'inTeam' flag of the 'other' character to true
    other->setInTeam(true);
    size_++;
}


void Team::attack(Team* other_team) {
    // Checking that there is someone to attack
    if (other_team->stillAlive() == 0) return;

    // Checking that I can attack
    if (this->stillAlive() == 0) return;

    // Checking that I'm not attacking myself
    if (leader_ == other_team->getLeader()) {
        throw runtime_error("You are trying to attack yourself!!!");
    }

    // Check if the leader of the attacking team is alive and if not replace him with the player closest to him
    if (!leader_->isAlive()) {
        leader_ = this->getNewLeader();
    }

    // Find the victim from the enemy group
    Character* victim = this->getClosest(other_team);

    // Attack the chosen victim with all the Cowboys
    for (Character* character : vector_team_) {
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
        }
    }

    // Attack the chosen victim with all the Ninjas
    for (Character* character : vector_team_) {
        // Check if the victim is dead
        if (!victim->isAlive()) {
            if (other_team->stillAlive() == 0) return;
            victim = this->getClosest(other_team);
        } else if (character->isAlive()) {
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





int Team::stillAlive() {
    int cnt = 0;

    size_t team_size = vector_team_.size();

    // Iterate over the team members
    for (size_t i = 0; i < team_size; ++i) {
        // Check if the team member is alive
        if (vector_team_.at(i)->isAlive())
            cnt++;  // Increment count if the team member is alive
    }

    return cnt;  // Return the total count of alive members
}


void Team::print() {
    Ninja* ninjaPtr = nullptr;
    Cowboy* cowboyPtr = nullptr;


    size_t team_size = vector_team_.size();

    // Iterate over the team members  of Cowboy
    for (size_t i = 0; i < team_size; ++i) {
        // Check if the team member is a Cowboy
        cowboyPtr = dynamic_cast<Cowboy*>(vector_team_.at(i));
        if (cowboyPtr) {
            cout<<vector_team_.at(i)->print()<<endl;  // Print team member's information (Cowboy-specific)
        }
    }

    // Iterate over the team members of Ninja
    for (size_t i = 0; i < team_size; ++i) {
        // Check if the team member is a Ninja
        ninjaPtr = dynamic_cast<Ninja*>(vector_team_.at(i));
        if (ninjaPtr) {
            cout<<vector_team_.at(i)->print()<<endl;  // Print team member's information (Ninja-specific)
        }
    }


}


Team::~Team() {
    // Clear the vector to remove all elements
    vector_team_.clear();

    // Set the leader pointer to null
    leader_ = nullptr;
}

Character* Team::getClosest(Team *other) {
    Ninja* ninjaPtr = nullptr;
    Cowboy* cowboyPtr = nullptr;
    double minDistance = numeric_limits<double>::max();
    size_t j = 0;

    size_t team_size = other->getTeamMembers().size();

    // Iterate over the team members of Cowboys
    for (size_t i = 0; i < team_size; ++i) {
        // Check if the team member is a Cowboy
        cowboyPtr = dynamic_cast<Cowboy*>(other->getTeamMembers().at(i));
        double tempDistance = other->getTeamMembers().at(i)->distance(leader_);
        if (cowboyPtr && cowboyPtr->isAlive() && tempDistance < minDistance) {
            minDistance = tempDistance;
            j = i;
        }
    }

    // Iterate over the team members of Ninjas
    for (size_t i = 0; i < team_size; ++i) {
        // Check if the team member is a Ninja
        ninjaPtr = dynamic_cast<Ninja*>(other->getTeamMembers().at(i));
        double tempDistance = other->getTeamMembers().at(i)->distance(leader_);
        if (ninjaPtr && ninjaPtr->isAlive() && tempDistance < minDistance) {
            minDistance = tempDistance;
            j = i;
        }
    }

    // Return the closest living team member
    return other->getTeamMembers().at(j);
}

Character* Team::getNewLeader() {
    if (leader_->isAlive()) {
        return leader_; // If the current leader is alive, return the current leader
    }

    double minDistance = numeric_limits<double>::max();
    Character* newLeader = nullptr;

    for (Character* character : vector_team_) {
        if (character->isAlive()) {
            double distance = character->distance(leader_);
            if (distance < minDistance && leader_!=character) {
                minDistance = distance;
                newLeader = character;
            }
        }
    }

    return newLeader;
}




