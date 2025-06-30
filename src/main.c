#include "json.h"
#include <stdio.h>

#define BUFFER_SIZE 50

void parse(char *buffer) { printf("%s", buffer); }

int main(int argc, char **argv) {
  if (argc < 2) {
    printf("USAGE: cuaso <file>");
    return 0;
  }
  char buffer[BUFFER_SIZE];
  FILE *file = fopen(argv[1], "r");
  
  if (!file) {
    printf("Couldn't finish operation: FILE DOESN'T EXIST");
    return -1;
  }

  // this will read line by line of json file or input
  while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
    parse(buffer);
  }

  return 0;
}
