//
// Created by Cameron Bradshaw on 4/1/2021.
//

#include <string>
using namespace std;

class IComparable {
public:
    virtual bool isLessThan(IComparable* rhs) const =0;
};

class IntWrapper : public IComparable {
private:
    int val;

public:
    IntWrapper(int num) : val(num) {};
    bool isLessThan(IComparable* rhs) const override {
        IntWrapper * point = dynamic_cast<IntWrapper *>(rhs);
        if (point == nullptr) {
            return false;
        }
        return *this < *point;
    };

    int getVal() const {
        return val;
    }

    void setVal(int val) {
        IntWrapper::val = val;
    }

    bool operator<(const IntWrapper &rhs) const {
        return val < rhs.getVal();
    }

    bool operator>(const IntWrapper &rhs) const {
        return val > rhs.getVal();
    }

    bool operator<=(const IntWrapper &rhs) const {
        return val <= rhs.getVal();
    }

    bool operator>=(const IntWrapper &rhs) const {
        return val >= rhs.getVal();
    }
};

class StringWrapper : public IComparable {
private:
    string val;
public:
    StringWrapper(string str) : val(str) {};
    bool isLessThan(IComparable* rhs) const override {
        StringWrapper * point = dynamic_cast<StringWrapper *>(rhs);
        if (point == nullptr) {
            return false;
        }
        return *this < *point;
    }

    const string &getVal() const {
        return val;
    }

    void setVal(const string &val) {
        StringWrapper::val = val;
    }

    bool operator<(const StringWrapper &rhs) const {
        return val.compare(rhs.getVal()) < 0;
    }

    bool operator>(const StringWrapper &rhs) const {
        return val.compare(rhs.getVal()) > 0;
    }

    bool operator<=(const StringWrapper &rhs) const {
        return val.compare(rhs.getVal()) <= 0;
    }

    bool operator>=(const StringWrapper &rhs) const {
        return val.compare(rhs.getVal()) >= 0;
    }
};
