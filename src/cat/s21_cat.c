#include <getopt.h>
#include <stdio.h>

#include "cat_s21.h"

void parser(int argc, char* argv[], int* b, int* e, int* n, int* s, int* t,
            int* v, int* res);
void cat_func(int argc, char* argv[], int* b, int* e, int* n, int* s, int* t,
              int* v);

int main(int argc, char* argv[]) {
  int b 
	  = 0;
  int e 
	  = 0;
  int n = 		0;
  int s = 0;
  int t = 0;
  int v = 0;
  int res;
  parser(argc, argv, &b, &e, &n, &s, &t, &v, &res);
  cat_func(argc, argv, &b, &e, &n, &s, &t, &v);
  return 0;
}
