%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    
    void yyerror(const char *s);
    int yylex();
    int yywrap();
%}

%token VOID CHARACTER PRINTF SCANF INT FLOAT CHAR WHILE IF ELSE TRUE FALSE NUM FLOAT_NUM ID LE GE EQ NE GT LT AND OR STR ADD MUL DIV SUB UNARY INCLUDE RETURN

%%

program: headers main '(' ')' '{' body return '}' 
       ;

headers: INCLUDE headers
       | 
       ;

main: datatype ID
    ;

datatype: INT 
        | FLOAT 
        | CHAR
        | VOID
        ;

body: body body
    | WHILE '(' condition ')' '{' body '}'
    | IF '(' condition ')' '{' body '}' else
    | statement ';'
    ;

condition: expression relop expression
        | expression
        | TRUE 
        | FALSE
        ;

statement: datatype init ';'
        | ID '=' expression 
        | ID relop expression
        | ID UNARY 
        | UNARY ID
        | PRINTF '(' STR ')'
        | SCANF '(' STR ',' '&' ID ')'
        ;

else: ELSE '{' body '}'
    |
    ;

relop: LT
    | GT
    | LE
    | GE
    | EQ
    | NE
    ;

init: init ',' ID '=' value
    | init ',' ID 
    | ID '=' value
    | ID
    ;

expression: expression arithmetic expression
          | value
          ;

arithmetic: ADD
          | SUB
          | MUL
          | DIV
          ;

value: NUM
    | FLOAT_NUM
    | CHARACTER
    | ID
    ;

return: RETURN value ';' 
|
;

%%
int main() {
    yyin=fopen("input.c","r");
    yyparse();
    printf("Syntax Analyser: Parsing Successful\n");
    return 0;
}
void yyerror(const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(0);
}