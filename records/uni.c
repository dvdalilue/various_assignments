#include <stdio.h>
#include <stdlib.h>
#include "student.h"
#include "employee.h"

void summary(struct person *records, int n)
{
    int n_s = 0,
        n_e = 0;

    float gpa = 0.0,
          courses = 0.0,
          fees = 0.0;

    int min_level = 0,
        max_level = 16;

    float age = 0.0,
          salary = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (records[i].type == 0)
        {
            gpa += records[i].person.student.gpa;
            courses += records[i].person.student.courses;
            fees += records[i].person.student.tuition_fees;
            n_s++;
        }
        else
        {
            age += records[i].person.employee.years_service;
            salary += records[i].person.employee.salary;
            if (records[i].person.employee.level < min_level) 
                min_level = records[i].person.employee.level;
            if (records[i].person.employee.level > max_level)
                max_level = records[i].person.employee.level;
            n_e++;
        }
    }

    gpa = gpa / (float) n_s;
    courses = courses / (float) n_s;
    fees = fees / (float) n_s;

    age = age / (float) n_e;
    salary = salary / (float) n_e;

    printf("Total number of records: %i\n", n);
    puts("Students Stats:");
    printf("Number of students: %i\n", n_s);
    printf("Average GPA: %.2f, Average number of courses: %.2f, Average tuition fees: %.2f\n", gpa, courses, fees);

    puts("Employees Stats:");
    printf("Number of employees: %i\n", n_e);
    printf("Number of employees: %i, Min level: %i, Max level: %i\n", n_e, min_level, max_level);
    printf("Average age: %.2f, Average salary: %.2f\n", age, salary);
}

int menu()
{
    int read_checker;
    int n_bytes = 2;
    char *read_string = NULL;
    
    puts("---- Menu ----");
    puts("1. Add a new employee");
    puts("2. Add a new student");
    puts("3. Print all employees");
    puts("4. Print all students");
    puts("5. Search students using Family Name");
    puts("6. Summary of Data");
    puts("0. Quit");
    printf("\n---- Your choice: ");
    
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);
    
    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }
    else if ((read_string[0] < 48) ||
             (read_string[0] > 54) ||
             (read_string[1] != '\n'))
    {
        puts("\n************************");
        puts("**** Invalid option ****");
        puts("************************\n");
        return -1;
    }

    return atoi(read_string);
}

int main(int argc, char const *argv[])
{
    int option;
    int valid = 1;
    int n_records = 0;
    struct person records[20];

    while (1) {
        option = -1;
        while (option == -1) {
            option = menu();
        }

        switch (option) {
            case 0:
                exit(0);
            case 1:
                if (n_records > 19) {
                    puts("\n*********************************");
                    puts("**** Maximun records reached ****");
                    puts("*********************************\n");
                    break;
                }
                while (valid) {
                    valid = add_new_employee(records, n_records);
                }
                valid = 1;
                records[n_records].type = 1;
                n_records += 1;
                break;
            case 2:
                if (n_records > 19) {
                    puts("\n*********************************");
                    puts("**** Maximun records reached ****");
                    puts("*********************************\n");
                    break;
                }
                while (valid) {
                    valid = add_new_student(records, n_records);
                }
                valid = 1;
                records[n_records].type = 0;
                n_records += 1;
                break;
            case 3:
                print_all_employees(records,n_records);
                break;
            case 4:
                print_all_students(records,n_records);
                break;
            case 5:
                search_student_by_familyname(records,n_records);
                break;
            case 6:
                summary(records, n_records);
                break;
            default:
                continue;
        }      
    }
    return 0;
}