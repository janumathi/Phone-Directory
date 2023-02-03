#include "search.h"
#include "array.h"
#include "queue.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>

void search()
{
    char fname[25];
    struct queue q;
    initializeQueue(&q);
    readFromFile(&q);
    initializeArray(q);
    sortArray(q.size);
    printf("Enter the contact name to be searched: ");
    scanf("%s",fname);

    int index=binarySearch(fname,q.size);
    struct node* n=returnNode(index);
    if(n==NULL)
    {
        printf("Contact not found");
    }
    else
        {
        displayContact(n->data);
        }
}
