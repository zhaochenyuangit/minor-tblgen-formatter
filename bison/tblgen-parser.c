#include <stdlib.h>
#include "tblgen-parser.h"

scope_t* create_scope(class_t* class_, def_t *def_, scope_t *next_){
    static int i =0;
    scope_t *scope = malloc(sizeof(scope_t));
    scope->index = i++;
    scope->cls = class_;
    scope->def = def_;
    scope->next = next_;
    return scope;
}

class_t* create_class(char *id_, inherit_t *inherit_, body_t *body_){
    class_t *class = malloc(sizeof(class_t));
    class->id = id_;
    class->inherit = inherit_;
    class->body = body_;
    return class;
}

def_t* create_def(char *id_,inherit_t *inherit_, body_t *body_){
    static int i =0;
    def_t *def = malloc(sizeof(def_t));
    def->index = i++;
    def->id = id_;
    def->inherit = inherit_;
    def->body = body_;
    //printf("def %d : %s\n",def->index,def->id);
    return def;
}

inherit_t* create_inherit(_Bool empty_, parent_t *parent_){
    inherit_t *inherit = malloc(sizeof(inherit_t));
    inherit->empty = empty_;
    inherit->parent = parent_;
    return inherit;
}

parent_t* create_parent(char *id_,parent_t *next_){
    //printf("created parent %s\n", id_);
    parent_t *parent = malloc(sizeof(parent_t));
    parent->id = id_;
    parent->next = next_;
    return parent;
}

body_t* create_body(_Bool empty,stmt_t *stmt_){
    body_t *body = malloc(sizeof(body_t));
    body->empty = empty;
    body->stmt = stmt_;
    return body;
}

stmt_t* create_stmt(char *id_, int num_, stmt_t *next_){
    stmt_t *stmt = malloc(sizeof(stmt_t));
    stmt->id = id_;
    stmt->num = num_;
    stmt->next = next_;
    return stmt;
}

void set_next_stmt(stmt_t *t, stmt_t *next_){
    t->next = next_;
}

void set_next_parent(parent_t *p, parent_t *next_){
    p->next = next_;
}
void set_next_scope(scope_t *s, scope_t *next_){
    //printf("%d scope %s next %x %d\n", s->index,s->def->id,next_,next_->index);
    s->next = next_;
}



