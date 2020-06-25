#ifndef __PHONE_H__
#define __PHONE_H__
#include <stdio.h>
#include <stdlib.h>
enum select { Register = 1, Print, Search, Delete, Sort, Exit };

typedef struct TelephoneBook
{
   char Name[20];
   char phoneNum[20];
   struct TelephoneBook *next;
}Contact;

Contact PhoneBook[50];
int size;


Contact* head;
Contact* tail;

typedef int (*cmp)(const void*, int, int);
typedef int (*swap)(void*, int, int);

void sortPhoneBook(void*, int, cmp, swap);

int contactCmpr(const void*, int, int);
int contactSwap(void*, int, int);


void registerPhoneData();
void printAll();
void printArray(void*, int);
void searchByName();
void DeleteByName();
void sort();
void save_Information();
Contact* loadList(FILE*);
void deleteStruct(char*);

#endif
