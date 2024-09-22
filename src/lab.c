#include "lab.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char *MY_PROMPT = "shell>";

char *get_prompt(const char *env){


    //setting a temporary variable to change to the env provided.
    const char *environment = MY_PROMPT;

        if((env != NULL)){
            environment = getenv(env);
        }

        char *prompt = malloc(strlen(environment) + 1);
        strcpy (prompt, environment);

        return prompt;

}


