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
%nonassoc '!' UMINUS INCR DECR PONT ENDE
%nonassoc '[' '('

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

corpo 		:'{' prmtOrMore instrOrMore '}'
			;

prmtOrMore : parametro ';'
		   | parametro ';' prmtOrMore
		   ;


instrOrMore	: instrucao
			| instrucao instrOrMore
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
			| expressao '(' args ')'		
			| expressao '(' ')'				
      		| '-' expressao %prec UMINUS 	
			| '&' lvalue %prec ENDE				
			| '~' expressao					
			| lvalue INCR		
			| lvalue DECR	
			| INCR lvalue		
			| DECR lvalue		
     		| expressao '*' expressao	
     		| expressao '/' expressao	
     		| expressao '%' expressao	
    		| expressao '+' expressao	
    		| expressao '-' expressao	
			| expressao '<' expressao	
			| expressao '>' expressao	
			| expressao GE expressao
			| expressao LE expressao	
			| expressao '=' expressao	
			| expressao NE expressao	
    		| expressao '&' expressao	
    		| expressao '|' expressao	
			| lvalue ATR expressao	
       		;

args	: expressao		
		| args ',' expressao
		;
		


%%
char **yynames =
#if YYDEBUG > 0
		 (char**)yyname;
#else
		 0;
#endif
