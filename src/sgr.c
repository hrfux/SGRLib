/**
 * @file sgr.c
 * @date 2022-09-02
 * @author Steven-L. Fuchs (stevenfuchs@live.de)
 * @version 2.0
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

  void sgr_set(int count, ...)
  {
    va_list args;
    int     iter;

    va_start(args, count);

    printf(SGR_PARAM_ECMA_CSI);

    for (iter = 0; iter < count; iter++)
    {
      printf("%d", va_arg(args, int));
      if (iter != count - 1) putchar(SGR_SEPERATOR);
    }

    putchar('m');
    va_end(args);
  }

  void sgr_fset(FILE *file, int count, ...)
  {
    va_list args;
    int     iter;

    va_start(args, count);

    fprintf(file, SGR_PARAM_ECMA_CSI);

    for (iter = 0; iter < count; iter++)
    {
      fprintf(file, "%d", va_arg(args, int));
      if (iter != count - 1) fputc(SGR_SEPERATOR, file);
    }

    fputc('m', file);
    va_end(args);
  }

  /**
   * @brief Discrete printing function used to avoid boilerplate.
   * @param file File for output.
   * @param newline Bool for whether to output newline or not.
   * @param sgr Escape sequence as string. (e.g. standalone macro)
   * @param format Format to be printed.
   * @param args Arguments for format.
   */
  static void _sgr_fprintf(FILE   *file,
                           _bool_t newline,
                           char   *sgr,
                           char   *format,
                           va_list args)
  {
    printf(sgr);
    vfprintf(file, format, args);
    sgr_reset();
    if (newline) putchar('\n');
  }

  void sgr_printf(char *sgr, char *format, ...)
  {
    va_list args;
    va_start(args, format);
    _sgr_fprintf(stdout, FALSE, sgr, format, args);
    va_end(args);
  }

  void sgr_printfn(char *sgr, char *format, ...)
  {
    va_list args;
    va_start(args, format);
    _sgr_fprintf(stdout, TRUE, sgr, format, args);
    va_end(args);
  }

  void sgr_fprintf(FILE *file, char *sgr, char *format, ...)
  {
    va_list args;
    va_start(args, format);
    _sgr_fprintf(file, FALSE, sgr, format, args);
    va_end(args);
  }

  void sgr_fprintfn(FILE *file, char *sgr, char *format, ...)
  {
    va_list args;
    va_start(args, format);
    _sgr_fprintf(file, TRUE, sgr, format, args);
    va_end(args);
  }

#ifdef __cplusplus
}
#endif

#endif