#include <iostream>
#include "utilityHLS.h"
#include "box.h"

int main() {

    std::cout << "box vector of objects with iterator" << std::endl;
    // create vector of objects
    vectorHLS<box> v;

    // create object of class box
    box b0;
    // fill the class variables
    b0.setX(7);
    //std::cout << "box->x:    " << b0.getX() << std::endl;
    b0.setY(3.5);
    //std::cout << "box->y:    " << b0.getY() << std::endl;
    // push back the object in vector v
//    v.push_back(b0);
//
//    // create object of class box
//    box b1;
//    // fill the class variables
//    b1.setX(9);
//    std::cout << "box->x:    " << b1.getX() << std::endl;
//    b1.setY(5.5);
//    std::cout << "box->y:    " << b1.getY() << std::endl;
//    // push back the object in vector v
//    v.push_back(b1);
//
//    // create object of class box
//    box b2;
//    // fill the class variables
//    b2.setX(11);
//    std::cout << "box->x:    " << b2.getX() << std::endl;
//    b2.setY(7.5);
//    std::cout << "box->y:    " << b2.getY() << std::endl;
//    // push back the object in vector v
//    v.push_back(b2);
//
//    // use iterator
//    for(auto itr1=v.begin(); itr1!=v.end(); ++itr1)
//        std::cout << "Elements:   " << &itr1 << std::endl;
//
//    // use range-based loop
//    for(const auto &itr2 : v)
//        std::cout << "Elements:   " << &itr2 << std::endl;
    
    // test vectorHLS expand function
    for(int i=0; i<6; i++) {
        v.push_back(b0);
    }

    // use range-based loop
    for(const auto &itr2 : v)
        std::cout << "Elements:   " << itr2.getY() << std::endl;

//    std::cout << "box pair class" << std::endl;
//    pairHLS<int, float> p1(13, 15.5);
//    std::cout << "pair.first:     " << p1.first   <<std::endl;
//    std::cout << "pair.second:    " << p1.second  <<std::endl;
//
//    std::cout << "box make_pair function" << std::endl;
//    pairHLS<double, char> p2 = make_pairHLS(15.5, 'a');
//    std::cout << "pair.first:     " << p2.first   <<std::endl;
//    std::cout << "pair.second:    " << p2.second  <<std::endl;

    std::cout << "end of main function!!!" << std::endl;
    return 0;
}