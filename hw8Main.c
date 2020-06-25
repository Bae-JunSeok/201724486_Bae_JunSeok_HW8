#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phone.h"


int main()
{
   printf("Loading information...\n");
   FILE* fp;
   fp = fopen("phone.dat", "rb");
   if(fp != NULL)
   {	
	 head = loadList(fp);
	 printAll();
	 fclose(fp);
   }
   int s;
   while (1) {
      printf("============ Telophone Book Management ============\n");
      printf("<<<1. Register\t2. Print All\t3. Search\t4. Delete\t5. Sort\t6. Exit>>>\n");
      printf("Please enter your service number (1-5)> ");
      scanf("%d", &s);
      switch (s)
      {
      case Register:
         registerPhoneData();
         break;
      case Print:
         printAll();
         break;
      case Search:
         searchByName();
         break;
      case Delete:
         DeleteByName();
         break;
      case Sort:
         sort();
         break;
      case Exit:
	 save_Information();
         return 0;
      		}
	}
}

Contact* loadList(FILE* fp)
{
	head = NULL; 
	Contact *p = NULL;
	
	while(1)
	{
		Contact* temp = (Contact*)malloc(sizeof(Contact));
		int isRead = fread((void*)temp, sizeof(Contact), 1, fp);
		
		if(!isRead)
			break;
		
		if(head == NULL){
			head = temp;
			p = temp;
			strcpy(PhoneBook[size].Name, temp->Name);
         	strcpy(PhoneBook[size].phoneNum, temp->phoneNum);
         	size++;
		}
		else
		{
			p->next = temp;
			p = p->next;
			strcpy(PhoneBook[size].Name, p->Name);
         	strcpy(PhoneBook[size].phoneNum, p->phoneNum);
         	size++;
		}
	}	
	p->next = NULL;
	
	tail = p;
	return head;
}

void save_Information()
{
	FILE* fp;
	fp = fopen("phone.dat", "wb");
	Contact* temp = head;
	while(temp != NULL){
		fwrite(temp, sizeof(Contact), 1, fp);
		temp = temp->next;
	}
	fclose(fp);
	printf("Information saved...\n");
}
