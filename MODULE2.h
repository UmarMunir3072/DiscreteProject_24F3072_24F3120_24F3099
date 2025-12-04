#ifndef MODULE2_H
#define MODULE2_H

#include "UnidiscEngine.h"
#include <iostream>
#include <string>

using namespace std;

class Module2 {
private:
    Student* students;
    int studentCount;

    int factorial(int n);
    void printCombinationsRecursive(string* data, int n, int r, int index, string* current, int i);

public:
    Module2(Student* s, int sc) : students(s), studentCount(sc) {}

    void generateStudentGroups(int k);
};

#endif