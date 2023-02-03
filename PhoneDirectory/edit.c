#include "edit.h"
#include "array.h"
#include "queue.h"
#include "file.h"
#include "contact.h"
#include "favourites.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void changeContact(struct contact* data);
void edit()
{
    system("cls");
    char fname[25];
    struct queue q;
    initializeQueue(&q);
    readFromFile(&q);
    initializeArray(q);
    sortArray(q.size);
    printf("\nEnter the contact name to be searched: ");
    scanf("%s",fname);

    int index=binarySearch(fname,q.size);
    struct node* n=returnNode(index);
    if(n==NULL)
    {
        printf("Contact not found");
    }
    else
        {
        displayContact2(n->data);
        changeContact(&n->data);
        removeFile();
        writeFromQueue(q);
        }

}
void changeContact(struct contact* data)
{
    int ch;
        printf("\n\n");
        printf("\t--------------\n");
        printf("\t|   CHANGE   |\n");
        printf("\t--------------\n\n\n");
        printf("\n1) first name\n");
        printf("\n2) last name\n");
        printf("\n3) mobile number\n");
        printf("\n4) email-Id\n");
        printf("\n5) address\n");
        printf("\n6) Leave as it is");
        printf("\n\n\t\4 Enter your choice\n");
        scanf("%d",&ch);

     switch(ch)
     {
             case 1:
             {printf("\n Enter new first name:");
             char t[25];
             scanf("%s",t);
             replaceinFavourites(data->fname,t);
             strcpy(data->fname,t);
             }
             break;

             case 2:
             printf("\n Enter new last name:");
             scanf("%s",data->lname);
             break;

             case 3:
             printf("\n Enter new mobile number:");
             scanf("%s",data->mob_no);
             break;

             case 4:
             printf("\n Enter new email-Id:");
             scanf("%s",data->email);
             break;

             case 5:
             printf("\n Enter new address:");
             scanf("%s",data->address);
             break;


     }




}


