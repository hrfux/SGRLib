/**
 * @file sgr.h
 * @date 2022-09-01
 * @author Steven-L. Fuchs (stevenfuchs@live.de)
 * @version 2.0
 * @copyright Copyright (c) 2022 Steven-L. Fuchs
 * @brief Header for escape sequences for graphical changes based on Select
 * Graphic Rendition codes from the ECMA-48 standard with some nonstandard
 * additions for modern terminals.
 * @todo
 *  - convience print functions that call reset before printing newline
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

  /* Standalone string macros */

#define SGR_RESET                           "\x1B[0m"
#define SGR_BOLD                            "\x1B[1m"
#define SGR_DIM                             "\x1B[2m"
#define SGR_ITALIC                          "\x1B[3m"
#define SGR_UNDERLINED                      "\x1B[4m"
#define SGR_BLINKING_SLOW                   "\x1B[5m"
#define SGR_BLANK_FAST                      "\x1B[6m"
#define SGR_INVERTED                        "\x1B[7m"
#define SGR_CONCEALED                       "\x1B[8m"
#define SGR_CROSSED_OUT                     "\x1B[9m"
#define SGR_DEFAULT_FONT                    "\x1B[10m"
#define SGR_ALTERNATE_FONT_1                "\x1B[11m"
#define SGR_ALTERNATE_FONT_2                "\x1B[12m"
#define SGR_ALTERNATE_FONT_3                "\x1B[13m"
#define SGR_ALTERNATE_FONT_4                "\x1B[14m"
#define SGR_ALTERNATE_FONT_5                "\x1B[15m"
#define SGR_ALTERNATE_FONT_6                "\x1B[16m"
#define SGR_ALTERNATE_FONT_7                "\x1B[17m"
#define SGR_ALTERNATE_FONT_8                "\x1B[18m"
#define SGR_ALTERNATE_FONT_9                "\x1B[19m"
#define SGR_FRAKTUR_FONT                    "\x1B[20m"
#define SGR_UNDERLINED_DOUBLE               "\x1B[21m"
#define SGR_NORMAL_INTENSITY                "\x1B[22m"
#define SGR_NOT_ITALIC                      "\x1B[23m"
#define SGR_NOT_FRAKTUR_FONT                "\x1B[23m"
#define SGR_NOT_UNDERLINED                  "\x1B[24m"
#define SGR_STEADY                          "\x1B[25m"
#define SGR_NOT_BLINKING                    "\x1B[25m"
#define SGR_PROPORTIONAL_SPACING            "\x1B[26m"
#define SGR_NOT_INVERTED                    "\x1B[27m"
#define SGR_NOT_CONCEALED                   "\x1B[28m"
#define SGR_REVEAL                          "\x1B[28m"
#define SGR_NOT_CROSSED_OUT                 "\x1B[29m"
#define SGR_FORE_BLACK                      "\x1B[30m"
#define SGR_FORE_RED                        "\x1B[31m"
#define SGR_FORE_GREEN                      "\x1B[32m"
#define SGR_FORE_YELLOW                     "\x1B[33m"
#define SGR_FORE_BLUE                       "\x1B[34m"
#define SGR_FORE_MAGENTA                    "\x1B[35m"
#define SGR_FORE_CYAN                       "\x1B[36m"
#define SGR_FORE_WHITE                      "\x1B[37m"
#define SGR_FORE_SET_COLOR                  "\x1B[38m"
#define SGR_FORE_DEFAULT_COLOR              "\x1B[39m"
#define SGR_BACK_BLACK                      "\x1B[40m"
#define SGR_BACK_RED                        "\x1B[41m"
#define SGR_BACK_GREEN                      "\x1B[42m"
#define SGR_BACK_YELLOW                     "\x1B[43m"
#define SGR_BACK_BLUE                       "\x1B[44m"
#define SGR_BACK_MAGENTA                    "\x1B[45m"
#define SGR_BACK_CYAN                       "\x1B[46m"
#define SGR_BACK_WHITE                      "\x1B[47m"
#define SGR_BACK_SET_COLOR                  "\x1B[48m"
#define SGR_BACK_DEFAULT_COLOR              "\x1B[49m"
#define SGR_NOT_PROPORTIONAL_SPACING        "\x1B[50m"
#define SGR_FRAMED                          "\x1B[51m"
#define SGR_ENCIRCLED                       "\x1B[52m"
#define SGR_OVERLINED                       "\x1B[53m"
#define SGR_NOT_FRAMED                      "\x1B[54m"
#define SGR_NOT_ENCIRCLED                   "\x1B[54m"
#define SGR_NOT_OVERLINED                   "\x1B[55m"
#define SGR_UNDERLINED_SET_COLOR            "\x1B[58m"
#define SGR_UNDERLINED_DEFAULT_COLOR        "\x1B[59m"
#define SGR_IDEOGRAM_UNDERLINED             "\x1B[60m"
#define SGR_IDEOGRAM_RIGHT_LINED            "\x1B[60m"
#define SGR_IDEOGRAM_UNDERLINED_DOUBLE      "\x1B[61m"
#define SGR_IDEOGRAM_RIGHT_LINED_DOUBLE     "\x1B[61m"
#define SGR_IDEOGRAM_OVERLINED              "\x1B[62m"
#define SGR_IDEOGRAM_LEFT_LINED             "\x1B[62m"
#define SGR_IDEOGRAM_OVERLINED_DOUBLE       "\x1B[63m"
#define SGR_IDEOGRAM_LEFT_LINED_DOUBLE      "\x1B[63m"
#define SGR_IDEOGRAM_STRESS_MARKING         "\x1B[64m"
#define SGR_IDEOGRAM_RESET                  "\x1B[65m"
#define SGR_NONSTANDARD_SUPERSCRIPT         "\x1B[73m"
#define SGR_NONSTANDARD_SUBSCRIPT           "\x1B[74m"
#define SGR_NONSTANDARD_NOT_SUPERSCRIPT     "\x1B[75m"
#define SGR_NONSTANDARD_NOT_SUBSCRIPT       "\x1B[75m"
#define SGR_NONSTANDARD_FORE_BRIGHT_BLACK   "\x1B[90m"
#define SGR_NONSTANDARD_FORE_GREY           "\x1B[90m"
#define SGR_NONSTANDARD_FORE_BRIGHT_RED     "\x1B[91m"
#define SGR_NONSTANDARD_FORE_BRIGHT_GREEN   "\x1B[92m"
#define SGR_NONSTANDARD_FORE_BRIGHT_YELLOW  "\x1B[93m"
#define SGR_NONSTANDARD_FORE_BRIGHT_BLUE    "\x1B[94m"
#define SGR_NONSTANDARD_FORE_BRIGHT_MAGENTA "\x1B[95m"
#define SGR_NONSTANDARD_FORE_BRIGHT_CYAN    "\x1B[96m"
#define SGR_NONSTANDARD_FORE_BRIGHT_WHITE   "\x1B[97m"
#define SGR_NONSTANDARD_BACK_BRIGHT_BLACK   "\x1B[100m"
#define SGR_NONSTANDARD_BACK_BRIGHT_RED     "\x1B[101m"
#define SGR_NONSTANDARD_BACK_BRIGHT_GREEN   "\x1B[102m"
#define SGR_NONSTANDARD_BACK_BRIGHT_YELLOW  "\x1B[103m"
#define SGR_NONSTANDARD_BACK_BRIGHT_BLUE    "\x1B[104m"
#define SGR_NONSTANDARD_BACK_BRIGHT_MAGENTA "\x1B[105m"
#define SGR_NONSTANDARD_BACK_BRIGHT_CYAN    "\x1B[106m"
#define SGR_NONSTANDARD_BACK_BRIGHT_WHITE   "\x1B[107m"

/** Provides shorter macros via concat for standard parameter codes. */
#define sgr(short) SGR_PARAM_##short

/** Provides shorter macros via concat for nonstandard parameter codes. */
#define sgrn(short) SGR_PARAM_NONSTANDARD_##short

/** Outputs reset code. */
#define sgr_reset() printf("\x1B[0m")

/** Specifies SGR library version. */
#define SGR_LIBVER 20

/** Specifies which character to use as seperator. May be overwritten. */
#define SGR_SEPERATOR ';'

  extern void sgr_set(int count, ...);
  extern void sgr_fset(FILE *file, int count, ...);

#endif

#ifdef __cplusplus
}
#endif