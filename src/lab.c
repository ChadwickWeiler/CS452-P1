#include "lab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *default_prompt = "shell>";

char *get_prompt(const char *env){

    char *environment =  getenv(env);
    //setting a temporary variable to change to the env provided.
    char *prompt = NULL;
        if(!environment){
            prompt = malloc(strlen(default_prompt) + 1);
            strcpy(prompt, default_prompt);
        }
        else{
            prompt = malloc(strlen(environment) + 1);
            strcpy(prompt, environment);
        }
        return prompt;

}

// int change_dir(char **dir){

// }

char **cmd_parse(char const *line){

    size_t max_arguments = sysconf(_SC_ARG_MAX);
    char *new_line = strdup(line);
    char **stored_strings = NULL;
    char *command = strtok(new_line, " ");
    int i = 0;
    

    while(command != NULL){
        stored_strings = realloc(stored_strings, sizeof(i + 1));
        stored_strings[i] = strdup(command);
        i++;
        command = strtok(NULL, " ");
    }

    stored_strings = realloc(stored_strings, sizeof(i + 1));
    stored_strings[i] = NULL;

    if(sizeof(stored_strings) > max_arguments){
        fprintf(stderr, "too many arguments");
        return NULL;
    }
    else{
        return stored_strings;
    }

    
}