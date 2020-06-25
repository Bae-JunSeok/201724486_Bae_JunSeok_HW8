#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phone.h"

void DeleteByName()
{
   char name_delete[20];
   printf(">>Enter a name to delete: ");
   scanf("%s", name_delete);
   Contact* curr = head;
   Contact* previous = curr;
   while(curr != NULL){
   	if(!strcmp(curr->Name, name_delete)){
   		previous->next = curr->next;
   		if(curr == head)
   			head = curr->next;
   		free(curr);
   		printf("%s is deleted...\n", name_delete);
   		break;
	   }
	previous = curr;
	curr = curr->next;
   }
   if(curr == NULL)
		printf("Oops! %s is not in the PhoneBook.\n", name_delete);
}
