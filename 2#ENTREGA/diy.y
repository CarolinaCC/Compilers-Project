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
	
%token EQ GT LT BAND BOR MUL DIV MOD ADD SUB BNOT 
%token CALL PTR ARG EEND
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

lvalue		: ID				
			| lvalue '[' expressao ']'
			| '*' lvalue			
			;

expressao	: INT
			| REAL
			| STR
			| lvalue						
			| '(' expressao ')'				
			| expressao '(' args ')'	{ $$ = binNode(CALL, $1, $3); }	
			| expressao '(' ')'			{ $$ = binNode(CALL, $1, nilNode(EEND)); }	
      		| '-' expressao %prec UMINUS 	{ $$ = uniNode(UMINUS, $2); }
			| '&' lvalue %prec ENDE			{ $$ = uniNode(PTR, $2); }	
			| '~' expressao					{ $$ = uniNode(BNOT, $2); }	
			| lvalue INCR			{ $$ = binNode(INCR, $1, intNode(INT, 1)); }
			| lvalue DECR			{ $$ = binNode(DECR, $1, intNode(INT, 1)); }
			| INCR lvalue			{ $$ = binNode(INCR, intNode(INT, 1),  $2 ); }
			| DECR lvalue			{ $$ = binNode(DECR, intNode(INT, 1),  $2 ); }

     		| expressao '*' expressao	{ $$ = binNode(MUL, $1, $3); }
     		| expressao '/' expressao	{ $$ = binNode(DIV, $1, $3); }
     		| expressao '%' expressao	{ $$ = binNode(MOD, $1, $3); }
    		| expressao '+' expressao	{ $$ = binNode(ADD, $1, $3); }
    		| expressao '-' expressao	{ $$ = binNode(SUB, $1, $3); }
			| expressao '<' expressao	{ $$ = binNode(LT, $1, $3); }
			| expressao '>' expressao	{ $$ = binNode(GT, $1, $3); }
			| expressao GE expressao    { $$ = binNode(GE, $1, $3); }
			| expressao LE expressao    { $$ = binNode(LE, $1, $3); }	
			| expressao '=' expressao   { $$ = binNode(EQ, $1, $3); }	
			| expressao NE expressao	{ $$ = binNode(NE, $1, $3); }	
    		| expressao '&' expressao	{ $$ = binNode(BAND, $1, $3); }	
    		| expressao '|' expressao	{ $$ = binNode(BOR, $1, $3); }	
			| lvalue ATR expressao		{ $$ = binNode(ATR, $3, $1); }
       		;

args	: expressao		      { $$ = binNode(ARG, $1, nilNode(EEND)); }
		| args ',' expressao
		;
		


%%
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
