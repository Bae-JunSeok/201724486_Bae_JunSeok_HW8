#include "phone.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void registerPhoneData()
{
   char pw[] = "1234";
   char pw_input[10];
   int pw_count = 1;
   char name[20];
   char phone[20];
   while (1) {
      printf("Password:\n");
      scanf("%s", pw_input);
      if (!(strcmp(pw, pw_input)))
      {
         printf("New User Name: ");
         scanf("%s", name);
         printf("PhoneNumber: ");
         scanf("%s", phone);
         Contact *a = (Contact*)malloc(sizeof(Contact));
         strcpy(a->Name, name);
         strcpy(a->phoneNum, phone);
	 strcpy(PhoneBook[size].Name, a->Name);
         strcpy(PhoneBook[size].phoneNum, a->phoneNum);
         size ++;
         printf("Registered...\n");

         a->next = NULL;
         if (head == NULL) {
            head = a;
            tail = a;
         }
         else {
            tail->next = a;
            tail = a;
         }
         return;
      }
      else
      {
         if (pw_count == 1) {
            printf(">>Not Matched!!!\n");
            pw_count++;
         }
         else if (pw_count == 2) {
            printf(">>Not Matched!!!(twice)\n");
            pw_count++;
         }
         else if (pw_count == 3) {
            printf(">>Not Matched!!!(3 times)\n");
            pw_count++;
         }
         else {
            printf("You are not allowed to access PhoneBook.\n");
            break;
         }
      }
   }
   return;
}
