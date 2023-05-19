//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_CHARACTER_HPP
#define SP_Y2S2M4_CHARACTER_HPP
#include <string>
#include "Point.hpp"
#include <stdexcept>


using namespace std;


class Character {
protected:
    string name_;
    Point location_;
    int hit_points_;
    bool inTeam_;



public:
    Character(string name, Point location,int hit_points):
            name_(name), location_(location),hit_points_(hit_points),inTeam_(false){}
    Point getLocation(){return location_;}
    string getName(){return name_;}
    int getHitPoints() const{return hit_points_;}
    bool isAlive() const{return hit_points_>0;}
    double distance(Character *other){return location_.distance(other->getLocation());}
    void hit(int hit) {
        if(hit <=0){
            throw invalid_argument("hit must have a positive number");
        }
        if (!isAlive()) return;
        hit_points_-=hit;
    }
    virtual string print(){
        if (isAlive()){
            return " name: " + getName() + ", hit points: "  + to_string(getHitPoints()) +", location: " + getLocation().toString();

        }
        return " name: (" + getName() + "), location: " + getLocation().toString();
    }
    bool getInTeam() const{ return inTeam_;}
    void setInTeam(bool boolean){inTeam_=boolean;}
    virtual ~Character() = default;
};


#endif //SP_Y2S2M4_CHARACTER_HPP
