#ifndef MODULE1_H
#define MODULE1_H

#include "UnidiscEngine.h"
#include <iostream>
#include <string>

using namespace std;

class Module1 {
private:
    Course* courses;
    int courseCount;
    RelationPair* prerequisites;
    int prereqCount;

    int getCourseIndex(string code);

public:
    Module1(Course* c, int cc, RelationPair* p, int pc)
        : courses(c), courseCount(cc), prerequisites(p), prereqCount(pc) {
    }

    void generateCourseSchedule();
};

#endif