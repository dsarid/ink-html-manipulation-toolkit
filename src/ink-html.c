#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ink-html.h"

const char extention[] = ".html";

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

/* This function return a dynamically allocated pointer
It is up to the caller to free it */
char* get_html_path(const char* root_path, const char* html_name) {
  char *req_path;
  int path_len = sizeof(char) * (strlen(html_name) + strlen(root_path) + 1);
  if ((req_path = malloc(path_len)) != NULL ) {
    req_path[0] = '\0';
    strcat(req_path, root_path);
    strcat(req_path, html_name);
    return req_path;
  } else {
    perror("failed to allocate memory");
    return NULL;
  }
}
