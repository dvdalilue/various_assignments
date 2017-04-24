#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

#ifndef _check_telephone_
#define _check_telephone_

int check_telephone(char *telephone)
{
    int i = 0;

    while (i < 10)
    {
        if (telephone[i] == '\n')
        {
            break;
        }
        else if ((telephone[i] < 48) || (telephone[i] > 57))
        {
            return 0;
        }
        i += 1;
    }

    if ((i != 0) && ((telephone[0] == 48) || (telephone[0] == 49)))
    {
        return 0;
    }

    return 1;
}

#endif

int check_gpa(char *string)
{
    int i = 0;

    while (i < 3)
    {
        if ((string[i] == '\n') || (string[i] == '\0'))
            break;

        if ((string[i] < 48) || (string[i] > 54))
        {
            return 0;
        }
        i += 1;
    }

    if ((atoi(string) > 10) || i == 0)
        return 0;

    return 1;
}

int check_fees(char *string)
{
    int i = 0;
    int dots = 0;

    while (i < 15)
    {
        if ((string[i] == '\n') || (string[i] == '\0'))
            break;

        if (string[i] == '.')
        {
            dots++;
            if (dots > 1)
            {
                return 0;
            }
        }
        else if ((string[i] < 48) || (string[i] > 54))
        {
            return 0;
        }
        i += 1;
    }

    if (i == 0)
        return 0;

    return 1;
}

int check_courses(char *string)
{
    int i = 0;

    while (i < 3)
    {
        if ((string[i] == '\n') || (string[i] == '\0'))
            break;

        if ((string[i] < 48) || (string[i] > 54))
        {
            return 0;
        }
        i += 1;
    }

    if ((atoi(string) > 40) || i == 0)
        return 0;

    return 1;
}

#ifndef _remove_linebreak_
#define _remove_linebreak_

void remove_linebreak(char *string)
{
    int i = 0;

    while (string[i] != '\0')
    {
        if (string[i] == '\n')
        {
            string[i] = '\0';
        }
        i++;
    }
}

#endif

int add_new_student(struct person *records, int n)
{
    int read_checker;
    int n_bytes = 15;
    char *read_string = NULL;

    struct person new_person;

    printf("\n- First name: ");
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }

    remove_linebreak(read_string);
    strcat(read_string, " ");
    strcpy(new_person.first_name, read_string);
    read_string = NULL;

    printf("- Family name: ");
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }

    remove_linebreak(read_string);
    strcpy(new_person.family_name, read_string);
    read_string = NULL;

    n_bytes = 15;
    printf("- Telephone: ");
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }

    if (check_telephone(read_string))
    {
        remove_linebreak(read_string);
        strcpy(new_person.telephone, read_string);
        read_string = NULL;
        records[n] = new_person;
    }
    else
    {
        puts("\n**************************");
        puts("**** Bad phone number ****");
        puts("**************************\n");
        return 1;
    }

    n_bytes = 3;
    printf("- GPA: ");
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }

    if (check_gpa(read_string))
    {
        new_person.person.student.gpa = atoi(read_string);
        read_string = NULL;
        records[n] = new_person;
    }
    else
    {
        puts("\n**************************");
        puts("**** GPA out of range ****");
        puts("**************************\n");
        return 1;
    }

    n_bytes = 15;
    printf("- Tuition fees: ");
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }

    if (check_fees(read_string))
    {
        new_person.person.student.tuition_fees = atof(read_string);
        read_string = NULL;
        records[n] = new_person;
    }
    else
    {
        puts("\n**********************");
        puts("**** Invalid fees ****");
        puts("**********************\n");
        return 1;
    }

    n_bytes = 3;
    printf("- Number of courses: ");
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }

    if (check_courses(read_string))
    {
        new_person.person.student.courses = atoi(read_string);
        read_string = NULL;
        records[n] = new_person;
    }
    else
    {
        puts("\n******************************");
        puts("**** Courses out of range ****");
        puts("******************************\n");
        return 1;
    }

    return 0;
}

void print_student(struct person *records, int p)
{
    char aux[15];
    strcpy(aux, records[p].first_name);
    strcat(aux, records[p].family_name);
    puts("");
    printf("%-33s, Tel: %10s, GPA: %2i, Courses: %2i, Tuition: %4.2f\n", aux, records[p].telephone, records[p].person.student.gpa, records[p].person.student.courses, records[p].person.student.tuition_fees);    
    puts("");
}

void print_all_students(struct person *records, int n)
{
    int i = 0;

    while (i < n) {
        if (records[i].type == 0)
        {   
            print_student(records,i);
        }
        i += 1;
    }
}

void search_student_by_familyname(struct person *records, int n)
{
    int i = 0;
    int read_checker;
    int n_bytes = 15;
    char *family_search = NULL;
    char *aux = "";

    printf("- Search for family name: ");
    read_checker = getline(&family_search, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }

    remove_linebreak(family_search);

    while (i < n) {
        if ((records[i].type == 0) && (!strcmp(records[i].family_name, family_search)))
            print_student(records,i);
        i += 1;
    }
}