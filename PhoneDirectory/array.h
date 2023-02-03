#ifndef ARRAY_H
#define ARRAY_H
#include "queue.h"
void initializeArray(struct queue q3);
void displayArray(int size);
void displayReverse(int size);
void freeArray();
void quickSort(struct node** array,int lb, int ub);
int partition(struct node** a,int lb, int ub);
void swap(struct node** a, struct node** b);
int compareName(char* a, char* b);
int compareNode(struct node* a, struct node* b);
int compareNode2(struct node* a, char* b);
void sortArray(int size);
int binarySearch(char* searchStr,int n);
struct node* returnNode(int i);

#endif // ARRAY_H
