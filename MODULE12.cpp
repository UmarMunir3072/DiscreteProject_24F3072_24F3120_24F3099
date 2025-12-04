#include "Module12.h"

void Module12::runDummyMode(UnidiscEngine* engine)
{
    cout << " RUNNING MODULE 12: DUMMY TEST CASES & SUITE " << endl;

    cout << " Populating Dummy Data ..." << endl;
    engine->addStudent("S1", "Umar", "CS", 3);
    engine->addStudent("S2", "Ali", "SE", 2);
    engine->addStudent("S3", "Rayan", "CS", 3);

    engine->addCourse("CS101", "PF", 3);
    engine->addCourse("CS102", "OOPS", 3);
    engine->addCourse("CS201", "DSA", 3);

    engine->addFaculty("1", "Dr. Qamar");
    engine->addRoom("R1", "Lab 1");

    cout << endl << " Testing Prerequisities" << endl;
    engine->addPrerequisite("CS101", "CS102");
    engine->addPrerequisite("CS102", "CS201");

    cout << endl << " Testing Enrollment" << endl;
    engine->enrollStudent("S1", "CS201");
    engine->enrollStudent("S2", "CS102");
    engine->enrollStudent("S3", "CS201");
    engine->enrollStudent("S2", "CS101");

    cout << endl << " Testing Assignments" << endl;
    engine->assignFaculty("CS101", "1");
    engine->assignFaculty("CS102", "1");
    engine->assignFaculty("CS201", "1");
    engine->assignRoom("CS101", "R1");

    cout << endl << " Running ALL Analysis Modules..." << endl;

    engine->generateCourseSchedule();
    cout << endl;

    engine->generateStudentGroups(2);
    cout << endl;

    engine->verifyPrereqChainInduction("CS101", "CS201");
    cout << endl;

    engine->checkIndirectConflicts();
    cout << endl;

    engine->analyzeSetOperations("CS101", "CS102");
    cout << endl;

    engine->analyzeRelations();
    cout << endl;

    engine->analyzeFunctions();
    cout << endl;

    engine->provePrereqChain("CS201");
    cout << endl;

    engine->runConsistencyCheck();
    cout << endl;

    engine->runBenchmarks();
}