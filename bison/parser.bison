%{
 #include <stdio.h>
 #include <string.h>
 #include "tblgen-parser.h"
 #include "printer.h"
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
%token TOKEN_LANGLE
%token TOKEN_RANGLE
%token TOKEN_ERROR

%%
program : scopes {print_scope($1);};
scopes  : scope {$$ = $1;}
        | scope scopes {$$ = $1;set_next_scope($1,$2);}
        ;
scope   : class {$$ = create_scope($1,0,0);}
        | record {$$ = create_scope(0,$1,0);}
        ;
class   : TOKEN_CLASS id template inherit body
                {$$ = create_class($2,$3,$4,$5);}
        ;
stmts   : stmt stmts {set_next_stmt($1, $2);$$=$1;}
        | stmt {$$ = $1;}
        ;
stmt    : type id assign TOKEN_SEMI
            {$$ = create_stmt($1,$2,$3,0);}
        ;
args    : arg TOKEN_COMMA args {set_next_arg($1,$3);$$=$1;};
        | arg {$$=$1;}
        ;
arg   : rvalue {$$=create_arg($1,0);};
params  : param TOKEN_COMMA params {set_next_param($1,$3);$$=$1;}
        | param {$$=$1;}
        ;
param   : type id assign {$$ = create_param($1,$2,$3,0);};

assign  : TOKEN_EQ rvalue {$$=$2;}
        | {$$=0;}
        ;
body    : TOKEN_LBRACKET stmts TOKEN_RBRACKET {$$ = $2;}
        | TOKEN_SEMI {$$ = 0;}
        ;
template: TOKEN_LANGLE params TOKEN_RANGLE {$$=$2;}
        | {$$=0;}
        ;
instance: TOKEN_LANGLE args TOKEN_RANGLE {$$=$2;}
        | {$$=0;}
        ;
inherit : TOKEN_COLON parents {$$ = $2;}
        | {$$ = 0;}
        ;
defname : id {$$=$1;}
        | {$$=0;}
        ;
rvalue  : num   {$$ = create_rvalue((long)$1,0,0);}
        | string{$$ = create_rvalue(0,$1,0);}
        | id    {$$ = create_rvalue(0,0,$1);}
        ;
type    : TOKEN_INT {
                char *str = malloc(strlen(yytext));
                strcpy(str,yytext);
                $$ = str;
                }
        | TOKEN_STRING {
                char *str = malloc(strlen(yytext));
                strcpy(str,yytext);
                $$ = str;
                }
        ;
record  : TOKEN_DEF defname inherit body
            {$$ = create_def($2,$3,$4);}
        ;

id      : TOKEN_ID{
                char *str = malloc(strlen(yytext));
                strcpy(str,yytext);
                $$ = str;
                }
        ;

string  : TOKEN_DQUOTE {
                char *str = malloc(strlen(yytext));
                strcpy(str,yytext);
                $$ = str;
                }
        ;
num     : TOKEN_NUMBER {long num = atoi(yytext);$$ = (void*)num;};
parents : parent TOKEN_COMMA parents {set_next_parent($1,$3);$$=$1;}
        | parent {$$ = $1;}
        ; 
parent  : id instance {$$ = create_parent($1,$2,0);};

%%
int yywarp(){return 0;}