#include "box.h"
#include "utilityHLS.h"
#include <iostream>

int main() {

    std::cout << "box arrayHLS class of objects" << std::endl;
    // create vector of objects
    arrayHLS<box*> v;

    // create object of class box
    box v0;
    v0.setX(1);
    v0.setY(3.5);
    v.push_back(&v0);

    // create object of class box
    box v1;
    v1.setX(2);
    v1.setY(5.5);
    v.push_back(&v1);

    // create object of class box
    box v2;
    v2.setX(3);
    v2.setY(7.5);
    v.push_back(&v2);

    // create object of class box
    box v3;
    v3.setX(4);
    v3.setY(7.5);
    v.push_back(&v3);

    // create object of class box
    box v4;
    v4.setX(5);
    v4.setY(7.5);
    v.push_back(&v4);

    std::cout << '\n';

    arrayHLS<box*>::iterator itr1;

    std::cout << "box arrayHLS iterator" << std::endl;
    for(itr1=v.begin(); itr1!=v.end(); ++itr1)
        std::cout << "Elements:   " << itr1 << std::endl;

    std::cout << '\n';

    std::cout << "box arrayHLS range-based loop" << std::endl;
    for(const auto &itr2 : v)
        std::cout << "Elements:   " << itr2->getX() << std::endl;

    std::cout << '\n';

//    std::cout << "box arrayHLS clear()" << std::endl;
//    v.clear();
//    for(const auto &itr2 : v)
//        std::cout << "Elements:   " << &itr2 << std::endl;
//
//    std::cout << '\n';

    std::cout << "box pairHLS class" << std::endl;
    pairHLS<int, float> p1(13, 15.5);
    std::cout << "pair.first:     " << p1.first   <<std::endl;
    std::cout << "pair.second:    " << p1.second  <<std::endl;

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
    mapHLS<unsigned int, arrayHLS<box*>> sorted;

    sorted = testMap;

    sorted.sort();

    for( auto &c : sorted ) {
        std::cout << "key: " << c.first << '\t';
        std::cout << "Element: " << c.second[0] << std::endl;
    }

    std::cout << "Test hasKey function" << std::endl;
    std::cout << "hasKey: " << testMap.hasKey(5) << std::endl;

    std::cout << '\n';

    std::cout << "Test subscripting for mapHLS" << std::endl;
    std::cout << "testMap[5][2]: " << testMap[5][2]->getX() << std::endl;
    std::cout << "testMap[2][4]: " << testMap[2][4]->getX() << std::endl;

//    std::cout << '\n';
//    std::cout << "Test erase(value) function for mapHLS" << std::endl;
//    testMap[5].erase(testMap[5][2]);
//
//    std::cout << "box mapHLS range-based loop" << std::endl;
//    for ( auto &t : testMap ) {
//        std::cout << t.first << '\t';
//        for( auto &i : t.second ) {
//            std::cout << i->getX() << '\t';
//        }
//        std::cout << '\n';
//    }
//    std::cout << '\n';

//    std::cout << "Test erase(pos1, pos2) function for mapHLS" << std::endl;
//    testMap[5].erase(testMap[5].begin(), testMap[5].end());
//    std::cout << "box mapHLS range-based loop" << std::endl;
//    for ( auto &t : testMap ) {
//        std::cout << t.first << '\t';
//        for( int i=0; i<t.second.size(); ++i) {
//            std::cout << t.second[i]->getX() << '\t';
//        }
//        std::cout << '\n';
//    }
//    std::cout << '\n';

    std::cout << "Test removeHLS function" << std::endl;
    const box* b(testMap[5][4]);
    testMap[5].erase(removeHLS(testMap[5].begin(), testMap[5].end(), b), testMap[5].end());

    std::cout << "box mapHLS range-based loop" << std::endl;
    for ( auto &t : testMap ) {
        std::cout << t.first << '\t';
        for( auto &i : t.second ) {
            std::cout << i->getX() << '\t';
        }
        std::cout << '\n';
    }
    std::cout << '\n';
    
    std::cout << '\n';

    std::cout << "End of main function!!!" << std::endl;
    return 0;
}