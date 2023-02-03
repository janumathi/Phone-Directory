#include "contact.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact* newContact()
{
        struct contact* n1= (struct contact*) malloc (sizeof(struct contact));
        printf("\n");
		printf("\t\t\t\3 Enter first name:");
		scanf("%s",n1->fname);
		printf("\n");
		printf("\t\t\t\4 Enter last name:");
		scanf("%s",n1->lname);
		printf("\n");
		printf("\t\t\t\2 Enter mobile number:");
		scanf("%s",n1->mob_no);
		printf("\n");
		printf("\t\t\t\1 Enter email:");
		scanf("%s",n1->email);
		printf("\n");
		printf("\t\t\t\5 Enter location:");
		scanf("%s",n1->address);


	return n1;
}

void copyContact(struct contact* d1, struct contact* d2)
{
	strcpy(d1->fname,d2->fname);
	strcpy(d1->lname,d2->lname);
	strcpy(d1->mob_no,d2->mob_no);
	strcpy(d1->email,d2->email);
	strcpy(d1->address,d2->address);
}

void initializeContact(struct contact* data)
{

	strcpy(data->fname," ");
	strcpy(data->lname," ");
	strcpy(data->mob_no," ");
	strcpy(data->email," ");
	strcpy(data->address," ");
}

void displayContact(struct contact a)
{
    printf("|");
    printf("%-25s",a.fname);
    printf("|");
    printf("%-25s",a.lname);
    printf("|");
    printf("%-11s",a.mob_no);
    printf("|");
    printf("   %-25s",a.email);
    printf("|");
    printf("%-30s",a.address);
    printf("|");
}
void displayContact2(struct contact a)
{
    printf("\n\n");
    printf("%-15s :%15s","first name",a.fname);
    printf("\n\n");
    printf("%-15s :%15s","last name",a.lname);
    printf("\n\n");
    printf("%-15s :%15s","mobile number ",a.mob_no);
    printf("\n\n");
    printf("%-15s :%15s","Email-Id ",a.email);
    printf("\n\n");
    printf("%-15s :%15s","location ",a.address);
    printf("\n\n");
}
