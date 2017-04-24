
/* 
File name is linked_list.h

*/


#ifndef LINKED_LIST_2401
#define LINKED_LIST_2401 1

#define NAME_LENGTH 32

typedef struct personalInfo {
	struct personalInfo *next;
	unsigned int id;		
	char firstName[NAME_LENGTH];
	char familyName[NAME_LENGTH];
} PersonalInfo;

// Part 
// Insert Functions 
PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName);

PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, 
        char *firstName, char *familyName);

PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName);


// Search Functions

PersonalInfo *searchByName(PersonalInfo *head, char *firstName);

PersonalInfo *searchById(PersonalInfo *head, unsigned int id);


// Delete Functions
int deleteFromList(PersonalInfo **head, unsigned int *id, 
        char *firstName, char *familyName);

int deleteLast(PersonalInfo **head, unsigned int *id,
	char *firstName, char *familyName);

int deleteAfter(PersonalInfo *node, unsigned int *id,
        char *firstName, char *familyName);

int deleteNodeByName(PersonalInfo **head, char *firstName,
	char *lastName, unsigned int *id);

void deleteList(PersonalInfo **head);


// Print Functions
void printNode(PersonalInfo *node);

void printList(PersonalInfo *head);

// Counting Functions
int listSize(PersonalInfo *head);

int countRecords(PersonalInfo *head, char *firstName);

// Miscellaneous Functions

void removeDuplicates(PersonalInfo *head);

// Bonus

void mergeLists(PersonalInfo **head1, PersonalInfo **head2, 
        PersonalInfo **outHead);


#endif
