#include "Module4.h"

void Module4::checkIndirectConflicts()
{
    cout << "--- Module 4: Logic & Inference Engine ---" << endl;
    cout << "Rule: Enrolled(S, PostReq) -> Must have Enrolled(S, PreReq)" << endl;

    bool conflictFound = false;

    for (int s = 0; s < studentCount; s++)
    {
        string sID = students[s].id;

        for (int p = 0; p < prereqCount; p++)
        {
            string pre = prerequisites[p].elementA;
            string post = prerequisites[p].elementB;

            bool takingPost = false;
            for (int e = 0; e < enrollCount; e++)
            {
                if (enrollments[e].elementA == sID && enrollments[e].elementB == post)
                    takingPost = true;
            }

            bool takingPre = false;
            for (int e = 0; e < enrollCount; e++)
            {
                if (enrollments[e].elementA == sID && enrollments[e].elementB == pre)
                    takingPre = true;
            }

            if (takingPost && !takingPre)
            {
                cout << "[CONFLICT] Student " << sID << " is taking " << post
                    << " but missing prerequisite " << pre << "!" << endl;
                conflictFound = true;
            }
        }
    }

    if (!conflictFound)
    {
        cout << "Inference Result: All enrollment logic is valid." << endl;
    }
}