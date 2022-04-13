#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#ifndef __EXPR_H__
#define __EXPR_H__

typedef struct stmt_t{
    char *id;
    int num;
    struct stmt_t *next;
}stmt_t;

typedef struct body_t{
    _Bool empty;
    struct stmt_t *stmt;
}body_t;

typedef struct inherit_t{
    _Bool empty;
    struct parent_t *parent;
}inherit_t;

typedef struct def_t{
    int index;
    char *id;
    struct inherit_t *inherit;
    struct body_t *body;
}def_t;

typedef struct parent_t{
    char *id;
    struct parent_t *next;
}parent_t;

typedef struct class_t{
    char *id;
    struct inherit_t *inherit;
    struct body_t *body;
}class_t;

typedef struct scope_t{
    int index;
    struct class_t *cls;
    struct def_t *def;
    struct scope_t *next;
}scope_t;

scope_t* create_scope(class_t* class_, def_t *def_, scope_t *next_);
class_t* create_class(char *id_, inherit_t *inherit_, body_t *body_);
def_t* create_def(char *id_,inherit_t *inherit_, body_t *body);
inherit_t* create_inherit(_Bool empty_, parent_t *parent_);
parent_t* create_parent(char *id_,parent_t *next_);
stmt_t* create_stmt(char *id_, int num_, stmt_t *next_);
body_t* create_body(_Bool empty,stmt_t *stmt_);

void set_next_parent(parent_t *p,parent_t *next_);
void set_next_scope(scope_t *s, scope_t *next_);
void set_next_stmt(stmt_t *t, stmt_t *next_);

#endif