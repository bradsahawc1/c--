//
// Created by Cameron Bradshaw on 3/15/2021.
//

#ifndef CLASSESANDSINGLETON_STUDENT_H
#define CLASSESANDSINGLETON_STUDENT_H
#include <iostream>
#include <vector>
#include <string>
#include "Grade.h"
#include "Logger.h"
using namespace std;

class Student {
private:
    int ID;
    string name;
    vector<Grade*> grades;
    Logger log = Logger::getInstance();
public:
    Student(int i, string n);
    ~Student();
    Student(const Student &rhs);
    const Student & operator=(const Student &rhs);
    double calculateFinal();
    double calculateGrade(int i);
    string calculateLetterGrade();
    void printReport();
    int getId() const;
    void setId(int id);
    const string getName() const;
    void setName(const string newname);
    const vector<Grade *> &getGrades() const;
    void setGrades(const vector<Grade *> &grades);
};

#endif //CLASSESANDSINGLETON_STUDENT_H
