#include <stdlib.h>
#include "expr.h"

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

def_t* create_def(char *id_,inherit_t *inherit_){
    static int i =0;
    def_t *def = malloc(sizeof(def_t));
    def->index = i++;
    def->id = id_;
    def->inherit = inherit_;
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

void set_next_parent(parent_t *p, parent_t *next_){
    p->next = next_;
}
void set_next_scope(scope_t *s, scope_t *next_){
    //printf("%d scope %s next %x %d\n", s->index,s->def->id,next_,next_->index);
    s->next = next_;
}

void print_parent(parent_t *p){
    printf("%s",p->id);
    if (p->next){
        printf(", ");
        print_parent(p->next);
    }
}

void print_inherit(inherit_t *i){
    if(!i) puts("inherit empty");
    else print_parent(i->parent);
}

void print_def(def_t *d){
    if(!d) puts("def empty");
    printf("def %s", d->id);
    if(!d->inherit->empty){
        printf(": ");
        print_inherit(d->inherit);
    }
    printf(";");
}
void print_scope(scope_t *s){
    if(!s) puts("empty");
    if(s->def){
        print_def(s->def);
    }
    printf("\n");
    if (s->next)
        print_scope(s->next);
}