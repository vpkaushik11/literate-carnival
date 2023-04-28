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
        char * type;
        char * data_type;
        char  *scope;
        int size;
        int off;
        int line_no;
    } symbol_table[40];

    int ind=0;
    int offset=0;
    int exists;
    char type[10];
    extern int countn;

    struct node *head;
	int sem_errors=0;
	int ic_idx=0;
	int temp_var=0;
	int label=0;
	int is_for=0;
	char buff[100];
	char errors[10][100];
	char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};
	char icg[50][100];

    struct node { 
		struct node *left; 
		struct node *right; 
		char *token; 
	};

%}

%union { struct var_name { 
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
	} 

%token VOID
%token <nd_obj> CHARACTER PRINTF SCANF INT FLOAT CHAR WHILE IF ELSE TRUE FALSE NUM FLOAT_NUM ID LE GE EQ NE GT LT AND OR STR ADD MUL DIV SUB UNARY INCLUDE RETURN
%type <nd_obj> headers main body return datatype statement arithmetic relop program else
%type <nd_obj2> init value expression
%type <nd_obj3> condition


%%

program: headers main '(' ')' '{' body return '}' { $2.nd = mknode($6.nd, $7.nd, "main"); $$.nd = mknode($1.nd, $2.nd, "program"); 
	    head = $$.nd;
    } 
    ;

headers: headers headers { $$.nd = mknode($1.nd, $2.nd, "headers"); }
        | INCLUDE { add('H'); } { $$.nd = mknode(NULL, NULL, $1.name); }
        ;

main: datatype ID           { add('F'); }
    ;

datatype: INT               { insert_type(); }
        | FLOAT             { insert_type(); }
        | CHAR              { insert_type(); }
        | VOID              { insert_type(); }
        ;

/* body: body body
    | WHILE { add('K'); is_for = 1;} '(' condition ')' '{' body '}'
    | IF  { add('K'); } '(' condition ')' '{' body '}' else
    | statement ';'
    ; */

body: WHILE { add('K'); is_for = 1;} '(' condition ')' '{' body '}' {
        struct node *temp = mknode($6.nd, $8.nd, "CONDITION"); 
	    struct node *temp2 = mknode($4.nd, temp, "CONDITION"); 
	    $$.nd = mknode(temp2, $11.nd, $1.name); 
	    sprintf(icg[ic_idx++], buff);
	    sprintf(icg[ic_idx++], "JUMP to %s\n", $6.if_body);
	    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $6.else_body);
    }
|   IF { add('K'); is_for = 0; } '(' condition ')' { sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.if_body); } '{' body '}' { 
        sprintf(icg[ic_idx++], "\nLABEL %s:\n", $4.else_body); 
    } 
    else { 
	    struct node *iff = mknode($4.nd, $8.nd, $1.name); 
	    $$.nd = mknode(iff, $11.nd, "if-else"); 
	    sprintf(icg[ic_idx++], "GOTO next\n");
    }
|   statement ';' { $$.nd = $1.nd; }
|   body body { $$.nd = mknode($1.nd, $2.nd, "statements"); }
|   PRINTF { add('K'); } '(' STR ')' ';' { $$.nd = mknode(NULL, NULL, "printf"); }
|   SCANF { add('K'); } '(' STR ',' '&' ID ')' ';' { $$.nd = mknode(NULL, NULL, "scanf"); }
    ;

/* condition: expression relop expression
        | expression
        | TRUE      { add('K'); }
        | FALSE     { add('K'); }
        ; */

condition: expression relop expression { 
	    $$.nd = mknode($1.nd, $3.nd, $2.name); 
	    if(is_for) {
		    sprintf($$.if_body, "L%d", label++);
		    sprintf(icg[ic_idx++], "\nLABEL %s:\n", $$.if_body);
		    sprintf(icg[ic_idx++], "\nif NOT (%s %s %s) GOTO L%d\n", $1.name, $2.name, $3.name, label);
		    sprintf($$.else_body, "L%d", label++);
	    } else {
		    sprintf(icg[ic_idx++], "\nif (%s %s %s) GOTO L%d else GOTO L%d\n", $1.name, $2.name, $3.name, label, label+1);
		    sprintf($$.if_body, "L%d", label++);
		    sprintf($$.else_body, "L%d", label++);
	    }
    }
    | expression
    | TRUE { add('K'); $$.nd = NULL; }
    | FALSE { add('K'); $$.nd = NULL; }
    | { $$.nd = NULL; }
    ;

statement: datatype ID { add('V'); } init
        | ID '=' expression 
        | ID relop expression
        | ID UNARY 
        | UNARY ID
        | PRINTF { add('K'); } '(' STR ')'
        | SCANF { add('K'); } '(' STR ',' '&' ID ')'
        ;

else: ELSE { add('K'); } '{' body '}' { $$.nd = mknode(NULL, $4.nd, $1.name); }
    | { $$.nd = NULL; }
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

value: NUM          
    | FLOAT_NUM     
    | CHARACTER     
    | ID
    ;

return: RETURN { add('K'); } NUM ';' 
|
;

%%
int main() {
    yyin=fopen("input.c","r");
    printf("\n");
    yyparse();
   printf("Syntax Analyser: Parsing Successful\n\nSymbol Table:\n");

    printf("\nSYMBOL\t\tSCOPE\t\tTYPE\t\tDATATYPE\tSIZE\t\tOFFSET\n");
	printf("______________________________________________________________________________________\n\n");
    int i;
	for(i=0; i<ind; i++) {
		printf("%s\t\t%s\t\t%s\t\t%d\t\t%d\t\t%s\t\t\n", symbol_table[i].id_name,symbol_table[i].type,symbol_table[i].data_type,symbol_table[i].size,symbol_table[i].off, symbol_table[i].scope);
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
            symbol_table[ind].data_type=strdup("-");     
            symbol_table[ind].type=strdup("Func");
            symbol_table[ind].size=1;
            symbol_table[ind].off=offset;
            offset+=symbol_table[ind].size;
            symbol_table[ind].scope=strdup("local");   
            ind++;  
        }
    }
}

int lookup(char *id) {
	int i;
	for(i=ind-1; i>=0; i--) {
		if(strcmp(symbol_table[i].id_name, id)==0) {
            printf("Parsing Error: Rentry in Symbol Table - %s\n\n",id);
			exit(0);
		}
	}
	return 0;
}