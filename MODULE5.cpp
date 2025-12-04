#include "Module5.h"

void Module5::analyzeSetOperations(string c1, string c2)
{
    cout << "--- Module 5: Sets (Intersection) ---" << endl;
    cout << "Students in " << c1 << " AND " << c2 << ": { ";
    for (int i = 0; i < enrollCount; i++)
    {
        if (enrollments[i].elementB == c1)
        {
            string s = enrollments[i].elementA;
            for (int j = 0; j < enrollCount; j++)
            {
                if (enrollments[j].elementA == s && enrollments[j].elementB == c2) cout << s << " ";
            }
        }
    }
    cout << "}" << endl;
}