#include "Module2.h"

int Module2::factorial(int n)
{
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void Module2::printCombinationsRecursive(string* data, int n, int r, int index, string* current, int i)
{
    if (index == r)
    {
        cout << "{ ";
        for (int j = 0; j < r; j++) cout << current[j] << " ";
        cout << "}" << endl;
        return;
    }
    if (i >= n) return;
    current[index] = data[i];
    printCombinationsRecursive(data, n, r, index + 1, current, i + 1);
    printCombinationsRecursive(data, n, r, index, current, i + 1);
}

void Module2::generateStudentGroups(int k)
{
    cout << "--- Module 2: Combinations ---" << endl;
    if (studentCount < k) { cout << "Not enough students." << endl; return; }
    string* sIds = new string[studentCount];
    for (int i = 0; i < studentCount; i++) sIds[i] = students[i].id;
    string* temp = new string[k];
    printCombinationsRecursive(sIds, studentCount, k, 0, temp, 0);
    int comb = factorial(studentCount) / (factorial(k) * factorial(studentCount - k));
    cout << "Total C(" << studentCount << "," << k << "): " << comb << endl;
    delete[] sIds; delete[] temp;
}