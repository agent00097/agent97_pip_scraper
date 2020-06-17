#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/wait.h>
#include <fcntl.h>
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
        char* i_scraper_pip[50] = {"/usr/bin/pip3", "install", "instagram-scraper", NULL};
        execute_function(i_scraper_pip, "/usr/bin/pip3");
    }
}

int directory_exists(char *name) {
    struct stat s;
    int err = stat(name, &s);
    if(err == -1) {
        if(ENOENT == errno) {
            //Directory doesnt exist
            return -1;
        }
        else {
            perror("stat");
            exit(1);
        }
    }
    else {
        //Directory Exists
        return 1;
    }
}

void install_all_dependancies() {
    
}

void run_system_commands_redir(char **path, char *filename, char *path_copy) {
    int rc = fork();
    if (rc < 0) {
        write(STDERR_FILENO, error_message, strlen(error_message));
    }
    else if (rc == 0) {
        close(STDOUT_FILENO);
        open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRWXU);
        if(execv(path_copy, path)) {
            write(STDERR_FILENO, error_message, strlen(error_message));
        }
    }
    else {
        int rc_wait = wait(NULL);
    }
}

void execute_function(char **path, char *path_copy)
{
    int child;
    child = fork();
    if (child < 0)
    {
        write(STDERR_FILENO, error_message, strlen(error_message));
    }
    else if (child == 0)
    {
        if (execv(path_copy, path))
        {
            write(STDERR_FILENO, error_message, strlen(error_message));
        }
        exit(1);
    }
    else
    {
        int rc_wait = wait(NULL);
    }
}
