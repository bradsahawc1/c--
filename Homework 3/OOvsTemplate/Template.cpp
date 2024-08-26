//
// Created by Cameron Bradshaw on 4/3/2021.
//

#include <string>
using namespace std;

class TIWrapper {
private:
    int val;

public:
    TIWrapper(int num) : val(num) {};
    bool isLessThan(TIWrapper* rhs) const {
        TIWrapper * point = dynamic_cast<TIWrapper *>(rhs);
        if (point == nullptr) {
            return false;
        }
        return *this < *point;
    };

    int getVal() const {
        return val;
    }

    void setVal(int val) {
        TIWrapper::val = val;
    }

    bool operator<(const TIWrapper &rhs) const {
        return val < rhs.getVal();
    }

    bool operator>(const TIWrapper &rhs) const {
        return val > rhs.getVal();
    }

    bool operator<=(const TIWrapper &rhs) const {
        return val <= rhs.getVal();
    }

    bool operator>=(const TIWrapper &rhs) const {
        return val >= rhs.getVal();
    }
};

class TSWrapper {
private:
    string val;
public:
    TSWrapper(string str) : val(str) {};
    bool operator()(TSWrapper* rhs) const {
        TSWrapper * point = dynamic_cast<TSWrapper *>(rhs);
        if (point == nullptr) {
            return false;
        }
        return *this < *point;
    }

    const string &getVal() const {
        return val;
    }

    void setVal(const string &val) {
        TSWrapper::val = val;
    }

    bool operator<(const TSWrapper &rhs) const {
        return val.compare(rhs.getVal()) < 0;
    }

    bool operator>(const TSWrapper &rhs) const {
        return val.compare(rhs.getVal()) > 0;
    }

    bool operator<=(const TSWrapper &rhs) const {
        return val.compare(rhs.getVal()) <= 0;
    }

    bool operator>=(const TSWrapper &rhs) const {
        return val.compare(rhs.getVal()) >= 0;
    }
};

template<typename Object>
class isLessThan {
public:
    bool operator()(const Object &lhs, const Object &rhs) const {
        return lhs < rhs;
    }
};