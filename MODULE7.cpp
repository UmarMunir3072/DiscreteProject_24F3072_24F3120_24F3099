#include "Module7.h"

void Module7::analyzeFunctions()
{
    cout << "--- Module 7: Functions, Composition & Inverse ---" << endl;

    if (studentCount == 0 || courseCount == 0)
    {
        cout << "Error: Insufficient data for analysis." << endl;
        return;
    }

    cout << endl;
    cout << "[Analysis 1] Mapping: Students -> Courses" << endl;

    bool scIsFunction = true;
    for (int i = 0; i < studentCount; i++)
    {
        int count = 0;
        for (int j = 0; j < enrollCount; j++)
        {
            if (enrollments[j].elementA == students[i].id)
            {
                count = count + 1;
            }
        }
        if (count != 1)
        {
            scIsFunction = false;
        }
    }

    if (!scIsFunction)
    {
        cout << "Result: NOT a Function (Some students take 0 or >1 courses)." << endl;
    }
    else
    {
        cout << "Result: Valid Function." << endl;

        bool isInjective = true;
        for (int i = 0; i < courseCount; i++)
        {
            int mapped = 0;
            for (int j = 0; j < enrollCount; j++)
            {
                if (enrollments[j].elementB == courses[i].code)
                {
                    mapped = mapped + 1;
                }
            }
            if (mapped > 1)
            {
                isInjective = false;
            }
        }

        bool isSurjective = true;
        for (int i = 0; i < courseCount; i++)
        {
            int mapped = 0;
            for (int j = 0; j < enrollCount; j++)
            {
                if (enrollments[j].elementB == courses[i].code)
                {
                    mapped = mapped + 1;
                }
            }
            if (mapped == 0)
            {
                isSurjective = false;
            }
        }

        if (isInjective)
        {
            cout << " - Injective: YES" << endl;
        }
        else
        {
            cout << " - Injective: NO" << endl;
        }

        if (isSurjective)
        {
            cout << " - Surjective: YES" << endl;
        }
        else
        {
            cout << " - Surjective: NO" << endl;
        }

        if (isInjective && isSurjective)
        {
            cout << " - Bijective: YES" << endl;
        }
        else
        {
            cout << " - Bijective: NO" << endl;
        }
    }

    cout << endl;
    cout << "[Analysis 2] Mapping: Courses -> Faculty" << endl;

    bool cfIsFunction = true;
    for (int i = 0; i < courseCount; i++)
    {
        int count = 0;
        for (int j = 0; j < facAssignCount; j++)
        {
            if (facultyAssignments[j].elementA == courses[i].code)
            {
                count = count + 1;
            }
        }
        if (count != 1)
        {
            cfIsFunction = false;
        }
    }

    if (!cfIsFunction)
    {
        cout << "Result: NOT a Function." << endl;
    }
    else
    {
        cout << "Result: Valid Function." << endl;

        bool isInjective = true;
        for (int i = 0; i < facultyCount; i++)
        {
            int mapped = 0;
            for (int j = 0; j < facAssignCount; j++)
            {
                if (facultyAssignments[j].elementB == faculties[i].id)
                {
                    mapped = mapped + 1;
                }
            }
            if (mapped > 1)
            {
                isInjective = false;
            }
        }

        bool isSurjective = true;
        for (int i = 0; i < facultyCount; i++)
        {
            int mapped = 0;
            for (int j = 0; j < facAssignCount; j++)
            {
                if (facultyAssignments[j].elementB == faculties[i].id)
                {
                    mapped = mapped + 1;
                }
            }
            if (mapped == 0)
            {
                isSurjective = false;
            }
        }

        if (isInjective)
        {
            cout << " - Injective: YES" << endl;
        }
        else
        {
            cout << " - Injective: NO" << endl;
        }

        if (isSurjective)
        {
            cout << " - Surjective: YES" << endl;
        }
        else
        {
            cout << " - Surjective: NO" << endl;
        }

        if (isInjective && isSurjective)
        {
            cout << " - Bijective: YES" << endl;
            cout << "   [Inverse Map Generated: Faculty -> Course]" << endl;
            cout << "   { ";
            for (int k = 0; k < facAssignCount; k++)
            {
                cout << "(" << facultyAssignments[k].elementB << "->" << facultyAssignments[k].elementA << ") ";
            }
            cout << "}" << endl;
        }
        else
        {
            cout << " - Bijective: NO (Inverse not possible)" << endl;
        }
    }

    cout << endl;
    cout << "[Analysis 3] Composition: Student -> Faculty" << endl;
    cout << "Logic: (Student -> Course) o (Course -> Faculty)" << endl;
    cout << "Pairs: { ";
    for (int i = 0; i < enrollCount; i++)
    {
        string s = enrollments[i].elementA;
        string c = enrollments[i].elementB;

        string f = "None";
        for (int j = 0; j < facAssignCount; j++)
        {
            if (facultyAssignments[j].elementA == c)
            {
                f = facultyAssignments[j].elementB;
            }
        }

        if (f != "None")
        {
            cout << "(" << s << " -> " << f << ") ";
        }
    }
    cout << "}" << endl;

    cout << endl;
    cout << "[Analysis 4] Mapping: Faculty -> Rooms" << endl;
    cout << "Logic: Faculty -> Course -> Room" << endl;

    for (int i = 0; i < facultyCount; i++)
    {
        string fID = faculties[i].id;
        cout << "  Faculty " << fID << " teaches in: { ";

        for (int j = 0; j < facAssignCount; j++)
        {
            if (facultyAssignments[j].elementB == fID)
            {
                string c = facultyAssignments[j].elementA;
                for (int k = 0; k < roomAssignCount; k++)
                {
                    if (roomAssignments[k].elementA == c)
                    {
                        cout << roomAssignments[k].elementB << " ";
                    }
                }
            }
        }
        cout << "}" << endl;
    }
}