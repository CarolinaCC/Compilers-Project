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
	Node *n;	/* tree node */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 43 "y.tab.c"

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
#define ENDE 287
#define tEQ 288
#define tGT 289
#define tLT 290
#define tAND 291
#define tBOR 292
#define tMUL 293
#define tDIV 294
#define tMOD 295
#define tADD 296
#define tSUB 297
#define tNOT 298
#define tCALL 299
#define tPTR 300
#define tARG 301
#define tEND 302
#define tINDEX 303
#define tLOAD 304
#define tOR 305
#define tALLOC 306
#define tSTAR 307
#define tCONSTSTR 308
#define tPARA 309
#define tPUBoN 310
#define tFILE 311
#define tSTMT 312
#define tPUBeTIPO 313
#define tSTARMORE 314
#define tIDINIT 315
#define tPRMTCRP 316
#define tCORPO 317
#define tINSTM 318
#define tSTARID 319
#define tFINST 320
#define tTIPOSTAR 321
#define FEXPSTP 322
#define tFLVEX 323
#define tUPDOWN 324
#define tFORX 325
#define tPARAM 326
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    2,    2,    3,    3,    4,    4,    5,
    5,    5,    5,    6,    6,    7,    7,    7,    7,    7,
    8,    8,    9,    9,   10,   10,   11,   11,   12,   13,
   14,   14,   15,   15,   16,   16,   16,   16,   16,   16,
   16,   16,   17,   17,   18,   18,   19,   19,   20,   20,
   21,   21,   21,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   23,   23,
};
static const YYINT yylen[] = {                            2,
    0,    2,    6,    0,    1,    1,    2,    0,    1,    1,
    1,    1,    1,    2,    4,    0,    1,    2,    1,    1,
    0,    1,    0,    1,    0,    1,    1,    3,    3,    4,
    0,    3,    0,    2,    5,    5,    9,    2,    1,    3,
    3,    4,    0,    2,    1,    1,    0,    2,    0,    1,
    1,    4,    2,    1,    1,    1,    1,    3,    4,    3,
    2,    2,    2,    2,    2,    2,    2,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    1,    3,
};
static const YYINT yydefred[] = {                         1,
    0,   26,    0,    2,    0,    6,    7,   13,   10,   11,
   12,    0,    9,    0,    0,    0,    0,    0,    5,   17,
   19,   20,   14,    0,    0,    0,   22,    0,    3,   18,
    0,    0,    0,   29,    0,   15,   24,   28,    0,    0,
    0,   54,   55,   51,   56,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   39,    0,    0,
    0,    0,   32,    0,    0,    0,    0,   50,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   30,   34,   64,
   65,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   38,    0,
    0,    0,   40,   41,   58,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   60,    0,    0,    0,    0,    0,   52,   42,   59,
    0,   36,    0,   35,   45,   46,    0,    0,   48,    0,
    0,    0,    0,    0,   37,
};
static const YYINT yydgoto[] = {                          1,
    4,   18,    5,   14,   25,   19,   23,   26,   36,    6,
   27,   28,   58,   40,   59,   60,  142,  137,  134,   69,
   65,   62,  124,
};
static const YYINT yysindex[] = {                         0,
 -254,    0, -260,    0, -124,    0,    0,    0,    0,    0,
    0,   -1,    0, -211,  -39, -239, -124,   -4,    0,    0,
    0,    0,    0, -201,   -1,   24,    0,   22,    0,    0,
 -180,  -42, -124,    0, -124,    0,    0,    0,   27,  932,
 -124,    0,    0,    0,    0,  932,  941,  -31, -169, -169,
  -31,  -31,  -31,  941,  941,  -31,  941,    0,  -27,  932,
   25,  396,    0, -168,  -87,  423,  -77,    0,   50,   54,
   23,   23,   23,  648,   83,   23,  434,    0,    0,    0,
    0,  941,  941,  941,  941,  941,  941,  941,  941,  941,
  941,  941,  941,  941,  941,  941,  941,  988,    0,  941,
  932,  941,    0,    0,    0,  576,  461,  472,   85,   40,
   40,  605,  648,   85,   40,   40,   70,   70,   83,   83,
   83,    0,  576,   13,  503, -155,  358,    0,    0,    0,
  941,    0,  932,    0,    0,    0,  941,  576,    0,  539,
  941, -130,  576,  932,    0,
};
static const YYINT yyrindex[] = {                         0,
  -99,    0,  -99,    0,    0,    0,    0,    0,    0,    0,
    0, -126,    0,    0,   77,  -46,   96,    0,    0,    0,
    0,    0,    0,    0, -126,    0,    0,  105,    0,    0,
    0,   94,    0,    0,  882,    0,    0,    0,    0,   35,
  882,    0,    0,    0,    0,    0,    0,    0,  102,  102,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   35,
  550,    0,    0,    0,   -9,    0,    0,    0,    0,    0,
    2,   31,   59, 1009,   97,  -35,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  642,    0,    0,  840,  730,
  756,  917, 1072,  856,  802,  812,  686,  721,  125,  163,
  292,    0,   26,    0,    0,  681,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   64,    0,  -97,
    0,    0,  -96,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,  146,  172,    0,    0,    0,    0,   14,
  145,  -20,  147,  139,  121,   10,    0,    0,    0,  132,
 1111, 1206,    0,
};
#define YYTABLESIZE 1347
static const YYINT yytable[] = {                         53,
   17,   53,   53,   83,   53,   53,   53,   53,   53,   53,
   56,   53,   16,   83,   39,    2,    7,   20,   21,   22,
   39,    2,    3,   53,   53,   53,   53,   57,   57,   24,
   57,   57,   57,   57,   57,   57,    2,   57,   66,   66,
   13,   66,   66,   66,   66,   66,   66,   15,   66,   57,
   57,   57,   57,  130,   29,   64,  131,   53,   30,   84,
   66,   66,   66,   66,   32,   33,   82,   67,   67,   82,
   67,   67,   67,   67,   67,   67,   97,   67,   34,   98,
   35,   95,   94,   57,   93,   41,   96,   68,   53,   67,
   67,   67,   67,  100,   66,   62,   62,   78,   62,   62,
   62,   62,   62,   62,   83,   62,   97,   83,  103,   98,
  126,   95,  104,   83,   57,   83,   96,   62,   62,   62,
   62,   97,   98,   67,   98,   66,   95,   94,  133,   93,
  144,   96,    8,   61,   61,    4,   21,   61,   61,   61,
   61,   61,  139,   61,   91,   27,   92,    8,    9,   10,
   11,   62,   23,  145,   67,   61,   61,   61,   61,   33,
   49,   68,   68,   43,   44,   68,   68,   68,   68,   68,
   31,   68,   25,   25,   25,   25,   12,   38,   37,   63,
   79,   70,   62,   68,   68,   68,   68,    0,  102,   61,
   80,   81,   82,    0,    0,    0,    0,    0,    0,   69,
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
    0,    0,   80,   81,   82,    0,    0,    0,    0,    0,
    0,   67,   67,   67,    0,    0,    0,    0,    0,   62,
    0,    0,   62,    0,    0,   62,   62,   62,   70,   70,
    0,    0,   70,   70,   70,   70,   70,    0,   70,   62,
   62,   62,    0,    0,    0,    0,    0,    0,    0,    0,
   70,   70,   70,   70,    0,    0,    0,   61,    0,    0,
   61,    0,    0,   61,   61,   61,   86,   87,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   61,   61,   61,
    0,    0,    0,    0,   70,   68,    0,    0,   68,    0,
    0,   68,   68,   68,   97,   89,    0,   98,    0,   95,
   94,    0,   93,    0,   96,   68,   68,   68,    0,    0,
    0,    0,    0,    0,    0,   70,    0,   91,   90,   92,
    0,    0,    0,   69,    0,    0,   69,    0,    0,   69,
   69,   69,   97,   89,    0,   98,    0,   95,   94,    0,
   93,    0,   96,   69,   69,   69,    0,    0,    0,    0,
    0,    0,    0,    0,   99,   91,   90,   92,    0,   97,
   89,    0,   98,    0,   95,   94,    0,   93,    0,   96,
   97,   89,    0,   98,  105,   95,   94,    0,   93,    0,
   96,   88,   91,   90,   92,    0,    0,    0,    0,    0,
    0,    0,    0,   91,   90,   92,    0,   97,   89,    0,
   98,    0,   95,   94,    0,   93,    0,   96,   97,   89,
    0,   98,    0,   95,   94,    0,   93,    0,   96,   88,
   91,   90,   92,    0,    0,    0,    0,    0,    0,    0,
  129,   91,   90,   92,    0,    0,    0,    0,    0,   97,
   89,    0,   98,    0,   95,   94,   88,   93,    0,   96,
    0,    0,   70,  128,    0,   70,    0,   88,   70,   70,
   70,  132,   91,   90,   92,    0,    0,    0,    0,    0,
    0,    0,   70,   70,   70,   97,   89,    0,   98,    0,
   95,   94,    0,   93,   88,   96,   57,   57,    0,   57,
    0,   57,   57,    0,   57,   88,   57,    0,   91,   90,
   92,    0,    0,    0,    0,    0,    0,    0,   57,   57,
   57,   57,   97,   89,    0,   98,    0,   95,   94,    0,
   93,    0,   96,    0,  135,  136,   88,    0,    0,    0,
    0,    0,    0,    0,    0,   91,   90,   92,   85,   86,
   87,   97,   89,    0,   98,    0,   95,   94,    0,   93,
    0,   96,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   88,    0,   91,   90,   92,    0,    0,    0,
    0,    0,    0,   57,    0,    0,   85,   86,   87,    0,
    0,    0,   81,    0,   97,   81,  101,   98,    0,   95,
   94,    0,   93,    0,   96,    0,    0,    0,    0,   88,
   81,    0,    0,   85,   86,   87,    0,   91,   90,   92,
    0,    0,    0,    0,   85,   86,   87,    0,   47,    0,
   47,    0,   47,   72,    0,   47,   72,    0,   72,   72,
   72,    0,    0,    0,   81,    0,    0,    0,    0,    0,
    0,   85,   86,   87,   72,   72,   72,   72,    0,    0,
    0,    0,   85,   86,   87,    0,    0,    0,   71,    0,
    0,   71,    0,   71,   71,   71,    0,   75,    0,    0,
   75,    0,    0,   75,    0,    0,    0,    0,   72,   71,
   71,   71,   71,   85,   86,   87,    0,    0,   75,   75,
   75,   75,    0,   76,    0,    0,   76,    0,    0,   76,
    0,    0,    0,   47,    0,   47,   47,  141,    0,   72,
    0,    0,    0,   71,   76,   76,   76,   76,    0,   85,
   86,   87,   75,    0,    0,    0,    0,    0,    0,    0,
   57,   57,   57,    0,    0,    0,    0,    0,    0,   73,
    0,    0,   73,    0,   71,   73,    0,    0,   76,   74,
    0,    0,   74,   75,    0,   74,   85,   86,   87,    0,
   73,   73,   73,   73,    0,    0,    0,    0,    0,    0,
   74,   74,   74,   74,    0,    0,    0,   78,    0,   76,
   78,    0,    0,   78,    0,   85,   86,   87,    0,    0,
    0,    0,    0,   77,   73,    0,   77,    0,   78,   77,
   78,    0,   81,    0,   74,   81,    0,    0,   81,   81,
   81,    0,    0,    0,   77,    0,   77,    0,    0,   31,
    0,   31,    0,   31,    0,   73,   31,    0,   85,   86,
   87,    0,   78,    0,    0,   74,    0,   47,   47,   47,
   47,   47,   47,   47,    0,   47,   72,    0,   77,   72,
   47,   47,   72,   72,   72,    0,    0,   80,   47,   47,
   80,    0,    0,   78,    0,    0,   72,   72,   72,   53,
    0,   57,    0,   56,    0,   80,   55,    0,   53,   77,
   57,   71,   56,    0,   71,   55,    0,   71,   71,   71,
   75,    0,    0,   75,    0,    0,   75,   75,   75,    0,
    0,   71,   71,   71,   31,    0,   31,   31,    0,   80,
   75,   75,   75,    0,    0,    0,   76,    0,    0,   76,
    0,    0,   76,   76,   76,   53,    0,   57,  122,   56,
    0,    0,   55,    0,    0,    0,   76,   76,   76,    0,
   80,    0,    0,    0,    0,    0,   63,    0,    0,   63,
    0,    0,   63,    0,   35,    0,    0,   54,    0,    0,
    0,    0,   73,    0,    0,   73,   54,   63,   73,   73,
   73,    0,   74,    0,    0,   74,    0,    0,   74,   74,
   74,    0,   73,   73,   73,    0,    0,    0,    0,    0,
    0,    0,   74,   74,   74,    0,    0,    0,    0,    0,
   78,   63,    0,   78,    0,    0,   78,   78,   78,   79,
    0,    0,   79,   54,    0,   79,   77,    0,    0,   77,
   78,    0,   77,   77,   77,    0,    0,    0,    0,    0,
   79,    0,   63,    0,    0,    0,   77,    0,   31,   31,
   31,   31,   31,    0,   31,    0,   31,    0,    0,    0,
   61,   31,   31,    0,    0,    0,   61,    0,   67,   31,
   31,   71,   72,   73,   79,    0,   76,    0,    0,    0,
   61,    0,    0,    0,    0,    0,    0,   80,    0,    0,
   80,    0,    0,   80,   80,   80,    0,    0,   42,   43,
   44,   45,   46,    0,   47,   79,   48,   42,   43,   44,
   45,   49,   50,    0,    0,    0,    0,    0,    0,   51,
   52,   61,    0,    0,    0,    0,    0,    0,   51,   52,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   61,   42,   43,   44,   45,    0,    0,
    0,    0,   66,    0,   61,    0,    0,    0,    0,   74,
   75,    0,   77,    0,    0,   51,   52,    0,    0,   63,
    0,    0,   63,    0,    0,   63,   63,   63,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  106,  107,  108,
  109,  110,  111,  112,  113,  114,  115,  116,  117,  118,
  119,  120,  121,  123,    0,  125,    0,  127,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   79,    0,    0,   79,  138,    0,   79,   79,
   79,    0,  140,    0,    0,    0,  143,
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
  275,   93,   59,  144,  124,   59,   60,   61,   62,  125,
   59,   37,   38,  261,  261,   41,   42,   43,   44,   45,
   25,   47,  272,  273,  274,  275,    5,   33,   32,   41,
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
   -1,   -1,   41,   -1,   37,   44,  264,   40,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,  124,
   59,   -1,   -1,  281,  282,  283,   -1,   60,   61,   62,
   -1,   -1,   -1,   -1,  281,  282,  283,   -1,   38,   -1,
   40,   -1,   42,   38,   -1,   45,   41,   -1,   43,   44,
   45,   -1,   -1,   -1,   93,   -1,   -1,   -1,   -1,   -1,
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
   61,   -1,  261,   -1,   93,  264,   -1,   -1,  267,  268,
  269,   -1,   -1,   -1,   59,   -1,   61,   -1,   -1,   38,
   -1,   40,   -1,   42,   -1,  124,   45,   -1,  281,  282,
  283,   -1,   93,   -1,   -1,  124,   -1,  257,  258,  259,
  260,  261,  262,  263,   -1,  265,  261,   -1,   93,  264,
  270,  271,  267,  268,  269,   -1,   -1,   41,  278,  279,
   44,   -1,   -1,  124,   -1,   -1,  281,  282,  283,   38,
   -1,   40,   -1,   42,   -1,   59,   45,   -1,   38,  124,
   40,  261,   42,   -1,  264,   45,   -1,  267,  268,  269,
  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,
   -1,  281,  282,  283,  123,   -1,  125,  126,   -1,   93,
  281,  282,  283,   -1,   -1,   -1,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   38,   -1,   40,   41,   42,
   -1,   -1,   45,   -1,   -1,   -1,  281,  282,  283,   -1,
  124,   -1,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,  123,   -1,   -1,  126,   -1,   -1,
   -1,   -1,  261,   -1,   -1,  264,  126,   59,  267,  268,
  269,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,
  269,   -1,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,
  261,   93,   -1,  264,   -1,   -1,  267,  268,  269,   38,
   -1,   -1,   41,  126,   -1,   44,  261,   -1,   -1,  264,
  281,   -1,  267,  268,  269,   -1,   -1,   -1,   -1,   -1,
   59,   -1,  124,   -1,   -1,   -1,  281,   -1,  257,  258,
  259,  260,  261,   -1,  263,   -1,  265,   -1,   -1,   -1,
   40,  270,  271,   -1,   -1,   -1,   46,   -1,   48,  278,
  279,   51,   52,   53,   93,   -1,   56,   -1,   -1,   -1,
   60,   -1,   -1,   -1,   -1,   -1,   -1,  261,   -1,   -1,
  264,   -1,   -1,  267,  268,  269,   -1,   -1,  257,  258,
  259,  260,  261,   -1,  263,  124,  265,  257,  258,  259,
  260,  270,  271,   -1,   -1,   -1,   -1,   -1,   -1,  278,
  279,  101,   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  133,  257,  258,  259,  260,   -1,   -1,
   -1,   -1,   47,   -1,  144,   -1,   -1,   -1,   -1,   54,
   55,   -1,   57,   -1,   -1,  278,  279,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   82,   83,   84,
   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
   95,   96,   97,   98,   -1,  100,   -1,  102,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  261,   -1,   -1,  264,  131,   -1,  267,  268,
  269,   -1,  137,   -1,   -1,   -1,  141,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 326
#define YYUNDFTOKEN 352
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
"GE","LE","ELSE","IFX","UMINUS","ENDE","tEQ","tGT","tLT","tAND","tBOR","tMUL",
"tDIV","tMOD","tADD","tSUB","tNOT","tCALL","tPTR","tARG","tEND","tINDEX",
"tLOAD","tOR","tALLOC","tSTAR","tCONSTSTR","tPARA","tPUBoN","tFILE","tSTMT",
"tPUBeTIPO","tSTARMORE","tIDINIT","tPRMTCRP","tCORPO","tINSTM","tSTARID",
"tFINST","tTIPOSTAR","FEXPSTP","tFLVEX","tUPDOWN","tFORX","tPARAM",0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"illegal-symbol",
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
"corpo : '{' prmtNonOrMore instrNonOrMore '}'",
"prmtNonOrMore :",
"prmtNonOrMore : parametro ';' prmtNonOrMore",
"instrNonOrMore :",
"instrNonOrMore : instrucao instrNonOrMore",
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
#line 180 "diy.y"
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
#line 668 "y.tab.c"

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
case 1:
#line 42 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 2:
#line 43 "diy.y"
	{ yyval.n = binNode(tFILE, yystack.l_mark[-1].n, yystack.l_mark[0].n ); }
break;
case 3:
#line 46 "diy.y"
	{ yyval.n = binNode(tSTMT, binNode(tPUBeTIPO, yystack.l_mark[-5].n, yystack.l_mark[-4].n), binNode(tSTARMORE, yystack.l_mark[-3].n, binNode(tIDINIT, yystack.l_mark[-2].s, yystack.l_mark[-1].n ))); }
break;
case 4:
#line 49 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 5:
#line 50 "diy.y"
	{ yyval.n = nilNode(yystack.l_mark[0].n); }
break;
case 6:
#line 53 "diy.y"
	{ yyval.n = binNode(tPUBoN, nilNode(tEND), yystack.l_mark[0].n ); }
break;
case 7:
#line 54 "diy.y"
	{ yyval.n = binNode(tPUBoN, nilNode(PUBLIC), yystack.l_mark[0].n ); }
break;
case 8:
#line 58 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 9:
#line 59 "diy.y"
	{ yyval.n = nilNode(tSTAR); }
break;
case 10:
#line 62 "diy.y"
	{ yyval.n = nilNode(INTEGER); }
break;
case 11:
#line 63 "diy.y"
	{ yyval.n = nilNode(STRING); }
break;
case 12:
#line 64 "diy.y"
	{ yyval.n = nilNode(NUMBER); }
break;
case 13:
#line 65 "diy.y"
	{ yyval.n = nilNode(VOID); }
break;
case 14:
#line 68 "diy.y"
	{ yyval.n = uniNode(ATR, yystack.l_mark[0].n); }
break;
case 15:
#line 69 "diy.y"
	{ yyval.n = binNode(tPRMTCRP, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 16:
#line 72 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 17:
#line 73 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); }
break;
case 18:
#line 74 "diy.y"
	{ yyval.n = binNode(tCONSTSTR, yystack.l_mark[-1].n, strNode(STR, yystack.l_mark[0].s)); }
break;
case 19:
#line 75 "diy.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[0].r); }
break;
case 20:
#line 76 "diy.y"
	{ yyval.n = strNode(ID, yystack.l_mark[0].s); }
break;
case 21:
#line 79 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 22:
#line 80 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 23:
#line 84 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 24:
#line 85 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 25:
#line 88 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 26:
#line 89 "diy.y"
	{ yyval.n = nilNode(CONST); }
break;
case 27:
#line 92 "diy.y"
	{ yyval.n = binNode(tPARA, yystack.l_mark[0].n, nilNode(tEND)); }
break;
case 28:
#line 93 "diy.y"
	{ yyval.n = binNode(tPARA, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 29:
#line 96 "diy.y"
	{ yyval.n = binNode(tTIPOSTAR, yystack.l_mark[-2].n, binNode(tSTARID, yystack.l_mark[-1].n, yystack.l_mark[0].s));}
break;
case 30:
#line 99 "diy.y"
	{ yyval.n = binNode(tCORPO, yystack.l_mark[-2].n, yystack.l_mark[-1].n);}
break;
case 31:
#line 102 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 32:
#line 103 "diy.y"
	{ yyval.n = binNode(tPARAM, yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 33:
#line 107 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 34:
#line 108 "diy.y"
	{ yyval.n = binNode(tINSTM, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 35:
#line 111 "diy.y"
	{ yyval.n = binNode(IF, binNode(THEN, yystack.l_mark[-3].n, yystack.l_mark[-1].n), yystack.l_mark[0].n); }
break;
case 36:
#line 112 "diy.y"
	{ yyval.n = binNode(WHILE, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 37:
#line 113 "diy.y"
	{ yyval.n = binNode(tFINST, binNode(tFORX, binNode(tFLVEX, yystack.l_mark[-7].n, yystack.l_mark[-5].n), binNode(tUPDOWN, yystack.l_mark[-4].n, binNode($FEXPSTP, yystack.l_mark[-3].n, yystack.l_mark[-2].n))), yystack.l_mark[0].n); }
break;
case 38:
#line 114 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 39:
#line 115 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 40:
#line 116 "diy.y"
	{ yyval.n = uniNode(BREAK, yystack.l_mark[-1].n);  }
break;
case 41:
#line 117 "diy.y"
	{ yyval.n = uniNode(CONTINUE, yystack.l_mark[-1].n);  }
break;
case 42:
#line 118 "diy.y"
	{ yyval.n = binNode(tALLOC, yystack.l_mark[-1].n, yystack.l_mark[-3].n); }
break;
case 43:
#line 121 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 44:
#line 122 "diy.y"
	{ yyval.n = uniNode(STEP, yystack.l_mark[0].n);  }
break;
case 45:
#line 125 "diy.y"
	{ yyval.n = nilNode(UPTO); }
break;
case 46:
#line 126 "diy.y"
	{ yyval.n = nilNode(DOWNTO); }
break;
case 47:
#line 129 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 48:
#line 130 "diy.y"
	{ yyval.n = uniNode(ELSE, yystack.l_mark[0].n);  }
break;
case 49:
#line 133 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 50:
#line 134 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); }
break;
case 51:
#line 137 "diy.y"
	{ yyval.n = strNode(ID , yystack.l_mark[0].s); }
break;
case 52:
#line 138 "diy.y"
	{ yyval.n = binNode(tINDEX, yystack.l_mark[-3].n, yystack.l_mark[-1].n); yyval.n->info = 0; }
break;
case 53:
#line 139 "diy.y"
	{ yyval.n = uniNode(tLOAD, yystack.l_mark[0].n); yyval.n->info = 0; }
break;
case 54:
#line 142 "diy.y"
	{ yyval.n = nilNode(INT); }
break;
case 55:
#line 143 "diy.y"
	{ yyval.n = nilNode(REAL); }
break;
case 56:
#line 144 "diy.y"
	{ yyval.n = nilNode(STR); }
break;
case 57:
#line 145 "diy.y"
	{ yyval.n = uniNode(tLOAD, yystack.l_mark[0].n); }
break;
case 58:
#line 146 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 59:
#line 147 "diy.y"
	{ yyval.n = binNode(tCALL, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 60:
#line 148 "diy.y"
	{ yyval.n = binNode(tCALL, yystack.l_mark[-2].n, nilNode(tEND)); }
break;
case 61:
#line 149 "diy.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); }
break;
case 62:
#line 150 "diy.y"
	{ yyval.n = uniNode(tPTR, yystack.l_mark[0].n); }
break;
case 63:
#line 151 "diy.y"
	{ yyval.n = uniNode(tNOT, yystack.l_mark[0].n); }
break;
case 64:
#line 152 "diy.y"
	{ yyval.n = binNode(INCR, yystack.l_mark[-1].n, intNode(INT, 1)); }
break;
case 65:
#line 153 "diy.y"
	{ yyval.n = binNode(DECR, yystack.l_mark[-1].n, intNode(INT, 1)); }
break;
case 66:
#line 154 "diy.y"
	{ yyval.n = binNode(INCR, intNode(INT, 1),  yystack.l_mark[0].n ); }
break;
case 67:
#line 155 "diy.y"
	{ yyval.n = binNode(DECR, intNode(INT, 1),  yystack.l_mark[0].n ); }
break;
case 68:
#line 157 "diy.y"
	{ yyval.n = binNode(tMUL, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 69:
#line 158 "diy.y"
	{ yyval.n = binNode(tDIV, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 70:
#line 159 "diy.y"
	{ yyval.n = binNode(tMOD, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 71:
#line 160 "diy.y"
	{ yyval.n = binNode(tADD, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 72:
#line 161 "diy.y"
	{ yyval.n = binNode(tSUB, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 73:
#line 162 "diy.y"
	{ yyval.n = binNode(tLT, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 74:
#line 163 "diy.y"
	{ yyval.n = binNode(tGT, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 75:
#line 164 "diy.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 76:
#line 165 "diy.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 77:
#line 166 "diy.y"
	{ yyval.n = binNode(tEQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 78:
#line 167 "diy.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 79:
#line 168 "diy.y"
	{ yyval.n = binNode(tAND, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 80:
#line 169 "diy.y"
	{ yyval.n = binNode(tOR, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 81:
#line 170 "diy.y"
	{ yyval.n = binNode(ATR, yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
case 82:
#line 173 "diy.y"
	{ yyval.n = binNode(tARG, yystack.l_mark[0].n, nilNode(tEND)); }
break;
case 83:
#line 174 "diy.y"
	{ yyval.n = binNode(tARG, yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
#line 1199 "y.tab.c"
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
