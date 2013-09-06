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



List List_add(List list, int value)
{
    item *li = (item*)malloc(sizeof(item));
    li->value = value;
    li->pointer = NULL;

    if(list == NULL)
        return li;

    item* tmp = list;

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

    item* tmp = list;

    int i;
    for(i=0; i<index; i++)
        tmp = tmp->pointer;
    return tmp->value;
}



int List_size(List list)
{
    if(list == NULL)
        return 0;
    return List_size(list->pointer)+1;
}



void List_display(List list)
{
    if(list == NULL)
        return;
    printf("%d ", list->value);
    List_display(list->pointer);
}



int List_head(List list)
{
    return list->value;
}



List List_queue(List list)
{
    return list->pointer;
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
    item* tmp = list;

    if(index == 0)
    {
        tmp = tmp->pointer;
        free(list);
        return tmp;
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
    item *tmp = list;
    int i;
    for(i=0; tmp != NULL && tmp->value != value; i++)
        tmp = tmp->pointer;
    if(tmp == NULL)
        return -1;
    return i;
}
