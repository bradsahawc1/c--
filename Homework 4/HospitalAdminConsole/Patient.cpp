//
// Created by Cameron Bradshaw on 4/26/2021.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Patient {
private:
    int priority;
    string Fname, Mname, Lname, suffix;
    vector<string> Ailments;
    string doctor;
    int treated;

public:
    Patient(string F, string M, string L, string S, int p, vector<string> A, string D, int t)
            : Fname(F), Mname(M), Lname(L), suffix(S), priority(p), Ailments(A), doctor(D), treated(t){
    }

    bool operator<(const Patient &rhs) const {
        return priority > rhs.priority;
    }

    bool operator>(const Patient &rhs) const {
        return priority < rhs.priority;
    }

    bool operator<=(const Patient &rhs) const {
        return priority >= rhs.priority;
    }

    bool operator>=(const Patient &rhs) const {
        return priority <= rhs.priority;
    }

    int getPriority() const {
        return priority;
    }

    void setPriority(int priority) {
        Patient::priority = priority;
    }

    const string &getFname() const {
        return Fname;
    }

    const string &getMname() const {
        return Mname;
    }

    const string &getLname() const {
        return Lname;
    }

    const string &getSuffix() const {
        return suffix;
    }

    const vector<string> &getAilments() const {
        return Ailments;
    }

    void setAilments(const vector<string> &ailments) {
        Ailments = ailments;
    }

    const string &getDoctor() const {
        return doctor;
    }

    int getTreated() const {
        return treated;
    }

    void setTreated(int treated) {
        Patient::treated = treated;
    }

    void addAilments(string a) {
        Ailments.push_back(a);
    }

    void report() {
        cout << "----------" << endl;
        cout << "Name:" << endl;
        cout << Fname << " " << Mname << " " << Lname << " " << suffix << endl;
        cout << "Ailments:" << endl;
        for (int i = 0; i < Ailments.size(); ++i) {
            cout << Ailments[i] << endl;
        }
        cout << "Doctor:" << endl;
        cout << doctor << endl;
        cout << "Treated?" << endl;
        if (!treated) {
            cout << "Patient has not been treated yet." << endl;
            cout << "Priority:" << endl;
            cout << priority << endl;
        }
        else {
            cout << "Patient has been treated." << endl;
        }
        cout << "----------" << endl;
    }
};