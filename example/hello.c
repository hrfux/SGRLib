#include "sgr.h"
#include <stdio.h>

int main(void)
{
  /* without ease of use functions */

  setsgr(3, sgr(CROSSED_OUT), sgr(FORE_BLUE), sgr(BACK_WHITE));
  printf("Hello, world!");
  resetsgr();
  setsgr(3, sgr(FORE_SET_COLOR), sgrn(8BIT_ARGUMENT), sgrn(8BIT_BRIGHT_BLUE));
  printf(" And again!");
  resetsgr();
  putchar('\n');

  printf("%sAnother Text.", SGR_FORE_GREEN);
  resetsgr();

  /* with ease of use of functions */

  /* use new functions here ... */

  return 0;
}