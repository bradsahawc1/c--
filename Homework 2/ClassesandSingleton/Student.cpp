#include "Student.h"

Student::Student(int i, string n) : ID(i), name(n) {
}
Student::~Student() {
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] != nullptr) {
            delete grades[i];
        }
    }
}
Student::Student(const Student &rhs) : ID(rhs.ID), name(rhs.name){
    grades.clear();
    for (int i = 0; i < rhs.grades.size(); i++) {
        Grade* g = rhs.grades[i];
        grades.push_back(new Grade(g->pointsEarned, g->totalPoints, g->weight, g->assignment));
    }
}
const Student & Student::operator=(const Student &rhs) {
    if (this != &rhs) {
        this->grades.clear();
        ID = rhs.ID;
        name = rhs.name;
        for (int i = 0; i < rhs.grades.size(); i++) {
            Grade* g = rhs.grades[i];
            this->grades.push_back(new Grade(g->pointsEarned, g->totalPoints, g->weight, g->assignment));
        }
    }
    return *this;
}
double Student::calculateFinal() {
    double finalgrade;
    double sum;
    for (int i = 0; i < grades.size(); ++i) {
        finalgrade += (calculateGrade(i)) * grades[i]->weight;
        sum += grades[i]->weight;
    }
    finalgrade = (finalgrade / sum) * 100;
    return finalgrade;
}
double Student::calculateGrade(int i) {
    double g;
    g = double(grades[i]->pointsEarned) / double(grades[i]->totalPoints);
    return g;
}
string Student::calculateLetterGrade() {
    double final = calculateFinal();
    if (final >= 93) {
        return "A+";
    }
    else if (93 > final && final >= 90) {
        return "A";
    }
    else if (90 > final && final >= 87) {
        return "B+";
    }
    else if (87 > final && final >= 83) {
        return "B";
    }
    else if (83 > final && final >= 80) {
        return "B-";
    }
    else if (80 > final && final >= 77) {
        return "C+";
    }
    else if (77 > final && final >= 73) {
        return "C";
    }
    else if (73 > final && final >= 70) {
        return "C-";
    }
    else if (70 > final && final >= 67) {
        return "D+";
    }
    else if (67 > final && final >= 63) {
        return "D";
    }
    else if (60 > final) {
        return "F";
    }
    return ".";
}
void Student::printReport() {
    log.log(to_string(ID));
    log.log(name);
    for (int i = 0; i < grades.size(); ++i) {
        log.log(grades[i]->assignment + ":");
        log.log(to_string(calculateGrade(i) * 100));
    }
    log.log("Final Grade:");
    log.log(to_string(calculateFinal()));
    log.log(calculateLetterGrade());
}

int Student::getId() const {
    return ID;
}

void Student::setId(int id) {
    ID = id;
}

const string Student::getName() const {
    return name;
}

void Student::setName(const string newname) {
    name = newname;
}

const vector<Grade *> &Student::getGrades() const {
    return grades;
}

void Student::setGrades(const vector<Grade *> &grades) {
    Student::grades.clear();
    for (int i = 0; i < grades.size(); ++i) {
        Grade* g = grades[i];
        Student::grades.push_back(new Grade(g->pointsEarned, g->totalPoints, g->weight, g->assignment));
    }
}