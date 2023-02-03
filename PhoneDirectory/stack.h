#ifndef STACK_H
#define STACK_H
#include "queue.h"

struct nodeStack{
    struct node* n;
    struct nodeStack* next;
};

struct stack{
    struct nodeStack* top;
};

void initializeStack(struct stack* s);
void push(struct stack* s, struct node* n);
struct node* pop(struct stack* s);
void displayStack(struct stack s);
void displayqueueandstack(struct stack s,struct queue q);

#endif // STACK_H
