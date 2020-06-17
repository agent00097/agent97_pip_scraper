#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "main_header.h"

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
        printf("-----------------------------------------------------------\n\n\n\n");
        while (1)
        {
            //This is where the main menu option will be
            printf("-----------------------------------------------------------\n");
            printf("-----------------------------------------------------------\n");
            printf("------------------CHOOSE THE MENU OPTION-------------------\n");
            printf("1.PEOPLE HACK\n");
            printf("2.WEB APPLICATION HACK\n");
            printf("3.INSTALL ALL THE DEPENDANCIES\n");
            printf("4.EXIT\n\n\n\n");

            int choice = 5;
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                people_hack_menu();
                break;
            case 2:
                printf("Web Application Hacking\n");
                break;
            case 3:
                printf("Install all dependancies\n");
                break;
            case 4:
                exit_gracefully();
                break;
            default:
                printf("Choose the right option please\n");
                break;
            }

            exit(0);
        }
    }

    return 0;
}

void exit_gracefully()
{
    printf("See you next time man, Goodbye.\n");
    exit(0);
}

void people_hack_menu()
{
    while (1)
    {
        printf("-----------------------------------------------------------\n");
        printf("-----------------------------------------------------------\n");
        printf("------------------CHOOSE THE MENU OPTION-------------------\n\n\n\n");
        printf("1.INSTAGRAM SEARCH\n");
        printf("2.FACEBOOK SEARCH\n");
        printf("3.TWITTER SEARCH\n");
        printf("4.EXIT\n");

        int choice2 = 5;
        scanf("%d", &choice2);

        switch (choice2)
        {
        case 1:
            instagram_menu();
            break;
        case 2:
            printf("FACEBOOK MENU\n");
            break;
        case 3:
            printf("TWITTER MENU\n");
            break;
        case 4:
            exit_gracefully();
            break;
        default:
            printf("Choose the right option please\n");
            break;
        }
    }
}

void instagram_menu()
{
    //This is the function start of the instagram
    //First we need to see if instagram-scraper is installed or not
    if(directory_exists("/usr/local/bin/instagram-scraper") == 1) {
        //Ok so instagram-scraper is installed now we need to run it.
        //First ask whether to run in ghost mode or not
        printf("-----------------------------------------------------------\n");
        printf("-----------------------------------------------------------\n");
        printf("------------------CHOOSE THE MENU OPTION-------------------\n\n\n\n");
        printf("1.GHOST MODE\n");
        printf("2.FACEBOOK SEARCH\n");
        printf("3.PREVIOUS MENU\n");
        printf("4.EXIT\n\n\n\n");

        int instagram_option = 5;
        scanf("%d", &instagram_option);

        switch (instagram_option)
        {
        case 1:
            printf("INSTAGRAM MENU\n");
            break;
        case 2:
            printf("FACEBOOK MENU\n");
            break;
        case 3:
            printf("TWITTER MENU\n");
            break;
        case 4:
            exit_gracefully();
            break;
        default:
            printf("Choose the right option please\n");
            break;
        }
    }
    else {
        //I need to install instagram-scraper first
    }
}

int directory_exists(char *name) {
    struct stat s;
    int err = stat(name, &s);
    if(err == -1) {
        if(ENOENT == errno) {
            //Directory doesnt exist prompt me to use the install tor command
            return -1;
        }
        else {
            perror("stat");
            exit(1);
        }
    }
    else {
        return 1;
    }
}