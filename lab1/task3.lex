%{
	int currLine = 1, currPos = 1, numOp = 0, numInt = 0, numPar = 0, numEq = 0;
%}

DIGIT    [0-9]

%%

"-"            {printf("MINUS\n"); currPos += yyleng; numOp++; }
"+"            {printf("PLUS\n"); currPos += yyleng; numOp++; }
"*"            {printf("MULT\n"); currPos += yyleng; numOp++; }
"/"            {printf("DIV\n"); currPos += yyleng; numOp++;  }
"="            {printf("EQUAL\n"); currPos += yyleng; numEq++; }
"("            {printf("L_PAREN\n"); currPos += yyleng; numPar++; }
")"            {printf("R_PAREN\n"); currPos += yyleng; numPar++; }

{DIGIT}+       {printf("NUMBER %s\n", yytext); currPos += yyleng; numInt++; }

[ \t]+         {/* ignore spaces */ currPos += yyleng;}

"\n"           {currLine++; currPos = 1;}

.              {printf("Error at line %d, column %d: unrecognized symbol \"%s\"\n", currLine, currPos, yytext); exit(0);}

%%

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


  printf("Number of Intergers: %d \n", numInt);
  printf("Number of Operators: %d \n", numOp);
  printf("Number of Paranthesis: %d \n", numPar);
  printf("Number of Equal: %d \n", numEq);


}

