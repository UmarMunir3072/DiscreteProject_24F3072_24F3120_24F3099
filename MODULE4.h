#ifndef MODULE4_H
#define MODULE4_H

#include "UnidiscEngine.h"
#include <iostream>
#include <string>

using namespace std;

class Module4 {
private:
    Student* students;
    int studentCount;
    RelationPair* prerequisites;
    int prereqCount;
    RelationPair* enrollments;
    int enrollCount;

public:
    Module4(Student* s, int sc, RelationPair* p, int pc, RelationPair* e, int ec)
        : students(s), studentCount(sc), prerequisites(p), prereqCount(pc), enrollments(e), enrollCount(ec) {
    }

    void checkIndirectConflicts();
};

#endif