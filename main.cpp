#include <iostream>
#include "test.h"
#include "LRutilityHLS.h"

int main() {

    std::cout << "test vector of objects with iterator" << std::endl;
    // create vector of objects
    vector_<test*> v;

    // create object of class test
    test v0;
    // fill the class variables
    v0.setX(7);
    std::cout << "test->x:    " << v0.getX() << std::endl;
    v0.setY(3.5);
    std::cout << "test->y:    " << v0.getY() << std::endl;
    // push back the object in vector v
    v.push_back(&v0);

    // create object of class test
    test v1;
    // fill the class variables
    v1.setX(9);
    std::cout << "test->x:    " << v1.getX() << std::endl;
    v1.setY(5.5);
    std::cout << "test->y:    " << v1.getY() << std::endl;
    // push back the object in vector v
    v.push_back(&v1);

    // create object of class test
    test v2;
    // fill the class variables
    v2.setX(11);
    std::cout << "test->x:    " << v2.getX() << std::endl;
    v2.setY(7.5);
    std::cout << "test->y:    " << v2.getY() << std::endl;
    // push back the object in vector v
    v.push_back(&v2);

    // use iterator
    for(auto itr1=v.begin(); itr1!=v.end(); ++itr1)
        std::cout << "Elements:   " << *itr1 << std::endl;

    // use range-based loop
    for(const auto &itr2 : v)
        std::cout << "Elements:   " << itr2 << std::endl;

    std::cout << "test pair class" << std::endl;
    pair_<int, float> p1(13, 15.5);
    std::cout << "pair.first:     " << p1.first_   <<std::endl;
    std::cout << "pair.second:    " << p1.second_  <<std::endl;

    std::cout << "test make_pair function" << std::endl;
    pair_<double, char> p2 = make_pair_(15.5, 'a');
    std::cout << "pair.first:     " << p2.first_   <<std::endl;
    std::cout << "pair.second:    " << p2.second_  <<std::endl;

    std::cout << "end of main function!!!" << std::endl;
    return 0;
}