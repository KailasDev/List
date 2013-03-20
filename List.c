#include "List.h"


struct item
{
    int value;

    struct item *pointeur;
};

List List_add(List list, int value)
{
    item *li = malloc(sizeof(item));
    li->pointeur = list;
    li->value = value;

    return li;
}

List List_addMany(List list, int number, ...)
{
    va_list vl;
    va_start(vl, number);
    item *li = malloc(sizeof(item));
    li->pointeur = list;
    li->value = va_arg(vl, int);
    int i;

    if(number > 0)
    {
        for(i=0; i<number-1; i++)
        {
            li = List_add(li, va_arg(vl, int));
        }
    }
    va_end(vl);


    return li;
}

int List_get(List list, int index)
{
    int i;
    item li2 = *list;
    if(index == 0)
        return li2.value;
    if(index < 0)
        return NULL;
        //fprintf(stderr, "Index error");
    for(i=0; i<index; i++)
    {
        if(li2.pointeur != NULL)
            li2 = *li2.pointeur;
        else
            return NULL;
    }

    //return li2->value;
    return li2.value;
}

int List_size(List list)
{
    int i;
    for(i=0; List_get(list, i) != NULL; i++)
    {

    }
    return i++;
}

void List_display(List list)
{
    int i;
    for(i=0; i<List_size(list); i++)
        printf("%d ", List_get(list, i));
    printf("\n");
}

int List_head(List list)
{
    return list->value;
}

List List_queue(List list)
{
    return list->pointeur;
}
