/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    #include <queue>

    void yyerror(const char *s);
    int yylex();
    int yywrap();
    void add(char);
    void insert_type();
    int lookup(char *);
    struct node* makenode(struct node *left, struct node *right, char *token);
    void printInorder(struct node *);
    void check_declaration(char *);
	int check_types(char *, char *);
	char *get_type(char *);
    void printLevelOrder(struct node*);
    
    struct dataType {
        char * id_name;
        char * type;
        char * data_type;
        char  *scope;
        int size;
        int off;
        int line_no;
    } symbol_table[40];


    struct node {
        struct node *left;
        struct node *right;
        char *token;     
    };

    struct node *head;
    

    int ind=0;
    int offset=0;
    int exists;
    char type[10];
    extern int countn;
    int label=0;
    char errors[10][100];
    char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "while", "main", "return", "include"};
    int sem_errors=0;

    int icgind=0;
    int temp_var=0; 
    int is_while=0;
    char buffer[100];
    char icg[50][100];

#line 129 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    VOID = 258,                    /* VOID  */
    CHARACTER = 259,               /* CHARACTER  */
    PRINTF = 260,                  /* PRINTF  */
    SCANF = 261,                   /* SCANF  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    CHAR = 264,                    /* CHAR  */
    WHILE = 265,                   /* WHILE  */
    IF = 266,                      /* IF  */
    ELSE = 267,                    /* ELSE  */
    TRUE = 268,                    /* TRUE  */
    FALSE = 269,                   /* FALSE  */
    NUM = 270,                     /* NUM  */
    FLOAT_NUM = 271,               /* FLOAT_NUM  */
    ID = 272,                      /* ID  */
    LE = 273,                      /* LE  */
    GE = 274,                      /* GE  */
    EQ = 275,                      /* EQ  */
    NE = 276,                      /* NE  */
    GT = 277,                      /* GT  */
    LT = 278,                      /* LT  */
    AND = 279,                     /* AND  */
    OR = 280,                      /* OR  */
    STR = 281,                     /* STR  */
    ADD = 282,                     /* ADD  */
    MUL = 283,                     /* MUL  */
    DIV = 284,                     /* DIV  */
    SUB = 285,                     /* SUB  */
    UNARY = 286,                   /* UNARY  */
    INCLUDE = 287,                 /* INCLUDE  */
    RETURN = 288                   /* RETURN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define VOID 258
#define CHARACTER 259
#define PRINTF 260
#define SCANF 261
#define INT 262
#define FLOAT 263
#define CHAR 264
#define WHILE 265
#define IF 266
#define ELSE 267
#define TRUE 268
#define FALSE 269
#define NUM 270
#define FLOAT_NUM 271
#define ID 272
#define LE 273
#define GE 274
#define EQ 275
#define NE 276
#define GT 277
#define LT 278
#define AND 279
#define OR 280
#define STR 281
#define ADD 282
#define MUL 283
#define DIV 284
#define SUB 285
#define UNARY 286
#define INCLUDE 287
#define RETURN 288

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 59 "parser.y"

    struct var_name {
        char name[100];
        struct node* nd;
    } node_obj;
    struct var_name2 { 
		char name[100]; 
		struct node* nd;
		char type[10];
	} node_obj2;
    struct var_name3 {
		char name[100];
		struct node* nd;
		char if_body[5];
		char else_body[5];
	} node_obj3; 

#line 266 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_VOID = 3,                       /* VOID  */
  YYSYMBOL_CHARACTER = 4,                  /* CHARACTER  */
  YYSYMBOL_PRINTF = 5,                     /* PRINTF  */
  YYSYMBOL_SCANF = 6,                      /* SCANF  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_IF = 11,                        /* IF  */
  YYSYMBOL_ELSE = 12,                      /* ELSE  */
  YYSYMBOL_TRUE = 13,                      /* TRUE  */
  YYSYMBOL_FALSE = 14,                     /* FALSE  */
  YYSYMBOL_NUM = 15,                       /* NUM  */
  YYSYMBOL_FLOAT_NUM = 16,                 /* FLOAT_NUM  */
  YYSYMBOL_ID = 17,                        /* ID  */
  YYSYMBOL_LE = 18,                        /* LE  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_GT = 22,                        /* GT  */
  YYSYMBOL_LT = 23,                        /* LT  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_STR = 26,                       /* STR  */
  YYSYMBOL_ADD = 27,                       /* ADD  */
  YYSYMBOL_MUL = 28,                       /* MUL  */
  YYSYMBOL_DIV = 29,                       /* DIV  */
  YYSYMBOL_SUB = 30,                       /* SUB  */
  YYSYMBOL_UNARY = 31,                     /* UNARY  */
  YYSYMBOL_INCLUDE = 32,                   /* INCLUDE  */
  YYSYMBOL_RETURN = 33,                    /* RETURN  */
  YYSYMBOL_34_ = 34,                       /* '('  */
  YYSYMBOL_35_ = 35,                       /* ')'  */
  YYSYMBOL_36_ = 36,                       /* '{'  */
  YYSYMBOL_37_ = 37,                       /* '}'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '='  */
  YYSYMBOL_40_ = 40,                       /* ','  */
  YYSYMBOL_41_ = 41,                       /* '&'  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_headers = 44,                   /* headers  */
  YYSYMBOL_main = 45,                      /* main  */
  YYSYMBOL_datatype = 46,                  /* datatype  */
  YYSYMBOL_body = 47,                      /* body  */
  YYSYMBOL_48_1 = 48,                      /* $@1  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_condition = 52,                 /* condition  */
  YYSYMBOL_statement = 53,                 /* statement  */
  YYSYMBOL_54_5 = 54,                      /* $@5  */
  YYSYMBOL_55_6 = 55,                      /* $@6  */
  YYSYMBOL_56_7 = 56,                      /* $@7  */
  YYSYMBOL_57_8 = 57,                      /* $@8  */
  YYSYMBOL_58_9 = 58,                      /* $@9  */
  YYSYMBOL_59_10 = 59,                     /* $@10  */
  YYSYMBOL_else = 60,                      /* else  */
  YYSYMBOL_61_11 = 61,                     /* $@11  */
  YYSYMBOL_relop = 62,                     /* relop  */
  YYSYMBOL_init = 63,                      /* init  */
  YYSYMBOL_64_12 = 64,                     /* $@12  */
  YYSYMBOL_65_13 = 65,                     /* $@13  */
  YYSYMBOL_expression = 66,                /* expression  */
  YYSYMBOL_arithmetic = 67,                /* arithmetic  */
  YYSYMBOL_value = 68,                     /* value  */
  YYSYMBOL_return = 69,                    /* return  */
  YYSYMBOL_70_14 = 70                      /* $@14  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   288


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    41,     2,
      34,    35,     2,     2,    40,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    39,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    36,     2,    37,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    87,    87,    92,    93,    96,    99,   100,   101,   102,
     105,   106,   106,   109,   109,   109,   109,   112,   115,   127,
     139,   140,   141,   144,   144,   176,   176,   216,   216,   218,
     218,   227,   238,   238,   239,   239,   242,   242,   243,   246,
     247,   248,   249,   250,   251,   254,   254,   289,   289,   324,
     327,   332,   372,   377,   378,   379,   380,   383,   385,   387,
     389,   395,   395,   397
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "VOID", "CHARACTER",
  "PRINTF", "SCANF", "INT", "FLOAT", "CHAR", "WHILE", "IF", "ELSE", "TRUE",
  "FALSE", "NUM", "FLOAT_NUM", "ID", "LE", "GE", "EQ", "NE", "GT", "LT",
  "AND", "OR", "STR", "ADD", "MUL", "DIV", "SUB", "UNARY", "INCLUDE",
  "RETURN", "'('", "')'", "'{'", "'}'", "';'", "'='", "','", "'&'",
  "$accept", "program", "headers", "main", "datatype", "body", "$@1",
  "$@2", "$@3", "$@4", "condition", "statement", "$@5", "$@6", "$@7",
  "$@8", "$@9", "$@10", "else", "$@11", "relop", "init", "$@12", "$@13",
  "expression", "arithmetic", "value", "return", "$@14", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-59)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-30)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -28,   -59,     6,    37,   -59,   -59,   -59,   -59,   -59,   -28,
      -4,     2,    -3,   -59,    -5,    96,   -59,   -59,   -59,   -59,
      -2,    19,    26,    67,     9,    28,    29,    30,    31,    27,
     123,    49,   -59,   -59,   -59,    96,    45,   -59,    42,    57,
     104,   104,     1,   -59,   -59,   -59,   -59,   -59,   -59,     1,
     -59,   -37,    70,   -59,    51,    48,   -59,   -59,   -59,   -59,
     -59,   -59,    54,   110,   -59,    55,    22,    22,     1,    74,
     -59,    56,   -59,    52,    59,   -59,   -59,   -59,   -59,     1,
       1,   -59,    69,   -59,   -59,    79,    96,    22,    22,    61,
      93,   -37,    76,     4,    96,   -59,   -59,   -59,   -59,    17,
     -37,   -59,   -59,   100,   -59,   -59,    78,    96,    50,   -59
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,     1,     9,     6,     7,     8,     3,
       0,     0,     0,     5,     0,     0,    32,    34,    11,    13,
      27,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    23,    61,    10,     0,    17,     0,     0,
      22,    22,     0,    41,    42,    43,    44,    40,    39,     0,
      30,    50,     0,     2,     0,     0,    59,    20,    21,    57,
      58,    60,     0,    19,    52,     0,    26,    28,     0,     0,
      24,     0,    33,     0,     0,    53,    55,    56,    54,     0,
       0,    14,    49,    45,    62,     0,     0,    18,    51,     0,
       0,    50,     0,     0,     0,    47,    46,    35,    12,     0,
      50,    15,    48,    38,    36,    16,     0,     0,     0,    37
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -59,   -59,   115,   -59,   113,   -15,   -59,   -59,   -59,   -59,
      81,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,
      60,   -58,   -59,   -59,   -41,   -59,    58,   -59,   -59
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,     9,    10,    22,    35,    27,    28,    89,   103,
      62,    24,    51,    29,    30,    31,    25,    26,   105,   106,
      49,    70,    91,   100,    63,    80,    64,    36,    52
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      23,    66,    68,    69,     1,    56,     4,     5,    67,    16,
      17,     6,     7,     8,    18,    19,    59,    60,    61,    13,
       5,    20,    16,    17,     6,     7,     8,    18,    19,   -29,
      12,    15,    14,    96,    20,    21,    32,   -25,    87,    88,
       5,    98,   102,    33,     6,     7,     8,    37,    21,    75,
      76,    77,    78,     5,   101,    16,    17,     6,     7,     8,
      18,    19,    38,    39,    40,    41,    42,    20,    54,     1,
       5,    93,    16,    17,     6,     7,     8,    18,    19,    99,
      50,    21,    53,    55,    20,    71,    72,   109,    73,    74,
      81,    83,   108,    85,    84,    86,    92,    94,    21,     5,
      34,    16,    17,     6,     7,     8,    18,    19,    56,    90,
      95,    97,   104,    20,   107,     3,    11,    57,    58,    59,
      60,    61,    65,    79,     0,     0,    82,    21,    43,    44,
      45,    46,    47,    48,     0,     0,     0,    75,    76,    77,
      78,    43,    44,    45,    46,    47,    48
};

static const yytype_int8 yycheck[] =
{
      15,    42,    39,    40,    32,     4,     0,     3,    49,     5,
       6,     7,     8,     9,    10,    11,    15,    16,    17,    17,
       3,    17,     5,     6,     7,     8,     9,    10,    11,    31,
      34,    36,    35,    91,    17,    31,    17,    39,    79,    80,
       3,    37,   100,    17,     7,     8,     9,    38,    31,    27,
      28,    29,    30,     3,    37,     5,     6,     7,     8,     9,
      10,    11,    34,    34,    34,    34,    39,    17,    26,    32,
       3,    86,     5,     6,     7,     8,     9,    10,    11,    94,
      31,    31,    37,    26,    17,    15,    35,    37,    40,    35,
      35,    17,   107,    41,    38,    36,    17,    36,    31,     3,
      33,     5,     6,     7,     8,     9,    10,    11,     4,    40,
      17,    35,    12,    17,    36,     0,     3,    13,    14,    15,
      16,    17,    41,    63,    -1,    -1,    68,    31,    18,    19,
      20,    21,    22,    23,    -1,    -1,    -1,    27,    28,    29,
      30,    18,    19,    20,    21,    22,    23
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    43,    44,     0,     3,     7,     8,     9,    44,
      45,    46,    34,    17,    35,    36,     5,     6,    10,    11,
      17,    31,    46,    47,    53,    58,    59,    48,    49,    55,
      56,    57,    17,    17,    33,    47,    69,    38,    34,    34,
      34,    34,    39,    18,    19,    20,    21,    22,    23,    62,
      31,    54,    70,    37,    26,    26,     4,    13,    14,    15,
      16,    17,    52,    66,    68,    52,    66,    66,    39,    40,
      63,    15,    35,    40,    35,    27,    28,    29,    30,    62,
      67,    35,    68,    17,    38,    41,    36,    66,    66,    50,
      40,    64,    17,    47,    36,    17,    63,    35,    37,    47,
      65,    37,    63,    51,    12,    60,    61,    36,    47,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    46,    46,    46,    46,
      47,    48,    47,    49,    50,    51,    47,    47,    52,    52,
      52,    52,    52,    54,    53,    55,    53,    56,    53,    57,
      53,    53,    58,    53,    59,    53,    61,    60,    60,    62,
      62,    62,    62,    62,    62,    64,    63,    65,    63,    63,
      63,    66,    66,    67,    67,    67,    67,    68,    68,    68,
      68,    70,    69,    69
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     1,     2,     1,     1,     1,     1,
       2,     0,     8,     0,     0,     0,    11,     2,     3,     1,
       1,     1,     0,     0,     4,     0,     4,     0,     4,     0,
       3,     2,     0,     5,     0,     8,     0,     5,     0,     1,
       1,     1,     1,     1,     1,     0,     4,     0,     6,     2,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 2: /* program: headers main '(' ')' '{' body return '}'  */
#line 87 "parser.y"
                                                            { (yyvsp[-6].node_obj).nd = makenode((yyvsp[-2].node_obj).nd, (yyvsp[-1].node_obj).nd, "main"); 
                                                            (yyval.node_obj).nd = makenode((yyvsp[-7].node_obj).nd, (yyvsp[-6].node_obj).nd, "program"); 
                                                            head = (yyval.node_obj).nd; }
#line 1393 "y.tab.c"
    break;

  case 3: /* headers: headers headers  */
#line 92 "parser.y"
                                                            { (yyval.node_obj).nd = makenode((yyvsp[-1].node_obj).nd, (yyvsp[0].node_obj).nd, "headers"); }
#line 1399 "y.tab.c"
    break;

  case 4: /* headers: INCLUDE  */
#line 93 "parser.y"
                                                            { (yyval.node_obj).nd = makenode(NULL, NULL, (yyvsp[0].node_obj).name); }
#line 1405 "y.tab.c"
    break;

  case 5: /* main: datatype ID  */
#line 96 "parser.y"
                            { add('F'); }
#line 1411 "y.tab.c"
    break;

  case 6: /* datatype: INT  */
#line 99 "parser.y"
                            { insert_type(); }
#line 1417 "y.tab.c"
    break;

  case 7: /* datatype: FLOAT  */
#line 100 "parser.y"
                            { insert_type(); }
#line 1423 "y.tab.c"
    break;

  case 8: /* datatype: CHAR  */
#line 101 "parser.y"
                            { insert_type(); }
#line 1429 "y.tab.c"
    break;

  case 9: /* datatype: VOID  */
#line 102 "parser.y"
                            { insert_type(); }
#line 1435 "y.tab.c"
    break;

  case 10: /* body: body body  */
#line 105 "parser.y"
                                                            { (yyval.node_obj).nd = makenode((yyvsp[-1].node_obj).nd, (yyvsp[0].node_obj).nd, "statements"); }
#line 1441 "y.tab.c"
    break;

  case 11: /* $@1: %empty  */
#line 106 "parser.y"
            { add('K'); is_while = 1; }
#line 1447 "y.tab.c"
    break;

  case 12: /* body: WHILE $@1 '(' condition ')' '{' body '}'  */
#line 106 "parser.y"
                                                                          { (yyval.node_obj).nd = makenode((yyvsp[-4].node_obj3).nd, (yyvsp[-1].node_obj).nd, "While");
                                                            sprintf(icg[icgind++], "GOTO %s\n", (yyvsp[-4].node_obj3).if_body);
                                                            sprintf(icg[icgind++], "\n%s:\n", (yyvsp[-4].node_obj3).else_body);}
#line 1455 "y.tab.c"
    break;

  case 13: /* $@2: %empty  */
#line 109 "parser.y"
          { add('K'); is_while = 0; }
#line 1461 "y.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 109 "parser.y"
                                                        { sprintf(icg[icgind++], "\n%s:\n", (yyvsp[-1].node_obj3).if_body); }
#line 1467 "y.tab.c"
    break;

  case 15: /* $@4: %empty  */
#line 109 "parser.y"
                                                                                                                        { sprintf(icg[icgind++], "GOTO Next\n\n%s:\n", (yyvsp[-5].node_obj3).else_body); }
#line 1473 "y.tab.c"
    break;

  case 16: /* body: IF $@2 '(' condition ')' $@3 '{' body '}' $@4 else  */
#line 110 "parser.y"
                                                            { struct node *iff = makenode((yyvsp[-7].node_obj3).nd, (yyvsp[-3].node_obj).nd, (yyvsp[-10].node_obj).name);  
                                                              (yyval.node_obj).nd = makenode(iff, (yyvsp[0].node_obj).nd, "if-else");}
#line 1480 "y.tab.c"
    break;

  case 17: /* body: statement ';'  */
#line 112 "parser.y"
                                                            { (yyval.node_obj).nd = (yyvsp[-1].node_obj).nd; }
#line 1486 "y.tab.c"
    break;

  case 18: /* condition: expression relop expression  */
#line 115 "parser.y"
                                                            { (yyval.node_obj3).nd = makenode((yyvsp[-2].node_obj2).nd, (yyvsp[0].node_obj2).nd, (yyvsp[-1].node_obj).name); 
                                                            if(is_while) {  
                                                                sprintf((yyval.node_obj3).if_body, "L%d", label++);  
                                                                sprintf(icg[icgind++], "\n%s:\n", (yyval.node_obj3).if_body);
                                                                sprintf(icg[icgind++], "if NOT (%s %s %s) GOTO L%d\n", (yyvsp[-2].node_obj2).name, (yyvsp[-1].node_obj).name, (yyvsp[0].node_obj2).name, label);  
                                                                sprintf((yyval.node_obj3).else_body, "L%d", label++); 
                                                            } 
                                                            else {  
                                                                sprintf(icg[icgind++], "if (%s %s %s) GOTO L%d\nGOTO L%d\n", (yyvsp[-2].node_obj2).name, (yyvsp[-1].node_obj).name, (yyvsp[0].node_obj2).name, label, label+1);
                                                                sprintf((yyval.node_obj3).if_body, "L%d", label++);  
                                                                sprintf((yyval.node_obj3).else_body, "L%d", label++); 
                                                            }}
#line 1503 "y.tab.c"
    break;

  case 19: /* condition: expression  */
#line 127 "parser.y"
                                                            { (yyval.node_obj3).nd = (yyvsp[0].node_obj2).nd;
                                                            if(is_while) {  
                                                                sprintf((yyval.node_obj3).if_body, "L%d", label++);  
                                                                sprintf(icg[icgind++], "\n%s:\n", (yyval.node_obj3).if_body);
                                                                sprintf(icg[icgind++], "if NOT (%s) GOTO L%d\n", (yyvsp[0].node_obj2).name,label);  
                                                                sprintf((yyval.node_obj3).else_body, "L%d", label++); 
                                                            } 
                                                            else {  
                                                                sprintf(icg[icgind++], "if (%s) GOTO L%d\nGOTO L%d\n", (yyvsp[0].node_obj2).name, label, label+1);
                                                                sprintf((yyval.node_obj3).if_body, "L%d", label++);  
                                                                sprintf((yyval.node_obj3).else_body, "L%d", label++); 
                                                            }}
#line 1520 "y.tab.c"
    break;

  case 20: /* condition: TRUE  */
#line 139 "parser.y"
                                                            { add('K'); (yyval.node_obj3).nd = NULL; }
#line 1526 "y.tab.c"
    break;

  case 21: /* condition: FALSE  */
#line 140 "parser.y"
                                                            { add('K'); (yyval.node_obj3).nd = NULL; }
#line 1532 "y.tab.c"
    break;

  case 22: /* condition: %empty  */
#line 141 "parser.y"
                                                            { (yyval.node_obj3).nd = NULL; }
#line 1538 "y.tab.c"
    break;

  case 23: /* $@5: %empty  */
#line 144 "parser.y"
                       { add('V'); }
#line 1544 "y.tab.c"
    break;

  case 24: /* statement: datatype ID $@5 init  */
#line 144 "parser.y"
                                                            {(yyvsp[-2].node_obj).nd = makenode(NULL, NULL, (yyvsp[-2].node_obj).name);  
                                                            int t = check_types((yyvsp[-3].node_obj).name, (yyvsp[0].node_obj2).type);
                                                            if(t>0) {   
                                                                if(t == 1) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "floattoint");
                                                                    (yyval.node_obj).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 2) {
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "inttofloat");
                                                                    (yyval.node_obj).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 3) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "chartoint");
                                                                    (yyval.node_obj).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 4) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "inttochar");
                                                                    (yyval.node_obj).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 5) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "chartofloat");
                                                                    (yyval.node_obj).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else {   
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "floattochar");
                                                                    (yyval.node_obj).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }
                                                            }
                                                            else {   
                                                                (yyval.node_obj).nd = makenode((yyvsp[-2].node_obj).nd, (yyvsp[0].node_obj2).nd, "declaration");  
                                                            }
                                                            sprintf(icg[icgind++], "%s = %s\n", (yyvsp[-2].node_obj).name, (yyvsp[0].node_obj2).name);}
#line 1581 "y.tab.c"
    break;

  case 25: /* $@6: %empty  */
#line 176 "parser.y"
             { check_declaration((yyvsp[0].node_obj).name); }
#line 1587 "y.tab.c"
    break;

  case 26: /* statement: ID $@6 '=' expression  */
#line 176 "parser.y"
                                                            { (yyvsp[-3].node_obj).nd = makenode(NULL, NULL, (yyvsp[-3].node_obj).name);
                                                            char *id_type = get_type((yyvsp[-3].node_obj).name);  
                                                            if(strcmp(id_type, (yyvsp[0].node_obj2).type)) {  
                                                                if(!strcmp(id_type, "int")) {   
                                                                    //declaration is int but intialization is float
                                                                    if(!strcmp((yyvsp[0].node_obj2).type, "float")) {    
                                                                        struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "floattoint");
                                                                        (yyval.node_obj).nd = makenode((yyvsp[-3].node_obj).nd, temp, "=");    
                                                                    }
                                                                    //declaration is int but intialization is char  
                                                                    else {    
                                                                        struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "chartoint");
                                                                        (yyval.node_obj).nd = makenode((yyvsp[-3].node_obj).nd, temp, "=");    
                                                                    }     
                                                                }  
                                                                else if(!strcmp(id_type, "float")) {   
                                                                    if(!strcmp((yyvsp[0].node_obj2).type, "int")) {    
                                                                        struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "inttofloat");
                                                                        (yyval.node_obj).nd = makenode((yyvsp[-3].node_obj).nd, temp, "=");    
                                                                    }   
                                                                    else {    
                                                                        struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "chartofloat");
                                                                        (yyval.node_obj).nd = makenode((yyvsp[-3].node_obj).nd, temp, "=");    
                                                                    }     
                                                                }  
                                                                else {   
                                                                    if(!strcmp((yyvsp[0].node_obj2).type, "int")) {    
                                                                        struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "inttochar");
                                                                        (yyval.node_obj).nd = makenode((yyvsp[-3].node_obj).nd, temp, "=");    
                                                                    }   
                                                                    else {    
                                                                        struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "floattochar");
                                                                        (yyval.node_obj).nd = makenode((yyvsp[-3].node_obj).nd, temp, "=");    
                                                                    }
                                                                } 
                                                            } 
                                                            else {  
                                                                (yyval.node_obj).nd = makenode((yyvsp[-3].node_obj).nd, (yyvsp[0].node_obj2).nd, "=");  
                                                            }
                                                            sprintf(icg[icgind++], "%s = %s\n", (yyvsp[-3].node_obj).name, (yyvsp[0].node_obj2).name);}
#line 1632 "y.tab.c"
    break;

  case 27: /* $@7: %empty  */
#line 216 "parser.y"
             { check_declaration((yyvsp[0].node_obj).name); }
#line 1638 "y.tab.c"
    break;

  case 28: /* statement: ID $@7 relop expression  */
#line 216 "parser.y"
                                                              { (yyvsp[-3].node_obj).nd = makenode(NULL, NULL, (yyvsp[-3].node_obj).name); 
                                                            (yyval.node_obj).nd = makenode((yyvsp[-3].node_obj).nd, (yyvsp[0].node_obj2).nd, (yyvsp[-1].node_obj).name); }
#line 1645 "y.tab.c"
    break;

  case 29: /* $@8: %empty  */
#line 218 "parser.y"
             { check_declaration((yyvsp[0].node_obj).name); }
#line 1651 "y.tab.c"
    break;

  case 30: /* statement: ID $@8 UNARY  */
#line 218 "parser.y"
                                                            { (yyvsp[-2].node_obj).nd = makenode(NULL, NULL, (yyvsp[-2].node_obj).name); 
                                                            (yyvsp[0].node_obj).nd = makenode(NULL, NULL, (yyvsp[0].node_obj).name); 
                                                            (yyval.node_obj).nd = makenode((yyvsp[-2].node_obj).nd, (yyvsp[0].node_obj).nd, "ITERATOR");
                                                            if(!strcmp((yyvsp[0].node_obj).name, "++")) {
                                                                sprintf(icg[icgind++], "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[-2].node_obj).name, (yyvsp[-2].node_obj).name, temp_var++);
                                                            }
                                                            else {
                                                                sprintf(icg[icgind++], "t%d = %s - 1\n%s = t%d\n", temp_var, (yyvsp[-2].node_obj).name, (yyvsp[-2].node_obj).name, temp_var++);
                                                            }}
#line 1665 "y.tab.c"
    break;

  case 31: /* statement: UNARY ID  */
#line 227 "parser.y"
                                                            { check_declaration((yyvsp[0].node_obj).name); 
                                                            (yyvsp[-1].node_obj).nd = makenode(NULL, NULL, (yyvsp[-1].node_obj).name); 
                                                            (yyvsp[0].node_obj).nd = makenode(NULL, NULL, (yyvsp[0].node_obj).name); 
                                                            (yyval.node_obj).nd = makenode((yyvsp[-1].node_obj).nd, (yyvsp[0].node_obj).nd, "ITERATOR"); 
                                                            if(!strcmp((yyvsp[-1].node_obj).name, "++")) {
                                                                sprintf(icg[icgind++], "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[0].node_obj).name, (yyvsp[0].node_obj).name, temp_var++);
                                                            }
                                                            else {
                                                                sprintf(icg[icgind++], "t%d = %s - 1\n%s = t%d\n", temp_var, (yyvsp[0].node_obj).name, (yyvsp[0].node_obj).name, temp_var++);

                                                            }}
#line 1681 "y.tab.c"
    break;

  case 32: /* $@9: %empty  */
#line 238 "parser.y"
                 { add('K'); }
#line 1687 "y.tab.c"
    break;

  case 33: /* statement: PRINTF $@9 '(' STR ')'  */
#line 238 "parser.y"
                                                            { (yyval.node_obj).nd = makenode(NULL, NULL, "printf"); }
#line 1693 "y.tab.c"
    break;

  case 34: /* $@10: %empty  */
#line 239 "parser.y"
                { add('K'); }
#line 1699 "y.tab.c"
    break;

  case 35: /* statement: SCANF $@10 '(' STR ',' '&' ID ')'  */
#line 239 "parser.y"
                                                            { (yyval.node_obj).nd = makenode(NULL, NULL, "scanf"); }
#line 1705 "y.tab.c"
    break;

  case 36: /* $@11: %empty  */
#line 242 "parser.y"
           { add('K'); }
#line 1711 "y.tab.c"
    break;

  case 37: /* else: ELSE $@11 '{' body '}'  */
#line 242 "parser.y"
                                                            { (yyval.node_obj).nd = makenode(NULL, (yyvsp[-1].node_obj).nd, (yyvsp[-4].node_obj).name);}
#line 1717 "y.tab.c"
    break;

  case 38: /* else: %empty  */
#line 243 "parser.y"
                                                            { (yyval.node_obj).nd = NULL; }
#line 1723 "y.tab.c"
    break;

  case 45: /* $@12: %empty  */
#line 254 "parser.y"
             { add('V'); }
#line 1729 "y.tab.c"
    break;

  case 46: /* init: ',' ID $@12 init  */
#line 254 "parser.y"
                                                            {sprintf((yyval.node_obj2).type, "null"); 
                                                            (yyval.node_obj2).nd = makenode(NULL, NULL, "NULL"); 
                                                            strcpy((yyval.node_obj2).name, "NULL");
                                                            (yyvsp[-2].node_obj).nd = makenode(NULL, NULL, (yyvsp[-2].node_obj).name);
                                                            int t = check_types(type, (yyvsp[0].node_obj2).type);
                                                            if(t>0) {   
                                                                if(t == 1) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "floattoint");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 2) {
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "inttofloat");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 3) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "chartoint");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 4) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "inttochar");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 5) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "chartofloat");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else {   
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "floattochar");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }
                                                            }
                                                            else {   
                                                                (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, (yyvsp[0].node_obj2).nd, "declaration");  
                                                            }
                                                            sprintf(icg[icgind++], "%s = %s\n", (yyvsp[-2].node_obj).name, (yyvsp[0].node_obj2).name);}
#line 1769 "y.tab.c"
    break;

  case 47: /* $@13: %empty  */
#line 289 "parser.y"
                       { add('V'); }
#line 1775 "y.tab.c"
    break;

  case 48: /* init: '=' value ',' ID $@13 init  */
#line 289 "parser.y"
                                                            {(yyval.node_obj2).nd = (yyvsp[-4].node_obj2).nd; 
                                                            sprintf((yyval.node_obj2).type, (yyvsp[-4].node_obj2).type); 
                                                            strcpy((yyval.node_obj2).name, (yyvsp[-4].node_obj2).name);
                                                            (yyvsp[-2].node_obj).nd = makenode(NULL, NULL, (yyvsp[-2].node_obj).name);
                                                            int t = check_types(type, (yyvsp[0].node_obj2).type);
                                                            if(t>0) {   
                                                                if(t == 1) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "floattoint");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 2) {
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "inttofloat");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 3) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "chartoint");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 4) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "inttochar");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 5) {    
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "chartofloat");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }   
                                                                else {   
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "floattochar");
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, temp, "declaration");   
                                                                }
                                                            }
                                                            else {   
                                                                (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj).nd, (yyvsp[0].node_obj2).nd, "declaration");  
                                                            }
                                                            sprintf(icg[icgind++], "%s = %s\n", (yyvsp[-2].node_obj).name, (yyvsp[0].node_obj2).name);}
#line 1815 "y.tab.c"
    break;

  case 49: /* init: '=' value  */
#line 324 "parser.y"
                                                            { (yyval.node_obj2).nd = (yyvsp[0].node_obj2).nd; 
                                                            sprintf((yyval.node_obj2).type, (yyvsp[0].node_obj2).type); 
                                                            strcpy((yyval.node_obj2).name, (yyvsp[0].node_obj2).name); }
#line 1823 "y.tab.c"
    break;

  case 50: /* init: %empty  */
#line 327 "parser.y"
                                                            { sprintf((yyval.node_obj2).type, "null"); 
                                                            (yyval.node_obj2).nd = makenode(NULL, NULL, "NULL"); 
                                                            strcpy((yyval.node_obj2).name, "NULL"); }
#line 1831 "y.tab.c"
    break;

  case 51: /* expression: expression arithmetic expression  */
#line 332 "parser.y"
                                                            { if(!strcmp((yyvsp[-2].node_obj2).type, (yyvsp[0].node_obj2).type)) {  
                                                                sprintf((yyval.node_obj2).type, (yyvsp[-2].node_obj2).type);  
                                                                (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj2).nd, (yyvsp[0].node_obj2).nd, (yyvsp[-1].node_obj).name);  
                                                            }
                                                            //Expr1 and expr2 are different types 
                                                            else {  
                                                                if(!strcmp((yyvsp[-2].node_obj2).type, "int") && !strcmp((yyvsp[0].node_obj2).type, "float")) {
                                                                    struct node *temp = makenode(NULL, (yyvsp[-2].node_obj2).nd, "inttofloat");
                                                                    sprintf((yyval.node_obj2).type, (yyvsp[0].node_obj2).type);   
                                                                    (yyval.node_obj2).nd = makenode(temp, (yyvsp[0].node_obj2).nd, (yyvsp[-1].node_obj).name);  
                                                                }  
                                                                else if(!strcmp((yyvsp[-2].node_obj2).type, "float") && !strcmp((yyvsp[0].node_obj2).type, "int")) {   
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "inttofloat");
                                                                    sprintf((yyval.node_obj2).type, (yyvsp[-2].node_obj2).type);   
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj2).nd, temp, (yyvsp[-1].node_obj).name);  
                                                                }  
                                                                else if(!strcmp((yyvsp[-2].node_obj2).type, "int") && !strcmp((yyvsp[0].node_obj2).type, "char")){   
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "chartoint");
                                                                    sprintf((yyval.node_obj2).type, (yyvsp[-2].node_obj2).type);   
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj2).nd, temp, (yyvsp[-1].node_obj).name);  
                                                                }  
                                                                else if(!strcmp((yyvsp[-2].node_obj2).type, "char") && !strcmp((yyvsp[0].node_obj2).type, "int")) {   
                                                                    struct node *temp = makenode(NULL, (yyvsp[-2].node_obj2).nd, "chartoint");
                                                                    sprintf((yyval.node_obj2).type, (yyvsp[0].node_obj2).type);   
                                                                    (yyval.node_obj2).nd = makenode(temp, (yyvsp[0].node_obj2).nd, (yyvsp[-1].node_obj).name);  
                                                                }  
                                                                else if(!strcmp((yyvsp[-2].node_obj2).type, "float") && !strcmp((yyvsp[0].node_obj2).type, "char")) {   
                                                                    struct node *temp = makenode(NULL, (yyvsp[0].node_obj2).nd, "chartofloat");
                                                                    sprintf((yyval.node_obj2).type, (yyvsp[-2].node_obj2).type);   
                                                                    (yyval.node_obj2).nd = makenode((yyvsp[-2].node_obj2).nd, temp, (yyvsp[-1].node_obj).name);  
                                                                }  
                                                                else {   
                                                                    struct node *temp = makenode(NULL, (yyvsp[-2].node_obj2).nd, "chartofloat");
                                                                    sprintf((yyval.node_obj2).type, (yyvsp[0].node_obj2).type);   
                                                                    (yyval.node_obj2).nd = makenode(temp, (yyvsp[0].node_obj2).nd, (yyvsp[-1].node_obj).name);  
                                                                } 
                                                            }
                                                            sprintf((yyval.node_obj2).name, "t%d", temp_var);
                                                            temp_var++;
                                                            sprintf(icg[icgind++], "%s = %s %s %s\n",  (yyval.node_obj2).name, (yyvsp[-2].node_obj2).name, (yyvsp[-1].node_obj).name, (yyvsp[0].node_obj2).name);}
#line 1876 "y.tab.c"
    break;

  case 52: /* expression: value  */
#line 372 "parser.y"
                                                            { strcpy((yyval.node_obj2).name, (yyvsp[0].node_obj2).name); 
                                                            sprintf((yyval.node_obj2).type, (yyvsp[0].node_obj2).type); 
                                                            (yyval.node_obj2).nd = (yyvsp[0].node_obj2).nd;}
#line 1884 "y.tab.c"
    break;

  case 57: /* value: NUM  */
#line 383 "parser.y"
                                                            {strcpy((yyval.node_obj2).name, (yyvsp[0].node_obj).name); sprintf((yyval.node_obj2).type, "int");
                                                            (yyval.node_obj2).nd = makenode(NULL, NULL, (yyvsp[0].node_obj).name);}
#line 1891 "y.tab.c"
    break;

  case 58: /* value: FLOAT_NUM  */
#line 385 "parser.y"
                                                            {(yyval.node_obj2).nd = makenode(NULL, NULL, (yyvsp[0].node_obj).name);
                                                            strcpy((yyval.node_obj2).name, (yyvsp[0].node_obj).name); sprintf((yyval.node_obj2).type, "float");}
#line 1898 "y.tab.c"
    break;

  case 59: /* value: CHARACTER  */
#line 387 "parser.y"
                                                            {(yyval.node_obj2).nd = makenode(NULL, NULL, (yyvsp[0].node_obj).name);
                                                            strcpy((yyval.node_obj2).name, (yyvsp[0].node_obj).name); sprintf((yyval.node_obj2).type, "char");}
#line 1905 "y.tab.c"
    break;

  case 60: /* value: ID  */
#line 389 "parser.y"
                                                            {strcpy((yyval.node_obj2).name, (yyvsp[0].node_obj).name); char *id_type = get_type((yyvsp[0].node_obj).name); 
                                                            sprintf((yyval.node_obj2).type, id_type); 
                                                            check_declaration((yyvsp[0].node_obj).name); 
                                                            (yyval.node_obj2).nd = makenode(NULL, NULL, (yyvsp[0].node_obj).name);}
#line 1914 "y.tab.c"
    break;

  case 61: /* $@14: %empty  */
#line 395 "parser.y"
               { add('K'); }
#line 1920 "y.tab.c"
    break;

  case 62: /* return: RETURN $@14 NUM ';'  */
#line 395 "parser.y"
                                                            {(yyvsp[-3].node_obj).nd = makenode(NULL, NULL, "return"); 
                                                            (yyval.node_obj).nd = makenode((yyvsp[-3].node_obj).nd, (yyvsp[-1].node_obj).nd, "RETURN"); }
#line 1927 "y.tab.c"
    break;

  case 63: /* return: %empty  */
#line 397 "parser.y"
                                                            { (yyval.node_obj).nd = NULL; }
#line 1933 "y.tab.c"
    break;


#line 1937 "y.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 400 "parser.y"

int main() {
    yyin=fopen("input.c","r");
    FILE *out = fopen("output.txt", "w");
    printf("\n");
    printf("_____________________________________________________________________________________________________________________\n");
    printf("\nPhase 1-Lexical Analyser:\n\n");
    yyparse();
    printf("Tokenization Succesful\n\n");
    printf("_____________________________________________________________________________________________________________________\n");
    printf("\nPhase 2-Syntax Analyser:\n\nParsing Successful.\nSymbol Table:\n");

    printf("\nSYMBOL\t\tTYPE\t\tDATATYPE\tSIZE\t\tOFFSET\t\tSCOPE\n");
	printf("______________________________________________________________________________________\n\n");
    int i;
	for(i=0; i<ind; i++) {
		printf("%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%s\t\t\n", symbol_table[i].id_name,symbol_table[i].type,symbol_table[i].data_type,symbol_table[i].size,symbol_table[i].off, symbol_table[i].scope);
	}
	for(int i=0;i<ind;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
    printf("\n\nSyntax Tree in Level Order:\n\n");
    printLevelOrder(head);
    printf("\n___________________________________________________________________________________________________________________\n");
	printf("\nPhase 3-Semantic Analyser:\n\n");
    	if(sem_errors>0) {
		    printf("Semantic analysis completed with %d errors:\n", sem_errors);
		for(int i=0; i<sem_errors; i++){
			printf("  %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed with no errors");
	}
    printf("\n___________________________________________________________________________________________________________________\n");
    printf("\nPhase 4-Intermediate Code Generator:\n\n");
    printf("Three address code succesfully generated:\n\n");
	for(int i=0; i<icgind; i++){
		printf("%s", icg[i]);
        fprintf(out, "%s", icg[i]);
	}
    printf("\n___________________________________________________________________________________________________________________\n");
	printf("\n\n");
    return 0;
}
void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(0);
}

void insert_type() {
    strcpy(type, yytext);
}

void add(char c) {
  if(c == 'V') {  
    for(int i=0; i<10; i++) {   
        if(!strcmp(reserved[i], strdup(yytext))) {
            sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a keyword.\n", countn+1, yytext);
            sem_errors++;    
            return;
        }  
    } 
  }
  exists=lookup(yytext);
  if(!exists){
        if(c == 'H') {
            symbol_table[ind].id_name=strdup(yytext);            
            symbol_table[ind].line_no=countn;
            symbol_table[ind].data_type=strdup(type);         
            symbol_table[ind].type=strdup("Header");
            symbol_table[ind].size=1;
            symbol_table[ind].off=offset;
            offset+=symbol_table[ind].size;
            symbol_table[ind].scope=strdup("local");
            ind++;  
        }  
        else if(c == 'K') {
            symbol_table[ind].id_name=strdup(yytext);
            symbol_table[ind].line_no=countn;
            symbol_table[ind].data_type=strdup("-");     
            symbol_table[ind].type=strdup("Keyword"); 
            symbol_table[ind].size=1;
            symbol_table[ind].off=offset; 
            offset+=symbol_table[ind].size;
            symbol_table[ind].scope=strdup("local"); 
            ind++;  
        }  
        else if(c == 'V') {
            symbol_table[ind].id_name=strdup(yytext);
            symbol_table[ind].line_no=countn;
            symbol_table[ind].data_type=strdup(type);     
            symbol_table[ind].type=strdup("Var");   
            if(strcmp(type,"int")==0){
                symbol_table[ind].size=2;
            }
            else if(strcmp(type,"float")==0){
                symbol_table[ind].size=4;
            }
            else {
                symbol_table[ind].size=1;
            }
            symbol_table[ind].off=offset;
            offset+=symbol_table[ind].size;
            symbol_table[ind].scope=strdup("local");
            ind++;  
        }  
        else if(c == 'C') {
            //Only considering integer constants
            symbol_table[ind].id_name=strdup(yytext);
            symbol_table[ind].line_no=countn;
            symbol_table[ind].data_type=strdup("CONST");     
            symbol_table[ind].type=strdup("Constant");
            symbol_table[ind].size=2;
            symbol_table[ind].off=offset;
            offset+=symbol_table[ind].size;
            symbol_table[ind].scope=strdup("local");   
            ind++;  
        }  
        else if(c == 'F') {
            symbol_table[ind].id_name=strdup(yytext);
            symbol_table[ind].line_no=countn;
            symbol_table[ind].data_type=strdup(type);    
            symbol_table[ind].type=strdup("Func");
            symbol_table[ind].size=1;
            symbol_table[ind].off=offset;
            offset+=symbol_table[ind].size;
            symbol_table[ind].scope=strdup("local");   
            ind++;  
        }
    }
    else if(c == 'V' && exists) {
        sprintf(errors[sem_errors], "Line %d: Multiple declaration of variable \"%s\" not allowed!\n", countn+1, yytext);  
        sem_errors++;
    }
}

int lookup(char *id) {
	int i;
	for(i=ind-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, id)==0) {
            return 1;
		}
	}
	return 0;
}

struct node* makenode(struct node *left, struct node *right, char *token) {
  struct node *newnode = (struct node*) malloc(sizeof(struct node));
  char *newstr = (char*) malloc(strlen(token)+1);
  strcpy(newstr, token);
  newnode->left = left;
  newnode->right = right;
  newnode->token = newstr;
  return(newnode);
}

void printInorder(struct node *curr) {
    if (curr->left) {
        printInorder(curr->left); 
    } 
    printf("%s, ", curr->token); 
    if (curr->right) {  
        printInorder(curr->right); 
    }
}

void printLevelOrder(struct node* root) {
    if (root == NULL){
        return;
    }
    std::queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            struct node* curr = q.front();
            q.pop();
            printf("%s ",curr->token);
            if (curr->left != NULL){
                q.push(curr->left);
            }
            if (curr->right != NULL){
                q.push(curr->right);
            }
        }
       printf("\n");
    }
}

void check_declaration(char *c) {    
    exists = lookup(c);    
    if(!exists) {        
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" has not been declared.\n", countn+1, c);  
        sem_errors++;    
    }
}

int check_types(char *type1, char *type2) { 
    // declaration with no init 
    if(!strcmp(type2, "null")) return -1; 
    // both datatypes are same 
    if(!strcmp(type1, type2)) return 0; 
    // both datatypes are different 
    if(!strcmp(type1, "int") && !strcmp(type2, "float")) return 1;
    if(!strcmp(type1, "float") && !strcmp(type2, "int")) return 2;
    if(!strcmp(type1, "int") && !strcmp(type2, "char")) return 3;
    if(!strcmp(type1, "char") && !strcmp(type2, "int")) return 4;
    if(!strcmp(type1, "float") && !strcmp(type2, "char")) return 5;
    if(!strcmp(type1, "char") && !strcmp(type2, "float")) return 6;
}

char *get_type(char *var) { 
    for(int i=0; i<ind; i++) {  
        if(!strcmp(symbol_table[i].id_name, var)) {   
            return symbol_table[i].data_type;  
        }
    }
    return NULL;
}
