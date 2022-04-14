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

class_t* create_class(char *id_, template_t *template_, inherit_t *inherit_, body_t *body_){
    class_t *class = malloc(sizeof(class_t));
    class->id = id_;
    class->template = template_;
    class->inherit = inherit_;
    class->body = body_;
    return class;
}

def_t* create_def(char *id_, inherit_t *inherit_, body_t *body_){
    static int i =0;
    def_t *def = malloc(sizeof(def_t));
    def->index = i++;
    def->id = id_;
    def->inherit = inherit_;
    def->body = body_;
    //printf("def %d : %s\n",def->index,def->id);
    return def;
}

parent_t* create_parent(char *id_, instance_t *instance_, parent_t *next_){
    parent_t* parent = malloc(sizeof(parent_t));
    parent->id = id_;
    parent->instance = instance_;
    parent->next = next_;
}

stmt_t* create_stmt(type_t *type_, char *id_, assign_t *assign_, stmt_t *next_){
    stmt_t *stmt = malloc(sizeof(stmt_t));
    stmt->type = type_;
    stmt->id = id_;
    stmt->assign = assign_;
    stmt->next = next_;
    return stmt;
}

arg_t* create_arg(rvalue_t *rvalue_, arg_t *next_){
    arg_t *arg = malloc(sizeof(arg_t));
    arg->rvalue = rvalue_;
    arg->next = next_;
}

param_t* create_param(type_t *type_,char *id_,assign_t* assign_,param_t *next_){
    param_t *param = malloc(sizeof(param_t));
    param->type = type_;
    param->id = id_;
    param->assign = assign_;
    param->next = next_;
}

rvalue_t* create_rvalue(long num_, char *string_,char *id_){
    rvalue_t *rvalue = malloc(sizeof(rvalue));
    if(id_){
        rvalue->id = id_;
        rvalue->vtype = ID;
    }
    if(num_){
        rvalue->num = num_;
        rvalue->vtype = NUM;
    }
    if(string_){
        rvalue->string = string_;
        rvalue->vtype = STRING;
    }
}

void set_next_stmt(stmt_t *t, stmt_t *next_){
    t->next = next_;
}

void set_next_arg(arg_t *t, arg_t *next_){
    t->next = next_;
}

void set_next_param(param_t *t, param_t *next_){
    t->next = next_;
}

void set_next_parent(parent_t *p, parent_t *next_){
    p->next = next_;
}
void set_next_scope(scope_t *s, scope_t *next_){
    //printf("%d scope %s next %x %d\n", s->index,s->def->id,next_,next_->index);
    s->next = next_;
}



