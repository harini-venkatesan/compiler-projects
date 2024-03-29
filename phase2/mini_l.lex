/* Harini Venkatesan - phase 1 */

%{
	
	#include "heading.h"
        #include "tok.h"
	int yyerror(char *s);
        int currPos = 1, currLine = 1;
			
%}

DIGIT    [0-9]
   
%%


"function"     {currPos += yyleng; return FUNCTION; }
"beginparams"  {currPos += yyleng; return BEGIN_PARAMS;}
"endparams"    {currPos += yyleng; return END_PARAMS;}
"beginlocals"  {currPos += yyleng; return BEGIN_LOCALS;}
"endlocals"    {currPos += yyleng; return END_LOCALS;}
"beginbody"    {currPos += yyleng; return BEGIN_BODY;}
"endbody"      {currPos += yyleng; return END_BODY;}
"integer"      {currPos += yyleng; return INTEGER;}
"array"        {currPos += yyleng; return ARRAY;}
"of"           {currPos += yyleng; return OF;}
"if"           {currPos += yyleng; return IF;}
"then"         {currPos += yyleng; return THEN;}
"endif"        {currPos += yyleng; return ENDIF;}
"else"         {currPos += yyleng; return ELSE;}
"while"        {currPos += yyleng; return WHILE;}
"do"           {currPos += yyleng; return DO;}
"beginloop"    {currPos += yyleng; return BEGINLOOP;}
"endloop"      {currPos += yyleng; return ENDLOOP;}
"continue"     {currPos += yyleng; return CONTINUE;}
"read"         {currPos += yyleng; return READ;}
"write"        {currPos += yyleng; return WRITE;}
"and"          {currPos += yyleng; return AND;}
"or"           {currPos += yyleng; return OR;}
"not"          {currPos += yyleng; return NOT;}
"true"         {currPos += yyleng; return TRUE;}
"false"        {currPos += yyleng; return FALSE;}
"return"       {currPos += yyleng; return RETURN;}


"-"            {currPos += yyleng; return SUB; }
"+"            {currPos += yyleng;  return ADD;}
"*"            {currPos += yyleng; return MULT;}
"/"            {currPos += yyleng; return DIV;}
"%"            {currPos += yyleng; return MOD;}


"=="           {currPos += yyleng; return EQ; }
"<>"           {currPos += yyleng; return NEQ;}
"<"            {currPos += yyleng; return LT;}
">"            {currPos += yyleng; return GT;}
"<="           {currPos += yyleng; return LTE;}
">="           {currPos += yyleng; return GTE;}

{DIGIT}+       {currPos += yyleng; return NUMBER; }

[a-zA-Z][a-zA-Z0-9]*                 {currPos += yyleng; return IDENT;} /*Make sure it does not start with a digit or an underscore*/

[a-zA-Z][a-zA-Z0-9_]*[a-zA-Z0-9]  {currPos += yyleng; return IDENT;} /*Identifiers with underscore in the middle*/ 


";"	       {currPos += yyleng; return SEMICOLON;}
":"	       {currPos += yyleng; return COLON;}
","            {currPos += yyleng; return COMMA;}
"("            {currPos += yyleng;return L_PAREN; }
")"            {currPos += yyleng; return R_PAREN;}
"["	       {currPos += yyleng; return L_SQUARE_BRACKET;}
"]"	       {currPos += yyleng; return R_SQUARE_BRACKET;}
":="	       {currPos += yyleng; return ASSIGN;}

[#].*	       {currLine++; currPos = 1;}   /*Comments are avoided*/

[ ]            {currPos += yyleng;}        /*Spaces are avoided*/

[ \t]+         {currPos += yyleng;}	 

"\n"           {yylineno++, currLine++; currPos = 1;} /*Move to a new line */


[0-9_][a-zA-Z0-9_]*[a-zA-Z0-9_]      {printf("LEXER Error at line %d, column %d: identifier \"%s\" must begin with a letter\n",currLine,currPos,yytext); currPos += yyleng; exit(0);} /* If it begins with an underscore or a number*/

[a-zA-Z][a-zA-Z0-9_]*[_]                {printf("LEXER Error at line %d, column %d: identifier \"%s\" cannot end with an underscore\n", currLine, currPos, yytext); currPos+= yyleng; exit(0);} /* If it ends with an underscore */

.              {printf("LEXER Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext); exit(0);}

%%

/*
int main(int argc, char ** argv)
{
   if(argc >= 2)
   {
      yyin = fopen(argv[1], "r");
      if(yyin == NULL)
      {
         yyin = stdin;
      }
   }
   else
   {
      yyin = stdin;
   }
   yylex();




}

*/

