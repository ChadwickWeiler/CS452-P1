#include "lab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *MY_PROMPT = "shell>";

char *get_prompt(const char *env){

    //setting a temporary variable to change to the env provided.
    char *environment = getenv(env);
    if(environment != NULL){

        //malloc the size of the environment 
        char *prompt = malloc(strlen(environment) + 1);
        strcpy (prompt, environment);
         //casting the prompt to const char to return
        
        return prompt; 
    }
    //malloc the size of the environment 
    char *prompt = malloc(strlen(MY_PROMPT) + 1);
    strcpy (prompt, MY_PROMPT);
    //casting the prompt to const char to return
    return prompt; 

}

