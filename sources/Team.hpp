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
    int size_;
    Character* leader_;
    vector<Character*> vector_team_;

public:
    Team(Character *leader){
        // Check if the character already belongs to a team
        if (leader->getInTeam()) {
            throw runtime_error("Character belongs to a team!!!");
        }

        // Add the character to the team
        vector_team_.push_back(leader);

        // Set the 'inTeam' flag of the 'other' character to true
        leader->setInTeam(true);
        size_=1;
        leader_=leader;
    }
    Character* getLeader() {return leader_;}
    void add(Character*);
    virtual void attack(Team*);
    int stillAlive();
    virtual void print();
    void setLeader(Character *newLeader){leader_= newLeader;}
    ~Team();
    virtual Character* getClosest(Team *other);
    Character* getNewLeader();
    vector<Character*> getTeamMembers() {return vector_team_;}
    void setSize(int size){size_ = size;}
    int getSize(){return size_;}






};


#endif //SP_Y2S2M4_TEAM_HPP