#include <iostream>
#include "UnidiscEngine.h"

using namespace std;

void showLiveMenu()
{
    cout << "===== FAST UNIVERSITY LIVE MENU =====" << endl;
    cout << "1) Add Student " << endl;
    cout << "2) List Students " << endl;
    cout << "3) Add Course " << endl;
    cout << "4) List Courses " << endl;
    cout << "5) Add Faculty " << endl;
    cout << "6) List Faculty " << endl;
    cout << "7) Add Room " << endl;
    cout << "8) List Rooms (Module 5: Sets)" << endl;
    cout << "9) Add Prerequisite " << endl;
    cout << "10) Generate Schedule " << endl;
    cout << "11) Generate Groups " << endl;
    cout << "12) Verify Induction " << endl;
    cout << "13) Enroll Student " << endl;
    cout << "14) Set Intersection " << endl;
    cout << "15) Analyze Relations " << endl;
    cout << "16) Assign Faculty " << endl;
    cout << "17) Assign Room " << endl;
    cout << "18) Analyze Functions " << endl;
    cout << "19) Prove Chain " << endl;
    cout << "20) Consistency Check " << endl;
    cout << "21) Benchmarks " << endl;
    cout << "22) Check Logic Conflicts " << endl;
    cout << "0) Exit" << endl;
    cout << "Choice: ";
}

int main()
{
    UnidiscEngine* engine = new UnidiscEngine();

    int mode = 0;
    while (mode != 1 && mode != 2)
    {
        cout << "========================================" << endl;
        cout << "       UNIDISC ENGINE LAUNCHER          " << endl;
        cout << "========================================" << endl;
        cout << "1. Dummy Mode (Run Module 12 Test Cases)" << endl;
        cout << "2. Live Mode  (Start Empty)" << endl;
        cout << "Select Option: ";
        cin >> mode;
        cin.ignore();
        cout << endl;

        if (mode == 1)
        {
            engine->runDummyMode();
            string dummy;
            getline(cin, dummy);
        }
        else if (mode == 2)
        {
            cout << "Starting Live System (Empty Database)..." << endl;

            int choice = -1;
            string s1, s2, s3;
            int i1;

            while (choice != 0)
            {
                showLiveMenu();
                cin >> choice;
                cin.ignore();
                cout << endl;

                if (choice == 0)
                {
                    cout << "Exiting..." << endl;
                }
                else if (choice == 1)
                {
                    cout << "ID: "; getline(cin, s1);
                    cout << "Name: "; getline(cin, s2);
                    cout << "Program: "; getline(cin, s3);
                    cout << "Semester: "; cin >> i1;
                    cin.ignore();
                    engine->addStudent(s1, s2, s3, i1);
                }
                else if (choice == 2)
                {
                    engine->listStudents();
                }
                else if (choice == 3)
                {
                    cout << "Code: "; getline(cin, s1);
                    cout << "Title: "; getline(cin, s2);
                    cout << "Credits: "; cin >> i1;
                    cin.ignore();
                    engine->addCourse(s1, s2, i1);
                }
                else if (choice == 4)
                {
                    engine->listCourses();
                }
                else if (choice == 5)
                {
                    cout << "ID: "; getline(cin, s1);
                    cout << "Name: "; getline(cin, s2);
                    engine->addFaculty(s1, s2);
                }
                else if (choice == 6)
                {
                    engine->listFaculty();
                }
                else if (choice == 7)
                {
                    cout << "ID: "; getline(cin, s1);
                    cout << "Name: "; getline(cin, s2);
                    engine->addRoom(s1, s2);
                }
                else if (choice == 8)
                {
                    engine->listRooms();
                }
                else if (choice == 9)
                {
                    cout << "Base Code: "; getline(cin, s1);
                    cout << "Target Code: "; getline(cin, s2);
                    engine->addPrerequisite(s1, s2);
                }
                else if (choice == 10)
                {
                    engine->generateCourseSchedule();
                }
                else if (choice == 11)
                {
                    cout << "Enter group size k: "; cin >> i1;
                    cin.ignore();
                    engine->generateStudentGroups(i1);
                }
                else if (choice == 12)
                {
                    cout << "Enter base course: "; getline(cin, s1);
                    cout << "Enter target course: "; getline(cin, s2);
                    engine->verifyPrereqChainInduction(s1, s2);
                }
                else if (choice == 13)
                {
                    cout << "Student ID: "; getline(cin, s1);
                    cout << "Course Code: "; getline(cin, s2);
                    engine->enrollStudent(s1, s2);
                }
                else if (choice == 14)
                {
                    cout << "Course 1: "; getline(cin, s1);
                    cout << "Course 2: "; getline(cin, s2);
                    engine->analyzeSetOperations(s1, s2);
                }
                else if (choice == 15)
                {
                    engine->analyzeRelations();
                }
                else if (choice == 16)
                {
                    cout << "Course: "; getline(cin, s1);
                    cout << "Faculty ID: "; getline(cin, s2);
                    engine->assignFaculty(s1, s2);
                }
                else if (choice == 17)
                {
                    cout << "Course: "; getline(cin, s1);
                    cout << "Room ID: "; getline(cin, s2);
                    engine->assignRoom(s1, s2);
                }
                else if (choice == 18)
                {
                    engine->analyzeFunctions();
                }
                else if (choice == 19)
                {
                    cout << "Course: "; getline(cin, s1);
                    engine->provePrereqChain(s1);
                }
                else if (choice == 20)
                {
                    engine->runConsistencyCheck();
                }
                else if (choice == 21)
                {
                    engine->runBenchmarks();
                }
                else if (choice == 22)
                {
                    engine->checkIndirectConflicts();
                }
                else
                {
                    cout << "Feature under construction." << endl;
                }

                cout << endl << "Press Enter to continue..." << endl;
                string dummy;
                getline(cin, dummy);
            }

        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    delete engine;
    return 0;
}