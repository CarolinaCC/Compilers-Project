/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20180609

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "diy.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/tabid.h"
#include "lib/node.h"
extern int yylex();
int yyerror(char *s);
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 10 "diy.y"
typedef union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 42 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

#if !(defined(yylex) || defined(YYSTATE))
int YYLEX_DECL();
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define INT 257
#define REAL 258
#define ID 259
#define STR 260
#define DO 261
#define WHILE 262
#define IF 263
#define THEN 264
#define FOR 265
#define IN 266
#define UPTO 267
#define DOWNTO 268
#define STEP 269
#define BREAK 270
#define CONTINUE 271
#define VOID 272
#define INTEGER 273
#define STRING 274
#define NUMBER 275
#define CONST 276
#define PUBLIC 277
#define INCR 278
#define DECR 279
#define ATR 280
#define NE 281
#define GE 282
#define LE 283
#define ELSE 284
#define IFX 285
#define UMINUS 286
#define PONT 287
#define ENDE 288
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    5,    5,    2,    2,    4,    4,    3,
    3,    3,    3,    6,    6,    8,    8,    8,    8,    8,
    9,    9,   12,   12,   10,   10,    7,    7,   11,   11,
   13,   14,   15,   15,   16,   16,   16,   16,   16,   16,
   16,   16,   21,   21,   20,   20,   18,   18,   22,   22,
   19,   19,   19,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   23,   23,
};
static const YYINT yylen[] = {                            2,
    0,    2,    6,    0,    1,    1,    2,    0,    1,    1,
    1,    1,    1,    2,    5,    0,    1,    2,    1,    1,
    0,    1,    0,    2,    0,    1,    0,    1,    1,    3,
    3,    4,    0,    1,    5,    5,    9,    2,    1,    3,
    3,    4,    0,    2,    1,    1,    0,    2,    0,    1,
    1,    4,    2,    1,    1,    1,    1,    3,    4,    3,
    2,    2,    2,    2,    2,    2,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    3,
};
static const YYINT yydefred[] = {                         1,
    0,   28,    0,    2,    0,    6,    7,   13,   10,   11,
   12,    0,    9,    0,    0,    0,    0,    5,   17,   19,
   20,    0,    0,   14,    3,    0,    0,   22,    0,   18,
    0,    0,    0,   31,    0,   15,   26,   30,    0,    0,
   54,   55,   51,   56,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   39,    0,   34,    0,
    0,   24,    0,    0,    0,    0,   50,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   32,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   38,   64,   65,    0,    0,    0,    0,    0,    0,
   40,   41,   58,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   60,    0,    0,    0,
    0,    0,    0,    0,    0,   59,    0,   52,   42,   36,
    0,   35,   45,   46,    0,    0,   48,    0,    0,    0,
    0,    0,   37,
};
static const YYINT yydgoto[] = {                          1,
    4,    5,   26,   14,   17,   18,    6,   24,   27,   36,
   28,   39,   29,   57,   58,   59,   60,  132,   65,  135,
  140,   68,  119,
};
static const YYINT yysindex[] = {                         0,
 -261,    0, -239,    0, -253,    0,    0,    0,    0,    0,
    0,  -19,    0, -218, -232,  -22,   -5,    0,    0,    0,
    0, -253, -205,    0,    0,  -19,   24,    0,   22,    0,
 -180,  -42, -253,    0, -253,    0,    0,    0,  869,   27,
    0,    0,    0,    0,  869,  932,  -31, -169, -169,  -31,
  -31,  -31,  932,  932,  -31,  932,    0,  -27,    0,  396,
   25,    0, -168,  423,  -87,  -78,    0,   50,   54,   23,
   23,   23,  648,   83,   23,  434,    0,  932,  932,  932,
  932,  932,  932,  932,  932,  932,  932,  932,  932,  932,
  796,    0,    0,    0,  932,  932,  932,  932,  869,  932,
    0,    0,    0,   85,   40,   40,  605,  648,   85,   40,
   40,   70,   70,   83,   83,   83,    0,  576,   15,  576,
  461,  472,  503, -155,  358,    0,  932,    0,    0,    0,
  869,    0,    0,    0,  932,  576,    0,  539,  932, -130,
  576,  869,    0,
};
static const YYINT yyrindex[] = {                         0,
  -99,    0,  -99,    0,    0,    0,    0,    0,    0,    0,
    0, -126,    0,    0,   77,  -58,    0,    0,    0,    0,
    0,   96,    0,    0,    0, -126,    0,    0,  105,    0,
    0,   -5,    0,    0,  681,    0,    0,    0,   28,    0,
    0,    0,    0,    0,    0,    0,    0,   89,   89,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  550,    0,    0,    0,   -9,    0,    0,    0,    0,    2,
   31,   59,  937,   97,  -35,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  840,  730,  756,  917, 1059,  856,  802,
  812,  686,  721,  125,  163,  292,    0,   26,    0,  783,
    0,    0,    0, -111,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   64,    0, -112,    0,    0,
 -101,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  145,  135,    0,    0,   14,    0,    0,    0,
  131,    0,  130,  139,    0,   12, 1141,    0, 1104,    0,
    0,  128,    0,
};
#define YYTABLESIZE 1328
static const YYINT yytable[] = {                         53,
   16,   53,   53,   96,   53,   53,   53,   53,   53,   53,
   55,   53,   96,   47,    2,    3,    7,   22,    8,    9,
   10,   11,   13,   53,   53,   53,   53,   57,   57,   23,
   57,   57,   57,   57,   57,   57,    2,   57,   66,   66,
   15,   66,   66,   66,   66,   66,   66,   16,   66,   57,
   57,   57,   57,   25,   30,  126,   63,   53,  127,   97,
   66,   66,   66,   66,   32,   33,   82,   67,   67,   82,
   67,   67,   67,   67,   67,   67,   90,   67,   34,   91,
   35,   88,   87,   57,   86,   62,   89,   67,   53,   67,
   67,   67,   67,   98,   66,   62,   62,   77,   62,   62,
   62,   62,   62,   62,   83,   62,   90,   83,  101,   91,
  124,   88,  102,   96,   57,   96,   89,   62,   62,   62,
   62,   90,   91,   67,   91,   66,   88,   87,  131,   86,
  142,   89,    8,   61,   61,    4,   21,   61,   61,   61,
   61,   61,  137,   61,   84,   29,   85,   49,   43,   12,
   47,   62,   33,  143,   67,   61,   61,   61,   61,   44,
   31,   68,   68,   38,   40,   68,   68,   68,   68,   68,
   37,   68,   27,   27,   27,   27,   69,    0,    0,    0,
    0,    0,   62,   68,   68,   68,   68,  100,    0,   61,
   93,   94,   95,    0,    0,    0,    0,    0,    0,   69,
   69,   27,    0,   69,   69,   69,   69,   69,    0,   69,
    0,    0,    0,    0,    0,    0,    0,   68,    0,    0,
   61,   69,   69,   69,   69,   53,    0,   43,   53,    0,
   53,   53,   53,   53,   19,   20,   21,    0,    0,    0,
    0,    0,   53,   53,   53,   53,   53,   53,   68,    0,
    0,   57,    0,    2,   57,   69,    0,   57,   57,   57,
    0,    0,   66,    0,    0,   66,    0,    0,   66,   66,
   66,   57,   57,   57,    0,    0,    0,    0,    0,    0,
    0,    0,   66,   66,   66,    0,   69,    0,    0,    0,
    0,   67,    0,    0,   67,    0,    0,   67,   67,   67,
    0,    0,   93,   94,   95,    0,    0,    0,    0,    0,
    0,   67,   67,   67,    0,    0,    0,    0,    0,   62,
    0,    0,   62,    0,    0,   62,   62,   62,   70,   70,
    0,    0,   70,   70,   70,   70,   70,    0,   70,   62,
   62,   62,    0,    0,    0,    0,    0,    0,    0,    0,
   70,   70,   70,   70,    0,    0,    0,   61,    0,    0,
   61,    0,    0,   61,   61,   61,   79,   80,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   61,   61,   61,
    0,    0,    0,    0,   70,   68,    0,    0,   68,    0,
    0,   68,   68,   68,   90,   82,    0,   91,    0,   88,
   87,    0,   86,    0,   89,   68,   68,   68,    0,    0,
    0,    0,    0,    0,    0,   70,    0,   84,   83,   85,
    0,    0,    0,   69,    0,    0,   69,    0,    0,   69,
   69,   69,   90,   82,    0,   91,    0,   88,   87,    0,
   86,    0,   89,   69,   69,   69,    0,    0,    0,    0,
    0,    0,    0,    0,   92,   84,   83,   85,    0,   90,
   82,    0,   91,    0,   88,   87,    0,   86,    0,   89,
   90,   82,    0,   91,  103,   88,   87,    0,   86,    0,
   89,   81,   84,   83,   85,    0,    0,    0,    0,    0,
    0,    0,    0,   84,   83,   85,    0,   90,   82,    0,
   91,    0,   88,   87,    0,   86,    0,   89,   90,   82,
    0,   91,    0,   88,   87,    0,   86,    0,   89,   81,
   84,   83,   85,    0,    0,    0,    0,    0,    0,    0,
  129,   84,   83,   85,    0,    0,    0,    0,    0,   90,
   82,    0,   91,    0,   88,   87,   81,   86,    0,   89,
    0,    0,   70,  128,    0,   70,    0,   81,   70,   70,
   70,  130,   84,   83,   85,    0,    0,    0,    0,    0,
    0,    0,   70,   70,   70,   90,   82,    0,   91,    0,
   88,   87,    0,   86,   81,   89,   57,   57,    0,   57,
    0,   57,   57,    0,   57,   81,   57,    0,   84,   83,
   85,    0,    0,    0,    0,    0,    0,    0,   57,   57,
   57,   57,   90,   82,    0,   91,    0,   88,   87,    0,
   86,    0,   89,    0,  133,  134,   81,    0,    0,    0,
    0,    0,    0,    0,    0,   84,   83,   85,   78,   79,
   80,   90,   82,    0,   91,    0,   88,   87,    0,   86,
    0,   89,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   81,    0,   84,   83,   85,    0,    0,    0,
    0,    0,    0,   57,    0,    0,   78,   79,   80,    0,
    0,    0,    0,    0,   90,    0,   99,   91,    0,   88,
   87,    0,   86,    0,   89,    0,    0,    0,    0,   81,
    0,    0,    0,   78,   79,   80,    0,   84,   83,   85,
    0,    0,    0,    0,   78,   79,   80,    0,   23,    0,
   23,    0,   23,   72,    0,   23,   72,    0,   72,   72,
   72,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   78,   79,   80,   72,   72,   72,   72,    0,    0,
    0,    0,   78,   79,   80,    0,    0,    0,   71,    0,
    0,   71,    0,   71,   71,   71,    0,   75,    0,    0,
   75,    0,    0,   75,    0,    0,    0,    0,   72,   71,
   71,   71,   71,   78,   79,   80,    0,    0,   75,   75,
   75,   75,    0,   76,    0,    0,   76,    0,    0,   76,
    0,    0,    0,   23,    0,   23,   23,  139,    0,   72,
    0,    0,    0,   71,   76,   76,   76,   76,    0,   78,
   79,   80,   75,   81,    0,    0,   81,    0,    0,    0,
   57,   57,   57,   52,    0,   56,  117,   55,    0,   73,
   54,   81,   73,    0,   71,   73,    0,    0,   76,   74,
    0,    0,   74,   75,    0,   74,   78,   79,   80,    0,
   73,   73,   73,   73,    0,    0,    0,    0,    0,    0,
   74,   74,   74,   74,    0,   81,    0,   78,    0,   76,
   78,    0,    0,   78,    0,   78,   79,   80,    0,    0,
    0,    0,    0,   77,   73,    0,   77,    0,   78,   77,
   78,    0,    0,    0,   74,    0,   52,    0,   56,    0,
   55,    0,    0,   54,   77,    0,   77,    0,    0,    0,
    0,   53,    0,    0,    0,   73,    0,    0,   78,   79,
   80,    0,   78,    0,    0,   74,    0,   23,   23,   23,
   23,   23,    0,   23,    0,   23,   72,    0,   77,   72,
   23,   23,   72,   72,   72,    0,    0,   80,   23,   23,
   80,    0,    0,   78,    0,    0,   72,   72,   72,   52,
    0,   56,    0,   55,   63,   80,   54,   63,    0,   77,
   63,   71,    0,    0,   71,    0,    0,   71,   71,   71,
   75,   35,    0,   75,   53,   63,   75,   75,   75,    0,
    0,   71,   71,   71,    0,    0,    0,    0,    0,   80,
   75,   75,   75,    0,    0,    0,   76,    0,    0,   76,
    0,    0,   76,   76,   76,    0,    0,    0,    0,   63,
    0,    0,    0,    0,    0,    0,   76,   76,   76,    0,
   80,    0,    0,   81,    0,    0,   81,    0,    0,   81,
   81,   81,   41,   42,   43,   44,    0,   53,    0,    0,
   63,    0,   73,    0,    0,   73,    0,    0,   73,   73,
   73,    0,   74,   50,   51,   74,    0,    0,   74,   74,
   74,    0,   73,   73,   73,    0,    0,    0,    0,    0,
    0,    0,   74,   74,   74,    0,   79,    0,    0,   79,
   78,    0,   79,   78,    0,    0,   78,   78,   78,    0,
    0,    0,    0,    0,    0,    0,   77,   79,    0,   77,
   78,    0,   77,   77,   77,   41,   42,   43,   44,   45,
    0,   46,    0,   47,    0,    0,   77,    0,   48,   49,
    0,    0,   61,    0,    0,    0,   50,   51,   61,    0,
   66,   79,    0,   70,   71,   72,    0,    0,   75,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   80,    0,    0,
   80,    0,   79,   80,   80,   80,   64,    0,   41,   42,
   43,   44,    0,   73,   74,    0,   76,   63,    0,    0,
   63,    0,   61,   63,   63,   63,    0,    0,    0,   50,
   51,    0,    0,    0,    0,    0,    0,    0,  104,  105,
  106,  107,  108,  109,  110,  111,  112,  113,  114,  115,
  116,  118,    0,    0,   61,  120,  121,  122,  123,    0,
  125,    0,    0,    0,    0,   61,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  136,    0,    0,
    0,    0,    0,    0,    0,  138,    0,    0,    0,  141,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   79,
    0,    0,   79,    0,    0,   79,   79,   79,
};
static const YYINT yycheck[] = {                         35,
   59,   37,   38,   91,   40,   41,   42,   43,   44,   45,
   42,   47,   91,  125,  276,  277,    3,   40,  272,  273,
  274,  275,   42,   59,   60,   61,   62,   37,   38,   16,
   40,   41,   42,   43,   44,   45,  276,   47,   37,   38,
  259,   40,   41,   42,   43,   44,   45,  280,   47,   59,
   60,   61,   62,   59,  260,   41,   45,   93,   44,   35,
   59,   60,   61,   62,   41,   44,   41,   37,   38,   44,
   40,   41,   42,   43,   44,   45,   37,   47,  259,   40,
  123,   42,   43,   93,   45,   59,   47,  257,  124,   59,
   60,   61,   62,  262,   93,   37,   38,  125,   40,   41,
   42,   43,   44,   45,   41,   47,   37,   44,   59,   40,
   99,   42,   59,   91,  124,   91,   47,   59,   60,   61,
   62,   37,   40,   93,   40,  124,   42,   43,  284,   45,
  261,   47,  259,   37,   38,   59,   41,   41,   42,   43,
   44,   45,  131,   47,   60,   41,   62,   59,  261,    5,
  262,   93,  125,  142,  124,   59,   60,   61,   62,  261,
   26,   37,   38,   33,   35,   41,   42,   43,   44,   45,
   32,   47,  272,  273,  274,  275,   49,   -1,   -1,   -1,
   -1,   -1,  124,   59,   60,   61,   62,  266,   -1,   93,
  278,  279,  280,   -1,   -1,   -1,   -1,   -1,   -1,   37,
   38,  260,   -1,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   93,   -1,   -1,
  124,   59,   60,   61,   62,  261,   -1,  259,  264,   -1,
  266,  267,  268,  269,  257,  258,  259,   -1,   -1,   -1,
   -1,   -1,  278,  279,  280,  281,  282,  283,  124,   -1,
   -1,  261,   -1,  276,  264,   93,   -1,  267,  268,  269,
   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,
  269,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,   -1,  124,   -1,   -1,   -1,
   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,
   -1,   -1,  278,  279,  280,   -1,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   37,   38,
   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,  281,
  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,  261,   -1,   -1,
  264,   -1,   -1,  267,  268,  269,  282,  283,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,
   -1,   -1,   -1,   -1,   93,  261,   -1,   -1,  264,   -1,
   -1,  267,  268,  269,   37,   38,   -1,   40,   -1,   42,
   43,   -1,   45,   -1,   47,  281,  282,  283,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   -1,   60,   61,   62,
   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,   37,   38,   -1,   40,   -1,   42,   43,   -1,
   45,   -1,   47,  281,  282,  283,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,   37,
   38,   -1,   40,   -1,   42,   43,   -1,   45,   -1,   47,
   37,   38,   -1,   40,   41,   42,   43,   -1,   45,   -1,
   47,  124,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   60,   61,   62,   -1,   37,   38,   -1,
   40,   -1,   42,   43,   -1,   45,   -1,   47,   37,   38,
   -1,   40,   -1,   42,   43,   -1,   45,   -1,   47,  124,
   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   37,
   38,   -1,   40,   -1,   42,   43,  124,   45,   -1,   47,
   -1,   -1,  261,   93,   -1,  264,   -1,  124,  267,  268,
  269,   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,   37,   38,   -1,   40,   -1,
   42,   43,   -1,   45,  124,   47,   37,   38,   -1,   40,
   -1,   42,   43,   -1,   45,  124,   47,   -1,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,   60,
   61,   62,   37,   38,   -1,   40,   -1,   42,   43,   -1,
   45,   -1,   47,   -1,  267,  268,  124,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   60,   61,   62,  281,  282,
  283,   37,   38,   -1,   40,   -1,   42,   43,   -1,   45,
   -1,   47,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  124,   -1,   60,   61,   62,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,  281,  282,  283,   -1,
   -1,   -1,   -1,   -1,   37,   -1,  264,   40,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,  124,
   -1,   -1,   -1,  281,  282,  283,   -1,   60,   61,   62,
   -1,   -1,   -1,   -1,  281,  282,  283,   -1,   38,   -1,
   40,   -1,   42,   38,   -1,   45,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,   59,   60,   61,   62,   -1,   -1,
   -1,   -1,  281,  282,  283,   -1,   -1,   -1,   38,   -1,
   -1,   41,   -1,   43,   44,   45,   -1,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,   -1,   -1,   93,   59,
   60,   61,   62,  281,  282,  283,   -1,   -1,   59,   60,
   61,   62,   -1,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,   -1,   -1,  123,   -1,  125,  126,  269,   -1,  124,
   -1,   -1,   -1,   93,   59,   60,   61,   62,   -1,  281,
  282,  283,   93,   41,   -1,   -1,   44,   -1,   -1,   -1,
  281,  282,  283,   38,   -1,   40,   41,   42,   -1,   38,
   45,   59,   41,   -1,  124,   44,   -1,   -1,   93,   38,
   -1,   -1,   41,  124,   -1,   44,  281,  282,  283,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   60,   61,   62,   -1,   93,   -1,   38,   -1,  124,
   41,   -1,   -1,   44,   -1,  281,  282,  283,   -1,   -1,
   -1,   -1,   -1,   38,   93,   -1,   41,   -1,   59,   44,
   61,   -1,   -1,   -1,   93,   -1,   38,   -1,   40,   -1,
   42,   -1,   -1,   45,   59,   -1,   61,   -1,   -1,   -1,
   -1,  126,   -1,   -1,   -1,  124,   -1,   -1,  281,  282,
  283,   -1,   93,   -1,   -1,  124,   -1,  257,  258,  259,
  260,  261,   -1,  263,   -1,  265,  261,   -1,   93,  264,
  270,  271,  267,  268,  269,   -1,   -1,   41,  278,  279,
   44,   -1,   -1,  124,   -1,   -1,  281,  282,  283,   38,
   -1,   40,   -1,   42,   38,   59,   45,   41,   -1,  124,
   44,  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,
  261,  123,   -1,  264,  126,   59,  267,  268,  269,   -1,
   -1,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,   93,
  281,  282,  283,   -1,   -1,   -1,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   93,
   -1,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,   -1,
  124,   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,  257,  258,  259,  260,   -1,  126,   -1,   -1,
  124,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,
  269,   -1,  261,  278,  279,  264,   -1,   -1,  267,  268,
  269,   -1,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,   -1,   38,   -1,   -1,   41,
  261,   -1,   44,  264,   -1,   -1,  267,  268,  269,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  261,   59,   -1,  264,
  281,   -1,  267,  268,  269,  257,  258,  259,  260,  261,
   -1,  263,   -1,  265,   -1,   -1,  281,   -1,  270,  271,
   -1,   -1,   39,   -1,   -1,   -1,  278,  279,   45,   -1,
   47,   93,   -1,   50,   51,   52,   -1,   -1,   55,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,   -1,   -1,
  264,   -1,  124,  267,  268,  269,   46,   -1,  257,  258,
  259,  260,   -1,   53,   54,   -1,   56,  261,   -1,   -1,
  264,   -1,   99,  267,  268,  269,   -1,   -1,   -1,  278,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   78,   79,
   80,   81,   82,   83,   84,   85,   86,   87,   88,   89,
   90,   91,   -1,   -1,  131,   95,   96,   97,   98,   -1,
  100,   -1,   -1,   -1,   -1,  142,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  127,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  135,   -1,   -1,   -1,  139,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 288
#define YYUNDFTOKEN 314
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","REAL","ID","STR",
"DO","WHILE","IF","THEN","FOR","IN","UPTO","DOWNTO","STEP","BREAK","CONTINUE",
"VOID","INTEGER","STRING","NUMBER","CONST","PUBLIC","INCR","DECR","ATR","NE",
"GE","LE","ELSE","IFX","UMINUS","PONT","ENDE",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file :",
"file : file stmt",
"stmt : pubOuConstOrNone tipo astOrNon ID initOrNon ';'",
"initOrNon :",
"initOrNon : init",
"pubOuConstOrNone : cnstOrNon",
"pubOuConstOrNone : PUBLIC cnstOrNon",
"astOrNon :",
"astOrNon : '*'",
"tipo : INTEGER",
"tipo : STRING",
"tipo : NUMBER",
"tipo : VOID",
"init : ATR init1",
"init : ATR '(' prmtsOrNon ')' crpOrNon",
"init1 :",
"init1 : INT",
"init1 : cnstOrNon STR",
"init1 : REAL",
"init1 : ID",
"prmtsOrNon :",
"prmtsOrNon : parametros",
"prmtOrNon :",
"prmtOrNon : parametro ';'",
"crpOrNon :",
"crpOrNon : corpo",
"cnstOrNon :",
"cnstOrNon : CONST",
"parametros : parametro",
"parametros : parametro ',' parametros",
"parametro : tipo astOrNon ID",
"corpo : '{' prmtOrNon instrOrNon '}'",
"instrOrNon :",
"instrOrNon : instrucao",
"instrucao : IF expressao THEN instrucao els",
"instrucao : DO instrucao WHILE expressao ';'",
"instrucao : FOR lvalue IN expressao upOrDown expressao stp DO instrucao",
"instrucao : expressao ';'",
"instrucao : corpo",
"instrucao : BREAK inteirOrNon ';'",
"instrucao : CONTINUE inteirOrNon ';'",
"instrucao : lvalue '#' expressao ';'",
"stp :",
"stp : STEP expressao",
"upOrDown : UPTO",
"upOrDown : DOWNTO",
"els :",
"els : ELSE instrucao",
"inteirOrNon :",
"inteirOrNon : INT",
"lvalue : ID",
"lvalue : lvalue '[' expressao ']'",
"lvalue : '*' lvalue",
"expressao : INT",
"expressao : REAL",
"expressao : STR",
"expressao : lvalue",
"expressao : '(' expressao ')'",
"expressao : expressao '(' args ')'",
"expressao : expressao '(' ')'",
"expressao : '-' expressao",
"expressao : '&' lvalue",
"expressao : '~' expressao",
"expressao : lvalue INCR",
"expressao : lvalue DECR",
"expressao : INCR lvalue",
"expressao : DECR lvalue",
"expressao : expressao '*' expressao",
"expressao : expressao '/' expressao",
"expressao : expressao '%' expressao",
"expressao : expressao '+' expressao",
"expressao : expressao '-' expressao",
"expressao : expressao '<' expressao",
"expressao : expressao '>' expressao",
"expressao : expressao GE expressao",
"expressao : expressao LE expressao",
"expressao : expressao '=' expressao",
"expressao : expressao NE expressao",
"expressao : expressao '&' expressao",
"expressao : expressao '|' expressao",
"expressao : lvalue ATR expressao",
"args : expressao",
"args : args ',' expressao",

};
#endif

#if YYDEBUG
int      yydebug;
#endif

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;
int      yynerrs;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 200

typedef struct {
    unsigned stacksize;
    YYINT    *s_base;
    YYINT    *s_mark;
    YYINT    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 172 "diy.y"
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 621 "y.tab.c"

#if YYDEBUG
#include <stdio.h>	/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    YYINT *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return YYENOMEM;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (YYINT *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return YYENOMEM;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return YYENOMEM;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yym = 0;
    yyn = 0;
    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        yychar = YYLEX;
        if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if (((yyn = yysindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if (((yyn = yyrindex[yystate]) != 0) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag != 0) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab; /* redundant goto avoids 'unused label' warning */
yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if (((yyn = yysindex[*yystack.s_mark]) != 0) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == YYEOF) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym > 0)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);

    switch (yyn)
    {
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            yychar = YYLEX;
            if (yychar < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                if ((yys = yyname[YYTRANSLATE(yychar)]) == NULL) yys = yyname[YYUNDFTOKEN];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if (((yyn = yygindex[yym]) != 0) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == (YYINT) yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM) goto yyoverflow;
    *++yystack.s_mark = (YYINT) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    YYERROR_CALL("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
