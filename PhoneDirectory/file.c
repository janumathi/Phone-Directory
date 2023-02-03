#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void readFromFile(struct queue* q1)
{
    FILE* ptr;
    struct node* n;
    struct contact data;
    ptr=fopen("contact.dat","r");
    while(fread(&data,sizeof(struct contact),1,ptr))
    {
       n=newNode(&data);
       addAtRear(n,q1);
    }
    fclose(ptr);
}


void writeInFile(struct contact data)
{
    FILE* ptr;
    ptr=fopen("contact.dat","a");
    fwrite(&data,sizeof(data),1,ptr);
    fclose(ptr);

}

void writeFromQueue(struct queue q)
{
     for(struct node* i=q.front;i!=NULL;i=i->next)
    {
        writeInFile(i->data);
    }

}

void removeFile()
{
    remove("contact.dat");
}
