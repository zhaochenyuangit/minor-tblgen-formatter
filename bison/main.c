#include <stdio.h>
#include "tblgen-parser.h"
#define YYSTYPE void *

extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern int yyparse();

int main(){
    yyin = fopen("/home/ros/Documents/tblgen-playground/tblgen-master/talk4.td","r");
    if(!yyin){
        printf("could not open\n");
        return 1;
    }
    int ret = yyparse();
    if(ret) puts("parse fail");

}
