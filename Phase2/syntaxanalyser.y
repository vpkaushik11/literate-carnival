%{
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
    int lookup(char *);

    struct dataType {
        char * id_name;
        char * data_type;
        char * type;
        int line_no;
    } symbol_table[40];

    int ind=0;
    int exists;
    char type[10];
    extern int countn;

%}

%token VOID CHARACTER PRINTF SCANF INT FLOAT CHAR WHILE IF ELSE TRUE FALSE NUM FLOAT_NUM ID LE GE EQ NE GT LT AND OR STR ADD MUL DIV SUB UNARY INCLUDE RETURN

%%

program: headers main '(' ')' '{' body return '}' 
       ;

headers: headers headers
        | INCLUDE           { add('H'); }
        ;

main: datatype ID           { add('F'); }
    ;

datatype: INT               { insert_type(); }
        | FLOAT             { insert_type(); }
        | CHAR              { insert_type(); }
        | VOID              { insert_type(); }
        ;

body: body body
    | WHILE { add('K'); } '(' condition ')' '{' body '}'
    | IF  { add('K'); } '(' condition ')' '{' body '}' else
    | statement ';'
    ;

condition: expression relop expression
        | expression
        | TRUE      { add('K'); }
        | FALSE     { add('K'); }
        ;

statement: datatype ID { add('V'); } init
        | ID '=' expression 
        | ID relop expression
        | ID UNARY 
        | UNARY ID
        | PRINTF { add('K'); } '(' STR ')'
        | SCANF { add('K'); } '(' STR ',' '&' ID ')'
        ;

else: ELSE { add('K'); } '{' body '}'
    |
    ;

relop: LT
    | GT
    | LE
    | GE
    | EQ
    | NE
    ;

init:  '=' value
    | 
    ;

expression: expression arithmetic expression
          | value
          ;

arithmetic: ADD
          | SUB
          | MUL
          | DIV
          ;

value: NUM          { add('C'); }
    | FLOAT_NUM     { add('C'); }
    | CHARACTER     { add('C'); }
    | ID
    ;

return: RETURN { add('K'); } value ';' 
|
;

%%
int main() {
    yyin=fopen("input.c","r");
    printf("\n");
    yyparse();
    printf("Syntax Analyser: Parsing Successful\n");

    printf("\nSYMBOL          DATATYPE          TYPE           LINE NUMBER \n");
	printf("_______________________________________\n\n");
    int i;
	for(i=0; i<ind; i++) {
		printf("%s\t\t%s\t\t%s\t\t%d\t\t\n", symbol_table[i].id_name, symbol_table[i].data_type, symbol_table[i].type, symbol_table[i].line_no);
	}
	for(int i=0;i<ind;i++) {
		free(symbol_table[i].id_name);
		free(symbol_table[i].type);
	}

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
  exists=lookup(yytext);
  if(!exists){
        if(c == 'H') {
            symbol_table[ind].id_name=strdup(yytext);        
            symbol_table[ind].data_type=strdup(type);     
            symbol_table[ind].line_no=countn;    
            symbol_table[ind].type=strdup("Header");
            ind++;  
        }  
        else if(c == 'K') {
            symbol_table[ind].id_name=strdup(yytext);
            symbol_table[ind].data_type=strdup("-");
            symbol_table[ind].line_no=countn;
            symbol_table[ind].type=strdup("Keyword\t");   
            ind++;  
        }  
        else if(c == 'V') {
            symbol_table[ind].id_name=strdup(yytext);
            symbol_table[ind].data_type=strdup(type);
            symbol_table[ind].line_no=countn;
            symbol_table[ind].type=strdup("Variable");   
            ind++;  
        }  
        else if(c == 'C') {
            symbol_table[ind].id_name=strdup(yytext);
            symbol_table[ind].data_type=strdup("CONST");
            symbol_table[ind].line_no=countn;
            symbol_table[ind].type=strdup("Constant");   
            ind++;  
        }  
        else if(c == 'F') {
            symbol_table[ind].id_name=strdup(yytext);
            symbol_table[ind].data_type=strdup(type);
            symbol_table[ind].line_no=countn;
            symbol_table[ind].type=strdup("Function");   
            ind++;  
        }
    }
}

int lookup(char *id) {
	int i;
	for(i=ind-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, id)==0) {
            printf("Parsing error: Rentry in Symbol Table - %s\n\n",id);
			exit(0);
		}
	}
	return 0;
}