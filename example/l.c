#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include "sgr.h"

void listing(char *dir)
{
  DIR           *dir_ptr;
  struct dirent *entry;
  int            count = 0;

  printf("Listing '%s':\n\n", dir);

  if ((dir_ptr = opendir(dir)))
  {
    while ((entry = readdir(dir_ptr)))
    {
      setsgr(2, SGR_PARAM_BOLD, sgrn(FORE_BRIGHT_BLUE));
      printf("  %s", entry->d_name);
      sgrreset();
      putchar('\n');
      count++;
    }

    closedir(dir_ptr);
    printf("\n%d entries in '%s'.\n", count, dir);
  }
  else
  {
    setsgr(2, SGR_PARAM_BOLD, SGR_PARAM_FORE_RED);
    fprintf(stderr, "  '%s' could not be listed.", dir);
    sgrreset();
    putchar('\n');
  }

  putchar('\n');
}

int main(int argc, char **argv)
{
  int iter;

  if (argc == 1)
  {
    listing(".");
    return 0;
  }

  for (iter = 1; iter < argc; iter++) listing(argv[iter]);

  return 0;
}