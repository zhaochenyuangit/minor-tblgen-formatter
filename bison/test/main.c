#include <stdio.h>
#include "expr.h"

void print_def(def_t *d){
    printf("def %s;", d->id);
}
void print_scope(scope_t *s){
    print_def(s->def);
}

int main()
{
    scope_t *s = create_scope(NULL,
                              create_def("a", NULL),
                              NULL);
    print_scope(s);
    return 0;
}

