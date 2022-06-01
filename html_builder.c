#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
  TODO:
  add commants
  clean IF statement
  change the html syntax so it would be more safe to use the program
*/

// typedef struct text_block {
//   char* name;
//   char* path;
// } text_block;

char* read_block(char* path) {
  FILE* fileptr = fopen(path, "r");
  if (fileptr == NULL) {
    perror("Could not open the file-block!");
    return NULL;
  }
  int eob = 1;
  char b_line[256];
  while (eob != 0) {
    if (fgets(b_line, 256, fileptr) == NULL) {
      eob = 0;
    } else {
      printf("%s", b_line);
    }
  }
  fclose(fileptr);
  return path;
}


int main(int argc, char const *argv[]) {
  printf("Content-type: text/html\n\r\n\r");
  char configAddress[64] = "/etc/html-blocks/";
  const char extention[] = ".html";
  char *endOfPath;
  endOfPath = &configAddress[strlen(configAddress)];
  char *address;
  char *keyWordStart;
  char *keyWordEnd;

  int endOfLine = 1;
  int keyWordLen;

  //  const char toRoot[] = "../"; --> for local debuginf porposes
  if ((address = malloc(sizeof(char) * (
  strlen(getenv("SCRIPT_NAME")) + strlen(getenv("DOCUMENT_ROOT") + 1)
  ))) != NULL) {
    address[0] = '\0';
    strcat(address, getenv("DOCUMENT_ROOT"));
    strcat(address, getenv("SCRIPT_NAME"));
  } else {
    perror("failed to allocate memory");
    return 3;
  }
  // printf("%s\n", address); --> for local debuginf porposes

  char line[256];
  FILE* subject = fopen(address, "r");
  if (subject == NULL) {
    perror("error: subject couldn't be open \n");
    free(address);
    return 2;
  }

  while (endOfLine != 0) {
    if (fgets(line, 256, subject) == NULL) {
      endOfLine = 0;
    } else {
      // TODO: clean this IF statement and make it more efficient
      if ( strstr(line, "<!--") &&
        strstr(line, "@@") &&
        strstr(line, "-->") &&
        (keyWordStart = strstr(line, "\"" ))
      ) {
        ++keyWordStart;
        keyWordEnd = strstr(keyWordStart, "\"");
        *keyWordEnd = '\0';
        keyWordLen = keyWordEnd - keyWordStart;
        if (keyWordLen > 32) {
          perror("keyword lenth out of range");
          continue;
        }
        else {
          strcat(configAddress, keyWordStart);
          strcat(configAddress, extention);
          read_block(configAddress);
          *endOfPath = '\0';
        }
      }
      else {
        printf("%s", line);
      }
    }
  }
  free(address);
  fclose(subject);
  return 0;
}
