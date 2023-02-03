#include "favourites.h"
#include "queue.h"
#include "array.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void addtoFavourites(char s[]);
void displayFavourites();
int findinFavourites(char t[25]);
void favourites()
{
    int ch,exit=0;
    char fname[25];
    struct queue q;
    initializeQueue(&q);
    readFromFile(&q);
    initializeArray(q);
    sortArray(q.size);
    do
    {
        system("cls");
        printf("\n\n");
        printf("\n\n\t\t");
        printf("------------"); printf("\n\t\t");
        printf("|FAVOURITES|"); printf("\n\t\t");
        printf("------------"); printf("\n\t\t");
        displayFavourites();
        printf("\n\n\t");
        printf("------"); printf("\n\t");
        printf("|MENU|"); printf("\n\t");
        printf("------"); printf("\n\t");
        printf("\n");
        printf("\npress 1 if you want to add to favourites\n");
        printf("\npress 2 if you want to remove from favourites\n");
        printf("\npress 3 to view contact\n");
        printf("\npress 4 to leave as it is\n ");
        printf("\nEnter your choice:\n");
        scanf("%d",&ch);
        if(ch==1)
        {
    printf("Enter the contact name to be searched: \n");
    scanf("%s",fname);

    int index=binarySearch(fname,q.size);
    struct node* n=returnNode(index);
    if(n==NULL)
    {
        printf("Contact not found");
    }
    else
        {
         if(findinFavourites(n->data.fname)==0)
        {
        printf("\n");
        displayContact(n->data);
        addtoFavourites(n->data.fname);
        }
        else
            printf("\n It already exists");
        getch();

        }
        }
        else if(ch==2)
        {
            char s[25];
            printf("enter the name to be removed from favourites:");
            fflush(stdin);
            gets(s);
            if(findinFavourites(s)==0)
            {
                printf("the given name does not exist");
            }
            else
            {
                replaceinFavourites(s," ");
            }
        }
        else if(ch==3)
        {
            char s[25];
            printf("enter the name to be displayed from favourites:");
            fflush(stdin);
            gets(s);
            if(findinFavourites(s)==0)
            {
                printf("the given name does not exist");
            }
            else
            {
                int index=binarySearch(s,q.size);
                struct node* n=returnNode(index);
                printf("\n\n");
                displayContact2(n->data);
                getch();
            }
        }
        else if(ch==4)
        {
            exit=1;
        }
    }while(exit==0);
}

void addtoFavourites(char s[25])
{
  FILE * ptr;
  ptr=fopen("favourites.dat","a");
  fwrite(s,sizeof(char),25,ptr);
  fclose(ptr);
}

void displayFavourites()
{
    FILE* ptr;
    char s[25];

    ptr=fopen("favourites.dat","r");
    while(fread(&s,sizeof(s ),1,ptr))
    {

      printf("\n\t\t%s",s);
    }
    fclose(ptr);
}

int findinFavourites(char t[25])
{
    FILE* ptr;
    char s[25];

    ptr=fopen("favourites.dat","r");
    while(fread(&s,sizeof(s ),1,ptr))
    {

     if(strcmp(s,t)==0)
     {
       fclose(ptr);
       return 1;
     }
    }
    fclose(ptr);
    return 0;
}

void  removeFavourites()
{
    remove("favourites.dat");
}

void replaceinFavourites(char t1[25],char t2[25])
{
    FILE* ptr,*ptr2;
    char s[25];

    ptr=fopen("favourites.dat","r");
    ptr2=fopen("temp.dat","w");
    while(fread(&s,sizeof(s ),1,ptr))
    {

     if(strcmp(s,t1)==0)
     {
      if(strcmp(t2," ")==0)
      {
          continue;
      }
      else{
        fwrite(t2,sizeof(char),25,ptr2);
      }
     }
     else{
         fwrite(s,sizeof(char),25,ptr2);
     }
    }
    fclose(ptr);
    fclose(ptr2);
    removeFavourites();
    rename("temp.dat","favourites.dat");
}




