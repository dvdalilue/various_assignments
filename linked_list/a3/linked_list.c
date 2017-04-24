
/* 
File name is linked_list.c

*/

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// Define 



/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
id - id of person
firstName - first name of person
familyName - family name of person

input/output
head - head of linked list

return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName)
{
	// add code
    PersonalInfo *aux = (PersonalInfo*) malloc(sizeof(PersonalInfo));

    aux->next = (*head);
    aux->id = id;
    strcpy(aux->firstName, firstName);
    strcpy(aux->familyName, familyName);

    (*head) = aux;

    return aux; 
}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
node - the node after which the new node must be added to the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName)
{
	// add code 

    PersonalInfo *aux = (PersonalInfo*) malloc(sizeof(PersonalInfo));

    aux->next = node->next;
    aux->id = id;
    strcpy(aux->firstName, firstName);
    strcpy(aux->familyName, familyName);

    node->next = aux;

    return aux;
}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/


PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName)
{
	// add code
    PersonalInfo *aux = (PersonalInfo*) malloc(sizeof(PersonalInfo));

    aux->next = NULL;
    aux->id = id;
    strcpy(aux->firstName, firstName);
    strcpy(aux->familyName, familyName);

    PersonalInfo *tmp = (*head);

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }

    tmp->next = aux;
}


/************************************************************************/
/*
Purpose: search for the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


PersonalInfo *searchByName(PersonalInfo *head, char *firstName)
{
	// add code 
    while (head != NULL) {
        if (strcmp(head->firstName, firstName) == 0) {
            return head;
        }
        head = head->next;
    }

    return NULL;
}

/************************************************************************/
/*
Purpose: search for the first node with the matching id
Input
head - the head of the list
id - id of person person

return
a pointer to the node that was allocated.  

NULL - if no node was found or list empty 

*/


PersonalInfo *searchById(PersonalInfo *head, unsigned int id)
{
	// add code 
    while (head != NULL) {
        if (head->id == id) {
            return head;
        }
        head = head->next;
    }
    
    return NULL;
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted
1 if node was not deleted or list is empty

*/


int deleteFromList(PersonalInfo **head, unsigned int *id,
	char *firstName, char *familyName)

{
    // add code
    PersonalInfo *tmp = (*head);
    if (tmp == NULL)
        return 1;

    (*id) = tmp->id;
    strcpy(firstName, tmp->firstName);
    strcpy(familyName, tmp->familyName);

    (*head) = (*head)->next;

    free(tmp);

    return 0;
}


/***************************************************************/

/*
Purpose: delete the last node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted  
1 if node was not deleted or list is empty 

*/


int deleteLast(PersonalInfo **head, unsigned int *id,
                char *firstName, char *familyName)

{

    // add code
    if ((*head) == NULL)
        return 1;

    PersonalInfo *prev = NULL;
    PersonalInfo *tmp = (*head);

    while (tmp->next != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }

    (*id) = tmp->id;
    strcpy(firstName, tmp->firstName);
    strcpy(familyName, tmp->familyName);

    free(tmp);

    if (prev == NULL) {
        (*head) = NULL;
        return 0;
    }

    prev->next = NULL;

    return 0;
}



/************************************************************************/

/*
Purpose: delete the record after the given node 
Input
node - a node in the list

output
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0 if node was deleted 
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/



int deleteAfter(PersonalInfo *node, unsigned int *id,
                char *firstName, char *familyName)

{
    // add code
    PersonalInfo *tmp = NULL;

    if ((node == NULL) || (node->next == NULL))
        return 1;

    (*id) = node->next->id;
    strcpy(firstName, node->next->firstName);
    strcpy(familyName, node->next->familyName);

    tmp = node->next;
    node->next = node->next->next;
    free(tmp);
    return 0;
}

/************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonalInfo **head, char *firstName,
	char *familyName, unsigned int *id)
{
	// add code

    PersonalInfo *prev = NULL;
    PersonalInfo *tmp = (*head);

    while (tmp != NULL) {
        if (strcmp(tmp->firstName, firstName) == 0) {
            (*id) = tmp->id;
            strcpy(familyName, tmp->familyName);
            break;
        }
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == NULL)
        return 1;

    if (prev == NULL) {
        (*head) = tmp->next;
    } else {
        prev->next = tmp->next;
    }

    free(tmp);
    return 0;

}
/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(PersonalInfo **head)
{
	// add code 

    PersonalInfo *prev = NULL;
    PersonalInfo *tmp = (*head);

    while (tmp != NULL) {
        prev = tmp;
        tmp = tmp->next;
        free(prev);
    }
}



/************************************************************************/
/*
Purpose: prints the fields of a node
input:
node - a pointer to a given node

*/


void printNode(PersonalInfo *node)
{
	printf("%-20s %-20s %7d \n",node->firstName, node->familyName, node->id);

}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head)
{
	// add code 

    while (head != NULL) {
        printNode(head);
        head = head->next;
    }

}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


int listSize(PersonalInfo *head)
{
	// add code 

    int size = 0;

    while (head != NULL) {
        size++;
        head = head->next;
    }

    return size;
}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list with a matching firstName
input
head - the head of the list

return 
the number of nodes in the list that match the firstName


*/


int countRecords(PersonalInfo *head, char *firstName)
{
	// add code

    int counter = 0;

    while (head != NULL) {
        if (strcmp(head->firstName, firstName) == 0) {
            counter++;
        }
        head = head->next;
    }

    return counter;
}




/************************************************************************/
/*

Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name. 
You can assume that the listed is sorted by first name.

input
head - the head of the  list



*/




void removeDuplicates(PersonalInfo *head)
{
	// add code 

    PersonalInfo *prev = head;

    head = head->next;

    while (head != NULL) {
        if (strcmp(head->firstName, prev->firstName) == 0) {
            prev->next = head->next;
            free(head);
        }
        prev = prev->next;
        head = prev->next;
    }

}

