#include <sstream>
#include "doctest.h"
#include "sources/Point.hpp"
#include "sources/Cowboy.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/Team.hpp"

using namespace ariel;
TEST_CASE("Test on  Constructor of point"){
    CHECK_NOTHROW(Point p1(1.5, 2.5));
    CHECK_NOTHROW(Point p2=Point());
    CHECK_NOTHROW(Point p3(1, 2));

}

TEST_CASE("Test on  functions of point"){
    Point p1(1.5, 2.5);
    Point p2=Point();
    Point p3(1, 2);

    CHECK(p1.getX()==1.5);
    CHECK(p1.getY()==2.5);
    CHECK(p2.getX()==0);
    CHECK(p2.getY()==0);
    CHECK(p2.distance(p1) == 3.20156);
    CHECK(p1.distance(p2) == 3.20156);
    CHECK(p1.distance(p1) == 0);

    std::ostringstream oss;
    oss << "(" << p3.getX() << ", " << p3.getY() << ")";
    CHECK("(1.5,2.5)" == oss.str());


    Point source(1, 1);
    Point destination(4, 5);
    double distance = 4.5;
    Point result = source.moveTowards(source, destination, distance);
    CHECK(result.distance(destination) <= distance);
}
TEST_CASE("Test on Constructor of Cowboy"){
    CHECK_NOTHROW(Cowboy("nisim",Point(1,0)));
}
TEST_CASE("Test on the functions of Cowboy that do not throw errors"){
    Cowboy *c1 = new Cowboy("nisim",Point(1,0));
    Cowboy *c2 = new Cowboy("yosi",Point(1,0));
    CHECK_NOTHROW(c1->isAlive());
    CHECK_NOTHROW(c1->distance(c2));
    CHECK_NOTHROW(c1->hit(3));
    CHECK_NOTHROW(c1->getName());
    CHECK_NOTHROW(c1->getLocation());
    CHECK_NOTHROW(c1->shoot(c2));
    CHECK_NOTHROW(c1->reload());
    CHECK_NOTHROW(c1->print());
    CHECK_NOTHROW(c1->hasboolets());

}
TEST_CASE("Test on  functions of Cowboy"){
    Cowboy *c1 = new Cowboy("nisim",Point(1,0));
    Cowboy *c2 = new Cowboy("yosi",Point(1,0));

    CHECK(c1->isAlive() == true);
    CHECK(c1->distance(c2)==0);
    CHECK(c1->getName()=="nisim");
    CHECK(c1->hasboolets()== true);
}
TEST_CASE("Test on the functions of YoungNinja that do not throw errors"){
    YoungNinja *c1 = new YoungNinja("nisim",Point(1,0));
    YoungNinja *c2 = new YoungNinja("yosi",Point(1,0));
    CHECK_NOTHROW(c1->isAlive());
    CHECK_NOTHROW(c1->distance(c2));
    CHECK_NOTHROW(c1->hit(3));
    CHECK_NOTHROW(c1->getName());
    CHECK_NOTHROW(c1->getLocation());
    CHECK_NOTHROW(c1->slash(c2));
    CHECK_NOTHROW(c1->move(c2));
    CHECK_NOTHROW(c1->print());

}
TEST_CASE("Test on  functions of YoungNinja"){
    YoungNinja *c1 = new YoungNinja("nisim",Point(1,0));
    YoungNinja *c2 = new YoungNinja("yosi",Point(1,0));

    CHECK(c1->isAlive() == true);
    CHECK(c1->distance(c2)==0);
    CHECK(c1->getName()=="nisim");
}
TEST_CASE("Test on the functions of TrainedNinja that do not throw errors"){
    TrainedNinja *c1 = new TrainedNinja("nisim",Point(1,0));
    TrainedNinja *c2 = new TrainedNinja("yosi",Point(1,0));
    CHECK_NOTHROW(c1->isAlive());
    CHECK_NOTHROW(c1->distance(c2));
    CHECK_NOTHROW(c1->hit(3));
    CHECK_NOTHROW(c1->getName());
    CHECK_NOTHROW(c1->getLocation());
    CHECK_NOTHROW(c1->slash(c2));
    CHECK_NOTHROW(c1->move(c2));
    CHECK_NOTHROW(c1->print());

}
TEST_CASE("Test on  functions of TrainedNinja"){
    TrainedNinja *c1 = new TrainedNinja("nisim",Point(1,0));
    TrainedNinja *c2 = new TrainedNinja("yosi",Point(1,0));

    CHECK(c1->isAlive() == true);
    CHECK(c1->distance(c2)==0);
    CHECK(c1->getName()=="nisim");
}
TEST_CASE("Test on the functions of OldNinja that do not throw errors"){
    OldNinja *c1 = new OldNinja("nisim",Point(1,0));
    OldNinja *c2 = new OldNinja("yosi",Point(1,0));
    CHECK_NOTHROW(c1->isAlive());
    CHECK_NOTHROW(c1->distance(c2));
    CHECK_NOTHROW(c1->hit(3));
    CHECK_NOTHROW(c1->getName());
    CHECK_NOTHROW(c1->getLocation());
    CHECK_NOTHROW(c1->slash(c2));
    CHECK_NOTHROW(c1->move(c2));
    CHECK_NOTHROW(c1->print());

}
TEST_CASE("Test on  functions of OldNinja"){
    OldNinja *c1 = new OldNinja("nisim",Point(1,0));
    OldNinja *c2 = new OldNinja("yosi",Point(1,0));

    CHECK(c1->isAlive() == true);
    CHECK(c1->distance(c2)==0);
    CHECK(c1->getName()=="nisim");
}

TEST_CASE("Test on the functions of Team") {
    YoungNinja *ninja1=new YoungNinja("Ninja1", Point(0, 0));
    YoungNinja *ninja2=new YoungNinja("Ninja2", Point(1, 1));
    YoungNinja *ninja3=new YoungNinja("Ninja3", Point(2, 2));
    YoungNinja *leader_YoungNinja = new YoungNinja("leader_YoungNinja", Point(3, 3));
    Team team1(leader_YoungNinja);
    team1.add(ninja1);
    team1.add(ninja2);
    team1.add(ninja3);
    CHECK(team1.stillAlive() == 4);



    Cowboy *cowboy1 = new Cowboy("Cowboy1", Point(0, 0));
    Cowboy *cowboy2 = new Cowboy("Cowboy2", Point(1, 1));
    Cowboy *cowboy3 = new Cowboy("Cowboy3", Point(2, 2));
    Cowboy *leader_cowboy = new Cowboy("LeaderCowboy", Point(3, 3));
    Team team2(leader_cowboy);
    team2.add(cowboy1);
    team2.add(cowboy2);
    team2.add(cowboy3);
    CHECK(team2.stillAlive() == 4);
    team1.attack(&team2);

    REQUIRE(team2.stillAlive() < 4);
    REQUIRE(team1.stillAlive() == 4);

    // Test print function
    team1.print();
}
