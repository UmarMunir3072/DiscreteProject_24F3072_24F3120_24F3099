#ifndef MODULE8_H
#define MODULE8_H

#include "UnidiscEngine.h"
#include <iostream>
#include <string>

using namespace std;

class Module8 {
private:
    RelationPair* prerequisites;
    int prereqCount;
    Course* courses;
    int courseCount;

    int getCourseIndex(string code);

public:
    Module8(RelationPair* pre, int pc, Course* c, int cc)
        : prerequisites(pre), prereqCount(pc), courses(c), courseCount(cc) {
    }

    void provePrereqChain(string course);
};

#endif