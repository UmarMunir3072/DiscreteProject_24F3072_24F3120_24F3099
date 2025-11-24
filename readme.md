Fast University Management System:

At FAST University, managing courses, prerequisites, student enrollment, faculty assignments, and resources involves complex dependencies and rules. This project creates a high-level computational framework that models FAST University’s operations using discrete structures, enforcing rules and verifying correctness


24F-3099 (Modules 1-4)
   
       Module 1: Course Permutation & Scheduling
           - void addPrerequisite(string pre, string post)
             Maps a prerequisite relation between two courses (Relation A -> B).
             
           - void generateCourseSchedule()
             Implements a Topological Sort algorithm to generate a valid 
             semester-wise schedule where prerequisites are met before 
             advanced courses. Detects cycles in the graph.

       Module 2: Student Group Combinations
           - void generateStudentGroups(int k)
             Calculates and displays all possible unique groups of size k 
             from the set of students using recursion.
             
           - void printCombinationsRecursive(...)
             A helper function that iterates through the set of students to 
             generate subsets without repetition.
             
           - int factorial(int n)
             Helper function to calculate factorials for the nCr formula.

       Module 3: Induction & Strong Induction
           - void verifyPrereqChainInduction(string base, string target)
             Prints a formal mathematical proof structure (Base Step, 
             Hypothesis, Inductive Step) for a prerequisite chain.
             
           - bool verifyPrereqChainRecursive(string targetCourse, int depth)
             The internal recursive engine that traverses the prerequisite 
             tree to validate Strong Induction hypotheses.

       Module 4: Logic & Inference Engine
           - checkIndirectConflicts()
             Integrated into Relations/Logic checks. Checks for logical 
             inconsistencies in data rules.



24F-3120 (Modules 5-8)

       Module 5: Set Operations
           - void enrollStudent(string sID, string cID)
             Creates a mapping in the Enrollment Relation 
             (Set Student x Course).
             
           - void analyzeSetOperations(string c1, string c2)
             Performs Intersection operations on two course sets to find 
             students enrolled in both.

       Module 6: Relations Module
           - void analyzeRelations()
             Iterates through the Prerequisite relations to test for 
             Reflexivity (checking if aRa exists, which is invalid for 
             prerequisites) and Irreflexivity.
             
           - void assignRoom(string cCode, string rID)
             Manages the binary relation between Courses and Rooms.

       Module 7: Functions Module
           - void assignFaculty(string cCode, string fID)
             Maps a Course to a Faculty member.
             
           - void analyzeFunctions()
             Verifies if the assignment of Faculty to Courses represents a 
             valid mathematical Function (checking that every course maps 
             to exactly one faculty member).

       Module 8: Automated Proof & Verification
           - void provePrereqChain(string course)
             Generates a text-based formal proof output, demonstrating 
             "Q.E.D" for the validity of a specific course chain.

24F-3072 (Modules 9-12)

       Module 9: Consistency Checker
           - void runConsistencyCheck()
             Scans all arrays and relations to ensure no "dangling pointers" 
             (e.g., an enrollment record pointing to a deleted student). 
             Ensures the system state is valid.

       Module 10: Algorithmic Efficiency
           - void resize...Array()
             Implements dynamic memory management (manual heap allocation) 
             to handle data growth efficiently (O(n) resizing).
             
           - runBenchmarks()
             Simulates high-load operations to test the time complexity of 
             the DFS and sorting algorithms.

       Module 11: CLI Interaction
           - void showBigMenu() (in Main.cpp)
             Provides the text-based interface for user interaction.
             
           - CRUD Operations
             (addStudent, addCourse, addFaculty, addRoom). These functions 
             handle the input/output and memory storage for the base sets.

       Module 12: Unit Testing
           - Integrated Validation
             The system includes checks within addStudent (counter 
             incrementing) and error handling in generateCourseSchedule 
             (cycle detection) to serve as unit tests for data integrity