#include "tblgen-parser.h"

void print_rvalue(rvalue_t *r){
    switch(r->vtype){
        default: printf("rvalue no type\n"); break;
        case NUM: printf("%ld",r->num); break;
        case ID: printf("%s",r->id);break;
        case STRING: printf("%s",r->string);break;
    }
}

void print_stmt(stmt_t *t){
    printf("\t");
    printf("%s %s",t->type,t->id);
    if(t->assign){
        printf(" = ");
        print_rvalue(t->assign);
    }
    printf(";");
    if(t->next){
        printf("\n");
        print_stmt(t->next);
    }
}

void print_arg(arg_t *t){
    print_rvalue(t->rvalue);
    if(t->next){
        printf(", ");
        print_arg(t->next);
    }
}

void print_param(param_t *t){
    printf("%s %s",t->type,t->id);
    if(t->assign){
        printf(" = ");
        print_rvalue(t->assign);
    }
    if(t->next){
        printf(", ");
        print_param(t->next);
    }
}

void print_parent(parent_t *p){
    printf("%s",p->id);
    if(p->instance){
        printf("<");
        //print_arg(p->instance);
        printf(">");
    }
    if (p->next){
        printf(", ");
        print_parent(p->next);
    }
}

void print_def(def_t *d){
    if(!d) puts("def empty");
    printf("def ");
    if(d->id){
        printf("%s",d->id);
    }
    if(d->inherit){
        printf(":");
        print_parent(d->inherit);
    }
    if(d->body){
        printf("{\n");
        print_stmt(d->body);
        printf("\n}");
    }
    else{
        printf(";");
    }
}

void print_class(class_t *c){
    printf("class %s",c->id);
    if(c->inherit){
        printf(": ");
        print_parent(c->inherit);
    }
    if(c->body){
        print_stmt(c->body);
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
        //print_class(s->cls);
    }
    printf("\n");
    if (s->next)
        print_scope(s->next);
}