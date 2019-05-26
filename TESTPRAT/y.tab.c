/* original parser id follows */
/* yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93" */
/* (use YYMAJOR/YYMINOR for ifdefs dependent on parser version) */

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20140715

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)
#define YYENOMEM       (-2)
#define YYEOF          0
#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "diy.y"
/* $Id: diy.y,v 1.0 2019/02/06 17:25:13 prs Exp $ */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.h"
#include "tabid.h"

extern int yylex();
extern void function(int pub, Node *type, char *name, Node *body);
extern void externs();
extern void globalVariable(int pub, int cnst, Node *type, char *name, Node *value) ;
void yyerror(char *s);
void declare(int pub, int cnst, Node *type, char *name, Node *value);
void enter(int pub, int typ, char *name);
int checkargs(char *name, Node *args);
int nostring(Node *arg1, Node *arg2);
int intonly(Node *arg, int);
int noassign(Node *arg1, Node *arg2);
static int ncicl;
static char *fpar;
int sizeOfLocalVariable = 0;
int sizeOfArgs = 8;
#line 27 "diy.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
	Node *n;		/* node pointer */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 59 "y.tab.c"

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
#define IFX 280
#define ELSE 281
#define ATR 282
#define NE 283
#define GE 284
#define LE 285
#define UMINUS 287
#define NOT 288
#define REF 289
#define LOCAL 290
#define POSINC 291
#define POSDEC 292
#define PTR 293
#define CALL 294
#define START 295
#define PARAM 296
#define NIL 297
#define YYERRCODE 256
typedef short YYINT;
static const YYINT yylhs[] = {                           -1,
    0,   21,   21,   21,   21,   21,   21,   22,   21,   23,
   21,   20,   20,   18,   18,    1,    1,    1,    2,    2,
    2,    2,    2,    2,    2,    3,    3,    4,    4,    5,
    5,   24,    6,    7,    7,    8,   10,   10,    9,   25,
    9,   26,    9,   27,    9,    9,    9,    9,    9,    9,
    9,   14,   14,   15,   15,   11,   11,   19,   19,   13,
   13,   12,   12,   16,   16,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,   17,   17,   17,   17,
   17,   17,   17,   17,   17,   17,
};
static const YYINT yylen[] = {                            2,
    1,    0,    3,    5,    6,    5,    6,    0,    6,    0,
    6,    0,    1,    0,    1,    2,    2,    2,    3,    3,
    4,    3,    4,    3,    4,    4,    3,    1,    2,    1,
    3,    0,    6,    0,    3,    2,    1,    1,    1,    0,
    6,    0,   10,    0,   10,    4,    6,    2,    1,    4,
    2,    0,    1,    3,    3,    0,    2,    0,    1,    1,
    2,    1,    3,    1,    4,    1,    2,    3,    1,    1,
    1,    2,    2,    2,    2,    3,    2,    2,    2,    2,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    3,    3,    3,    4,    3,
};
static const YYINT yydefred[] = {                         2,
    0,    0,    0,   13,    0,    3,    0,    0,    0,    0,
    0,    0,   10,   15,   16,   17,   18,    0,    0,    0,
    0,    0,    4,    6,    0,    0,   11,    5,    7,    0,
    0,    0,    0,    0,    0,    9,    0,    0,    0,   30,
   20,   24,   19,   22,    0,    0,    0,   28,   32,   27,
    0,   36,    0,    0,   23,   21,   25,   34,   29,   26,
   31,    0,    0,   69,   71,    0,   70,   40,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   39,   49,    0,
   60,    0,    0,    0,   51,    0,    0,    0,    0,    0,
    0,    0,   77,   78,   74,    0,    0,   67,    0,   35,
    0,    0,   61,    0,   53,   79,   80,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   75,   48,    0,    0,   96,    0,    0,   37,
    0,   38,    0,    0,   94,   59,    0,    0,   33,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   65,   95,    0,    0,    0,
    0,   54,   55,   50,    0,    0,    0,    0,    0,   41,
   47,    0,    0,    0,    0,    0,    0,   42,   44,    0,
    0,   43,   45,
};
static const YYINT yydgoto[] = {                          1,
   38,   24,   27,   50,   39,   79,   62,   40,  130,  131,
  175,  128,   82,  104,  132,   89,   84,   15,  137,    5,
    2,   25,   20,   58,   88,  180,  181,
};
static const YYINT yysindex[] = {                         0,
    0, -238,  -25,    0, -170,    0, -217,   10,   10,   10,
 -181, -201,    0,    0,    0,    0,    0, -193,  -56,   33,
  -40,  -39,    0,    0,   33,  -34,    0,    0,    0,   16,
   36,   49,   50, -150, -233,    0,  -44, -146,  -21,    0,
    0,    0,    0,    0,   55,   56,   61,    0,    0,    0,
   63,    0,  -44, -181,    0,    0,    0,    0,    0,    0,
    0, 1027,   64,    0,    0,  -24,    0,    0, 1050, -135,
 -135, -135, -135, 1050, 1050, -135, 1050,    0,    0,   66,
    0, 1086,  -22,  105,    0, 1050,  737, 1086, -208,  144,
   35, -138,    0,    0,    0,   37,   37,    0,  252,    0,
 -128, -128,    0,    5,    0,    0,    0, 1050, 1050, 1050,
 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050, 1050,
 1050, 1050,    0,    0, 1050,  288,    0,   13,  470,    0,
 -125,    0, 1086, 1050,    0,    0,   82,   86,    0,  470,
  332,  481,  507,  514,  514,  602,  602,  602,  602,  107,
  107,  -16,  -16,  -16,  470,    0,    0, 1050, 1050, -142,
   74,    0,    0,    0,  470,  372, 1086, 1050, 1050,    0,
    0,  403,  403, 1050, -115, -110,  470,    0,    0, 1086,
 1086,    0,    0,
};
static const YYINT yyrindex[] = {                         0,
    0,    1,    0,    0,    0,    0,    0, -106, -106, -106,
    0,    0,    0,    0,    0,    0,    0,    0,  115,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -33,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   31,  439,    0,    0,    0,    0,    0,   39,    0,
    3,    0,    0,    0,    0,  543,  581,    0,    0,    0,
   98,   98,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   15,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  134,
    0, 1011,   -6,  842,  960,  700,  888,  914,  949,  814,
  853,  621,  656,  776, 1030,    0,    0,    0,    0,  990,
    0,    0,    0,    0,   44,    0,    0,    0,    0,    0,
    0, -103, -103,    0,    0,    0, -102,    0,    0,    0,
    0,    0,    0,
};
static const YYINT yygindex[] = {                         0,
   32,  139,  136,  109,    0,   -4,    0,  -32,  -31, -112,
   -3,    0,    0,    0,   87,  290, 1284,   80,   69,    0,
    0,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1458
static const YYINT yytable[] = {                         64,
    1,   64,   23,   64,   64,   35,   37,   64,   64,   64,
   64,   64,  109,   64,   48,   87,  123,    3,   28,   53,
  160,   61,   54,   46,   47,   64,   64,   64,   64,   80,
   81,   92,   51,    6,   92,   64,   12,   92,    4,   64,
   64,   13,   18,   64,   64,   64,   64,   64,   51,   64,
  103,   14,   92,  157,  171,   62,  158,   19,   62,   64,
   64,   64,   64,   64,   64,   21,   86,  182,  183,  106,
  107,   66,   26,  108,   41,   66,   66,  125,   49,   66,
   66,   66,   66,   66,   63,   66,   92,   63,   16,   17,
   64,    8,    9,   10,   42,   64,   64,   66,   66,   66,
   66,    7,    8,    9,   10,   11,  123,   43,   44,   45,
  122,  111,   52,   55,   56,  120,  118,   92,  119,   57,
  121,   59,   85,   91,  100,   86,   64,  134,  136,  139,
  125,   66,   66,  117,  112,  116,  159,  123,  167,  123,
  162,  122,  111,  122,  163,  178,  120,  118,  120,  119,
  179,  121,   14,  121,    8,   52,   58,   56,   57,   29,
   36,   60,   66,  124,  117,  112,  116,  125,  105,  176,
  138,    0,    0,    0,   68,    0,  123,   68,    0,    0,
  122,  111,    0,    0,    0,  120,  118,    0,  119,    0,
  121,    0,   68,    0,    0,    0,    0,  110,  125,    0,
  125,    0,    0,  117,  112,  116,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   30,   31,   32,
   33,    0,    0,    0,    0,   22,   68,   64,  110,    0,
   64,    0,    0,   64,   64,   64,   34,  125,    8,    9,
   10,   22,    0,    0,   64,   64,    0,    0,   64,   64,
   64,   64,    0,    0,   92,  106,  107,   92,    0,  108,
   92,   92,   92,   64,    0,    0,   64,  110,   64,   64,
   64,   64,   12,   12,   12,   12,   12,    0,    0,    0,
    0,    0,    0,    0,  123,   64,   64,   64,  122,  111,
    0,    0,  135,  120,  118,    0,  119,    0,  121,   66,
    0,    0,   66,    0,    0,   66,   66,   66,    0,    0,
    0,  117,  112,  116,    0,    0,    0,    0,    0,    0,
  123,   66,   66,   66,  122,  111,    0,    0,    0,  120,
  118,    0,  119,    0,  121,    0,    0,    0,    0,    0,
  168,  169,    0,    0,    0,  125,    0,  117,  112,  116,
    0,   83,    0,    0,    0,    0,  113,  114,  115,   92,
   93,   94,   95,    0,  123,   98,    0,    0,  122,  111,
    0,   83,    0,  120,  118,  110,  119,   83,  121,    0,
  156,  125,    0,    0,    0,    0,    0,  113,  114,  115,
  164,  117,  112,  116,   68,    0,    0,   68,    0,    0,
   68,   68,   68,    0,  123,    0,    0,  133,  122,  111,
    0,  110,    0,  120,  118,    0,  119,    0,  121,    0,
    0,    0,   83,    0,    0,  125,  113,  114,  115,    0,
  170,  117,  112,  116,    0,  123,    0,    0,    0,  122,
  111,    0,    0,    0,  120,  118,    0,  119,    0,  121,
    0,    0,    0,    0,    0,  110,   83,    0,    0,    0,
    0,    0,  117,  112,  116,  125,    0,    0,    0,   83,
   83,   66,    0,    0,    0,   66,   66,    0,    0,    0,
   66,   66,    0,   66,    0,   66,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  110,  125,   66,   66,   66,
   66,    0,  123,    0,    0,    0,  122,  111,    0,    0,
    0,  120,  118,  123,  119,    0,  121,  122,  111,    0,
    0,    0,  120,  118,    0,  119,  110,  121,    0,  117,
  112,  116,   66,    0,  113,  114,  115,    0,    0,  123,
  117,  112,  116,  122,    0,    0,  123,    0,  120,  118,
  122,  119,    0,  121,    0,  120,  118,    0,  119,    0,
  121,    0,   66,  125,    0,    0,  117,  112,  116,    0,
  113,  114,  115,  117,  125,  116,    0,    0,    0,   73,
   73,    0,    0,   73,   73,   73,   73,   73,    0,   73,
    0,    0,    0,  110,    0,    0,    0,    0,    0,    0,
  125,   73,   73,   73,   73,    0,    0,  125,    0,    0,
    0,    0,    0,    0,  113,  114,  115,   72,   72,    0,
    0,   72,   72,   72,   72,   72,    0,   72,    0,    0,
    0,    0,    0,    0,  123,   73,    0,    0,  122,   72,
   72,   72,   72,  120,  118,    0,  119,    0,  121,    0,
    0,    0,    0,    0,  113,  114,  115,   83,   83,    0,
    0,   83,   83,   83,   83,   83,   73,   83,    0,    0,
    0,  174,    0,   72,    0,    0,    0,    0,    0,   83,
   83,   83,   83,    0,    0,  113,  114,  115,    0,    0,
    0,    0,   84,   84,    0,  125,   84,   84,   84,   84,
   84,    0,   84,    0,   72,    0,    0,    0,    0,    0,
    0,    0,    0,   83,   84,   84,   84,   84,    0,    0,
    0,   66,   66,   66,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   88,    0,    0,
   88,    0,    0,   88,   83,    0,    0,    0,   84,    0,
    0,    0,  113,  114,  115,    0,    0,    0,   88,   88,
   88,   88,    0,  113,  114,  115,    0,    0,    0,    0,
    0,    0,    0,    0,   73,    0,   77,  127,   76,   84,
    0,   75,    0,    0,    0,    0,    0,    0,    0,  113,
  114,  115,   88,    0,    0,    0,    0,  114,  115,    0,
    0,    0,    0,   73,    0,    0,   73,    0,    0,   73,
   73,   73,   85,   85,    0,    0,   85,   85,   85,   85,
   85,    0,   85,   88,    0,   73,   73,   73,    0,    0,
    0,    0,    0,    0,   85,   85,   85,   85,    0,    0,
    0,   72,    0,    0,   72,    0,    0,   72,   72,   72,
    0,   81,    0,    0,   81,    0,   81,   81,   81,    0,
    0,    0,   74,   72,   72,   72,    0,    0,   85,    0,
    0,    0,   81,   81,   81,   81,    0,    0,    0,   91,
    0,   83,   91,    0,   83,   91,    0,   83,   83,   83,
   82,    0,    0,   82,    0,   82,   82,   82,    0,   85,
   91,    0,   91,   83,   83,   83,   81,    0,    0,    0,
    0,   82,   82,   82,   82,    0,   84,    0,    0,   84,
    0,    0,   84,   84,   84,   89,    0,    0,   89,    0,
    0,   89,    0,    0,   91,    0,    0,   81,   84,   84,
   84,    0,    0,    0,    0,   82,   89,   89,   89,   89,
    0,   87,    0,    0,   87,    0,    0,   87,    0,    0,
   88,    0,    0,   88,    0,   91,   88,   88,   88,    0,
    0,    0,   87,   87,   87,   87,   82,    0,    0,    0,
   89,    0,   88,   88,   88,    0,   86,    0,    0,   86,
    0,    0,   86,   64,   65,   66,   67,   90,    0,    0,
   90,    0,    0,   90,    0,    0,   87,   86,   86,   86,
   86,   89,    0,    0,   71,   72,    0,    0,   90,    0,
   90,    0,    0,    0,    0,    0,    0,   46,    0,   46,
    0,   46,    0,    0,   46,    0,   85,   87,    0,   85,
    0,   86,   85,   85,   85,    0,    0,    0,   46,    0,
    0,   93,   90,    0,   93,    0,    0,    0,   85,   85,
   85,    0,    0,    0,   73,    0,   77,    0,   76,   93,
   76,   75,   86,   76,   81,    0,    0,   81,    0,    0,
   81,   81,   81,   90,    0,   78,    0,   73,   76,   77,
    0,   76,    0,    0,   75,    0,   81,   81,   81,    0,
    0,    0,   91,   93,    0,   91,    0,    0,   91,   91,
   91,    0,   46,   82,   46,   46,   82,    0,    0,   82,
   82,   82,   76,   73,   91,   77,    0,   76,    0,    0,
   75,    0,    0,    0,   93,   82,   82,   82,    0,    0,
    0,    0,    0,    0,   78,    0,    0,    0,   89,   49,
    0,   89,   74,    0,   89,   89,   89,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   89,   89,   89,    0,   87,   74,    0,   87,    0,    0,
   87,   87,   87,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   87,   87,   87,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   49,   86,
    0,   74,   86,    0,    0,   86,   86,   86,    0,    0,
   90,    0,    0,   90,    0,    0,   90,   90,   90,    0,
    0,   86,   86,   86,    0,    0,    0,    0,    0,    0,
    0,    0,   90,    0,    0,   46,   46,   46,   46,   46,
   46,   46,   46,    0,   46,    0,    0,    0,    0,   46,
   46,    0,    0,    0,    0,    0,    0,   46,   46,    0,
    0,   93,    0,    0,   93,    0,    0,   93,   93,   93,
    0,    0,   63,   64,   65,   66,   67,   68,    0,   69,
   76,   70,    0,   76,    0,    0,   76,   76,   76,    8,
    9,   10,    0,    0,   71,   72,   64,   65,   66,   67,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   71,   72,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   63,   64,   65,   66,   67,   68,    0,   69,    0,
   70,    0,   90,    0,    0,  101,  102,   96,   97,    0,
   99,    0,    0,   71,   72,    0,    0,    0,    0,  126,
  129,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  140,  141,  142,  143,  144,  145,  146,  147,  148,
  149,  150,  151,  152,  153,  154,    0,    0,  155,    0,
    0,    0,    0,    0,    0,    0,    0,  161,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  165,  166,    0,    0,    0,    0,    0,    0,    0,
    0,  172,  173,    0,    0,    0,    0,  177,
};
static const YYINT yycheck[] = {                         33,
    0,   35,   59,   37,   38,   45,   41,   41,   42,   43,
   44,   45,   35,   47,   59,   40,   33,  256,   59,   41,
  133,   54,   44,  257,  258,   59,   60,   61,   62,   62,
   62,   38,   37,   59,   41,   33,    5,   44,  277,   37,
   38,  259,   11,   41,   42,   43,   44,   45,   53,   47,
   82,   42,   59,   41,  167,   41,   44,  259,   44,   93,
   94,   59,   60,   61,   62,  259,   91,  180,  181,  278,
  279,   33,   40,  282,   59,   37,   38,   94,  123,   41,
   42,   43,   44,   45,   41,   47,   93,   44,    9,   10,
  124,  273,  274,  275,   59,   93,   94,   59,   60,   61,
   62,  272,  273,  274,  275,  276,   33,   59,   59,  260,
   37,   38,  259,   59,   59,   42,   43,  124,   45,   59,
   47,   59,   59,  259,   59,   91,  124,  266,  257,  125,
   94,   93,   94,   60,   61,   62,  262,   33,  281,   33,
   59,   37,   38,   37,   59,  261,   42,   43,   42,   45,
  261,   47,  259,   47,   40,  125,   59,  261,  261,   21,
   25,   53,  124,   59,   60,   61,   62,   94,   82,  173,
  102,   -1,   -1,   -1,   41,   -1,   33,   44,   -1,   -1,
   37,   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,   59,   -1,   -1,   -1,   -1,  124,   94,   -1,
   94,   -1,   -1,   60,   61,   62,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,   -1,   -1,   -1,   -1,  282,   93,  261,  124,   -1,
  264,   -1,   -1,  267,  268,  269,  276,   94,  273,  274,
  275,  282,   -1,   -1,  278,  279,   -1,   -1,  282,  283,
  284,  285,   -1,   -1,  261,  278,  279,  264,   -1,  282,
  267,  268,  269,  261,   -1,   -1,  264,  124,  266,  267,
  268,  269,  272,  273,  274,  275,  276,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   33,  283,  284,  285,   37,   38,
   -1,   -1,   41,   42,   43,   -1,   45,   -1,   47,  261,
   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
   -1,   60,   61,   62,   -1,   -1,   -1,   -1,   -1,   -1,
   33,  283,  284,  285,   37,   38,   -1,   -1,   -1,   42,
   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,   -1,
  267,  268,   -1,   -1,   -1,   94,   -1,   60,   61,   62,
   -1,   62,   -1,   -1,   -1,   -1,  283,  284,  285,   70,
   71,   72,   73,   -1,   33,   76,   -1,   -1,   37,   38,
   -1,   82,   -1,   42,   43,  124,   45,   88,   47,   -1,
   93,   94,   -1,   -1,   -1,   -1,   -1,  283,  284,  285,
   59,   60,   61,   62,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,   -1,   33,   -1,   -1,  264,   37,   38,
   -1,  124,   -1,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,  133,   -1,   -1,   94,  283,  284,  285,   -1,
   59,   60,   61,   62,   -1,   33,   -1,   -1,   -1,   37,
   38,   -1,   -1,   -1,   42,   43,   -1,   45,   -1,   47,
   -1,   -1,   -1,   -1,   -1,  124,  167,   -1,   -1,   -1,
   -1,   -1,   60,   61,   62,   94,   -1,   -1,   -1,  180,
  181,   33,   -1,   -1,   -1,   37,   38,   -1,   -1,   -1,
   42,   43,   -1,   45,   -1,   47,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  124,   94,   59,   60,   61,
   62,   -1,   33,   -1,   -1,   -1,   37,   38,   -1,   -1,
   -1,   42,   43,   33,   45,   -1,   47,   37,   38,   -1,
   -1,   -1,   42,   43,   -1,   45,  124,   47,   -1,   60,
   61,   62,   94,   -1,  283,  284,  285,   -1,   -1,   33,
   60,   61,   62,   37,   -1,   -1,   33,   -1,   42,   43,
   37,   45,   -1,   47,   -1,   42,   43,   -1,   45,   -1,
   47,   -1,  124,   94,   -1,   -1,   60,   61,   62,   -1,
  283,  284,  285,   60,   94,   62,   -1,   -1,   -1,   37,
   38,   -1,   -1,   41,   42,   43,   44,   45,   -1,   47,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   94,   59,   60,   61,   62,   -1,   -1,   94,   -1,   -1,
   -1,   -1,   -1,   -1,  283,  284,  285,   37,   38,   -1,
   -1,   41,   42,   43,   44,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,   33,   93,   -1,   -1,   37,   59,
   60,   61,   62,   42,   43,   -1,   45,   -1,   47,   -1,
   -1,   -1,   -1,   -1,  283,  284,  285,   37,   38,   -1,
   -1,   41,   42,   43,   44,   45,  124,   47,   -1,   -1,
   -1,  269,   -1,   93,   -1,   -1,   -1,   -1,   -1,   59,
   60,   61,   62,   -1,   -1,  283,  284,  285,   -1,   -1,
   -1,   -1,   37,   38,   -1,   94,   41,   42,   43,   44,
   45,   -1,   47,   -1,  124,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   93,   59,   60,   61,   62,   -1,   -1,
   -1,  283,  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   38,   -1,   -1,
   41,   -1,   -1,   44,  124,   -1,   -1,   -1,   93,   -1,
   -1,   -1,  283,  284,  285,   -1,   -1,   -1,   59,   60,
   61,   62,   -1,  283,  284,  285,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   38,   -1,   40,   41,   42,  124,
   -1,   45,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  283,
  284,  285,   93,   -1,   -1,   -1,   -1,  284,  285,   -1,
   -1,   -1,   -1,  261,   -1,   -1,  264,   -1,   -1,  267,
  268,  269,   37,   38,   -1,   -1,   41,   42,   43,   44,
   45,   -1,   47,  124,   -1,  283,  284,  285,   -1,   -1,
   -1,   -1,   -1,   -1,   59,   60,   61,   62,   -1,   -1,
   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,
   -1,   38,   -1,   -1,   41,   -1,   43,   44,   45,   -1,
   -1,   -1,  126,  283,  284,  285,   -1,   -1,   93,   -1,
   -1,   -1,   59,   60,   61,   62,   -1,   -1,   -1,   38,
   -1,  261,   41,   -1,  264,   44,   -1,  267,  268,  269,
   38,   -1,   -1,   41,   -1,   43,   44,   45,   -1,  124,
   59,   -1,   61,  283,  284,  285,   93,   -1,   -1,   -1,
   -1,   59,   60,   61,   62,   -1,  261,   -1,   -1,  264,
   -1,   -1,  267,  268,  269,   38,   -1,   -1,   41,   -1,
   -1,   44,   -1,   -1,   93,   -1,   -1,  124,  283,  284,
  285,   -1,   -1,   -1,   -1,   93,   59,   60,   61,   62,
   -1,   38,   -1,   -1,   41,   -1,   -1,   44,   -1,   -1,
  261,   -1,   -1,  264,   -1,  124,  267,  268,  269,   -1,
   -1,   -1,   59,   60,   61,   62,  124,   -1,   -1,   -1,
   93,   -1,  283,  284,  285,   -1,   38,   -1,   -1,   41,
   -1,   -1,   44,  257,  258,  259,  260,   38,   -1,   -1,
   41,   -1,   -1,   44,   -1,   -1,   93,   59,   60,   61,
   62,  124,   -1,   -1,  278,  279,   -1,   -1,   59,   -1,
   61,   -1,   -1,   -1,   -1,   -1,   -1,   38,   -1,   40,
   -1,   42,   -1,   -1,   45,   -1,  261,  124,   -1,  264,
   -1,   93,  267,  268,  269,   -1,   -1,   -1,   59,   -1,
   -1,   41,   93,   -1,   44,   -1,   -1,   -1,  283,  284,
  285,   -1,   -1,   -1,   38,   -1,   40,   -1,   42,   59,
   41,   45,  124,   44,  261,   -1,   -1,  264,   -1,   -1,
  267,  268,  269,  124,   -1,   59,   -1,   38,   59,   40,
   -1,   42,   -1,   -1,   45,   -1,  283,  284,  285,   -1,
   -1,   -1,  261,   93,   -1,  264,   -1,   -1,  267,  268,
  269,   -1,  123,  261,  125,  126,  264,   -1,   -1,  267,
  268,  269,   93,   38,  283,   40,   -1,   42,   -1,   -1,
   45,   -1,   -1,   -1,  124,  283,  284,  285,   -1,   -1,
   -1,   -1,   -1,   -1,   59,   -1,   -1,   -1,  261,  123,
   -1,  264,  126,   -1,  267,  268,  269,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  283,  284,  285,   -1,  261,  126,   -1,  264,   -1,   -1,
  267,  268,  269,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  283,  284,  285,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,  261,
   -1,  126,  264,   -1,   -1,  267,  268,  269,   -1,   -1,
  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,   -1,
   -1,  283,  284,  285,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  283,   -1,   -1,  256,  257,  258,  259,  260,
  261,  262,  263,   -1,  265,   -1,   -1,   -1,   -1,  270,
  271,   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,   -1,
   -1,  261,   -1,   -1,  264,   -1,   -1,  267,  268,  269,
   -1,   -1,  256,  257,  258,  259,  260,  261,   -1,  263,
  261,  265,   -1,  264,   -1,   -1,  267,  268,  269,  273,
  274,  275,   -1,   -1,  278,  279,  257,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  278,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  256,  257,  258,  259,  260,  261,   -1,  263,   -1,
  265,   -1,   69,   -1,   -1,  270,  271,   74,   75,   -1,
   77,   -1,   -1,  278,  279,   -1,   -1,   -1,   -1,   86,
   87,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  108,  109,  110,  111,  112,  113,  114,  115,  116,
  117,  118,  119,  120,  121,  122,   -1,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  134,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  158,  159,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  168,  169,   -1,   -1,   -1,   -1,  174,
};
#define YYFINAL 1
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 297
#define YYUNDFTOKEN 327
#define YYTRANSLATE(a) ((a) > YYMAXTOKEN ? YYUNDFTOKEN : (a))
#if YYDEBUG
static const char *const yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'!'",0,"'#'",0,"'%'","'&'",0,"'('","')'","'*'","'+'","','","'-'",0,"'/'",0,0,0,
0,0,0,0,0,0,0,0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,"'['",0,"']'","'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'{'","'|'","'}'","'~'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"INT","REAL","ID","STR",
"DO","WHILE","IF","THEN","FOR","IN","UPTO","DOWNTO","STEP","BREAK","CONTINUE",
"VOID","INTEGER","STRING","NUMBER","CONST","PUBLIC","INCR","DECR","IFX","ELSE",
"ATR","NE","GE","LE","\"\"","UMINUS","NOT","REF","LOCAL","POSINC","POSDEC",
"PTR","CALL","START","PARAM","NIL",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,"illegal-symbol",
};
static const char *const yyrule[] = {
"$accept : extn",
"extn : file",
"file :",
"file : file error ';'",
"file : file public tipo ID ';'",
"file : file public CONST tipo ID ';'",
"file : file public tipo ID init",
"file : file public CONST tipo ID init",
"$$1 :",
"file : file public tipo ID $$1 finit",
"$$2 :",
"file : file public VOID ID $$2 finit",
"public :",
"public : PUBLIC",
"ptr :",
"ptr : '*'",
"tipo : INTEGER ptr",
"tipo : STRING ptr",
"tipo : NUMBER ptr",
"init : ATR ID ';'",
"init : ATR INT ';'",
"init : ATR '-' INT ';'",
"init : ATR STR ';'",
"init : ATR CONST STR ';'",
"init : ATR REAL ';'",
"init : ATR '-' REAL ';'",
"finit : '(' params ')' blocop",
"finit : '(' ')' blocop",
"blocop : ';'",
"blocop : bloco ';'",
"params : param",
"params : params ',' param",
"$$3 :",
"bloco : '{' $$3 decls list end '}'",
"decls :",
"decls : decls param ';'",
"param : tipo ID",
"stmt : base",
"stmt : brk",
"base : ';'",
"$$4 :",
"base : DO $$4 stmt WHILE expr ';'",
"$$5 :",
"base : FOR lv IN expr UPTO expr step DO $$5 stmt",
"$$6 :",
"base : FOR lv IN expr DOWNTO expr step DO $$6 stmt",
"base : IF expr THEN stmt",
"base : IF expr THEN stmt ELSE stmt",
"base : expr ';'",
"base : bloco",
"base : lv '#' expr ';'",
"base : error ';'",
"end :",
"end : brk",
"brk : BREAK intp ';'",
"brk : CONTINUE intp ';'",
"step :",
"step : STEP expr",
"intp :",
"intp : INT",
"list : base",
"list : list base",
"args : expr",
"args : args ',' expr",
"lv : ID",
"lv : ID '[' expr ']'",
"expr : lv",
"expr : '*' lv",
"expr : lv ATR expr",
"expr : INT",
"expr : STR",
"expr : REAL",
"expr : '-' expr",
"expr : '~' expr",
"expr : '&' lv",
"expr : expr '!'",
"expr : expr '^' expr",
"expr : INCR lv",
"expr : DECR lv",
"expr : lv INCR",
"expr : lv DECR",
"expr : expr '+' expr",
"expr : expr '-' expr",
"expr : expr '*' expr",
"expr : expr '/' expr",
"expr : expr '%' expr",
"expr : expr '<' expr",
"expr : expr '>' expr",
"expr : expr GE expr",
"expr : expr LE expr",
"expr : expr NE expr",
"expr : expr '=' expr",
"expr : expr '&' expr",
"expr : expr '|' expr",
"expr : '(' expr ')'",
"expr : ID '(' args ')'",
"expr : ID '(' ')'",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

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
#line 221 "diy.y"
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif

void declare(int pub, int cnst, Node *type, char *name, Node *value)
{
  int typ;
  if (!value) {
    if (!pub && cnst) yyerror("local constants must be initialised");
    return;
  }
  if (value->attrib = INT && value->value.i == 0 && type->value.i > 10)
  	return; /* NULL pointer */
  if ((typ = value->info) % 10 > 5) typ -= 5;
  if (type->value.i != typ)
    yyerror("wrong types in initialization");
}
void enter(int pub, int typ, char *name) {
	fpar = malloc(32); /* 31 arguments, at most */
	fpar[0] = 0; /* argument count */
	if (IDfind(name, (long*)IDtest) < 20) 
		IDnew(typ+20, name, (long)fpar);
	IDpush();
	if (typ != 4) {
	 	sizeOfLocalVariable += typ == 3 ? 8 : 4;	 
	 	IDnew(typ, name, -sizeOfLocalVariable);
	 	}

}

int checkargs(char *name, Node *args) {
	char *arg;
	int typ;
        if ((typ = IDsearch(name, (long*)&arg,IDlevel(),1)) < 20) {
		yyerror("ident not a function");
		return 0;
	}
	if (args == 0 && arg[0] == 0)
		;
	else if (args == 0 && arg[0] != 0)
		yyerror("function requires no arguments");
	else if (args != 0 && arg[0] == 0)
		yyerror("function requires arguments");
	else {
		int err = 0, null, i = arg[0], typ;
		do {
			Node *n;
			if (i == 0) {
				yyerror("too many arguments.");
				err = 1;
				break;
			}
			n = LEFT_CHILD(args);
			typ = n->info;
			if (typ % 10 > 5) typ -= 5; /* remove CONST */
			null =  (n->attrib == INT && n->value.i == 0 && arg[i] > 10) ? 1 : 0;
			if (!null && arg[i] != typ) {
				yyerror("wrong argument type");
				err = 1;
				break;
			}
			args = RIGHT_CHILD(args);
			i--;
		} while (args->attrib != NIL);
		if (!err && i > 0)
			yyerror("missing arguments");
	}
	return typ % 20;
}
void resetCounters() {
	sizeOfLocalVariable = 0;
	sizeOfArgs = 8;	
}
 
int nostring(Node *arg1, Node *arg2) {
	if (arg1->info % 5 == 2 || arg2->info % 5 == 2)
		yyerror("can not use strings");
	return arg1->info % 5 == 3 || arg2->info % 5 == 3 ? 3 : 1;
}

int intonly(Node *arg, int novar) {
	if (arg->info % 5 != 1)
		yyerror("only integers can be used");
	if (arg->info % 10 > 5)
		yyerror("argument is constant");
	return 1;
}

int noassign(Node *arg1, Node *arg2) {
	int t1 = arg1->info, t2 = arg2->info;
	if (t1 == t2) return 0;
	if (t1 == 3 && t2 == 1) return 0; /* real := int */
	if (t1 == 1 && t2 == 3) return 0; /* int := real */
	if (t1 == 2 && t2 == 11) return 0; /* string := int* */
	if (t1 == 2 && arg2->attrib == INT && arg2->value.i == 0)
		return 0; /* string := 0 */
	if (t1 > 10 && t1 < 20 && arg2->attrib == INT && arg2->value.i == 0)
		return 0; /* pointer := 0 */
	return 1;
}


#line 793 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
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
        if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
        if (yydebug)
        {
            yys = yyname[YYTRANSLATE(yychar)];
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    YYERROR_CALL("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
                {
                    goto yyoverflow;
                }
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
            yys = yyname[YYTRANSLATE(yychar)];
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
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 60 "diy.y"
	{externs();}
break;
case 4:
#line 64 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-3].i, 0, yystack.l_mark[-2].n, yystack.l_mark[-1].s, 0); globalVariable(yystack.l_mark[-3].i, 0, yystack.l_mark[-2].n, yystack.l_mark[-1].s, 0);  }
break;
case 5:
#line 65 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i+5, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-4].i, 1, yystack.l_mark[-2].n, yystack.l_mark[-1].s, 0); globalVariable(yystack.l_mark[-4].i, 1, yystack.l_mark[-2].n, yystack.l_mark[-1].s, 0); }
break;
case 6:
#line 66 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-3].i, 0, yystack.l_mark[-2].n, yystack.l_mark[-1].s, yystack.l_mark[0].n); globalVariable(yystack.l_mark[-3].i, 0, yystack.l_mark[-2].n, yystack.l_mark[-1].s, yystack.l_mark[0].n); }
break;
case 7:
#line 67 "diy.y"
	{ IDnew(yystack.l_mark[-2].n->value.i+5, yystack.l_mark[-1].s, 0); declare(yystack.l_mark[-4].i, 1, yystack.l_mark[-2].n, yystack.l_mark[-1].s, yystack.l_mark[0].n); globalVariable(yystack.l_mark[-4].i, 1, yystack.l_mark[-2].n, yystack.l_mark[-1].s, yystack.l_mark[0].n); }
break;
case 8:
#line 68 "diy.y"
	{ resetCounters(); enter(yystack.l_mark[-2].i, yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s); }
break;
case 9:
#line 68 "diy.y"
	{ function(yystack.l_mark[-4].i, yystack.l_mark[-3].n, yystack.l_mark[-2].s, yystack.l_mark[0].n);  }
break;
case 10:
#line 69 "diy.y"
	{ resetCounters(); enter(yystack.l_mark[-2].i, 4, yystack.l_mark[0].s); }
break;
case 11:
#line 69 "diy.y"
	{ function(yystack.l_mark[-4].i, intNode(VOID, 4), yystack.l_mark[-2].s, yystack.l_mark[0].n); }
break;
case 12:
#line 72 "diy.y"
	{ yyval.i = 0; }
break;
case 13:
#line 73 "diy.y"
	{ yyval.i = 1; }
break;
case 14:
#line 76 "diy.y"
	{ yyval.i = 0; }
break;
case 15:
#line 77 "diy.y"
	{ yyval.i = 10; }
break;
case 16:
#line 80 "diy.y"
	{ yyval.n = intNode(INTEGER, 1+yystack.l_mark[0].i); }
break;
case 17:
#line 81 "diy.y"
	{ yyval.n = intNode(STRING, 2+yystack.l_mark[0].i); }
break;
case 18:
#line 82 "diy.y"
	{ yyval.n = intNode(NUMBER, 3+yystack.l_mark[0].i); }
break;
case 19:
#line 85 "diy.y"
	{ yyval.n = strNode(ID, yystack.l_mark[-1].s); yyval.n->info = IDfind(yystack.l_mark[-1].s, 0) + 10; }
break;
case 20:
#line 86 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[-1].i); yyval.n->info = 1; }
break;
case 21:
#line 87 "diy.y"
	{ yyval.n = intNode(INT, -yystack.l_mark[-1].i); yyval.n->info = 1; }
break;
case 22:
#line 88 "diy.y"
	{ yyval.n = strNode(STR, yystack.l_mark[-1].s); yyval.n->info = 2; }
break;
case 23:
#line 89 "diy.y"
	{ yyval.n = strNode(CONST, yystack.l_mark[-1].s); yyval.n->info = 2+5; }
break;
case 24:
#line 90 "diy.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[-1].r); yyval.n->info = 3; }
break;
case 25:
#line 91 "diy.y"
	{ yyval.n = realNode(REAL, -yystack.l_mark[-1].r); yyval.n->info = 3; }
break;
case 26:
#line 94 "diy.y"
	{ yyval.n = binNode('(', yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
case 27:
#line 95 "diy.y"
	{ yyval.n = binNode('(', yystack.l_mark[0].n, nilNode(NIL));  }
break;
case 28:
#line 98 "diy.y"
	{ yyval.n = 0; }
break;
case 29:
#line 99 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 30:
#line 102 "diy.y"
	{ yyval.n = yystack.l_mark[0].n;}
break;
case 31:
#line 103 "diy.y"
	{ yyval.n = binNode(',', yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 32:
#line 106 "diy.y"
	{ IDpush(); }
break;
case 33:
#line 106 "diy.y"
	{ yyval.n = binNode('{', yystack.l_mark[-1].n ? binNode(';', yystack.l_mark[-2].n, yystack.l_mark[-1].n) : yystack.l_mark[-2].n, yystack.l_mark[-3].n); IDpop(); }
break;
case 34:
#line 109 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 35:
#line 110 "diy.y"
	{ yyval.n = binNode(';', yystack.l_mark[-2].n, yystack.l_mark[-1].n); }
break;
case 36:
#line 113 "diy.y"
	{ yyval.n = binNode(PARAM, yystack.l_mark[-1].n, strNode(ID, yystack.l_mark[0].s));
                                  
                                  if (IDlevel() == 1)  {
                                  	fpar[++fpar[0]] = yystack.l_mark[-1].n->value.i;
                                  	IDnew(yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s, sizeOfArgs);
                                  	sizeOfArgs += yystack.l_mark[-1].n->value.i == 3 ? 8 : 4;
                                  }
                                  else {
                                  	sizeOfLocalVariable += yystack.l_mark[-1].n->value.i == 3 ? 8 : 4;
                                  	IDnew(yystack.l_mark[-1].n->value.i, yystack.l_mark[0].s, -sizeOfLocalVariable);
                                  }
                                }
break;
case 39:
#line 131 "diy.y"
	{ yyval.n = nilNode(VOID); }
break;
case 40:
#line 132 "diy.y"
	{ ncicl++; }
break;
case 41:
#line 132 "diy.y"
	{ yyval.n = binNode(WHILE, binNode(DO, nilNode(START), yystack.l_mark[-3].n), yystack.l_mark[-1].n); ncicl--; }
break;
case 42:
#line 133 "diy.y"
	{ ncicl++; }
break;
case 43:
#line 133 "diy.y"
	{ Node* pt = uniNode(PTR, yystack.l_mark[-8].n); pt->info = yystack.l_mark[-8].n->info; yyval.n = binNode(';', binNode(ATR, yystack.l_mark[-6].n, yystack.l_mark[-8].n), binNode(FOR, binNode(IN, nilNode(START), binNode(LE,pt, yystack.l_mark[-4].n)), binNode(';', yystack.l_mark[0].n, binNode(ATR, binNode('+', pt, yystack.l_mark[-3].n), yystack.l_mark[-8].n)))); ncicl--; }
break;
case 44:
#line 134 "diy.y"
	{ ncicl++; }
break;
case 45:
#line 134 "diy.y"
	{ Node* pointer = uniNode(PTR, yystack.l_mark[-8].n); pointer->info = yystack.l_mark[-8].n->info; yyval.n = binNode(';', binNode(ATR, yystack.l_mark[-6].n, yystack.l_mark[-8].n), binNode(FOR, binNode(IN, nilNode(START), binNode(GE, pointer, yystack.l_mark[-4].n)), binNode(';', yystack.l_mark[0].n, binNode(ATR, binNode('-', pointer, yystack.l_mark[-3].n), yystack.l_mark[-8].n)))); ncicl--; }
break;
case 46:
#line 135 "diy.y"
	{ yyval.n = binNode(IF, yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 47:
#line 136 "diy.y"
	{ yyval.n = binNode(ELSE, binNode(IF, yystack.l_mark[-4].n, yystack.l_mark[-2].n), yystack.l_mark[0].n); }
break;
case 48:
#line 137 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; }
break;
case 49:
#line 138 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 50:
#line 139 "diy.y"
	{ yyval.n = binNode('#', yystack.l_mark[-1].n, yystack.l_mark[-3].n); }
break;
case 51:
#line 140 "diy.y"
	{ yyval.n = nilNode(NIL); }
break;
case 52:
#line 143 "diy.y"
	{ yyval.n = 0; }
break;
case 54:
#line 146 "diy.y"
	{ yyval.n = intNode(BREAK, yystack.l_mark[-1].i); if (yystack.l_mark[-1].i <= 0 || yystack.l_mark[-1].i > ncicl) yyerror("invalid break argument"); }
break;
case 55:
#line 147 "diy.y"
	{ yyval.n = intNode(CONTINUE, yystack.l_mark[-1].i); if (yystack.l_mark[-1].i <= 0 || yystack.l_mark[-1].i > ncicl) yyerror("invalid continue argument"); }
break;
case 56:
#line 150 "diy.y"
	{ yyval.n = intNode(INT, 1); }
break;
case 57:
#line 151 "diy.y"
	{ yyval.n = yystack.l_mark[0].n; }
break;
case 58:
#line 154 "diy.y"
	{ yyval.i = 1; }
break;
case 60:
#line 158 "diy.y"
	{ yyval.n = yystack.l_mark[0].n;}
break;
case 61:
#line 159 "diy.y"
	{ yyval.n = binNode(';', yystack.l_mark[-1].n, yystack.l_mark[0].n); }
break;
case 62:
#line 162 "diy.y"
	{ yyval.n = binNode(',', yystack.l_mark[0].n, nilNode(NIL)); }
break;
case 63:
#line 163 "diy.y"
	{ yyval.n = binNode(',', yystack.l_mark[0].n, yystack.l_mark[-2].n); }
break;
case 64:
#line 166 "diy.y"
	{ long pos; int typ = IDfind(yystack.l_mark[0].s, &pos);
                          if (pos == 0) yyval.n = strNode(ID, yystack.l_mark[0].s);
                          else {yyval.n = intNode(LOCAL, pos);}
			  yyval.n->info = typ;
			}
break;
case 65:
#line 171 "diy.y"
	{ Node *n;
                            long pos; int siz, typ = IDfind(yystack.l_mark[-3].s, &pos);
                            if (typ / 10 != 1 && typ % 5 != 2) yyerror("not a pointer");
                            if (pos == 0) n = strNode(ID, yystack.l_mark[-3].s);
                            else n = intNode(LOCAL, pos);
                            n->info = typ;
                            yyval.n = binNode('[', n, yystack.l_mark[-1].n);
			    			if (typ >= 10) typ -= 10;
                            	else if (typ % 5 == 2) typ = 1;
			    			if (typ >= 5) typ -= 5;
			   				yyval.n->info = typ;
			  }
break;
case 66:
#line 185 "diy.y"
	{ yyval.n = uniNode(PTR, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; }
break;
case 67:
#line 186 "diy.y"
	{ yyval.n = uniNode(PTR, uniNode(PTR, yystack.l_mark[0].n)); if (yystack.l_mark[0].n->info % 5 == 2) yyval.n->info = 1; else if (yystack.l_mark[0].n->info / 10 == 1) yyval.n->info = yystack.l_mark[0].n->info % 10; else yyerror("can dereference lvalue"); }
break;
case 68:
#line 187 "diy.y"
	{ yyval.n = binNode(ATR, yystack.l_mark[0].n, yystack.l_mark[-2].n); if (yyval.n->info % 10 > 5) yyerror("constant value to assignment"); if (noassign(yystack.l_mark[-2].n, yystack.l_mark[0].n)) yyerror("illegal assignment"); yyval.n->info = yystack.l_mark[-2].n->info; }
break;
case 69:
#line 188 "diy.y"
	{ yyval.n = intNode(INT, yystack.l_mark[0].i); yyval.n->info = 1; }
break;
case 70:
#line 189 "diy.y"
	{ yyval.n = strNode(STR, yystack.l_mark[0].s); yyval.n->info = 2; }
break;
case 71:
#line 190 "diy.y"
	{ yyval.n = realNode(REAL, yystack.l_mark[0].r); yyval.n->info = 3; }
break;
case 72:
#line 191 "diy.y"
	{ yyval.n = uniNode(UMINUS, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info; nostring(yystack.l_mark[0].n, yystack.l_mark[0].n);}
break;
case 73:
#line 192 "diy.y"
	{ yyval.n = uniNode(NOT, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 0); }
break;
case 74:
#line 193 "diy.y"
	{ yyval.n = uniNode(REF, yystack.l_mark[0].n); yyval.n->info = yystack.l_mark[0].n->info + 10; }
break;
case 75:
#line 194 "diy.y"
	{ yyval.n = uniNode('!', yystack.l_mark[-1].n); yyval.n->info = 3; intonly(yystack.l_mark[-1].n, 0); }
break;
case 76:
#line 195 "diy.y"
	{ yyval.n = binNode('^', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0);}
break;
case 77:
#line 196 "diy.y"
	{ yyval.n = uniNode(INCR, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 1); }
break;
case 78:
#line 197 "diy.y"
	{ yyval.n = uniNode(DECR, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[0].n, 1); }
break;
case 79:
#line 198 "diy.y"
	{ yyval.n = uniNode(POSINC, yystack.l_mark[-1].n); yyval.n->info = intonly(yystack.l_mark[-1].n, 1); }
break;
case 80:
#line 199 "diy.y"
	{ yyval.n = uniNode(POSDEC, yystack.l_mark[-1].n); yyval.n->info = intonly(yystack.l_mark[-1].n, 1); }
break;
case 81:
#line 200 "diy.y"
	{ yyval.n = binNode('+', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 82:
#line 201 "diy.y"
	{ yyval.n = binNode('-', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 83:
#line 202 "diy.y"
	{ yyval.n = binNode('*', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 84:
#line 203 "diy.y"
	{ yyval.n = binNode('/', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = nostring(yystack.l_mark[-2].n, yystack.l_mark[0].n); }
break;
case 85:
#line 204 "diy.y"
	{ yyval.n = binNode('%', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 86:
#line 205 "diy.y"
	{ yyval.n = binNode('<', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 87:
#line 206 "diy.y"
	{ yyval.n = binNode('>', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 88:
#line 207 "diy.y"
	{ yyval.n = binNode(GE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 89:
#line 208 "diy.y"
	{ yyval.n = binNode(LE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 90:
#line 209 "diy.y"
	{ yyval.n = binNode(NE, yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 91:
#line 210 "diy.y"
	{ yyval.n = binNode('=', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = 1; }
break;
case 92:
#line 211 "diy.y"
	{ yyval.n = binNode('&', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 93:
#line 212 "diy.y"
	{ yyval.n = binNode('|', yystack.l_mark[-2].n, yystack.l_mark[0].n); yyval.n->info = intonly(yystack.l_mark[-2].n, 0); intonly(yystack.l_mark[0].n, 0); }
break;
case 94:
#line 213 "diy.y"
	{ yyval.n = yystack.l_mark[-1].n; yyval.n->info = yystack.l_mark[-1].n->info; }
break;
case 95:
#line 214 "diy.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-3].s), yystack.l_mark[-1].n);
                            yyval.n->info = checkargs(yystack.l_mark[-3].s, yystack.l_mark[-1].n); }
break;
case 96:
#line 216 "diy.y"
	{ yyval.n = binNode(CALL, strNode(ID, yystack.l_mark[-2].s), nilNode(VOID));
                          yyval.n->info = checkargs(yystack.l_mark[-2].s, 0); }
break;
#line 1383 "y.tab.c"
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
            if ((yychar = YYLEX) < 0) yychar = YYEOF;
#if YYDEBUG
            if (yydebug)
            {
                yys = yyname[YYTRANSLATE(yychar)];
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == YYEOF) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack) == YYENOMEM)
    {
        goto yyoverflow;
    }
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
