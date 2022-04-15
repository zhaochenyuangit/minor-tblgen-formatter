#include "tblgen-parser.h"

#ifndef __PRINTER_H__
#define __PRINTER_H__

typedef enum{
    STYLE_NORMAL=0,
    STYLE_COMPACT,
    STYLE_PYTHON,
    NUM_OF_STYLES
}style_t;

typedef enum{
    ELE_NEWLINE=0,
    ELE_LBODY,
    ELE_RBODY,
    ELE_ASSIGN,
    ELE_COMMA,
    ELE_INHERIT,
    ELE_RINHERIT,
    ELE_LPARAM,
    ELE_RPARAM,
    ELE_STATE,
    ELE_EMPTY_BODY,
    NUM_OF_ELEMENTS
}element_t;

void print_scope(scope_t *s);
void set_format_style(style_t style);

#define INDENT "%4s", " "

const static char* FORMAT_TABLE[NUM_OF_ELEMENTS][NUM_OF_STYLES] = {
    //NORMAL    COMPACT PYTHON
    {"\n\n",    "\n",   "\n\n"},
    {"\n{\n",   "{\n",  ":\n"},
    {"\n}",  "\n}",     ""},
    {" = ",     "=",    " = "},
    {", ",      ",",    ", "},
    {": ",      ": ",   "("},
    {"",        "",     ") "},
    {"<",       "<",    "("},
    {">",       ">",    ")"},
    {";",       ";",    ""},
    {";",       ";",    ": ..."},
    };

#endif //__PRINTER_H__
