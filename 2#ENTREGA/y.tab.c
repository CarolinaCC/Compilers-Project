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
    9,    9,   10,   10,    7,    7,   11,   11,   13,   12,
   14,   14,   15,   15,   16,   16,   16,   16,   16,   16,
   16,   16,   21,   21,   20,   20,   18,   18,   22,   22,
   19,   19,   19,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   23,   23,
};
static const YYINT yylen[] = {                            2,
    0,    2,    6,    0,    1,    1,    2,    0,    1,    1,
    1,    1,    1,    2,    4,    0,    1,    2,    1,    1,
    0,    1,    0,    1,    0,    1,    1,    3,    3,    4,
    2,    3,    1,    2,    5,    5,    9,    2,    1,    3,
    3,    4,    0,    2,    1,    1,    0,    2,    0,    1,
    1,    4,    2,    1,    1,    1,    1,    3,    4,    3,
    2,    2,    2,    2,    2,    2,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    3,
};
static const YYINT yydefred[] = {                         1,
    0,   26,    0,    2,    0,    6,    7,   13,   10,   11,
   12,    0,    9,    0,    0,    0,    0,    0,    5,   17,
   19,   20,    0,   14,    0,    0,   22,    0,    3,   18,
    0,    0,    0,   29,    0,   15,   24,   28,    0,    0,
    0,   54,   55,   51,   56,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   39,    0,    0,
    0,    0,   32,    0,    0,    0,    0,   50,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   30,   34,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   38,   64,   65,    0,    0,    0,    0,
    0,    0,   40,   41,   58,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   60,    0,
    0,    0,    0,    0,    0,    0,    0,   59,    0,   52,
   42,   36,    0,   35,   45,   46,    0,    0,   48,    0,
    0,    0,    0,    0,   37,
};
static const YYINT yydgoto[] = {                          1,
    4,    5,   25,   14,   18,   19,    6,   24,   26,   36,
   27,   58,   28,   40,   59,   60,   61,  134,   66,  137,
  142,   69,  121,
};
static const YYINT yysindex[] = {                         0,
 -254,    0, -260,    0, -124,    0,    0,    0,    0,    0,
    0,   -1,    0, -211,  -39, -239, -124,   -4,    0,    0,
    0,    0, -201,    0,   -1,   24,    0,   22,    0,    0,
 -180,  -42, -124,    0, -124,    0,    0,    0,   27,  869,
 -124,    0,    0,    0,    0,  869,  941,  -31, -169, -169,
  -31,  -31,  -31,  941,  941,  -31,  941,    0,  -27,  869,
  396,   25,    0, -168,  423,  -87,  -77,    0,   50,   54,
   23,   23,   23,  648,   83,   23,  434,    0,    0,  941,
  941,  941,  941,  941,  941,  941,  941,  941,  941,  941,
  941,  941,  988,    0,    0,    0,  941,  941,  941,  941,
  869,  941,    0,    0,    0,   85,   40,   40,  605,  648,
   85,   40,   40,   70,   70,   83,   83,   83,    0,  576,
   13,  576,  461,  472,  503, -155,  358,    0,  941,    0,
    0,    0,  869,    0,    0,    0,  941,  576,    0,  539,
  941, -130,  576,  869,    0,
};
static const YYINT yyrindex[] = {                         0,
  -99,    0,  -99,    0,    0,    0,    0,    0,    0,    0,
    0, -126,    0,    0,   77,  -46,   96,    0,    0,    0,
    0,    0,    0,    0, -126,    0,    0,  105,    0,    0,
    0,   94,    0,    0,    0,    0,    0,    0,    0,    0,
  932,    0,    0,    0,    0,    0,    0,    0,  101,  101,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   36,
    0,  550,    0,    0,    0,   -9,    0,    0,    0,    0,
    2,   31,   59, 1009,   97,  -35,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  840,  730,  756,  917, 1018,
  856,  802,  812,  686,  721,  125,  163,  292,    0,   26,
    0, 1056,    0,    0,    0,  681,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   64,    0,  -97,
    0,    0,  -96,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,  166,  152,    0,    0,   14,    0,    0,    0,
  145,  147,  -20,  139,  121,   10, 1208,    0,  872,    0,
    0,  132,    0,
};
#define YYTABLESIZE 1349
static const YYINT yytable[] = {                         53,
   17,   53,   53,   98,   53,   53,   53,   53,   53,   53,
   56,   53,   16,   98,   39,    2,    7,   20,   21,   22,
   39,    2,    3,   53,   53,   53,   53,   57,   57,   23,
   57,   57,   57,   57,   57,   57,    2,   57,   66,   66,
   13,   66,   66,   66,   66,   66,   66,   15,   66,   57,
   57,   57,   57,  128,   29,   64,  129,   53,   30,   99,
   66,   66,   66,   66,   32,   33,   82,   67,   67,   82,
   67,   67,   67,   67,   67,   67,   92,   67,   34,   93,
   35,   90,   89,   57,   88,   41,   91,   68,   53,   67,
   67,   67,   67,  100,   66,   62,   62,   78,   62,   62,
   62,   62,   62,   62,   83,   62,   92,   83,  103,   93,
  126,   90,  104,   98,   57,   98,   91,   62,   62,   62,
   62,   92,   93,   67,   93,   66,   90,   89,  133,   88,
  144,   91,    8,   61,   61,    4,   21,   61,   61,   61,
   61,   61,  139,   61,   86,   27,   87,    8,    9,   10,
   11,   62,   23,  145,   67,   61,   61,   61,   61,   49,
   33,   68,   68,   43,   44,   68,   68,   68,   68,   68,
   12,   68,   25,   25,   25,   25,   31,   38,   37,   63,
   79,   70,   62,   68,   68,   68,   68,    0,  102,   61,
   95,   96,   97,    0,    0,    0,    0,    0,    0,   69,
   69,    0,    0,   69,   69,   69,   69,   69,    0,   69,
    0,    0,    0,   25,    0,    0,    0,   68,    0,    0,
   61,   69,   69,   69,   69,   53,    0,   44,   53,    0,
   53,   53,   53,   53,    0,    0,    0,    0,    0,    0,
   16,    0,   53,   53,   53,   53,   53,   53,   68,    0,
    0,   57,    0,    0,   57,   69,    0,   57,   57,   57,
    0,    0,   66,    0,    0,   66,    0,    0,   66,   66,
   66,   57,   57,   57,    0,    0,    0,    0,    0,    0,
    0,    0,   66,   66,   66,    0,   69,    0,    0,    0,
    0,   67,    0,    0,   67,    0,    0,   67,   67,   67,
    0,    0,   95,   96,   97,    0,    0,    0,    0,    0,
    0,   67,   67,   67,    0,    0,    0,    0,    0,   62,
    0,    0,   62,    0,    0,   62,   62,   62,   70,   70,
    0,    0,   70,   70,   70,   70,   70,    0,   70,   62,
   62,   62,    0,    0,    0,    0,    0,    0,    0,    0,
   70,   70,   70,   70,    0,    0,    0,   61,    0,    0,
   61,    0,    0,   61,   61,   61,   81,   82,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   61,   61,   61,
    0,    0,    0,    0,   70,   68,    0,    0,   68,    0,
    0,   68,   68,   68,   92,   84,    0,   93,    0,   90,
   89,    0,   88,    0,   91,   68,   68,   68,    0,    0,
    0,    0,    0,    0,    0,   70,    0,   86,   85,   87,
    0,    0,    0,   69,    0,    0,   69,    0,    0,   69,
   69,   69,   92,   84,    0,   93,    0,   90,   89,    0,
   88,    0,   91,   69,   69,   69,    0,    0,    0,    0,
    0,    0,    0,    0,   94,   86,   85,   87,    0,   92,
   84,    0,   93,    0,   90,   89,    0,   88,    0,   91,
   92,   84,    0,   93,  105,   90,   89,    0,   88,    0,
   91,   83,   86,   85,   87,    0,    0,    0,    0,    0,
    0,    0,    0,   86,   85,   87,    0,   92,   84,    0,
   93,    0,   90,   89,    0,   88,    0,   91,   92,   84,
    0,   93,    0,   90,   89,    0,   88,    0,   91,   83,
   86,   85,   87,    0,    0,    0,    0,    0,    0,    0,
  131,   86,   85,   87,    0,    0,    0,    0,    0,   92,
   84,    0,   93,    0,   90,   89,   83,   88,    0,   91,
    0,    0,   70,  130,    0,   70,    0,   83,   70,   70,
   70,  132,   86,   85,   87,    0,    0,    0,    0,    0,
    0,    0,   70,   70,   70,   92,   84,    0,   93,    0,
   90,   89,    0,   88,   83,   91,   57,   57,    0,   57,
    0,   57,   57,    0,   57,   83,   57,    0,   86,   85,
   87,    0,    0,    0,    0,    0,    0,    0,   57,   57,
   57,   57,   92,   84,    0,   93,    0,   90,   89,    0,
   88,    0,   91,    0,  135,  136,   83,    0,    0,    0,
    0,    0,    0,    0,    0,   86,   85,   87,   80,   81,
   82,   92,   84,    0,   93,    0,   90,   89,    0,   88,
    0,   91,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   83,    0,   86,   85,   87,    0,    0,    0,
    0,    0,    0,   57,    0,    0,   80,   81,   82,    0,
    0,    0,    0,    0,   92,    0,  101,   93,    0,   90,
   89,    0,   88,    0,   91,    0,    0,    0,    0,   83,
    0,    0,    0,   80,   81,   82,    0,   86,   85,   87,
    0,    0,    0,    0,   80,   81,   82,    0,   47,    0,
   47,    0,   47,   72,    0,   47,   72,    0,   72,   72,
   72,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   80,   81,   82,   72,   72,   72,   72,    0,    0,
    0,    0,   80,   81,   82,    0,    0,    0,   71,    0,
    0,   71,    0,   71,   71,   71,    0,   75,    0,    0,
   75,    0,    0,   75,    0,    0,    0,    0,   72,   71,
   71,   71,   71,   80,   81,   82,    0,    0,   75,   75,
   75,   75,    0,   76,    0,    0,   76,    0,    0,   76,
    0,    0,    0,   47,    0,   47,   47,  141,    0,   72,
    0,    0,    0,   71,   76,   76,   76,   76,    0,   80,
   81,   82,   75,    0,    0,    0,    0,    0,    0,    0,
   57,   57,   57,    0,    0,    0,    0,    0,    0,   73,
    0,    0,   73,    0,   71,   73,    0,    0,   76,   74,
    0,    0,   74,   75,    0,   74,   80,   81,   82,    0,
   73,   73,   73,   73,    0,    0,    0,    0,    0,    0,
   74,   74,   74,   74,    0,    0,    0,   78,    0,   76,
   78,    0,    0,   78,    0,   80,   81,   82,    0,    0,
    0,    0,    0,   77,   73,    0,   77,    0,   78,   77,
   78,    0,    0,    0,   74,    0,   53,    0,   57,    0,
   56,   62,    0,   55,   77,    0,   77,   62,    0,   67,
    0,    0,   71,   72,   73,   73,    0,   76,   80,   81,
   82,   62,   78,    0,    0,   74,    0,   47,   47,   47,
   47,   47,   47,   47,    0,   47,   72,    0,   77,   72,
   47,   47,   72,   72,   72,    0,    0,   80,   47,   47,
   80,    0,    0,   78,    0,    0,   72,   72,   72,   31,
    0,   31,   62,   31,    0,   80,   31,    0,   53,   77,
   57,   71,   56,    0,   71,   55,    0,   71,   71,   71,
   75,   35,    0,   75,   54,    0,   75,   75,   75,    0,
    0,   71,   71,   71,   62,    0,    0,    0,    0,   80,
   75,   75,   75,    0,    0,   62,   76,    0,    0,   76,
    0,    0,   76,   76,   76,   53,    0,   57,  119,   56,
    0,    0,   55,    0,    0,    0,   76,   76,   76,    0,
   80,    0,    0,    0,    0,    0,   63,    0,    0,   63,
    0,    0,   63,    0,   31,   79,    0,   31,   79,    0,
    0,   79,   73,    0,    0,   73,   54,   63,   73,   73,
   73,    0,   74,    0,    0,   74,   79,    0,   74,   74,
   74,    0,   73,   73,   73,    0,    0,    0,    0,    0,
    0,    0,   74,   74,   74,    0,   81,    0,    0,   81,
   78,   63,    0,   78,    0,    0,   78,   78,   78,    0,
   79,    0,    0,   54,   81,    0,   77,    0,    0,   77,
   78,    0,   77,   77,   77,   42,   43,   44,   45,   46,
    0,   47,   63,   48,    0,    0,   77,    0,   49,   50,
    0,   79,    0,    0,    0,    0,   51,   52,   81,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   80,    0,    0,
   80,    0,    0,   80,   80,   80,    0,    0,   31,   31,
   31,   31,   31,    0,   31,    0,   31,   42,   43,   44,
   45,   31,   31,    0,    0,    0,    0,    0,    0,   31,
   31,    0,    0,    0,    0,    0,    0,    0,   51,   52,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   42,   43,   44,   45,    0,    0,
    0,    0,    0,    0,   65,    0,    0,    0,    0,    0,
    0,   74,   75,    0,   77,   51,   52,    0,    0,   63,
    0,    0,   63,    0,    0,   63,   63,   63,   79,    0,
    0,   79,    0,    0,   79,   79,   79,  106,  107,  108,
  109,  110,  111,  112,  113,  114,  115,  116,  117,  118,
  120,    0,    0,    0,  122,  123,  124,  125,    0,  127,
    0,    0,    0,    0,    0,    0,   81,    0,    0,   81,
    0,    0,   81,   81,   81,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  138,    0,    0,    0,
    0,    0,    0,    0,  140,    0,    0,    0,  143,
};
static const YYINT yycheck[] = {                         35,
   40,   37,   38,   91,   40,   41,   42,   43,   44,   45,
   42,   47,   59,   91,   35,  276,    3,  257,  258,  259,
   41,  276,  277,   59,   60,   61,   62,   37,   38,   16,
   40,   41,   42,   43,   44,   45,  276,   47,   37,   38,
   42,   40,   41,   42,   43,   44,   45,  259,   47,   59,
   60,   61,   62,   41,   59,   46,   44,   93,  260,   35,
   59,   60,   61,   62,   41,   44,   41,   37,   38,   44,
   40,   41,   42,   43,   44,   45,   37,   47,  259,   40,
  123,   42,   43,   93,   45,   59,   47,  257,  124,   59,
   60,   61,   62,  262,   93,   37,   38,  125,   40,   41,
   42,   43,   44,   45,   41,   47,   37,   44,   59,   40,
  101,   42,   59,   91,  124,   91,   47,   59,   60,   61,
   62,   37,   40,   93,   40,  124,   42,   43,  284,   45,
  261,   47,  259,   37,   38,   59,   41,   41,   42,   43,
   44,   45,  133,   47,   60,   41,   62,  272,  273,  274,
  275,   93,   59,  144,  124,   59,   60,   61,   62,   59,
  125,   37,   38,  261,  261,   41,   42,   43,   44,   45,
    5,   47,  272,  273,  274,  275,   25,   33,   32,   41,
   60,   50,  124,   59,   60,   61,   62,   -1,  266,   93,
  278,  279,  280,   -1,   -1,   -1,   -1,   -1,   -1,   37,
   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,  260,   -1,   -1,   -1,   93,   -1,   -1,
  124,   59,   60,   61,   62,  261,   -1,  259,  264,   -1,
  266,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,
  280,   -1,  278,  279,  280,  281,  282,  283,  124,   -1,
   -1,  261,   -1,   -1,  264,   93,   -1,  267,  268,  269,
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
  282,  283,   93,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  281,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   38,
   -1,   -1,   41,   -1,  124,   44,   -1,   -1,   93,   38,
   -1,   -1,   41,  124,   -1,   44,  281,  282,  283,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   59,   60,   61,   62,   -1,   -1,   -1,   38,   -1,  124,
   41,   -1,   -1,   44,   -1,  281,  282,  283,   -1,   -1,
   -1,   -1,   -1,   38,   93,   -1,   41,   -1,   59,   44,
   61,   -1,   -1,   -1,   93,   -1,   38,   -1,   40,   -1,
   42,   40,   -1,   45,   59,   -1,   61,   46,   -1,   48,
   -1,   -1,   51,   52,   53,  124,   -1,   56,  281,  282,
  283,   60,   93,   -1,   -1,  124,   -1,  257,  258,  259,
  260,  261,  262,  263,   -1,  265,  261,   -1,   93,  264,
  270,  271,  267,  268,  269,   -1,   -1,   41,  278,  279,
   44,   -1,   -1,  124,   -1,   -1,  281,  282,  283,   38,
   -1,   40,  101,   42,   -1,   59,   45,   -1,   38,  124,
   40,  261,   42,   -1,  264,   45,   -1,  267,  268,  269,
  261,  123,   -1,  264,  126,   -1,  267,  268,  269,   -1,
   -1,  281,  282,  283,  133,   -1,   -1,   -1,   -1,   93,
  281,  282,  283,   -1,   -1,  144,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   38,   -1,   40,   41,   42,
   -1,   -1,   45,   -1,   -1,   -1,  281,  282,  283,   -1,
  124,   -1,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,  123,   38,   -1,  126,   41,   -1,
   -1,   44,  261,   -1,   -1,  264,  126,   59,  267,  268,
  269,   -1,  261,   -1,   -1,  264,   59,   -1,  267,  268,
  269,   -1,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,   -1,   41,   -1,   -1,   44,
  261,   93,   -1,  264,   -1,   -1,  267,  268,  269,   -1,
   93,   -1,   -1,  126,   59,   -1,  261,   -1,   -1,  264,
  281,   -1,  267,  268,  269,  257,  258,  259,  260,  261,
   -1,  263,  124,  265,   -1,   -1,  281,   -1,  270,  271,
   -1,  124,   -1,   -1,   -1,   -1,  278,  279,   93,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  261,   -1,   -1,
  264,   -1,   -1,  267,  268,  269,   -1,   -1,  257,  258,
  259,  260,  261,   -1,  263,   -1,  265,  257,  258,  259,
  260,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,  278,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,   -1,   -1,
   -1,   -1,   -1,   -1,   47,   -1,   -1,   -1,   -1,   -1,
   -1,   54,   55,   -1,   57,  278,  279,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,  261,   -1,
   -1,  264,   -1,   -1,  267,  268,  269,   80,   81,   82,
   83,   84,   85,   86,   87,   88,   89,   90,   91,   92,
   93,   -1,   -1,   -1,   97,   98,   99,  100,   -1,  102,
   -1,   -1,   -1,   -1,   -1,   -1,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  129,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  137,   -1,   -1,   -1,  141,
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
"init : '(' prmtsOrNon ')' crpOrNon",
"init1 :",
"init1 : INT",
"init1 : cnstOrNon STR",
"init1 : REAL",
"init1 : ID",
"prmtsOrNon :",
"prmtsOrNon : parametros",
"crpOrNon :",
"crpOrNon : corpo",
"cnstOrNon :",
"cnstOrNon : CONST",
"parametros : parametro",
"parametros : parametro ',' parametros",
"parametro : tipo astOrNon ID",
"corpo : '{' prmtOrMore instrOrMore '}'",
"prmtOrMore : parametro ';'",
"prmtOrMore : parametro ';' prmtOrMore",
"instrOrMore : instrucao",
"instrOrMore : instrucao instrOrMore",
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
#line 174 "diy.y"
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 625 "y.tab.c"

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
