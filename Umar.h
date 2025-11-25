

class UnidiscEngine
{
private:
    void resizeStudentArray();
    void resizeCourseArray();
    void resizeFacultyArray();
    void resizeRoomArray();
    void resizeRelationArray(RelationPair*& arr, int& cap);

public:
    void runConsistencyCheck();
    void runBenchmarks();

    void addStudent(string id, string name, string program, int sem);
    void listStudents();
    void addCourse(string code, string title, int ch);
    void listCourses();
    void addFaculty(string id, string name);
    void listFaculty();
    void addRoom(string id, string name);
    void listRooms();
};
