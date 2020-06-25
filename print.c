#include "phone.h"
#include <stdio.h>


void printAll()
{
   printf("Print all contants int the PhoneBook\n");
   printArray(PhoneBook, size);
}

void printArray(void* PhoneBook, int size)
{
	int i;
	void* vp;
	vp = PhoneBook;
	for(i = 0; i < size; i++)
	{
		printf("name : %s\tphone : %s\n", ((Contact*)vp + i)->Name, ((Contact*)vp + i)->phoneNum);
	}
	printf("\n");
}
