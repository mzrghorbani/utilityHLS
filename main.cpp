#include "box.h"
#include "utilityHLS.h"
#include <iostream>

int main() {

    std::cout << "box arrayHLS class of objects" << std::endl;
//    // create vector of objects
//    arrayHLS<box*> v;
//
//    // create object of class box
//    box v0;
//    // fill the class variables
//    v0.setX(7);
//    std::cout << "box->x:    " << v0.getX() << std::endl;
//    v0.setY(3.5);
//    std::cout << "box->y:    " << v0.getY() << std::endl;
//    // push back the object in vector v
//    v.push_back(&v0);
//
//    // create object of class box
//    box v1;
//    // fill the class variables
//    v1.setX(9);
//    std::cout << "box->x:    " << v1.getX() << std::endl;
//    v1.setY(5.5);
//    std::cout << "box->y:    " << v1.getY() << std::endl;
//    // push back the object in vector v
//    v.push_back(&v1);
//
//    // create object of class box
//    box v2;
//    // fill the class variables
//    v2.setX(11);
//    std::cout << "box->x:    " << v2.getX() << std::endl;
//    v2.setY(7.5);
//    std::cout << "box->y:    " << v2.getY() << std::endl;
//    // push back the object in vector v
//    v.push_back(&v2);
//
//    std::cout << '\n';
//
//    std::cout << "box arrayHLS iterator" << std::endl;
//    for(auto itr1=v.begin(); itr1!=v.end(); ++itr1)
//        std::cout << "Elements:   " << &itr1 << std::endl;
//
//    std::cout << '\n';
//
//    std::cout << "box arrayHLS range-based loop" << std::endl;
//    for(const auto &itr2 : v)
//        std::cout << "Elements:   " << &itr2 << std::endl;
//
//    std::cout << '\n';
//
////    std::cout << "box arrayHLS clear()" << std::endl;
////    v.clear();
//    for(const auto &itr2 : v)
//        std::cout << "Elements:   " << &itr2 << std::endl;
//
//    std::cout << '\n';
//
//    std::cout << "box pairHLS class" << std::endl;
//    pairHLS<int, float> p1(13, 15.5);
//    std::cout << "pair.first:     " << p1.first   <<std::endl;
//    std::cout << "pair.second:    " << p1.second  <<std::endl;
//
//    std::cout << '\n';
//
//    std::cout << "box make_pairHLS function" << std::endl;
//    pairHLS<double, char> p2 = make_pairHLS(15.5, 'a');
//    std::cout << "pair.first:     " << p2.first   <<std::endl;
//    std::cout << "pair.second:    " << p2.second  <<std::endl;
//
//    std::cout << '\n';
//
//    std::cout << "box mapHLS class" << std::endl;
//    mapHLS<unsigned int, arrayHLS<box*>> testMap;
//    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(3, v));
//    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(5, v));
//    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(1, v));
//    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(6, v));
//    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(4, v));
//    testMap.push_back(pairHLS<unsigned int, arrayHLS<box*>>(2, v));
//
//    std::cout << "box mapHLS range-based loop" << std::endl;
//    for ( auto &t : testMap ) {
//        std::cout << t.first << '\t';
//        for( auto &i : t.second ) {
//            std::cout << &i << '\t';
//        }
//        std::cout << '\n';
//    }
//    std::cout << '\n';
//
//    std::cout << "box mapHLS sort()" << std::endl;
//    mapHLS<unsigned int, arrayHLS<box*>> testMap_sorted;
//
//    testMap_sorted = testMap;
//
//    testMap_sorted.sort();
//
//    for( auto &c : testMap_sorted ) {
//        std::cout << "key: " << c.first << '\t';
//        std::cout << "Element: " << c.second[0] << std::endl;
//    }
//    std::cout << '\n';

//    std::cout << "Test findHLS function in arrayHLS" << std::endl;
//
//    arrayHLS<int> vec1;
//
//    vec1.push_back(7);
//    vec1.push_back(14);
//    vec1.push_back(21);
//    vec1.push_back(28);
//    vec1.push_back(35);
//    vec1.push_back(42);
//    vec1.push_back(48);
//
//    int ser = 7;
//
//    std::cout << '\n';
//
//    arrayHLS<int>::iterator itr4;
//
//    itr4 = findHLS(vec1.begin(), vec1.end(), ser);
//
//    if (itr4 != vec1.end()) {
//        std::cout << "Element " << ser <<" found at position : " ;
//        std:: cout << itr4 - vec1.begin() + 1 << "\n" ;
//    } else
//        std::cout << "Element not found.\n";
//
//    std::cout << '\n';
//
//    std::cout << "Test moveHLS function in arrayHLS" << std::endl;
//
//    arrayHLS<int> vec2;
//
//    vec2.push_back(5);
//    vec2.push_back(5);
//    vec2.push_back(5);
//    vec2.push_back(5);
//    vec2.push_back(5);
//    vec2.push_back(5);
//    vec2.push_back(5);
//
//    moveHLS(vec1.begin()+1, vec1.begin() + 3, vec2.begin() + 3);
//
//    for(unsigned int i = 0; i < vec2.size(); i++)
//        std :: cout << " " << vec2[i];
//    std :: cout << "\n";
//
//    std::cout << '\n';
//
//    std::cout << "Test removeHLS function in arrayHLS" << std::endl;

//    arrayHLS<int> vec3;
//
//    vec3.push_back(10);
//    vec3.push_back(7);
//    vec3.push_back(30);
//    vec3.push_back(7);
//    vec3.push_back(50);
//    vec3.push_back(7);
//    vec3.push_back(70);
//
//    std::cout << '\n';
//
//    removeHLS(vec3.begin(), vec3.end(), 7);
//
//    arrayHLS<int>::iterator pend = nullptr;
//
//    std :: cout << "After remove : ";
//    for ( auto p=vec3.begin(); p != vec3.end(); ++p)
//        std :: cout << ' ' << *p;
//    std :: cout << "\n";

//    const box* b(testMap[0][0]);
//
//    testMap[0].erase(removeHLS(testMap[0].begin(), testMap[0].end(), b), testMap[0].end());

    std::cout << std::endl;

    arrayHLS<int> vec3;

    vec3.push_back(10);
    vec3.push_back(10);
    vec3.push_back(30);
    vec3.push_back(30);
    vec3.push_back(10);
    vec3.push_back(10);
    vec3.push_back(10);
    vec3.push_back(20);

    // Print original vector
    std::cout << "Original vector : ";
    for(int i=0; i < vec3.size(); i++)
        std::cout << " " << vec3[i];
    std::cout << "\n";

    // std ::remove function call
    removeHLS(vec3.begin(), vec3.end() , 20);
    // Print the vector
    std::cout << "After remove : ";
    for ( auto p=vec3.begin(); p !=vec3.end(); ++p )
        std::cout << ' ' << *p;
    std::cout << '\n';

    std::cout << "end of main function!!!" << std::endl;
    return 0;
}