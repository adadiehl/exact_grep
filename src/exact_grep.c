#include <exact_grep.h>
#define MAXLINE 100000

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

int main(int argc, char *argv[]) {

  int status = 0;

  status = exact_grep(argv[1], argv[2], MAXLINE);

  return(status);
}

