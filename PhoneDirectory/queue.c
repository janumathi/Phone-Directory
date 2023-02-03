#include "queue.h"
#include "file.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node* newNode(struct contact* data)
{
	struct node* n2=(struct node*) malloc(sizeof(struct node));
	if(n2==NULL)
	return NULL;

	initializeContact(&n2->data);
	if(data!=NULL)
	{
	copyContact(&n2->data,data);
	}
	n2->prev=NULL;
	n2->next=NULL;
	return n2;
}
void initializeQueue(struct queue* q1)
{
    q1->front=NULL;
    q1->rear=NULL;
    q1->size=0;
}

void addAtRear(struct node* n, struct queue* q1)
{
    if(n==NULL)
    {
        printf("Overflow");
        return;
    }
    else{
        if(q1->rear==NULL)
        {
            q1->front=q1->rear=n;
        }
        else{
            n->prev=q1->rear;
            q1->rear->next=n;
            q1->rear=n;
        }
       q1->size=q1->size+1;
    }

}
void displayQueue(struct queue q)
{

    if(q.front==NULL)
        return;
    for(int i=0;i<125;i++)//this is for printing line
    {
       printf("-");
    }
    printf("\n");

    printf("|");
    printf("%-25s","fname");
    printf("|");
    printf("%-25s","lname");
    printf("|");
    printf("%-11s","mob_no");
    printf("|");
    printf("   %-25s","email");
    printf("|");
    printf("%-30s","location");
    printf("|");
    printf("\n");

    for(int i=0;i<125;i++)//this is for printing line
    {
       printf("-");
    }
    printf("\n");
    for(struct node* i=q.front;i!=NULL;i=i->next)//this is for printing the records
    {

        displayContact(i->data);
        printf("\n");
    }

    for(int i=0;i<125;i++)//this is for printing lines
    {
       printf("-");
    }
    printf("\n");
}
void freeQueue(struct queue* q)
{
    struct node* dummy;
    for(struct node* i=q->front;i!=NULL;)
    {
        dummy=i;
        i=i->next;
        free(dummy);
    }
    q->front=q->rear=NULL;
    q->size=0;
}
struct contact deleteNode(struct queue* q, struct node* n,struct stack* s)
{
    struct contact a;
    initializeContact(&a);
    if(n==NULL)
    {
        printf("There is no contact");
    }
    else
        copyContact(&a,&n->data);
    if(q->front==q->rear)
    {
    push(s,n);
    q->front=q->rear=NULL;
    }
    else if(q->front==n)
    {
        q->front=q->front->next;
        push(s,n);
        q->front->prev=NULL;
    }
    else if(q->rear==n)
    {
        q->rear=q->rear->prev;
        push(s,n);
        q->rear->next=NULL;
    }
    else
    {
        n->next->prev=n->prev;
        n->prev->next=n->next;
        push(s,n);
    }
    q->size=q->size-1;
    return a;
}

void restore(struct stack* s,struct queue* q)
{
    struct node* n=pop(s);
    if(q->front==NULL)
    {
    q->front=q->rear=n;
    }
    else if(n->prev==NULL)
    {
        n->next->prev=n;
        q->front=n;
    }
    else if(n->next==NULL)
    {
        n->prev->next=n;
        q->rear=n;
    }
    else
    {
        n->prev->next=n;
        n->next->prev=n;
    }
    q->size=q->size+1;
}

