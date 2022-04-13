%{
 #include <stdio.h>
 #include <string.h>
 #include "expr.h"
 #define YYSTYPE void *
 int yylex(void);
 extern char *yytext;
 void yyerror(char const *s){
    fprintf(stderr,"%s\n",s);
 }
%}

%token TOKEN_EOF
%token TOKEN_ID
%token TOKEN_NUMBER
%token TOKEN_DEF
%token TOKEN_CLASS
%token TOKEN_INT
%token TOKEN_STRING
%token TOKEN_SEMI
%token TOKEN_COMMA
%token TOKEN_EQ
%token TOKEN_ADD
%token TOKEN_DQUOTE
%token TOKEN_COLON
%token TOKEN_LBRACKET
%token TOKEN_RBRACKET
%token TOKEN_ERROR

%%
program : scopes {print_scope($1);};
scopes  : scope {$$ = $1;}
        | scope scopes {$$ = $1;set_next_scope($1,$2);}
        ;
scope   : class {$$ = create_scope($1,0,0);}
        | record {$$ = create_scope(0,$1,0);}
        ;
class   : TOKEN_CLASS TOKEN_ID inherit body
            {$$ = create_class($2,$3,$4);}
        ;
body    : TOKEN_LBRACKET stmts TOKEN_RBRACKET
        | TOKEN_SEMI
        ;
stmts   : stmt stmts
        | stmt
        ;
stmt    : type TOKEN_ID TOKEN_EQ TOKEN_NUMBER TOKEN_SEMI;
type    : TOKEN_INT;
record  : TOKEN_DEF id inherit TOKEN_SEMI
            {$$ = create_def($2,$3);}
        ;
id      : TOKEN_ID {char *str = malloc(10);
                    strcpy(str,yytext);
                    $$ = str;}; 
inherit : TOKEN_COLON parents {$$ = create_inherit(false,$2);}
        | {$$ = create_inherit(true,0);}
        ;
parents : parent TOKEN_COMMA parents {set_next_parent($1,$3);$$=$1;}
        | parent {$$ = $1;}
        ; 
parent  : TOKEN_ID { char *str = malloc(10);
                    strcpy(str,yytext);
                    $$ = create_parent(str,0);};

%%
int yywarp(){return 0;}