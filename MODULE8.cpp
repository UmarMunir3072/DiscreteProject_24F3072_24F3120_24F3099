#include "Module8.h"

int Module8::getCourseIndex(string code)
{
    for (int i = 0; i < courseCount; i++) if (courses[i].code == code) return i;
    return -1;
}

void Module8::provePrereqChain(string course)
{
    cout << "--- Module 8: Automated Proof Generation ---" << endl;
    cout << "Theorem: Prove prerequisites for " << course << " exist." << endl;

    int idx = getCourseIndex(course);
    if (idx == -1)
    {
        cout << "Error: Course not found." << endl;
        return;
    }

    cout << "Proof:" << endl;
    bool foundAny = false;
    int step = 1;

    for (int i = 0; i < prereqCount; i++)
    {
        if (prerequisites[i].elementB == course)
        {
            cout << "Step " << step++ << ": We know " << prerequisites[i].elementA
                << " is a prerequisite of " << course << endl;

            for (int j = 0; j < prereqCount; j++)
            {
                if (prerequisites[j].elementB == prerequisites[i].elementA)
                {
                    cout << "Step " << step++ << ": We know " << prerequisites[j].elementA
                        << " is a prerequisite of " << prerequisites[i].elementA << "." << endl;
                    cout << "Step " << step++ << ": By Transitivity Rule (A->B ^ B->C => A->C), "
                        << prerequisites[j].elementA << " is a prerequisite of " << course << "." << endl;
                }
            }
            foundAny = true;
        }
    }

    if (foundAny)
        cout << "Conclusion: The prerequisite chain is formally verified. Q.E.D." << endl;
    else
        cout << "Result: No prerequisites found to prove" << endl;
}