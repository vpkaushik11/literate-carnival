%{
    int countn=0;
%}

%option yylineno

alpha [a-zA-Z]
digit [0-9]
unary "++"|"--"
seperator [(){}|,;]

%%

"printf"                    { ECHO; printf(" :PRINTF\n"); }
"scanf"                     { ECHO; printf(" :SCANF\n"); }
"int"                       { ECHO; printf(" :INT\n"); }
"float"                     { ECHO; printf(" :FLOAT\n"); }
"char"                      { ECHO; printf(" :CHAR\n"); }
"void"                      { ECHO; printf(" :VOID\n"); }
"return"                    { ECHO; printf(" :RETURN\n"); }
"while"	                    { ECHO; printf(" :WHILE\n"); }
"if"	                    { ECHO; printf(" :IF\n"); }
"else"	                    { ECHO; printf(" :ELSE\n"); }
^"#include"[ ]*<.+\.h>      { ECHO; printf(" :INCLUDE\n"); }
"true"                      { ECHO; printf(" :TRUE\n"); }
"false"                     { ECHO; printf(" :FALSE\n"); }
[-]?{digit}+                { ECHO; printf(" :NUMBER\n"); }
{alpha}({alpha}|{digit})*   { ECHO; printf(" :ID\n"); }
{unary}                     { ECHO; printf(" :UNARY\n"); }
"<="                        { ECHO; printf(" :LE\n"); }
">="                        { ECHO; printf(" :GE\n"); }
"=="                        { ECHO; printf(" :EQ\n"); }
"!="                        { ECHO; printf(" :NE\n"); }
">"	                        { ECHO; printf(" :GT\n"); }
"<"	                        { ECHO; printf(" :LT\n"); }
"&&"	                    { ECHO; printf(" :AND\n"); }
"||"	                    { ECHO; printf(" :OR\n"); }
"+"                         { ECHO; printf(" :ADD\n"); }
"-"                         { ECHO; printf(" :SUB\n"); }
"/"                         { ECHO; printf(" :DIV\n"); }
"*"                         { ECHO; printf(" :MUL\n"); }
{seperator}                 { ECHO; printf(" :SEPERATOR\n"); }
\/\/.*                      { ; }
\/\*(.*\n)*.*\*\/           { ; } 
[ \t]*                      { ; }
[\n]                        { countn++; }
.	                        { ECHO; printf(" :ERROR\n"); }
["].*["]                    { ECHO; printf(" :STR\n"); }
['].[']                     { ECHO; printf(" :CHAR\n"); }

%%

int yywrap() {
    return 1;
}

int main(){
    yyin=fopen("input.c","r");
    printf("\n");
    yylex();
    printf("\nNo.of lines : %d\n\n",countn);
    return 0;
}