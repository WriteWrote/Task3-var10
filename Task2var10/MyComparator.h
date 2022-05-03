#pragma once
#include <iostream>
using namespace std;

template<typename T>
class MyComparator
{
public:
    // Comparator function
    MyComparator() {}

    bool compare(T o1, T o2) {
        return o1 == o2;
    }
};

