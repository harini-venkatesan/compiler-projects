%{
// #include "heading.h"
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <assert.h>
 #include <vector>
 #include <cstring>
 #include <sstream>
 #include <iostream>
 
 using namespace std;
 
 int yylex(void);
 void yyerror(const char *msg);
 extern int currline;
 extern int currpos;
 extern FILE * yyin;

/*
    template <typename T>
    std::string to_string(T value)
    {
      //create an output string stream
      std::ostringstream os ;

      //throw the value into the string stream
      os << value ;

      //convert the string stream into a string and return
      return os.str() ;
    }
 
 */

 vector<string> symbol_table; // table for symbols
 vector<string> symbol_table_type; // table for symbol types
 vector<string> param_table; // parameter table
 vector<string> ops_table; // operators table
 vector<string> ops_table_type; // operators type table

 vector<string> statements;  
 vector<string> statements_all;
 vector<string> functions;

 vector<vector<string> > if_label;
 vector<vector<string> > LoopLabel;
 int labelCount = 0;
 int varCount = 0;
 int tempCount = 0;
 int paramCount = 0;


 bool isParam;
 bool isMain;
 bool isError;
 unsigned index_return(string s){
 	for (unsigned i = 0; i < symbol_table.size(); i++){
		if(symbol_table[i] == s){
			return i;
		}
	}
	for (unsigned i = 0; i < param_table.size(); i++){
		if (param_table[i] == s){
			return i;
		}
	}
	for (unsigned i = 0; i < functions.size(); i++){
		if(functions[i] == s){
			return i;
		}
	}
 }

 bool identifer_used (string s) {
	for (unsigned i = 0; i < symbol_table.size(); i++) {
		if (symbol_table[i] == s) {
			return true;
		}
	}
	for (unsigned i = 0; i < param_table.size(); i++) {
		if (param_table[i] == s) {
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
prog_start: functions
			;

functions: function functions 
			| /* */
			;

function_ident: FUNCTION IDENT 
				{
					functions.push_back($2);
					statements_all.push_back(string("func ") + functions.back());
				}
				;

begin_params: BEGIN_PARAMS {isParam = true; }
			  ;

end_params: END_PARAMS {isParam = false; }
			;

function: function_ident SEMICOLON begin_params declarations end_params print_params BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY 	
			{
				
				
				for(unsigned i = 0; i < symbol_table.size(); i++) {
					if(symbol_table_type[i] == "INTEGER") {
						statements_all.push_back(". " + symbol_table[i]);
					}
					else {
						statements_all.push_back(".[] " + symbol_table[i] + ", " + symbol_table_type[i]);
					}
				}
				
				statements_all.push_back(": START");
				 

				
				for(unsigned i = 0; i < statements.size(); i++) {
					statements_all.push_back(statements[i]);
				}

				
				symbol_table.clear();
				symbol_table_type.clear();
				ops_table.clear();
				ops_table_type.clear();
				param_table.clear();
				statements.clear();
				paramCount = 0; 

				statements_all.push_back("endfunc");
			}
			;

print_params:	{
			 while(!param_table.empty()) {
			 	statements.push_back("= " + param_table.back() + ", $" + to_string(paramCount)); 
			 	param_table.pop_back(); 
			 	paramCount++;
			 } 
			 isParam = false;
		}
			;

declarations: declaration SEMICOLON declarations
			| /*  */
			;

declaration: identifiers COLON assign_dec 

assign_dec:	INTEGER 
			{
				symbol_table_type.push_back("INTEGER");
			}
			| ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER {
					if($3 == 0){
						printf("Error line %d: %d is not a valid array size\n", currline, $3);
						isError = true;					
					}
					else {
						symbol_table_type.push_back(to_string($3));
						}
			}
			| ARRAY L_SQUARE_BRACKET SUB NUMBER R_SQUARE_BRACKET OF INTEGER{
					printf("Error line %d: -%d is not a valid array size\n", currline, $4);
					isError = true;
			}
			;

identifiers:  IDENT {
				if (identifer_used($1)) {
					printf("Error Line %d: symbol %s is already defined \n", currline, $1);
					//yyerror("symbol %s is multiply-defined");
					isError = true;
				}
				if (isParam) {
					param_table.push_back($1);
				}
				symbol_table.push_back($1);

			
				//symbol_table.push_back($1);
			}

			| IDENT COMMA identifiers {
				
				 if (identifer_used($1)) {
                                        printf("Error Line %d: symbol %s is already defined \n", currline, $1);
                                        //yyerror("symbol %s is multiply-defined");
                                        isError = true;
                                }


				symbol_table.push_back($1);
				symbol_table_type.push_back("INTEGER");

			}
			;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

statements: statement SEMICOLON statements 
			| statement SEMICOLON
			;

statement:	st1 
			| st2 
			| st3 
			| st4 
			| st5 
			| st6 
			| st7 
			| st8 
			| st9
			;

st1:	assign_variable ASSIGN expression {
				string op2 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();

				string op = ops_table.back();
				ops_table.pop_back();
				string optype = ops_table_type.back();
				ops_table_type.pop_back();
				if (optype == "INTEGER") {
					statements.push_back("= " + op + ", " + op2);
				}
				else {
					statements.push_back("[]= " + op + ", " + op2);
				}
			}
		;

assign_variable:
			
			IDENT { 
				
				if (!identifer_used($1)) {
					printf("Error line %d: used variable %s was not previously declared\n", currline, $1);
					isError = true;
				}
				unsigned tmp = index_return($1);

				
				//unsigned tmp = index($1);
				if(symbol_table_type[tmp] != "INTEGER"){
					printf("Error line %d: used int variable %s does not have an index\n", currline, $1);
					isError = true;
				}
				string temp_index = $1;
				ops_table.push_back(temp_index);
				ops_table_type.push_back("INTEGER");
			}

			| IDENT L_SQUARE_BRACKET expressions R_SQUARE_BRACKET 
				{ if (!identifer_used($1)) {
					printf("Error line %d: used variable %s was not previously declared\n", currline, $1);
					isError = true;
				}
				unsigned tmp = index_return($1);
				
				//unsigned tmp = index($1);
				if(symbol_table_type[tmp] == "INTEGER"){
					printf("Error integer is used as an Array\n");
				}
				string temp = $1;
				string size = ops_table.back();
					ops_table.pop_back();
					ops_table_type.pop_back();
				string id = temp + ", " + size;
				ops_table.push_back(id);
				ops_table_type.push_back("ARRAY");
			} 
			;

st2:	 if_bool THEN statements ENDIF { 
				statements.push_back(": " + if_label.back()[1]);
				if_label.pop_back();
			}
		;


st3:	 if_bool THEN statements if_else ENDIF { 
				statements.push_back(": " + if_label.back()[2]);
				if_label.pop_back();
			}
		;

if_bool:  IF bool_exp {		/* ?= test_codition_temp_variable, goto first_label
               		          =:second_label
              			  :first_label
             			   ## Statements
                		  :second_label
            			*/

				vector<string> temp;
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				if_label.push_back(temp);
				statements.push_back("?:= " + if_label.back()[0] + ", " + ops_table.back());
					//if condition evaluate then goto first_label
				ops_table.pop_back();
				ops_table_type.pop_back();
				statements.push_back(":= " + if_label.back()[1]); //goto second_label
				statements.push_back(": " + if_label.back()[0]);  //declaration first_laebl
			}
			;

if_else:  ELSE statements {
				statements.push_back(":= " + if_label.back()[2]);  
				statements.push_back(": " + if_label.back()[1]);
			}
			;

st4:	 while_bool statements ENDLOOP { 
				statements.push_back(":= " + LoopLabel.back()[1]);
				statements.push_back(": " + LoopLabel.back()[3]);
				LoopLabel.pop_back();
			}
		;

st5:	 do_loop WHILE bool_exp { 
				statements.push_back("?:= " + LoopLabel.back()[1] + ", " + ops_table.back());
				
				ops_table.pop_back();
				ops_table_type.pop_back();
				LoopLabel.pop_back();
			}
	;



while_bool:  while bool_exp BEGINLOOP {
				statements.push_back("?:= " + LoopLabel.back()[2] + ", " +ops_table.back());
				ops_table.pop_back();
				ops_table_type.pop_back();
				statements.push_back(":= " + LoopLabel.back()[3]);
				statements.push_back(": " + LoopLabel.back()[2]);
		}
            ;

while:   WHILE {		/* :while_loop_[NUM]
		       		 //conditional statements
		        	?= test_codition_temp_variable, conditonal_true_[NUM]
		        	=:conditional_false_[NUM]
		        	:conditional_true_[NUM]
		        	## Statements
		        	=: while_loop_[NUM]
		        	:conditional_false[NUM]
		    		*/

				vector<string> temp;
				temp.push_back("while");
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				LoopLabel.push_back(temp);
				statements.push_back(": " + LoopLabel.back().at(1));
		}
	;

do_loop:   do statements ENDLOOP {
				statements.push_back(": " + LoopLabel.back()[2]);
		}
	;

do:	DO BEGINLOOP {		 /* :do_while_loop_[NUM]
				=:conditional_false_[NUM]
				:conditional_true_[NUM]
				## Statements
				?= test_codition_temp_variable, conditonal_true_[NUM]
			  	  */

				vector<string> temp;
				temp.push_back("do_while");
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				LoopLabel.push_back(temp);
				statements.push_back(": " + LoopLabel.back()[1]);
		}
	;

		
st6:	READ readVars
	;

st7:	WRITE writeVars
	;


readVars:	var {
				string op1 = ops_table.back();
				string op1type = ops_table_type.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				if (op1type == "INTEGER") {
					statements.push_back(".< " + op1);
				}
				else {
					statements.push_back(".[]< " + op1);
				}
			}
		
		| var COMMA readVars { 
				string op1 = ops_table.back();
				string op1type = ops_table_type.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				if (op1type == "INTEGER") {
					statements.push_back(".< " + op1);
				}
				else {
					statements.push_back(".[]< " + op1);
				}
			}
		;

writeVars: 	var {
				string op1 = ops_table.back();
				string op1type = ops_table_type.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				if (op1type == "INTEGER") {
					statements.push_back(".> " + op1);
				}
				else {
					statements.push_back(".[]> " + op1);
				}
			}
		
		| var COMMA readVars { 
				string op1 = ops_table.back();
				string op1type = ops_table_type.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				if (op1type == "INTEGER") {
					statements.push_back(".> " + op1);
				}
				else {
					statements.push_back(".[]> " + op1);
				}
			}
		;


			
st8:	CONTINUE {	//transfer control back to recent while loop - := while_loop_[NUM]
				if(!LoopLabel.empty()) {
					string loopType = LoopLabel.back()[0];
					if (loopType == "while") {
						statements.push_back(":= " + LoopLabel.back()[1]);
					}
					else { 
						statements.push_back(":= " + LoopLabel.back()[2]);
					}
				}
				if (LoopLabel.empty()){
					printf("Error line %d: continue statement not within a loop\n", currline);
					isError = true;
				}
			}
	;

st9:	RETURN expression {
				statements.push_back("ret " + ops_table.back());
				ops_table.pop_back();
				ops_table_type.pop_back();
			}
	;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	


bool_exp:	relation_and_exp 
			
		| relation_and_exp OR bool_exp {
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");

				string op2 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();

				statements.push_back("|| " + temp + ", " + op1 + ", " + op2);
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
		;

relation_and_exp:	relation_exp 
		
			| relation_exp AND relation_and_exp {
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");

				string op2 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();

				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back("&& " + temp + ", " + op1 + ", " + op2);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			} 
		;

relation_exp: 	rexp
			
		| NOT rexp {
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");

				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back("! " + temp + ", " + op1);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
		;

rexp:		expression comp expression {
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");

				string op2 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				string comp = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();

				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back(comp + " " + temp + ", " + op1 + ", " + op2);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
			
		| TRUE {	//= t[temp_var_num], 1
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");
				
				statements.push_back("= " + temp + ", 1");
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
			
		| FALSE {	//= t[temp_var_num], 0
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");
				
				statements.push_back("= " + temp + ", 0");
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}

		| L_PAREN bool_exp R_PAREN 
		
		;

comp:			EQ {
				ops_table.push_back("==");
				ops_table_type.push_back("null");
			}

			| NEQ {
				ops_table.push_back("!=");
				ops_table_type.push_back("null");
			}

			| LT {
				ops_table.push_back("<");
				ops_table_type.push_back("null");
			} 

			| GT {
				ops_table.push_back(">");
				ops_table_type.push_back("null");
			}

			| LTE {
				ops_table.push_back("<=");
				ops_table_type.push_back("null");
			}

			| GTE {
				ops_table.push_back(">=");
				ops_table_type.push_back("null");
			}
			;

expressions:	expression 
		
		| expression COMMA expression 

		;
			
expression:	mult_expression 
			
		| mult_expression ADD expression { 
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");

				string op2 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();

				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back("+ " + temp + ", " + op1 + ", " + op2);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}

		| mult_expression SUB expression {
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");

				string op2 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();

				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back("- " + temp + ", " + op1 + ", " + op2);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
		;

mult_expression:	term
			
			| term MULT mult_expression {
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");

				string op2 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();

				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back("* " + temp + ", " + op1 + ", " + op2);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}

			| term DIV mult_expression {
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");

				string op2 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();

				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back("/ " + temp + ", " + op1 + ", " + op2);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}

			| term MOD mult_expression {
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");

				string op2 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();

				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back("% " + temp + ", " + op1 + ", " + op2);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
		;

term:		var 
			
		| NUMBER {
				ops_table.push_back(to_string($1));
				ops_table_type.push_back("INTEGER");
			}
			
		| SUB NUMBER {
				ops_table.push_back(to_string($2*-1));
				ops_table_type.push_back("INTEGER");
			}
			
		| L_PAREN expression R_PAREN 

		| SUB L_PAREN expression R_PAREN {
				string temp = "_t"+to_string(tempCount++);
				
				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back("- " + temp + ", 0, " + op1);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
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
					printf("Error line %d: Function %s not defined\n", currline,$1 );
					isError = true;
				}

				string temp = "_t"+to_string(tempCount++);
					symbol_table.push_back(temp);
					symbol_table_type.push_back("INTEGER");

				string op1 = ops_table.back();
					ops_table.pop_back();
					ops_table_type.pop_back();

				statements.push_back("param " + op1);
				statements.push_back(string("call ") + $1 + ", " + temp);

				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
		;

var: 		IDENT {
				if (!identifer_used($1)) {
					printf("Error line %d: used variable %s was not previously defined\n", currline, $1);
					//yyerror("variable not defined.");
					isError = true;
				}
				unsigned tmp = index_return($1);
				if(symbol_table_type[tmp] != "INTEGER"){
					printf("Error line %d: used array variable \"%s\" is missing a specified index\n", currline, $1);
					isError = true;
				}
				string temp = $1;
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
			
		| IDENT L_SQUARE_BRACKET expressions R_SQUARE_BRACKET {
				if (!identifer_used($1)) {
					printf("Error line %d: used variable %s was not previously defined\n", currline, $1);
					//yyerror("variable not defined.");
					isError = true;
				}
				unsigned tmp = index_return($1);
				if(symbol_table_type[tmp] == "INTEGER"){
					printf("Error line %d: used integer variable \"%s\" does not have an index\n",currline, $1);
					isError = true;
				}
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");

				string arraySize = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				ops_table.push_back(temp);
				ops_table_type.push_back("ARRAY");
				statements.push_back("=[] "+ temp + ", " + $1 + ", " + arraySize);
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
		printf("Error: Main function is not declared\n");
		return -1;
	}
	if (isError) {
		
		return -1;
	}

	for(unsigned i = 0; i < statements_all.size(); i++) {
		cout << statements_all[i] <<endl;
	}

	return 0;
}

void yyerror(const char *msg) {



	printf("** Line %d, position %d: %s\n", currline, currpos, msg);
}

