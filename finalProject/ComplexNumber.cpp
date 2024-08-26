//
// Created by Cameron Bradshaw on 5/6/2021.
//

#include <ostream>
using namespace std;

template<typename type>
class ComplexNumber {
public:
    ComplexNumber(type r, type i)  {real = r;   imag = i;}

    ComplexNumber<type> operator+(ComplexNumber<type> const &obj) {
        ComplexNumber<type> res(0, 0);
        res.real = real + obj.real;
        res.imag = imag + obj.imag;
        return res;
    }

    ComplexNumber<type> operator-(ComplexNumber<type> const &obj) {
        ComplexNumber<type> res(0, 0);
        res.real = real - obj.real;
        res.imag = imag - obj.imag;
        return res;
    }

    bool operator<(ComplexNumber<type> const &obj) {
        if (real < obj.real) {
            return true;
        }
        else if (imag < obj.imag) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator>(ComplexNumber<type> const &obj) {
        if (obj.real < real) {
            return true;
        }
        else if (obj.imag < imag) {
            return true;
        }
        else {
            return false;
        }
    }

    bool operator==(ComplexNumber<type> const &obj) {
        if (real == obj.real) {
            if (imag == obj.imag) {
                return true;
            }
            else {
                return false;
            }
        }
        else {
            return false;
        }
    }

    bool operator!=(ComplexNumber<type> const &obj) {
        if (real == obj.real) {
            if (imag == obj.imag) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return true;
        }
    }

    template <typename U>
    friend ostream& operator<<( ostream&, const ComplexNumber<U>& );

private:
    type real, imag;
};

template <typename T>
ostream& operator<<( ostream& out, const ComplexNumber<T>& cn) {
    out << cn.real << " + i" << cn.imag;
    return out;
}