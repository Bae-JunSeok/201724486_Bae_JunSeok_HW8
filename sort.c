#include "phone.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void sort()
{
	printf("Sort function is called\n");
	printf("Before sorting-----\n");
	printArray(PhoneBook, size);
	sortPhoneBook(PhoneBook, size, contactCmpr, contactSwap);
	printf("After sorting-----\n");
	printArray(PhoneBook, size);	
}

void sortPhoneBook(void* PhoneBook, int size, cmp cfn, swap sfn)
{
	int i, j;
	for(i = 0; i < size - 1; i++){
		for(j = 0; j < size - i - 1; j++){
			if(cfn(PhoneBook, j, j+1) > 0)
				sfn(PhoneBook, j, j+1);
		}
	}
}

int contactCmpr(const void* PhoneBook, int i, int j)
{
	if(strcmp(((Contact*)PhoneBook + i)->Name, ((Contact*)PhoneBook + j)->Name) > 0)
		return 1;
	else
		return 0;
}

int contactSwap(void* PhoneBook, int i, int j)
{
	Contact temp;
	temp = *((Contact*)PhoneBook + i);
	*((Contact*)PhoneBook + i) = *((Contact*)PhoneBook + j);
	*((Contact*)PhoneBook + j) = temp;
	
	return 1;
}
