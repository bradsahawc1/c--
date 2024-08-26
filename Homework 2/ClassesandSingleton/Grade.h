//
// Created by Cameron Bradshaw on 3/15/2021.
//

#ifndef CLASSESANDSINGLETON_GRADE_H
#define CLASSESANDSINGLETON_GRADE_H
#include <string>
#include "Logger.h"
using namespace std;

class Grade {
public:
    int pointsEarned;
    int totalPoints;
    double weight;
    string assignment;
    Grade(int e, int t, double w, string a);

    int getPointsEarned() const;

    void setPointsEarned(int pointsEarned);

    int getTotalPoints() const;

    void setTotalPoints(int totalPoints);

    double getWeight() const;

    void setWeight(double weight);

    const string &getAssignment() const;

    void setAssignment(const string &assignment);
};

#endif //CLASSESANDSINGLETON_GRADE_H
