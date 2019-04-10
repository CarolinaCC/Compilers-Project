%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/tabid.h"
#include "lib/node.h"
extern int yylex();
int yyerror(char *s);
%}
%union {
	int i;			/* integer value */
	double r;		/* real value */
	char *s;		/* symbol name or string literal */
	Node *n;	/* tree node */
};
%token <i> INT
%token <r> REAL
%token <s> ID STR
%token DO WHILE IF THEN FOR IN UPTO DOWNTO STEP BREAK CONTINUE
%token VOID INTEGER STRING NUMBER CONST PUBLIC INCR DECR
%token ATR NE GE LE ELSE

%nonassoc IFX
%nonassoc ELSE
%right ATR
%left '|'
%left '&'
%nonassoc '~'
%left '=' NE
%left '<' '>' LE GE
%left '-' '+'
%left '*' '/' '%'
%nonassoc '!' UMINUS INCR DECR ENDE
%nonassoc '[' '('

%type<n> file stmt initOrNon pubOuConstOrNone astOrNon tipo init init1 prmtsOrNon crpOrNon cnstOrNon parametros parametro corpo prmtNonOrMore instrNonOrMore instrucao stp upOrDown els inteirOrNon lvalue expressao args
	
%token tEQ tGT tLT tBAND tBOR tMUL tDIV tMOD tADD tSUB tNOT 
%token tCALL tPTR tARG tEND tINDEX tLOAD
%%

file	: 
		| file stmt
		;

stmt 	: pubOuConstOrNone tipo astOrNon ID initOrNon ';'
		;

initOrNon : 
		  | init
		  ;

pubOuConstOrNone : cnstOrNon
				 | PUBLIC cnstOrNon
				 ;


astOrNon: 
		| '*'
		;

tipo	: INTEGER
		| STRING
		| NUMBER
		| VOID
		;

init 	: ATR init1
		| '(' prmtsOrNon ')' crpOrNon
		;

init1 	: 
		| INT
		| cnstOrNon STR
		| REAL
		| ID
		;

prmtsOrNon: 
		  | parametros
		  ;


crpOrNon: 
		| corpo
		;

cnstOrNon : 
		  | CONST
		  ;

parametros 	: parametro
			| parametro ',' parametros
			;

parametro   : tipo astOrNon ID
			;

corpo 		:'{' prmtNonOrMore instrNonOrMore '}'
			;

prmtNonOrMore : 
		  	  | parametro ';' prmtNonOrMore
		   	  ;


instrNonOrMore	: 
				| instrucao instrNonOrMore
				;

instrucao 	: IF expressao THEN instrucao els
			| DO instrucao WHILE expressao ';'
			| FOR lvalue IN expressao upOrDown expressao stp DO instrucao
			| expressao ';'
			| corpo 
			| BREAK inteirOrNon ';'
			| CONTINUE inteirOrNon ';'
			| lvalue '#' expressao ';'
			;

stp			:
			| STEP expressao
			;

upOrDown	: UPTO
			| DOWNTO
			;

els 		: %prec IFX
			| ELSE instrucao
			;
	
inteirOrNon	: 
			| INT 
			;

lvalue		: ID				        { $$ = ID($1); }
			| lvalue '[' expressao ']'  { $$ = binNode(INDEX, $1, $3); $$->info = 0; }
			| '*' lvalue				{ $$ = uniNode(tLOAD, $2); $$->info = 0; }	
			;

expressao	: INT
			| REAL
			| STR
			| lvalue						
			| '(' expressao ')'				
			| expressao '(' args ')'	{ $$ = binNode(tCALL, $1, $3); }	
			| expressao '(' ')'			{ $$ = binNode(tCALL, $1, nilNode(EEND)); }	
      		| '-' expressao %prec UMINUS 	{ $$ = uniNode(UMINUS, $2); }
			| '&' lvalue %prec ENDE			{ $$ = uniNode(tPTR, $2); }	
			| '~' expressao					{ $$ = uniNode(tNOT, $2); }	
			| lvalue INCR			{ $$ = binNode(INCR, $1, intNode(INT, 1)); }
			| lvalue DECR			{ $$ = binNode(DECR, $1, intNode(INT, 1)); }
			| INCR lvalue			{ $$ = binNode(INCR, intNode(INT, 1),  $2 ); }
			| DECR lvalue			{ $$ = binNode(DECR, intNode(INT, 1),  $2 ); }

     		| expressao '*' expressao	{ $$ = binNode(tMUL, $1, $3); }
     		| expressao '/' expressao	{ $$ = binNode(tDIV, $1, $3); }
     		| expressao '%' expressao	{ $$ = binNode(tMOD, $1, $3); }
    		| expressao '+' expressao	{ $$ = binNode(tADD, $1, $3); }
    		| expressao '-' expressao	{ $$ = binNode(tSUB, $1, $3); }
			| expressao '<' expressao	{ $$ = binNode(tLT, $1, $3); }
			| expressao '>' expressao	{ $$ = binNode(tGT, $1, $3); }
			| expressao GE expressao    { $$ = binNode(GE, $1, $3); }
			| expressao LE expressao    { $$ = binNode(LE, $1, $3); }	
			| expressao '=' expressao   { $$ = binNode(tEQ, $1, $3); }	
			| expressao NE expressao	{ $$ = binNode(NE, $1, $3); }	
    		| expressao '&' expressao	{ $$ = binNode(tAND, $1, $3); }	
    		| expressao '|' expressao	{ $$ = binNode(tOR, $1, $3); }	
			| lvalue ATR expressao		{ $$ = binNode(tATR, $3, $1); }
       		;

args	: expressao		      { $$ = binNode(tARG, $1, nilNode(tEND)); }
		| args ',' expressao  { $$ = binNode(tARG, $3, $1); }
		;
		


%%
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
