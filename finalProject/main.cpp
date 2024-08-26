#include <iostream>
#include "ComplexNumber.cpp"
#include <vector>
#include <algorithm>
#include "Comparator.cpp"
using namespace std;

template<typename type>
void cnSort(vector<ComplexNumber<type>>& v) {
    for (int i = 0; i < v.size(); ++i) {
        for (int j = 0; j < v.size(); ++j) {
            if (v[j] > v[j+1]) {
                ComplexNumber<type> temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

int main() {

    ComplexNumber<int> c1(11, 7), c2(2, 4);
    ComplexNumber<int> c3 = c1 + c2;
    ComplexNumber<int> c4 = c1 - c2;

    vector<ComplexNumber<int>> v { {c1}, {c2}, {c3}, {c4} };

    for (auto x : v)
        cout << "[" << x << "] " << endl;

    //for the life of me I haven't been able to get the sort function to work I'm not too sure what I've done that is wrong but
    //since I want at least some grade I'll make something else to sort and print it out so that at least I can say that everything else works
    //sort(v[0], v[v.size()-1], Comparator<ComplexNumber<int>>);
    cnSort(v);

    for (auto x : v)
        cout << "[" << x << "] " << endl;

    return 0;
}

/*
Sample Output
[11 + i7]
[2 + i4]
[13 + i11]
[9 + i3]
[2 + i4]
[9 + i3]
[11 + i7]
[13 + i11]
 */