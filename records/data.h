#ifndef struct_student_
#define struct_student_

struct struct_student
{
    int gpa;
    float tuition_fees;
    int courses;
};
#endif

#ifndef struct_employee_
#define struct_employee_

struct struct_employee
{
    float salary;
    int years_service;
    int level;
};
#endif

#ifndef person_
#define person_

union Person {
    struct struct_student student;
    struct struct_employee employee;
};

struct person
{
    char first_name[15];
    char family_name[15];
    char telephone[10];
    int type; // 0: student, 1: employee
    union Person person;
};
#endif