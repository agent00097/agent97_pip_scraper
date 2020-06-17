#include <stdio.h>
#include <stdlib.h>
#include<zconf.h>

int main(int argc, char *argv)
{
    
        //First need to check if it was ran as root
        if (geteuid() != 0)
        {
            //App is not running as root
            printf("You know the drill, run the app as root. Goodbye.\n");
            exit(1);
        }
        else
        {
            printf("-----------------------------------------------------------\n");
            printf("-----------------------------------------------------------\n");
            printf("---------------------WELCOME AGENT97-----------------------\n");
            printf("----------------YOU KNOW WHAT TO DO NEXT-------------------\n");
            printf("-----------------------------------------------------------\n");
            printf("-----------------------------------------------------------\n");
            while(1) {
                //This is where the main menu option will be
                printf("-----------------------------------------------------------\n");
                printf("-----------------------------------------------------------\n");
                printf("------------------CHOOSE THE MENU OPTION-------------------\n");
                printf("1.PEOPLE HACK\n");
                printf("2.WEB APPLICATION HACK\n");
                printf("3.INSTALL ALL THE DEPENDANCIES\n");
                exit(0);
            }
        }
    
    return 0;
}