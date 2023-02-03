#include "add.h"
#include "queue.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include<string.h>


void add()
{
    system("cls");
    struct contact* c;
    struct node* n;
    struct queue q4;
    initializeQueue(&q4);
    printf("\t\t\t\t----------------------\n");
    printf("\t\t\t\t|  ADD TO PHONEBOOK  |\n");
    printf("\t\t\t\t----------------------\n");
    printf("\n\n\n");
    c=newContact();
    n=newNode(c);
    free(c);
    addAtRear(n,&q4);
    writeFromQueue(q4);
    freeQueue(&q4);
    readFromFile(&q4);
    printf("\n\n");
    displayQueue(q4);
    getch();
}
