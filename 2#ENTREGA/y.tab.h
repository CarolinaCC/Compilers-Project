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
	Node *n;	/* tree node */
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
extern YYSTYPE yylval;
