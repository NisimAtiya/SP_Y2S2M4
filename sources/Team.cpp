//
// Created by Nisim Atiya on 02/05/2023.
//

#include "Team.hpp"
#include <iostream>
#include <limits>

using namespace std;
void Team::add(Character *other) {
    // Check if the character already belongs to a team
    if (other->getInTeam()) {
        throw runtime_error("Character belongs to a team!!!");
    }

    // Check if the team is already full
    if (size_ >= 10) {
        throw runtime_error("The team is full!!!");
    }

    // Add the character to the team
    vector_team_.push_back(other);

    // Set the 'inTeam' flag of the 'other' character to true
    other->setInTeam(true);
    size_++;
}


void Team::attack(Team* other_team) {
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
        }  if (character->isAlive()) {
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
        }  if (character->isAlive()) {
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


    // Release all characters in the vector_team_
    for (Character* character : vector_team_) {
        delete character;
    }
}


Character* Team::getClosest(Team *other) {
    double min_dis = numeric_limits<double>::max();
    Character* closest_enemy = nullptr;
    for (Character* character : other->getTeamMembers()){
        if(character->isAlive()){
            if(this->getLeader()->distance(character)<min_dis){
                min_dis = this->getLeader()->distance(character);
                closest_enemy = character;
            }
        }
    }
    return closest_enemy;
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

Team::Team(const Team &other) {
    vector_team_ = other.vector_team_;
    leader_= other.leader_;
    size_ = other.size_;

}

Team &Team::operator=(const Team &other) {
    if(this == &other){
        return *this;
    }
    vector_team_ = other.vector_team_;
    leader_ = other.leader_;
    size_ = other.size_;

    return *this;
}

Team::Team(Team &&other) noexcept{
    vector_team_ = other.vector_team_;
    leader_ = other.leader_;
    size_=other.size_;
}

Team &Team::operator=(Team &&other) noexcept{
    vector_team_ = other.vector_team_;
    leader_ = other.leader_;
    size_ = other.size_;

    return *this;
}







