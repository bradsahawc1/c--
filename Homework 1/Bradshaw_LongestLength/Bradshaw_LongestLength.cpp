#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> longestLength(vector<string> original) {
    int max = 0;
    vector<string> longest;
    vector<int> index;

    for (int j = 0; j < original.size(); j++) {
        if (original.at(j).size() > max) {
            max = original.at(j).size();
        }
    }

    for (int j = 0; j < original.size(); j++) {
        if (original.at(j).size() == max) {
            longest.push_back(original.at(j));
        }
    }

    return longest;
}

int main() {
    int cont = 1;
    string current;
    vector<string> originalVector;
    vector<string> newVector;

    cout << "Enter some Strings:\n";

    do {
        cin >> current;
        originalVector.push_back(current);
        cout << "Continue? 1=yes 0=no:\n";
        cin >> cont;
    } while (cont == 1);

    newVector = longestLength(originalVector);

    for (int j = 0; j < newVector.size(); j++) {
        cout << newVector[j] << ",";
    }

    return 0;
}

/*
Enter some Strings:
mio
Continue? 1=yes 0=no:
1
Ina
Continue? 1=yes 0=no:
1
Ganyu
Continue? 1=yes 0=no:
1
Keqing
Continue? 1=yes 0=no:
1
Aether
Continue? 1=yes 0=no:
1
Diluc
Continue? 1=yes 0=no:
1
Beidou
Continue? 1=yes 0=no:
0
Keqing,Aether,Beidou,
 */
