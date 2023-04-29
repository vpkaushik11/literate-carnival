%{
    #include "y.tab.h"
    int countn=0;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"

%%

"printf"                    { strcpy(yylval.node_obj.name,(yytext));return PRINTF; }
"scanf"                     { strcpy(yylval.node_obj.name,(yytext));return SCANF; }
"int"                       { strcpy(yylval.node_obj.name,(yytext));return INT; }
"float"                     { strcpy(yylval.node_obj.name,(yytext));return FLOAT; }
"char"                      { strcpy(yylval.node_obj.name,(yytext));return CHAR; }
"void"                      { strcpy(yylval.node_obj.name,(yytext));return VOID; }
"return"                    { strcpy(yylval.node_obj.name,(yytext));return RETURN; }
"while"	                    { strcpy(yylval.node_obj.name,(yytext));return WHILE; }
"if"	                    { strcpy(yylval.node_obj.name,(yytext));return IF; }
"else"	                    { strcpy(yylval.node_obj.name,(yytext));return ELSE; }
^"#include"[ ]*<.+\.h>      { strcpy(yylval.node_obj.name,(yytext));return INCLUDE; }
"true"                      { strcpy(yylval.node_obj.name,(yytext));return TRUE; }
"false"                     { strcpy(yylval.node_obj.name,(yytext));return FALSE; }
[-]?{digit}+                { strcpy(yylval.node_obj.name,(yytext));return NUM; }
[-]?{digit}+\.{digit}{1,6}  { strcpy(yylval.node_obj.name,(yytext));return FLOAT_NUM; }
{alpha}({alpha}|{digit})*   { strcpy(yylval.node_obj.name,(yytext));return ID; }
{unary}                     { strcpy(yylval.node_obj.name,(yytext));return UNARY; }
"<="                        { strcpy(yylval.node_obj.name,(yytext));return LE; }
">="                        { strcpy(yylval.node_obj.name,(yytext));return GE; }
"=="                        { strcpy(yylval.node_obj.name,(yytext));return EQ; }
"!="                        { strcpy(yylval.node_obj.name,(yytext));return NE; }
">"	                        { strcpy(yylval.node_obj.name,(yytext));return GT; }
"<"	                        { strcpy(yylval.node_obj.name,(yytext));return LT; }
"&&"	                    { strcpy(yylval.node_obj.name,(yytext));return AND; }
"||"	                    { strcpy(yylval.node_obj.name,(yytext));return OR; }
"+"                         { strcpy(yylval.node_obj.name,(yytext));return ADD; }
"-"                         { strcpy(yylval.node_obj.name,(yytext));return SUB; }
"/"                         { strcpy(yylval.node_obj.name,(yytext));return DIV; }
"*"                         { strcpy(yylval.node_obj.name,(yytext));return MUL; }
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
.	                        { return *yytext; }
["].*["]                    { strcpy(yylval.node_obj.name,(yytext));return STR; }
['].[']                     { strcpy(yylval.node_obj.name,(yytext));return CHAR; }

%%

int yywrap() {
    return 1;
}