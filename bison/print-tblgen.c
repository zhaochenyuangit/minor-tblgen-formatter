#include "tblgen-parser.h"

void print_parent(parent_t *p){
    printf("%s",p->id);
    if (p->next){
        printf(", ");
        print_parent(p->next);
    }
}

void print_inherit(inherit_t *i){
    if(!i) puts("inherit empty");
    else {
        printf(": ");
        print_parent(i->parent);
    }
}

void print_def(def_t *d){
    if(!d) puts("def empty");
    printf("def %s", d->id);
    if(!d->inherit->empty){
        print_inherit(d->inherit);
    }
    if(!d->body->empty){
        print_body(d->body);
    }
    else{
        printf(";");
    }
}

void print_stmt(stmt_t *t){
    printf("\t");
    printf("int %s = %d;\n",t->id,t->num);
    if(t->next){
        print_stmt(t->next);
    }
}

void print_body(body_t *b){
    printf("{\n");
    print_stmt(b->stmt);
    printf("}");
}

void print_class(class_t *c){
    printf("class %s",c->id);
    if(!c->inherit->empty){
        print_inherit(c->inherit);
    }
    if(!c->body->empty){
        print_body(c->body);
    } else {
        printf(";");
    }
}

void print_scope(scope_t *s){
    if(!s) puts("empty");
    if(s->def){
        print_def(s->def);
    }
    if(s->cls){
        print_class(s->cls);
    }
    printf("\n");
    if (s->next)
        print_scope(s->next);
}