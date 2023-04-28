%{
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    #include<ctype.h>
    #include"lex.yy.c"
    #include<queue>

    void yyerror(const char *s);
    int yylex();
    int yywrap();
    void add(char);
    void insert_type();
    int lookup(char *);
    struct node* makenode(struct node *left, struct node *right, char *token);
    void printInorder(struct node *);
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
%}

%union{
    struct var_name {
        char name[100];
        struct node* nd;
    } node_obj;
    struct var_name2 { 
			char name[100]; 
			struct node* nd;
			char type[5];
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
    | WHILE { add('K'); } '(' condition ')' '{' body '}'    { $$.nd = makenode($4.nd, $7.nd, "While"); }
    | IF  { add('K'); } '(' condition ')' '{' body '}' else { struct node *iff = makenode($4.nd, $7.nd, $1.name);  
                                                              $$.nd = makenode(iff, $9.nd, "if-else"); }
    | statement ';'                                         { $$.nd = $1.nd; }
    ;

condition: expression relop expression                      { $$.nd = makenode($1.nd, $3.nd, $2.name); }
        | expression                                        { $$.nd = $1.nd; }
        | TRUE                                              { add('K'); $$.nd = NULL; }
        | FALSE                                             { add('K'); $$.nd = NULL; }
        |                                                   { $$.nd = NULL; }
        ;

statement: datatype ID { add('V'); } init                   { $2.nd = makenode(NULL, NULL, $2.name); 
                                                            $$.nd = makenode($2.nd, $4.nd, "declaration"); }
        | ID '=' expression                                 { $1.nd = makenode(NULL, NULL, $1.name); 
                                                            $$.nd = makenode($1.nd, $3.nd, "="); }
        | ID relop expression                               { $1.nd = makenode(NULL, NULL, $1.name); 
                                                            $$.nd = makenode($1.nd, $3.nd, $2.name); }
        | ID UNARY                                          { $1.nd = makenode(NULL, NULL, $1.name); 
                                                            $2.nd = makenode(NULL, NULL, $2.name); 
                                                            $$.nd = makenode($1.nd, $2.nd, "ITERATOR");}
        | UNARY ID                                          { $1.nd = makenode(NULL, NULL, $1.name); 
                                                            $2.nd = makenode(NULL, NULL, $2.name); 
                                                            $$.nd = makenode($1.nd, $2.nd, "ITERATOR"); }
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

init:  '=' value                                            { $$.nd = $2.nd; }
    |                                                       { $$.nd = makenode(NULL, NULL, "NULL"); }
    ;

expression: expression arithmetic expression                { $$.nd = makenode($1.nd, $3.nd, $2.name); }
          | value                                           { $$.nd = $1.nd; }
          ;

arithmetic: ADD
          | SUB
          | MUL
          | DIV
          ;

value: NUM                                                  {$$.nd = makenode(NULL, NULL, $1.name);}         
    | FLOAT_NUM                                             {$$.nd = makenode(NULL, NULL, $1.name);}
    | CHARACTER                                             {$$.nd = makenode(NULL, NULL, $1.name);}
    | ID                                                    {$$.nd = makenode(NULL, NULL, $1.name);}
    ;

return: RETURN { add('K'); } NUM ';'                        {$1.nd = makenode(NULL, NULL, "return"); 
                                                            $$.nd = makenode($1.nd, $3.nd, "RETURN"); }
    |                                                       { $$.nd = NULL; }
    ;

%%
int main() {
    yyin=fopen("input.c","r");
    printf("\n");
    yyparse();
   printf("Syntax Analyser: Parsing Successful\n\nSymbol Table:\n");

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
    printf("\n\nSyntax Tree:\n\n");
    printLevelOrder(head);
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