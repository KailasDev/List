#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

enum type{TYPE_INTEGER, TYPE_FLOAT, TYPE_CHAR};

typedef struct itemBase itemBase;
typedef struct item item;
typedef itemBase *List;
///WARNING: in the declaration, the variable of type List MUST be initialized at NULL

List List_add(List, int); ///Add the number at the list's head
#define List_add(list, value) list = List_add(list, value)

List List_addMany(List, int, ...); ///args: List, number of new values, all values...
#define List_addMany(list, number, ...) list = List_addMany(list, number, __VA_ARGS__)

int List_get(List, int); ///index begining at 0
void List_display(List);
int List_size(List);
int List_head(List); ///based on lists caml
List List_delete(List);
#define List_delete(list) list = List_delete(list)

List List_deleteElement(List, int);
#define List_deleteElement(list, index) list = List_deleteElement(list, index)

int List_indexOf(List, int); ///only the first element

List List_queue(List); ///based on lists caml
#define List_queue(list) list = List_queue(list)
