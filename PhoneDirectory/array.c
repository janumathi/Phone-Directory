#include "array.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node** array;

void initializeArray(struct queue q3)
{

	struct node* n=q3.front;
	array=(struct node** )malloc(q3.size*sizeof(struct node*));
	for(int i=0;i<q3.size;i++)
	{
		array[i]=n;
		n=n->next;
	}

}

void displayArray(int size)
{

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
    printf("%-30s","address");
    printf("|");
    printf("\n");

    for(int i=0;i<125;i++)//this is for printing line
    {
       printf("-");
    }
    printf("\n");
	for(int i=0;i<size;i++)
	{
	    printf("\t\t|");
		displayContact(array[i]->data);
		printf("\n");
	}
	for(int i=0;i<125;i++)//this is for printing line
    {
       printf("-");
    }
    printf("\n");
}

void quickSort(struct node** array,int lb, int ub)
{
    int loc;
    if(lb<ub)
    {
        loc=partition(array,lb,ub);
        quickSort(array,lb,loc-1);
        quickSort(array,loc+1,ub);
    }
}

int partition(struct node** a,int lb, int ub)
{

    struct node* pivot=a[lb];
    int start=lb;
    int end=ub;
    while(start<end)
    {

        while(compareNode(a[start],pivot)==-1||compareNode(a[start],pivot)==0)
        {
            start++;
            if(start==end)
                break;

        }
        while(compareNode(a[end],pivot)==1)
        {
            end--;
        }
        if(start<end)
        {
            swap(&a[start],&a[end]);
        }
    }
        swap(&a[lb],&a[end]);
        return end;
}
void swap(struct node** a, struct node** b)
{
    struct node* temp=*a;
    *a=*b;
    *b=temp;
}

int compareName(char* a, char* b)
{

     int i = 0;
    while(a[i] != '\0' || b[i] != '\0')
    {
       if(a[i] < b[i])
       {
           return -1;
       }
       else if(a[i] > b[i])
       {
           return 1;
       }
       i++;
    }
    if(strlen(a) > i)
        return 1;
    else if(strlen(b) > i)
        return -1;
    else
        return 0;
}

int compareNode(struct node* a, struct node* b)
{
    char aname[25],bname[25];
    strcpy(aname,a->data.fname);
    strcpy(bname,b->data.fname);
    for(int i=0;i<strlen(aname);i++)
    {
        aname[i]=toupper(aname[i]);
    }
    for(int i=0;i<strlen(bname);i++)
    {
        bname[i]=toupper(bname[i]);
    }
    int r=compareName(aname,bname);

    return r;
}
void freeArray()
{
    free(array);
    array=NULL;
}

void sortArray(int size)
{

    quickSort(array,0,size-1);

}
void displayReverse(int size)
{

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
    printf("%-30s","address");
    printf("|");
    printf("\n");
    ;
    for(int i=0;i<125;i++)//this is for printing line
    {
       printf("-");
    }
    printf("\n");
    for(int i=size-1;i>=0;i--)
	{

		displayContact(array[i]->data);
		printf("\n");

	}
	for(int i=0;i<125;i++)//this is for printing line
    {
       printf("-");
    }
    printf("\n");
}
int compareNode2(struct node* a, char* b)
{
    char aname[25],bname[25];
    strcpy(aname,a->data.fname);
    strcpy(bname,b);
    for(int i=0;i<strlen(aname);i++)
    {
        aname[i]=toupper(aname[i]);
    }
    for(int i=0;i<strlen(bname);i++)
    {
        bname[i]=toupper(bname[i]);
    }
    int r=compareName(aname,bname);

    return r;
}

int binarySearch(char* searchStr,int n)
{

    int left=0,right=n-1,middle;
    while(left<=right)
    {
        middle=(left+right)/2;

    switch(compareNode2(array[middle],searchStr))
    {
        case -1:
                left=middle+1;
                break;
        case 0:
                return middle;
        case 1:
                right=(middle-1);
    }
    }
    return -1;
}
//this will return the node * at index i
struct node* returnNode(int i)
{
    if(i==-1)
    {
        return NULL;
    }
    return array[i];
}
