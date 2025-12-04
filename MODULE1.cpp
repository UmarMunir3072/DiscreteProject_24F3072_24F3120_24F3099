#include "Module1.h"

int Module1::getCourseIndex(string code)
{
    for (int i = 0; i < courseCount; i++) if (courses[i].code == code) return i;
    return -1;
}

void Module1::generateCourseSchedule()
{
    cout << "--- Module 1: Scheduling ---" << endl;
    int* inDegree = new int[courseCount];
    bool* visited = new bool[courseCount];
    for (int i = 0; i < courseCount; i++) { inDegree[i] = 0; visited[i] = false; }

    for (int i = 0; i < prereqCount; i++)
    {
        int idx = getCourseIndex(prerequisites[i].elementB);
        if (idx != -1) inDegree[idx] = inDegree[idx] + 1;
    }

    int sem = 1;
    bool processing = true;
    while (processing)
    {
        processing = false;
        cout << "Semester " << sem << ": ";
        bool found = false;
        for (int i = 0; i < courseCount; i++)
        {
            if (visited[i] == false)
            {
                if (inDegree[i] == 0)
                {
                    cout << "[" << courses[i].code << "] ";
                    visited[i] = true;
                    found = true;
                    for (int j = 0; j < prereqCount; j++)
                    {
                        if (prerequisites[j].elementA == courses[i].code)
                        {
                            int t = getCourseIndex(prerequisites[j].elementB);
                            if (t != -1) inDegree[t] = inDegree[t] - 1;
                        }
                    }
                }
            }
        }
        if (found) { cout << endl; processing = true; sem = sem + 1; }
    }
    delete[] inDegree; delete[] visited;
}