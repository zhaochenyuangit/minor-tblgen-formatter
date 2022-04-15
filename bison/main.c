#include <stdio.h>
#include "tblgen-parser.h"
#include "printer.h"
#include "string.h"
#define YYSTYPE void *

extern FILE *yyin;
extern int yylex();
extern char *yytext;
extern int yyparse();

int main(int argc, char* argv[]){
    if (argc<2){
        yyin = fopen("/home/ros/Documents/tblgen-playground/tblgen-master/talk9.td","r");
        set_format_style(STYLE_COMPACT);
    }else if(argc==2){
        yyin = fopen(argv[1],"r");
        set_format_style(STYLE_COMPACT);
    }else{
        yyin = fopen(argv[1],"r");
        if(0==strncmp(argv[2],"--compact",strlen("--compact"))){
            set_format_style(STYLE_COMPACT);
        }else if(0==strncmp(argv[2],"--normal",strlen("--normal"))){
            set_format_style(STYLE_NORMAL);
        }else if(0==strncmp(argv[2],"--python",strlen("--python"))){
            set_format_style(STYLE_PYTHON);
        }else{
            printf("not implemented\n");
            return 1;
        }
    }
    if(!yyin){
        printf("could not open\n");
        return 1;
    }
    int ret = yyparse();
    if(ret) puts("parse fail");

}
