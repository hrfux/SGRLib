/**
 * @file sgr.c
 * @date 2022-09-02
 * @author Steven-L. Fuchs (stevenfuchs@live.de)
 * @version 1.0
 * @copyright Copyright (c) 2022 Steven-L. Fuchs
 * @brief Implementation of SGR library functions.
 */

#include "sgr.h"
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef _SGR_C_
#define _SGR_C_

#ifdef __cplusplus
extern "C"
{
#endif

  /**
   * @brief Sets SGR via CSI.
   * @param count Number of escape sequence parameter codes.
   * @param ... Escape sequence parameter codes.
   */
  void setsgr(int count, ...)
  {
    va_list args;
    int     iter;

    va_start(args, count);

    putchar('\x1B');
    putchar('[');

    for (iter = 0; iter < count; iter++)
    {
      printf("%d", va_arg(args, int));
      if (iter != count - 1) putchar(';');
    }

    putchar('m');
    va_end(args);
  }

  /**
   * @brief Sets SGR via CSI with output to file stream.
   * @param file File for output.
   * @param count Number of escape sequence parameter codes.
   * @param ... Escape sequence parameter codes.
   */
  void fsetsgr(FILE *file, int count, ...)
  {
    va_list args;
    int     iter;

    va_start(args, count);

    fputc('\x1B', file);
    fputc('[', file);

    for (iter = 0; iter < count; iter++)
    {
      fprintf(file, "%d", va_arg(args, int));
      if (iter != count - 1) fputc(';', file);
    }

    fputc('m', file);
    va_end(args);
  }

#ifdef __cplusplus
}
#endif

#endif