/**
 * @file sgr.h
 * @date 2022-09-01
 * @author Steven-L. Fuchs (stevenfuchs@live.de)
 * @version 1.0
 * @copyright Copyright (c) 2022 Steven-L. Fuchs
 * @brief Header for escape sequences for graphical changes based on Select
 * Graphic Rendition codes from the ECMA-48 standard with some nonstandard
 * additions for modern terminals.
 * @todo
 *  - convience print functions that call reset before printing newline
 *  - maybe support for ITU T.416 with colon seperator
 *  - string macros for printing
 */

#include <stdarg.h>
#include <stdio.h>

#ifndef _SGR_H_
#define _SGR_H_

#ifdef __cplusplus
extern "C"
{
#endif

  /* Official standard parameter macros from ECMA-48 */

#define SGR_PARAM_RESET                       0
#define SGR_PARAM_BOLD                        1
#define SGR_PARAM_DIM                         2
#define SGR_PARAM_ITALIC                      3
#define SGR_PARAM_UNDERLINED                  4
#define SGR_PARAM_BLINKING_SLOW               5
#define SGR_PARAM_BLANK_FAST                  6
#define SGR_PARAM_INVERTED                    7
#define SGR_PARAM_CONCEALED                   8
#define SGR_PARAM_CROSSED_OUT                 9
#define SGR_PARAM_DEFAULT_FONT                10
#define SGR_PARAM_ALTERNATE_FONT_1            11
#define SGR_PARAM_ALTERNATE_FONT_2            12
#define SGR_PARAM_ALTERNATE_FONT_3            13
#define SGR_PARAM_ALTERNATE_FONT_4            14
#define SGR_PARAM_ALTERNATE_FONT_5            15
#define SGR_PARAM_ALTERNATE_FONT_6            16
#define SGR_PARAM_ALTERNATE_FONT_7            17
#define SGR_PARAM_ALTERNATE_FONT_8            18
#define SGR_PARAM_ALTERNATE_FONT_9            19
#define SGR_PARAM_FRAKTUR_FONT                20
#define SGR_PARAM_UNDERLINED_DOUBLE           21
#define SGR_PARAM_NORMAL_INTENSITY            22
#define SGR_PARAM_NOT_ITALIC                  23
#define SGR_PARAM_NOT_FRAKTUR_FONT            23
#define SGR_PARAM_NOT_UNDERLINED              24
#define SGR_PARAM_STEADY                      25
#define SGR_PARAM_NOT_BLINKING                25
#define SGR_PARAM_PROPORTIONAL_SPACING        26
#define SGR_PARAM_NOT_INVERTED                27
#define SGR_PARAM_NOT_CONCEALED               28
#define SGR_PARAM_REVEAL                      28
#define SGR_PARAM_NOT_CROSSED_OUT             29
#define SGR_PARAM_FORE_BLACK                  30
#define SGR_PARAM_FORE_RED                    31
#define SGR_PARAM_FORE_GREEN                  32
#define SGR_PARAM_FORE_YELLOW                 33
#define SGR_PARAM_FORE_BLUE                   34
#define SGR_PARAM_FORE_MAGENTA                35
#define SGR_PARAM_FORE_CYAN                   36
#define SGR_PARAM_FORE_WHITE                  37
#define SGR_PARAM_FORE_SET_COLOR              38
#define SGR_PARAM_FORE_DEFAULT_COLOR          39
#define SGR_PARAM_BACK_BLACK                  40
#define SGR_PARAM_BACK_RED                    41
#define SGR_PARAM_BACK_GREEN                  42
#define SGR_PARAM_BACK_YELLOW                 43
#define SGR_PARAM_BACK_BLUE                   44
#define SGR_PARAM_BACK_MAGENTA                45
#define SGR_PARAM_BACK_CYAN                   46
#define SGR_PARAM_BACK_WHITE                  47
#define SGR_PARAM_BACK_SET_COLOR              48
#define SGR_PARAM_BACK_DEFAULT_COLOR          49
#define SGR_PARAM_NOT_PROPORTIONAL_SPACING    50
#define SGR_PARAM_FRAMED                      51
#define SGR_PARAM_ENCIRCLED                   52
#define SGR_PARAM_OVERLINED                   53
#define SGR_PARAM_NOT_FRAMED                  54
#define SGR_PARAM_NOT_ENCIRCLED               54
#define SGR_PARAM_NOT_OVERLINED               55
#define SGR_PARAM_UNDERLINED_SET_COLOR        58
#define SGR_PARAM_UNDERLINED_DEFAULT_COLOR    59
#define SGR_PARAM_IDEOGRAM_UNDERLINED         60
#define SGR_PARAM_IDEOGRAM_RIGHT_LINED        60
#define SGR_PARAM_IDEOGRAM_UNDERLINED_DOUBLE  61
#define SGR_PARAM_IDEOGRAM_RIGHT_LINED_DOUBLE 61
#define SGR_PARAM_IDEOGRAM_OVERLINED          62
#define SGR_PARAM_IDEOGRAM_LEFT_LINED         62
#define SGR_PARAM_IDEOGRAM_OVERLINED_DOUBLE   63
#define SGR_PARAM_IDEOGRAM_LEFT_LINED_DOUBLE  63
#define SGR_PARAM_IDEOGRAM_STRESS_MARKING     64
#define SGR_PARAM_IDEOGRAM_RESET              65

  /* Nonstandard parameter macros for super- and subscript support */

#define SGR_PARAM_NONSTANDARD_SUPERSCRIPT     73
#define SGR_PARAM_NONSTANDARD_SUBSCRIPT       74
#define SGR_PARAM_NONSTANDARD_NOT_SUPERSCRIPT 75
#define SGR_PARAM_NONSTANDARD_NOT_SUBSCRIPT   75

  /* Nonstandard parameter macros for bright color support */

#define SGR_PARAM_NONSTANDARD_FORE_BRIGHT_BLACK   90
#define SGR_PARAM_NONSTANDARD_FORE_GREY           90
#define SGR_PARAM_NONSTANDARD_FORE_BRIGHT_RED     91
#define SGR_PARAM_NONSTANDARD_FORE_BRIGHT_GREEN   92
#define SGR_PARAM_NONSTANDARD_FORE_BRIGHT_YELLOW  93
#define SGR_PARAM_NONSTANDARD_FORE_BRIGHT_BLUE    94
#define SGR_PARAM_NONSTANDARD_FORE_BRIGHT_MAGENTA 95
#define SGR_PARAM_NONSTANDARD_FORE_BRIGHT_CYAN    96
#define SGR_PARAM_NONSTANDARD_FORE_BRIGHT_WHITE   97
#define SGR_PARAM_NONSTANDARD_BACK_BRIGHT_BLACK   100
#define SGR_PARAM_NONSTANDARD_BACK_BRIGHT_RED     101
#define SGR_PARAM_NONSTANDARD_BACK_BRIGHT_GREEN   102
#define SGR_PARAM_NONSTANDARD_BACK_BRIGHT_YELLOW  103
#define SGR_PARAM_NONSTANDARD_BACK_BRIGHT_BLUE    104
#define SGR_PARAM_NONSTANDARD_BACK_BRIGHT_MAGENTA 105
#define SGR_PARAM_NONSTANDARD_BACK_BRIGHT_CYAN    106
#define SGR_PARAM_NONSTANDARD_BACK_BRIGHT_WHITE   107

  /* Auxiliary parameter macros for constructing escape sequences */

#define SGR_PARAM_ECMA_CSI                   "\x1B["
#define SGR_PARAM_NONSTANDARD_8BIT_ARGUMENT  5
#define SGR_PARAM_NONSTANDARD_24BIT_ARGUMENT 2

  /* Nonstandard parameter macros for 8-bit color support */

#define SGR_PARAM_NONSTANDARD_8BIT_BLACK          0
#define SGR_PARAM_NONSTANDARD_8BIT_RED            1
#define SGR_PARAM_NONSTANDARD_8BIT_GREEN          2
#define SGR_PARAM_NONSTANDARD_8BIT_YELLOW         3
#define SGR_PARAM_NONSTANDARD_8BIT_BLUE           4
#define SGR_PARAM_NONSTANDARD_8BIT_MAGENTA        5
#define SGR_PARAM_NONSTANDARD_8BIT_CYAN           6
#define SGR_PARAM_NONSTANDARD_8BIT_WHITE          7
#define SGR_PARAM_NONSTANDARD_8BIT_BRIGHT_BLACK   8
#define SGR_PARAM_NONSTANDARD_8BIT_GREY           8
#define SGR_PARAM_NONSTANDARD_8BIT_BRIGHT_RED     9
#define SGR_PARAM_NONSTANDARD_8BIT_BRIGHT_GREEN   10
#define SGR_PARAM_NONSTANDARD_8BIT_BRIGHT_YELLOW  11
#define SGR_PARAM_NONSTANDARD_8BIT_BRIGHT_BLUE    12
#define SGR_PARAM_NONSTANDARD_8BIT_BRIGHT_MAGENTA 13
#define SGR_PARAM_NONSTANDARD_8BIT_BRIGHT_CYAN    14
#define SGR_PARAM_NONSTANDARD_8BIT_BRIGHT_WHITE   15

/** Provides shorter macros via concat for standard parameter codes. */
#define sgr(short) SGR_PARAM_##short

/** Provides shorter macros via concat for nonstandard parameter codes. */
#define sgrn(short) SGR_PARAM_NONSTANDARD_##short

/** Outputs reset code. */
#define resetsgr() printf("\x1B[0m")

  void setsgr(int count, ...);
  void fsetsgr(FILE *file, int count, ...);

#endif

#ifdef __cplusplus
}
#endif