%{
#include "y.tab.h"
#include "heading.h"
 int currline = 1, currpos = 1;
%}
FUNCTION "function"
BEGIN_PARAMS "beginparams"
END_PARAMS "endparams"
BEGIN_LOCALS "beginlocals"
END_LOCALS "endlocals"
BEGIN_BODY "beginbody"
END_BODY "endbody"
INTEGER "integer"
ARRAY "array"
OF "of"
IF "if"
THEN "then"
ENDIF "endif"
ELSE "else"
WHILE "while"
DO "do"
BEGINLOOP "beginloop"
ENDLOOP "endloop"
CONTINUE "continue"
READ "read"
WRITE "write"
AND "and"
OR "or"
NOT "not"
TRUE "true"
FALSE "false"
RETURN "return"
DIGIT [0-9]
LETTER [a-z]|[A-Z]
WHITE [ \t]
%%
{FUNCTION} {currpos += yyleng; return FUNCTION; }
{BEGIN_PARAMS} {currpos += yyleng; return BEGIN_PARAMS; }
{END_PARAMS} {currpos += yyleng; return END_PARAMS; }
{BEGIN_LOCALS} {currpos += yyleng; return BEGIN_LOCALS; }
{END_LOCALS} {currpos += yyleng; return END_LOCALS; }
{BEGIN_BODY} {currpos += yyleng; return BEGIN_BODY; }
{END_BODY} {currpos += yyleng; return END_BODY; }
{INTEGER} {currpos += yyleng; return INTEGER; }
{ARRAY} {currpos += yyleng; return ARRAY; }
{OF} {currpos += yyleng; return OF; }
{IF} {currpos += yyleng; return IF; }
{THEN} {currpos += yyleng; return THEN; }
{ENDIF} {currpos += yyleng; return ENDIF; }
{ELSE} {currpos += yyleng; return ELSE; }
{WHILE} {currpos += yyleng; return WHILE; }
{DO} {currpos += yyleng; return DO; }
{BEGINLOOP} {currpos += yyleng; return BEGINLOOP;}
{ENDLOOP} {currpos += yyleng; return ENDLOOP; }
{CONTINUE} {currpos += yyleng; return CONTINUE;}
{READ} {currpos += yyleng; return READ; }
{WRITE} {currpos += yyleng; return WRITE; }
{AND} {currpos += yyleng; return AND; }
{OR} {currpos += yyleng; return OR; } 
{NOT} {currpos += yyleng; return NOT; }
{TRUE} {currpos += yyleng; return TRUE;}
{FALSE} {currpos += yyleng; return FALSE;}
{RETURN} {currpos += yyleng; return RETURN;}
"-" {currpos += yyleng; return SUB;}
"+" {currpos += yyleng; return ADD;}
"*" {currpos += yyleng; return MULT;}
"/" {currpos += yyleng; return DIV;} 
"%" {currpos += yyleng; return MOD;}
"==" {currpos += yyleng; return EQ;} 
"<>" {currpos += yyleng; return NEQ;}
"<" {currpos += yyleng; return LT;}
">" {currpos += yyleng; return GT;}
"<=" {currpos += yyleng; return LTE;}
">=" {currpos += yyleng; return GTE;}
";" {currpos += yyleng; return SEMICOLON;}
":" {currpos += yyleng; return COLON;}
"," {currpos += yyleng; return COMMA;}
"(" {currpos += yyleng; return L_PAREN;}
")" {currpos += yyleng; return R_PAREN;}
"[" {currpos += yyleng; return L_SQUARE_BRACKET;}
"]" {currpos += yyleng; return R_SQUARE_BRACKET;}
":=" {currpos += yyleng; return ASSIGN;}
\n {currline++; currpos = 1;}
{LETTER}+|({LETTER}({LETTER}|{DIGIT}|"_")*({LETTER}|{DIGIT})) {currpos += yyleng; yylval.string = strdup(yytext); return IDENT;}
({DIGIT}+|"_"){LETTER}({LETTER}|{DIGIT})* {printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currline, currpos, yytext); exit(0);}
{LETTER}({LETTER}|{DIGIT}|"_")*"_" {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currline, currpos, yytext); exit(0);}
##.*\n {currline++; currpos = 1;}
{DIGIT}+ {currpos += yyleng; yylval.ival = atof(yytext); return NUMBER;}
{WHITE} {currpos += yyleng;}
. {printf("error at line %d, column %d: unrecognized symbol \"%s\"\n" ,currline,currpos,yytext ); exit(0);}
%%

