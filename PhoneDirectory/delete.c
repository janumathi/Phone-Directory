#include "delete.h"
#include "array.h"
#include "queue.h"
#include "file.h"
#include "stack.h"
#include "favourites.h"
#include <stdio.h>
#include <stdlib.h>

struct contact deleteNode(struct queue* q, struct node* n,struct stack* s);
void restore(struct stack* s,struct queue* q);

void delete()
{
    char fname[25];
    int ch;
    int exit=0;
    struct stack s;
    initializeStack(&s);

    struct queue q;
    initializeQueue(&q);
    readFromFile(&q);
    initializeArray(q);
    sortArray(q.size);

    do
    {
        freeArray();
        initializeArray(q);
        sortArray(q.size);
        system("cls");
        printf("\n\n");
        displayqueueandstack(s,q);
        printf("\n\n\t\t");
        printf("------"); printf("\n\t\t");
        printf("|MENU|"); printf("\n\t\t");
        printf("------"); printf("\n\t\t");
        printf("\n");
        printf("\npress 1 if you want to delete\n");
        printf("\npress 2 if you want to restore\n");
        printf("\npress 3 to leave as it is\n");
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        if(ch==1)
        {
        printf("Enter the contact name to be deleted: ");
        scanf("%s",fname);
        int index=binarySearch(fname,q.size);
        struct node* n=returnNode(index);

    if(n==NULL)
    {
        printf("Contact not found");
    }
    else
        {
        replaceinFavourites(n->data.fname," ");
        deleteNode(&q,n,&s);
        removeFile();
        writeFromQueue(q);
        }
    }
    else if(ch==2)
    {
        if(s.top==NULL)
            continue;
        addtoFavourites(s.top->n->data.fname);
        restore(&s,&q);
        removeFile();
        writeFromQueue(q);
    }
    else if(ch==3)
    {
     exit=1;
    }
}while(exit==0);

}


