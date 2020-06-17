//These are the function declarations
void exit_gracefully();
void people_hack_menu();
void instagram_menu();
int directory_exists(char *name);
void install_all_dependancies();
void execute_function(char **path, char *path_copy);
void run_system_commands_redir(char **path, char *filename, char *path_copy);


//The Constants in the program
char error_message[50] = "An error has occurred with system commands\n";