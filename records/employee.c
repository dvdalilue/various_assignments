#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

#ifndef check_telephone_
#define check_telephone_

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

int check_years(char *string)
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

    if ((atoi(string) > 63) || i == 0)
        return 0;

    return 1;
}

int check_salary(char *string)
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

int check_level(char *string)
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

    if ((atoi(string) > 15) || (atoi(string) < 1) || i == 0)
        return 0;

    return 1;
}

void remove_employee_linebreak(char *string)
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

int add_new_employee(struct person *records, int n)
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

    remove_employee_linebreak(read_string);
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

    remove_employee_linebreak(read_string);
    strcpy(new_person.family_name, read_string);

    n_bytes = 10;
    printf("- Telephone: ");
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }
    if (check_telephone(read_string))
    {
        remove_employee_linebreak(read_string);
        strcpy(new_person.telephone, read_string);
        records[n] = new_person;
    }
    else
    {
        puts("\n**************************");
        puts("**** Bad phone number ****");
        puts("**************************\n");
        return 1;
    }

    n_bytes = 15;
    printf("- Salary: ");
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }

    if (check_salary(read_string))
    {
        new_person.person.employee.salary = atof(read_string);
        records[n] = new_person;
    }
    else
    {
        puts("\n************************");
        puts("**** Invalid salary ****");
        puts("************************\n");
        return 1;
    }

    n_bytes = 3;
    printf("- Years of service: ");
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }

    if (check_years(read_string))
    {
        new_person.person.employee.years_service = atoi(read_string);
        records[n] = new_person;
    }
    else
    {
        puts("\n**********************************");
        puts("**** Invalid years of service ****");
        puts("**********************************\n");
        return 1;
    }

    n_bytes = 3;
    printf("- Level: ");
    read_checker = getline(&read_string, (size_t *) &n_bytes, stdin);

    if (read_checker == -1)
    {
        puts("ERROR!");
        exit(1);
    }

    if (check_level(read_string))
    {
        new_person.person.employee.level = atoi(read_string);
        records[n] = new_person;
    }
    else
    {
        puts("\n***********************");
        puts("**** Invalid level ****");
        puts("***********************\n");
        return 1;
    }

    return 0;
}

void print_employee(struct person *records, int p)
{
    char aux[15];
    strcpy(aux, records[p].first_name);
    strcat(aux, records[p].family_name);
    puts("");
    printf("%-33s, Tel: %10s, Age: %2i, Level: %2i, Salary: %6.2f\n", aux, records[p].telephone, records[p].person.employee.years_service, records[p].person.employee.level, records[p].person.employee.salary);    
    puts("");
}

void print_all_employees(struct person *records, int n)
{
    int i = 0;

    while (i < n) {
        if (records[i].type == 1)
            print_employee(records,i);
        i += 1;
    }
}