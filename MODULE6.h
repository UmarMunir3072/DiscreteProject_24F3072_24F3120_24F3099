#ifndef MODULE6_H
#define MODULE6_H

#include "UnidiscEngine.h"
#include <iostream>
#include <string>

using namespace std;

class Module6 {
private:
    Course* courses;
    int courseCount;
    RelationPair* prerequisites;
    int prereqCount;

    bool hasRelationPair(string a, string b);

public:
    Module6(Course* c, int cc, RelationPair* pre, int pc)
        : courses(c), courseCount(cc), prerequisites(pre), prereqCount(pc) {
    }

    void analyzeRelations();
};

#endif