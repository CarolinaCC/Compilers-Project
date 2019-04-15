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
#define vint 1
#define	vreal 2
#define vstr 3
#define vvoid 4
#define vptr 1000
#define vconst 10000
#define vpublic 100000

extern int yylex();
int yyerror(char *s);

int ciclos = 0;

#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#line 21 "diy.y"
typedef union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
	Node *n;	/* tree node */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 54 "y.tab.c"

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
#define tFEXPSTP 322
#define tFLVEX 323
#define tUPDOWN 324
#define tFORX 325
#define tPARAM 326
#define tSTMT1 327
#define tSTMTN 328
#define tSTMTSTARTID 329
#define tSTMTPRMTCORP 330
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,    0,    1,    1,    2,    2,    3,    3,    4,    4,
    5,    5,    5,    5,    6,    6,    6,    6,    6,    7,
    7,    8,    8,    9,    9,   10,   10,   11,   12,   13,
   13,   14,   14,   15,   15,   15,   15,   15,   15,   15,
   15,   16,   16,   17,   17,   18,   18,   19,   19,   20,
   20,   20,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   21,   21,   21,   21,   21,   21,   21,   21,   21,   21,
   22,   22,
};
static const YYINT yylen[] = {                            2,
    0,    2,    6,    9,    0,    2,    1,    2,    0,    1,
    1,    1,    1,    1,    0,    1,    2,    1,    1,    0,
    1,    0,    1,    0,    1,    1,    3,    3,    4,    0,
    3,    0,    2,    5,    5,    9,    2,    1,    3,    3,
    4,    0,    2,    1,    1,    0,    2,    0,    1,    1,
    4,    2,    1,    1,    1,    1,    3,    4,    3,    2,
    2,    2,    2,    2,    2,    2,    3,    3,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    1,    3,
};
static const YYINT yydefred[] = {                         1,
    0,   25,    0,    2,    0,    7,    8,   14,   11,   12,
   13,    0,   10,    0,    0,    0,    0,    0,   16,   18,
   19,    6,    0,    0,    0,   21,    0,    3,   17,    0,
    0,    0,   28,    0,    0,   23,   27,    0,    0,    4,
    0,   53,   54,    0,   55,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   38,    0,    0,
    0,    0,   31,    0,    0,    0,    0,   50,    0,   49,
    0,    0,    0,    0,    0,    0,   60,    0,    0,   29,
   33,   63,   64,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   37,
   59,    0,    0,    0,    0,    0,   39,   40,   57,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   67,   68,   69,   58,    0,    0,    0,    0,
   51,   41,    0,   35,    0,   34,   44,   45,    0,   47,
    0,    0,    0,    0,    0,   36,
};
static const YYINT yydgoto[] = {                          1,
    4,   18,    5,   14,   24,   22,   25,   35,    6,   26,
   27,   58,   39,   59,   60,  143,  139,  136,   71,   66,
   62,  103,
};
static const YYINT yysindex[] = {                         0,
 -235,    0, -255,    0, -161,    0,    0,    0,    0,    0,
    0,  -13,    0, -216,  -39, -244, -161,  -11,    0,    0,
    0,    0, -214,  -13,    9,    0,   13,    0,    0, -198,
  -61, -161,    0, -161,   14,    0,    0,   32,  748,    0,
 -161,    0,    0,   28,    0,  748,  441,  -38, -185, -185,
  -38,  -38,  -38,  441,  441,  -38,  441,    0,  -27,  748,
  -12,  139,    0,  849, -163,  -75,  292,    0,  -74,    0,
   48,   49,   18,   18,   18,  493,    0,   18,  327,    0,
    0,    0,    0,  441,  441,  441,  441,  441,  441,  441,
  441,  441,  441,  441,  441,  441,  441,  441,  441,    0,
    0,  472,  -22,  441,  748,  441,    0,    0,    0,  472,
  370,  381,  165,    2,    2,  177,  493,  165,    2,    2,
   86,   86,    0,    0,    0,    0,  441,  407, -179,  128,
    0,    0,  472,    0,  748,    0,    0,    0,  441,    0,
  435,  441, -145,  472,  748,    0,
};
static const YYINT yyrindex[] = {                         0,
 -130,    0, -130,    0,    0,    0,    0,    0,    0,    0,
    0, -137,    0,    0,   65,  -54,   84,    0,    0,    0,
    0,    0,    0, -137,    0,    0,   88,    0,    0,    0,
   68,    0,    0,  719,    0,    0,    0,    0,   23,    0,
  719,    0,    0,  -35,    0,    0,    0,    0,   71,   71,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   23,
  461,    0,    0,    0,    0,   22,    0,    0,    0,    0,
    0,    0,   33,   59,   94,  868,    0,   -7,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   44,    0,    0,    0,    0,    0,    0,    0,  772,
    0,    0,  589,  554,  579,  888,  878,  616,  632,  667,
  501,  543,    0,    0,    0,    0,    0,    0,  694,    0,
    0,    0,   46,    0,    0,    0,    0,    0,    0,    0,
 -127,    0,    0, -114,    0,    0,
};
static const YYINT yygindex[] = {                         0,
    0,    0,    0,  125,  146,    0,    0,    0,   17,  126,
  -23,  129,  118,  101,    5,    0,    0,    0,  112,  996,
 1096,    0,
};
#define YYTABLESIZE 1238
static const YYINT yytable[] = {                         50,
   17,   50,   50,   56,   15,   50,   50,   50,   50,   50,
   38,   50,   19,   20,   21,   85,   85,   38,  126,    7,
    2,  127,   86,   50,   50,   50,   50,   52,   13,   52,
   52,    2,   23,   52,   52,   52,   52,   52,   99,   52,
    2,    3,   15,   97,   96,   29,   95,   28,   98,   31,
   65,   52,   52,   52,   52,   50,   32,   50,   56,   56,
   33,   34,   56,   56,   56,   56,   56,   64,   56,   65,
   65,   70,   40,   65,   65,   65,   65,   65,   85,   65,
   56,   56,   56,   56,   81,   52,   82,   81,   50,   82,
   41,   65,   65,   65,   65,   66,   66,   80,  104,   66,
   66,   66,   66,   66,  135,   66,  107,  108,   85,  129,
    8,    9,   10,   11,   56,  145,   52,   66,   66,   66,
   66,    9,   99,    5,   20,   65,   22,   97,   26,   48,
   61,   61,   98,   42,   61,   61,   61,   61,   61,  140,
   61,   24,   24,   24,   24,   56,   43,   32,   30,  146,
   12,   66,   61,   61,   61,   61,   65,   37,   63,   36,
   81,   72,    0,    0,   99,   91,    0,    0,    0,   97,
   96,    0,   95,    0,   98,   99,   91,    0,    0,    0,
   97,   96,   66,   95,    0,   98,   61,   93,   92,   94,
    0,  106,    0,    0,    0,    0,    0,  100,   93,   92,
   94,   99,   82,   83,   84,   24,   97,   96,    0,   95,
    0,   98,    0,   99,   91,    0,    0,   61,   97,   96,
   68,   95,    0,   98,   93,   50,   94,    0,   50,    0,
    0,   50,   50,   50,    0,    0,   93,   92,   94,    0,
   16,    0,   50,   50,   50,   50,   50,   50,    0,    0,
    0,   90,    0,   52,    0,    0,   52,    0,   52,   52,
   52,   52,   90,    0,    0,   82,   83,   84,    0,    0,
   52,   52,   52,   52,   52,   52,    0,    0,    0,    0,
    0,    0,   56,    0,    0,   56,    0,    0,   56,   56,
   56,    0,    0,   65,    0,    0,   65,    0,    0,   65,
   65,   65,   56,   56,   56,    0,    0,    0,    0,    0,
    0,    0,    0,   65,   65,   65,    0,    0,    0,   66,
    0,    0,   66,    0,    0,   66,   66,   66,   99,   91,
    0,    0,    0,   97,   96,    0,   95,    0,   98,   66,
   66,   66,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   93,   92,   94,   61,    0,    0,   61,    0,    0,
   61,   61,   61,   99,   91,    0,    0,  109,   97,   96,
    0,   95,    0,   98,   61,   61,   61,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   93,   92,   94,    0,
    0,    0,    0,    0,  137,  138,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   99,   91,   87,   88,
   89,   97,   96,    0,   95,   90,   98,   99,   91,   87,
   88,   89,   97,   96,    0,   95,    0,   98,    0,   93,
   92,   94,    0,    0,    0,    0,    0,    0,    0,  132,
   93,   92,   94,   99,   91,    0,   88,   89,   97,   96,
   90,   95,    0,   98,    0,    0,    0,   87,   88,   89,
    0,    0,  131,    0,    0,  134,   93,   92,   94,    0,
    0,   99,   91,    0,    0,    0,   97,   96,   53,   95,
   57,   98,   56,    0,    0,   55,    0,    0,    0,    0,
    0,    0,    0,   90,   93,   92,   94,   56,   56,    0,
    0,    0,   56,   56,   90,   56,    0,   56,   99,   91,
    0,    0,    0,   97,   96,    0,   95,    0,   98,   56,
   56,   56,   56,    0,    0,    0,    0,    0,    0,   99,
   90,   93,   92,   94,   97,   96,    0,   95,   71,   98,
    0,   71,    0,   71,   71,   71,    0,    0,    0,    0,
    0,    0,   93,   92,   94,  105,    0,    0,   90,   71,
   71,   71,   71,    0,    0,    0,   54,    0,    0,    0,
    0,    0,   87,   88,   89,    0,    0,    0,    0,    0,
   70,    0,    0,   70,   56,   70,   70,   70,    0,    0,
    0,   74,    0,   71,   74,   90,    0,   74,    0,    0,
    0,   70,   70,   70,   70,    0,    0,   87,   88,   89,
    0,    0,   74,   74,   74,   74,   75,    0,    0,   75,
    0,    0,   75,    0,   71,    0,   77,    0,    0,   77,
    0,    0,   77,    0,    0,   70,    0,   75,   75,   75,
   75,    0,    0,    0,    0,    0,   74,   77,    0,   77,
   87,   88,   89,   76,    0,    0,   76,    0,    0,   76,
    0,   87,   88,   89,    0,    0,   70,    0,    0,   72,
    0,   75,   72,    0,   76,   72,   76,   74,    0,    0,
    0,   77,    0,    0,    0,    0,    0,   87,   88,   89,
   72,   72,   72,   72,    0,    0,    0,   42,   43,   44,
   45,    0,   75,  142,   73,    0,    0,   73,   76,    0,
   73,    0,   77,    0,    0,   87,   88,   89,   51,   52,
    0,    0,    0,    0,   72,   73,   73,   73,   73,    0,
    0,   46,    0,   46,    0,   46,    0,    0,   46,   76,
    0,   56,   56,   56,    0,    0,    0,    0,    0,    0,
    0,    0,   87,   88,   89,   72,   30,    0,   30,   73,
   30,   71,    0,   30,   71,    0,    0,   71,   71,   71,
    0,    0,    0,   87,   88,   89,    0,    0,    0,    0,
    0,   71,   71,   71,    0,   53,    0,   57,    0,   56,
   73,    0,   55,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   70,    0,    0,   70,    0,    0,   70,
   70,   70,   80,    0,   74,   80,   46,   74,   46,   46,
   74,   74,   74,   70,   70,   70,    0,    0,    0,    0,
   80,    0,    0,    0,   74,   74,   74,    0,    0,   75,
    0,   30,   75,   30,   30,   75,   75,   75,    0,   77,
    0,    0,   77,    0,    0,   77,   77,   77,    0,   75,
   75,   75,    0,    0,   80,    0,    0,    0,    0,   77,
   34,    0,    0,   54,    0,    0,   76,    0,    0,   76,
    0,    0,   76,   76,   76,    0,   53,    0,   57,  101,
   56,    0,   72,   55,    0,   72,   76,    0,   72,   72,
   72,    0,    0,    0,    0,   62,    0,    0,   62,    0,
    0,   62,   72,   72,   72,   78,    0,    0,   78,    0,
    0,   78,    0,    0,    0,    0,   62,   73,   79,    0,
   73,   79,    0,   73,   73,   73,   78,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   79,   73,   73,   73,
   46,   46,   46,   46,   46,   46,   46,    0,   46,    0,
   62,    0,    0,   46,   46,    0,    0,    0,    0,    0,
   78,   46,   46,    0,   54,   30,   30,   30,   30,   30,
   79,   30,    0,   30,    0,    0,    0,    0,   30,   30,
    0,   62,    0,    0,    0,    0,   30,   30,    0,    0,
    0,   78,    0,    0,   42,   43,   44,   45,   46,    0,
   47,   79,   48,    0,    0,    0,    0,   49,   50,    0,
    0,    0,    0,    0,    0,   51,   52,    0,    0,    0,
    0,    0,   80,    0,   61,   80,    0,    0,   80,   80,
   80,   61,    0,   69,    0,    0,   73,   74,   75,    0,
    0,   78,    0,    0,    0,   61,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   61,    0,    0,    0,    0,   42,   43,   44,   45,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   51,   52,   62,    0,
   61,   62,    0,    0,   62,   62,   62,    0,   78,    0,
   61,   78,   67,    0,   78,   78,   78,    0,   79,   76,
   77,   79,   79,    0,   79,   79,   79,    0,    0,  102,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  110,
  111,  112,  113,  114,  115,  116,  117,  118,  119,  120,
  121,  122,  123,  124,  125,    0,    0,    0,    0,  128,
    0,  130,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  133,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  141,    0,    0,  144,
};
static const YYINT yycheck[] = {                         35,
   40,   37,   38,   42,   59,   41,   42,   43,   44,   45,
   34,   47,  257,  258,  259,   91,   91,   41,   41,    3,
  276,   44,   35,   59,   60,   61,   62,   35,   42,   37,
   38,  276,   16,   41,   42,   43,   44,   45,   37,   47,
  276,  277,  259,   42,   43,  260,   45,   59,   47,   41,
   46,   59,   60,   61,   62,   91,   44,   93,   37,   38,
  259,  123,   41,   42,   43,   44,   45,   40,   47,   37,
   38,  257,   59,   41,   42,   43,   44,   45,   91,   47,
   59,   60,   61,   62,   41,   93,   41,   44,  124,   44,
   59,   59,   60,   61,   62,   37,   38,  125,  262,   41,
   42,   43,   44,   45,  284,   47,   59,   59,   91,  105,
  272,  273,  274,  275,   93,  261,  124,   59,   60,   61,
   62,  259,   37,   59,   41,   93,   59,   42,   41,   59,
   37,   38,   47,  261,   41,   42,   43,   44,   45,  135,
   47,  272,  273,  274,  275,  124,  261,  125,   24,  145,
    5,   93,   59,   60,   61,   62,  124,   32,   41,   31,
   60,   50,   -1,   -1,   37,   38,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   37,   38,   -1,   -1,   -1,
   42,   43,  124,   45,   -1,   47,   93,   60,   61,   62,
   -1,  266,   -1,   -1,   -1,   -1,   -1,   59,   60,   61,
   62,   37,  278,  279,  280,  260,   42,   43,   -1,   45,
   -1,   47,   -1,   37,   38,   -1,   -1,  124,   42,   43,
  259,   45,   -1,   47,   60,  261,   62,   -1,  264,   -1,
   -1,  267,  268,  269,   -1,   -1,   60,   61,   62,   -1,
  280,   -1,  278,  279,  280,  281,  282,  283,   -1,   -1,
   -1,  124,   -1,  261,   -1,   -1,  264,   -1,  266,  267,
  268,  269,  124,   -1,   -1,  278,  279,  280,   -1,   -1,
  278,  279,  280,  281,  282,  283,   -1,   -1,   -1,   -1,
   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,
  269,   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  281,  282,  283,   -1,   -1,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,  281,
  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   60,   61,   62,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,   37,   38,   -1,   -1,   41,   42,   43,
   -1,   45,   -1,   47,  281,  282,  283,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   60,   61,   62,   -1,
   -1,   -1,   -1,   -1,  267,  268,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   37,   38,  281,  282,
  283,   42,   43,   -1,   45,  124,   47,   37,   38,  281,
  282,  283,   42,   43,   -1,   45,   -1,   47,   -1,   60,
   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   59,
   60,   61,   62,   37,   38,   -1,  282,  283,   42,   43,
  124,   45,   -1,   47,   -1,   -1,   -1,  281,  282,  283,
   -1,   -1,   93,   -1,   -1,   59,   60,   61,   62,   -1,
   -1,   37,   38,   -1,   -1,   -1,   42,   43,   38,   45,
   40,   47,   42,   -1,   -1,   45,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   60,   61,   62,   37,   38,   -1,
   -1,   -1,   42,   43,  124,   45,   -1,   47,   37,   38,
   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,   59,
   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,   37,
  124,   60,   61,   62,   42,   43,   -1,   45,   38,   47,
   -1,   41,   -1,   43,   44,   45,   -1,   -1,   -1,   -1,
   -1,   -1,   60,   61,   62,  264,   -1,   -1,  124,   59,
   60,   61,   62,   -1,   -1,   -1,  126,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,
   38,   -1,   -1,   41,  124,   43,   44,   45,   -1,   -1,
   -1,   38,   -1,   93,   41,  124,   -1,   44,   -1,   -1,
   -1,   59,   60,   61,   62,   -1,   -1,  281,  282,  283,
   -1,   -1,   59,   60,   61,   62,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,  124,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,   -1,   -1,   93,   -1,   59,   60,   61,
   62,   -1,   -1,   -1,   -1,   -1,   93,   59,   -1,   61,
  281,  282,  283,   38,   -1,   -1,   41,   -1,   -1,   44,
   -1,  281,  282,  283,   -1,   -1,  124,   -1,   -1,   38,
   -1,   93,   41,   -1,   59,   44,   61,  124,   -1,   -1,
   -1,   93,   -1,   -1,   -1,   -1,   -1,  281,  282,  283,
   59,   60,   61,   62,   -1,   -1,   -1,  257,  258,  259,
  260,   -1,  124,  269,   38,   -1,   -1,   41,   93,   -1,
   44,   -1,  124,   -1,   -1,  281,  282,  283,  278,  279,
   -1,   -1,   -1,   -1,   93,   59,   60,   61,   62,   -1,
   -1,   38,   -1,   40,   -1,   42,   -1,   -1,   45,  124,
   -1,  281,  282,  283,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  281,  282,  283,  124,   38,   -1,   40,   93,
   42,  261,   -1,   45,  264,   -1,   -1,  267,  268,  269,
   -1,   -1,   -1,  281,  282,  283,   -1,   -1,   -1,   -1,
   -1,  281,  282,  283,   -1,   38,   -1,   40,   -1,   42,
  124,   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,   41,   -1,  261,   44,  123,  264,  125,  126,
  267,  268,  269,  281,  282,  283,   -1,   -1,   -1,   -1,
   59,   -1,   -1,   -1,  281,  282,  283,   -1,   -1,  261,
   -1,  123,  264,  125,  126,  267,  268,  269,   -1,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,  281,
  282,  283,   -1,   -1,   93,   -1,   -1,   -1,   -1,  281,
  123,   -1,   -1,  126,   -1,   -1,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   -1,   38,   -1,   40,   41,
   42,   -1,  261,   45,   -1,  264,  281,   -1,  267,  268,
  269,   -1,   -1,   -1,   -1,   38,   -1,   -1,   41,   -1,
   -1,   44,  281,  282,  283,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   -1,   -1,   -1,   59,  261,   41,   -1,
  264,   44,   -1,  267,  268,  269,   59,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   59,  281,  282,  283,
  257,  258,  259,  260,  261,  262,  263,   -1,  265,   -1,
   93,   -1,   -1,  270,  271,   -1,   -1,   -1,   -1,   -1,
   93,  278,  279,   -1,  126,  257,  258,  259,  260,  261,
   93,  263,   -1,  265,   -1,   -1,   -1,   -1,  270,  271,
   -1,  124,   -1,   -1,   -1,   -1,  278,  279,   -1,   -1,
   -1,  124,   -1,   -1,  257,  258,  259,  260,  261,   -1,
  263,  124,  265,   -1,   -1,   -1,   -1,  270,  271,   -1,
   -1,   -1,   -1,   -1,   -1,  278,  279,   -1,   -1,   -1,
   -1,   -1,  261,   -1,   39,  264,   -1,   -1,  267,  268,
  269,   46,   -1,   48,   -1,   -1,   51,   52,   53,   -1,
   -1,   56,   -1,   -1,   -1,   60,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  105,   -1,   -1,   -1,   -1,  257,  258,  259,  260,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,  261,   -1,
  135,  264,   -1,   -1,  267,  268,  269,   -1,  261,   -1,
  145,  264,   47,   -1,  267,  268,  269,   -1,  261,   54,
   55,  264,   57,   -1,  267,  268,  269,   -1,   -1,   64,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   84,
   85,   86,   87,   88,   89,   90,   91,   92,   93,   94,
   95,   96,   97,   98,   99,   -1,   -1,   -1,   -1,  104,
   -1,  106,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  127,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  139,   -1,   -1,  142,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 330
#define YYUNDFTOKEN 355
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
"tFINST","tTIPOSTAR","tFEXPSTP","tFLVEX","tUPDOWN","tFORX","tPARAM","tSTMT1",
"tSTMTN","tSTMTSTARTID","tSTMTPRMTCORP",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : file",
"file :",
"file : file stmt",
"stmt : pubOuConstOrNone tipo astOrNon ID initOrNon ';'",
"stmt : pubOuConstOrNone tipo astOrNon ID '(' prmtsOrNon ')' crpOrNon ';'",
"initOrNon :",
"initOrNon : ATR init",
"pubOuConstOrNone : cnstOrNon",
"pubOuConstOrNone : PUBLIC cnstOrNon",
"astOrNon :",
"astOrNon : '*'",
"tipo : INTEGER",
"tipo : STRING",
"tipo : NUMBER",
"tipo : VOID",
"init :",
"init : INT",
"init : cnstOrNon STR",
"init : REAL",
"init : ID",
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
"expressao : ID '(' args ')'",
"expressao : ID '(' ')'",
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
#line 191 "diy.y"
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

void minusChecking(int tipo) {
	if (!(tipo == vint || tipo == vreal || tipo == vreal + vconst || tipo == vint + vconst))
		yyerror("Invalid operation");
}

void isIntRealStrVoid(int tipo) {
	if (!(tipo == vint || tipo == vreal || tipo == vreal + vconst || tipo == vint + vconst || tipo == vstr || tipo == vstr + vconst || tipo == vvoid || tipo == vvoid + vconst))
		yyerror("Invalid operation");

}

void isInt(int tipo, int canBeConst) {
	if (canBeConst)
		if (!(tipo == vint + vconst))
			yyerror("Invalid operation");
	if (tipo != vint)
		yyerror("Invalid operation");
}

int areIntOrReal(int first, int second) {
	if (!(first == vint + vconst || first == vreal + vconst || second == vint + vconst || second == vreal+ vconst || first == vint || first == vreal || second == vint || second == vreal)) {
			yyerror("Invalid operation");
			return 0;
	}

	return first%10>second%10 ? first : second;

}

void areIntRealOrStr(int first, int second) {
	if ((first == vint || first == vreal || first == vint + vconst || first == vreal + vconst ) && ( second == vint + vconst || second == vreal+ vconst || second == vint || second == vreal))
		return;
	if ((first == vstr  || first == vstr + vconst) && (second == vstr || second == vstr + vconst))
		return;
	yyerror("Invalid operation");

		
}

void areInt(int first, int second) {
	if (!(first == vint || first == vint + vconst || second == vint || second == vint + vconst))
		yyerror("Invalid operation");

}

void verificacoesSTMT(int pubOrConst, int tipo, int ast, char* id, int init) {
	
	// se e so const sem public
	if (pubOrConst == vconst && !init)
		yyerror("Const variable must inicialized");

	// se um e const e outro nao, da erro
	if (!(tipo>vconst && tipo<vconst && init>vconst && init<vconst ))
		yyerror("Const variable must inicialized with const value");	


	// ver se tipos sao iguais
	if (tipo%10 == init%10)
		// se init for ponteiro
		if (init>vptr && init<vconst) {
			if (ast)
				IDnew(tipo,id,0);
			else 
				yyerror("Non compatible types");
		}
		
		// init nao tem ponteiro
		else {
			if (ast)
				yyerror("Non compatible types");
			else
				IDnew(tipo,id,0);
		}		
}

int verificacaoPonteiro(int lval) {
	// se lval for ponteiro
	if (lval>=vptr && lval <= vconst) {

		// se for string retorna int
		if (lval%10 == vstr)
			return lval-vstr-vptr+vint;

		else return lval-vptr;
	}
	return 0;
}

int verificacoesPonteiro(int lval, int exp) {
	if (exp%10 != vint) {
		yyerror("Index must be integer");
		return 0;
	}
	return verificacaoPonteiro(lval);
}

void verificacaoAtribuicoes(int lval, int exp) {
	// para o caso em que e retorno de funcao 
	if (lval == -1) return;
	
	// se estamos a atribuir valor a um const
	if (lval>=vconst && lval<=vpublic)
		yyerror("Cannot attribute new value to a const");	

	else if (((lval%10 == vint || lval%10 == vreal) && !(exp%10 == vint || exp%10 == vreal )) || ((exp%10 == vint || exp%10 == vreal ) && !(lval%10 == vint || lval%10 == vreal)))
		yyerror("Atribution should be with int or real");

	// atribuicao de um *int a uma string e valida
	else if (lval%10 == vstr && exp%10 == vint && exp>vptr && exp<vconst)
		return;

	else if (lval%10 != exp%10)
		yyerror("Invalid atribution");
			
}
#line 777 "y.tab.c"

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
#line 53 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 2:
#line 54 "diy.y"
	{ yyval.n = binNode(tFILE, yystack.l_mark[-1].n, yystack.l_mark[0].n ); printNode(yyval.n, 0, (char**)yyname); }
break;
case 3:
#line 57 "diy.y"
	{ yyval.n = binNode(tSTMT, binNode(tPUBeTIPO, yystack.l_mark[-5].n, yystack.l_mark[-4].n),binNode(tSTARMORE, yystack.l_mark[-3].n, binNode(tIDINIT, strNode(ID, yystack.l_mark[-2].s), yystack.l_mark[-1].n ))); verificacoesSTMT( yystack.l_mark[-5].n->info, yystack.l_mark[-4].n->info, yystack.l_mark[-3].n->info, yystack.l_mark[-2].s, yystack.l_mark[-1].n->info); }
break;
case 4:
#line 58 "diy.y"
	{ yyval.n = binNode(tSTMT1, binNode(tPUBeTIPO, yystack.l_mark[-8].n, yystack.l_mark[-7].n), binNode(tSTMTN, binNode(tSTMTSTARTID, yystack.l_mark[-6].n, strNode(ID, yystack.l_mark[-5].s)), binNode(tSTMTPRMTCORP, yystack.l_mark[-3].n, yystack.l_mark[-1].n))); /*TODO*/}
break;
case 5:
#line 62 "diy.y"
	{ yyval.n = nilNode(tEND); yyval.n->info = 0;}
break;
case 6:
#line 63 "diy.y"
	{ yyval.n = uniNode(ATR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 7:
#line 66 "diy.y"
	{ yyval.n = binNode(tPUBoN, nilNode(tEND), yystack.l_mark[0].n ); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 8:
#line 67 "diy.y"
	{ yyval.n = binNode(tPUBoN, nilNode(PUBLIC), yystack.l_mark[0].n ); yyval.n->info = yystack.l_mark[0].n->info + vpublic;}
break;
case 9:
#line 71 "diy.y"
	{ yyval.n = nilNode(tEND); yyval.n->info = 0;}
break;
case 10:
#line 72 "diy.y"
	{ yyval.n = nilNode(tSTAR); yyval.n->info = vptr;}
break;
case 11:
#line 75 "diy.y"
	{ yyval.n = nilNode(INTEGER); yyval.n->info = vint;}
break;
case 12:
#line 76 "diy.y"
	{ yyval.n = nilNode(STRING); yyval.n->info = vstr;}
break;
case 13:
#line 77 "diy.y"
	{ yyval.n = nilNode(NUMBER); yyval.n->info = vreal;}
break;
case 14:
#line 78 "diy.y"
	{ yyval.n = nilNode(VOID); yyval.n->info = vvoid;}
break;
case 15:
#line 81 "diy.y"
	{ yyval.n = nilNode(tEND); yyval.n->info = 0;}
break;
case 16:
#line 82 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = vint;}
break;
case 17:
#line 83 "diy.y"
	{ yyval.n = binNode(tCONSTSTR, yystack.l_mark[-1].n, strNode(STR, yystack.l_mark[0].s)); yyval.n->info = yystack.l_mark[-1].n->info + vstr;}
break;
case 18:
#line 84 "diy.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[0].r); yyval.n->info=vreal;}
break;
case 19:
#line 85 "diy.y"
	{ yyval.n = strNode(ID, yystack.l_mark[0].s); yyval.n->info=IDfind(yystack.l_mark[0].s, NULL);}
break;
case 20:
#line 88 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 21:
#line 89 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 22:
#line 93 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 23:
#line 94 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 24:
#line 97 "diy.y"
	{ yyval.n = nilNode(tEND); yyval.n->info = 0;}
break;
case 25:
#line 98 "diy.y"
	{ yyval.n = nilNode(CONST); yyval.n->info = vconst;}
break;
case 26:
#line 101 "diy.y"
	{ yyval.n = binNode(tPARA, yystack.l_mark[0].n, nilNode(tEND)); }
break;
case 27:
#line 102 "diy.y"
	{ yyval.n = binNode(tPARA, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 28:
#line 105 "diy.y"
	{ yyval.n = binNode(tTIPOSTAR, yystack.l_mark[-2].n, binNode(tSTARID, yystack.l_mark[-1].n, strNode(ID, yystack.l_mark[0].s))); 
										IDnew (yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info, yystack.l_mark[0].s, 0); 
										yyval.n->info = yystack.l_mark[-2].n->info + yystack.l_mark[-1].n->info;}
break;
case 29:
#line 110 "diy.y"
	{ yyval.n = binNode(tCORPO, yystack.l_mark[-2].n, yystack.l_mark[-1].n);}
break;
case 30:
#line 113 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 31:
#line 114 "diy.y"
	{ yyval.n = binNode(tPARAM, yystack.l_mark[-2].n, yystack.l_mark[0].n);}
break;
case 32:
#line 118 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 33:
#line 119 "diy.y"
	{ yyval.n = binNode(tINSTM, yystack.l_mark[-1].n, yystack.l_mark[0].n);}
break;
case 34:
#line 122 "diy.y"
	{ yyval.n = binNode(IF, binNode(THEN, yystack.l_mark[-3].n, yystack.l_mark[-1].n), yystack.l_mark[0].n); }
break;
case 35:
#line 123 "diy.y"
	{ yyval.n = binNode(WHILE, yystack.l_mark[-3].n, yystack.l_mark[-1].n); }
break;
case 36:
#line 124 "diy.y"
	{ yyval.n = binNode(tFINST, binNode(tFORX, binNode(tFLVEX, yystack.l_mark[-7].n, yystack.l_mark[-5].n), binNode(tUPDOWN, yystack.l_mark[-4].n, binNode(tFEXPSTP, yystack.l_mark[-3].n, yystack.l_mark[-2].n))), yystack.l_mark[0].n); }
break;
case 37:
#line 125 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 38:
#line 126 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 39:
#line 127 "diy.y"
	{ yyval.n = uniNode(BREAK, yystack.l_mark[-1].n);  }
break;
case 40:
#line 128 "diy.y"
	{ yyval.n = uniNode(CONTINUE, yystack.l_mark[-1].n);  }
break;
case 41:
#line 129 "diy.y"
	{ yyval.n = binNode(tALLOC, yystack.l_mark[-1].n, yystack.l_mark[-3].n); }
break;
case 42:
#line 132 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 43:
#line 133 "diy.y"
	{ yyval.n = uniNode(STEP, yystack.l_mark[0].n);  }
break;
case 44:
#line 136 "diy.y"
	{ yyval.n = nilNode(UPTO); }
break;
case 45:
#line 137 "diy.y"
	{ yyval.n = nilNode(DOWNTO); }
break;
case 46:
#line 140 "diy.y"
	{ yyval.n = nilNode(tEND); }
break;
case 47:
#line 141 "diy.y"
	{ yyval.n = uniNode(ELSE, yystack.l_mark[0].n);  }
break;
case 48:
#line 144 "diy.y"
	{ yyval.n = nilNode(tEND); yyval.n->info = 0;}
break;
case 49:
#line 145 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = vint; }
break;
case 50:
#line 148 "diy.y"
	{ yyval.n = strNode(ID , yystack.l_mark[0].s); yyval.n->info = IDfind(yystack.l_mark[0].s, NULL); }
break;
case 51:
#line 149 "diy.y"
	{ yyval.n = binNode(tINDEX, yystack.l_mark[-3].n, yystack.l_mark[-1].n); yyval.n->info = verificacoesPonteiro(yystack.l_mark[-3].n->info, yystack.l_mark[-1].n->info);  }
break;
case 52:
#line 150 "diy.y"
	{ yyval.n = uniNode(tLOAD, yystack.l_mark[0].n); yyval.n->info = verificacaoPonteiro(yystack.l_mark[0].n->info);  }
break;
case 53:
#line 153 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = vint;}
break;
case 54:
#line 154 "diy.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[0].r); yyval.n->info = vreal;}
break;
case 55:
#line 155 "diy.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = vstr; }
break;
case 56:
#line 156 "diy.y"
	{ yyval.n = uniNode(tLOAD, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info;}
break;
case 57:
#line 157 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; yyval.n->info = yystack.l_mark[-1].n->info;}
break;
case 58:
#line 158 "diy.y"
	{ yyval.n = binNode(tCALL, strNode(ID , yystack.l_mark[-3].s), yystack.l_mark[-1].n); }
break;
case 59:
#line 159 "diy.y"
	{ yyval.n = binNode(tCALL, strNode(ID , yystack.l_mark[-2].s), nilNode(tEND)); }
break;
case 60:
#line 160 "diy.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); minusChecking(yystack.l_mark[0].n->info); yyval.n->info = (yystack.l_mark[0].n->info > vconst) ? yystack.l_mark[0].n->info - vconst + vptr : yystack.l_mark[0].n->info + vptr;}
break;
case 61:
#line 161 "diy.y"
	{ yyval.n = uniNode(tPTR, yystack.l_mark[0].n); isIntRealStrVoid(yystack.l_mark[0].n->info); yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 62:
#line 162 "diy.y"
	{ yyval.n = uniNode(tNOT, yystack.l_mark[0].n); isInt(yystack.l_mark[0].n->info, 1);}
break;
case 63:
#line 163 "diy.y"
	{ yyval.n = binNode(INCR, yystack.l_mark[-1].n, intNode(INT, 1)); isInt(yystack.l_mark[-1].n->info, 0);}
break;
case 64:
#line 164 "diy.y"
	{ yyval.n = binNode(DECR, yystack.l_mark[-1].n, intNode(INT, 1)); isInt(yystack.l_mark[-1].n->info, 0);}
break;
case 65:
#line 165 "diy.y"
	{ yyval.n = binNode(INCR, intNode(INT, 1),  yystack.l_mark[0].n ); isInt(yystack.l_mark[0].n->info, 0);}
break;
case 66:
#line 166 "diy.y"
	{ yyval.n = binNode(DECR, intNode(INT, 1),  yystack.l_mark[0].n ); isInt(yystack.l_mark[0].n->info, 0);}
break;
case 67:
#line 168 "diy.y"
	{ yyval.n = binNode(tMUL, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = areIntOrReal(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); }
break;
case 68:
#line 169 "diy.y"
	{ yyval.n = binNode(tDIV, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = areIntOrReal(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); }
break;
case 69:
#line 170 "diy.y"
	{ yyval.n = binNode(tMOD, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = areIntOrReal(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 70:
#line 171 "diy.y"
	{ yyval.n = binNode(tADD, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = areIntOrReal(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); }
break;
case 71:
#line 172 "diy.y"
	{ yyval.n = binNode(tSUB, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = areIntOrReal(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); }
break;
case 72:
#line 173 "diy.y"
	{ yyval.n = binNode(tLT, yystack.l_mark[-2].n, yystack.l_mark[0].n); areIntRealOrStr(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = vint;}
break;
case 73:
#line 174 "diy.y"
	{ yyval.n = binNode(tGT, yystack.l_mark[-2].n, yystack.l_mark[0].n); areIntRealOrStr(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = vint;}
break;
case 74:
#line 175 "diy.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); areIntRealOrStr(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = vint;}
break;
case 75:
#line 176 "diy.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); areIntRealOrStr(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = vint;}
break;
case 76:
#line 177 "diy.y"
	{ yyval.n = binNode(tEQ, yystack.l_mark[-2].n, yystack.l_mark[0].n); areIntRealOrStr(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = vint;}
break;
case 77:
#line 178 "diy.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); areIntRealOrStr(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info); yyval.n->info = vint;}
break;
case 78:
#line 179 "diy.y"
	{ yyval.n = binNode(tAND, yystack.l_mark[-2].n, yystack.l_mark[0].n); areInt(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 79:
#line 180 "diy.y"
	{ yyval.n = binNode(tOR, yystack.l_mark[-2].n, yystack.l_mark[0].n); areInt(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 80:
#line 181 "diy.y"
	{ yyval.n = binNode(ATR, yystack.l_mark[0].n, yystack.l_mark[-2].n); verificacaoAtribuicoes(yystack.l_mark[-2].n->info, yystack.l_mark[0].n->info);}
break;
case 81:
#line 184 "diy.y"
	{ yyval.n = binNode(tARG, yystack.l_mark[0].n, nilNode(tEND)); }
break;
case 82:
#line 185 "diy.y"
	{ yyval.n = binNode(tARG, yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
#line 1306 "y.tab.c"
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
