typedef char String[20];

typedef struct {
    int studID;
    String studName;
    String program;
    int year;
} Student;

Student createStudent(int studID, String studName, String program, int year);
void displayStudent(Student s);