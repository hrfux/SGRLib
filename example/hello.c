#include "sgr.h"
#include <stdio.h>

int main(void)
{
  setsgr(3, sgr(CROSSED_OUT), sgr(FORE_BLUE), sgr(BACK_WHITE));
  printf("Hello, world!");
  sgrreset();
  puts("\nAnd again!");
  return 0;
}