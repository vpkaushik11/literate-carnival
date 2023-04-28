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
#line 1 "parser2.y"

    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    void yyerror(const char *s);
    int yylex();
    int yywrap();
    void add(char);
    void insert_type();
    int search(char *);
	void insert_type();
	void print_tree(struct node*);
	void print_inorder(struct node *);
    void check_declaration(char *);
	void check_return_type(char *);
	int check_types(char *, char *);
	char *get_type(char *);
	struct node* mknode(struct node *left, struct node *right, char *token);

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
	} symbol_table[40];

    int count=0;
    int q;
	char type[10];
    extern int countn;
	struct node *head;
	int sem_errors=0;
	int ic_idx=0;
	int temp_var=0;
	int label=0;
	int is_while =0;
	char buff[100];
	char errors[10][100];
	char reserved[11][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include", "while"};
	char icg[50][100];

	struct node { 
		struct node *left; 
		struct node *right; 
		char *token; 
	};


#line 122 "y.tab.c"

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
    PRINTFF = 260,                 /* PRINTFF  */
    SCANFF = 261,                  /* SCANFF  */
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
#define PRINTFF 260
#define SCANFF 261
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
#line 52 "parser2.y"
 struct var_name { 
			char name[100]; 
			struct node* nd;
		} nd_obj;

		struct var_name2 { 
			char name[100]; 
			struct node* nd;
			char type[5];
		} nd_obj2; 

		struct var_name3 {
			char name[100];
			struct node* nd;
			char if_body[5];
			char else_body[5];
		} nd_obj3;
	

#line 261 "y.tab.c"

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
  YYSYMBOL_PRINTFF = 5,                    /* PRINTFF  */
  YYSYMBOL_SCANFF = 6,                     /* SCANFF  */
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
  YYSYMBOL_39_ = 39,                       /* ','  */
  YYSYMBOL_40_ = 40,                       /* '&'  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_headers = 44,                   /* headers  */
  YYSYMBOL_45_1 = 45,                      /* $@1  */
  YYSYMBOL_main = 46,                      /* main  */
  YYSYMBOL_datatype = 47,                  /* datatype  */
  YYSYMBOL_body = 48,                      /* body  */
  YYSYMBOL_49_2 = 49,                      /* $@2  */
  YYSYMBOL_50_3 = 50,                      /* $@3  */
  YYSYMBOL_51_4 = 51,                      /* $@4  */
  YYSYMBOL_52_5 = 52,                      /* $@5  */
  YYSYMBOL_53_6 = 53,                      /* $@6  */
  YYSYMBOL_54_7 = 54,                      /* $@7  */
  YYSYMBOL_else = 55,                      /* else  */
  YYSYMBOL_56_8 = 56,                      /* $@8  */
  YYSYMBOL_condition = 57,                 /* condition  */
  YYSYMBOL_statement = 58,                 /* statement  */
  YYSYMBOL_59_9 = 59,                      /* $@9  */
  YYSYMBOL_60_10 = 60,                     /* $@10  */
  YYSYMBOL_61_11 = 61,                     /* $@11  */
  YYSYMBOL_62_12 = 62,                     /* $@12  */
  YYSYMBOL_init = 63,                      /* init  */
  YYSYMBOL_expression = 64,                /* expression  */
  YYSYMBOL_arithmetic = 65,                /* arithmetic  */
  YYSYMBOL_relop = 66,                     /* relop  */
  YYSYMBOL_value = 67,                     /* value  */
  YYSYMBOL_return = 68,                    /* return  */
  YYSYMBOL_69_13 = 69                      /* $@13  */
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  28
/* YYNRULES -- Number of rules.  */
#define YYNRULES  59
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  105

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
       2,     2,     2,     2,     2,     2,     2,     2,    40,     2,
      34,    35,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
       2,    41,     2,     2,     2,     2,     2,     2,     2,     2,
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
       0,    78,    78,    83,    84,    84,    87,    90,    91,    92,
      93,    96,    96,   110,   110,   111,   110,   117,   118,   119,
     119,   120,   120,   123,   123,   124,   127,   140,   141,   142,
     145,   145,   179,   179,   221,   221,   222,   222,   233,   248,
     249,   252,   293,   296,   297,   298,   299,   302,   303,   304,
     305,   306,   307,   310,   311,   312,   313,   316,   316,   317
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
  "PRINTFF", "SCANFF", "INT", "FLOAT", "CHAR", "WHILE", "IF", "ELSE",
  "TRUE", "FALSE", "NUM", "FLOAT_NUM", "ID", "LE", "GE", "EQ", "NE", "GT",
  "LT", "AND", "OR", "STR", "ADD", "MUL", "DIV", "SUB", "UNARY", "INCLUDE",
  "RETURN", "'('", "')'", "'{'", "'}'", "';'", "','", "'&'", "'='",
  "$accept", "program", "headers", "$@1", "main", "datatype", "body",
  "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "else", "$@8", "condition",
  "statement", "$@9", "$@10", "$@11", "$@12", "init", "expression",
  "arithmetic", "relop", "value", "return", "$@13", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-49)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-37)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
     -22,   -49,    30,    70,   -49,   -49,   -49,   -49,   -49,   -49,
     -22,    -3,    15,    -1,   -49,     0,    86,   -49,   -49,   -49,
     -49,    -4,    21,    23,    57,     3,    10,    12,    35,    37,
       2,   100,    41,   -49,   -49,   -49,    86,    43,   -49,    56,
      58,    94,    94,     9,   -49,   -49,   -49,   -49,   -49,   -49,
       9,   -49,    42,     9,   -49,    50,    48,   -49,   -49,   -49,
     -49,   -49,   -49,    64,   100,    65,    29,   -49,    29,     9,
     -49,    63,    66,    72,    69,     9,   -49,   -49,   -49,   -49,
     -49,     9,   -49,   -49,   -49,    89,    86,   -49,    77,    29,
      79,    -2,    86,    78,   -49,    11,   -49,   -49,   103,   -49,
     -49,    88,    86,    44,   -49
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     4,     0,     0,     5,     1,    10,     7,     8,     9,
       3,     0,     0,     0,     6,     0,     0,    19,    21,    11,
      13,    34,     0,     0,    59,     0,     0,     0,     0,     0,
       0,     0,     0,    38,    30,    57,    18,     0,    17,     0,
       0,    29,    29,     0,    49,    50,    51,    52,    48,    47,
       0,    37,    40,     0,     2,     0,     0,    55,    27,    28,
      53,    54,    56,     0,     0,     0,    33,    42,    35,     0,
      31,     0,     0,     0,     0,     0,    14,    43,    45,    46,
      44,     0,    39,    58,    20,     0,     0,    26,     0,    41,
       0,     0,     0,     0,    12,     0,    22,    15,    25,    23,
      16,     0,     0,     0,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -49,   -49,   125,   -49,   -49,   123,   -16,   -49,   -49,   -49,
     -49,   -49,   -49,   -49,   -49,    85,   -49,   -49,   -49,   -49,
     -49,   -49,   -48,   -49,    67,   -30,   -49,   -49
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     2,    10,     4,    11,    23,    36,    28,    29,    88,
      98,    26,    27,   100,   101,    63,    25,    52,    30,    31,
      32,    70,    66,    81,    50,    67,    37,    53
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      24,     6,    68,    17,    18,     7,     8,     9,    19,    20,
       1,    64,    64,    57,     6,    21,    17,    18,     7,     8,
       9,    19,    20,    71,    60,    61,    62,   -36,    21,    22,
       5,    13,    14,    89,    15,    94,    16,   -32,    33,    82,
      34,    38,    22,    43,    39,    87,    40,     6,    97,    17,
      18,     7,     8,     9,    19,    20,    77,    78,    79,    80,
       6,    21,    17,    18,     7,     8,     9,    19,    20,    41,
      91,    42,    51,     6,    21,    22,    95,     7,     8,     9,
      54,   104,    55,    69,    56,    72,   103,    73,    22,     6,
      35,    17,    18,     7,     8,     9,    19,    20,    57,    74,
      76,    83,     1,    21,    84,    86,    90,    58,    59,    60,
      61,    62,    85,    92,    93,    99,    96,    22,    44,    45,
      46,    47,    48,    49,   102,     3,    12,    65,     0,     0,
       0,    75
};

static const yytype_int8 yycheck[] =
{
      16,     3,    50,     5,     6,     7,     8,     9,    10,    11,
      32,    41,    42,     4,     3,    17,     5,     6,     7,     8,
       9,    10,    11,    53,    15,    16,    17,    31,    17,    31,
       0,    34,    17,    81,    35,    37,    36,    41,    17,    69,
      17,    38,    31,    41,    34,    75,    34,     3,    37,     5,
       6,     7,     8,     9,    10,    11,    27,    28,    29,    30,
       3,    17,     5,     6,     7,     8,     9,    10,    11,    34,
      86,    34,    31,     3,    17,    31,    92,     7,     8,     9,
      37,    37,    26,    41,    26,    35,   102,    39,    31,     3,
      33,     5,     6,     7,     8,     9,    10,    11,     4,    35,
      35,    38,    32,    17,    38,    36,    17,    13,    14,    15,
      16,    17,    40,    36,    35,    12,    38,    31,    18,    19,
      20,    21,    22,    23,    36,     0,     3,    42,    -1,    -1,
      -1,    64
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    32,    43,    44,    45,     0,     3,     7,     8,     9,
      44,    46,    47,    34,    17,    35,    36,     5,     6,    10,
      11,    17,    31,    47,    48,    58,    53,    54,    49,    50,
      60,    61,    62,    17,    17,    33,    48,    68,    38,    34,
      34,    34,    34,    41,    18,    19,    20,    21,    22,    23,
      66,    31,    59,    69,    37,    26,    26,     4,    13,    14,
      15,    16,    17,    57,    67,    57,    64,    67,    64,    41,
      63,    67,    35,    39,    35,    66,    35,    27,    28,    29,
      30,    65,    67,    38,    38,    40,    36,    67,    51,    64,
      17,    48,    36,    35,    37,    48,    38,    37,    52,    12,
      55,    56,    36,    48,    37
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    45,    44,    46,    47,    47,    47,
      47,    49,    48,    50,    51,    52,    48,    48,    48,    53,
      48,    54,    48,    56,    55,    55,    57,    57,    57,    57,
      59,    58,    60,    58,    61,    58,    62,    58,    58,    63,
      63,    64,    64,    65,    65,    65,    65,    66,    66,    66,
      66,    66,    66,    67,    67,    67,    67,    69,    68,    68
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     8,     2,     0,     2,     2,     1,     1,     1,
       1,     0,     8,     0,     0,     0,    11,     2,     2,     0,
       6,     0,     9,     0,     5,     0,     3,     1,     1,     0,
       0,     4,     0,     4,     0,     4,     0,     3,     2,     2,
       0,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     0,     4,     0
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
#line 78 "parser2.y"
                                                  { (yyvsp[-6].nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[-1].nd_obj).nd, "main"); (yyval.nd_obj).nd = mknode((yyvsp[-7].nd_obj).nd, (yyvsp[-6].nd_obj).nd, "program"); 
	head = (yyval.nd_obj).nd;
}
#line 1382 "y.tab.c"
    break;

  case 3: /* headers: headers headers  */
#line 83 "parser2.y"
                         { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "headers"); }
#line 1388 "y.tab.c"
    break;

  case 4: /* $@1: %empty  */
#line 84 "parser2.y"
          { add('H'); }
#line 1394 "y.tab.c"
    break;

  case 5: /* headers: INCLUDE $@1  */
#line 84 "parser2.y"
                        { (yyval.nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name); }
#line 1400 "y.tab.c"
    break;

  case 6: /* main: datatype ID  */
#line 87 "parser2.y"
                  { add('F'); }
#line 1406 "y.tab.c"
    break;

  case 7: /* datatype: INT  */
#line 90 "parser2.y"
              { insert_type(); }
#line 1412 "y.tab.c"
    break;

  case 8: /* datatype: FLOAT  */
#line 91 "parser2.y"
        { insert_type(); }
#line 1418 "y.tab.c"
    break;

  case 9: /* datatype: CHAR  */
#line 92 "parser2.y"
       { insert_type(); }
#line 1424 "y.tab.c"
    break;

  case 10: /* datatype: VOID  */
#line 93 "parser2.y"
       { insert_type(); }
#line 1430 "y.tab.c"
    break;

  case 11: /* $@2: %empty  */
#line 96 "parser2.y"
            { add('K'); is_while = 1; }
#line 1436 "y.tab.c"
    break;

  case 12: /* body: WHILE $@2 '(' condition ')' '{' body '}'  */
#line 96 "parser2.y"
                                                                      { 
    // condition = 4, body is 7
    // FOR { add('K'); is_for = 1; } '(' statement ';' condition ';' statement ')' '{' body '}' { 
    // body is 11, st1 is 4,  st2 is 8, cond is 6
	// struct node *temp = mknode($6.nd, $8.nd, "CONDITION"); 
	// struct node *temp2 = mknode($4.nd, temp, "CONDITION"); 
    struct node *whi = ((yyvsp[-4].nd_obj3).nd, (yyvsp[-1].nd_obj).nd, (yyvsp[-7].nd_obj).name)
	// $$.nd = mknode(temp2, $11.nd, $1.name); 
	(yyval.nd_obj).nd = mknode(whi, (yyvsp[-1].nd_obj).nd, "WHILE"); 
	
    sprintf(icg[ic_idx++], buff);
	sprintf(icg[ic_idx++], "JUMP to %s\n", (yyvsp[-4].nd_obj3).if_body);
	sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-4].nd_obj3).else_body);
}
#line 1455 "y.tab.c"
    break;

  case 13: /* $@3: %empty  */
#line 110 "parser2.y"
     { add('K'); is_while = 0; }
#line 1461 "y.tab.c"
    break;

  case 14: /* $@4: %empty  */
#line 110 "parser2.y"
                                                   { sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-1].nd_obj3).if_body); }
#line 1467 "y.tab.c"
    break;

  case 15: /* $@5: %empty  */
#line 111 "parser2.y"
    { sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyvsp[-5].nd_obj3).else_body); }
#line 1473 "y.tab.c"
    break;

  case 16: /* body: IF $@3 '(' condition ')' $@4 '{' body '}' $@5 else  */
#line 112 "parser2.y"
         { 
	    struct node *iff = mknode((yyvsp[-7].nd_obj3).nd, (yyvsp[-3].nd_obj).nd, (yyvsp[-10].nd_obj).name); 
	    (yyval.nd_obj).nd = mknode(iff, (yyvsp[0].nd_obj).nd, "if-else"); 
	    sprintf(icg[ic_idx++], "GOTO next\n");
    }
#line 1483 "y.tab.c"
    break;

  case 17: /* body: statement ';'  */
#line 117 "parser2.y"
                { (yyval.nd_obj).nd = (yyvsp[-1].nd_obj).nd; }
#line 1489 "y.tab.c"
    break;

  case 18: /* body: body body  */
#line 118 "parser2.y"
            { (yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "statements"); }
#line 1495 "y.tab.c"
    break;

  case 19: /* $@6: %empty  */
#line 119 "parser2.y"
          { add('K'); }
#line 1501 "y.tab.c"
    break;

  case 20: /* body: PRINTFF $@6 '(' STR ')' ';'  */
#line 119 "parser2.y"
                                        { (yyval.nd_obj).nd = mknode(NULL, NULL, "printf"); }
#line 1507 "y.tab.c"
    break;

  case 21: /* $@7: %empty  */
#line 120 "parser2.y"
         { add('K'); }
#line 1513 "y.tab.c"
    break;

  case 22: /* body: SCANFF $@7 '(' STR ',' '&' ID ')' ';'  */
#line 120 "parser2.y"
                                                  { (yyval.nd_obj).nd = mknode(NULL, NULL, "scanf"); }
#line 1519 "y.tab.c"
    break;

  case 23: /* $@8: %empty  */
#line 123 "parser2.y"
           { add('K'); }
#line 1525 "y.tab.c"
    break;

  case 24: /* else: ELSE $@8 '{' body '}'  */
#line 123 "parser2.y"
                                      { (yyval.nd_obj).nd = mknode(NULL, (yyvsp[-1].nd_obj).nd, (yyvsp[-4].nd_obj).name); }
#line 1531 "y.tab.c"
    break;

  case 25: /* else: %empty  */
#line 124 "parser2.y"
  { (yyval.nd_obj).nd = NULL; }
#line 1537 "y.tab.c"
    break;

  case 26: /* condition: value relop value  */
#line 127 "parser2.y"
                             { 
	(yyval.nd_obj3).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
	if(is_while) {
		sprintf((yyval.nd_obj3).if_body, "L%d", label++);
		sprintf(icg[ic_idx++], "\nLABEL %s:\n", (yyval.nd_obj3).if_body);
		sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name, label);
		sprintf((yyval.nd_obj3).else_body, "L%d", label++);
	} else {
		sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name, label, label+1);
		sprintf((yyval.nd_obj3).if_body, "L%d", label++);
		sprintf((yyval.nd_obj3).else_body, "L%d", label++);
	}
}
#line 1555 "y.tab.c"
    break;

  case 27: /* condition: TRUE  */
#line 140 "parser2.y"
       { add('K'); (yyval.nd_obj3).nd = NULL; }
#line 1561 "y.tab.c"
    break;

  case 28: /* condition: FALSE  */
#line 141 "parser2.y"
        { add('K'); (yyval.nd_obj3).nd = NULL; }
#line 1567 "y.tab.c"
    break;

  case 29: /* condition: %empty  */
#line 142 "parser2.y"
  { (yyval.nd_obj3).nd = NULL; }
#line 1573 "y.tab.c"
    break;

  case 30: /* $@9: %empty  */
#line 145 "parser2.y"
                       { add('V'); }
#line 1579 "y.tab.c"
    break;

  case 31: /* statement: datatype ID $@9 init  */
#line 145 "parser2.y"
                                          { 
	(yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
	int t = check_types((yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).type); 
	if(t>0) { 
		if(t == 1) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "floattoint"); 
			(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration"); 
		} 
		else if(t == 2) { 
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inttofloat"); 
			(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration"); 
		} 
		else if(t == 3) { 
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartoint"); 
			(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration"); 
		} 
		else if(t == 4) { 
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inttochar"); 
			(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration"); 
		} 
		else if(t == 5) { 
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartofloat"); 
			(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration"); 
		} 
		else{
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "floattochar"); 
			(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, temp, "declaration"); 
		}
	} 
	else { 
		(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "declaration"); 
	} 
	sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[-2].nd_obj).name, (yyvsp[0].nd_obj2).name);
}
#line 1618 "y.tab.c"
    break;

  case 32: /* $@10: %empty  */
#line 179 "parser2.y"
     { check_declaration((yyvsp[0].nd_obj).name); }
#line 1624 "y.tab.c"
    break;

  case 33: /* statement: ID $@10 '=' expression  */
#line 179 "parser2.y"
                                                    {
	(yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name); 
	char *id_type = get_type((yyvsp[-3].nd_obj).name); 
	if(strcmp(id_type, (yyvsp[0].nd_obj2).type)) {
		if(!strcmp(id_type, "int")) {
			if(!strcmp((yyvsp[0].nd_obj2).type, "float")){
				struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "floattoint");
				(yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
			}
			else{
				struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartoint");
				(yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
			}
			
		}
		else if(!strcmp(id_type, "float")) {
			if(!strcmp((yyvsp[0].nd_obj2).type, "int")){
				struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inttofloat");
				(yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
			}
			else{
				struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartofloat");
				(yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
			}
			
		}
		else{
			if(!strcmp((yyvsp[0].nd_obj2).type, "int")){
				struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inttochar");
				(yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
			}
			else{
				struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "floattochar");
				(yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, temp, "="); 
			}
		}
	}
	else {
		(yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, "="); 
	}
	sprintf(icg[ic_idx++], "%s = %s\n", (yyvsp[-3].nd_obj).name, (yyvsp[0].nd_obj2).name);
}
#line 1671 "y.tab.c"
    break;

  case 34: /* $@11: %empty  */
#line 221 "parser2.y"
     { check_declaration((yyvsp[0].nd_obj).name); }
#line 1677 "y.tab.c"
    break;

  case 35: /* statement: ID $@11 relop expression  */
#line 221 "parser2.y"
                                                      { (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-3].nd_obj).name); (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); }
#line 1683 "y.tab.c"
    break;

  case 36: /* $@12: %empty  */
#line 222 "parser2.y"
     { check_declaration((yyvsp[0].nd_obj).name); }
#line 1689 "y.tab.c"
    break;

  case 37: /* statement: ID $@12 UNARY  */
#line 222 "parser2.y"
                                           { 
	(yyvsp[-2].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-2].nd_obj).name); 
	(yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
	(yyval.nd_obj).nd = mknode((yyvsp[-2].nd_obj).nd, (yyvsp[0].nd_obj).nd, "ITERATOR");  
	if(!strcmp((yyvsp[0].nd_obj).name, "++")) {
		sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[-2].nd_obj).name, (yyvsp[-2].nd_obj).name, temp_var++);
	}
	else {
		sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[-2].nd_obj).name, (yyvsp[-2].nd_obj).name, temp_var++);
	}
}
#line 1705 "y.tab.c"
    break;

  case 38: /* statement: UNARY ID  */
#line 233 "parser2.y"
           { 
	check_declaration((yyvsp[0].nd_obj).name); 
	(yyvsp[-1].nd_obj).nd = mknode(NULL, NULL, (yyvsp[-1].nd_obj).name); 
	(yyvsp[0].nd_obj).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); 
	(yyval.nd_obj).nd = mknode((yyvsp[-1].nd_obj).nd, (yyvsp[0].nd_obj).nd, "ITERATOR"); 
	if(!strcmp((yyvsp[-1].nd_obj).name, "++")) {
		sprintf(buff, "t%d = %s + 1\n%s = t%d\n", temp_var, (yyvsp[0].nd_obj).name, (yyvsp[0].nd_obj).name, temp_var++);
	}
	else {
		sprintf(buff, "t%d = %s - 1\n%s = t%d\n", temp_var, (yyvsp[0].nd_obj).name, (yyvsp[0].nd_obj).name, temp_var++);

	}
}
#line 1723 "y.tab.c"
    break;

  case 39: /* init: '=' value  */
#line 248 "parser2.y"
                { (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; sprintf((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type); strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name); }
#line 1729 "y.tab.c"
    break;

  case 40: /* init: %empty  */
#line 249 "parser2.y"
  { sprintf((yyval.nd_obj2).type, "null"); (yyval.nd_obj2).nd = mknode(NULL, NULL, "NULL"); strcpy((yyval.nd_obj2).name, "NULL"); }
#line 1735 "y.tab.c"
    break;

  case 41: /* expression: expression arithmetic expression  */
#line 252 "parser2.y"
                                             { 
	if(!strcmp((yyvsp[-2].nd_obj2).type, (yyvsp[0].nd_obj2).type)) {
		sprintf((yyval.nd_obj2).type, (yyvsp[-2].nd_obj2).type);
		(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name); 
	}
	else {
		if(!strcmp((yyvsp[-2].nd_obj2).type, "int") && !strcmp((yyvsp[0].nd_obj2).type, "float")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "inttofloat");
			sprintf((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "float") && !strcmp((yyvsp[0].nd_obj2).type, "int")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "inttofloat");
			sprintf((yyval.nd_obj2).type, (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "int") && !strcmp((yyvsp[0].nd_obj2).type, "char")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartoint");
			sprintf((yyval.nd_obj2).type, (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "char") && !strcmp((yyvsp[0].nd_obj2).type, "int")) {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "chartoint");
			sprintf((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
		else if(!strcmp((yyvsp[-2].nd_obj2).type, "float") && !strcmp((yyvsp[0].nd_obj2).type, "char")) {
			struct node *temp = mknode(NULL, (yyvsp[0].nd_obj2).nd, "chartofloat");
			sprintf((yyval.nd_obj2).type, (yyvsp[-2].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode((yyvsp[-2].nd_obj2).nd, temp, (yyvsp[-1].nd_obj).name);
		}
		else {
			struct node *temp = mknode(NULL, (yyvsp[-2].nd_obj2).nd, "chartofloat");
			sprintf((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type);
			(yyval.nd_obj2).nd = mknode(temp, (yyvsp[0].nd_obj2).nd, (yyvsp[-1].nd_obj).name);
		}
	}
	sprintf((yyval.nd_obj2).name, "t%d", temp_var);
	temp_var++;
	sprintf(icg[ic_idx++], "%s = %s %s %s\n",  (yyval.nd_obj2).name, (yyvsp[-2].nd_obj2).name, (yyvsp[-1].nd_obj).name, (yyvsp[0].nd_obj2).name);
}
#line 1781 "y.tab.c"
    break;

  case 42: /* expression: value  */
#line 293 "parser2.y"
        { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj2).name); sprintf((yyval.nd_obj2).type, (yyvsp[0].nd_obj2).type); (yyval.nd_obj2).nd = (yyvsp[0].nd_obj2).nd; }
#line 1787 "y.tab.c"
    break;

  case 53: /* value: NUM  */
#line 310 "parser2.y"
           { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); sprintf((yyval.nd_obj2).type, "int"); add('C'); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 1793 "y.tab.c"
    break;

  case 54: /* value: FLOAT_NUM  */
#line 311 "parser2.y"
            { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); sprintf((yyval.nd_obj2).type, "float"); add('C'); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 1799 "y.tab.c"
    break;

  case 55: /* value: CHARACTER  */
#line 312 "parser2.y"
            { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); sprintf((yyval.nd_obj2).type, "char"); add('C'); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 1805 "y.tab.c"
    break;

  case 56: /* value: ID  */
#line 313 "parser2.y"
     { strcpy((yyval.nd_obj2).name, (yyvsp[0].nd_obj).name); char *id_type = get_type((yyvsp[0].nd_obj).name); sprintf((yyval.nd_obj2).type, id_type); check_declaration((yyvsp[0].nd_obj).name); (yyval.nd_obj2).nd = mknode(NULL, NULL, (yyvsp[0].nd_obj).name); }
#line 1811 "y.tab.c"
    break;

  case 57: /* $@13: %empty  */
#line 316 "parser2.y"
               { add('K'); }
#line 1817 "y.tab.c"
    break;

  case 58: /* return: RETURN $@13 value ';'  */
#line 316 "parser2.y"
                                       { check_return_type((yyvsp[-1].nd_obj2).name); (yyvsp[-3].nd_obj).nd = mknode(NULL, NULL, "return"); (yyval.nd_obj).nd = mknode((yyvsp[-3].nd_obj).nd, (yyvsp[-1].nd_obj2).nd, "RETURN"); }
#line 1823 "y.tab.c"
    break;

  case 59: /* return: %empty  */
#line 317 "parser2.y"
  { (yyval.nd_obj).nd = NULL; }
#line 1829 "y.tab.c"
    break;


#line 1833 "y.tab.c"

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

#line 320 "parser2.y"


int main() {
    yyparse();
    printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 1: LEXICAL ANALYSIS \n\n");
	printf("\nSYMBOL   DATATYPE   TYPE   LINE NUM \n");
	printf("_______________________________________\n\n");
	int i=0;
	for(i=0; i<count; i++) {
		printf("%s\t%s\t%s\t%d\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(i=0;i<count;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}
	printf("\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 2: SYNTAX ANALYSIS \n\n");
	print_tree(head); 
	printf("\n\n\n\n");
	printf("\t\t\t\t\t\t\t\t PHASE 3: SEMANTIC ANALYSIS \n\n");
	if(sem_errors>0) {
		printf("Semantic analysis completed with %d errors\n", sem_errors);
		for(int i=0; i<sem_errors; i++){
			printf("\t - %s", errors[i]);
		}
	} else {
		printf("Semantic analysis completed with no errors");
	}
	printf("\n\n");
	printf("\t\t\t\t\t\t\t   PHASE 4: INTERMEDIATE CODE GENERATION \n\n");
	for(int i=0; i<ic_idx; i++){
		printf("%s", icg[i]);
	}
	printf("\n\n");
}

int search(char *type) {
	int i;
	for(i=count-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, type)==0) {
			return -1;
			break;
		}
	}
	return 0;
}

void check_declaration(char *c) {
    q = search(c);
    if(!q) {
        sprintf(errors[sem_errors], "Line %d: Variable \"%s\" not declared before usage!\n", countn+1, c);
		sem_errors++;
    }
}

void check_return_type(char *value) {
	char *main_datatype = get_type("main");
	char *return_datatype = get_type(value);
	if((!strcmp(main_datatype, "int") && !strcmp(return_datatype, "CONST")) || !strcmp(main_datatype, return_datatype)){
		return ;
	}
	else {
		sprintf(errors[sem_errors], "Line %d: Return type mismatch\n", countn+1);
		sem_errors++;
	}
}

int check_types(char *type1, char *type2){
	// declaration with no init
	if(!strcmp(type2, "null"))
		return -1;
	// both datatypes are same
	if(!strcmp(type1, type2))
		return 0;
	// both datatypes are different
	if(!strcmp(type1, "int") && !strcmp(type2, "float"))
		return 1;
	if(!strcmp(type1, "float") && !strcmp(type2, "int"))
		return 2;
	if(!strcmp(type1, "int") && !strcmp(type2, "char"))
		return 3;
	if(!strcmp(type1, "char") && !strcmp(type2, "int"))
		return 4;
	if(!strcmp(type1, "float") && !strcmp(type2, "char"))
		return 5;
	if(!strcmp(type1, "char") && !strcmp(type2, "float"))
		return 6;
}

char *get_type(char *var){
	for(int i=0; i<count; i++) {
		// Handle case of use before declaration
		if(!strcmp(symbol_table[i].id_name, var)) {
			return symbol_table[i].data_type;
		}
	}
}

void add(char c) {
	if(c == 'V'){
		for(int i=0; i<10; i++){
			if(!strcmp(reserved[i], strdup(yytext))){
        		sprintf(errors[sem_errors], "Line %d: Variable name \"%s\" is a reserved keyword!\n", countn+1, yytext);
				sem_errors++;
				return;
			}
		}
	}
    q=search(yytext);
	if(!q) {
		if(c == 'H') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Header");
			count++;
		}
		else if(c == 'K') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("N/A");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Keyword\t");
			count++;
		}
		else if(c == 'V') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Variable");
			count++;
		}
		else if(c == 'C') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup("CONST");
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Constant");
			count++;
		}
		else if(c == 'F') {
			symbol_table[count].id_name=strdup(yytext);
			symbol_table[count].data_type=strdup(type);
			symbol_table[count].line_no=countn;
			symbol_table[count].type=strdup("Function");
			count++;
		}
    }
    else if(c == 'V' && q) {
        sprintf(errors[sem_errors], "Line %d: Multiple declarations of \"%s\" not allowed!\n", countn+1, yytext);
		sem_errors++;
    }
}

struct node* mknode(struct node *left, struct node *right, char *token) {	
	struct node *newnode = (struct node *)malloc(sizeof(struct node));
	char *newstr = (char *)malloc(strlen(token)+1);
	strcpy(newstr, token);
	newnode->left = left;
	newnode->right = right;
	newnode->token = newstr;
	return(newnode);
}

void print_tree(struct node* tree) {
	printf("\n\nInorder traversal of the Parse Tree is: \n\n");
	print_inorder(tree);
}

void print_inorder(struct node *tree) {
	int i;
	if (tree->left) {
		print_inorder(tree->left);
	}
	printf("%s, ", tree->token);
	if (tree->right) {
		print_inorder(tree->right);
	}
}

void insert_type() {
	strcpy(type, yytext);
}

void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
}
