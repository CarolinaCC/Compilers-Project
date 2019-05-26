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
extern YYSTYPE yylval;
