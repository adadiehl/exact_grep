#include <stdio.h>
#include <string.h>
#include <exact_grep.h>

/********************************************************************

exact_grep: A simple utility to find lines in a text file containing
exact word matches.

Copyright (C) 2015, Adam Diehl, adadiehl@umich.edu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>

*********************************************************************/

int exact_grep(char pat[], char fname[], int max_len) {
  FILE *fp;
  char line[max_len];
  char cpy[max_len];
  char *token;
  int status = 0;
  const char delim[10] = " \t";

  fp = fopen(fname, "r");
  if (fp == NULL) {
    perror("Error opening input file");
    return(-1);
  }

  while (fgets(line, max_len, fp) != NULL) {

    strcpy(cpy, line);

    /* Truncate the trailing newline character */
    cpy[strcspn(cpy, "\n")] = 0;

    token = strtok(cpy, delim);

    while ( token != NULL ) {
      if ( strcmp(token, pat) == 0 ) {
        status = 0;
        printf("%s", line);
      }
      token = strtok(NULL, delim);
    }

  }

  fclose(fp);
  return(status);
}
