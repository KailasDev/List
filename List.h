#include <stdio.h>
#include <stdlib.h>
#if defined (WIN32) || defined (WIN64)
#include <windows.h>
#else
#include <stdarg.h>
#endif

typedef struct item item;
typedef item *List;

List List_add(List, int);
List List_addMany(List, int, ...);
int List_get(List, int);
void List_display(List);
int List_size(List);
int List_head(List);
List List_queue(List);
