//
// Created by Nisim Atiya on 02/05/2023.
//

#include "Team.hpp"

void Team::add(Character *other) {
    // Check if the character already belongs to a team
    if (other->getInTeam()) {
        throw runtime_error("Character belongs to a team!!!");
    }

    // Check if the team is already full
    if (vector_team_.size() >= 9) {
        throw runtime_error("The team is full!!!");
    }

    // Add the character to the team
    vector_team_.push_back(other);

    // Set the 'inTeam' flag of the 'other' character to true
    other->setInTeam(true);
}


void Team::attack(Team *other_team) {

}

int Team::stillAlive() {
    int cnt = 0;

    // Check if the leader is alive
    if (leader_->isAlive())
        cnt++;  // Increment count if the leader is alive

    int team_size = vector_team_.size();

    // Iterate over the team members
    for (int i = 0; i < team_size; ++i) {
        // Check if the team member is alive
        if (vector_team_[i]->isAlive())
            cnt++;  // Increment count if the team member is alive
    }

    return cnt;  // Return the total count of alive members
}


void Team::print() {
    int team_size = vector_team_.size();
    Ninja* ninjaPtr = nullptr;
    Cowboy* cowboyPtr = nullptr;

    // Check if the leader is a Cowboy
    cowboyPtr = dynamic_cast<Cowboy*>(leader_);
    if (cowboyPtr) {
        leader_->Print();  // Print leader's information (Cowboy-specific)
    }

    // Iterate over the team members  of Cowboy
    for (int i = 0; i < team_size; ++i) {
        // Check if the team member is a Cowboy
        cowboyPtr = dynamic_cast<Cowboy*>(vector_team_[i]);
        if (cowboyPtr) {
            vector_team_[i]->Print();  // Print team member's information (Cowboy-specific)
        }
    }

    // Iterate over the team members of Ninja
    for (int i = 0; i < team_size; ++i) {
        // Check if the team member is a Ninja
        ninjaPtr = dynamic_cast<Ninja*>(vector_team_[i]);
        if (ninjaPtr) {
            vector_team_[i]->Print();  // Print team member's information (Ninja-specific)
        }
    }

    // Check if the leader is a Ninja
    ninjaPtr = dynamic_cast<Ninja*>(leader_);
    if (ninjaPtr) {
        leader_->Print();  // Print leader's information (Ninja-specific)
    }
}


Team::~Team() {
    int team_size = vector_team_.size();

    // Destruct team members
    for (int i = 0; i < team_size; ++i) {
        vector_team_[i]->~Character();  // Explicitly call the destructor of each team member
    }

    // Destruct leader
    leader_->~Character();  // Explicitly call the destructor of the leader
}

