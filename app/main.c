#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "../src/lab.h"
#include <readline/readline.h>
#include <readline/history.h>


int main(int argc, char **argv){
  int c;
  //int historyflag;
  extern char *optarg;
  extern int optind, optopt, opterr;
  char test_input[100] = "     wow buddy   this     is wild   ";
  char *trimmed = trim_white(test_input);
  printf("%s\n", trimmed);

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

    if(strcmp(line, "exit") == 0 || strcmp(line, "EOF") == 0){
      //quit and free memory
      free(line);
      free((void *)shell_prompt);
      exit(0);
    }

    if(strcmp(line, "history") == 0){

          int i = 0;

          HIST_ENTRY **history_print = history_list();
          if(history_print != NULL){
            while(history_print[i] != NULL){
              printf("%s\n", history_print[i]->line);
              i++;
            }
          }

          else{
            printf("No History found\n");
          }         
    }
    if(strcmp(line, "cd") == 0){
      
    }

    //printf("%s\n",line);
    add_history(line);
    free(line);
  }

  //freeing memory
  free((void *)shell_prompt);

  exit(1);
}

