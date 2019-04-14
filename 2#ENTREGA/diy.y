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

%type<n> file stmt initOrNon pubOuConstOrNone astOrNon tipo init prmtsOrNon crpOrNon cnstOrNon parametros parametro corpo prmtNonOrMore instrNonOrMore instrucao stp upOrDown els inteirOrNon lvalue expressao args
	
%token tEQ tGT tLT tAND tBOR tMUL tDIV tMOD tADD tSUB tNOT 
%token tCALL tPTR tARG tEND tINDEX tLOAD tOR tALLOC tSTAR tCONSTSTR tPARA tPUBoN tFILE tSTMT tPUBeTIPO tSTARMORE tIDINIT tPRMTCRP tCORPO tINSTM tSTARID tFINST tTIPOSTAR tFEXPSTP tFLVEX tUPDOWN tFORX tPARAM tSTMT1 tSTMTN tSTMTSTARTID tSTMTPRMTCORP
%%

file	:			 { $$ = nilNode(tEND); } 
		| file stmt	 { $$ = binNode(tFILE, $1, $2 ); printNode($$, 0, (char**)yyname); }
		;

stmt 	: pubOuConstOrNone tipo astOrNon ID initOrNon ';' { $$ = binNode(tSTMT, binNode(tPUBeTIPO, $1, $2), binNode(tSTARMORE, $3, binNode(tIDINIT, strNode(ID, $4), $5 ))); } 
		| pubOuConstOrNone tipo astOrNon ID '(' prmtsOrNon ')' crpOrNon { $$ = binNode(tSTMT1, binNode(tPUBeTIPO, $1, $2), binNode(tSTMTN, binNode(tSTMTSTARTID, $3, strNode(ID, $4)), binNode(tSTMTPRMTCORP, $6, $8))); } 
		;


initOrNon : 				{ $$ = nilNode(tEND); }
		  | ATR init		{ $$ = uniNode(ATR, $2); }
		  ;

pubOuConstOrNone : cnstOrNon 	  		{ $$ = binNode(tPUBoN, nilNode(tEND), $1 ); } 
				 | PUBLIC cnstOrNon 	{ $$ = binNode(tPUBoN, nilNode(PUBLIC), $2 ); }
				 ;


astOrNon: 		{ $$ = nilNode(tEND); }
		| '*'	{ $$ = nilNode(tSTAR); }
		;

tipo	: INTEGER 	{ $$ = nilNode(INTEGER); }
		| STRING 	{ $$ = nilNode(STRING); }
		| NUMBER 	{ $$ = nilNode(NUMBER); }
		| VOID 		{ $$ = nilNode(VOID); }
		;

init 	: 					{ $$ = nilNode(tEND); }
		| INT 				{ $$ = intNode(INT, $1); $$->info = 1}
		| cnstOrNon STR 	{ $$ = binNode(tCONSTSTR, $1, strNode(STR, $2)); }
		| REAL 				{ $$ = realNode(REAL, $1); $$->info = 2}
		| ID 				{ $$ = strNode(ID, $1); }
		;

prmtsOrNon:					{ $$ = nilNode(tEND); } 
		  | parametros		{ $$ = $1; }
		  ;


crpOrNon: 			{ $$ = nilNode(tEND); }
		| corpo		{ $$ = $1; }
		;

cnstOrNon : 		{ $$ = nilNode(tEND); }
		  | CONST   { $$ = nilNode(CONST); }
		  ;

parametros 	: parametro 			   { $$ = binNode(tPARA, $1, nilNode(tEND)); }
			| parametro ',' parametros { $$ = binNode(tPARA, $1, $3); }
			;

parametro   : tipo astOrNon ID  	{ $$ = binNode(tTIPOSTAR, $1, binNode(tSTARID, $2, strNode(ID, $3)));}
			;

corpo 		:'{' prmtNonOrMore instrNonOrMore '}' { $$ = binNode(tCORPO, $2, $3);}
			;

prmtNonOrMore : 								{ $$ = nilNode(tEND); }
		  	  | parametro ';' prmtNonOrMore		{ $$ = binNode(tPARAM, $1, $3);}
		   	  ;


instrNonOrMore	: 								{ $$ = nilNode(tEND); }
				| instrucao instrNonOrMore		{ $$ = binNode(tINSTM, $1, $2);}
				;

instrucao 	: IF expressao THEN instrucao els  { $$ = binNode(IF, binNode(THEN, $2, $4), $5); }
			| DO instrucao WHILE expressao ';' { $$ = binNode(WHILE, $2, $4); }
			| FOR lvalue IN expressao upOrDown expressao stp DO instrucao { $$ = binNode(tFINST, binNode(tFORX, binNode(tFLVEX, $2, $4), binNode(tUPDOWN, $5, binNode(tFEXPSTP, $6, $7))), $9); }
			| expressao ';'    			{ $$ = $1; }
			| corpo 					{ $$ = $1; }
			| BREAK inteirOrNon ';'     { $$ = uniNode(BREAK, $2);  }		
			| CONTINUE inteirOrNon ';'	{ $$ = uniNode(CONTINUE, $2);  }		
			| lvalue '#' expressao ';'	{ $$ = binNode(tALLOC, $3, $1); }
			;

stp			:					{ $$ = nilNode(tEND); }
			| STEP expressao    { $$ = uniNode(STEP, $2);  }		
			;

upOrDown	: UPTO			{ $$ = nilNode(UPTO); }	
			| DOWNTO		{ $$ = nilNode(DOWNTO); }	
			;

els 		: %prec IFX		  { $$ = nilNode(tEND); }
			| ELSE instrucao  { $$ = uniNode(ELSE, $2);  }	
			;
	
inteirOrNon	: 				{ $$ = nilNode(tEND); }
			| INT 			{ $$ = intNode(INT, $1); }
			;

lvalue		: ID				        { $$ = strNode(ID , $1); }
			| lvalue '[' expressao ']'  { $$ = binNode(tINDEX, $1, $3); $$->info = 0; }
			| '*' lvalue				{ $$ = uniNode(tLOAD, $2); $$->info = 0; }	
			;

expressao	: INT 		{ $$ = intNode(INT, $1); }	
			| REAL 		{ $$ = realNode(REAL, $1); }	
			| STR 		{ $$ = strNode(STR, $1); }	
			| lvalue	{ $$ = uniNode(tLOAD, $1); }						
			| '(' expressao ')'			{ $$ = $2; }	
			| expressao '(' args ')'	{ $$ = binNode(tCALL, $1, $3); }	
			| expressao '(' ')'			{ $$ = binNode(tCALL, $1, nilNode(tEND)); }	
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
			| lvalue ATR expressao		{ $$ = binNode(ATR, $3, $1); }
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
