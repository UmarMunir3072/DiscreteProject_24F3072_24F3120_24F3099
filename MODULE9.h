#ifndef MODULE9_H
#define MODULE9_H

#include "UnidiscEngine.h"
#include <iostream>
#include <string>

using namespace std;

class Module9 {
private:
    Student* students;
    int studentCount;
    Course* courses;
    int courseCount;
    Faculty* faculties;
    int facultyCount;

    RelationPair* prerequisites;
    int prereqCount;
    RelationPair* enrollments;
    int enrollCount;
    RelationPair* facultyAssignments;
    int facAssignCount;

    int getStudentIndex(string id);
    int getCourseIndex(string code);

public:
    Module9(Student* s, int sc, Course* c, int cc, Faculty* f, int fc,
        RelationPair* pre, int pc, RelationPair* enr, int ec, RelationPair* fa, int fac)
        : students(s), studentCount(sc), courses(c), courseCount(cc), faculties(f), facultyCount(fc),
        prerequisites(pre), prereqCount(pc), enrollments(enr), enrollCount(ec), facultyAssignments(fa), facAssignCount(fac) {
    }

    void runConsistencyCheck();
};

#endif