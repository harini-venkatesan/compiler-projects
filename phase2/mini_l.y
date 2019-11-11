%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <cstring>
 #include "heading.h"
 void yyerror(const char* s);
 int yylex(void);
%}

%union{
  char* dval;
  int ival;
}


%start prog_start

%token INTEGER ARRAY OF FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE TRUE FALSE
%token SEMICOLON COLON COMMA R_PAREN L_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET RETURN ASSIGN
%token <ival> NUMBER
%token <dval> IDENT
%left MULT DIV MOD ADD SUB AND OR LT GT LTE GTE EQ NEQ ASSIGN
%right NOT  


%%

prog_start:	function {printf("prog_start -> functions\n");}
		;


functions:	function functions {printf("functions -> function functions\n");}
		| {printf("function -> epsilon\n");}
		;

function:	FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY {printf("FUNCTION INDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY\n");}
		;

declarations:	declaration SEMICOLON declarations {printf("declrations -> decleration SEMICOLON decleration\n");}
		| {printf("declarations -> epsilon\n");}
		;

declaration:	identifiers COLON assign {printf("declaration -> identifiers COLON assign\n");}
		;

identifiers:	ident {printf("identifiers -> ident\n");}
		| IDENT COMMA identifiers {printf("identifiers -> ident COMMA identifiers\n");}
		;

ident:		IDENT {printf("ident -> IDENT\n");}
		;

assign:		INTEGER {printf("assign -> INTEGER\n");}
		|ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {printf("assign -> COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
		;

statements:	statement SEMICOLON statements {printf("statements -> statement SEMICOLON statements\n");}
		| {printf("statements -> epsilon\n");}
		;

statement:	var ASSIGN expression {printf("statement -> var ASSIGN expression\n");}
		| IF bool_exp THEN statements ENDIF {printf("statement -> IF bool_exp THEN statements ENDIF\n");}
		| IF bool_exp THEN statements ELSE statements ENDIF {printf("statement -> IF bool_exp THEN statements ELSE statements ENDIF\n");}
		| WHILE bool_exp BEGINLOOP statements ENDLOOP {printf("statement -> WHILE bool_exp BEGINLOOP statements ENDLOOP\n");}
		| DO BEGINLOOP statements ENDLOOP WHILE bool_exp {printf("statement -> DO BEGINLOOP statements ENDLOOP WHILE bool_exp\n");}
		| READ vars {printf("statement -> READ vars\n");}
		| WRITE vars {printf("statement -> WRITE vars\n");}
		| CONTINUE {printf("statement -> CONTINUE\n");}
		| RETURN expression {printf("statement -> RETURN expression\n");}
		;

bool_exp:	relation_and_exp {printf("bool_exp -> relation_and_exp\n");}
		| relation_and_exp OR relation_and_exp {printf("bool_exp -> relation_and_exp OR relation_and_exp\n");}
		;

relation_and_exp: relation_exp {printf("relation_and_exp -> relation_exp\n");}
		  | relation_exp AND relation_exp {printf("relation_and__exp -> relation_exp AND relation_exp\n");}
		  ;

relation_exp:	rexp {printf("relation_exp -> rexp");}
		| NOT rexp {printf("relation_exp -> NOT rexp");}
		;

rexp:		expression comp expression {printf("rexp -> expression comp expression\n");}
		| TRUE {printf("rexp -> TRUE\n");}
		| FALSE {printf("rexp -> FALSE\n");}
		| L_PAREN bool_exp R_PAREN {printf("rexp -> L_PAREN bool_exp R_PAREN\n");}
		;
 
comp:		EQ {printf("comp -> EQ\n");}
		| NEQ {printf("comp -> NEQ\n");}
		| LT {printf("comp -> LT\n");}
		| GT {printf("comp -> GT\n");}
		| LTE {printf("comp -> LTE\n");}
		| GTE {printf("comp -> GTE\n");}
		;

expression:	multiplicative_expression {printf("expression -> multiplicative_expression\n");}
		| multiplicative_expression ADD multiplicative_expression {printf("expression -> multiplicative_expression ADD multiplicative_expression\n");}
		| multiplicative_expression SUB multiplicative_expression {printf("expression -> multiplicative_expression SUB multiplicative_expression\n");}
		;

multiplicative_expression: term multi_term{printf("multiplicative_expression -> term multi_term\n");}
			   ;

multi_term:	/*empty*/ {printf("multi_term -> epsilon\n");}
		| MULT multi_term {printf("mutli_term -> MULT term\n");}
		| DIV multi_term {printf("multi_term -> DIV term\n");}
		| MOD multi_term {printf("mutli_term -> MOD term\n");}
		;

term:		var {printf("term -> var\n");}
		| SUB var {printf("term -> SUB var\n");}
		| NUMBER {printf("term -> NUMBER\n");}
		| SUB NUMBER {printf("term -> SUB NUMBER\n");}
		| L_PAREN expression R_PAREN {printf("term -> L_PAREN expression R_PAREN\n");}
		| SUB L_PAREN expression R_PAREN {printf("term -> SUB L_PAREN expression R_PAREN\n");}
		| ident ident_term {printf("term -> ident ident_term\n ");} 
		;		

ident_term:	L_PAREN expr_term R_PAREN {printf("ident_term -> L_PAREN expr_term R_PAREN");}
		| L_PAREN R_PAREN {printf("ident_term -> L_PAREN R_PAREN");}
		;

expr_term:	expression {printf("expr_term -> expression\n");}
		| expression COMMA expr_term {printf("expr_term -> expression COMMA expr_term\n");}
		;	

var:		ident {printf("var -> ident\n");}
		| ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET {printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
		;

vars:		var {printf("vars -> var\n");}
		| var COMMA vars {printf("vars -> var COMMA vars\n");}
				
%%	

void yyerror(const char* s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << yylineno << endl;
  exit(1);
}

	
