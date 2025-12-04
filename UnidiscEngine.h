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
    // Allow Module 12 to access private members for populating dummy data
    friend class Module12;

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

    // Memory Management Helpers
    void resizeStudentArray();
    void resizeCourseArray();
    void resizeFacultyArray();
    void resizeRoomArray();
    void resizeRelationArray(RelationPair*& arr, int& cap);

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
    void enrollStudent(string sID, string cID);
    void assignFaculty(string cCode, string fID);
    void assignRoom(string cCode, string rID);

    void generateCourseSchedule();                  // Module 1
    void generateStudentGroups(int k);              // Module 2
    void verifyPrereqChainInduction(string base, string target); // Module 3
    void checkIndirectConflicts();                  // Module 4
    void analyzeSetOperations(string c1, string c2);// Module 5
    void analyzeRelations();                        // Module 6
    void analyzeFunctions();                        // Module 7
    void provePrereqChain(string course);           // Module 8
    void runConsistencyCheck();                     // Module 9
    void runBenchmarks();                           // Module 10
    void runDummyMode();                            // Module 12
};

#endif