//
// Created by Nisim Atiya on 02/05/2023.
//

#ifndef SP_Y2S2M4_CHARACTER_HPP
#define SP_Y2S2M4_CHARACTER_HPP
#include <string>
#include "Point.hpp"

using namespace std;


class Character {
    private:
    string name_;
        Point location_;
        int hit_points_;



    public:
        Character() : hit_points_(0) {}
        Character(Character const &)= default;

        bool isAlive();
        double distance(const Character *);
        void hit(int);
        string getName();
        Point getLocation();

    virtual string print();
            virtual ~Character() = default;
            Character& operator=(const Character& other) {
        if (this == &other) {
            return *this;
        }

        // Perform the necessary copying/assignment operations here

        return *this;
    }
    // Move constructor
    Character(Character&& other) = default;
    // Move assignment operator
    Character& operator=(Character&& other) noexcept {
	    if (this == &other) {
		return *this;
	    }
	    // Perform move assignment operations here
	    return *this;
	}


};


#endif //SP_Y2S2M4_CHARACTER_HPP
