//
// Created by Cameron Bradshaw on 5/6/2021.
//
#include <ostream>
using namespace std;

template<typename Object>
class Comparator {
public:
    virtual bool isGreaterThan(const Object & lhs, const Object & rhs) const {
        return lhs > rhs;
    }
};