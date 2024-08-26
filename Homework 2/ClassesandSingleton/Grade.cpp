#include "Grade.h"
#include <string>

Grade::Grade(int e, int t, double w, string a) : pointsEarned(e), totalPoints(t), weight(w), assignment(a) {
}

int Grade::getPointsEarned() const {
    return pointsEarned;
}

void Grade::setPointsEarned(int pointsEarned) {
    Grade::pointsEarned = pointsEarned;
}

int Grade::getTotalPoints() const {
    return totalPoints;
}

void Grade::setTotalPoints(int totalPoints) {
    Grade::totalPoints = totalPoints;
}

double Grade::getWeight() const {
    return weight;
}

void Grade::setWeight(double weight) {
    Grade::weight = weight;
}

const string &Grade::getAssignment() const {
    return assignment;
}

void Grade::setAssignment(const string &assignment) {
    Grade::assignment = assignment;
}
