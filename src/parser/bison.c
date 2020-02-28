/* A Bison parser, made by GNU Bison 3.0.5.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 5 "./parser/parse.y" /* yacc.c:316  */

  #include "heading.h"
  // #include "tokens.h"
  #include "ast.h"


  void yyerror(const char *s);
  int yylex(void);
  extern int yylineno;	// defined and maintained in lex.c
  extern char *yytext;	// defined and maintained in lex.c
  AST *tree;

  char *no_data = "no data";

  // yydebug = 1;

#line 80 "./parser/parse.tab.c" /* yacc.c:316  */



/* Copy the first part of user declarations.  */
#line 1 "./parser/parse.y" /* yacc.c:339  */

  #define YYDEBUG 1

#line 89 "./parser/parse.tab.c" /* yacc.c:339  */

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
   by #include "parse.tab.h".  */
#ifndef YY_YY_PARSER_PARSE_TAB_H_INCLUDED
# define YY_YY_PARSER_PARSE_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 22 "./parser/parse.y" /* yacc.c:355  */

  #include "ast.h"

#line 123 "./parser/parse.tab.c" /* yacc.c:355  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    INT_DEC = 258,
    BOOL_DEC = 259,
    NUMBER = 260,
    STRING = 261,
    BOOL = 262,
    VOID = 263,
    OPEN_PAREN = 264,
    END_PAREN = 265,
    OPEN_BRACE = 266,
    END_BRACE = 267,
    SEMICOLON = 268,
    COMMA = 269,
    MULT = 270,
    DIV = 271,
    MOD = 272,
    ADD = 273,
    SUB = 274,
    GT = 275,
    LT = 276,
    GTE = 277,
    LTE = 278,
    EQ = 279,
    NEQ = 280,
    NEG = 281,
    NOT = 282,
    AND = 283,
    OR = 284,
    ASSIGNMENT = 285,
    IDENTIFIER = 286,
    IF = 287,
    ELSE = 288,
    WHILE = 289,
    BREAK = 290,
    RETURN = 291,
    NO_TYPE = 292,
    VAR_DEC = 293,
    GLOBAL_DEC = 294,
    FUNC_DEC = 295,
    FUNC_DECL = 296,
    FUNC_HEAD = 297,
    MAIN_FUNC = 298,
    ARG_LIST = 299,
    FUNC_INVOKE = 300,
    BLOCK_STATE = 301,
    PARAM_LIST = 302,
    BLOCK = 303
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 27 "./parser/parse.y" /* yacc.c:355  */

  char *name;
  AST * tree;

#line 189 "./parser/parse.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_PARSE_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "./parser/parse.tab.c" /* yacc.c:358  */

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
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   175

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  49
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  77
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  128

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   303

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
      45,    46,    47,    48
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   132,   132,   134,   138,   139,   140,   141,   145,   146,
     150,   151,   157,   158,   159,   163,   167,   171,   175,   180,
     184,   188,   189,   193,   194,   198,   202,   203,   207,   208,
     214,   215,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   231,   232,   236,   237,   238,   242,   243,   247,   248,
     252,   253,   257,   258,   259,   263,   264,   265,   266,   270,
     271,   272,   276,   277,   278,   279,   280,   284,   285,   286,
     289,   290,   294,   295,   299,   300,   304,   308
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT_DEC", "BOOL_DEC", "NUMBER",
  "STRING", "BOOL", "VOID", "OPEN_PAREN", "END_PAREN", "OPEN_BRACE",
  "END_BRACE", "SEMICOLON", "COMMA", "MULT", "DIV", "MOD", "ADD", "SUB",
  "GT", "LT", "GTE", "LTE", "EQ", "NEQ", "NEG", "NOT", "AND", "OR",
  "ASSIGNMENT", "IDENTIFIER", "IF", "ELSE", "WHILE", "BREAK", "RETURN",
  "NO_TYPE", "VAR_DEC", "GLOBAL_DEC", "FUNC_DEC", "FUNC_DECL", "FUNC_HEAD",
  "MAIN_FUNC", "ARG_LIST", "FUNC_INVOKE", "BLOCK_STATE", "PARAM_LIST",
  "BLOCK", "$accept", "start", "literal", "type", "globaldeclarations",
  "globaldeclaration", "variabledeclaration", "identifier",
  "mainfunctiondeclaration", "mainfunctiondeclarator",
  "functiondeclaration", "functionheader", "functiondeclarator",
  "formalparameterlist", "formalparameter", "block", "blockstatements",
  "blockstatement", "statement", "statementexpression", "primary",
  "argumentlist", "functioninvocation", "postfixexpression",
  "unaryexpression", "multiplicativeexpression", "additiveexpression",
  "relationalexpression", "equalityexpression", "conditionalandexpression",
  "conditionalorexpression", "assignmentexpression", "assignment",
  "expression", YY_NULLPTR
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
     295,   296,   297,   298,   299,   300,   301,   302,   303
};
# endif

#define YYPACT_NINF -93

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-93)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       8,   -93,   -93,   -93,    18,   -10,     8,   -93,   -93,    29,
     -93,    30,   -93,    30,   -93,    24,   -93,   -93,    34,    50,
     -93,   -93,    22,   -93,   -93,   -93,   -93,    51,    74,    37,
     107,   -10,   -93,    13,   -93,    65,   -93,   -93,    67,   -93,
     -93,   -93,   -10,    26,   -93,   134,   134,   -93,   -93,   -93,
     -93,   -93,   134,   -93,   134,   134,   -93,    13,   -93,   -93,
     -93,   -93,    49,     9,    36,    46,    61,    69,   -93,   -93,
      90,    94,   122,   134,   -93,   -93,   -93,   -93,   -93,    71,
     111,   113,   114,   108,   -93,   -93,   134,   134,   134,   134,
     134,   134,   134,   134,   134,   134,   134,   134,   134,   -93,
     -93,    41,   -93,   -93,   -93,   139,   139,   -93,   -93,   -93,
     -93,    49,    49,     9,     9,     9,     9,    36,    36,    46,
      61,   -93,   134,    92,   -93,   -93,   139,   -93
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     9,     8,    16,     0,     0,     3,    10,    12,     0,
      14,     0,    13,     0,     1,     0,    20,    11,     0,     0,
      17,    19,     0,    15,    18,    27,    33,     0,     0,     0,
       0,     0,    30,     0,    32,     0,    28,    31,     0,    42,
      41,    22,     0,     0,    23,     0,     0,    35,     4,     5,
       6,     7,     0,    37,     0,     0,    43,    51,    50,    45,
      54,    55,    59,    62,    67,    70,    72,    74,    77,    75,
       0,     0,     0,     0,    26,    29,    34,    25,    21,     0,
       0,     0,     0,    51,    52,    53,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    36,
      49,     0,    46,    76,    24,     0,     0,    44,    56,    57,
      58,    60,    61,    64,    63,    66,    65,    68,    69,    71,
      73,    48,     0,    38,    40,    47,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -93,   -93,   -93,   -12,   -93,   129,   -11,     0,   -93,   -93,
     -93,   -93,   -93,   -93,    57,    91,   -93,   102,   -92,   -93,
     -93,   -93,   -18,   -93,   -39,    20,     1,    23,    47,    48,
     -93,    72,   -15,   -43
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,    56,     5,     6,     7,     8,    83,    10,    11,
      12,    13,    16,    43,    44,    34,    35,    36,    37,    38,
      58,   101,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
       9,    39,    80,    81,    40,    15,     9,    31,    32,    82,
      42,     1,     2,   123,   124,    84,    85,    39,    14,    33,
      40,     3,    72,    31,    32,     1,     2,    89,    90,   102,
      57,    71,    41,    22,   127,    33,    78,    23,    18,     3,
      79,    19,    77,    73,    24,    57,    57,   108,   109,   110,
      47,   121,    57,     1,     2,   122,    91,    92,    93,    94,
      45,    19,    25,    26,    86,    87,    88,    42,     1,     2,
      95,    96,    57,    57,     1,     2,    19,    74,    26,   125,
      76,     3,    27,    46,    28,    29,    30,    39,    39,    97,
      40,    40,   113,   114,   115,   116,     3,    27,    98,    28,
      29,    30,    20,    99,    21,    33,    33,    23,    39,   111,
     112,    40,    48,    49,    50,    51,    52,    72,   117,   118,
      53,   105,    57,   106,   107,   126,    33,    48,    49,    50,
      51,    52,   100,    54,    55,    17,   104,    75,     3,    48,
      49,    50,    51,    52,   119,   103,   120,     0,    54,    55,
      19,     0,    26,     3,     0,     0,     0,     0,     0,     0,
      54,    55,     0,     0,     0,     3,     0,     0,     0,     0,
       3,    27,     0,    28,    29,    30
};

static const yytype_int8 yycheck[] =
{
       0,    19,    45,    46,    19,     5,     6,    19,    19,    52,
      22,     3,     4,   105,   106,    54,    55,    35,     0,    19,
      35,    31,     9,    35,    35,     3,     4,    18,    19,    72,
      30,    31,    10,     9,   126,    35,    10,    13,     9,    31,
      14,    11,    42,    30,    10,    45,    46,    86,    87,    88,
      13,    10,    52,     3,     4,    14,    20,    21,    22,    23,
       9,    11,    12,    13,    15,    16,    17,    79,     3,     4,
      24,    25,    72,    73,     3,     4,    11,    12,    13,   122,
      13,    31,    32,     9,    34,    35,    36,   105,   106,    28,
     105,   106,    91,    92,    93,    94,    31,    32,    29,    34,
      35,    36,    11,    13,    13,   105,   106,    13,   126,    89,
      90,   126,     5,     6,     7,     8,     9,     9,    95,    96,
      13,    10,   122,    10,    10,    33,   126,     5,     6,     7,
       8,     9,    10,    26,    27,     6,    79,    35,    31,     5,
       6,     7,     8,     9,    97,    73,    98,    -1,    26,    27,
      11,    -1,    13,    31,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      31,    32,    -1,    34,    35,    36
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,    31,    50,    52,    53,    54,    55,    56,
      57,    58,    59,    60,     0,    56,    61,    54,     9,    11,
      64,    64,     9,    13,    10,    12,    13,    32,    34,    35,
      36,    52,    55,    56,    64,    65,    66,    67,    68,    71,
      81,    10,    52,    62,    63,     9,     9,    13,     5,     6,
       7,     8,     9,    13,    26,    27,    51,    56,    69,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    56,     9,    30,    12,    66,    13,    56,    10,    14,
      82,    82,    82,    56,    73,    73,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    28,    29,    13,
      10,    70,    82,    80,    63,    10,    10,    10,    73,    73,
      73,    74,    74,    75,    75,    75,    75,    76,    76,    77,
      78,    10,    14,    67,    67,    82,    33,    67
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    49,    50,    50,    51,    51,    51,    51,    52,    52,
      53,    53,    54,    54,    54,    55,    56,    57,    58,    59,
      60,    61,    61,    62,    62,    63,    64,    64,    65,    65,
      66,    66,    67,    67,    67,    67,    67,    67,    67,    67,
      67,    68,    68,    69,    69,    69,    70,    70,    71,    71,
      72,    72,    73,    73,    73,    74,    74,    74,    74,    75,
      75,    75,    76,    76,    76,    76,    76,    77,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    82
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     1,     3,     1,     2,     3,     2,
       2,     4,     3,     1,     3,     2,     3,     2,     1,     2,
       1,     1,     1,     1,     2,     2,     3,     2,     5,     7,
       5,     1,     1,     1,     3,     1,     1,     3,     4,     3,
       1,     1,     2,     2,     1,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     3,     3,     1,     3,     3,
       1,     3,     1,     3,     1,     1,     3,     1
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
    default: /* Avoid compiler warnings. */
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
        case 3:
#line 134 "./parser/parse.y" /* yacc.c:1648  */
    {std::cout << ast_to_string((yyval.tree), 0) << "\n"; exit(0);}
#line 1394 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 4:
#line 138 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(NUMBER, (yyvsp[0].name), 0);}
#line 1400 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 5:
#line 139 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(STRING, (yyvsp[0].name), 0);}
#line 1406 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 6:
#line 140 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(BOOL, (yyvsp[0].name), 0);}
#line 1412 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 7:
#line 141 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(VOID, (yyvsp[0].name), 0);}
#line 1418 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 8:
#line 145 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(BOOL_DEC, (yyvsp[0].name), 0);}
#line 1424 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 9:
#line 146 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(INT_DEC, (yyvsp[0].name), 0);}
#line 1430 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 10:
#line 150 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(GLOBAL_DEC, no_data, 1, (yyvsp[0].tree));}
#line 1436 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 11:
#line 151 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = (yyvsp[-1].tree);
                                                                     add_child((yyval.tree), (yyvsp[0].tree));
                                                                    }
#line 1444 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 15:
#line 163 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(VAR_DEC, no_data, 2, (yyvsp[-2].tree), (yyvsp[-1].tree));}
#line 1450 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 16:
#line 167 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(IDENTIFIER, (yyvsp[0].name), 0);}
#line 1456 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 17:
#line 171 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(MAIN_FUNC, no_data, 2, (yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1462 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 19:
#line 180 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(FUNC_DEC, no_data, 2, (yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1468 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 20:
#line 184 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(FUNC_HEAD, no_data, 2, (yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1474 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 21:
#line 188 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(FUNC_DECL, no_data, 2, (yyvsp[-3].tree), (yyvsp[-1].tree));}
#line 1480 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 24:
#line 194 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(PARAM_LIST, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1486 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 25:
#line 198 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(NO_TYPE, no_data, 2, (yyvsp[-1].tree), (yyvsp[0].tree));}
#line 1492 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 26:
#line 202 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(BLOCK, no_data, 1, (yyvsp[-1].tree));}
#line 1498 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 27:
#line 203 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(NO_TYPE, no_data, 0);}
#line 1504 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 28:
#line 207 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(BLOCK_STATE, no_data, 1, (yyvsp[0].tree));}
#line 1510 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 29:
#line 208 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = (yyvsp[-1].tree);
                                                                      add_child((yyval.tree), (yyvsp[0].tree));
                                                                     }
#line 1518 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 33:
#line 220 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(NO_TYPE, no_data, 0);}
#line 1524 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 34:
#line 221 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = (yyvsp[-1].tree);}
#line 1530 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 35:
#line 222 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(BREAK, (yyvsp[-1].name), 0);}
#line 1536 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 36:
#line 223 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(BREAK, (yyvsp[-2].name), 1, (yyvsp[-1].tree));}
#line 1542 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 37:
#line 224 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(RETURN, (yyvsp[-1].name), 0);}
#line 1548 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 38:
#line 225 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(IF, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1554 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 39:
#line 226 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(ELSE, no_data, 3, (yyvsp[-4].tree), (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1560 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 40:
#line 227 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(WHILE, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1566 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 44:
#line 237 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = (yyvsp[-1].tree);}
#line 1572 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 47:
#line 243 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(ARG_LIST, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1578 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 48:
#line 247 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(FUNC_INVOKE, no_data, 2, (yyvsp[-3].tree), (yyvsp[-1].tree));}
#line 1584 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 49:
#line 248 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(FUNC_INVOKE, no_data, 1, (yyvsp[-2].tree));}
#line 1590 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 52:
#line 257 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(NEG, no_data, 1, (yyvsp[0].tree));}
#line 1596 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 53:
#line 258 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(NOT, no_data, 1, (yyvsp[0].tree));}
#line 1602 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 56:
#line 264 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(MULT, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1608 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 57:
#line 265 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(DIV, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1614 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 58:
#line 266 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(MOD, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1620 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 60:
#line 271 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(ADD, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1626 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 61:
#line 272 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(SUB, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1632 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 63:
#line 277 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(LT, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1638 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 64:
#line 278 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(GT, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1644 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 65:
#line 279 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(LTE, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1650 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 66:
#line 280 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(GTE, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1656 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 68:
#line 285 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(EQ, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1662 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 69:
#line 286 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(NEQ, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1668 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 71:
#line 290 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(AND, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1674 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 73:
#line 295 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(OR, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1680 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;

  case 76:
#line 304 "./parser/parse.y" /* yacc.c:1648  */
    {(yyval.tree) = make_new_node(ASSIGNMENT, no_data, 2, (yyvsp[-2].tree), (yyvsp[0].tree));}
#line 1686 "./parser/parse.tab.c" /* yacc.c:1648  */
    break;


#line 1690 "./parser/parse.tab.c" /* yacc.c:1648  */
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
#line 310 "./parser/parse.y" /* yacc.c:1907  */


void yyerror(const char *s)
{
  fprintf (stderr, "line no: %i   %s\n", yylineno, s);
  exit(-1);
}
