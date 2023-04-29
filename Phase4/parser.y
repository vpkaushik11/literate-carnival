%{
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
    char reserved[10][10] = {"int", "float", "char", "void", "if", "else", "for", "main", "return", "include"};
    int sem_errors=0;

    int icgind=0;
    int temp_var=0; 
    int is_while=0;
    char buffer[100];
    char icg[50][100];
    int icgind=0;
    int temp_var=0; 
    int is_while=0;
    char buffer[100];
    char icg[50][100];
%}

%union{
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
}


%token VOID 
%token <node_obj> CHARACTER PRINTF SCANF INT FLOAT CHAR WHILE IF ELSE TRUE FALSE NUM FLOAT_NUM ID LE GE EQ NE GT LT AND OR STR ADD MUL DIV SUB UNARY INCLUDE RETURN

%type <node_obj> program headers main body return datatype statement arithmetic relop else 
%type <node_obj2> init value expression
%type <node_obj3> condition

%%

program: headers main '(' ')' '{' body return '}'           { $2.nd = makenode($6.nd, $7.nd, "main"); 
                                                            $$.nd = makenode($1.nd, $2.nd, "program"); 
                                                            head = $$.nd; } 
       ;

headers: headers headers                                    { $$.nd = makenode($1.nd, $2.nd, "headers"); }
        | INCLUDE                                           { $$.nd = makenode(NULL, NULL, $1.name); }  
        ;

main: datatype ID           { add('F'); }
    ;

datatype: INT               { insert_type(); }
        | FLOAT             { insert_type(); }
        | CHAR              { insert_type(); }
        | VOID              { insert_type(); }
        ;

body: body body                                             { $$.nd = makenode($1.nd, $2.nd, "statements"); }
    | WHILE { add('K'); is_while = 1; } '(' condition ')' '{' body '}'    { $$.nd = makenode($4.nd, $7.nd, "While");
                                                            sprintf(icg[icgind++], "goto %s\n", $4.if_body);
                                                            sprintf(icg[icgind++], "\n%s :\n", $4.else_body);}
    | IF  { add('K'); is_while = 0; } '(' condition ')' { sprintf(icg[icgind++], "\n%s :\n", $4.if_body); } '{' body '}' { sprintf(icg[icgind++], "goto Lz\n\n%s :\n", $4.else_body); } else   
                                                            { struct node *iff = makenode($4.nd, $8.nd, $1.name);  
                                                              $$.nd = makenode(iff, $11.nd, "if-else");} 
    | statement ';'                                         { $$.nd = $1.nd; }
    ;

condition: expression relop expression                      { $$.nd = makenode($1.nd, $3.nd, $2.name); 
                                                            if(is_while) {  
                                                                sprintf($$.if_body, "L%d", label++);  
                                                                sprintf(icg[icgind++], "\n%s :\n", $$.if_body);
                                                                sprintf(icg[icgind++], "if!(%s%s%s) goto L%d\n", $1.name, $2.name, $3.name, label);  
                                                                sprintf($$.else_body, "L%d", label++); 
                                                            } 
                                                            else {  
                                                                sprintf(icg[icgind++], "if(%s%s%s) goto L%d\ngoto L%d\n", $1.name, $2.name, $3.name, label, label+1);
                                                                sprintf($$.if_body, "L%d", label++);  
                                                                sprintf($$.else_body, "L%d", label++); 
                                                            }}
        | expression                                        { $$.nd = $1.nd;
                                                            if(is_while) {  
                                                                sprintf($$.if_body, "L%d", label++);  
                                                                sprintf(icg[icgind++], "\n%s :\n", $$.if_body);
                                                                sprintf(icg[icgind++], "if!(%s) goto L%d\n", $1.name,label);  
                                                                sprintf($$.else_body, "L%d", label++); 
                                                            } 
                                                            else {  
                                                                sprintf(icg[icgind++], "if(%s) goto L%d\ngoto L%d\n", $1.name, label, label+1);
                                                                sprintf($$.if_body, "L%d", label++);  
                                                                sprintf($$.else_body, "L%d", label++); 
                                                            }}
        | TRUE                                              { add('K'); $$.nd = NULL; }
        | FALSE                                             { add('K'); $$.nd = NULL; }
        |                                                   { $$.nd = NULL; }
        ;

statement: datatype ID { add('V'); } init                   {$2.nd = makenode(NULL, NULL, $2.name);  
                                                            int t = check_types($1.name, $4.type);
                                                            if(t>0) {   
                                                                if(t == 1) {    
                                                                    struct node *temp = makenode(NULL, $4.nd, "floattoint");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 2) {
                                                                    struct node *temp = makenode(NULL, $4.nd, "inttofloat");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 3) {    
                                                                    struct node *temp = makenode(NULL, $4.nd, "chartoint");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 4) {    
                                                                    struct node *temp = makenode(NULL, $4.nd, "inttochar");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 5) {    
                                                                    struct node *temp = makenode(NULL, $4.nd, "chartofloat");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }   
                                                                else {   
                                                                    struct node *temp = makenode(NULL, $4.nd, "floattochar");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }
                                                            }
                                                            else {   
                                                                $$.nd = makenode($2.nd, $4.nd, "declaration");  
                                                            }
                                                            sprintf(icg[icgind++], "%s = %s\n", $2.name, $4.name);}
        | ID { check_declaration($1.name); }'=' expression  { $1.nd = makenode(NULL, NULL, $1.name);
                                                            char *id_type = get_type($1.name);  
                                                            if(strcmp(id_type, $4.type)) {  
                                                                if(!strcmp(id_type, "int")) {   
                                                                    //declaration is int but intialization is float
                                                                    if(!strcmp($4.type, "float")) {    
                                                                        struct node *temp = makenode(NULL, $4.nd, "floattoint");
                                                                        $$.nd = makenode($1.nd, temp, "=");    
                                                                    }
                                                                    //declaration is int but intialization is char  
                                                                    else {    
                                                                        struct node *temp = makenode(NULL, $4.nd, "chartoint");
                                                                        $$.nd = makenode($1.nd, temp, "=");    
                                                                    }     
                                                                }  
                                                                else if(!strcmp(id_type, "float")) {   
                                                                    if(!strcmp($4.type, "int")) {    
                                                                        struct node *temp = makenode(NULL, $4.nd, "inttofloat");
                                                                        $$.nd = makenode($1.nd, temp, "=");    
                                                                    }   
                                                                    else {    
                                                                        struct node *temp = makenode(NULL, $4.nd, "chartofloat");
                                                                        $$.nd = makenode($1.nd, temp, "=");    
                                                                    }     
                                                                }  
                                                                else {   
                                                                    if(!strcmp($4.type, "int")) {    
                                                                        struct node *temp = makenode(NULL, $4.nd, "inttochar");
                                                                        $$.nd = makenode($1.nd, temp, "=");    
                                                                    }   
                                                                    else {    
                                                                        struct node *temp = makenode(NULL, $4.nd, "floattochar");
                                                                        $$.nd = makenode($1.nd, temp, "=");    
                                                                    }
                                                                } 
                                                            } 
                                                            else {  
                                                                $$.nd = makenode($1.nd, $4.nd, "=");  
                                                            }
                                                            sprintf(icg[icgind++], "%s = %s\n", $1.name, $4.name);}
        | ID { check_declaration($1.name); } relop expression { $1.nd = makenode(NULL, NULL, $1.name); 
                                                            $$.nd = makenode($1.nd, $4.nd, $3.name); }
        | ID { check_declaration($1.name); } UNARY          { $1.nd = makenode(NULL, NULL, $1.name); 
                                                            $3.nd = makenode(NULL, NULL, $3.name); 
                                                            $$.nd = makenode($1.nd, $3.nd, "ITERATOR");
                                                            if(!strcmp($3.name, "++")) {
                                                                sprintf(icg[icgind++], "t%d = %s + 1\n%s = t%d\n", temp_var, $1.name, $1.name, temp_var++);
                                                            }
                                                            else {
                                                                sprintf(icg[icgind++], "t%d = %s - 1\n%s = t%d\n", temp_var, $1.name, $1.name, temp_var++);
                                                            }}
        | UNARY ID                                          { check_declaration($2.name); 
                                                            $1.nd = makenode(NULL, NULL, $1.name); 
                                                            $2.nd = makenode(NULL, NULL, $2.name); 
                                                            $$.nd = makenode($1.nd, $2.nd, "ITERATOR"); 
                                                            if(!strcmp($1.name, "++")) {
                                                                sprintf(icg[icgind++], "t%d = %s + 1\n%s = t%d\n", temp_var, $2.name, $2.name, temp_var++);
                                                            }
                                                            else {
                                                                sprintf(icg[icgind++], "t%d = %s - 1\n%s = t%d\n", temp_var, $2.name, $2.name, temp_var++);

                                                            }}
        | PRINTF { add('K'); } '(' STR ')'                  { $$.nd = makenode(NULL, NULL, "printf"); }
        | SCANF { add('K'); } '(' STR ',' '&' ID ')'        { $$.nd = makenode(NULL, NULL, "scanf"); }
        ;

else: ELSE { add('K'); } '{' body '}'                       { $$.nd = makenode(NULL, $4.nd, $1.name);}
    |                                                       { $$.nd = NULL; }
    ;

relop: LT
    | GT
    | LE
    | GE
    | EQ
    | NE
    ;

init: ',' ID { add('V'); } init                             {sprintf($$.type, "null"); 
                                                            $$.nd = makenode(NULL, NULL, "NULL"); 
                                                            strcpy($$.name, "NULL");
                                                            $2.nd = makenode(NULL, NULL, $2.name);
                                                            int t = check_types(type, $4.type);
                                                            if(t>0) {   
                                                                if(t == 1) {    
                                                                    struct node *temp = makenode(NULL, $4.nd, "floattoint");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 2) {
                                                                    struct node *temp = makenode(NULL, $4.nd, "inttofloat");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 3) {    
                                                                    struct node *temp = makenode(NULL, $4.nd, "chartoint");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 4) {    
                                                                    struct node *temp = makenode(NULL, $4.nd, "inttochar");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 5) {    
                                                                    struct node *temp = makenode(NULL, $4.nd, "chartofloat");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }   
                                                                else {   
                                                                    struct node *temp = makenode(NULL, $4.nd, "floattochar");
                                                                    $$.nd = makenode($2.nd, temp, "declaration");   
                                                                }
                                                            }
                                                            else {   
                                                                $$.nd = makenode($2.nd, $4.nd, "declaration");  
                                                            }
                                                            sprintf(icg[icgind++], "%s = %s\n", $2.name, $4.name);}
    | '=' value ',' ID { add('V'); } init                   {$$.nd = $2.nd; 
                                                            sprintf($$.type, $2.type); 
                                                            strcpy($$.name, $2.name);
                                                            $4.nd = makenode(NULL, NULL, $4.name);
                                                            int t = check_types(type, $6.type);
                                                            if(t>0) {   
                                                                if(t == 1) {    
                                                                    struct node *temp = makenode(NULL, $6.nd, "floattoint");
                                                                    $$.nd = makenode($4.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 2) {
                                                                    struct node *temp = makenode(NULL, $6.nd, "inttofloat");
                                                                    $$.nd = makenode($4.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 3) {    
                                                                    struct node *temp = makenode(NULL, $6.nd, "chartoint");
                                                                    $$.nd = makenode($4.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 4) {    
                                                                    struct node *temp = makenode(NULL, $6.nd, "inttochar");
                                                                    $$.nd = makenode($4.nd, temp, "declaration");   
                                                                }   
                                                                else if(t == 5) {    
                                                                    struct node *temp = makenode(NULL, $6.nd, "chartofloat");
                                                                    $$.nd = makenode($4.nd, temp, "declaration");   
                                                                }   
                                                                else {   
                                                                    struct node *temp = makenode(NULL, $6.nd, "floattochar");
                                                                    $$.nd = makenode($4.nd, temp, "declaration");   
                                                                }
                                                            }
                                                            else {   
                                                                $$.nd = makenode($4.nd, $6.nd, "declaration");  
                                                            }
                                                            sprintf(icg[icgind++], "%s = %s\n", $4.name, $6.name);}
    | '=' value                                             { $$.nd = $2.nd; 
                                                            sprintf($$.type, $2.type); 
                                                            strcpy($$.name, $2.name); }
    |                                                       { sprintf($$.type, "null"); 
                                                            $$.nd = makenode(NULL, NULL, "NULL"); 
                                                            strcpy($$.name, "NULL"); }
    ;

expression: expression arithmetic expression                { if(!strcmp($1.type, $3.type)) {  
                                                                sprintf($$.type, $1.type);  
                                                                $$.nd = makenode($1.nd, $3.nd, $2.name);  
                                                            }
                                                            //Expr1 and expr2 are different types 
                                                            else {  
                                                                if(!strcmp($1.type, "int") && !strcmp($3.type, "float")) {
                                                                    struct node *temp = makenode(NULL, $1.nd, "inttofloat");
                                                                    sprintf($$.type, $3.type);   
                                                                    $$.nd = makenode(temp, $3.nd, $2.name);  
                                                                }  
                                                                else if(!strcmp($1.type, "float") && !strcmp($3.type, "int")) {   
                                                                    struct node *temp = makenode(NULL, $3.nd, "inttofloat");
                                                                    sprintf($$.type, $1.type);   
                                                                    $$.nd = makenode($1.nd, temp, $2.name);  
                                                                }  
                                                                else if(!strcmp($1.type, "int") && !strcmp($3.type, "char")){   
                                                                    struct node *temp = makenode(NULL, $3.nd, "chartoint");
                                                                    sprintf($$.type, $1.type);   
                                                                    $$.nd = makenode($1.nd, temp, $2.name);  
                                                                }  
                                                                else if(!strcmp($1.type, "char") && !strcmp($3.type, "int")) {   
                                                                    struct node *temp = makenode(NULL, $1.nd, "chartoint");
                                                                    sprintf($$.type, $3.type);   
                                                                    $$.nd = makenode(temp, $3.nd, $2.name);  
                                                                }  
                                                                else if(!strcmp($1.type, "float") && !strcmp($3.type, "char")) {   
                                                                    struct node *temp = makenode(NULL, $3.nd, "chartofloat");
                                                                    sprintf($$.type, $1.type);   
                                                                    $$.nd = makenode($1.nd, temp, $2.name);  
                                                                }  
                                                                else {   
                                                                    struct node *temp = makenode(NULL, $1.nd, "chartofloat");
                                                                    sprintf($$.type, $3.type);   
                                                                    $$.nd = makenode(temp, $3.nd, $2.name);  
                                                                } 
                                                            }
                                                            sprintf($$.name, "t%d", temp_var);
                                                            temp_var++;
                                                            sprintf(icg[icgind++], "%s = %s %s %s\n",  $$.name, $1.name, $2.name, $3.name);}
          | value                                           { strcpy($$.name, $1.name); 
                                                            sprintf($$.type, $1.type); 
                                                            $$.nd = $1.nd;}
          ;

arithmetic: ADD
          | SUB
          | MUL
          | DIV
          ;

value: NUM                                                  {strcpy($$.name, $1.name); sprintf($$.type, "int");
                                                            $$.nd = makenode(NULL, NULL, $1.name);}         
    | FLOAT_NUM                                             {$$.nd = makenode(NULL, NULL, $1.name);
                                                            strcpy($$.name, $1.name); sprintf($$.type, "float");}
    | CHARACTER                                             {$$.nd = makenode(NULL, NULL, $1.name);
                                                            strcpy($$.name, $1.name); sprintf($$.type, "char");}
    | ID                                                    {strcpy($$.name, $1.name); char *id_type = get_type($1.name); 
                                                            sprintf($$.type, id_type); 
                                                            check_declaration($1.name); 
                                                            $$.nd = makenode(NULL, NULL, $1.name);}
    ;

return: RETURN { add('K'); } NUM ';'                        {$1.nd = makenode(NULL, NULL, "return"); 
                                                            $$.nd = makenode($1.nd, $3.nd, "RETURN"); }
    |                                                       { $$.nd = NULL; }
    ;

%%
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
