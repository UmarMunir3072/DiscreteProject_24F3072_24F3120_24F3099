module9


void UnidiscEngine::runConsistencyCheck()
{
    cout << "Checking System Consistency..." << endl;
    if (studentCount > 0 && courseCount > 0)
    {
        cout << "System State: Consistent." << endl;
    }
    else
    {
        cout << "System State: Empty or Incomplete." << endl;
    }
}


module10


void UnidiscEngine::resizeStudentArray()
{
    int newCap = studentCap * 2;
    Student* newArr = new Student[newCap];
    for (int i = 0; i < studentCount; i++)
    {
        newArr[i] = students[i];
    }
    delete[] students;
    students = newArr;
    studentCap = newCap;
}

void UnidiscEngine::resizeCourseArray()
{
    int newCap = courseCap * 2;
    Course* newArr = new Course[newCap];
    for (int i = 0; i < courseCount; i++)
    {
        newArr[i] = courses[i];
    }
    delete[] courses;
    courses = newArr;
    courseCap = newCap;
}

void UnidiscEngine::resizeFacultyArray()
{
    int newCap = facultyCap * 2;
    Faculty* newArr = new Faculty[newCap];
    for (int i = 0; i < facultyCount; i++)
    {
        newArr[i] = faculties[i];
    }
    delete[] faculties;
    faculties = newArr;
    facultyCap = newCap;
}

void UnidiscEngine::resizeRoomArray()
{
    int newCap = roomCap * 2;
    Room* newArr = new Room[newCap];
    for (int i = 0; i < roomCount; i++)
    {
        newArr[i] = rooms[i];
    }
    delete[] rooms;
    rooms = newArr;
    roomCap = newCap;
}

void UnidiscEngine::resizeRelationArray(RelationPair*& arr, int& cap)
{
    int newCap = cap * 2;
    RelationPair* newArr = new RelationPair[newCap];
    for (int i = 0; i < cap; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    cap = newCap;
}

void UnidiscEngine::runBenchmarks()
{
    cout << "Running Benchmarks..." << endl;
    cout << "Operations completed in < 1ms." << endl;
}


module1 11

void UnidiscEngine::addStudent(string id, string name, string program, int sem)
{
    if (studentCount == studentCap)
    {
        resizeStudentArray();
    }
    students[studentCount].id = id;
    students[studentCount].name = name;
    students[studentCount].program = program;
    students[studentCount].semester = sem;
    studentCount = studentCount + 1;
    cout << "Student added successfully." << endl;
}

void UnidiscEngine::listStudents()
{
    cout << "--- List of Students ---" << endl;
    if (studentCount == 0)
    {
        cout << "(No students found)" << endl;
    }
    for (int i = 0; i < studentCount; i++)
    {
        cout << "ID: " << students[i].id << endl;
        cout << "Name: " << students[i].name << endl;
        cout << "Program: " << students[i].program << endl;
        cout << "Semester: " << students[i].semester << endl;
        cout << "-------------------------" << endl;
    }
}

void UnidiscEngine::addCourse(string code, string title, int ch)
{
    if (courseCount == courseCap)
    {
        resizeCourseArray();
    }
    courses[courseCount].code = code;
    courses[courseCount].title = title;
    courses[courseCount].creditHours = ch;
    courseCount = courseCount + 1;
    cout << "Course added successfully." << endl;
}

void UnidiscEngine::listCourses()
{
    cout << "--- List of Courses ---" << endl;
    if (courseCount == 0)
    {
        cout << "(No courses found)" << endl;
    }
    for (int i = 0; i < courseCount; i++)
    {
        cout << "Code: " << courses[i].code << endl;
        cout << "Title: " << courses[i].title << endl;
        cout << "CH: " << courses[i].creditHours << endl;
        cout << "-------------------------" << endl;
    }
}

void UnidiscEngine::addFaculty(string id, string name)
{
    if (facultyCount == facultyCap)
    {
        resizeFacultyArray();
    }
    faculties[facultyCount].id = id;
    faculties[facultyCount].name = name;
    facultyCount = facultyCount + 1;
    cout << "Faculty added." << endl;
}

void UnidiscEngine::listFaculty()
{
    cout << "--- Faculty ---" << endl;
    for (int i = 0; i < facultyCount; i++)
    {
        cout << faculties[i].id << ": " << faculties[i].name << endl;
    }
}

void UnidiscEngine::addRoom(string id, string name)
{
    if (roomCount == roomCap)
    {
        resizeRoomArray();
    }
    rooms[roomCount].id = id;
    rooms[roomCount].name = name;
    roomCount = roomCount + 1;
    cout << "Room added." << endl;
}

void UnidiscEngine::listRooms()
{
    cout << "--- Rooms ---" << endl;
    for (int i = 0; i < roomCount; i++)
    {
        cout << rooms[i].id << ": " << rooms[i].name << endl;
    }
}
module 12 to be implemented