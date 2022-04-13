#include <stdlib.h>
#include <stdbool.h>

#define struct stmt      stmt_t;
#define struct body      body_t;
#define struct inherit inherit_t;
#define struct def     def_t;
#define struct parent  parent_t;
#define struct class   class_t;
#define struct scope  scope_t;

scope_t* create_scope(class_t* class_, def_t *def_, scope_t *next_);
class_t* create_class(char *id_, inherit_t *inherit_, body_t *body_);
def_t* create_def(char *id_,inherit_t *inherit_);
inherit_t* create_inherit(_Bool empty_, parent_t *parent_);
parent_t* create_parent(char *id_,parent_t *next_);

