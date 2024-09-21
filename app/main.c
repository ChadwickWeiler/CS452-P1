#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "../src/lab.h"
#include <readline/readline.h>
#include <readline/history.h>


int main(int argc, char **argv)
{
  printf("hello world\n");
  int c;
  extern char *optarg;
  extern int optind, optopt, opterr;

  while((c = getopt (argc, argv, "vi")) != -1)
    switch (c) {
      case 'v':
        printf("Version %d.%d\n", lab_VERSION_MAJOR, lab_VERSION_MINOR);
        break;

        case 'i':
        userInput;
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

  return 0;
}

char userInput(){
  char *line;
  while ((line=readline("$"))){
      printf("%s\n",line);
      add_history(line);
      free(line);
  }
}