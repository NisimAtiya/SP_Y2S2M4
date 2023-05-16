#include <iostream>
#include "Point.hpp"
#include "Cowboy.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

using namespace std;

int main() {
    Point a(1,0),b(1,3);
//    cout<<"The x-coordinate of point A: "<< a.getX()<<endl;
//    cout<<"The x-coordinate of point B: "<< b.getY()<<endl;
//    cout<<"The distance between point a and point b is: " <<a.distance(b)<<endl;
//    Point c = Point::moveTowards(a,b,3);
//    Point d = Point::moveTowards(a,b,1);
//    c.print();
//    d.print();
//~Character();


//    Cowboy *tom = new Cowboy("Tom", a);
//    cout<<tom->getLocation().toString()<<endl;
//    cout<<tom->getName()<<endl;
//    cout<<tom->getHitPoints()<<endl;
//    cout<<tom->isAlive()<<endl;
//    tom->hit(10);
//    cout<<tom->getHitPoints()<<endl;
//    Cowboy *nisim = new Cowboy("Nisim", a);
//    nisim->shoot(tom);
//    cout<<tom->getHitPoints()<<endl;
//    cout<<nisim->print()<<endl;
//    cout<<nisim->getAmountBalls()<<endl;
//    nisim->reload();
//    cout<<nisim->getAmountBalls()<<endl;
    Ninja *tom = new Ninja("Tom", a,100,14);
    cout<<tom->getLocation().toString()<<endl;
    cout<<tom->getName()<<endl;
    cout<<tom->getHitPoints()<<endl;
    cout<<tom->isAlive()<<endl;
    tom->hit(10);
    cout<<tom->getHitPoints()<<endl;
    Ninja *nisim = new Ninja("Nisim", b,100,14);
    nisim->slash(tom);
    cout<<tom->getHitPoints()<<endl;
    cout<<nisim->print()<<endl;
    nisim->move(tom);
    nisim->slash(tom);
    cout<<tom->getHitPoints()<<endl;












    return 0;
}

