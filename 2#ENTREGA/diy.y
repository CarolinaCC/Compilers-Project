%{
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

stmt 	: pubOuConstOrNone tipo astOrNon ID initOrNon ';' { $$ = binNode(tSTMT, binNode(tPUBeTIPO, $1, $2),binNode(tSTARMORE, $3, binNode(tIDINIT, strNode(ID, $4), $5 ))); verificacoesSTMT( $1->info, $2->info, $4->info, $5->info); } 
		| pubOuConstOrNone tipo astOrNon ID '(' prmtsOrNon ')' crpOrNon ';' { $$ = binNode(tSTMT1, binNode(tPUBeTIPO, $1, $2), binNode(tSTMTN, binNode(tSTMTSTARTID, $3, strNode(ID, $4)), binNode(tSTMTPRMTCORP, $6, $8))); /*TODO*/} 
		;


initOrNon : 				{ $$ = nilNode(tEND); $$->info = 0;}
		  | ATR init		{ $$ = uniNode(ATR, $2); $$->info = $2->info;}
		  ;

pubOuConstOrNone : cnstOrNon 	  		{ $$ = binNode(tPUBoN, nilNode(tEND), $1 ); $$->info = $1->info;} 
				 | PUBLIC cnstOrNon 	{ $$ = binNode(tPUBoN, nilNode(PUBLIC), $2 ); $$->info = $2->info + vpublic;}
				 ;


astOrNon: 		{ $$ = nilNode(tEND); $$->info = 0;}
		| '*'	{ $$ = nilNode(tSTAR); $$->info = vptr;}
		;

tipo	: INTEGER 	{ $$ = nilNode(INTEGER); $$->info = vint;}
		| STRING 	{ $$ = nilNode(STRING); $$->info = vstr;}
		| NUMBER 	{ $$ = nilNode(NUMBER); $$->info = vreal;}
		| VOID 		{ $$ = nilNode(VOID); $$->info = vvoid;}
		;

init 	: 					{ $$ = nilNode(tEND); $$->info = 0;}
		| INT 				{ $$ = intNode(INT, $1); $$->info = vint;}
		| cnstOrNon STR 	{ $$ = binNode(tCONSTSTR, $1, strNode(STR, $2)); $$->info = $1->info + vstr;}
		| REAL 				{ $$ = realNode(REAL, $1); $$->info=vreal;}
		| ID 				{ $$ = strNode(ID, $1); }
		;

prmtsOrNon:					{ $$ = nilNode(tEND); } 
		  | parametros		{ $$ = $1; }
		  ;


crpOrNon: 			{ $$ = nilNode(tEND); }
		| corpo		{ $$ = $1; }
		;

cnstOrNon : 		{ $$ = nilNode(tEND); $$->info = 0;}
		  | CONST   { $$ = nilNode(CONST); $$->info = vconst;}
		  ;

parametros 	: parametro 			   { $$ = binNode(tPARA, $1, nilNode(tEND)); }
			| parametro ',' parametros { $$ = binNode(tPARA, $1, $3); }
			;

parametro   : tipo astOrNon ID  	{ $$ = binNode(tTIPOSTAR, $1, binNode(tSTARID, $2, strNode(ID, $3))); 
										$$->info = $1->info + $2->info;}
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
			| INT 			{ $$ = intNode(INT, $1); $$->info = vint; }
			;

lvalue		: ID				        { $$ = strNode(ID , $1); }
			| lvalue '[' expressao ']'  { $$ = binNode(tINDEX, $1, $3); $$->info = 0; }
			| '*' lvalue				{ $$ = uniNode(tLOAD, $2); $$->info = 0; }	
			;

expressao	: INT 		{ $$ = intNode(INT, $1); $$->info = vint;}	
			| REAL 		{ $$ = realNode(REAL, $1); $$->info = vreal;}	
			| STR 		{ $$ = strNode(STR, $1); $$->info = vstr; }	
			| lvalue	{ $$ = uniNode(tLOAD, $1); $$->info = $1->info;}						
			| '(' expressao ')'			{ $$ = $2; $$->info = $2->info;}	
			| ID '(' args ')'	{ $$ = binNode(tCALL, strNode(ID , $1), $3); /*TODO*/}	
			| ID '(' ')'			{ $$ = binNode(tCALL, strNode(ID , $1), nilNode(tEND)); }	
      		| '-' expressao %prec UMINUS 	{ $$ = uniNode(UMINUS, $2); minusChecking($2->info); $$->info = ($2->info > vconst) ? $2->info - vconst + vptr : $2->info + vptr;}
			| '&' lvalue %prec ENDE			{ $$ = uniNode(tPTR, $2); isIntRealStrVoid($2->info); $$->info = £2>info; /*TODO*/ }	
			| '~' expressao					{ $$ = uniNode(tNOT, $2); isInt($2->info, 1);}	
			| lvalue INCR			{ $$ = binNode(INCR, $1, intNode(INT, 1)); isInt($1->info, 0);}
			| lvalue DECR			{ $$ = binNode(DECR, $1, intNode(INT, 1)); isInt($1->info, 0);}
			| INCR lvalue			{ $$ = binNode(INCR, intNode(INT, 1),  $2 ); isInt($2->info, 0);}
			| DECR lvalue			{ $$ = binNode(DECR, intNode(INT, 1),  $2 ); isInt($2->info, 0);}

     		| expressao '*' expressao	{ $$ = binNode(tMUL, $1, $3); areIntOrReal($1->info, $3->info);  $$->info = $1>$2 ? $1 : $2;}
     		| expressao '/' expressao	{ $$ = binNode(tDIV, $1, $3); areIntOrReal($1->info, $3->info);  $$->info = $1>$2 ? $1 : $2;}
     		| expressao '%' expressao	{ $$ = binNode(tMOD, $1, $3); areIntOrReal($1->info, $3->info);  $$->info = $1>$2 ? $1 : $2;}
    		| expressao '+' expressao	{ $$ = binNode(tADD, $1, $3); areIntOrReal($1->info, $3->info);  $$->info = $1>$2 ? $1 : $2;}
    		| expressao '-' expressao	{ $$ = binNode(tSUB, $1, $3); areIntOrReal($1->info, $3->info); $$->info = $1>$2 ? $1 : $2;}
			| expressao '<' expressao	{ $$ = binNode(tLT, $1, $3); areIntRealOrStr($1->info, $3->info); $$->info = vint;}
			| expressao '>' expressao	{ $$ = binNode(tGT, $1, $3); areIntRealOrStr($1->info, $3->info); $$->info = vint;}
			| expressao GE expressao    { $$ = binNode(GE, $1, $3); areIntRealOrStr($1->info, $3->info); $$->info = vint;}
			| expressao LE expressao    { $$ = binNode(LE, $1, $3); areIntRealOrStr($1->info, $3->info); $$->info = vint;}	
			| expressao '=' expressao   { $$ = binNode(tEQ, $1, $3); areIntRealOrStr($1->info, $3->info); $$->info = vint;}	
			| expressao NE expressao	{ $$ = binNode(NE, $1, $3); areIntRealOrStr($1->info, $3->info); $$->info = vint;}	
    		| expressao '&' expressao	{ $$ = binNode(tAND, $1, $3); areInt($1->info, $3->info);}	
    		| expressao '|' expressao	{ $$ = binNode(tOR, $1, $3); areInt($1->info, $3->info);}	
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

void areIntOrReal(int first, int second) {
	if (!(first == vint + vconst || first == vreal + vconst || second == vint + vconst || second == vreal+ vconst || first == vint || first == vreal || second == vint || second == vreal))
			yyerror("Invalid operation");

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

