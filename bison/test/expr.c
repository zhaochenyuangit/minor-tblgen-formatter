#include <stdlib.h>
#include "expr.h"


scope_t* create_scope(class_t* class_, def_t *def_, scope_t *next_){
    scope_t *scope = malloc(sizeof(scope_t));
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
    def_t *def = malloc(sizeof(def_t));
    def->id = id_;
    def->inherit = inherit_;
    return def;
}

inherit_t* create_inherit(_Bool empty_, parent_t *parent_){
    inherit_t *inherit = malloc(sizeof(inherit_t));
    inherit->empty = empty_;
    inherit->parent = parent_;
    return inherit;
}

parent_t* create_parent(char *id_,parent_t *next_){
    parent_t *parent = malloc(sizeof(parent_t));
    parent->id = id_;
    parent->next = next_;
    return parent;
}