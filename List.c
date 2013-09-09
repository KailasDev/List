#include "List.h"

#undef List_add
#undef List_addMany
#undef List_queue
#undef List_delete
#undef List_deleteElement

union typeVoid
{
    int in;
    float fl;
    char ch;
};



struct item
{
    typeVoid value;
    struct item *pointer;
};

struct itemBase
{
    int sizeList;
    int type;
    item *pointer;
};


List List_create()
{
    itemBase* base = (itemBase*)malloc(sizeof(itemBase));

    base->sizeList = 0;
    base->type = 0;
    base->pointer = NULL;

    return base;
}

List List_newInt()
{
    itemBase *it = List_create();
    it->type = TYPE_INTEGER;

    return it;
}

List List_newFloat()
{
    itemBase *it = List_create();
    it->type = TYPE_FLOAT;

    return it;
}

List List_newChar()
{
    itemBase *it = List_create();
    it->type = TYPE_CHAR;

    return it;
}


List List_add(List list, type value)
{

    if(list == NULL)
    {
        list = List_create();

        switch(list->type)
        {
            case TYPE_INTEGER:
                list = List_newInt();
                break;
            case TYPE_FLOAT:
                list = List_newFloat();
                break;
            case TYPE_CHAR:
                list = List_newChar();
                break;
            default:
                list = List_newInt();
                break;
        }
        list->sizeList = 0;
    }

    item *li = (item*)malloc(sizeof(item));

    switch(list->type)
    {
        case TYPE_INTEGER:
            li->value.in = (int)value;
            break;
        case TYPE_FLOAT:
            li->value.fl = value;
            printf("verif %f\n", li->value.fl);
            break;
        case TYPE_CHAR:
            li->value.ch = (char)value;
            break;
        default:
            li->value.in = (int)value;
            break;
    }

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

    switch(list->type)
    {
        case TYPE_INTEGER:
            return tmp->value.in;
            break;
        case TYPE_FLOAT:
            return tmp->value.fl;
            break;
        case TYPE_CHAR:
            return tmp->value.ch;
            break;
        default:
            return tmp->value.in;
            break;
    }

    return -1;
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
        switch(list->type)
        {
            case TYPE_INTEGER:
                printf("%d ", li->value.in);
                break;
            case TYPE_FLOAT:
                printf("%f ", li->value.fl);
                break;
            case TYPE_CHAR:
                printf("%c ", li->value.ch);
                break;
            default:
                printf("%d ", li->value.in);
                break;
        }
        li = li->pointer;

    }
}



int List_head(List list)
{
    if(List_size(list) == 0)
        return;
    switch(list->type)
    {
        case TYPE_INTEGER:
            return list->pointer->value.in;
            break;
        case TYPE_FLOAT:
            return list->pointer->value.fl;
            break;
        case TYPE_CHAR:
            return list->pointer->value.ch;
            break;
        default:
            return list->pointer->value.in;
            break;
    }
    return;
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


int List_indexOf(List list, type value)
{
    if(list == NULL || list->pointer == NULL)
        return -1;
    item *tmp = list->pointer;
    int i;
    for(i=0; tmp != NULL; i++)
    {
        switch(list->type)
        {
            case TYPE_INTEGER:
                if(tmp->value.in == (int)value)
                    return i;
                break;
            case TYPE_FLOAT:
                if(tmp->value.in == value)
                    return i;
                break;
            case TYPE_CHAR:
                if(tmp->value.in == (char)value)
                    return i;
                break;
        }
        tmp = tmp->pointer;
    }

    if(tmp == NULL)
        return -1;
    return i;
}
