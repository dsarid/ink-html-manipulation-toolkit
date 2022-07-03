/* License Notice:
This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation.

This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

 You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ink-html.h"

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

int main(int argc, char const *argv[]) {
  printf("Content-type: text/html\n\r\n\r");
  char configAddress[64] = "/etc/html-blocks/";
  const char extention[] = ".html";
  char *endOfPath;
  endOfPath = &configAddress[strlen(configAddress)];
  char *keyWordStart;
  char *keyWordEnd;

  bool endOfLine = 1;
  int keyWordLen;

  //  const char toRoot[] = "../"; --> for local debuging purposes
  char *address = get_html_path(getenv("DOCUMENT_ROOT"), getenv("SCRIPT_NAME"));
  // printf("%s\n", address); --> for local debuging purposes

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
        (keyWordStart = strstr(line, "/\"" )) &&
        (keyWordEnd = strstr(keyWordStart, "\"/"))
      ) {
        keyWordStart += 2;
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
