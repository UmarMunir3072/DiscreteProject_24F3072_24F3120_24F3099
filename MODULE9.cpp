#include "Module9.h"

int Module9::getStudentIndex(string id)
{
    for (int i = 0; i < studentCount; i++) if (students[i].id == id) return i;
    return -1;
}

int Module9::getCourseIndex(string code)
{
    for (int i = 0; i < courseCount; i++) if (courses[i].code == code) return i;
    return -1;
}

void Module9::runConsistencyCheck()
{
    cout << "--- Module 9: System Consistency Checker ---" << endl;

    int errors = 0;

    cout << " Validating Prerequisite References..." << endl;
    for (int i = 0; i < prereqCount; i++)
    {
        string pre = prerequisites[i].elementA;
        string post = prerequisites[i].elementB;

        if (getCourseIndex(pre) == -1)
        {
            cout << "  ERROR: Prerequisite '" << pre << "' does not exist in Course List." << endl;
            errors = errors + 1;
        }
        if (getCourseIndex(post) == -1)
        {
            cout << "  ERROR: Target Course '" << post << "' does not exist in Course List." << endl;
            errors = errors + 1;
        }
        if (pre == post)
        {
            cout << "  ERROR: Circular logic detected. '" << pre << "' cannot require itself." << endl;
            errors = errors + 1;
        }
    }

    cout << " Validating Enrollment Records..." << endl;
    for (int i = 0; i < enrollCount; i++)
    {
        string sID = enrollments[i].elementA;
        string cCode = enrollments[i].elementB;

        if (getStudentIndex(sID) == -1)
        {
            cout << "  ERROR: Enrolled Student '" << sID << "' does not exist." << endl;
            errors = errors + 1;
        }
        if (getCourseIndex(cCode) == -1)
        {
            cout << "  ERROR: Enrolled Course '" << cCode << "' does not exist." << endl;
            errors = errors + 1;
        }
    }

    cout << " Validating Faculty Assignments..." << endl;
    for (int i = 0; i < facAssignCount; i++)
    {
        string cCode = facultyAssignments[i].elementA;
        string fID = facultyAssignments[i].elementB;

        bool facultyExists = false;
        for (int j = 0; j < facultyCount; j++)
        {
            if (faculties[j].id == fID)
            {
                facultyExists = true;
            }
        }

        if (facultyExists == false)
        {
            cout << "  ERROR: Assigned Faculty '" << fID << "' not found in database." << endl;
            errors = errors + 1;
        }

        if (getCourseIndex(cCode) == -1)
        {
            cout << "  ERROR: Course '" << cCode << "' in faculty assignment not found." << endl;
            errors = errors + 1;
        }
    }

    cout << " Validating Student Prerequisite " << endl;
    for (int i = 0; i < enrollCount; i++)
    {
        string sID = enrollments[i].elementA;
        string currentCourse = enrollments[i].elementB;

        for (int j = 0; j < prereqCount; j++)
        {
            if (prerequisites[j].elementB == currentCourse)
            {
                string required = prerequisites[j].elementA;

                bool hasTaken = false;
                for (int k = 0; k < enrollCount; k++)
                {
                    if (enrollments[k].elementA == sID)
                    {
                        if (enrollments[k].elementB == required)
                        {
                            hasTaken = true;
                        }
                    }
                }

                if (hasTaken == false)
                {
                    cout << "  VIOLATION: Student " << sID << " enrolled in " << currentCourse
                        << " without taking prerequisite " << required << "." << endl;
                    errors = errors + 1;
                }
            }
        }
    }

    cout << endl;
    if (errors == 0)
    {
        cout << "System Status: CONSISTENT (0 Errors)" << endl;
    }
    else
    {
        cout << "System Status: INCONSISTENT (" << errors << " Errors Found)" << endl;
    }
}