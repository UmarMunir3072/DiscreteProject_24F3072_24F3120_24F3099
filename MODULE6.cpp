#include "Module6.h"

bool Module6::hasRelationPair(string a, string b)
{
    for (int i = 0; i < prereqCount; i++)
    {
        if (prerequisites[i].elementA == a)
        {
            if (prerequisites[i].elementB == b)
            {
                return true;
            }
        }
    }
    return false;
}

void Module6::analyzeRelations()
{
    cout << "--- Module 6: Relations Property Analysis ---" << endl;

    if (courseCount == 0)
    {
        cout << "No courses defined to analyze." << endl;
        return;
    }

    bool isReflexive = true;
    for (int i = 0; i < courseCount; i++)
    {
        if (hasRelationPair(courses[i].code, courses[i].code) == false)
        {
            isReflexive = false;
        }
    }

    bool isSymmetric = true;
    for (int i = 0; i < prereqCount; i++)
    {
        string a = prerequisites[i].elementA;
        string b = prerequisites[i].elementB;
        if (hasRelationPair(b, a) == false)
        {
            isSymmetric = false;
        }
    }

    bool isAntisymmetric = true;
    for (int i = 0; i < prereqCount; i++)
    {
        string a = prerequisites[i].elementA;
        string b = prerequisites[i].elementB;

        if (a != b)
        {
            if (hasRelationPair(b, a) == true)
            {
                isAntisymmetric = false;
            }
        }
    }

    bool isTransitive = true;
    for (int i = 0; i < prereqCount; i++)
    {
        string a = prerequisites[i].elementA;
        string b = prerequisites[i].elementB;

        for (int j = 0; j < prereqCount; j++)
        {
            if (prerequisites[j].elementA == b)
            {
                string c = prerequisites[j].elementB;
                if (hasRelationPair(a, c) == false)
                {
                    isTransitive = false;
                }
            }
        }
    }

    cout << "Properties of the Prerequisite Relation:" << endl;

    if (isReflexive)
    {
        cout << "1. Reflexive:     YES" << endl;
    }
    else
    {
        cout << "1. Reflexive:     NO" << endl;
    }

    if (isSymmetric)
    {
        cout << "2. Symmetric:     YES" << endl;
    }
    else
    {
        cout << "2. Symmetric:     NO" << endl;
    }

    if (isAntisymmetric)
    {
        cout << "3. Antisymmetric: YES" << endl;
    }
    else
    {
        cout << "3. Antisymmetric: NO" << endl;
    }

    if (isTransitive)
    {
        cout << "4. Transitive:    YES" << endl;
    }
    else
    {
        cout << "4. Transitive:    NO" << endl;
    }

    cout << "-----------------------------------" << endl;

    if (isReflexive)
    {
        if (isSymmetric)
        {
            if (isTransitive)
            {
                cout << "Classification: EQUIVALENCE RELATION" << endl;
            }
            else
            {
                cout << "Classification: None (Transitivity missing for Equivalence)" << endl;
            }
        }
        else if (isAntisymmetric)
        {
            if (isTransitive)
            {
                cout << "Classification: PARTIAL ORDER (POSET)" << endl;
            }
            else
            {
                cout << "Classification: None (Transitivity missing for Partial Order)" << endl;
            }
        }
        else
        {
            cout << "Classification: None" << endl;
        }
    }
    else
    {
        cout << "Classification: None (Relation is Irreflexive or not fully Reflexive)" << endl;
        cout << "Note: Prerequisites are typically Strict Partial Orders (Irreflexive, Antisymmetric, Transitive)." << endl;
    }
}