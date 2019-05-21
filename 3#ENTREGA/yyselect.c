/*
generated at Tue May 21 19:40:10 2019
by $Id: pburg.c,v 2.5 2017/11/16 09:41:42 prs Exp $
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PBURG_PREFIX "yy"
#define PBURG_VERSION "2.5"
#define MAX_COST 0x7fff
#if defined(__STDC__) || defined(__cplusplus)
#define YYCONST const
#else
#define YYCONST
#endif

#line 1 "diy.brg"

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "tabid.h"
#include "postfix.h"

#define DOUBLE 3

extern FILE *outfp;
extern int sizeOfLocalVariable;
extern int sizeOfArgs;


int lbl;
int returnType;

char *dupstr(const char *s);

static long brklbl[20], brkcnt; /* break labels */
/* label _L0 is a break without a while/switch) */

static char *extrns[100]; /* emit externs at the end only */
static int extcnt;

typedef struct controlerOfCycles {
	int start;
	int end;
	int cont;
} cycleControler;

cycleControler cycleControlers[70];
int cycleIndex = 0;


int lbl;
char *mklbl(int n) {
  static char buf[20];
  sprintf(buf, "_i%d", n);
  return strcpy(malloc(strlen(buf)+1),buf);
}

static void outstr(char *s) {
  while (*s) fprintf(outfp, pfCHAR, (unsigned char)*s++);
  fprintf(outfp, pfCHAR, 0);
}
static char *mkfunc(char *s) {
  static char buf[80];
  strcpy(buf, "_");
  strcat(buf, s);
  return buf;
}

int initCycleControler_while() {
	 cycleControlers[cycleIndex].start = ++lbl;
	 cycleControlers[cycleIndex].end = ++lbl;
	 cycleControlers[cycleIndex].cont = cycleControlers[cycleIndex].end;
	 cycleIndex++;
	 return cycleIndex - 1;
}

int initCycleControler_for() {
	 cycleControlers[cycleIndex].start = ++lbl;
	 cycleControlers[cycleIndex].end = ++lbl;
	 cycleControlers[cycleIndex].cont = ++lbl;
	  cycleIndex++;
	 return cycleIndex - 1;
}

void setPlace(Node *p) {
	if (IDfind(LEFT_CHILD(p)->value.s, NULL) == 3)
		p->place = 8;
	else 
		p->place = 4;
}

int isInt(Node *p) { return (p->info == 1  || p->info == -1)? 1 : MAX_COST; }

int isReal(Node *p) { return p->info == 3 ? 1 : MAX_COST; }

#ifndef PANIC
#define PANIC yypanic
static void yypanic(YYCONST char *rot, YYCONST char *msg, int val) {
	fprintf(stderr, "Internal Error in %s: %s %d\nexiting...\n",
		rot, msg, val);
	exit(2);
}
#endif
static void yykids(NODEPTR_TYPE, int, NODEPTR_TYPE[]);
#define yyfinit_NT 1
#define yyblocop_NT 2
#define yyparams_NT 3
#define yybloco_NT 4
#define yylist_NT 5
#define yydecls_NT 6
#define yystmt_NT 7
#define yyparam_NT 8
#define yybase_NT 9
#define yyexpr_NT 10
#define yytipo_NT 11
#define yyargs_NT 12
#define yylv_NT 13
#define yyiexpr_NT 14
#define yysexpr_NT 15
#define yyrexpr_NT 16
#define yyiassign_NT 17
#define yyrassign_NT 18
#define yysassign_NT 19
#define yybase_if_NT 20
#define yycond_NT 21
#define yybase_else_NT 22
#define yyif_NT 23
#define yybase_while_NT 24
#define yydo_NT 25
#define yystart_NT 26
#define yybase_for_NT 27
#define yyfor_NT 28
#define yyin_for_NT 29
#define yyend_for_NT 30
#define yycorpo_for_NT 31
#define yystart_for_NT 32

static YYCONST char *yyntname[] = {
	0,
	"finit",
	"blocop",
	"params",
	"bloco",
	"list",
	"decls",
	"stmt",
	"param",
	"base",
	"expr",
	"tipo",
	"args",
	"lv",
	"iexpr",
	"sexpr",
	"rexpr",
	"iassign",
	"rassign",
	"sassign",
	"base_if",
	"cond",
	"base_else",
	"if",
	"base_while",
	"do",
	"start",
	"base_for",
	"for",
	"in_for",
	"end_for",
	"corpo_for",
	"start_for",
	0
};

static YYCONST char *yytermname[] = {
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "",
	/* 34 */ "t_NOT",
 "",
	/* 36 */ "HASH",
 "",
	/* 38 */ "MOD",
	/* 39 */ "AND",
 "",
	/* 41 */ "t_OPENP",
 "",
	/* 43 */ "MUL",
	/* 44 */ "ADD",
	/* 45 */ "t_COMA",
	/* 46 */ "SUB",
 "",
	/* 48 */ "DIV",
 "", "", "", "", "", "", "", "", "", "", "",
	/* 60 */ "t_END",
	/* 61 */ "LT",
	/* 62 */ "EQ",
	/* 63 */ "GT",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "",
	/* 124 */ "t_BRACKET",
	/* 125 */ "OR",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "",
 "", "", "", "", "", "", "", "", "", "", "", "",
	/* 258 */ "INT",
	/* 259 */ "REAL",
	/* 260 */ "ID",
	/* 261 */ "STR",
	/* 262 */ "DO",
	/* 263 */ "WHILE",
	/* 264 */ "IF",
	/* 265 */ "THEN",
	/* 266 */ "FOR",
	/* 267 */ "IN",
	/* 268 */ "UPTO",
	/* 269 */ "DOWNTO",
	/* 270 */ "STEP",
	/* 271 */ "BREAK",
	/* 272 */ "CONTINUE",
	/* 273 */ "VOID",
	/* 274 */ "INTEGER",
	/* 275 */ "STRING",
	/* 276 */ "NUMBER",
	/* 277 */ "CONST",
	/* 278 */ "PUBLIC",
	/* 279 */ "INCR",
	/* 280 */ "DECR",
	/* 281 */ "IFX",
	/* 282 */ "ELSE",
	/* 283 */ "ATR",
	/* 284 */ "NE",
	/* 285 */ "GE",
	/* 286 */ "LE",
	/* 287 */ "UMINUS",
	/* 288 */ "NOT",
	/* 289 */ "REF",
	/* 290 */ "LOCAL",
	/* 291 */ "POSINC",
	/* 292 */ "POSDEC",
	/* 293 */ "PTR",
	/* 294 */ "CALL",
	/* 295 */ "START",
	/* 296 */ "PARAM",
	/* 297 */ "NIL",
	""
};

struct yystate {
	short cost[33];
	struct {
		unsigned int yyfinit:2;
		unsigned int yyblocop:1;
		unsigned int yyparams:2;
		unsigned int yybloco:2;
		unsigned int yylist:2;
		unsigned int yydecls:2;
		unsigned int yystmt:1;
		unsigned int yyparam:1;
		unsigned int yybase:3;
		unsigned int yyexpr:3;
		unsigned int yytipo:2;
		unsigned int yyargs:2;
		unsigned int yylv:1;
		unsigned int yyiexpr:5;
		unsigned int yysexpr:2;
		unsigned int yyrexpr:4;
		unsigned int yyiassign:2;
		unsigned int yyrassign:1;
		unsigned int yysassign:1;
		unsigned int yybase_if:1;
		unsigned int yycond:1;
		unsigned int yybase_else:1;
		unsigned int yyif:1;
		unsigned int yybase_while:1;
		unsigned int yydo:1;
		unsigned int yystart:1;
		unsigned int yybase_for:1;
		unsigned int yyfor:1;
		unsigned int yyin_for:1;
		unsigned int yyend_for:1;
		unsigned int yycorpo_for:1;
		unsigned int yystart_for:1;
	} rule;
};

static short yynts_0[] = { yyblocop_NT, yyparams_NT, 0 };
static short yynts_1[] = { yyblocop_NT, 0 };
static short yynts_2[] = { yybloco_NT, 0 };
static short yynts_3[] = { yylist_NT, yydecls_NT, 0 };
static short yynts_4[] = { yylist_NT, yystmt_NT, yydecls_NT, 0 };
static short yynts_5[] = { 0 };
static short yynts_6[] = { yydecls_NT, yyparam_NT, 0 };
static short yynts_7[] = { yybase_NT, 0 };
static short yynts_8[] = { yylist_NT, yybase_NT, 0 };
static short yynts_9[] = { yyexpr_NT, 0 };
static short yynts_10[] = { yyparam_NT, 0 };
static short yynts_11[] = { yyparams_NT, yyparam_NT, 0 };
static short yynts_12[] = { yytipo_NT, 0 };
static short yynts_13[] = { yyargs_NT, yyexpr_NT, 0 };
static short yynts_14[] = { yyiexpr_NT, 0 };
static short yynts_15[] = { yysexpr_NT, 0 };
static short yynts_16[] = { yyrexpr_NT, 0 };
static short yynts_17[] = { yyargs_NT, 0 };
static short yynts_18[] = { yyiexpr_NT, yyiexpr_NT, 0 };
static short yynts_19[] = { yylv_NT, 0 };
static short yynts_20[] = { yyiassign_NT, yylv_NT, 0 };
static short yynts_21[] = { yyrexpr_NT, yyrexpr_NT, 0 };
static short yynts_22[] = { yyrassign_NT, yylv_NT, 0 };
static short yynts_23[] = { yysassign_NT, yylv_NT, 0 };
static short yynts_24[] = { yybase_if_NT, 0 };
static short yynts_25[] = { yycond_NT, yystmt_NT, 0 };
static short yynts_26[] = { yybase_else_NT, 0 };
static short yynts_27[] = { yyif_NT, yystmt_NT, 0 };
static short yynts_28[] = { yybase_while_NT, 0 };
static short yynts_29[] = { yydo_NT, yyexpr_NT, 0 };
static short yynts_30[] = { yystart_NT, yystmt_NT, 0 };
static short yynts_31[] = { yybase_for_NT, 0 };
static short yynts_32[] = { yyexpr_NT, yyfor_NT, 0 };
static short yynts_33[] = { yyin_for_NT, yyend_for_NT, 0 };
static short yynts_34[] = { yycorpo_for_NT, yyexpr_NT, 0 };
static short yynts_35[] = { yystmt_NT, 0 };
static short yynts_36[] = { yystart_for_NT, yyexpr_NT, 0 };

static short *yynts[] = {
	0,	/* 0 */
	yynts_0,	/* 1 */
	yynts_1,	/* 2 */
	yynts_2,	/* 3 */
	yynts_3,	/* 4 */
	yynts_4,	/* 5 */
	yynts_5,	/* 6 */
	yynts_6,	/* 7 */
	yynts_7,	/* 8 */
	yynts_8,	/* 9 */
	yynts_7,	/* 10 */
	yynts_9,	/* 11 */
	yynts_2,	/* 12 */
	yynts_10,	/* 13 */
	yynts_11,	/* 14 */
	yynts_12,	/* 15 */
	yynts_9,	/* 16 */
	yynts_13,	/* 17 */
	yynts_5,	/* 18 */
	yynts_5,	/* 19 */
	yynts_5,	/* 20 */
	yynts_5,	/* 21 */
	yynts_14,	/* 22 */
	yynts_15,	/* 23 */
	yynts_16,	/* 24 */
	yynts_17,	/* 25 */
	yynts_5,	/* 26 */
	yynts_5,	/* 27 */
	yynts_18,	/* 28 */
	yynts_18,	/* 29 */
	yynts_18,	/* 30 */
	yynts_18,	/* 31 */
	yynts_18,	/* 32 */
	yynts_19,	/* 33 */
	yynts_19,	/* 34 */
	yynts_19,	/* 35 */
	yynts_19,	/* 36 */
	yynts_14,	/* 37 */
	yynts_18,	/* 38 */
	yynts_18,	/* 39 */
	yynts_18,	/* 40 */
	yynts_18,	/* 41 */
	yynts_18,	/* 42 */
	yynts_18,	/* 43 */
	yynts_18,	/* 44 */
	yynts_18,	/* 45 */
	yynts_20,	/* 46 */
	yynts_19,	/* 47 */
	yynts_14,	/* 48 */
	yynts_17,	/* 49 */
	yynts_5,	/* 50 */
	yynts_5,	/* 51 */
	yynts_21,	/* 52 */
	yynts_21,	/* 53 */
	yynts_21,	/* 54 */
	yynts_21,	/* 55 */
	yynts_16,	/* 56 */
	yynts_21,	/* 57 */
	yynts_21,	/* 58 */
	yynts_21,	/* 59 */
	yynts_21,	/* 60 */
	yynts_21,	/* 61 */
	yynts_21,	/* 62 */
	yynts_14,	/* 63 */
	yynts_16,	/* 64 */
	yynts_22,	/* 65 */
	yynts_19,	/* 66 */
	yynts_16,	/* 67 */
	yynts_17,	/* 68 */
	yynts_5,	/* 69 */
	yynts_5,	/* 70 */
	yynts_23,	/* 71 */
	yynts_15,	/* 72 */
	yynts_24,	/* 73 */
	yynts_25,	/* 74 */
	yynts_9,	/* 75 */
	yynts_26,	/* 76 */
	yynts_27,	/* 77 */
	yynts_25,	/* 78 */
	yynts_28,	/* 79 */
	yynts_29,	/* 80 */
	yynts_30,	/* 81 */
	yynts_5,	/* 82 */
	yynts_31,	/* 83 */
	yynts_32,	/* 84 */
	yynts_33,	/* 85 */
	yynts_34,	/* 86 */
	yynts_35,	/* 87 */
	yynts_36,	/* 88 */
	yynts_5,	/* 89 */
};


static YYCONST char *yystring[] = {
/* 0 */	0,
/* 1 */	"finit: t_OPENP(blocop,params)",
/* 2 */	"finit: t_OPENP(blocop,NIL)",
/* 3 */	"blocop: bloco",
/* 4 */	"bloco: t_BRACKET(list,decls)",
/* 5 */	"bloco: t_BRACKET(t_END(list,stmt),decls)",
/* 6 */	"decls: NIL",
/* 7 */	"decls: t_END(decls,param)",
/* 8 */	"list: base",
/* 9 */	"list: t_END(list,base)",
/* 10 */	"stmt: base",
/* 11 */	"base: expr",
/* 12 */	"base: bloco",
/* 13 */	"params: param",
/* 14 */	"params: t_COMA(params,param)",
/* 15 */	"param: PARAM(tipo,ID)",
/* 16 */	"args: t_COMA(NIL,expr)",
/* 17 */	"args: t_COMA(args,expr)",
/* 18 */	"tipo: INTEGER",
/* 19 */	"tipo: STRING",
/* 20 */	"tipo: NUMBER",
/* 21 */	"lv: LOCAL",
/* 22 */	"expr: iexpr",
/* 23 */	"expr: sexpr",
/* 24 */	"expr: rexpr",
/* 25 */	"expr: CALL(ID,args)",
/* 26 */	"expr: CALL(ID,VOID)",
/* 27 */	"iexpr: INT",
/* 28 */	"iexpr: ADD(iexpr,iexpr)",
/* 29 */	"iexpr: SUB(iexpr,iexpr)",
/* 30 */	"iexpr: MUL(iexpr,iexpr)",
/* 31 */	"iexpr: DIV(iexpr,iexpr)",
/* 32 */	"iexpr: MOD(iexpr,iexpr)",
/* 33 */	"iexpr: INCR(lv)",
/* 34 */	"iexpr: DECR(lv)",
/* 35 */	"iexpr: POSINC(lv)",
/* 36 */	"iexpr: POSDEC(lv)",
/* 37 */	"iexpr: UMINUS(iexpr)",
/* 38 */	"iexpr: EQ(iexpr,iexpr)",
/* 39 */	"iexpr: NE(iexpr,iexpr)",
/* 40 */	"iexpr: LT(iexpr,iexpr)",
/* 41 */	"iexpr: LE(iexpr,iexpr)",
/* 42 */	"iexpr: GT(iexpr,iexpr)",
/* 43 */	"iexpr: GE(iexpr,iexpr)",
/* 44 */	"iexpr: AND(iexpr,iexpr)",
/* 45 */	"iexpr: OR(iexpr,iexpr)",
/* 46 */	"iexpr: ATR(iassign,lv)",
/* 47 */	"iexpr: PTR(lv)",
/* 48 */	"iassign: iexpr",
/* 49 */	"iexpr: CALL(ID,args)",
/* 50 */	"iexpr: CALL(ID,VOID)",
/* 51 */	"rexpr: REAL",
/* 52 */	"rexpr: ADD(rexpr,rexpr)",
/* 53 */	"rexpr: SUB(rexpr,rexpr)",
/* 54 */	"rexpr: MUL(rexpr,rexpr)",
/* 55 */	"rexpr: DIV(rexpr,rexpr)",
/* 56 */	"rexpr: UMINUS(rexpr)",
/* 57 */	"iexpr: EQ(rexpr,rexpr)",
/* 58 */	"iexpr: NE(rexpr,rexpr)",
/* 59 */	"iexpr: LT(rexpr,rexpr)",
/* 60 */	"iexpr: LE(rexpr,rexpr)",
/* 61 */	"iexpr: GT(rexpr,rexpr)",
/* 62 */	"iexpr: GE(rexpr,rexpr)",
/* 63 */	"rexpr: iexpr",
/* 64 */	"iassign: rexpr",
/* 65 */	"rexpr: ATR(rassign,lv)",
/* 66 */	"rexpr: PTR(lv)",
/* 67 */	"rassign: rexpr",
/* 68 */	"rexpr: CALL(ID,args)",
/* 69 */	"rexpr: CALL(ID,VOID)",
/* 70 */	"sexpr: STR",
/* 71 */	"sexpr: ATR(sassign,lv)",
/* 72 */	"sassign: sexpr",
/* 73 */	"base: base_if",
/* 74 */	"base_if: IF(cond,stmt)",
/* 75 */	"cond: expr",
/* 76 */	"base: base_else",
/* 77 */	"base_else: ELSE(if,stmt)",
/* 78 */	"if: IF(cond,stmt)",
/* 79 */	"base: base_while",
/* 80 */	"base_while: WHILE(do,expr)",
/* 81 */	"do: DO(start,stmt)",
/* 82 */	"start: START",
/* 83 */	"base: base_for",
/* 84 */	"base_for: t_END(expr,for)",
/* 85 */	"for: FOR(in_for,end_for)",
/* 86 */	"end_for: t_END(corpo_for,expr)",
/* 87 */	"corpo_for: stmt",
/* 88 */	"in_for: IN(start_for,expr)",
/* 89 */	"start_for: START",
};

#ifndef TRACE
static void yytrace(NODEPTR_TYPE p, int eruleno, int cost, int bestcost)
{
	int op = OP_LABEL(p);
	YYCONST char *tname = yytermname[op] ? yytermname[op] : "?";
	fprintf(stderr, "0x%lx:%s matched %s with cost %d vs. %d\n", (long)p, tname, yystring[eruleno], cost, bestcost);
}
#endif

static short yydecode_finit[] = {
	0,
	1,
	2,
};

static short yydecode_blocop[] = {
	0,
	3,
};

static short yydecode_params[] = {
	0,
	13,
	14,
};

static short yydecode_bloco[] = {
	0,
	4,
	5,
};

static short yydecode_list[] = {
	0,
	8,
	9,
};

static short yydecode_decls[] = {
	0,
	6,
	7,
};

static short yydecode_stmt[] = {
	0,
	10,
};

static short yydecode_param[] = {
	0,
	15,
};

static short yydecode_base[] = {
	0,
	11,
	12,
	73,
	76,
	79,
	83,
};

static short yydecode_expr[] = {
	0,
	22,
	23,
	24,
	25,
	26,
};

static short yydecode_tipo[] = {
	0,
	18,
	19,
	20,
};

static short yydecode_args[] = {
	0,
	16,
	17,
};

static short yydecode_lv[] = {
	0,
	21,
};

static short yydecode_iexpr[] = {
	0,
	27,
	28,
	29,
	30,
	31,
	32,
	33,
	34,
	35,
	36,
	37,
	38,
	39,
	40,
	41,
	42,
	43,
	44,
	45,
	46,
	47,
	49,
	50,
	57,
	58,
	59,
	60,
	61,
	62,
};

static short yydecode_sexpr[] = {
	0,
	70,
	71,
};

static short yydecode_rexpr[] = {
	0,
	51,
	52,
	53,
	54,
	55,
	56,
	63,
	65,
	66,
	68,
	69,
};

static short yydecode_iassign[] = {
	0,
	48,
	64,
};

static short yydecode_rassign[] = {
	0,
	67,
};

static short yydecode_sassign[] = {
	0,
	72,
};

static short yydecode_base_if[] = {
	0,
	74,
};

static short yydecode_cond[] = {
	0,
	75,
};

static short yydecode_base_else[] = {
	0,
	77,
};

static short yydecode_if[] = {
	0,
	78,
};

static short yydecode_base_while[] = {
	0,
	80,
};

static short yydecode_do[] = {
	0,
	81,
};

static short yydecode_start[] = {
	0,
	82,
};

static short yydecode_base_for[] = {
	0,
	84,
};

static short yydecode_for[] = {
	0,
	85,
};

static short yydecode_in_for[] = {
	0,
	88,
};

static short yydecode_end_for[] = {
	0,
	86,
};

static short yydecode_corpo_for[] = {
	0,
	87,
};

static short yydecode_start_for[] = {
	0,
	89,
};

static int yyrule(void *state, int goalnt) {
	if (goalnt < 1 || goalnt > 32)
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
	if (!state)
		return 0;
	switch (goalnt) {
	case yyfinit_NT:	return yydecode_finit[((struct yystate *)state)->rule.yyfinit];
	case yyblocop_NT:	return yydecode_blocop[((struct yystate *)state)->rule.yyblocop];
	case yyparams_NT:	return yydecode_params[((struct yystate *)state)->rule.yyparams];
	case yybloco_NT:	return yydecode_bloco[((struct yystate *)state)->rule.yybloco];
	case yylist_NT:	return yydecode_list[((struct yystate *)state)->rule.yylist];
	case yydecls_NT:	return yydecode_decls[((struct yystate *)state)->rule.yydecls];
	case yystmt_NT:	return yydecode_stmt[((struct yystate *)state)->rule.yystmt];
	case yyparam_NT:	return yydecode_param[((struct yystate *)state)->rule.yyparam];
	case yybase_NT:	return yydecode_base[((struct yystate *)state)->rule.yybase];
	case yyexpr_NT:	return yydecode_expr[((struct yystate *)state)->rule.yyexpr];
	case yytipo_NT:	return yydecode_tipo[((struct yystate *)state)->rule.yytipo];
	case yyargs_NT:	return yydecode_args[((struct yystate *)state)->rule.yyargs];
	case yylv_NT:	return yydecode_lv[((struct yystate *)state)->rule.yylv];
	case yyiexpr_NT:	return yydecode_iexpr[((struct yystate *)state)->rule.yyiexpr];
	case yysexpr_NT:	return yydecode_sexpr[((struct yystate *)state)->rule.yysexpr];
	case yyrexpr_NT:	return yydecode_rexpr[((struct yystate *)state)->rule.yyrexpr];
	case yyiassign_NT:	return yydecode_iassign[((struct yystate *)state)->rule.yyiassign];
	case yyrassign_NT:	return yydecode_rassign[((struct yystate *)state)->rule.yyrassign];
	case yysassign_NT:	return yydecode_sassign[((struct yystate *)state)->rule.yysassign];
	case yybase_if_NT:	return yydecode_base_if[((struct yystate *)state)->rule.yybase_if];
	case yycond_NT:	return yydecode_cond[((struct yystate *)state)->rule.yycond];
	case yybase_else_NT:	return yydecode_base_else[((struct yystate *)state)->rule.yybase_else];
	case yyif_NT:	return yydecode_if[((struct yystate *)state)->rule.yyif];
	case yybase_while_NT:	return yydecode_base_while[((struct yystate *)state)->rule.yybase_while];
	case yydo_NT:	return yydecode_do[((struct yystate *)state)->rule.yydo];
	case yystart_NT:	return yydecode_start[((struct yystate *)state)->rule.yystart];
	case yybase_for_NT:	return yydecode_base_for[((struct yystate *)state)->rule.yybase_for];
	case yyfor_NT:	return yydecode_for[((struct yystate *)state)->rule.yyfor];
	case yyin_for_NT:	return yydecode_in_for[((struct yystate *)state)->rule.yyin_for];
	case yyend_for_NT:	return yydecode_end_for[((struct yystate *)state)->rule.yyend_for];
	case yycorpo_for_NT:	return yydecode_corpo_for[((struct yystate *)state)->rule.yycorpo_for];
	case yystart_for_NT:	return yydecode_start_for[((struct yystate *)state)->rule.yystart_for];
	default:
		PANIC("yyrule", "Bad goal nonterminal", goalnt);
		return 0;
	}
}

static void yyclosure_bloco(NODEPTR_TYPE, int);
static void yyclosure_stmt(NODEPTR_TYPE, int);
static void yyclosure_param(NODEPTR_TYPE, int);
static void yyclosure_base(NODEPTR_TYPE, int);
static void yyclosure_expr(NODEPTR_TYPE, int);
static void yyclosure_iexpr(NODEPTR_TYPE, int);
static void yyclosure_sexpr(NODEPTR_TYPE, int);
static void yyclosure_rexpr(NODEPTR_TYPE, int);
static void yyclosure_base_if(NODEPTR_TYPE, int);
static void yyclosure_base_else(NODEPTR_TYPE, int);
static void yyclosure_base_while(NODEPTR_TYPE, int);
static void yyclosure_base_for(NODEPTR_TYPE, int);

static void yyclosure_bloco(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 12, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 2;
		yyclosure_base(a, c + 1);
	}
	yytrace(a, 3, c + 1, p->cost[yyblocop_NT]);
	if (c + 1 < p->cost[yyblocop_NT]) {
		p->cost[yyblocop_NT] = c + 1;
		p->rule.yyblocop = 1;
	}
}

static void yyclosure_stmt(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 87, c + 1, p->cost[yycorpo_for_NT]);
	if (c + 1 < p->cost[yycorpo_for_NT]) {
		p->cost[yycorpo_for_NT] = c + 1;
		p->rule.yycorpo_for = 1;
	}
}

static void yyclosure_param(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 13, c + 1, p->cost[yyparams_NT]);
	if (c + 1 < p->cost[yyparams_NT]) {
		p->cost[yyparams_NT] = c + 1;
		p->rule.yyparams = 1;
	}
}

static void yyclosure_base(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 10, c + 1, p->cost[yystmt_NT]);
	if (c + 1 < p->cost[yystmt_NT]) {
		p->cost[yystmt_NT] = c + 1;
		p->rule.yystmt = 1;
		yyclosure_stmt(a, c + 1);
	}
	yytrace(a, 8, c + 1, p->cost[yylist_NT]);
	if (c + 1 < p->cost[yylist_NT]) {
		p->cost[yylist_NT] = c + 1;
		p->rule.yylist = 1;
	}
}

static void yyclosure_expr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 75, c + 1, p->cost[yycond_NT]);
	if (c + 1 < p->cost[yycond_NT]) {
		p->cost[yycond_NT] = c + 1;
		p->rule.yycond = 1;
	}
	yytrace(a, 11, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 1;
		yyclosure_base(a, c + 1);
	}
}

static void yyclosure_iexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 63, c + 1, p->cost[yyrexpr_NT]);
	if (c + 1 < p->cost[yyrexpr_NT]) {
		p->cost[yyrexpr_NT] = c + 1;
		p->rule.yyrexpr = 7;
		yyclosure_rexpr(a, c + 1);
	}
	yytrace(a, 48, c + 1, p->cost[yyiassign_NT]);
	if (c + 1 < p->cost[yyiassign_NT]) {
		p->cost[yyiassign_NT] = c + 1;
		p->rule.yyiassign = 1;
	}
	yytrace(a, 22, c + 1, p->cost[yyexpr_NT]);
	if (c + 1 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1;
		p->rule.yyexpr = 1;
		yyclosure_expr(a, c + 1);
	}
}

static void yyclosure_sexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 72, c + 1, p->cost[yysassign_NT]);
	if (c + 1 < p->cost[yysassign_NT]) {
		p->cost[yysassign_NT] = c + 1;
		p->rule.yysassign = 1;
	}
	yytrace(a, 23, c + 1, p->cost[yyexpr_NT]);
	if (c + 1 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1;
		p->rule.yyexpr = 2;
		yyclosure_expr(a, c + 1);
	}
}

static void yyclosure_rexpr(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 67, c + 1, p->cost[yyrassign_NT]);
	if (c + 1 < p->cost[yyrassign_NT]) {
		p->cost[yyrassign_NT] = c + 1;
		p->rule.yyrassign = 1;
	}
	yytrace(a, 64, c + 1, p->cost[yyiassign_NT]);
	if (c + 1 < p->cost[yyiassign_NT]) {
		p->cost[yyiassign_NT] = c + 1;
		p->rule.yyiassign = 2;
	}
	yytrace(a, 24, c + 1, p->cost[yyexpr_NT]);
	if (c + 1 < p->cost[yyexpr_NT]) {
		p->cost[yyexpr_NT] = c + 1;
		p->rule.yyexpr = 3;
		yyclosure_expr(a, c + 1);
	}
}

static void yyclosure_base_if(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 73, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 3;
		yyclosure_base(a, c + 1);
	}
}

static void yyclosure_base_else(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 76, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 4;
		yyclosure_base(a, c + 1);
	}
}

static void yyclosure_base_while(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 79, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 5;
		yyclosure_base(a, c + 1);
	}
}

static void yyclosure_base_for(NODEPTR_TYPE a, int c) {
	struct yystate *p = (struct yystate *)STATE_LABEL(a);
	yytrace(a, 83, c + 1, p->cost[yybase_NT]);
	if (c + 1 < p->cost[yybase_NT]) {
		p->cost[yybase_NT] = c + 1;
		p->rule.yybase = 6;
		yyclosure_base(a, c + 1);
	}
}

static void yylabel(NODEPTR_TYPE a, NODEPTR_TYPE u) {
	int c;
	struct yystate *p;

	if (!a)
		PANIC("yylabel", "Null tree in", OP_LABEL(u));
	STATE_LABEL(a) = p = (struct yystate *)malloc(sizeof *p);
	memset(p, 0, sizeof *p);
	p->cost[1] =
	p->cost[2] =
	p->cost[3] =
	p->cost[4] =
	p->cost[5] =
	p->cost[6] =
	p->cost[7] =
	p->cost[8] =
	p->cost[9] =
	p->cost[10] =
	p->cost[11] =
	p->cost[12] =
	p->cost[13] =
	p->cost[14] =
	p->cost[15] =
	p->cost[16] =
	p->cost[17] =
	p->cost[18] =
	p->cost[19] =
	p->cost[20] =
	p->cost[21] =
	p->cost[22] =
	p->cost[23] =
	p->cost[24] =
	p->cost[25] =
	p->cost[26] =
	p->cost[27] =
	p->cost[28] =
	p->cost[29] =
	p->cost[30] =
	p->cost[31] =
	p->cost[32] =
		0x7fff;
	switch (OP_LABEL(a)) {
	case 33: /* t_NOT */
		return;
	case 35: /* HASH */
		return;
	case 37: /* MOD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: MOD(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 32, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 6;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 38: /* AND */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: AND(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 44, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 18;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 40: /* t_OPENP */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* finit: t_OPENP(blocop,params) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyblocop_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparams_NT] + 1;
		yytrace(a, 1, c + 0, p->cost[yyfinit_NT]);
		if (c + 0 < p->cost[yyfinit_NT]) {
			p->cost[yyfinit_NT] = c + 0;
			p->rule.yyfinit = 1;
		}
		if (	/* finit: t_OPENP(blocop,NIL) */
			OP_LABEL(RIGHT_CHILD(a)) == 296 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyblocop_NT] + 1;
			yytrace(a, 2, c + 0, p->cost[yyfinit_NT]);
			if (c + 0 < p->cost[yyfinit_NT]) {
				p->cost[yyfinit_NT] = c + 0;
				p->rule.yyfinit = 2;
			}
		}
		break;
	case 42: /* MUL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: MUL(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 30, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 4;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: MUL(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 54, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 4;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 43: /* ADD */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: ADD(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 28, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 2;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: ADD(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 52, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 2;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 44: /* t_COMA */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* params: t_COMA(params,param) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyparams_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparam_NT] + 1;
		yytrace(a, 14, c + 0, p->cost[yyparams_NT]);
		if (c + 0 < p->cost[yyparams_NT]) {
			p->cost[yyparams_NT] = c + 0;
			p->rule.yyparams = 2;
		}
		if (	/* args: t_COMA(NIL,expr) */
			OP_LABEL(LEFT_CHILD(a)) == 296 /* NIL */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
			yytrace(a, 16, c + 0, p->cost[yyargs_NT]);
			if (c + 0 < p->cost[yyargs_NT]) {
				p->cost[yyargs_NT] = c + 0;
				p->rule.yyargs = 1;
			}
		}
		/* args: t_COMA(args,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyargs_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 17, c + 0, p->cost[yyargs_NT]);
		if (c + 0 < p->cost[yyargs_NT]) {
			p->cost[yyargs_NT] = c + 0;
			p->rule.yyargs = 2;
		}
		break;
	case 45: /* SUB */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: SUB(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 29, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 3;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: SUB(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 53, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 3;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 47: /* DIV */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: DIV(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 31, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 5;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: DIV(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 55, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 5;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 59: /* t_END */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* decls: t_END(decls,param) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydecls_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyparam_NT] + 1;
		yytrace(a, 7, c + 0, p->cost[yydecls_NT]);
		if (c + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = c + 0;
			p->rule.yydecls = 2;
		}
		/* list: t_END(list,base) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yybase_NT] + 1;
		yytrace(a, 9, c + 0, p->cost[yylist_NT]);
		if (c + 0 < p->cost[yylist_NT]) {
			p->cost[yylist_NT] = c + 0;
			p->rule.yylist = 2;
		}
		/* base_for: t_END(expr,for) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyfor_NT] + 1;
		yytrace(a, 84, c + 0, p->cost[yybase_for_NT]);
		if (c + 0 < p->cost[yybase_for_NT]) {
			p->cost[yybase_for_NT] = c + 0;
			p->rule.yybase_for = 1;
			yyclosure_base_for(a, c + 0);
		}
		/* end_for: t_END(corpo_for,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycorpo_for_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 86, c + 0, p->cost[yyend_for_NT]);
		if (c + 0 < p->cost[yyend_for_NT]) {
			p->cost[yyend_for_NT] = c + 0;
			p->rule.yyend_for = 1;
		}
		break;
	case 60: /* LT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LT(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 40, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 14;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LT(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 59, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 26;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 61: /* EQ */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: EQ(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 38, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 12;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: EQ(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 57, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 24;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 62: /* GT */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: GT(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 42, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 16;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GT(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 61, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 28;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 123: /* t_BRACKET */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* bloco: t_BRACKET(list,decls) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 1;
		yytrace(a, 4, c + 0, p->cost[yybloco_NT]);
		if (c + 0 < p->cost[yybloco_NT]) {
			p->cost[yybloco_NT] = c + 0;
			p->rule.yybloco = 1;
			yyclosure_bloco(a, c + 0);
		}
		if (	/* bloco: t_BRACKET(t_END(list,stmt),decls) */
			OP_LABEL(LEFT_CHILD(a)) == 59 /* t_END */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(LEFT_CHILD(a))))->cost[yylist_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(LEFT_CHILD(a))))->cost[yystmt_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yydecls_NT] + 1;
			yytrace(a, 5, c + 0, p->cost[yybloco_NT]);
			if (c + 0 < p->cost[yybloco_NT]) {
				p->cost[yybloco_NT] = c + 0;
				p->rule.yybloco = 2;
				yyclosure_bloco(a, c + 0);
			}
		}
		break;
	case 124: /* OR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: OR(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 45, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 19;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 257: /* INT */
		/* iexpr: INT */
		yytrace(a, 27, 1 + 0, p->cost[yyiexpr_NT]);
		if (1 + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = 1 + 0;
			p->rule.yyiexpr = 1;
			yyclosure_iexpr(a, 1 + 0);
		}
		break;
	case 258: /* REAL */
		/* rexpr: REAL */
		yytrace(a, 51, 1 + 0, p->cost[yyrexpr_NT]);
		if (1 + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = 1 + 0;
			p->rule.yyrexpr = 1;
			yyclosure_rexpr(a, 1 + 0);
		}
		break;
	case 259: /* ID */
		return;
	case 260: /* STR */
		/* sexpr: STR */
		yytrace(a, 70, 1 + 0, p->cost[yysexpr_NT]);
		if (1 + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = 1 + 0;
			p->rule.yysexpr = 1;
			yyclosure_sexpr(a, 1 + 0);
		}
		break;
	case 261: /* DO */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* do: DO(start,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystart_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 81, c + 0, p->cost[yydo_NT]);
		if (c + 0 < p->cost[yydo_NT]) {
			p->cost[yydo_NT] = c + 0;
			p->rule.yydo = 1;
		}
		break;
	case 262: /* WHILE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* base_while: WHILE(do,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yydo_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 80, c + 0, p->cost[yybase_while_NT]);
		if (c + 0 < p->cost[yybase_while_NT]) {
			p->cost[yybase_while_NT] = c + 0;
			p->rule.yybase_while = 1;
			yyclosure_base_while(a, c + 0);
		}
		break;
	case 263: /* IF */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* base_if: IF(cond,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 74, c + 0, p->cost[yybase_if_NT]);
		if (c + 0 < p->cost[yybase_if_NT]) {
			p->cost[yybase_if_NT] = c + 0;
			p->rule.yybase_if = 1;
			yyclosure_base_if(a, c + 0);
		}
		/* if: IF(cond,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yycond_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 78, c + 0, p->cost[yyif_NT]);
		if (c + 0 < p->cost[yyif_NT]) {
			p->cost[yyif_NT] = c + 0;
			p->rule.yyif = 1;
		}
		break;
	case 264: /* THEN */
		return;
	case 265: /* FOR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* for: FOR(in_for,end_for) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyin_for_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyend_for_NT] + 1;
		yytrace(a, 85, c + 0, p->cost[yyfor_NT]);
		if (c + 0 < p->cost[yyfor_NT]) {
			p->cost[yyfor_NT] = c + 0;
			p->rule.yyfor = 1;
		}
		break;
	case 266: /* IN */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* in_for: IN(start_for,expr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yystart_for_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyexpr_NT] + 1;
		yytrace(a, 88, c + 0, p->cost[yyin_for_NT]);
		if (c + 0 < p->cost[yyin_for_NT]) {
			p->cost[yyin_for_NT] = c + 0;
			p->rule.yyin_for = 1;
		}
		break;
	case 267: /* UPTO */
		return;
	case 268: /* DOWNTO */
		return;
	case 269: /* STEP */
		return;
	case 270: /* BREAK */
		return;
	case 271: /* CONTINUE */
		return;
	case 272: /* VOID */
		return;
	case 273: /* INTEGER */
		/* tipo: INTEGER */
		yytrace(a, 18, 1 + 0, p->cost[yytipo_NT]);
		if (1 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 1 + 0;
			p->rule.yytipo = 1;
		}
		break;
	case 274: /* STRING */
		/* tipo: STRING */
		yytrace(a, 19, 1 + 0, p->cost[yytipo_NT]);
		if (1 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 1 + 0;
			p->rule.yytipo = 2;
		}
		break;
	case 275: /* NUMBER */
		/* tipo: NUMBER */
		yytrace(a, 20, 1 + 0, p->cost[yytipo_NT]);
		if (1 + 0 < p->cost[yytipo_NT]) {
			p->cost[yytipo_NT] = 1 + 0;
			p->rule.yytipo = 3;
		}
		break;
	case 276: /* CONST */
		return;
	case 277: /* PUBLIC */
		return;
	case 278: /* INCR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: INCR(lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylv_NT] + 1;
		yytrace(a, 33, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 7;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 279: /* DECR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: DECR(lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylv_NT] + 1;
		yytrace(a, 34, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 8;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 280: /* IFX */
		return;
	case 281: /* ELSE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* base_else: ELSE(if,stmt) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyif_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yystmt_NT] + 1;
		yytrace(a, 77, c + 0, p->cost[yybase_else_NT]);
		if (c + 0 < p->cost[yybase_else_NT]) {
			p->cost[yybase_else_NT] = c + 0;
			p->rule.yybase_else = 1;
			yyclosure_base_else(a, c + 0);
		}
		break;
	case 282: /* ATR */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: ATR(iassign,lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylv_NT] + (isInt(a));
		yytrace(a, 46, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 20;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: ATR(rassign,lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylv_NT] + (isReal(a));
		yytrace(a, 65, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 8;
			yyclosure_rexpr(a, c + 0);
		}
		/* sexpr: ATR(sassign,lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yysassign_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yylv_NT] + 1;
		yytrace(a, 71, c + 0, p->cost[yysexpr_NT]);
		if (c + 0 < p->cost[yysexpr_NT]) {
			p->cost[yysexpr_NT] = c + 0;
			p->rule.yysexpr = 2;
			yyclosure_sexpr(a, c + 0);
		}
		break;
	case 283: /* NE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: NE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 39, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 13;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: NE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 58, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 25;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 284: /* GE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: GE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 43, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 17;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: GE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 62, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 29;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 285: /* LE */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		/* iexpr: LE(iexpr,iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 41, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 15;
			yyclosure_iexpr(a, c + 0);
		}
		/* iexpr: LE(rexpr,rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 60, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 27;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 286: /* UMINUS */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: UMINUS(iexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyiexpr_NT] + 1;
		yytrace(a, 37, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 11;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: UMINUS(rexpr) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yyrexpr_NT] + 1;
		yytrace(a, 56, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 6;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 287: /* NOT */
		return;
	case 288: /* REF */
		return;
	case 289: /* LOCAL */
		/* lv: LOCAL */
		yytrace(a, 21, 1 + 0, p->cost[yylv_NT]);
		if (1 + 0 < p->cost[yylv_NT]) {
			p->cost[yylv_NT] = 1 + 0;
			p->rule.yylv = 1;
		}
		break;
	case 290: /* POSINC */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: POSINC(lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylv_NT] + 1;
		yytrace(a, 35, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 9;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 291: /* POSDEC */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: POSDEC(lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylv_NT] + 1;
		yytrace(a, 36, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 10;
			yyclosure_iexpr(a, c + 0);
		}
		break;
	case 292: /* PTR */
		yylabel(LEFT_CHILD(a),a);
		/* iexpr: PTR(lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylv_NT] + (isInt(a));
		yytrace(a, 47, c + 0, p->cost[yyiexpr_NT]);
		if (c + 0 < p->cost[yyiexpr_NT]) {
			p->cost[yyiexpr_NT] = c + 0;
			p->rule.yyiexpr = 21;
			yyclosure_iexpr(a, c + 0);
		}
		/* rexpr: PTR(lv) */
		c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yylv_NT] + (isReal(a));
		yytrace(a, 66, c + 0, p->cost[yyrexpr_NT]);
		if (c + 0 < p->cost[yyrexpr_NT]) {
			p->cost[yyrexpr_NT] = c + 0;
			p->rule.yyrexpr = 9;
			yyclosure_rexpr(a, c + 0);
		}
		break;
	case 293: /* CALL */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* expr: CALL(ID,args) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyargs_NT] + 1;
			yytrace(a, 25, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 4;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* expr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = 1;
			yytrace(a, 26, c + 0, p->cost[yyexpr_NT]);
			if (c + 0 < p->cost[yyexpr_NT]) {
				p->cost[yyexpr_NT] = c + 0;
				p->rule.yyexpr = 5;
				yyclosure_expr(a, c + 0);
			}
		}
		if (	/* iexpr: CALL(ID,args) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyargs_NT] + 1;
			yytrace(a, 49, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 22;
				yyclosure_iexpr(a, c + 0);
			}
		}
		if (	/* iexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = 1;
			yytrace(a, 50, c + 0, p->cost[yyiexpr_NT]);
			if (c + 0 < p->cost[yyiexpr_NT]) {
				p->cost[yyiexpr_NT] = c + 0;
				p->rule.yyiexpr = 23;
				yyclosure_iexpr(a, c + 0);
			}
		}
		if (	/* rexpr: CALL(ID,args) */
			OP_LABEL(LEFT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(RIGHT_CHILD(a)))->cost[yyargs_NT] + 1;
			yytrace(a, 68, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 10;
				yyclosure_rexpr(a, c + 0);
			}
		}
		if (	/* rexpr: CALL(ID,VOID) */
			OP_LABEL(LEFT_CHILD(a)) == 259 && /* ID */
			OP_LABEL(RIGHT_CHILD(a)) == 272 /* VOID */
		) {
			c = 1;
			yytrace(a, 69, c + 0, p->cost[yyrexpr_NT]);
			if (c + 0 < p->cost[yyrexpr_NT]) {
				p->cost[yyrexpr_NT] = c + 0;
				p->rule.yyrexpr = 11;
				yyclosure_rexpr(a, c + 0);
			}
		}
		break;
	case 294: /* START */
		/* start: START */
		yytrace(a, 82, 1 + 0, p->cost[yystart_NT]);
		if (1 + 0 < p->cost[yystart_NT]) {
			p->cost[yystart_NT] = 1 + 0;
			p->rule.yystart = 1;
		}
		/* start_for: START */
		yytrace(a, 89, 1 + 0, p->cost[yystart_for_NT]);
		if (1 + 0 < p->cost[yystart_for_NT]) {
			p->cost[yystart_for_NT] = 1 + 0;
			p->rule.yystart_for = 1;
		}
		break;
	case 295: /* PARAM */
		yylabel(LEFT_CHILD(a),a);
		yylabel(RIGHT_CHILD(a),a);
		if (	/* param: PARAM(tipo,ID) */
			OP_LABEL(RIGHT_CHILD(a)) == 259 /* ID */
		) {
			c = ((struct yystate *)STATE_LABEL(LEFT_CHILD(a)))->cost[yytipo_NT] + 1;
			yytrace(a, 15, c + 0, p->cost[yyparam_NT]);
			if (c + 0 < p->cost[yyparam_NT]) {
				p->cost[yyparam_NT] = c + 0;
				p->rule.yyparam = 1;
				yyclosure_param(a, c + 0);
			}
		}
		break;
	case 296: /* NIL */
		/* decls: NIL */
		yytrace(a, 6, 1 + 0, p->cost[yydecls_NT]);
		if (1 + 0 < p->cost[yydecls_NT]) {
			p->cost[yydecls_NT] = 1 + 0;
			p->rule.yydecls = 1;
		}
		break;
	default:
		PANIC("yylabel", "Bad terminal", OP_LABEL(a));
	}
}

static void yykids(NODEPTR_TYPE p, int eruleno, NODEPTR_TYPE kids[]) {
	if (!p)
		PANIC("yykids", "Null tree in rule", eruleno);
	if (!kids)
		PANIC("yykids", "Null kids in", OP_LABEL(p));
	switch (eruleno) {
	case 88: /* in_for: IN(start_for,expr) */
	case 86: /* end_for: t_END(corpo_for,expr) */
	case 85: /* for: FOR(in_for,end_for) */
	case 84: /* base_for: t_END(expr,for) */
	case 81: /* do: DO(start,stmt) */
	case 80: /* base_while: WHILE(do,expr) */
	case 78: /* if: IF(cond,stmt) */
	case 77: /* base_else: ELSE(if,stmt) */
	case 74: /* base_if: IF(cond,stmt) */
	case 71: /* sexpr: ATR(sassign,lv) */
	case 65: /* rexpr: ATR(rassign,lv) */
	case 62: /* iexpr: GE(rexpr,rexpr) */
	case 61: /* iexpr: GT(rexpr,rexpr) */
	case 60: /* iexpr: LE(rexpr,rexpr) */
	case 59: /* iexpr: LT(rexpr,rexpr) */
	case 58: /* iexpr: NE(rexpr,rexpr) */
	case 57: /* iexpr: EQ(rexpr,rexpr) */
	case 55: /* rexpr: DIV(rexpr,rexpr) */
	case 54: /* rexpr: MUL(rexpr,rexpr) */
	case 53: /* rexpr: SUB(rexpr,rexpr) */
	case 52: /* rexpr: ADD(rexpr,rexpr) */
	case 46: /* iexpr: ATR(iassign,lv) */
	case 45: /* iexpr: OR(iexpr,iexpr) */
	case 44: /* iexpr: AND(iexpr,iexpr) */
	case 43: /* iexpr: GE(iexpr,iexpr) */
	case 42: /* iexpr: GT(iexpr,iexpr) */
	case 41: /* iexpr: LE(iexpr,iexpr) */
	case 40: /* iexpr: LT(iexpr,iexpr) */
	case 39: /* iexpr: NE(iexpr,iexpr) */
	case 38: /* iexpr: EQ(iexpr,iexpr) */
	case 32: /* iexpr: MOD(iexpr,iexpr) */
	case 31: /* iexpr: DIV(iexpr,iexpr) */
	case 30: /* iexpr: MUL(iexpr,iexpr) */
	case 29: /* iexpr: SUB(iexpr,iexpr) */
	case 28: /* iexpr: ADD(iexpr,iexpr) */
	case 17: /* args: t_COMA(args,expr) */
	case 14: /* params: t_COMA(params,param) */
	case 9: /* list: t_END(list,base) */
	case 7: /* decls: t_END(decls,param) */
	case 4: /* bloco: t_BRACKET(list,decls) */
	case 1: /* finit: t_OPENP(blocop,params) */
		kids[0] = LEFT_CHILD(p);
		kids[1] = RIGHT_CHILD(p);
		break;
	case 66: /* rexpr: PTR(lv) */
	case 56: /* rexpr: UMINUS(rexpr) */
	case 47: /* iexpr: PTR(lv) */
	case 37: /* iexpr: UMINUS(iexpr) */
	case 36: /* iexpr: POSDEC(lv) */
	case 35: /* iexpr: POSINC(lv) */
	case 34: /* iexpr: DECR(lv) */
	case 33: /* iexpr: INCR(lv) */
	case 15: /* param: PARAM(tipo,ID) */
	case 2: /* finit: t_OPENP(blocop,NIL) */
		kids[0] = LEFT_CHILD(p);
		break;
	case 87: /* corpo_for: stmt */
	case 83: /* base: base_for */
	case 79: /* base: base_while */
	case 76: /* base: base_else */
	case 75: /* cond: expr */
	case 73: /* base: base_if */
	case 72: /* sassign: sexpr */
	case 67: /* rassign: rexpr */
	case 64: /* iassign: rexpr */
	case 63: /* rexpr: iexpr */
	case 48: /* iassign: iexpr */
	case 24: /* expr: rexpr */
	case 23: /* expr: sexpr */
	case 22: /* expr: iexpr */
	case 13: /* params: param */
	case 12: /* base: bloco */
	case 11: /* base: expr */
	case 10: /* stmt: base */
	case 8: /* list: base */
	case 3: /* blocop: bloco */
		kids[0] = p;
		break;
	case 5: /* bloco: t_BRACKET(t_END(list,stmt),decls) */
		kids[0] = LEFT_CHILD(LEFT_CHILD(p));
		kids[1] = RIGHT_CHILD(LEFT_CHILD(p));
		kids[2] = RIGHT_CHILD(p);
		break;
	case 89: /* start_for: START */
	case 82: /* start: START */
	case 70: /* sexpr: STR */
	case 69: /* rexpr: CALL(ID,VOID) */
	case 51: /* rexpr: REAL */
	case 50: /* iexpr: CALL(ID,VOID) */
	case 27: /* iexpr: INT */
	case 26: /* expr: CALL(ID,VOID) */
	case 21: /* lv: LOCAL */
	case 20: /* tipo: NUMBER */
	case 19: /* tipo: STRING */
	case 18: /* tipo: INTEGER */
	case 6: /* decls: NIL */
		break;
	case 68: /* rexpr: CALL(ID,args) */
	case 49: /* iexpr: CALL(ID,args) */
	case 25: /* expr: CALL(ID,args) */
	case 16: /* args: t_COMA(NIL,expr) */
		kids[0] = RIGHT_CHILD(p);
		break;
	default:
		PANIC("yykids", "Bad rule number", eruleno);
	}
}

static void yyreduce(NODEPTR_TYPE p, int goalnt)
{
  int eruleno = yyrule(STATE_LABEL(p), goalnt);
  short *nts = yynts[eruleno];
  NODEPTR_TYPE kids[3];
  int i;

  for (yykids(p, eruleno, kids), i = 0; nts[i]; i++)
    yyreduce(kids[i], nts[i]);

  switch(eruleno) {
	case 1: /* finit: t_OPENP(blocop,params) */
#line 90 "diy.brg"
{if (returnType == DOUBLE) 
									fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP, 8);
								   else 
									fprintf(outfp, pfLOCAL pfLOAD pfPOP, 8);
								   }
		break;
	case 2: /* finit: t_OPENP(blocop,NIL) */
#line 95 "diy.brg"
{if (returnType == DOUBLE) 
									fprintf(outfp, pfLOCAL pfLOAD2 pfDPOP, 8);
								   else 
									fprintf(outfp, pfLOCAL pfLOAD pfPOP, 8);
								   }
		break;
	case 3: /* blocop: bloco */
#line 101 "diy.brg"
{}
		break;
	case 4: /* bloco: t_BRACKET(list,decls) */
#line 103 "diy.brg"
{}
		break;
	case 5: /* bloco: t_BRACKET(t_END(list,stmt),decls) */
#line 104 "diy.brg"
{}
		break;
	case 6: /* decls: NIL */
#line 107 "diy.brg"
{}
		break;
	case 7: /* decls: t_END(decls,param) */
#line 108 "diy.brg"
{}
		break;
	case 8: /* list: base */
#line 110 "diy.brg"
{}
		break;
	case 9: /* list: t_END(list,base) */
#line 111 "diy.brg"
{}
		break;
	case 10: /* stmt: base */
#line 113 "diy.brg"
{}
		break;
	case 11: /* base: expr */
#line 115 "diy.brg"
{fprintf(outfp, pfTRASH, (int)p->place); }
		break;
	case 12: /* base: bloco */
#line 116 "diy.brg"
{}
		break;
	case 13: /* params: param */
#line 118 "diy.brg"
{}
		break;
	case 14: /* params: t_COMA(params,param) */
#line 119 "diy.brg"
{}
		break;
	case 15: /* param: PARAM(tipo,ID) */
#line 121 "diy.brg"
{}
		break;
	case 16: /* args: t_COMA(NIL,expr) */
#line 123 "diy.brg"
{ p->place = RIGHT_CHILD(p)->place;}
		break;
	case 17: /* args: t_COMA(args,expr) */
#line 124 "diy.brg"
{ p->place = LEFT_CHILD(p)->place + RIGHT_CHILD(p)->place;}
		break;
	case 18: /* tipo: INTEGER */
#line 126 "diy.brg"
{}
		break;
	case 19: /* tipo: STRING */
#line 127 "diy.brg"
{}
		break;
	case 20: /* tipo: NUMBER */
#line 128 "diy.brg"
{}
		break;
	case 21: /* lv: LOCAL */
#line 130 "diy.brg"
{fprintf(outfp, pfLOCAL, p->value.i * (pfWORD/4));}
		break;
	case 22: /* expr: iexpr */
#line 132 "diy.brg"
{p->place = 4;}
		break;
	case 23: /* expr: sexpr */
#line 133 "diy.brg"
{p->place = 4;}
		break;
	case 24: /* expr: rexpr */
#line 134 "diy.brg"
{p->place = 8;}
		break;
	case 25: /* expr: CALL(ID,args) */
#line 135 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)((RIGHT_CHILD(p)->place))); setPlace(p);}
		break;
	case 26: /* expr: CALL(ID,VOID) */
#line 136 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s)); setPlace(p);}
		break;
	case 27: /* iexpr: INT */
#line 141 "diy.brg"
{fprintf(outfp, pfIMM, p->value.i);}
		break;
	case 28: /* iexpr: ADD(iexpr,iexpr) */
#line 142 "diy.brg"
{ fprintf(outfp, pfADD); }
		break;
	case 29: /* iexpr: SUB(iexpr,iexpr) */
#line 143 "diy.brg"
{ fprintf(outfp, pfSUB); }
		break;
	case 30: /* iexpr: MUL(iexpr,iexpr) */
#line 144 "diy.brg"
{ fprintf(outfp, pfMUL); }
		break;
	case 31: /* iexpr: DIV(iexpr,iexpr) */
#line 145 "diy.brg"
{ fprintf(outfp, pfDIV); }
		break;
	case 32: /* iexpr: MOD(iexpr,iexpr) */
#line 146 "diy.brg"
{ fprintf(outfp, pfMOD); }
		break;
	case 33: /* iexpr: INCR(lv) */
#line 147 "diy.brg"
{ fprintf(outfp, pfDUP pfINCR pfLOAD, 1); }
		break;
	case 34: /* iexpr: DECR(lv) */
#line 148 "diy.brg"
{ fprintf(outfp, pfDUP pfDECR pfLOAD, 1); }
		break;
	case 35: /* iexpr: POSINC(lv) */
#line 149 "diy.brg"
{ fprintf(outfp, pfDUP pfLOAD pfSWAP pfINCR, 1); }
		break;
	case 36: /* iexpr: POSDEC(lv) */
#line 150 "diy.brg"
{ fprintf(outfp, pfDUP pfLOAD pfSWAP pfDECR, 1); }
		break;
	case 37: /* iexpr: UMINUS(iexpr) */
#line 151 "diy.brg"
{ fprintf(outfp, pfNEG); }
		break;
	case 38: /* iexpr: EQ(iexpr,iexpr) */
#line 154 "diy.brg"
{ fprintf(outfp, pfEQ); }
		break;
	case 39: /* iexpr: NE(iexpr,iexpr) */
#line 155 "diy.brg"
{ fprintf(outfp, pfNE); }
		break;
	case 40: /* iexpr: LT(iexpr,iexpr) */
#line 156 "diy.brg"
{ fprintf(outfp, pfLT); }
		break;
	case 41: /* iexpr: LE(iexpr,iexpr) */
#line 157 "diy.brg"
{ fprintf(outfp, pfLE); }
		break;
	case 42: /* iexpr: GT(iexpr,iexpr) */
#line 158 "diy.brg"
{ fprintf(outfp, pfGT); }
		break;
	case 43: /* iexpr: GE(iexpr,iexpr) */
#line 159 "diy.brg"
{ fprintf(outfp, pfGE); }
		break;
	case 44: /* iexpr: AND(iexpr,iexpr) */
#line 160 "diy.brg"
{ fprintf(outfp, pfAND); }
		break;
	case 45: /* iexpr: OR(iexpr,iexpr) */
#line 161 "diy.brg"
{ fprintf(outfp, pfOR); }
		break;
	case 46: /* iexpr: ATR(iassign,lv) */
#line 165 "diy.brg"
{ fprintf(outfp, pfSTORE);}
		break;
	case 47: /* iexpr: PTR(lv) */
#line 166 "diy.brg"
{ fprintf(outfp, pfLOAD); }
		break;
	case 48: /* iassign: iexpr */
#line 167 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 49: /* iexpr: CALL(ID,args) */
#line 170 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)((RIGHT_CHILD(p)->place)));}
		break;
	case 50: /* iexpr: CALL(ID,VOID) */
#line 171 "diy.brg"
{fprintf(outfp, pfCALL pfPUSH, mkfunc(LEFT_CHILD(p)->value.s));}
		break;
	case 51: /* rexpr: REAL */
#line 175 "diy.brg"
{lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL pfDOUBLE, mklbl(lbl), p->value.r); fprintf(outfp, pfTEXT pfADDR pfLOAD2, mklbl(lbl));}
		break;
	case 52: /* rexpr: ADD(rexpr,rexpr) */
#line 176 "diy.brg"
{ fprintf(outfp, pfDADD); }
		break;
	case 53: /* rexpr: SUB(rexpr,rexpr) */
#line 177 "diy.brg"
{ fprintf(outfp, pfDSUB); }
		break;
	case 54: /* rexpr: MUL(rexpr,rexpr) */
#line 178 "diy.brg"
{ fprintf(outfp, pfDMUL); }
		break;
	case 55: /* rexpr: DIV(rexpr,rexpr) */
#line 179 "diy.brg"
{ fprintf(outfp, pfDDIV); }
		break;
	case 56: /* rexpr: UMINUS(rexpr) */
#line 180 "diy.brg"
{ fprintf(outfp, pfDNEG); }
		break;
	case 57: /* iexpr: EQ(rexpr,rexpr) */
#line 183 "diy.brg"
{ fprintf(outfp, pfDCMP pfIMM pfEQ, 0); }
		break;
	case 58: /* iexpr: NE(rexpr,rexpr) */
#line 184 "diy.brg"
{ fprintf(outfp, pfDCMP pfIMM pfNE, 0); }
		break;
	case 59: /* iexpr: LT(rexpr,rexpr) */
#line 185 "diy.brg"
{ fprintf(outfp, pfDCMP pfIMM pfLT, 0); }
		break;
	case 60: /* iexpr: LE(rexpr,rexpr) */
#line 186 "diy.brg"
{ fprintf(outfp, pfDCMP pfIMM pfLE, 0); }
		break;
	case 61: /* iexpr: GT(rexpr,rexpr) */
#line 187 "diy.brg"
{ fprintf(outfp, pfDCMP pfIMM pfGT, 0); }
		break;
	case 62: /* iexpr: GE(rexpr,rexpr) */
#line 188 "diy.brg"
{ fprintf(outfp, pfDCMP pfIMM pfGE, 0); }
		break;
	case 63: /* rexpr: iexpr */
#line 191 "diy.brg"
{ fprintf(outfp, pfI2D);}
		break;
	case 64: /* iassign: rexpr */
#line 192 "diy.brg"
{fprintf(outfp, pfD2I pfDUP);}
		break;
	case 65: /* rexpr: ATR(rassign,lv) */
#line 196 "diy.brg"
{fprintf(outfp, pfSTORE2);}
		break;
	case 66: /* rexpr: PTR(lv) */
#line 197 "diy.brg"
{fprintf(outfp, pfLOAD2); }
		break;
	case 67: /* rassign: rexpr */
#line 198 "diy.brg"
{fprintf(outfp, pfDUP2);}
		break;
	case 68: /* rexpr: CALL(ID,args) */
#line 200 "diy.brg"
{fprintf(outfp, pfCALL pfTRASH pfDPUSH, mkfunc(LEFT_CHILD(p)->value.s), (int)((RIGHT_CHILD(p)->place)));}
		break;
	case 69: /* rexpr: CALL(ID,VOID) */
#line 201 "diy.brg"
{fprintf(outfp, pfCALL pfDPUSH, mkfunc(LEFT_CHILD(p)->value.s));}
		break;
	case 70: /* sexpr: STR */
#line 205 "diy.brg"
{lbl++; fprintf(outfp, pfRODATA pfALIGN pfLABEL, mklbl(lbl)); 
							outstr(p->value.s); fprintf(outfp, pfTEXT pfADDR, mklbl(lbl));}
		break;
	case 71: /* sexpr: ATR(sassign,lv) */
#line 208 "diy.brg"
{fprintf(outfp, pfSTORE);}
		break;
	case 72: /* sassign: sexpr */
#line 209 "diy.brg"
{fprintf(outfp, pfDUP);}
		break;
	case 73: /* base: base_if */
#line 213 "diy.brg"
{}
		break;
	case 74: /* base_if: IF(cond,stmt) */
#line 214 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(p)->place));}
		break;
	case 75: /* cond: expr */
#line 215 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJZ, mklbl(p->place)); }
		break;
	case 76: /* base: base_else */
#line 218 "diy.brg"
{}
		break;
	case 77: /* base_else: ELSE(if,stmt) */
#line 219 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(LEFT_CHILD(
								p)->place)); }
		break;
	case 78: /* if: IF(cond,stmt) */
#line 221 "diy.brg"
{ p->place = ++lbl; fprintf(outfp, pfJMP pfLABEL,
								mklbl(p->place), mklbl(LEFT_CHILD(p)->place)); }
		break;
	case 79: /* base: base_while */
#line 225 "diy.brg"
{}
		break;
	case 80: /* base_while: WHILE(do,expr) */
#line 226 "diy.brg"
{ cycleIndex--;  fprintf(outfp,  pfJNZ pfLABEL , mklbl(cycleControlers[cycleIndex].start), mklbl(cycleControlers[cycleIndex].end)); }
		break;
	case 81: /* do: DO(start,stmt) */
#line 227 "diy.brg"
{}
		break;
	case 82: /* start: START */
#line 228 "diy.brg"
{  fprintf(outfp, pfLABEL,  mklbl(cycleControlers[initCycleControler_while()].start));  }
		break;
	case 83: /* base: base_for */
#line 231 "diy.brg"
{}
		break;
	case 84: /* base_for: t_END(expr,for) */
#line 232 "diy.brg"
{cycleIndex--; fprintf(outfp, pfLABEL, mklbl(cycleControlers[cycleIndex].end));}
		break;
	case 85: /* for: FOR(in_for,end_for) */
#line 234 "diy.brg"
{ fprintf(outfp, pfJMP, mklbl(cycleControlers[cycleIndex-1].start) );}
		break;
	case 86: /* end_for: t_END(corpo_for,expr) */
#line 235 "diy.brg"
{}
		break;
	case 87: /* corpo_for: stmt */
#line 237 "diy.brg"
{ fprintf(outfp, pfLABEL, mklbl(cycleControlers[cycleIndex-1].cont) ); }
		break;
	case 88: /* in_for: IN(start_for,expr) */
#line 239 "diy.brg"
{fprintf(outfp, pfJZ,  mklbl(cycleControlers[cycleIndex-1].end)); }
		break;
	case 89: /* start_for: START */
#line 240 "diy.brg"
{ fprintf(outfp, pfLABEL,  mklbl(cycleControlers[initCycleControler_for()].start)); }
		break;
	default: break;
  }
}

int yyselect(NODEPTR_TYPE p)
{
	yylabel(p,p);
	if (((struct yystate *)STATE_LABEL(p))->rule.yyfinit == 0) {
		fprintf(stderr, "No match for start symbol (%s).\n", yyntname[1]);
		return 1;
	}
	yyreduce(p, 1);
	return 0;
}


#line 244 "diy.brg"

#include "y.tab.h"
extern void yyerror(const char*);
extern char **yynames;
extern int trace;

void externs() {
  int i;
  
  for (i = 0; i < extcnt; i++)
    if (extrns[i])
      fprintf(outfp, pfEXTRN, extrns[i]);
}



void function(int pub, Node *type, char *name, Node *body) {
	returnType = type->value.i;
	Node *bloco = LEFT_CHILD(body);
	IDpop();
	if (bloco != 0) { /* not a forward declaration */
		long par;
		int fwd = IDfind(name, &par);
		if (fwd > 40) yyerror("duplicate function");
		else {
			IDreplace(fwd+40, name, par);
			fflush(stdout);
  			fprintf(outfp, pfTEXT pfALIGN pfGLOBL pfLABEL pfENTER, mkfunc(name), pfFUNC, mkfunc(name), sizeOfLocalVariable * (pfWORD/4));
  			yyselect(body);
  			fprintf(outfp, pfLEAVE pfRET); /* just in case ... */
  			freeNode(body);
  			
			int i;
			for (i = 0; i < extcnt; i++)
    			if (extrns[i] && strcmp(extrns[i], mkfunc(name)) == 0) 
    				extrns[i] = 0;
			}
	}
	else {
		char *array = malloc(sizeof(char)*80);
		array[0] = '\0';

		/*char array[80] ;
		array[0] = '\0';*/
		strcpy(array, "_");
		strcat(array, name);
		extrns[extcnt++] = array;
		
	}
}
