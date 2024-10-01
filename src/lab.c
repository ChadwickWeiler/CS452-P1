#include "lab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

const char *default_prompt = "shell>";
char **stored_strings = NULL;
int arguments = 0;

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
    char *command = strtok(new_line, " ");
    int i = 0;
    

    while(command != NULL){
        stored_strings = realloc(stored_strings, sizeof(i + 1));
        stored_strings[i] = strdup(command);
        i++;
        arguments = i; 
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

void cmd_free(char ** line){
    if((arguments = 0)){
        fprintf(stderr, "nothing to free");
    }
    else{
        free(stored_strings);
        free(line);
    }
}

char *trim_white(char *line){

    if (line == NULL) {
    fprintf(stderr, "Err NULL pointer in trim_white\n");
    return NULL; 
    }

    char *trimmed_line = line;
    char *line_copy = line;
    

    //skips beginning whitespace
    while(*trimmed_line && isspace((unsigned char)*trimmed_line)){
            trimmed_line++;
    }

    //checks if next character is whitespace, if it is, 
    //skips any proceeding whitespace til the next character or end of line
    while(*trimmed_line){

        //advance in the line if its not a white space
        if(!isspace((unsigned char)*trimmed_line)){
            *line_copy++ = *trimmed_line;

        }

        else{
            if(line_copy != line && *(line_copy - 1) != ' '){
                *line_copy++ = ' '; //assign current character as a single space
            }

        }

        trimmed_line++;
    }

    *line_copy = '\0';
    return line;


}

// bool do_builtin(struct shell *sh, char **argv);

// void sh_init(struct shell *sh);

// void sh_destroy(struct shell *sh);

// void parse_args(int argc, char **argv);
