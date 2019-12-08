%{
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
 #include <vector>
 #include <string>
 #include <sstream>
 #include <iostream>
 using namespace std;
 
 int yylex(void);
 void yyerror(const char *msg);
 extern int curline;
 extern int curpos;
 extern FILE * yyin;

  
 vector<string> symTable; // symbols
 vector<string> symTableType;
 vector<string> paramTable; // parameters
 vector<string> opTable; // operators
 vector<string> opTableType;
 vector<string> toPrint; 
 vector<string> toPrintAll;
 vector<string> functions;
 vector<vector<string> > ifLabel;
 vector<vector<string> > LoopLabel;
 int labelCount = 0;
 int varCount = 0;
 int tempCount = 0;
 int paramCount = 0;


 bool isParam;
 bool isMain;
 bool isError;
 unsigned index(string s){
 	for (unsigned i = 0; i < symTable.size(); i++){
		if(symTable[i] == s){
			return i;
		}
	}
	for (unsigned i = 0; i < paramTable.size(); i++){
		if (paramTable[i] == s){
			return i;
		}
	}
	for (unsigned i = 0; i < functions.size(); i++){
		if(functions[i] == s){
			return i;
		}
	}
 }

 bool identiferUsed (string s) {
	for (unsigned i = 0; i < symTable.size(); i++) {
		if (symTable[i] == s) {
			return true;
		}
	}
	for (unsigned i = 0; i < paramTable.size(); i++) {
		if (paramTable[i] == s) {
			return true;
		}
	}
	for (unsigned i = 0; i < functions.size(); i++) {
		if (functions[i] == s) {
			return true;
		}
	}
	return false;
 }

%}


%error-verbose
%start prog_start
%token FUNCTION BEGIN_PARAMS END_PARAMS BEGIN_LOCALS END_LOCALS BEGIN_BODY END_BODY
%token INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO BEGINLOOP ENDLOOP CONTINUE READ WRITE
%token AND OR NOT TRUE FALSE RETURN SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE
%token SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN
%token <ival> NUMBER
%token <string> IDENT
%left MULT DIV MOD
%left ADD SUB
%left EQ NEQ LT GT LTE GTE
%right NOT
%left AND
%left OR
%right ASSIGN
%nonassoc UMINUS


%union{
  int ival;
  char *string;
  double dval;
}

%%
prog_start:
			functions
			;

functions:
			function functions 
			| /* epsilon */
			;
function:
			FUNCTION IDENT {functions.push_back($2);} SEMICOLON BEGIN_PARAMS {isParam = true;} declarations END_PARAMS printParams BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY 	
			{
				toPrintAll.push_back(string("func ") + functions.back());
				// symbol Table
				for(unsigned i = 0; i < symTable.size(); i++) {
					if(symTableType[i] == "INTEGER") {
						toPrintAll.push_back(". " + symTable[i]);
					}
					else {
						toPrintAll.push_back(".[] " + symTable[i] + ", " + symTableType[i]);
					}
				}

				toPrintAll.push_back(": START");

				
				for(unsigned i = 0; i < toPrint.size(); i++) {
					toPrintAll.push_back(toPrint[i]);
				}

				//clear tables
				symTable.clear();
				symTableType.clear();
				opTable.clear();
				opTableType.clear();
				paramTable.clear();
				toPrint.clear();

				toPrintAll.push_back("endfunc");
			}
			;

printParams:
			{
				 while(!paramTable.empty()) {
				 	toPrint.push_back("= " + paramTable.back() + ", $" + to_string(paramCount)); 
				 	paramTable.pop_back(); 
				 	paramCount++;
				 } 
				 isParam = false;
			}
			;

declarations:
			declaration SEMICOLON declarations
			| /* epsilon */
			;
declaration: 
			identifiers COLON INTEGER {
				symTableType.push_back("INTEGER");
			}
			| identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
					if($5 == 0){
						printf("Error line %d: %d is not a valid array size\n", curline, $5);
					isError = true;					
					}
					symTableType.push_back(to_string($5));
			}
			| identifiers COLON ARRAY L_SQUARE_BRACKET SUB NUMBER R_SQUARE_BRACKET OF INTEGER{
					printf("Error line %d: -%d is not a valid array size\n", curline, $6);
					isError = true;
			}
			;

identifiers:
			IDENT {
				if (identiferUsed($1)) {
					printf("Error Line %d: symbol %s is already defined \n", curline, $1);
					//yyerror("symbol %s is multiply-defined");
					isError = true;
				}
				if (isParam) {
					paramTable.push_back($1);
				}
				symTable.push_back($1);
			}
			| IDENT COMMA identifiers {
				if (identiferUsed($1)) {
					printf("Error Line %d: symbol %s is already defined \n",curline, $1);
					//yyerror("identifier has been declared!");
					isError = true;
				}
				symTable.push_back($1);
				symTableType.push_back("INTEGER");

			}
			;


statements:
			statement SEMICOLON statements 
			| /* epsilon */
			;
statement:
			assign
			| if_bool THEN statements ENDIF { 
				toPrint.push_back(": " + ifLabel.back()[1]);
				ifLabel.pop_back();
			}
			| if_bool THEN statements if_else ENDIF { 
				toPrint.push_back(": " + ifLabel.back()[2]);
				ifLabel.pop_back();
			}
			| while_bool statements ENDLOOP { 
				toPrint.push_back(":= " + LoopLabel.back()[1]);
				toPrint.push_back(": " + LoopLabel.back()[3]);
				LoopLabel.pop_back();
			}
			| do_loop WHILE bool_exp { // do loop
				toPrint.push_back("?:= " + LoopLabel.back()[1] + ", " + opTable.back());
					opTable.pop_back();
					opTableType.pop_back();
				LoopLabel.pop_back();
			}
			| READ readVars
			| WRITE writeVars
			| CONTINUE {
				if(!LoopLabel.empty()) {
					string loopType = LoopLabel.back()[0];
					if (loopType == "while") {
						toPrint.push_back(":= " + LoopLabel.back()[1]);
					}
					else { 
						toPrint.push_back(":= " + LoopLabel.back()[2]);
					}
				}
				if (LoopLabel.empty()){
					printf("Error line %d: continue statement not within a loop\n", curline);
					isError = true;
				}
			}
			| RETURN expression {
				toPrint.push_back("ret " + opTable.back());
					opTable.pop_back();
					opTableType.pop_back();
			}
			;

assign:
			assignVar ASSIGN expression {
				string op2 = opTable.back();
				opTable.pop_back();
				opTableType.pop_back();

				string op1 = opTable.back();
				opTable.pop_back();
				string op1type = opTableType.back();
				opTableType.pop_back();
				if (op1type == "INTEGER") {
					toPrint.push_back("= " + op1 + ", " + op2);
				}
				else {
					toPrint.push_back("[]= " + op1 + ", " + op2);
				}
			}
			;

assignVar:
			IDENT {
				if (!identiferUsed($1)) {
					printf("Error line %d: used variable %s was not previously declared\n", curline, $1);
					isError = true;
				}
				unsigned tmp = index($1);
				if(symTableType[tmp] != "INTEGER"){
					printf("Error line %d: used int variable %s does not have an index\n", curline, $1);
					isError = true;
				}
				string temp = $1;
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			| IDENT L_SQUARE_BRACKET expressions R_SQUARE_BRACKET {
				if (!identiferUsed($1)) {
					printf("Error line %d: used variable %s was not previously declared\n", curline, $1);
					isError = true;
				}
				unsigned tmp = index($1);
				if(symTableType[tmp] == "INTEGER"){
					printf("using an integer as an array is dumb\n");
				}
				string temp = $1;
				string size = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				string id = temp + ", " + size;
				opTable.push_back(id);
				opTableType.push_back("ARRAY");
			} 
			;

if_bool:
			IF bool_exp {
				vector<string> temp;
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				ifLabel.push_back(temp);
				toPrint.push_back("?:= " + ifLabel.back()[0] + ", " + opTable.back()); 
					opTable.pop_back();
					opTableType.pop_back();
				toPrint.push_back(":= " + ifLabel.back()[1]);
				toPrint.push_back(": " + ifLabel.back()[0]);
			}
			;

if_else:
			ELSE statements {
				toPrint.push_back(":= " + ifLabel.back()[2]);
				toPrint.push_back(": " + ifLabel.back()[1]);
			}
			;

while_bool:
			while bool_exp BEGINLOOP {
				toPrint.push_back("?:= " + LoopLabel.back()[2] + ", " +opTable.back());
					opTable.pop_back();
					opTableType.pop_back();
				toPrint.push_back(":= " + LoopLabel.back()[3]);
				toPrint.push_back(": " + LoopLabel.back()[2]);
			}
			;

while:
			WHILE {
				vector<string> temp;
				temp.push_back("while");
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				LoopLabel.push_back(temp);
				toPrint.push_back(": " + LoopLabel.back().at(1));
			}
			;

do_loop:
			do statements ENDLOOP {
				toPrint.push_back(": " + LoopLabel.back()[2]);
			}
			;

do:
			DO BEGINLOOP {
				vector<string> temp;
				temp.push_back("do_while");
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				LoopLabel.push_back(temp);
				toPrint.push_back(": " + LoopLabel.back()[1]);
			}
			;

readVars:
			var {
				string op1 = opTable.back();
				string op1type = opTableType.back();
				opTable.pop_back();
				opTableType.pop_back();
				if (op1type == "INTEGER") {
					toPrint.push_back(".< " + op1);
				}
				else {
					toPrint.push_back(".[]< " + op1);
				}
			}
			| var COMMA readVars { //same as above var
				string op1 = opTable.back();
				string op1type = opTableType.back();
				opTable.pop_back();
				opTableType.pop_back();
				if (op1type == "INTEGER") {
					toPrint.push_back(".< " + op1);
				}
				else {
					toPrint.push_back(".[]< " + op1);
				}
			}
			;

writeVars: //same as above readVars
			var {
				string op1 = opTable.back();
				string op1type = opTableType.back();
				opTable.pop_back();
				opTableType.pop_back();
				if (op1type == "INTEGER") {
					toPrint.push_back(".> " + op1);
				}
				else {
					toPrint.push_back(".[]> " + op1);
				}
			}
			| var COMMA readVars { //same as above var
				string op1 = opTable.back();
				string op1type = opTableType.back();
				opTable.pop_back();
				opTableType.pop_back();
				if (op1type == "INTEGER") {
					toPrint.push_back(".> " + op1);
				}
				else {
					toPrint.push_back(".[]> " + op1);
				}
			}
			;

bool_exp:
			relation_and_exp 
			| relation_and_exp OR bool_exp {
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");

				string op2 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				toPrint.push_back("|| " + temp + ", " + op1 + ", " + op2);
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			;
relation_and_exp:
			relation_exp 
			| relation_exp AND relation_and_exp {
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");

				string op2 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				
				toPrint.push_back("&& " + temp + ", " + op1 + ", " + op2);
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			} 
			;
relation_exp: 
			relation_exp1 
			| NOT relation_exp1 {
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");

				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				
				toPrint.push_back("! " + temp + ", " + op1);
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			;
relation_exp1:
			expression comp expression {
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");

				string op2 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				string comp = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				
				toPrint.push_back(comp + " " + temp + ", " + op1 + ", " + op2);
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			| TRUE {
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");
				
				toPrint.push_back("= " + temp + ", 1");
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			| FALSE {
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");
				
				toPrint.push_back("= " + temp + ", 0");
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			| L_PAREN bool_exp R_PAREN 
			;

comp:
			EQ {
				opTable.push_back("==");
				opTableType.push_back("null");
			}
			| NEQ {
				opTable.push_back("!=");
				opTableType.push_back("null");
			}
			| LT {
				opTable.push_back("<");
				opTableType.push_back("null");
			} 
			| GT {
				opTable.push_back(">");
				opTableType.push_back("null");
			}
			| LTE {
				opTable.push_back("<=");
				opTableType.push_back("null");
			}
			| GTE {
				opTable.push_back(">=");
				opTableType.push_back("null");
			}
			;

expressions:
			expression 
			| expression COMMA expression 
			;
			
expression:
			mult_expression 
			| mult_expression ADD expression { 
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");
				string op2 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				
				toPrint.push_back("+ " + temp + ", " + op1 + ", " + op2);
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			| mult_expression SUB expression {
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");
				string op2 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				
				toPrint.push_back("- " + temp + ", " + op1 + ", " + op2);
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			;

mult_expression:	
			term
			| term MULT mult_expression {
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");
				string op2 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				
				toPrint.push_back("* " + temp + ", " + op1 + ", " + op2);
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			| term DIV mult_expression {
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");
				string op2 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				
				toPrint.push_back("/ " + temp + ", " + op1 + ", " + op2);
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			| term MOD mult_expression {
				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");
				string op2 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				
				toPrint.push_back("% " + temp + ", " + op1 + ", " + op2);
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			;

term:
			var 
			| NUMBER {
				opTable.push_back(to_string($1));
				opTableType.push_back("INTEGER");
			}
			| SUB NUMBER {
				opTable.push_back(to_string($2*-1));
				opTableType.push_back("INTEGER");
			}
			| L_PAREN expression R_PAREN 
			| SUB L_PAREN expression R_PAREN {
				string temp = "_t"+to_string(tempCount++);
				
				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();
				
				toPrint.push_back("- " + temp + ", 0, " + op1);
				
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			| IDENT L_PAREN expressions R_PAREN { //call a function
				// check if the funciton $1 has been defined
				bool findFunction = false;
				for (unsigned i = 0; i < functions.size(); i++) {
					if (functions[i] == $1) {
						findFunction = true;
						break;
					}
				}
				if (!findFunction) {
					printf("Error line %d: Function %s not defined\n", curline,$1 );
					isError = true;
				}

				string temp = "_t"+to_string(tempCount++);
					symTable.push_back(temp);
					symTableType.push_back("INTEGER");

				string op1 = opTable.back();
					opTable.pop_back();
					opTableType.pop_back();

				toPrint.push_back("param " + op1);
				toPrint.push_back(string("call ") + $1 + ", " + temp);

				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			;

var: 
			IDENT {
				if (!identiferUsed($1)) {
					printf("Error line %d: used variable %s was not previously defined\n", curline, $1);
					//yyerror("variable not defined.");
					isError = true;
				}
				unsigned tmp = index($1);
				if(symTableType[tmp] != "INTEGER"){
					printf("Error line %d: used array variable \"%s\" is missing a specified index\n", curline, $1);
					isError = true;
				}
				string temp = $1;
				opTable.push_back(temp);
				opTableType.push_back("INTEGER");
			}
			| IDENT L_SQUARE_BRACKET expressions R_SQUARE_BRACKET {
				if (!identiferUsed($1)) {
					printf("Error line %d: used variable %s was not previously defined\n", curline, $1);
					//yyerror("variable not defined.");
					isError = true;
				}
				unsigned tmp = index($1);
				if(symTableType[tmp] == "INTEGER"){
					printf("Error line %d: used integer variable \"%s\" does not have an index\n",curline, $1);
					isError = true;
				}
				string temp = "_t"+to_string(tempCount++);
				symTable.push_back(temp);
				symTableType.push_back("INTEGER");

				string arraySize = opTable.back();
				opTable.pop_back();
				opTableType.pop_back();
				opTable.push_back(temp);
				opTableType.push_back("ARRAY");
				toPrint.push_back("=[] "+ temp + ", " + $1 + ", " + arraySize);
			} 
			;

%%


int main(int argc, char **argv) {
	if (argc > 1) {
		yyin = fopen(argv[1], "r");
		if (yyin == NULL) {
			printf("syntax: %s filename\n", argv[0]);
		}
	}
	yyparse();
	for(unsigned i = 0; i < functions.size(); i++) {
		if (functions[i] == "main") {
			isMain = true;
			break;
		}
	}

	if (!isMain) {
		printf("Error: No main function defined\n");
		return -1;
	}
	if (isError) {
		printf("Error\n");
		return -1;
	}

	for(unsigned i = 0; i < toPrintAll.size(); i++) {
		cout << toPrintAll[i] <<endl;
	}

	return 0;
}

void yyerror(const char *msg) {
	printf("** Line %d, position %d: %s\n", curline, curpos, msg);
}

