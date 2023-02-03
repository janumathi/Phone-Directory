#include <stdio.h>
#include <stdlib.h>
#include "add.h"
#include "search.h"
#include "display.h"
#include "delete.h"
#include "edit.h"
#include "favourites.h"

int main()
{

    int c;
    int exit=0;



    do{
        system("cls");
        FILE *fptr;
        fptr = fopen("FIRST PAGE.txt","r");
        char ch[100];
        printf("\n\n");
        while(fgets(ch,100,fptr)!=NULL)
        {
            printf("\t\t\t\t\t%s",ch);

        }
        fclose(fptr);
        printf("\n\n\t\t\t\t\tEnter your choice:");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
           add();
            break;
        case 2:
            delete();
            break;
        case 3:
            edit();
            break;
        case 4:
            search();
            getch();
            break;
        case 5:
           display();
            break;
        case 6:
            favourites();
            break;

        case 8:
            exit=1;
            break;

        default:
            printf("Enter a right choice..");
        }
    }while(exit==0);



	return 0;
}


