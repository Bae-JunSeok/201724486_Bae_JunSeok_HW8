#include "phone.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void searchByName()
{
   Contact* curr = head;
   char name_search[20];
   printf(">>Enter a name to search: ");
   scanf("%s", name_search);
   while (curr != NULL) {
      if (strcmp(curr->Name, name_search) == 0)
         break;
      else
         curr = curr->next;
   }
   if (curr != NULL)
      printf("%s\t\t%s\n", curr->Name, curr->phoneNum);
   else
      printf("Oops! %s is not in the PhoneBook.\n", name_search);
   return;
}
