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
#define List_add(list, value) list = List_add(list, value)

List List_addMany(List, int, ...);
#define List_addMany(list, number, ...) list = List_addMany(list, number, __VA_ARGS__)

int List_get(List, int);
void List_display(List);
int List_size(List);
int List_head(List);

List List_queue(List);
#define List_queue(list) list = List_queue(list)
