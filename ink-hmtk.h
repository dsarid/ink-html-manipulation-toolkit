#ifndef INK_HMTK
#define INK_HMTK
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* read_block(char* path);

char* get_html_path(const char* root_path, const char* html_name);
#endif
