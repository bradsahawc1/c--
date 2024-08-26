#include "IComparable.cpp"
#include "Template.cpp"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;
using namespace std::chrono;

/* Sort and sort check for Inheritance */

void sort(vector<IComparable*>& vec) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < vec.size()-1; ++i) {
            if (vec[i + 1]->isLessThan(vec[i])) {
                sorted = false;
                IComparable* temp = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = temp;
            }
        }
    }
}

bool IsSorted(vector<IComparable*>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        if (vec[i]->isLessThan(vec[i - 1])) {
            return false;
        }
    }
    return true;
}

/* Sort and sort check for template */

template<typename vectorType, typename Comparator>
void Tsort(vector<vectorType>& vec, Comparator lessThan) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < vec.size() - 1; ++i) {
            if (lessThan(vec[i + 1], vec[i])) {
                sorted = false;
                vectorType temp = vec[i];
                vec[i] = vec[i + 1];
                vec[i + 1] = temp;
            }
        }
    }
}

template<typename vectorType, typename Comparator>
bool TIsSorted(vector<vectorType>& vec, Comparator lessThan) {
    for (int i = 1; i < vec.size(); ++i) {
        if (lessThan(vec[i], vec[i - 1])) {
            return false;
        }
    }
    return true;
}

/* Random generation for Vectors */

vector<IntWrapper*> randomInt() {
    vector<IntWrapper*> vec;
    srand(time(nullptr));
    for (int i = 0; i < 1000; ++i) {
        IntWrapper* temp = new IntWrapper(0);
        temp->setVal(rand() % 1000 + 1);
        vec.push_back(temp);
    }
    return vec;
}

vector<TIWrapper*> randomInt2() {
    vector<TIWrapper*> vec;
    srand(time(nullptr));
    for (int i = 0; i < 1000; ++i) {
        TIWrapper* temp = new TIWrapper(0);
        temp->setVal(rand() % 1000 + 1);
        vec.push_back(temp);
    }
    return vec;
}

vector<StringWrapper*> randomString() {
    vector<StringWrapper*> vec;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    srand(time(nullptr));
    for (int i = 0; i < 1000; ++i) {
        StringWrapper* temp = new StringWrapper("");
        string s;
        s.reserve(4);
        for (int i = 0; i < 4; ++i) {
            s += alphanum[rand() % (sizeof(alphanum) - 1)];
        }
        temp->setVal(s);
        vec.push_back(temp);
    }
    return vec;
}

vector<TSWrapper*> randomString2() {
    vector<TSWrapper*> vec;
    static const char alphanum[] =
            "0123456789"
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz";
    srand(time(nullptr));
    for (int i = 0; i < 1000; ++i) {
        TSWrapper* temp = new TSWrapper("");
        string s;
        s.reserve(4);
        for (int i = 0; i < 4; ++i) {
            s += alphanum[rand() % (sizeof(alphanum) - 1)];
        }
        temp->setVal(s);
        vec.push_back(temp);
    }
    return vec;
}

int main() {

    cout << "***Using Inheritance***" << "\n" << endl;

    vector<IntWrapper*> v1 = randomInt();
    vector<StringWrapper*> v2 = randomString();

    if (IsSorted((vector<struct IComparable *> &)v1)) {
        cout << "Vector 1 is sorted." << endl;
    } else {
        cout << "Vector 1 is not sorted." << endl;
    }

    cout << "Sorting..." << endl;
    auto start = high_resolution_clock::now();
    sort((vector<IComparable*> &)v1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Time taken by function: "
         << duration.count() << " microseconds" << endl;

    if (IsSorted((vector<struct IComparable *> &)v1)) {
        cout << "Vector 1 is sorted." << endl;
    } else {
        cout << "Vector 1 is not sorted." << endl;
    }

    cout << "\n";

    if (IsSorted((vector<struct IComparable *> &)v2)) {
        cout << "Vector 2 is sorted." << endl;
    } else {
        cout << "Vector 2 is not sorted." << endl;
    }

    cout << "Sorting..." << endl;
    auto start2 = high_resolution_clock::now();
    sort((vector<IComparable*> &)v2);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout << "Time taken by function: "
         << duration2.count() << " microseconds" << endl;

    if (IsSorted((vector<struct IComparable *> &)v2)) {
        cout << "Vector 2 is sorted." << endl;
    } else {
        cout << "Vector 2 is not sorted." << endl;
    }

    cout << "\n" << "***Now using Template***" << "\n" << endl;

    vector<TIWrapper*> v3 = randomInt2();
    vector<TSWrapper*> v4 = randomString2();

    if (TIsSorted(v3, isLessThan<TIWrapper*>())) {
        cout << "Vector 3 is sorted." << endl;
    } else {
        cout << "Vector 3 is not sorted." << endl;
    }

    cout << "Sorting..." << endl;
    auto start3 = high_resolution_clock::now();
    Tsort(v3, isLessThan<TIWrapper*>());
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout << "Time taken by function: "
         << duration3.count() << " microseconds" << endl;

    if (TIsSorted(v3, isLessThan<TIWrapper*>())) {
        cout << "Vector 3 is sorted." << endl;
    } else {
        cout << "Vector 3 is not sorted." << endl;
    }

    cout << "\n";

    if (TIsSorted(v4, isLessThan<TSWrapper*>())) {
        cout << "Vector 4 is sorted." << endl;
    } else {
        cout << "Vector 4 is not sorted." << endl;
    }

    cout << "Sorting..." << endl;
    auto start4 = high_resolution_clock::now();
    Tsort(v4, isLessThan<TSWrapper*>());
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout << "Time taken by function: "
         << duration4.count() << " microseconds" << endl;

    if (TIsSorted(v4, isLessThan<TSWrapper*>())) {
        cout << "Vector 4 is sorted." << endl;
    } else {
        cout << "Vector 4 is not sorted." << endl;
    }

    return 0;
}
