%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <cstring>
 #include "heading.h"
 int yyerror(string s);
 int yylex(void);
%}

%union{
  string* dval;
  int ival;
}


%start prog_start

%token INTEGER ARRAY OF FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE TRUE FALSE
%token SEMICOLON COLON COMMA R_PAREN L_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET RETURN ASSIGN
%token <ival> NUMBER
%token <dval> IDENT
%left MULT DIV MOD ADD SUB AND OR LT GT LTE GTE EQ NEQ 
%right NOT ASSIGN 


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
		|statement SEMICOLON {printf("statements -> statement SEMICOLON\n");}
		;

statement:	st1 {printf("statement -> st1\n");}
		| st2 {printf("statement -> st2\n");}
		| st3 {printf("statement -> st3\n");} 
		| st4 {printf("statement -> st4\n");}
		| st5 {printf("statement -> st5\n");}
		| st6 {printf("statement -> st6\n");}
		| st7 {printf("statement -> st7\n");}
		| st8 {printf("statement -> st8\n");}
		;

st1:		var ASSIGN expression {printf("st1 -> var ASSIGN expression\n");}
		;

st2:		IF bool_exp THEN statements ENDIF {printf("st2 -> IF bool_exp THEN statements ENDIF\n");}
		| IF bool_exp THEN statements ELSE statements ENDIF {printf("st2 -> IF bool_exp THEN statements ELSE statements ENDIF\n");}
		;

st3:		 WHILE bool_exp BEGINLOOP statements ENDLOOP {printf("st3 -> WHILE bool_exp BEGINLOOP statements ENDLOOP\n");}
		;

st4:		DO BEGINLOOP statements ENDLOOP WHILE bool_exp {printf("st4 -> DO BEGINLOOP statements ENDLOOP WHILE bool_exp\n");}
		;

st5:		READ  var svar {printf("st5 -> READ vars\n");}
		;

st6:		WRITE var svar {printf("st6 -> WRITE vars\n");}
		;

st7:		CONTINUE {printf("st7 -> CONTINUE\n");}
		;

st8:		RETURN expression {printf("st8 -> RETURN expression\n");}
		;

svar:		{printf("svar -> epsilon\n");}
		| COMMA var svar {printf("svar -> COMMA var svar\n");}
		;

bool_exp:	relation_and_exp {printf("bool_exp -> relation_and_exp\n");}
		| relation_and_exp OR relation_and_exp {printf("bool_exp -> relation_and_exp OR relation_and_exp\n");}
		;

relation_and_exp: relation_exp {printf("relation_and_exp -> relation_exp\n");}
		  | relation_and_exp AND relation_exp {printf("relation_exp -> relation_exp AND relation_exp\n");}
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

expression:	multiplicative_expression expaddsub {printf("expression -> multiplicative_expression expaddsub\n");}
		;

expaddsub:	/*empty*/ {printf("expaddsub -> epsilon\n");}
		| ADD multiplicative_expression expaddsub {printf("expression -> ADD expaddsub\n");}
		| SUB multiplicative_expression expaddsub {printf("expression -> SUB expaddsub\n");}
		;

multiplicative_expression: term multi_term{printf("multiplicative_expression -> term multi_term\n");}
			   ;

multi_term:	/*empty*/ {printf("multi_term -> epsilon\n");}
		| MULT term  multi_term {printf("mutli_term -> MULT term\n");}
		| DIV term multi_term {printf("multi_term -> DIV term\n");}
		| MOD term multi_term {printf("mutli_term -> MOD term\n");}
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

var:		IDENT {printf("var -> ident\n");}
		| IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET {printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
		;

vars:		var {printf("vars -> var\n");}
		| var COMMA vars {printf("vars -> var COMMA vars\n");}
		;		
%%	

int yyerror(string s)
{
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  
  cerr << "ERROR: " << s << " at symbol \"" << yytext;
  cerr << "\" on line " << yylineno << endl;
  exit(1);
}	
