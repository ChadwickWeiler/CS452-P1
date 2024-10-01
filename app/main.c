#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "../src/lab.h"
#include <readline/readline.h>
#include <readline/history.h>

#define MAX_ARGUMENTS 8

int main(int argc, char **argv){
  int c;
  //int historyflag;
  extern char *optarg;
  extern int optind, optopt, opterr;
  
  //char test_input[100] = "     wow buddy   this     is wild   ";
  //char *trimmed = trim_white(test_input);
  //printf("%s\n", trimmed);

  while((c = getopt (argc, argv, "vi")) != -1)
    switch (c) {

      case 'v':
        printf("Version %d.%d\n", lab_VERSION_MAJOR, lab_VERSION_MINOR);
        return 0;
        break;

        case 'i':
        
        break;

      case '?':
        if (isprint(optopt))
          fprintf(stderr, "Option unknown %c\n", optopt);
        else  
          fprintf(stderr, "Option unknown %c\n", optopt);
        return 1;

      default:
        abort();
        break;
    
    }


  const char *shell_prompt = get_prompt("MY_PROMPT");
  char *line;

  using_history();
  while ((line=readline(shell_prompt))){
    char *arguments[MAX_ARGUMENTS];
    int i = 0;

    trim_white(line);
    add_history(line);

    char* tokens = strtok(line, " ");

    while (tokens != NULL && i < MAX_ARGUMENTS -1){
      arguments[i] = tokens;
      i++;
      tokens = strtok(NULL, " ");
    }

    arguments[i] = NULL;

    if(i >= 1){
      
      //handling exit command
      if(strcmp(arguments[0], "exit") == 0 || strcmp(arguments[0], "EOF") == 0){  
      //quit and free memory
      free(line);
      free((void *)shell_prompt);
      exit(0);
      }

      //handling history command
      if(strcmp(arguments[0], "history") == 0){
        int j = 0;

        HIST_ENTRY **history_print = history_list();
        if(history_print != NULL){

          while(history_print[j] != NULL){

            printf("%s\n", history_print[j]->line);
            j++;

            }
          }

          else{
            printf("No History found\n");
          }         
      }

      if(strcmp(arguments[0], "cd") == 0){
        
      }

    }

    //printf("%s\n",line);
    free(line);
  }

  //freeing memory
  free((void *)shell_prompt);

  exit(1);
}

