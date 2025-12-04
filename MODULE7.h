#ifndef MODULE7_H
#define MODULE7_H

#include "UnidiscEngine.h"
#include <iostream>
#include <string>

using namespace std;

class Module7 {
private:
    Student* students;
    int studentCount;
    Course* courses;
    int courseCount;
    Faculty* faculties;
    int facultyCount;
    RelationPair* enrollments;
    int enrollCount;
    RelationPair* facultyAssignments;
    int facAssignCount;
    RelationPair* roomAssignments;
    int roomAssignCount;

public:
    Module7(Student* s, int sc, Course* c, int cc, Faculty* f, int fc,
        RelationPair* e, int ec, RelationPair* fa, int fac, RelationPair* ra, int rac)
        : students(s), studentCount(sc), courses(c), courseCount(cc), faculties(f), facultyCount(fc),
        enrollments(e), enrollCount(ec), facultyAssignments(fa), facAssignCount(fac),
        roomAssignments(ra), roomAssignCount(rac) {
    }

    void analyzeFunctions();
};

#endif