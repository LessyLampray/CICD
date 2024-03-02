#include "cat_s21.h"

#include <getopt.h>
#include <stdio.h>

void parser(int argc, char* argv[], int* b, int* e, int* n, int* s, int* t,
            int* v, int* res) {
  const char* short_options = "+benstvET";
  const struct option long_options[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};

  while ((*res = getopt_long(argc, argv, short_options, long_options, NULL)) !=
         -1) {
    switch (*res) {
      case 'b':
        *b = 1;
        break;
      case 'e':
        *e = 1;
        break;
      case 'n':
        *n = 1;
        break;
      case 's':
        *s = 1;
        break;
      case 't':
        *t = 1;
        break;
      case 'v':
        *v = 1;
        break;
      default:
        break;
    }
  }
}

void cat_func(int argc, char* argv[], int* b, int* e, int* n, int* s, int* t,
              int* v) {
  for (int i = optind; i < argc; i++) {
    FILE* file;
    file = fopen(argv[i], "r");
    if (file == NULL) {
      fprintf(stderr, "cat: %s: No such file or directory", argv[i]);
    } else {
      char ch;
      char last_ch = '\n';
      int counter = 0;
      int str_num = 0;

      while ((ch = getc(file)) != EOF) {
        if ((*s == 1 && ch == '\n') && (last_ch == '\n' || last_ch == '\0')) {
          counter++;
          if (counter > 1) {
            continue;
          }
        } else {
          counter = 0;
        }
        if (*b == 1 && ch != '\n' && last_ch == '\n') {
          printf("%6d	", ++str_num);
        }
        if ((*n == 1 && *b != 1 && last_ch == '\n')) {
          printf("%6d	", ++str_num);
        }
        if (*e == 1 && ch == '\n') {
          printf("$");
        }
        if (*t == 1 && ch == '\t') {
          printf("^");
          ch = 'I';
        }

        if ((ch < 32 && *v == 1 && ch != 9 && ch != 10) ||
            (ch < 32 && *e == 1 && ch != 9 && ch != 10) ||
            (ch < 32 && *t == 1 && ch != 9 && ch != 10)) {
          printf("^%c", ch + 64);
        } else {
          if ((ch > 126 && *v == 1) || (ch > 126 && *e == 1) ||
              (ch > 126 && *t == 1)) {
            printf("^%c", ch - 64);
          } else {
            printf("%c", ch);
          }
        }
        last_ch = ch;
      }
      fclose(file);
    }
  }
}