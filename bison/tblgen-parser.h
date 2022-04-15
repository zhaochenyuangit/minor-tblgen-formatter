#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

//#define DEBUG_MODE 
#ifdef DEBUG_MODE
#define __DEBUG(code) code 
#else
#define __DEBUG(code)
#endif //DEBUG_MODE

#ifndef __EXPR_H__
#define __EXPR_H__
enum {
    NUM=10,
    STRING,
    ID,
};

typedef struct rvalue_t{
    int vtype;
    long num;
    char *string;
    char *id;
}rvalue_t;

typedef char type_t;

typedef struct arg_t{
    struct rvalue_t *rvalue;
    struct arg_t *next;
}arg_t;

typedef struct param_t{
    type_t *type;
    char *id;
    struct rvalue_t *assign;
    struct param_t *next;
}param_t;

typedef struct stmt_t{
    type_t *type;
    char *id;
    struct rvalue_t *assign;
    struct stmt_t *next;
}stmt_t;

typedef struct parent_t{
    char *id;
    arg_t *instance;
    struct parent_t *next;
}parent_t;

typedef struct def_t{
    int index;
    char *id;
    struct parent_t* inherit;
    struct stmt *body;
}def_t;

typedef struct class_t{
    char *id;
    struct param_t *template;
    struct parent_t *inherit;
    struct stmt_t *body;
}class_t;

typedef struct scope_t{
    int index;
    struct class_t *cls;
    struct def_t *def;
    struct scope_t *next;
}scope_t;

typedef  param_t    template_t;
typedef  arg_t      instance_t;
typedef  parent_t   inherit_t;
typedef  stmt_t     body_t;
typedef rvalue_t    assign_t;

scope_t* create_scope(class_t* class_, def_t *def_, scope_t *next_);
class_t* create_class(char *id_, template_t *template_, inherit_t *inherit_, body_t *body_);
def_t* create_def(char *id_, inherit_t *inherit_, body_t *body_);
parent_t* create_parent(char *id_, instance_t *instance_, parent_t *next_);
stmt_t* create_stmt(type_t *type_, char *id_, assign_t *assign_, stmt_t *next_);
arg_t* create_arg(rvalue_t *rvalue_, arg_t *next_);
param_t* create_param(type_t *type_,char *id_,assign_t* assign_,param_t *next_);
rvalue_t* create_rvalue(long num_, char *string_,char *id_);

void set_next_stmt(stmt_t *t, stmt_t *next_);
void set_next_arg(arg_t *t, arg_t *next_);
void set_next_param(param_t *t, param_t *next_);
void set_next_parent(parent_t *p, parent_t *next_);
void set_next_scope(scope_t *s, scope_t *next_);
 

#endif