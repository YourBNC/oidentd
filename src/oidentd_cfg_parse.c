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
#line 1 "oidentd_cfg_parse.y" /* yacc.c:339  */

/*
** oidentd_cfg_parse.y - oidentd configuration parser.
** Copyright (C) 2001-2006 Ryan McCabe <ryan@numb.org>
**
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License, version 2,
** as published by the Free Software Foundation.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA
**
*/

#include <config.h>

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <syslog.h>
#include <pwd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <oidentd.h>
#include <oidentd_util.h>
#include <oidentd_missing.h>
#include <oidentd_inet_util.h>
#include <oidentd_user_db.h>
#include <oidentd_options.h>

extern struct user_info *default_user;
extern u_int32_t current_line;
extern int parser_mode;

static FILE *open_user_config(const struct passwd *pw);
static int extract_port_range(const char *token, struct port_range *range);
static void free_cap_entries(struct user_cap *free_cap);
static void yyerror(const char *err);

static struct user_info *cur_user;
static struct user_cap *cur_cap;
list_t *pref_list;

u_int16_t default_caps;


#line 126 "oidentd_cfg_parse.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "oidentd_cfg_parse.h".  */
#ifndef YY_YY_OIDENTD_CFG_PARSE_H_INCLUDED
# define YY_YY_OIDENTD_CFG_PARSE_H_INCLUDED
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
    TOK_USER = 258,
    TOK_DEFAULT = 259,
    TOK_GLOBAL = 260,
    TOK_FROM = 261,
    TOK_TO = 262,
    TOK_FPORT = 263,
    TOK_LPORT = 264,
    TOK_FORCE = 265,
    TOK_REPLY = 266,
    TOK_REQUEST = 267,
    TOK_ALLOWDENY = 268,
    TOK_CAP = 269,
    TOK_STRING = 270
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 61 "oidentd_cfg_parse.y" /* yacc.c:355  */

	int value;
	char *string;

#line 187 "oidentd_cfg_parse.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_OIDENTD_CFG_PARSE_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 204 "oidentd_cfg_parse.c" /* yacc.c:358  */

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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   92

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  18
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  51
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  93

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   270

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
       2,     2,     2,    16,     2,    17,     2,     2,     2,     2,
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
      15
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    82,    82,    85,    89,    91,    91,   106,   108,   112,
     112,   124,   124,   157,   159,   163,   163,   172,   177,   179,
     181,   185,   187,   189,   193,   195,   197,   201,   220,   237,
     256,   273,   275,   279,   287,   295,   303,   314,   319,   321,
     323,   334,   336,   338,   340,   344,   351,   361,   368,   379,
     389,   391
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TOK_USER", "TOK_DEFAULT", "TOK_GLOBAL",
  "TOK_FROM", "TOK_TO", "TOK_FPORT", "TOK_LPORT", "TOK_FORCE", "TOK_REPLY",
  "TOK_REQUEST", "TOK_ALLOWDENY", "TOK_CAP", "TOK_STRING", "'{'", "'}'",
  "$accept", "program", "parse_global", "$@1", "user_rule",
  "default_statement", "$@2", "user_statement", "$@3", "target_rule",
  "target_statement", "$@4", "range_rule", "src_rule", "dest_rule",
  "to_statement", "fport_statement", "from_statement", "lport_statement",
  "cap_rule", "force_reply", "force_request", "cap_statement",
  "user_range_rule", "user_reply", "user_request", "user_cap_rule", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   123,   125
};
# endif

#define YYPACT_NINF -72

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-72)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -72,    50,   -72,    -4,   -72,   -72,    40,   -72,   -72,   -72,
     -72,    -3,    -2,    19,    36,    37,    42,    45,     1,    21,
     -72,    54,   -72,   -72,    49,   -72,    44,   -72,   -72,   -72,
     -72,    44,    44,    51,   -72,   -72,   -72,    47,   -72,    35,
      53,    55,   -72,    56,    57,    52,    58,    59,    44,    60,
     -72,   -72,    62,   -72,    63,     6,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,    64,   -72,    25,    25,    25,    66,   -72,
      48,    69,    13,    65,    70,   -72,    14,    15,    25,    71,
      72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,    23,
     -72,   -72,   -72
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       2,     5,     1,     0,     9,     3,     0,     4,     8,     7,
      11,     0,     0,     0,     0,     0,     0,     0,     0,    24,
      25,    21,    22,     6,     0,    15,     0,    29,    27,    28,
      30,     0,     0,     0,    26,    23,    15,    15,    13,     0,
       0,     0,    49,    50,    51,     0,     0,     0,     0,    15,
      10,    14,     0,    16,     0,     0,    45,    47,    46,    48,
      41,    43,    42,     0,    12,     0,     0,     0,     0,    44,
       0,     0,     0,    38,    39,    31,     0,     0,     0,     0,
       0,    37,    40,    17,    32,    34,    36,    19,    18,     0,
      33,    35,    20
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,   -72,    30,
     -33,   -72,   -72,   -18,    34,   -72,    73,   -72,    67,   -58,
     -72,   -72,   -71,   -72,   -72,   -72,   -29
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     1,     5,     6,     7,     8,    11,     9,    24,    37,
      38,    39,    53,    17,    18,    19,    20,    21,    22,    72,
      73,    74,    75,    23,    43,    44,    45
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      33,    84,    46,    47,    51,    84,    84,    13,    76,    77,
      16,    10,    13,    25,    26,    16,    51,    32,    84,    63,
      89,    54,    67,    70,    70,    70,    71,    71,    71,    15,
      83,    87,    88,    70,    27,    70,    71,    68,    71,    52,
      92,    13,    14,    15,    16,    12,    13,    14,    15,    16,
       2,    28,    29,     3,     4,    40,    41,    30,    42,    79,
      80,    31,    81,    16,    50,    36,    49,    48,    56,    60,
      57,    58,    59,    55,     0,    61,    62,    64,    65,    66,
      85,    69,    78,    82,     0,    86,    90,    91,    35,     0,
       0,     0,    34
};

static const yytype_int8 yycheck[] =
{
      18,    72,    31,    32,    37,    76,    77,     6,    66,    67,
       9,    15,     6,    16,    16,     9,    49,    16,    89,    48,
      78,    39,    16,    10,    10,    10,    13,    13,    13,     8,
      17,    17,    17,    10,    15,    10,    13,    55,    13,     4,
      17,     6,     7,     8,     9,     5,     6,     7,     8,     9,
       0,    15,    15,     3,     4,    11,    12,    15,    14,    11,
      12,    16,    14,     9,    17,    16,    36,    16,    15,    17,
      15,    15,    15,    39,    -1,    17,    17,    17,    16,    16,
      15,    17,    16,    14,    -1,    15,    15,    15,    21,    -1,
      -1,    -1,    19
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    19,     0,     3,     4,    20,    21,    22,    23,    25,
      15,    24,     5,     6,     7,     8,     9,    31,    32,    33,
      34,    35,    36,    41,    26,    16,    16,    15,    15,    15,
      15,    16,    16,    31,    34,    36,    16,    27,    28,    29,
      11,    12,    14,    42,    43,    44,    44,    44,    16,    27,
      17,    28,     4,    30,    31,    32,    15,    15,    15,    15,
      17,    17,    17,    44,    17,    16,    16,    16,    31,    17,
      10,    13,    37,    38,    39,    40,    37,    37,    16,    11,
      12,    14,    14,    17,    40,    15,    15,    17,    17,    37,
      15,    15,    17
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    18,    19,    19,    20,    21,    20,    22,    22,    24,
      23,    26,    25,    27,    27,    29,    28,    30,    30,    30,
      30,    31,    31,    31,    32,    32,    32,    33,    34,    35,
      36,    37,    37,    38,    38,    39,    39,    40,    40,    40,
      40,    41,    41,    41,    41,    42,    42,    43,    43,    44,
      44,    44
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     1,     0,     2,     1,     1,     0,
       5,     0,     6,     1,     2,     0,     2,     4,     4,     4,
       5,     1,     1,     2,     1,     1,     2,     2,     2,     2,
       2,     1,     2,     3,     2,     3,     2,     2,     1,     1,
       2,     4,     4,     4,     5,     2,     2,     2,     2,     1,
       1,     1
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
#line 91 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		if (parser_mode != PARSE_USER) {
			o_log(NORMAL,
				"[line %d] This construct is valid only for user configuration files", current_line);
			YYABORT;
		}

		cur_cap = xcalloc(1, sizeof(struct user_cap));
		cur_cap->caps = default_caps;
	}
#line 1352 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 6:
#line 100 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		list_prepend(&pref_list, cur_cap);
	}
#line 1360 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 9:
#line 112 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		if (parser_mode != PARSE_SYSTEM)
			YYABORT;

		cur_user = xmalloc(sizeof(struct user_info));
		cur_user->cap_list = NULL;

		user_db_set_default(cur_user);
	}
#line 1374 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 11:
#line 124 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		if (parser_mode != PARSE_SYSTEM) {
			free((yyvsp[0].string));
			YYABORT;
		}

		cur_user = xmalloc(sizeof(struct user_info));
		cur_user->cap_list = NULL;

		if (find_user((yyvsp[0].string), &cur_user->user) == -1) {
			o_log(NORMAL, "[line %u] Invalid user: \"%s\"", current_line, (yyvsp[0].string));
			free((yyvsp[0].string));
			free_cap_entries(cur_cap);
			YYABORT;
		}

		if (user_db_lookup(cur_user->user) != NULL) {
			o_log(NORMAL,
				"[line %u] User \"%s\" already has a capability entry",
				current_line, (yyvsp[0].string));
			free((yyvsp[0].string));
			free_cap_entries(cur_cap);
			YYABORT;
		}

		free((yyvsp[0].string));
	}
#line 1406 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 12:
#line 151 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		user_db_add(cur_user);
	}
#line 1414 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 15:
#line 163 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap = xcalloc(1, sizeof(struct user_cap));
		cur_cap->caps = default_caps;
	}
#line 1423 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 16:
#line 166 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		list_prepend(&cur_user->cap_list, cur_cap);
	}
#line 1431 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 17:
#line 172 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		if (cur_user == default_user)
			default_caps = cur_cap->caps;
	}
#line 1440 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 27:
#line 201 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap->dest = xmalloc(sizeof(struct sockaddr_storage));

		if (get_addr((yyvsp[0].string), cur_cap->dest) == -1) {
			if (parser_mode == PARSE_SYSTEM) {
				o_log(NORMAL, "[line %u]: Bad address: \"%s\"",
					current_line, (yyvsp[0].string));
			}

			free((yyvsp[0].string));
			free_cap_entries(cur_cap);
			YYABORT;
		}

		free((yyvsp[0].string));
	}
#line 1461 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 28:
#line 220 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap->fport = xmalloc(sizeof(struct port_range));

		if (extract_port_range((yyvsp[0].string), cur_cap->fport) == -1) {
			if (parser_mode == PARSE_SYSTEM)
				o_log(NORMAL, "[line %u] Bad port: \"%s\"", current_line, (yyvsp[0].string));

			free((yyvsp[0].string));
			free_cap_entries(cur_cap);
			YYABORT;
		}

		free((yyvsp[0].string));
	}
#line 1480 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 29:
#line 237 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap->src = xmalloc(sizeof(struct sockaddr_storage));

		if (get_addr((yyvsp[0].string), cur_cap->src) == -1) {
			if (parser_mode == PARSE_SYSTEM) {
				o_log(NORMAL, "[line %u]: Bad address: \"%s\"",
					current_line, (yyvsp[0].string));
			}

			free((yyvsp[0].string));
			free_cap_entries(cur_cap);
			YYABORT;
		}

		free((yyvsp[0].string));
	}
#line 1501 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 30:
#line 256 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap->lport = xmalloc(sizeof(struct port_range));

		if (extract_port_range((yyvsp[0].string), cur_cap->lport) == -1) {
			if (parser_mode == PARSE_SYSTEM)
				o_log(NORMAL, "[line %u] Bad port: \"%s\"", current_line, (yyvsp[0].string));

			free((yyvsp[0].string));
			free_cap_entries(cur_cap);
			YYABORT;
		}

		free((yyvsp[0].string));
	}
#line 1520 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 33:
#line 279 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap->caps = CAP_REPLY;
		cur_cap->action = ACTION_FORCE;
		cur_cap->force_data = xrealloc(cur_cap->force_data,
			++cur_cap->num_replies * sizeof(u_char *));
		cur_cap->force_data[cur_cap->num_replies - 1] = (yyvsp[0].string);
	}
#line 1532 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 34:
#line 287 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap->force_data = xrealloc(cur_cap->force_data,
			++cur_cap->num_replies * sizeof(u_char *));
		cur_cap->force_data[cur_cap->num_replies - 1] = (yyvsp[0].string);
	}
#line 1542 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 35:
#line 295 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap->caps = CAP_REQUEST;
		cur_cap->action = ACTION_FORCE;
		cur_cap->force_data = xrealloc(cur_cap->request_data,
			++cur_cap->num_requests * sizeof(u_char *));
		cur_cap->request_data[cur_cap->num_requests - 1] = (yyvsp[0].string);
	}
#line 1554 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 36:
#line 303 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		if (cur_cap->num_requests < MAX_RANDOM_REPLIES) {
			cur_cap->request_data = xrealloc(cur_cap->request_data,
				++cur_cap->num_requests * sizeof(u_char *));
			cur_cap->request_data[cur_cap->num_requests - 1] = (yyvsp[0].string);
		}
	}
#line 1566 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 37:
#line 314 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap->caps = (yyvsp[0].value);
		cur_cap->action = ACTION_FORCE;
	}
#line 1575 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 40:
#line 323 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		if ((yyvsp[-1].value) == ACTION_ALLOW)
			cur_cap->caps |= (yyvsp[0].value);
		else
			cur_cap->caps &= ~(yyvsp[0].value);

		cur_cap->action = (yyvsp[-1].value);
	}
#line 1588 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 45:
#line 344 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap->caps = CAP_REPLY;
		cur_cap->force_data = xrealloc(cur_cap->force_data,
			++cur_cap->num_replies * sizeof(u_char *));
		cur_cap->force_data[cur_cap->num_replies - 1] = (yyvsp[0].string);
	}
#line 1599 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 46:
#line 351 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		if (cur_cap->num_replies < MAX_RANDOM_REPLIES) {
			cur_cap->force_data = xrealloc(cur_cap->force_data,
				++cur_cap->num_replies * sizeof(u_char *));
			cur_cap->force_data[cur_cap->num_replies - 1] = (yyvsp[0].string);
		}
	}
#line 1611 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 47:
#line 361 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		cur_cap->caps = CAP_REQUEST;
		cur_cap->force_data = xrealloc(cur_cap->request_data,
			++cur_cap->num_requests * sizeof(u_char *));
		cur_cap->request_data[cur_cap->num_requests - 1] = (yyvsp[0].string);
	}
#line 1622 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 48:
#line 368 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		if (cur_cap->num_requests < MAX_RANDOM_REPLIES) {
			cur_cap->request_data = xrealloc(cur_cap->request_data,
				++cur_cap->num_requests * sizeof(u_char *));
			cur_cap->request_data[cur_cap->num_requests - 1] = (yyvsp[0].string);
		}
	}
#line 1634 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;

  case 49:
#line 379 "oidentd_cfg_parse.y" /* yacc.c:1646  */
    {
		if ((yyvsp[0].value) == CAP_SPOOF || (yyvsp[0].value) == CAP_SPOOF_ALL || (yyvsp[0].value) == CAP_SPOOF_PRIVPORT)
		{
			free_cap_entries(cur_cap);
			YYABORT;
		}

		cur_cap->caps = (yyvsp[0].value);
	}
#line 1648 "oidentd_cfg_parse.c" /* yacc.c:1646  */
    break;


#line 1652 "oidentd_cfg_parse.c" /* yacc.c:1646  */
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
#line 394 "oidentd_cfg_parse.y" /* yacc.c:1906  */


/*
** Read in the system-wide configuration file.
*/

int read_config(const char *path) {
	FILE *fp;
	int ret;

	fp = fopen(path, "r");
	if (fp == NULL) {
		if (errno == ENOENT) {
			/*
			** If a configuration file is specified on the
			** command line, return an error if it can't be opened,
			** even if it doesn't exist.
			*/

			if (!strcmp(path, CONFFILE)) {
				struct user_info *temp_default;

				temp_default = user_db_create_default();
				user_db_set_default(temp_default);
				return (0);
			}
		}

		o_log(NORMAL, "Error opening config file: %s: %s",
			path, strerror(errno));
		return (-1);
	}

	yyrestart(fp);
	current_line = 1;
	parser_mode = PARSE_SYSTEM;
	ret = yyparse();

	fclose(fp);

	/*
	** Make sure there's a default to fall back on.
	*/

	if (default_user == NULL) {
		struct user_info *temp_default;

		temp_default = user_db_create_default();
		user_db_set_default(temp_default);
	}

	return (ret);
}

/*
** Open the user's ~/.oidentd_config file for reading
** by the parser.
*/

static FILE *open_user_config(const struct passwd *pw) {
	FILE *fp;

	fp = safe_open(pw, USER_CONF);
	if (fp == NULL)
		return (NULL);

	yyrestart(fp);
	current_line = 1;
	parser_mode = PARSE_USER;

	return (fp);
}

/*
** Read in a user's $HOME/.oidentd.conf file.
*/

list_t *user_db_get_pref_list(const struct passwd *pw) {
	FILE *fp;
	int ret;

	fp = open_user_config(pw);
	if (fp == NULL)
		return (NULL);

	cur_cap = NULL;
	pref_list = NULL;

	ret = yyparse();
	fclose(fp);

	if (ret != 0) {
		list_destroy(pref_list, user_db_cap_destroy_data);
		return (NULL);
	}

	return (pref_list);
}

static void yyerror(const char *err) {

	if (parser_mode == PARSE_USER)
		free_cap_entries(cur_cap);
	else
		o_log(NORMAL, "[line %u] %s", current_line, err);
}

/*
** Extract a port range from a token.
*/

static int extract_port_range(const char *token, struct port_range *range) {
	char *p;

	p = strchr(token, ':');
	if (p != NULL)
		*p++ = '\0';

	if (*token == '\0')
		range->min = PORT_MIN;
	else if (get_port(token, &range->min) == -1)
		return (-1);

	if (p == NULL)
		range->max = range->min;
	else {
		if (*p == '\0')
			range->max = PORT_MAX;
		else if (get_port(p, &range->max) == -1)
			return (-1);
	}

	return (0);
}

static void free_cap_entries(struct user_cap *free_cap) {
	user_db_cap_destroy_data(free_cap);

	if (free_cap != cur_cap)
		free(cur_cap);

	free(free_cap);
	free(cur_user);

	cur_cap = NULL;
	cur_user = NULL;
	pref_list = NULL;
}
