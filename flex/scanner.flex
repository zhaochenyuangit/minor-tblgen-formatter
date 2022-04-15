%{
    #include "token.h"
%}
DIGIT [0-9]
LETTER [a-zA-Z_]
%%
\/\/.*\n        /*skip comments*/
(" "|\t|\n)     /*skip blanks*/
def {return TOKEN_DEF;}
class {return TOKEN_CLASS;}
int {return TOKEN_INT;}
string {return TOKEN_STRING;}
;   {return TOKEN_SEMI;}
, {return TOKEN_COMMA;}
= {return TOKEN_EQ;}
\+ {return TOKEN_ADD;}

: {return  TOKEN_COLON;}
\{ {return TOKEN_LBRACKET;}
\} {return TOKEN_RBRACKET;}
\< {return TOKEN_LANGLE;}
\> {return TOKEN_RANGLE;}
{LETTER}({LETTER}|{DIGIT})* {return TOKEN_ID;}
{DIGIT}+ {return TOKEN_NUMBER;}
\"[^"]*\" {return TOKEN_DQUOTE;}
.   {return TOKEN_ERROR;} 
%%
int yywrap() {return 1;}