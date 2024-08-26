#include "main.h"
#include "Student.h"

int main() {
    vector<Grade*> g;
    Student stu1(1, "Trey");
    auto *g1 = new Grade(9, 10, .2, "Quiz 1");
    auto *g2 = new Grade(8, 10, .2, "Quiz 2");
    auto *g3 = new Grade(9, 10, .2, "Quiz 3");
    auto *g4 = new Grade(10, 10, .4, "Quiz 4");
    g.push_back(g1);
    g.push_back(g2);
    g.push_back(g3);
    g.push_back(g4);
    stu1.setGrades(g);
    stu1.printReport();
    Student stu2(stu1);
    vector<Grade*> gg = stu1.getGrades();
    gg[1] = new Grade(5, 10, .2, "Quiz 5");
    stu1.setGrades(gg);
    stu1.printReport();
    stu2.printReport();
    Student stu3 = stu1;
    stu3.printReport();
    destroyStudent(stu1);
    stu1.printReport();
    return 0;
}
void destroyStudent(Student &stu) {
    Student stu5(stu);
    stu5.printReport();
}