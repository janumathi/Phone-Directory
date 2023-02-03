#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initializeStack(struct stack* s)
{
    s->top=NULL;
}


void push(struct stack* s, struct node* n)
{
    struct nodeStack* s1=(struct nodeStack*) malloc(sizeof(struct nodeStack));
    s1->n=n;
    s1->next=NULL;
    if(s->top==NULL)
    {
        s->top=s1;
    }
    else{
        s1->next=s->top;
        s->top=s1;
    }

}

struct node* pop(struct stack* s)
{
    struct node* n;
    if(s->top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        struct nodeStack* s1=s->top;
        s->top=s->top->next;
        n=s1->n;
        free(s1);
    }
    return n;
}

void displayStack(struct stack s)
{
 for(struct nodeStack* i=s.top;i!=NULL;i=i->next)
 {
        displayContact(i->n->data);
        printf("\n");
}
}

void displayqueueandstack(struct stack s,struct queue q)
{
   struct node* i=q.front;
   struct nodeStack* j=s.top;
   printf("\n                queue               \t");
   printf("                stack               \t");
   printf("\n");
   while(1)//this is for printing the records
    {
       if(i!=NULL)
        {printf("%-25s",i->data.fname);
        printf("%-11s",i->data.mob_no);}
        else
        {
            for(int k=0;k<36;k++)
                printf(" ");
        }
        printf("\t");
        if(j!=NULL)
        {printf("%-25s",j->n->data.fname);
        printf("%-11s",j->n->data.mob_no);}
        printf("\n");
        if(i==NULL&&j==NULL)
            break;
        else if(i!=NULL&&j!=NULL)
        {
            i=i->next;
            j=j->next;
        }
        else if(i!=NULL)
            i=i->next;
        else if(j!=NULL)
            j=j->next;
    }
}
