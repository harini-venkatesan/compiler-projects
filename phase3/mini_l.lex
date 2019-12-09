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


"function"     {currpos += yyleng; return FUNCTION; }
"beginparams"  {currpos += yyleng; return BEGIN_PARAMS;}
"endparams"    {currpos += yyleng; return END_PARAMS;}
"beginlocals"  {currpos += yyleng; return BEGIN_LOCALS;}
"endlocals"    {currpos += yyleng; return END_LOCALS;}
"beginbody"    {currpos += yyleng; return BEGIN_BODY;}
"endbody"      {currpos += yyleng; return END_BODY;}
"integer"      {currpos += yyleng; return INTEGER;}
"array"        {currpos += yyleng; return ARRAY;}
"of"           {currpos += yyleng; return OF;}
"if"           {currpos += yyleng; return IF;}
"then"         {currpos += yyleng; return THEN;}
"endif"        {currpos += yyleng; return ENDIF;}
"else"         {currpos += yyleng; return ELSE;}
"while"        {currpos += yyleng; return WHILE;}
"do"           {currpos += yyleng; return DO;}
"beginloop"    {currpos += yyleng; return BEGINLOOP;}
"endloop"      {currpos += yyleng; return ENDLOOP;}
"continue"     {currpos += yyleng; return CONTINUE;}
"read"         {currpos += yyleng; return READ;}
"write"        {currpos += yyleng; return WRITE;}
"and"          {currpos += yyleng; return AND;}
"or"           {currpos += yyleng; return OR;}
"not"          {currpos += yyleng; return NOT;}
"true"         {currpos += yyleng; return TRUE;}
"false"        {currpos += yyleng; return FALSE;}
"return"       {currpos += yyleng; return RETURN;}


"-"            {currpos += yyleng; return SUB; }
"+"            {currpos += yyleng;  return ADD;}
"*"            {currpos += yyleng; return MULT;}
"/"            {currpos += yyleng; return DIV;}
"%"            {currpos += yyleng; return MOD;}


"=="           {currpos += yyleng; return EQ; }
"<>"           {currpos += yyleng; return NEQ;}
"<"            {currpos += yyleng; return LT;}
">"            {currpos += yyleng; return GT;}
"<="           {currpos += yyleng; return LTE;}
">="           {currpos += yyleng; return GTE;}




";"	       {currpos += yyleng; return SEMICOLON;}
":"	       {currpos += yyleng; return COLON;}
","            {currpos += yyleng; return COMMA;}
"("            {currpos += yyleng;return L_PAREN; }
")"            {currpos += yyleng; return R_PAREN;}
"["	       {currpos += yyleng; return L_SQUARE_BRACKET;}
"]"	       {currpos += yyleng; return R_SQUARE_BRACKET;}
":="	       {currpos += yyleng; return ASSIGN;}

\n {currline++; currpos = 1;}

{LETTER}+|({LETTER}({LETTER}|{DIGIT}|"_")*({LETTER}|{DIGIT})) {currpos += yyleng; yylval.string = strdup(yytext); return IDENT;}

({DIGIT}+|"_"){LETTER}({LETTER}|{DIGIT})* {printf("Error at line %d, column %d: identifier \"%s\" must begin with a letter\n", currline, currpos, yytext); exit(0);}

{LETTER}({LETTER}|{DIGIT}|"_")*"_" {printf("Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currline, currpos, yytext); exit(0);}

##.*\n {currline++; currpos = 1;}

{DIGIT}+ {currpos += yyleng; yylval.ival = atof(yytext); return NUMBER;}

{WHITE} {currpos += yyleng;}

. {printf("error at line %d, column %d: unrecognized symbol \"%s\"\n" ,currline,currpos,yytext ); exit(0);}

%%

