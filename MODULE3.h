#ifndef MODULE3_H
#define MODULE3_H

#include "UnidiscEngine.h"
#include <iostream>
#include <string>

using namespace std;

class Module3 {
private:
    RelationPair* prerequisites;
    int prereqCount;

    bool verifyPrereqChainRecursive(string targetCourse, int depth);

public:
    Module3(RelationPair* p, int pc) : prerequisites(p), prereqCount(pc) {}

    void verifyPrereqChainInduction(string base, string target);
};

#endif