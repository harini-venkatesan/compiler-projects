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

 vector<vector<string> > ifLabel;
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


#line 161 "y.tab.c" /* yacc.c:339  */

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
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
#line 115 "mini_l.y" /* yacc.c:355  */

  int ival;
  char *string;
  double dval;

#line 259 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 276 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  157

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
       0,   122,   122,   125,   126,   129,   136,   139,   142,   176,
     186,   187,   190,   192,   196,   205,   211,   226,   243,   244,
     247,   248,   249,   250,   251,   252,   253,   254,   255,   258,
     278,   297,   318,   325,   331,   352,   358,   365,   376,   385,
     405,   410,   427,   430,   434,   447,   461,   474,   490,   507,
     517,   519,   538,   540,   560,   562,   578,   601,   612,   623,
     627,   632,   637,   642,   647,   652,   658,   660,   664,   666,
     685,   705,   707,   726,   745,   765,   767,   772,   777,   779,
     792,   822,   838
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
  "begin_params", "end_params", "function", "print_params", "declarations",
  "declaration", "assign_dec", "identifiers", "statements", "statement",
  "st1", "assign_variable", "st2", "st3", "if_bool", "if_else", "st4",
  "st5", "while_bool", "while", "do_loop", "do", "st6", "st7", "readVars",
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

#define YYPACT_NINF -55

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-55)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       9,   -27,    30,   -55,    -4,     9,   -55,   -55,    35,   -55,
     -55,    -1,    18,    63,    52,    54,    -1,   -55,   -55,    -1,
      -2,   -55,    88,   -55,   -55,    51,   -55,    -1,   -25,    91,
      50,    53,    93,    55,    92,    -7,    94,    95,    -9,   -55,
      89,   -55,    59,    59,   -17,    61,   101,    70,   -55,    64,
     -55,   -55,    99,   -55,   -55,    -7,    -9,    97,    -7,   -55,
     -55,   -55,   -55,   105,   -55,     1,   -55,   -55,     4,    -9,
     -55,     8,   -55,    96,    98,   -55,    38,    57,    49,   -55,
     -55,    71,   -55,    73,   -55,    75,   -17,   -55,   -17,   -55,
      -7,   -17,    -7,   100,   104,    -9,   106,   -55,   -55,   -17,
     -55,    74,    27,   -17,   -17,    -9,    -9,   -55,   -55,   -55,
     -55,   -55,   -55,   -17,   -17,   -17,   -17,   -17,   -17,    59,
      59,    79,    78,    84,   -55,   -55,    42,   -55,   -55,   -55,
     -55,    83,   -55,   -55,    85,    82,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -17,   -55,    -7,
     116,   -55,   -55,   -55,   -55,   -55,   -55
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,     0,     0,     2,     0,     4,     5,     1,     0,     3,
       6,    11,    16,     0,     0,     0,     0,     7,     9,    11,
       0,    17,     0,    10,    13,     0,    12,    11,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    39,
       0,    48,     0,     0,     0,    30,     0,     0,    20,     0,
      21,    22,     0,    23,    24,     0,     0,     0,     0,    25,
      26,    27,    28,     0,    14,     0,    57,    58,     0,     0,
      76,    81,    34,    50,    52,    54,     0,    68,    71,    75,
      41,    81,    42,    44,    43,    46,     0,    49,     0,     8,
      19,     0,     0,     0,     0,     0,     0,    15,    55,     0,
      77,     0,     0,     0,     0,     0,     0,    60,    61,    62,
      63,    64,    65,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    66,    18,    29,     0,    36,    38,    37,
      40,     0,    59,    78,     0,     0,    51,    53,    56,    70,
      69,    72,    73,    74,    45,    47,    31,     0,    32,     0,
       0,    79,    80,    82,    67,    35,    33
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -55,   -55,   127,   -55,   -55,   -55,   -55,   -55,     7,   -55,
     -55,   117,   -54,   -55,   -55,   -55,   -55,   -55,   -55,   -55,
     -55,   -55,   -55,   -55,   -55,   -55,   -55,   -55,   -30,   -55,
     -55,   -55,   -49,    28,   -55,    72,   -55,   -12,   -44,   -32,
     -55,   -40
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     4,    11,    18,     5,    22,    13,    14,
      26,    15,    46,    47,    48,    49,    50,    51,    52,   150,
      53,    54,    55,    56,    57,    58,    59,    60,    82,    84,
      61,    62,    72,    73,    74,    75,   113,   122,    76,    77,
      78,    79
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      87,    93,    83,    85,    96,    30,    38,    94,    24,    25,
      39,    40,     1,    68,    41,    42,    43,    65,    66,    67,
     101,    68,    44,     6,    31,   102,    23,    86,    66,    67,
       7,    68,    70,    71,    29,    69,   124,     8,   126,    10,
      70,    71,   121,    45,   123,    69,   129,   125,    99,    12,
      70,    71,   103,   100,   104,   131,   136,   148,   149,   123,
     123,    16,   107,   108,   109,   110,   111,   112,    17,   138,
     139,   140,   133,   107,   108,   109,   110,   111,   112,    83,
      83,   116,   117,   118,   141,   142,   143,   114,   115,   144,
     145,   134,   135,    19,    27,   155,    20,    28,    32,    33,
      34,    35,    36,   154,    37,    64,    63,    88,    80,    81,
      89,    90,    91,    92,    95,    97,   119,   104,   120,   132,
     127,   105,   106,   128,   133,   146,   130,   147,   151,   153,
     152,   156,     9,    21,   137,     0,     0,    98
};

static const yytype_int16 yycheck[] =
{
      44,    55,    42,    43,    58,    30,    13,    56,    10,    11,
      17,    18,     3,    30,    21,    22,    23,    26,    27,    28,
      69,    30,    29,    50,    49,    69,    19,    44,    27,    28,
       0,    30,    49,    50,    27,    44,    90,    41,    92,     4,
      49,    50,    86,    50,    88,    44,    95,    91,    44,    50,
      49,    50,    44,    49,    46,    99,   105,    15,    16,   103,
     104,    43,    35,    36,    37,    38,    39,    40,     5,   113,
     114,   115,    45,    35,    36,    37,    38,    39,    40,   119,
     120,    32,    33,    34,   116,   117,   118,    30,    31,   119,
     120,   103,   104,    41,     6,   149,    42,    46,     7,    49,
      47,     8,    47,   147,    12,    10,    12,    46,    19,    50,
       9,    41,    48,    14,    17,    10,    43,    46,    43,    45,
      20,    25,    24,    19,    45,    47,    20,    43,    45,    47,
      45,    15,     5,    16,   106,    -1,    -1,    65
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    53,    54,    55,    58,    50,     0,    41,    54,
       4,    56,    50,    60,    61,    63,    43,     5,    57,    41,
      42,    63,    59,    60,    10,    11,    62,     6,    46,    60,
      30,    49,     7,    49,    47,     8,    47,    12,    13,    17,
      18,    21,    22,    23,    29,    50,    64,    65,    66,    67,
      68,    69,    70,    72,    73,    74,    75,    76,    77,    78,
      79,    82,    83,    12,    10,    26,    27,    28,    30,    44,
      49,    50,    84,    85,    86,    87,    90,    91,    92,    93,
      19,    50,    80,    93,    81,    93,    44,    90,    46,     9,
      41,    48,    14,    64,    84,    17,    64,    10,    87,    44,
      49,    84,    90,    44,    46,    25,    24,    35,    36,    37,
      38,    39,    40,    88,    30,    31,    32,    33,    34,    43,
      43,    90,    89,    90,    64,    90,    64,    20,    19,    84,
      20,    90,    45,    45,    89,    89,    84,    85,    90,    90,
      90,    91,    91,    91,    80,    80,    47,    43,    15,    16,
      71,    45,    45,    47,    90,    64,    15
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    56,    57,    58,    59,
      60,    60,    61,    62,    62,    62,    63,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    66,
      67,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    80,    81,    81,    82,    83,
      84,    84,    85,    85,    86,    86,    87,    87,    87,    87,
      88,    88,    88,    88,    88,    88,    89,    89,    90,    90,
      90,    91,    91,    91,    91,    92,    92,    92,    92,    92,
      92,    93,    93
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     2,     1,     1,    12,     0,
       3,     0,     3,     1,     6,     7,     1,     3,     3,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     4,     4,     5,     2,     2,     3,     3,     3,     1,
       3,     2,     2,     2,     1,     3,     1,     3,     1,     2,
       1,     3,     1,     3,     1,     2,     3,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     1,     1,     2,     3,     4,
       4,     1,     4
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
#line 130 "mini_l.y" /* yacc.c:1646  */
    {
					functions.push_back((yyvsp[0].string));
					statements_all.push_back(string("func ") + functions.back());
				}
#line 1470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 136 "mini_l.y" /* yacc.c:1646  */
    {isParam = true; }
#line 1476 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 139 "mini_l.y" /* yacc.c:1646  */
    {isParam = false; }
#line 1482 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 143 "mini_l.y" /* yacc.c:1646  */
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
#line 1518 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 176 "mini_l.y" /* yacc.c:1646  */
    {
			 while(!param_table.empty()) {
			 	statements.push_back("= " + param_table.back() + ", $" + to_string(paramCount)); 
			 	param_table.pop_back(); 
			 	paramCount++;
			 } 
			 isParam = false;
		}
#line 1531 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 193 "mini_l.y" /* yacc.c:1646  */
    {
				symbol_table_type.push_back("INTEGER");
			}
#line 1539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 196 "mini_l.y" /* yacc.c:1646  */
    {
					if((yyvsp[-3].ival) == 0){
						printf("Error line %d: %d is not a valid array size\n", currline, (yyvsp[-3].ival));
						isError = true;					
					}
					else {
						symbol_table_type.push_back(to_string((yyvsp[-3].ival)));
						}
			}
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 205 "mini_l.y" /* yacc.c:1646  */
    {
					printf("Error line %d: -%d is not a valid array size\n", currline, (yyvsp[-3].ival));
					isError = true;
			}
#line 1562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 211 "mini_l.y" /* yacc.c:1646  */
    {
				if (identifer_used((yyvsp[0].string))) {
					printf("Error Line %d: symbol %s is already defined \n", currline, (yyvsp[0].string));
					//yyerror("symbol %s is multiply-defined");
					isError = true;
				}
				if (isParam) {
					param_table.push_back((yyvsp[0].string));
				}
				symbol_table.push_back((yyvsp[0].string));

			
				//symbol_table.push_back($1);
			}
#line 1581 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 226 "mini_l.y" /* yacc.c:1646  */
    {
				
				 if (identifer_used((yyvsp[-2].string))) {
                                        printf("Error Line %d: symbol %s is already defined \n", currline, (yyvsp[-2].string));
                                        //yyerror("symbol %s is multiply-defined");
                                        isError = true;
                                }


				symbol_table.push_back((yyvsp[-2].string));
				symbol_table_type.push_back("INTEGER");

			}
#line 1599 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 258 "mini_l.y" /* yacc.c:1646  */
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
					statements.push_back("[]= " + op + ", " + op2);
				}
			}
#line 1620 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 278 "mini_l.y" /* yacc.c:1646  */
    { 
				
				if (!identifer_used((yyvsp[0].string))) {
					printf("Error line %d: used variable %s was not previously declared\n", currline, (yyvsp[0].string));
					isError = true;
				}
				unsigned tmp = index_return((yyvsp[0].string));

				
				//unsigned tmp = index($1);
				if(symbol_table_type[tmp] != "INTEGER"){
					printf("Error line %d: used int variable %s does not have an index\n", currline, (yyvsp[0].string));
					isError = true;
				}
				string temp_index = (yyvsp[0].string);
				ops_table.push_back(temp_index);
				ops_table_type.push_back("INTEGER");
			}
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 298 "mini_l.y" /* yacc.c:1646  */
    { if (!identifer_used((yyvsp[-3].string))) {
					printf("Error line %d: used variable %s was not previously declared\n", currline, (yyvsp[-3].string));
					isError = true;
				}
				unsigned tmp = index_return((yyvsp[-3].string));
				
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
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 318 "mini_l.y" /* yacc.c:1646  */
    { 
				statements.push_back(": " + ifLabel.back()[1]);
				ifLabel.pop_back();
			}
#line 1675 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 325 "mini_l.y" /* yacc.c:1646  */
    { 
				statements.push_back(": " + ifLabel.back()[2]);
				ifLabel.pop_back();
			}
#line 1684 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 331 "mini_l.y" /* yacc.c:1646  */
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
#line 1708 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 352 "mini_l.y" /* yacc.c:1646  */
    {
				statements.push_back(":= " + ifLabel.back()[2]);  
				statements.push_back(": " + ifLabel.back()[1]);
			}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 358 "mini_l.y" /* yacc.c:1646  */
    { 
				statements.push_back(":= " + LoopLabel.back()[1]);
				statements.push_back(": " + LoopLabel.back()[3]);
				LoopLabel.pop_back();
			}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 365 "mini_l.y" /* yacc.c:1646  */
    { 
				statements.push_back("?:= " + LoopLabel.back()[1] + ", " + ops_table.back());
				
				ops_table.pop_back();
				ops_table_type.pop_back();
				LoopLabel.pop_back();
			}
#line 1739 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 376 "mini_l.y" /* yacc.c:1646  */
    {
				statements.push_back("?:= " + LoopLabel.back()[2] + ", " +ops_table.back());
				ops_table.pop_back();
				ops_table_type.pop_back();
				statements.push_back(":= " + LoopLabel.back()[3]);
				statements.push_back(": " + LoopLabel.back()[2]);
		}
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 385 "mini_l.y" /* yacc.c:1646  */
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
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 405 "mini_l.y" /* yacc.c:1646  */
    {
				statements.push_back(": " + LoopLabel.back()[2]);
		}
#line 1782 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 410 "mini_l.y" /* yacc.c:1646  */
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
#line 1801 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 434 "mini_l.y" /* yacc.c:1646  */
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
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 447 "mini_l.y" /* yacc.c:1646  */
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
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 461 "mini_l.y" /* yacc.c:1646  */
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
#line 1852 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 474 "mini_l.y" /* yacc.c:1646  */
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
#line 1869 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 490 "mini_l.y" /* yacc.c:1646  */
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
					printf("Error line %d: continue statement not within a loop\n", currline);
					isError = true;
				}
			}
#line 1889 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 507 "mini_l.y" /* yacc.c:1646  */
    {
				statements.push_back("ret " + ops_table.back());
				ops_table.pop_back();
				ops_table_type.pop_back();
			}
#line 1899 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 519 "mini_l.y" /* yacc.c:1646  */
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
#line 1921 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 540 "mini_l.y" /* yacc.c:1646  */
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
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 562 "mini_l.y" /* yacc.c:1646  */
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
#line 1963 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 578 "mini_l.y" /* yacc.c:1646  */
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
#line 1990 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 601 "mini_l.y" /* yacc.c:1646  */
    {	//= t[temp_var_num], 1
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");
				
				statements.push_back("= " + temp + ", 1");
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
#line 2005 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 612 "mini_l.y" /* yacc.c:1646  */
    {	//= t[temp_var_num], 0
				string temp = "_t"+to_string(tempCount++);
				symbol_table.push_back(temp);
				symbol_table_type.push_back("INTEGER");
				
				statements.push_back("= " + temp + ", 0");
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
#line 2020 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 627 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back("==");
				ops_table_type.push_back("null");
			}
#line 2029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 632 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back("!=");
				ops_table_type.push_back("null");
			}
#line 2038 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 637 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back("<");
				ops_table_type.push_back("null");
			}
#line 2047 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 642 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back(">");
				ops_table_type.push_back("null");
			}
#line 2056 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 647 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back("<=");
				ops_table_type.push_back("null");
			}
#line 2065 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 652 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back(">=");
				ops_table_type.push_back("null");
			}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 666 "mini_l.y" /* yacc.c:1646  */
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
#line 2097 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 685 "mini_l.y" /* yacc.c:1646  */
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
#line 2120 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 707 "mini_l.y" /* yacc.c:1646  */
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
#line 2143 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 726 "mini_l.y" /* yacc.c:1646  */
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
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 745 "mini_l.y" /* yacc.c:1646  */
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
#line 2189 "y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 767 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back(to_string((yyvsp[0].ival)));
				ops_table_type.push_back("INTEGER");
			}
#line 2198 "y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 772 "mini_l.y" /* yacc.c:1646  */
    {
				ops_table.push_back(to_string((yyvsp[0].ival)*-1));
				ops_table_type.push_back("INTEGER");
			}
#line 2207 "y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 779 "mini_l.y" /* yacc.c:1646  */
    {
				string temp = "_t"+to_string(tempCount++);
				
				string op1 = ops_table.back();
				ops_table.pop_back();
				ops_table_type.pop_back();
				
				statements.push_back("- " + temp + ", 0, " + op1);
				
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
#line 2224 "y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 792 "mini_l.y" /* yacc.c:1646  */
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
					printf("Error line %d: Function %s not defined\n", currline,(yyvsp[-3].string) );
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
#line 2257 "y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 822 "mini_l.y" /* yacc.c:1646  */
    {
				if (!identifer_used((yyvsp[0].string))) {
					printf("Error line %d: used variable %s was not previously defined\n", currline, (yyvsp[0].string));
					//yyerror("variable not defined.");
					isError = true;
				}
				unsigned tmp = index_return((yyvsp[0].string));
				if(symbol_table_type[tmp] != "INTEGER"){
					printf("Error line %d: used array variable \"%s\" is missing a specified index\n", currline, (yyvsp[0].string));
					isError = true;
				}
				string temp = (yyvsp[0].string);
				ops_table.push_back(temp);
				ops_table_type.push_back("INTEGER");
			}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 838 "mini_l.y" /* yacc.c:1646  */
    {
				if (!identifer_used((yyvsp[-3].string))) {
					printf("Error line %d: used variable %s was not previously defined\n", currline, (yyvsp[-3].string));
					//yyerror("variable not defined.");
					isError = true;
				}
				unsigned tmp = index_return((yyvsp[-3].string));
				if(symbol_table_type[tmp] == "INTEGER"){
					printf("Error line %d: used integer variable \"%s\" does not have an index\n",currline, (yyvsp[-3].string));
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
#line 2304 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2308 "y.tab.c" /* yacc.c:1646  */
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
#line 862 "mini_l.y" /* yacc.c:1906  */



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



	printf("** Line %d, position %d: %s\n", currline, currpos, msg);
}

