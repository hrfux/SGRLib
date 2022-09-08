#include "sgr.h"
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>

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
      sgr_printfn(SGR_NONSTANDARD_FORE_BRIGHT_BLUE, "  %s", entry->d_name);
      count++;
    }

    closedir(dir_ptr);
    printf("\n%d entries in '%s'.\n", count, dir);
  }
  else
  {
    sgr_fprintfn(stderr, SGR_FORE_RED, "  '%s' could not be listed.", dir);
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