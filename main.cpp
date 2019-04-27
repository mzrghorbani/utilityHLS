#include <iostream>
#include "box.h"
#include "utilityHLS.h"

int main() {

    std::cout << "box arrayHLS class of objects" << std::endl;
    // create vector of objects
    arrayHLS<box*> v;

    // create object of class box
    box v0;
    // fill the class variables
    v0.setX(7);
    std::cout << "box->x:    " << v0.getX() << std::endl;
    v0.setY(3.5);
    std::cout << "box->y:    " << v0.getY() << std::endl;
    // push back the object in vector v
    v.push_back(&v0);

    // create object of class box
    box v1;
    // fill the class variables
    v1.setX(9);
    std::cout << "box->x:    " << v1.getX() << std::endl;
    v1.setY(5.5);
    std::cout << "box->y:    " << v1.getY() << std::endl;
    // push back the object in vector v
    v.push_back(&v1);

    // create object of class box
    box v2;
    // fill the class variables
    v2.setX(11);
    std::cout << "box->x:    " << v2.getX() << std::endl;
    v2.setY(7.5);
    std::cout << "box->y:    " << v2.getY() << std::endl;
    // push back the object in vector v
    v.push_back(&v2);

    std::cout << '\n';

    std::cout << "box arrayHLS iterator" << std::endl;
    for(auto itr1=v.begin(); itr1!=v.end(); ++itr1)
        std::cout << "Elements:   " << &itr1 << std::endl;

    std::cout << '\n';

    std::cout << "box arrayHLS range-based loop" << std::endl;
    for(const auto &itr2 : v)
        std::cout << "Elements:   " << &itr2 << std::endl;

    std::cout << '\n';

//    std::cout << "box arrayHLS clear()" << std::endl;
//    v.clear();
    for(const auto &itr2 : v)
        std::cout << "Elements:   " << &itr2 << std::endl;

    std::cout << '\n';

    std::cout << "box pairHLS class" << std::endl;
    pairHLS<int, float> p1(13, 15.5);
    std::cout << "pair.first:     " << p1.first   <<std::endl;
    std::cout << "pair.second:    " << p1.second  <<std::endl;

    std::cout << '\n';

    std::cout << "box make_pairHLS function" << std::endl;
    pairHLS<double, char> p2 = make_pairHLS(15.5, 'a');
    std::cout << "pair.first:     " << p2.first   <<std::endl;
    std::cout << "pair.second:    " << p2.second  <<std::endl;

    std::cout << '\n';

    std::cout << "box mapHLS class" << std::endl;
    mapHLS<unsigned int, arrayHLS<box*>> testMap;
    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(3, v));
    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(5, v));
    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(1, v));
    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(6, v));
    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(4, v));
    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(2, v));

    std::cout << "box mapHLS range-based loop" << std::endl;
    for ( auto &t : testMap ) {
        std::cout << t.first << '\t';
        for( auto &i : t.second ) {
            std::cout << &i << '\t';
        }
        std::cout << '\n';
    }
    std::cout << '\n';

    std::cout << "box mapHLS sort()" << std::endl;
    mapHLS<unsigned int, arrayHLS<box*>> testMap_sorted;

    testMap_sorted = testMap;

    testMap_sorted.sort();

    for( auto &c : testMap_sorted ) {
        std::cout << "key: " << c.first << '\t';
        std::cout << "Element: " << c.second[0] << std::endl;
    }
    std::cout << '\n';

    std::cout << "end of main function!!!" << std::endl;
    return 0;
}