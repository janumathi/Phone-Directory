#ifndef QUEUE_H
#define QUEUE_H
#include "contact.h"

struct node{
	struct contact data;
	struct node* prev;
	struct node* next;
};

struct queue{
	struct node* front;
	struct node* rear;
	int size;
};


struct node* newNode(struct contact* data);
void initializeQueue(struct queue* q1);
void addAtRear(struct node* n, struct queue* q1);
void displayQueue(struct queue q);
void freeQueue(struct queue* q);



#endif // QUEUE_H
