#include "tblgen-parser.h"
#include "printer.h"

void print_rvalue(rvalue_t *r){
    switch(r->vtype){
        default: printf("rvalue no type"); break;
        case NUM: printf("%ld",r->num); break;
        case ID:  printf("%s", r->id);break;
        case STRING: printf("%s",r->string);break;
    }
}

void print_stmt(stmt_t *t){
    printf(INDENT);
    printf("%s %s",t->type,t->id);
    if(t->assign){
        printf(FORMATS[ELE_ASSIGN]);
        print_rvalue(t->assign);
    }
    printf(FORMATS[ELE_STATE]);
    if(t->next){
        printf("\n");
        print_stmt(t->next);
    }
}

void print_arg(arg_t *t){
    print_rvalue(t->rvalue);
    if(t->next){
        printf(FORMATS[ELE_COMMA]);
        print_arg(t->next);
    }
}

void print_param(param_t *t){
    printf("%s %s",t->type,t->id);
    if(t->assign){
        printf(FORMATS[ELE_ASSIGN]);
        print_rvalue(t->assign);
    }
    if(t->next){
        printf(FORMATS[ELE_COMMA]);
        print_param(t->next);
    }
}

void print_parent(parent_t *p){
    printf("%s",p->id);
    if(p->instance){
        printf(FORMATS[ELE_LPARAM]);
        print_arg(p->instance);
        printf(FORMATS[ELE_RPARAM]);
    }
    if (p->next){
        printf(FORMATS[ELE_COMMA]);
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
        printf(FORMATS[ELE_INHERIT]);
        print_parent(d->inherit);
        printf(FORMATS[ELE_RINHERIT]);
    }
    if(d->body){
        printf(FORMATS[ELE_LBODY]);
        print_stmt(d->body);
        printf(FORMATS[ELE_RBODY]);
    }
    else{
        printf(FORMATS[ELE_EMPTY_BODY]);
    }
}

void print_class(class_t *c){
    printf("class %s",c->id);
    if(c->template){
        printf(FORMATS[ELE_LPARAM]);
        print_param(c->template);
        printf(FORMATS[ELE_RPARAM]);
    }
    if(c->inherit){
        printf(FORMATS[ELE_INHERIT]);
        print_parent(c->inherit);
        printf(FORMATS[ELE_RINHERIT]);
    }
    if(c->body){
        printf(FORMATS[ELE_LBODY]);
        print_stmt(c->body);
        printf(FORMATS[ELE_RBODY]);
    } else {
        printf(FORMATS[ELE_EMPTY_BODY]);
    }
}

void print_scope(scope_t *s){
    __DEBUG(if(!s) puts("empty");)
    if(s->def){
        print_def(s->def);
    }
    if(s->cls){
        print_class(s->cls);
    }
    printf(FORMATS[ELE_NEWLINE]);
    if (s->next){
        print_scope(s->next);
    }
}

void set_format_style(style_t style){
    for(int i =0;i<NUM_OF_ELEMENTS;i++){
        FORMATS[i] = FORMAT_TABLE[i][style];
    }
}