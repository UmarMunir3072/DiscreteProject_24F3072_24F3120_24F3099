#ifndef UNIDISC_ENGINE_H
#define UNIDISC_ENGINE_H

#include <iostream>
#include <string>

using namespace std;

struct Student
{
    string id;
    string name;
    string program;
    int semester;
};

struct Course
{
    string code;
    string title;
    int creditHours;
};

struct Faculty
{
    string id;
    string name;
};

struct Room
{
    string id;
    string name;
};

struct RelationPair
{
    string elementA;
    string elementB;
};

class UnidiscEngine
{
private:
    Student* students;
    int studentCount;
    int studentCap;

    Course* courses;
    int courseCount;
    int courseCap;

    Faculty* faculties;
    int facultyCount;
    int facultyCap;

    Room* rooms;
    int roomCount;
    int roomCap;

    RelationPair* prerequisites;
    int prereqCount;
    int prereqCap;

    RelationPair* enrollments;
    int enrollCount;
    int enrollCap;

    RelationPair* facultyAssignments;
    int facAssignCount;
    int facAssignCap;

    RelationPair* roomAssignments;
    int roomAssignCount;
    int roomAssignCap;

    void resizeStudentArray();
    void resizeCourseArray();
    void resizeFacultyArray();
    void resizeRoomArray();
    void resizeRelationArray(RelationPair*& arr, int& cap);

    int getStudentIndex(string id);
    int getCourseIndex(string code);

    void printCombinationsRecursive(string* data, int n, int r, int index, string* current, int i);
    int factorial(int n);
    bool verifyPrereqChainRecursive(string targetCourse, int depth);

    bool hasRelationPair(string a, string b);

public:
    UnidiscEngine();
    ~UnidiscEngine();

    void addStudent(string id, string name, string program, int sem);
    void listStudents();
    void addCourse(string code, string title, int ch);
    void listCourses();
    void addFaculty(string id, string name);
    void listFaculty();
    void addRoom(string id, string name);
    void listRooms();

    void addPrerequisite(string pre, string post);
    void generateCourseSchedule();
    void generateStudentGroups(int k);
    void verifyPrereqChainInduction(string base, string target);
    void enrollStudent(string sID, string cID);
    void analyzeSetOperations(string c1, string c2);
    void analyzeRelations();
    void assignFaculty(string cCode, string fID);
    void assignRoom(string cCode, string rID);
    void checkIndirectConflicts();
    void analyzeFunctions();
    void provePrereqChain(string course);
    void runConsistencyCheck();
    void runBenchmarks();

    void runDummyMode();
};

#endif