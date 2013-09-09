#include "List.h"

#undef List_add
#undef List_addMany
#undef List_queue
#undef List_delete
#undef List_deleteElement

struct item
{
    int value;
    struct item *pointer;
};

struct itemBase
{
    int sizeList;
    int type;
    item *pointer;
};


List List_create(List list)
{
    itemBase* base = (itemBase*)malloc(sizeof(itemBase));

    base->sizeList = 0;
    base->type = 0;
    base->pointer = NULL;

    list = base;

    return list;
}

List List_add(List list, int value)
{

    if(list == NULL)
    {
        list = List_create(list);
        list->sizeList = 0;
    }

    item *li = (item*)malloc(sizeof(item));
    li->value = value;
    li->pointer = NULL;

    list->sizeList++;

    if(list->sizeList == 1)
    {
        list->pointer = li;
        return list;
    }

    item* tmp = list->pointer;

    while(tmp->pointer != NULL)
        tmp = tmp->pointer;

    tmp->pointer = li;

    return list;
}


List List_addMany(List list, int number, ...)
{
    va_list vl;
    va_start(vl, number);
    int i;
    if(number > 0)
    {
        for(i=0; i<number; i++)
        {
            list = List_add(list, va_arg(vl, int));
        }
    }
    va_end(vl);

    return list;
}



int List_get(List list, int index)
{
    if(index >= List_size(list) || index < 0)
        return -1;

    item* tmp = list->pointer;

    int i;
    for(i=0; i<index; i++)
        tmp = tmp->pointer;
    return tmp->value;
}



int List_size(List list)
{
    return list->sizeList;
}



void List_display(List list)
{
    if(list == NULL || list->pointer == NULL)
        return;

    int i;

    item* li = list->pointer;

    for(i=0; i<list->sizeList; i++)
    {
        printf("%d ", li->value);
        li = li->pointer;

    }
}



int List_head(List list)
{
    if(List_size(list) == 0)
        return;
    return list->pointer->value;
}



List List_queue(List list)
{
    if(List_size(list) <2)
        return NULL;
    list->sizeList--;
    return list->pointer->pointer;
}


List List_delete(List list)
{
    item* var = NULL;

    while(list != NULL)
    {
        var = list->pointer;
        free(list);
        list = var;
    }

    free(var);

    return NULL;
}



List List_deleteElement(List list, int index)
{
    item* tmp = list->pointer;

    if(index == 0)
    {
        list->pointer = tmp->pointer;
        free(tmp);
        return list;
    }

    int i;
    for(i=0; i<index-1; i++)
    {
        tmp = tmp->pointer;
    }

    if(index == List_size(list)-1)
    {
        free(tmp->pointer);
        tmp->pointer = NULL;

        return list;
    }
    item* tmp2 = (tmp->pointer)->pointer;
    free(tmp->pointer);
    tmp->pointer = tmp2;

    return list;
}


int List_indexOf(List list, int value)
{
    if(list == NULL || list->pointer == NULL)
        return -1;
    item *tmp = list->pointer;
    int i;
    for(i=0; tmp != NULL && tmp->value != value; i++)
        tmp = tmp->pointer;
    if(tmp == NULL)
        return -1;
    return i;
}
