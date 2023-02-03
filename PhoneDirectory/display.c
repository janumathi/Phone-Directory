#include "display.h"
#include "queue.h"
#include "file.h"
#include "array.h"
#include <stdio.h>
#include <stdlib.h>

void display()
{
    struct queue q;
    initializeQueue(&q);
    readFromFile(&q);
    initializeArray(q);
    sortArray(q.size);
    char c='r';
    while(c!='0')
    {

        if(c=='r')
        {
            system("cls");
            printf("\nOriginal order:\n");
            displayQueue(q);
        }

        else if(c=='a')
        {
            system("cls");
            printf("\nAscending order:\n");
             displayArray(q.size);
        }
        else if(c=='d')
        {
            system("cls");
            printf("\nDescending order:\n");
            displayReverse(q.size);
        }
           c=getch();
    }

    freeQueue(&q);
    freeArray();

}
