#include "UnidiscEngine.h"

#include "MODULE1.h"
#include "MODULE2.h"
#include "MODULE3.h"
#include "MODULE4.h"
#include "MODULE5.h"
#include "MODULE6.h"
#include "MODULE7.h"
#include "MODULE8.h"
#include "MODULE9.h"
#include "MODULE10.h"
#include "MODULE12.h"

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

// --- Memory Management ---

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

// --- Data Management Methods ---

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

void UnidiscEngine::enrollStudent(string sID, string cID)
{
    if (enrollCount == enrollCap) resizeRelationArray(enrollments, enrollCap);
    enrollments[enrollCount].elementA = sID;
    enrollments[enrollCount].elementB = cID;
    enrollCount++;
    cout << "Enrolled " << sID << " in " << cID << endl;
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

// --- Module Delegations ---

void UnidiscEngine::generateCourseSchedule()
{
    Module1 module(courses, courseCount, prerequisites, prereqCount);
    module.generateCourseSchedule();
}

void UnidiscEngine::generateStudentGroups(int k)
{
    Module2 module(students, studentCount);
    module.generateStudentGroups(k);
}

void UnidiscEngine::verifyPrereqChainInduction(string base, string target)
{
    Module3 module(prerequisites, prereqCount);
    module.verifyPrereqChainInduction(base, target);
}

void UnidiscEngine::checkIndirectConflicts()
{
    Module4 module(students, studentCount, prerequisites, prereqCount, enrollments, enrollCount);
    module.checkIndirectConflicts();
}

void UnidiscEngine::analyzeSetOperations(string c1, string c2)
{
    Module5 module(enrollments, enrollCount);
    module.analyzeSetOperations(c1, c2);
}

void UnidiscEngine::analyzeRelations()
{
    Module6 module(courses, courseCount, prerequisites, prereqCount);
    module.analyzeRelations();
}

void UnidiscEngine::analyzeFunctions()
{
    Module7 module(students, studentCount, courses, courseCount, faculties, facultyCount,
        enrollments, enrollCount, facultyAssignments, facAssignCount,
        roomAssignments, roomAssignCount);
    module.analyzeFunctions();
}

void UnidiscEngine::provePrereqChain(string course)
{
    Module8 module(prerequisites, prereqCount, courses, courseCount);
    module.provePrereqChain(course);
}

void UnidiscEngine::runConsistencyCheck()
{
    Module9 module(students, studentCount, courses, courseCount, faculties, facultyCount,
        prerequisites, prereqCount, enrollments, enrollCount, facultyAssignments, facAssignCount);
    module.runConsistencyCheck();
}

void UnidiscEngine::runBenchmarks()
{
    Module10 module(studentCount, courseCount);
    module.runBenchmarks();
}

void UnidiscEngine::runDummyMode()
{
    Module12 module;
    module.runDummyMode(this);
}