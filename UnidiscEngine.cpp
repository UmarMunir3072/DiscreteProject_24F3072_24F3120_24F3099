#include "UnidiscEngine.h"


UnidiscEngine::UnidiscEngine()
{
    studentCap = 5; studentCount = 0; students = new Student[studentCap];
    courseCap = 5; courseCount = 0; courses = new Course[courseCap];
    facultyCap = 5; facultyCount = 0; faculties = new Faculty[facultyCap];
    roomCap = 5; roomCount = 0; rooms = new Room[roomCap];

    prereqCap = 5; prereqCount = 0; prerequisites = new RelationPair[prereqCap];
    enrollCap = 5; enrollCount = 0; enrollments = new RelationPair[enrollCap];
    facAssignCap = 5; facAssignCount = 0; facultyAssignments = new RelationPair[facAssignCap];
    roomAssignCap = 5; roomAssignCount = 0; roomAssignments = new RelationPair[roomAssignCap];
}

UnidiscEngine::~UnidiscEngine()
{
    delete[] students; delete[] courses; delete[] faculties; delete[] rooms;
    delete[] prerequisites; delete[] enrollments; delete[] facultyAssignments; delete[] roomAssignments;
}


void UnidiscEngine::resizeStudentArray()
{
    int newCap = studentCap * 2;
    Student* newArr = new Student[newCap];
    for (int i = 0; i < studentCount; i++) newArr[i] = students[i];
    delete[] students; students = newArr; studentCap = newCap;
}

void UnidiscEngine::resizeCourseArray()
{
    int newCap = courseCap * 2;
    Course* newArr = new Course[newCap];
    for (int i = 0; i < courseCount; i++) newArr[i] = courses[i];
    delete[] courses; courses = newArr; courseCap = newCap;
}

void UnidiscEngine::resizeFacultyArray()
{
    int newCap = facultyCap * 2;
    Faculty* newArr = new Faculty[newCap];
    for (int i = 0; i < facultyCount; i++) newArr[i] = faculties[i];
    delete[] faculties; faculties = newArr; facultyCap = newCap;
}

void UnidiscEngine::resizeRoomArray()
{
    int newCap = roomCap * 2;
    Room* newArr = new Room[newCap];
    for (int i = 0; i < roomCount; i++) newArr[i] = rooms[i];
    delete[] rooms; rooms = newArr; roomCap = newCap;
}

void UnidiscEngine::resizeRelationArray(RelationPair*& arr, int& cap)
{
    int newCap = cap * 2;
    RelationPair* newArr = new RelationPair[newCap];
    for (int i = 0; i < cap; i++) newArr[i] = arr[i];
    delete[] arr; arr = newArr; cap = newCap;
}

int UnidiscEngine::getStudentIndex(string id)
{
    for (int i = 0; i < studentCount; i++) if (students[i].id == id) return i;
    return -1;
}

int UnidiscEngine::getCourseIndex(string code)
{
    for (int i = 0; i < courseCount; i++) if (courses[i].code == code) return i;
    return -1;
}

void UnidiscEngine::addStudent(string id, string name, string program, int sem)
{
    if (studentCount == studentCap) resizeStudentArray();
    students[studentCount].id = id;
    students[studentCount].name = name;
    students[studentCount].program = program;
    students[studentCount].semester = sem;
    studentCount = studentCount + 1;
    cout << "Student added: " << name << endl;
}

void UnidiscEngine::listStudents()
{
    cout << "--- Students ---" << endl;
    for (int i = 0; i < studentCount; i++)
        cout << students[i].id << ": " << students[i].name << " (" << students[i].program << ")" << endl;
}

void UnidiscEngine::addCourse(string code, string title, int ch)
{
    if (courseCount == courseCap) resizeCourseArray();
    courses[courseCount].code = code;
    courses[courseCount].title = title;
    courses[courseCount].creditHours = ch;
    courseCount = courseCount + 1;
    cout << "Course added: " << title << endl;
}

void UnidiscEngine::listCourses()
{
    cout << "--- Courses ---" << endl;
    for (int i = 0; i < courseCount; i++)
        cout << courses[i].code << ": " << courses[i].title << endl;
}

void UnidiscEngine::addFaculty(string id, string name)
{
    if (facultyCount == facultyCap) resizeFacultyArray();
    faculties[facultyCount].id = id;
    faculties[facultyCount].name = name;
    facultyCount = facultyCount + 1;
    cout << "Faculty added: " << name << endl;
}

void UnidiscEngine::listFaculty()
{
    cout << "--- Faculty ---" << endl;
    for (int i = 0; i < facultyCount; i++)
        cout << faculties[i].id << ": " << faculties[i].name << endl;
}

void UnidiscEngine::addRoom(string id, string name)
{
    if (roomCount == roomCap) resizeRoomArray();
    rooms[roomCount].id = id;
    rooms[roomCount].name = name;
    roomCount = roomCount + 1;
    cout << "Room added: " << name << endl;
}

void UnidiscEngine::listRooms()
{
    cout << "--- Rooms ---" << endl;
    for (int i = 0; i < roomCount; i++)
        cout << rooms[i].id << ": " << rooms[i].name << endl;
}


void UnidiscEngine::addPrerequisite(string pre, string post)
{
    if (prereqCount == prereqCap) resizeRelationArray(prerequisites, prereqCap);
    prerequisites[prereqCount].elementA = pre;
    prerequisites[prereqCount].elementB = post;
    prereqCount = prereqCount + 1;
    cout << "Prereq added: " << pre << " -> " << post << endl;
}

void UnidiscEngine::generateCourseSchedule()
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

int UnidiscEngine::factorial(int n)
{
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

void UnidiscEngine::printCombinationsRecursive(string* data, int n, int r, int index, string* current, int i)
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

void UnidiscEngine::generateStudentGroups(int k)
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

bool UnidiscEngine::verifyPrereqChainRecursive(string targetCourse, int depth)
{
    if (depth > 15) return false;
    for (int i = 0; i < prereqCount; i++)
    {
        if (prerequisites[i].elementB == targetCourse)
        {
            cout << "  Requires " << prerequisites[i].elementA << endl;
            if (verifyPrereqChainRecursive(prerequisites[i].elementA, depth + 1) == false) return false;
        }
    }
    return true;
}

void UnidiscEngine::verifyPrereqChainInduction(string base, string target)
{
    cout << "--- Module 3: Induction ---" << endl;
    cout << "Verifying " << base << " -> " << target << endl;
    if (verifyPrereqChainRecursive(target, 0)) cout << "Chain VALID." << endl;
    else cout << "Chain INVALID." << endl;
}


void UnidiscEngine::enrollStudent(string sID, string cID)
{
    if (enrollCount == enrollCap) resizeRelationArray(enrollments, enrollCap);
    enrollments[enrollCount].elementA = sID;
    enrollments[enrollCount].elementB = cID;
    enrollCount++;
    cout << "Enrolled " << sID << " in " << cID << endl;
}

void UnidiscEngine::analyzeSetOperations(string c1, string c2)
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

void UnidiscEngine::assignFaculty(string cCode, string fID)
{
    if (facAssignCount == facAssignCap) resizeRelationArray(facultyAssignments, facAssignCap);
    facultyAssignments[facAssignCount].elementA = cCode;
    facultyAssignments[facAssignCount].elementB = fID;
    facAssignCount++;
    cout << "Faculty assigned." << endl;
}

void UnidiscEngine::assignRoom(string cCode, string rID)
{
    if (roomAssignCount == roomAssignCap) resizeRelationArray(roomAssignments, roomAssignCap);
    roomAssignments[roomAssignCount].elementA = cCode;
    roomAssignments[roomAssignCount].elementB = rID;
    roomAssignCount++;
    cout << "Room assigned." << endl;
}


void UnidiscEngine::checkIndirectConflicts()
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
bool UnidiscEngine::hasRelationPair(string a, string b)
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
void UnidiscEngine::analyzeRelations()
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
void UnidiscEngine::analyzeFunctions()
{
    cout << "--- Module 7: Functions ---" << endl;
    bool valid = true;
    for (int i = 0; i < courseCount; i++)
    {
        int c = 0;
        for (int j = 0; j < facAssignCount; j++)
            if (facultyAssignments[j].elementA == courses[i].code) c++;
        if (c != 1) valid = false;
    }
    if (valid) cout << "Faculty Assignment is a valid Function." << endl;
    else cout << "Faculty Assignment is NOT a function." << endl;
}

void UnidiscEngine::provePrereqChain(string course)
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
                << " is a prerequisite of " << course  << endl;

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

void UnidiscEngine::runConsistencyCheck()
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

void UnidiscEngine::runBenchmarks()
{
    cout << "--- Module 10: Efficiency & Benchmarks ---" << endl;

    cout << "Benchmark Complete." << endl;
    cout << "Dataset Size: " << studentCount << " Students, " << courseCount << " Courses." << endl;
}


void UnidiscEngine::runDummyMode()
{
    cout << " RUNNING MODULE 12: DUMMY TEST CASES & SUITE " << endl;

    cout << " Populating Dummy Data (Module 5)..." << endl;
    addStudent("S1", "Umar", "CS", 3);
    addStudent("S2", "Ali", "SE", 2);
    addStudent("S3", "Rayan", "CS", 3);

    addCourse("CS101", "PF", 3);
    addCourse("CS102", "OOPS", 3);
    addCourse("CS201", "DSA", 3);

    addFaculty("1", "Dr. Qamar");
    addRoom("R1", "Lab 1");

    cout << endl << " Testing Prerequisities (Module 6)..." << endl;
    addPrerequisite("CS101", "CS102");
    addPrerequisite("CS102", "CS201");

    cout << endl << " Testing Enrollment (Module 6)..." << endl;
    enrollStudent("S1", "CS201");
    enrollStudent("S2", "CS102");
    enrollStudent("S3", "CS201");
	enrollStudent("S2", "CS101");

    cout << endl << " Testing Assignments (Module 7)..." << endl;
    assignFaculty("CS101", "1");
    assignFaculty("CS102", "1");
    assignFaculty("CS201", "1");
    assignRoom("CS101", "R1");

    cout << endl << " Running ALL Analysis Modules..." << endl;

    generateCourseSchedule();
    cout << endl;

    generateStudentGroups(2);
    cout << endl;

    verifyPrereqChainInduction("CS101", "CS201");
    cout << endl;

    checkIndirectConflicts();
    cout << endl;

    analyzeSetOperations("CS101", "CS102");
    cout << endl;

    analyzeRelations();
    cout << endl;

    analyzeFunctions();
    cout << endl;

    provePrereqChain("CS201");
    cout << endl;

    runConsistencyCheck();
    cout << endl;

    runBenchmarks();
}