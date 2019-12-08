/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "mini_l.y" /* yacc.c:339  */

 #include "heading.h"
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
 extern int curline;
 extern int curpos;
 extern FILE * yyin;


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
 
 
 vector<string> symbol_table; // table for symbols
 vector<string> symbol_table_type; // table for symbol types
 vector<string> param_table; // parameter table
 vector<string> ops_table; // operators table
 vector<string> ops_table_type; // operators type table

 vector<string> statements;  
 vector<string> statements_all;
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

 bool identiferUsed (string s) {
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


#line 160 "mini_l.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "mini_l.tab.h".  */
#ifndef YY_YY_MINI_L_TAB_H_INCLUDED
# define YY_YY_MINI_L_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCTION = 258,
    BEGIN_PARAMS = 259,
    END_PARAMS = 260,
    BEGIN_LOCALS = 261,
    END_LOCALS = 262,
    BEGIN_BODY = 263,
    END_BODY = 264,
    INTEGER = 265,
    ARRAY = 266,
    OF = 267,
    IF = 268,
    THEN = 269,
    ENDIF = 270,
    ELSE = 271,
    WHILE = 272,
    DO = 273,
    BEGINLOOP = 274,
    ENDLOOP = 275,
    CONTINUE = 276,
    READ = 277,
    WRITE = 278,
    AND = 279,
    OR = 280,
    NOT = 281,
    TRUE = 282,
    FALSE = 283,
    RETURN = 284,
    SUB = 285,
    ADD = 286,
    MULT = 287,
    DIV = 288,
    MOD = 289,
    EQ = 290,
    NEQ = 291,
    LT = 292,
    GT = 293,
    LTE = 294,
    GTE = 295,
    SEMICOLON = 296,
    COLON = 297,
    COMMA = 298,
    L_PAREN = 299,
    R_PAREN = 300,
    L_SQUARE_BRACKET = 301,
    R_SQUARE_BRACKET = 302,
    ASSIGN = 303,
    NUMBER = 304,
    IDENT = 305,
    UMINUS = 306
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 114 "mini_l.y" /* yacc.c:355  */

  int ival;
  char *string;
  double dval;

#line 258 "mini_l.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_MINI_L_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 275 "mini_l.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif


#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  7
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   135

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  81
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  156

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   306

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   121,   121,   124,   125,   128,   135,   138,   141,   182,
     183,   186,   188,   192,   201,   207,   236,   267,   268,   271,
     272,   273,   274,   275,   276,   277,   278,   279,   282,   302,
     339,   379,   386,   392,   413,   419,   426,   437,   446,   466,
     471,   488,   491,   495,   508,   522,   535,   551,   568,   578,
     580,   599,   601,   621,   623,   639,   662,   673,   684,   688,
     693,   698,   703,   708,   713,   719,   721,   725,   727,   746,
     766,   768,   787,   806,   826,   828,   833,   838,   840,   853,
     883,   899
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "BEGINLOOP",
  "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", "NOT", "TRUE",
  "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT",
  "GT", "LTE", "GTE", "SEMICOLON", "COLON", "COMMA", "L_PAREN", "R_PAREN",
  "L_SQUARE_BRACKET", "R_SQUARE_BRACKET", "ASSIGN", "NUMBER", "IDENT",
  "UMINUS", "$accept", "prog_start", "functions", "function_ident",
  "begin_params", "end_params", "function", "declarations", "declaration",
  "assign_dec", "identifiers", "statements", "statement", "st1",
  "assign_variable", "st2", "st3", "if_bool", "if_else", "st4", "st5",
  "while_bool", "while", "do_loop", "do", "st6", "st7", "readVars",
  "writeVars", "st8", "st9", "bool_exp", "relation_and_exp",
  "relation_exp", "rexp", "comp", "expressions", "expression",
  "mult_expression", "term", "var", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306
};
# endif

#define YYPACT_NINF -52

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-52)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,   -20,    37,   -52,    14,     9,   -52,   -52,    58,   -52,
     -52,    19,    49,    81,    52,    53,    19,   -52,    88,    19,
      -2,   -52,    19,   -52,   -52,    50,   -52,    91,   -25,    92,
      54,    55,    -7,    57,    87,    -9,   -52,    82,   -52,    56,
      56,   -17,    61,    99,    68,   -52,    62,   -52,   -52,    97,
     -52,   -52,    -7,    -9,    95,    -7,   -52,   -52,   -52,   -52,
     101,   104,     1,   -52,   -52,   -10,    -9,   -52,    41,   -52,
      90,    93,   -52,    39,    18,    20,   -52,   -52,    70,   -52,
      75,   -52,    76,   -17,   -52,   -17,   -52,    -7,   -17,    -7,
     100,   102,    -9,   103,   112,   -52,   -52,   -17,   -52,    79,
      28,   -17,   -17,    -9,    -9,   -52,   -52,   -52,   -52,   -52,
     -52,   -17,   -17,   -17,   -17,   -17,   -17,    56,    56,    80,
      83,    84,   -52,   -52,    43,   -52,   -52,   -52,   -52,   -52,
      86,   -52,   -52,    89,    85,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -17,   -52,    -7,   111,
     -52,   -52,   -52,   -52,   -52,   -52
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     0,     4,     5,     1,     0,     3,
       6,    10,    15,     0,     0,     0,     0,     7,     0,    10,
       0,    16,    10,     9,    12,     0,    11,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    38,     0,    47,     0,
       0,     0,    29,     0,     0,    19,     0,    20,    21,     0,
      22,    23,     0,     0,     0,     0,    24,    25,    26,    27,
       0,     0,     0,    56,    57,     0,     0,    75,    80,    33,
      49,    51,    53,     0,    67,    70,    74,    40,    80,    41,
      43,    42,    45,     0,    48,     0,     8,    18,     0,     0,
       0,     0,     0,     0,     0,    13,    54,     0,    76,     0,
       0,     0,     0,     0,     0,    59,    60,    61,    62,    63,
      64,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    65,    17,    28,     0,    35,    37,    36,    39,    14,
       0,    58,    77,     0,     0,    50,    52,    55,    69,    68,
      71,    72,    73,    44,    46,    30,     0,    31,     0,     0,
      78,    79,    81,    66,    34,    32
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -52,   -52,   123,   -52,   -52,   -52,   -52,     4,   -52,   -52,
     113,   -51,   -52,   -52,   -52,   -52,   -52,   -52,   -52,   -52,
     -52,   -52,   -52,   -52,   -52,   -52,   -52,   -29,   -52,   -52,
     -52,   -46,    29,   -52,    73,   -52,   -11,   -41,   -32,   -52,
     -37
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    18,     5,    13,    14,    26,
      15,    43,    44,    45,    46,    47,    48,    49,   149,    50,
      51,    52,    53,    54,    55,    56,    57,    79,    81,    58,
      59,    69,    70,    71,    72,   111,   120,    73,    74,    75,
      76
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      84,    90,    80,    82,    93,    30,    35,    91,    24,    25,
      36,    37,     1,    65,    38,    39,    40,    62,    63,    64,
      99,    65,    41,    23,    31,   100,    27,    83,    63,    64,
       6,    65,    67,    68,    97,    66,   122,     7,   124,    98,
      67,    68,   119,    42,   121,    66,   127,   123,   112,   113,
      67,    68,   114,   115,   116,     8,   130,   135,   147,   148,
     121,   121,    10,   105,   106,   107,   108,   109,   110,    12,
     137,   138,   139,   132,   105,   106,   107,   108,   109,   110,
      80,    80,   140,   141,   142,   101,    17,   102,   143,   144,
     133,   134,    16,    19,    22,    20,    28,   154,    29,    61,
      32,    77,    34,    33,    60,   153,    78,    85,    86,    87,
      88,    89,    92,    94,    95,   103,   102,   104,   117,   118,
     125,   126,   129,   128,   131,   132,   155,   146,     9,    21,
     145,   150,   152,   136,   151,    96
};

static const yytype_uint8 yycheck[] =
{
      41,    52,    39,    40,    55,    30,    13,    53,    10,    11,
      17,    18,     3,    30,    21,    22,    23,    26,    27,    28,
      66,    30,    29,    19,    49,    66,    22,    44,    27,    28,
      50,    30,    49,    50,    44,    44,    87,     0,    89,    49,
      49,    50,    83,    50,    85,    44,    92,    88,    30,    31,
      49,    50,    32,    33,    34,    41,    97,   103,    15,    16,
     101,   102,     4,    35,    36,    37,    38,    39,    40,    50,
     111,   112,   113,    45,    35,    36,    37,    38,    39,    40,
     117,   118,   114,   115,   116,    44,     5,    46,   117,   118,
     101,   102,    43,    41,     6,    42,    46,   148,     7,    12,
       8,    19,    47,    49,    47,   146,    50,    46,     9,    41,
      48,    14,    17,    12,    10,    25,    46,    24,    43,    43,
      20,    19,    10,    20,    45,    45,    15,    43,     5,    16,
      47,    45,    47,   104,    45,    62
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,    54,    55,    58,    50,     0,    41,    54,
       4,    56,    50,    59,    60,    62,    43,     5,    57,    41,
      42,    62,     6,    59,    10,    11,    61,    59,    46,     7,
      30,    49,     8,    49,    47,    13,    17,    18,    21,    22,
      23,    29,    50,    63,    64,    65,    66,    67,    68,    69,
      71,    72,    73,    74,    75,    76,    77,    78,    81,    82,
      47,    12,    26,    27,    28,    30,    44,    49,    50,    83,
      84,    85,    86,    89,    90,    91,    92,    19,    50,    79,
      92,    80,    92,    44,    89,    46,     9,    41,    48,    14,
      63,    83,    17,    63,    12,    10,    86,    44,    49,    83,
      89,    44,    46,    25,    24,    35,    36,    37,    38,    39,
      40,    87,    30,    31,    32,    33,    34,    43,    43,    89,
      88,    89,    63,    89,    63,    20,    19,    83,    20,    10,
      89,    45,    45,    88,    88,    83,    84,    89,    89,    89,
      90,    90,    90,    79,    79,    47,    43,    15,    16,    70,
      45,    45,    47,    89,    63,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    56,    57,    58,    59,
      59,    60,    61,    61,    61,    62,    62,    63,    63,    64,
      64,    64,    64,    64,    64,    64,    64,    64,    65,    66,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    79,    80,    80,    81,    82,    83,
      83,    84,    84,    85,    85,    86,    86,    86,    86,    87,
      87,    87,    87,    87,    87,    88,    88,    89,    89,    89,
      90,    90,    90,    90,    91,    91,    91,    91,    91,    91,
      92,    92
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,    11,     3,
       0,     3,     1,     6,     7,     1,     3,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       4,     4,     5,     2,     2,     3,     3,     3,     1,     3,
       2,     2,     2,     1,     3,     1,     3,     1,     2,     1,
       3,     1,     3,     1,     2,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     1,     1,     2,     3,     4,     4,
       1,     4
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 5:
#line 129 "mini_l.y" /* yacc.c:1646  */
    {
					functions.push_back((yyvsp[0].string));
					statements_all.push_back(string("func ") + functions.back());
				}
#line 1469 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 135 "mini_l.y" /* yacc.c:1646  */
    {isParam = true; }
#line 1475 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 138 "mini_l.y" /* yacc.c:1646  */
    {isParam = false; }
#line 1481 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 142 "mini_l.y" /* yacc.c:1646  */
    {
				
				
				for(unsigned i = 0; i < symbol_table.size(); i++) {
					if(symbol_table_type[i] == "INTEGER") {
						statements_all.push_back(". " + symbol_table[i]);
					}
					else {
						statements_all.push_back(".[] " + symbol_table[i] + ", " + symbol_table_type[i]);
					}
				}

				 while(!param_table.empty()) {
				 	statements.push_back("= " + param_table.back() + ", $" + to_string(paramCount)); 
				 	
				 	param_table.pop_back(); 
				 	paramCount++;
				 } 
				 
				

				
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
#line 1523 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 189 "mini_l.y" /* yacc.c:1646  */
    {
				symbol_table_type.push_back("INTEGER");
			}
#line 1531 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 192 "mini_l.y" /* yacc.c:1646  */
    {
					if((yyvsp[-3].ival) == 0){
						printf("Error line %d: %d is not a valid array size\n", curline, (yyvsp[-3].ival));
						isError = true;					
					}
					else {
						symbol_table_type.push_back(to_string((yyvsp[-3].ival)));
						}
			}
#line 1545 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 201 "mini_l.y" /* yacc.c:1646  */
    {
					printf("Error line %d: -%d is not a valid array size\n", curline, (yyvsp[-3].ival));
					isError = true;
			}
#line 1554 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 207 "mini_l.y" /* yacc.c:1646  */
    {
				for (unsigned i = 0; i < symbol_table.size(); i++) {
					if (symbol_table[i] == (yyvsp[0].string)) {
					printf("Error Line %d: symbol %s is already defined \n", curline, (yyvsp[0].string));
					
					isError = true;
					}
				}
				for (unsigned i = 0; i < param_table.size(); i++) {
					if (param_table[i] == (yyvsp[0].string)) {
						printf("Error Line %d: parameter %s is already defined \n", curline, (yyvsp[0].string));

						isError = true;
					}
				}
				for (unsigned i = 0; i < functions.size(); i++) {
					if (functions[i] == (yyvsp[0].string)) {
						printf("Error Line %d: function %s is already defined \n", curline, (yyvsp[0].string));

						isError = true;
					}
				}

				if (isParam == true) {
					param_table.push_back((yyvsp[0].string));
				}
				symbol_table.push_back((yyvsp[0].string));
			}
#line 1587 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 236 "mini_l.y" /* yacc.c:1646  */
    {
				for (unsigned i = 0; i < symbol_table.size(); i++) {
					if (symbol_table[i] == (yyvsp[-2].string)) {
					printf("Error Line %d: symbol %s is already defined \n", curline, (yyvsp[-2].string));
					
					isError = true;
					}
				}
				for (unsigned i = 0; i < param_table.size(); i++) {
					if (param_table[i] == (yyvsp[-2].string)) {
						printf("Error Line %d: parameter %s is already defined \n", curline, (yyvsp[-2].string));

						isError = true;
					}
				}
				for (unsigned i = 0; i < functions.size(); i++) {
					if (functions[i] == (yyvsp[-2].string)) {
						printf("Error Line %d: function %s is already defined \n", curline, (yyvsp[-2].string));

						isError = true;
					}
				}

				symbol_table.push_back((yyvsp[-2].string));
				symbol_table_type.push_back("INTEGER");

			}
#line 1619 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 282 "mini_l.y" /* yacc.c:1646  */
    {
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
					statements.push_back("[]= _" + op + ", " + op2);
				}
			}
#line 1640 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 302 "mini_l.y" /* yacc.c:1646  */
    { unsigned tmp = 0;
				for (unsigned i = 0; i < symbol_table.size(); i++) {
					if (symbol_table[i] == (yyvsp[0].string)) {
					printf("Error Line %d: used variable %s is already defined \n", curline, (yyvsp[0].string));
					
					isError = true;
					tmp = i;
					}
				}
				for (unsigned i = 0; i < param_table.size(); i++) {
					if (param_table[i] == (yyvsp[0].string)) {
						printf("Error Line %d: used variable %s is already defined \n", curline, (yyvsp[0].string));

						isError = true;
						tmp = i;
					}
				}
				for (unsigned i = 0; i < functions.size(); i++) {
					if (functions[i] == (yyvsp[0].string)) {
						printf("Error Line %d: used variable %s is already defined \n", curline, (yyvsp[0].string));

						isError = true;
						tmp = i;
					}
				}

				
				//unsigned tmp = index($1);
				if(symbol_table_type[tmp] != "INTEGER"){
					printf("Error line %d: used int variable %s does not have an index\n", curline, (yyvsp[0].string));
					isError = true;
				}
				string temp_index = (yyvsp[0].string);
				ops_table.push_back(temp_index);
				ops_table_type.push_back("INTEGER");
			}
#line 1681 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 340 "mini_l.y" /* yacc.c:1646  */
    { unsigned tmp = 0;
				for (unsigned i = 0; i < symbol_table.size(); i++) {
					if (symbol_table[i] == (yyvsp[-3].string)) {
					printf("Error Line %d: used variable %s is already defined \n", curline, (yyvsp[-3].string));
					
					isError = true;
					tmp = i;
					}
				}
				for (unsigned i = 0; i < param_table.size(); i++) {
					if (param_table[i] == (yyvsp[-3].string)) {
						printf("Error Line %d: used variable %s is already defined \n", curline, (yyvsp[-3].string));

						isError = true;
						tmp = i;
					}
				}
				for (unsigned i = 0; i < functions.size(); i++) {
					if (functions[i] == (yyvsp[-3].string)) {
						printf("Error Line %d: used variable %s is already defined \n", curline, (yyvsp[-3].string));

						isError = true;
						tmp = i;
					}
				}
				//unsigned tmp = index($1);
				if(symbol_table_type[tmp] == "INTEGER"){
					printf("Error integer is used as an Array\n");
				}
				string temp = (yyvsp[-3].string);
				string size = ops_table.back();
					ops_table.pop_back();
					ops_table_type.pop_back();
				string id = temp + ", " + size;
				ops_table.push_back(id);
				ops_table_type.push_back("ARRAY");
			}
#line 1723 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 379 "mini_l.y" /* yacc.c:1646  */
    { 
				statements.push_back(":= " + ifLabel.back()[1]);
				ifLabel.pop_back();
			}
#line 1732 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 386 "mini_l.y" /* yacc.c:1646  */
    { 
				statements.push_back(": " + ifLabel.back()[2]);
				ifLabel.pop_back();
			}
#line 1741 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 392 "mini_l.y" /* yacc.c:1646  */
    {		/* ?= test_codition_temp_variable, goto first_label
               		          =:second_label
              			  :first_label
             			   ## Statements
                		  :second_label
            			*/

				vector<string> temp;
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				temp.push_back("L" + to_string(labelCount++));
				ifLabel.push_back(temp);
				statements.push_back("?:= " + ifLabel.back()[0] + ", " + ops_table.back());
					//if condition evaluate then goto first_label
				ops_table.pop_back();
				ops_table_type.pop_back();
				statements.push_back(":= " + ifLabel.back()[1]); //goto second_label
				statements.push_back(": " + ifLabel.back()[0]);  //declaration first_laebl
			}
#line 1765 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 413 "mini_l.y" /* yacc.c:1646  */
    {
				statements.push_back(":= " + ifLabel.back()[2]);  
				statements.push_back(": " + ifLabel.back()[1]);
			}
#line 1774 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 419 "mini_l.y" /* yacc.c:1646  */
    { 
				statements.push_back(":= " + LoopLabel.back()[1]);
				statements.push_back(": " + LoopLabel.back()[3]);
				LoopLabel.pop_back();
			}
#line 1784 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 426 "mini_l.y" /* yacc.c:1646  */
    { 
				statements.push_back("?:= " + LoopLabel.back()[1] + ", " + ops_table.back());
				
				ops_table.pop_back();
				ops_table_type.pop_back();
				LoopLabel.pop_back();
			}
#line 1796 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 437 "mini_l.y" /* yacc.c:1646  */
    {
				statements.push_back("?:= " + LoopLabel.back()[2] + ", " +ops_table.back());
				ops_table.pop_back();
				ops_table_type.pop_back();
				statements.push_back(":= " + LoopLabel.back()[3]);
				statements.push_back(": " + LoopLabel.back()[2]);
		}
#line 1808 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 446 "mini_l.y" /* yacc.c:1646  */
    {		/* :while_loop_[NUM]
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
#line 1831 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 466 "mini_l.y" /* yacc.c:1646  */
    {
				statements.push_back(": " + LoopLabel.back()[2]);
		}
#line 1839 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 471 "mini_l.y" /* yacc.c:1646  */
    {		 /* :do_while_loop_[NUM]
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
#line 1858 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 495 "mini_l.y" /* yacc.c:1646  */
    {
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
#line 1875 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 508 "mini_l.y" /* yacc.c:1646  */
    { 
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
#line 1892 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 522 "mini_l.y" /* yacc.c:1646  */
    {
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
#line 1909 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 535 "mini_l.y" /* yacc.c:1646  */
    { 
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
#line 1926 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 551 "mini_l.y" /* yacc.c:1646  */
    {	//transfer control back to recent while loop - := while_loop_[NUM]
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
					printf("Error line %d: continue statement not within a loop\n", curline);
					isError = true;
				}
			}
#line 1946 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 568 "mini_l.y" /* yacc.c:1646  */
    {
				statements.push_back("ret " + ops_table.back());
				ops_table.pop_back();
				ops_table_type.pop_back();
			}
#line 1956 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 580 "mini_l.y" /* yacc.c:1646  */
    {
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
#line 1978 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 601 "mini_l.y" /* yacc.c:1646  */
    {
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
#line 2001 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 623 "mini_l.y" /* yacc.c:1646  */
    {
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
#line 2020 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 639 "mini_l.y" /* yacc.c:1646  */
    {
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
#line 2047 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 662 "mini_l.y" /* yacc.c:1646  */
    {	//= t[temp_var_num], 1
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");
				
				statements.push_back("= " + temp + ", 1");
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
#line 2062 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 673 "mini_l.y" /* yacc.c:1646  */
    {	//= t[temp_var_num], 0
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");
				
				statements.push_back("= " + temp + ", 0");
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
#line 2077 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 688 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back("==");
				ops_table_type.push_back("null");
			}
#line 2086 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 693 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back("!=");
				ops_table_type.push_back("null");
			}
#line 2095 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 698 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back("<");
				ops_table_type.push_back("null");
			}
#line 2104 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 703 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back(">");
				ops_table_type.push_back("null");
			}
#line 2113 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 708 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back("<=");
				ops_table_type.push_back("null");
			}
#line 2122 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 713 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back(">=");
				ops_table_type.push_back("null");
			}
#line 2131 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 727 "mini_l.y" /* yacc.c:1646  */
    { 
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
#line 2154 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 746 "mini_l.y" /* yacc.c:1646  */
    {
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
#line 2177 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 768 "mini_l.y" /* yacc.c:1646  */
    {
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
#line 2200 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 787 "mini_l.y" /* yacc.c:1646  */
    {
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
#line 2223 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 806 "mini_l.y" /* yacc.c:1646  */
    {
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
#line 2246 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 828 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back(to_string((yyvsp[0].ival)));
				ops_table_type.push_back("INTEGER");
			}
#line 2255 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 833 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back(to_string((yyvsp[0].ival)*-1));
				ops_table_type.push_back("INTEGER");
			}
#line 2264 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 840 "mini_l.y" /* yacc.c:1646  */
    {
				string temp = "_t"+to_string(tempCount++);
				
				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back("- " + temp + ", 0, " + op1);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
#line 2281 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 853 "mini_l.y" /* yacc.c:1646  */
    { //call a function
				// check if the funciton $1 has been defined
				bool findFunction = false;
				for (unsigned i = 0; i < functions.size(); i++) {
					if (functions[i] == (yyvsp[-3].string)) {
						findFunction = true;
						break;
					}
				}
				if (!findFunction) {
					printf("Error line %d: Function %s not defined\n", curline,(yyvsp[-3].string) );
					isError = true;
				}

				string temp = "_t"+to_string(tempCount++);
					symbol_table.push_back(temp);
					symbol_table_type.push_back("INTEGER");

				string op1 = ops_table.back();
					ops_table.pop_back();
					ops_table_type.pop_back();

				statements.push_back("param " + op1);
				statements.push_back(string("call ") + (yyvsp[-3].string) + ", " + temp);

				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
#line 2314 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 883 "mini_l.y" /* yacc.c:1646  */
    {
				if (!identiferUsed((yyvsp[0].string))) {
					printf("Error line %d: used variable %s was not previously defined\n", curline, (yyvsp[0].string));
					//yyerror("variable not defined.");
					isError = true;
				}
				unsigned tmp = index((yyvsp[0].string));
				if(symbol_table_type[tmp] != "INTEGER"){
					printf("Error line %d: used array variable \"%s\" is missing a specified index\n", curline, (yyvsp[0].string));
					isError = true;
				}
				string temp = (yyvsp[0].string);
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
#line 2334 "mini_l.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 899 "mini_l.y" /* yacc.c:1646  */
    {
				if (!identiferUsed((yyvsp[-3].string))) {
					printf("Error line %d: used variable %s was not previously defined\n", curline, (yyvsp[-3].string));
					//yyerror("variable not defined.");
					isError = true;
				}
				unsigned tmp = index((yyvsp[-3].string));
				if(symbol_table_type[tmp] == "INTEGER"){
					printf("Error line %d: used integer variable \"%s\" does not have an index\n",curline, (yyvsp[-3].string));
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
				statements.push_back("=[] "+ temp + ", " + (yyvsp[-3].string) + ", " + arraySize);
			}
#line 2361 "mini_l.tab.c" /* yacc.c:1646  */
    break;


#line 2365 "mini_l.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 923 "mini_l.y" /* yacc.c:1906  */



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

	for(unsigned i = 0; i < statements_all.size(); i++) {
		cout << statements_all[i] <<endl;
	}

	return 0;
}

void yyerror(const char *msg) {
//	extern int curline;
//	 extern int curpos;

	printf("** Line %d, position %d: %s\n", curline, curpos, msg);
}

