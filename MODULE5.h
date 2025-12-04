#ifndef MODULE5_H
#define MODULE5_H

#include "UnidiscEngine.h"
#include <iostream>
#include <string>

using namespace std;

class Module5 {
private:
    RelationPair* enrollments;
    int enrollCount;

public:
    Module5(RelationPair* enr, int ec)
        : enrollments(enr), enrollCount(ec) {
    }

    void analyzeSetOperations(string c1, string c2);
};

#endif