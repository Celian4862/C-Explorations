#ifndef STUDENT_H
#define STUDENT_H

typedef char String[20];

typedef struct{
    String fname, lname;
} Name;

typedef struct {
    int studID;
    Name studName;
    bool sex; // true - male; false - female
    String program;
    int year;
} Student;

Name createName(String, String);
Student createStudent(int, Name, bool, String, int);
void displayStudent(Student);

Name createName(String fname, String lname) {
    Name n;
    strcpy(n.fname, fname);
    strcpy(n.lname, lname);
    return n;
}

Student createStudent(int studID, Name studName, bool sex, String program, int year) {
    Student s;
    s.studID = studID;
    s.studName = studName;
    s.sex = sex;
    strcpy(s.program, program);
    s.year = year;
    return s;
}

void displayStudent(Student s) {
    printf("%d | %s, %s | %c | %s | %d\n", s.studID, s.studName.lname, s.studName.fname, (s.sex) ? 'M' : 'F', s.program, s.year);
}

#endif