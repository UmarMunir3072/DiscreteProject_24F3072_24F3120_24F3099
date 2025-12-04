#ifndef MODULE10_H
#define MODULE10_H

#include "UnidiscEngine.h"
#include <iostream>
#include <string>

using namespace std;

class Module10 {
private:
    int studentCount;
    int courseCount;

public:
    Module10(int sc, int cc)
        : studentCount(sc), courseCount(cc) {
    }

    void runBenchmarks();
};

#endif