#include <stdio.h>
#include <malloc.h>
#include "List.h"

List *listNew(int length)
{
    List *list = malloc(sizeof(List));
    list->head = malloc(sizeof(ListElement));
    list->head->next = NULL;
    list->head->data = NULL;
    list->tail = malloc(sizeof(ListElement));
    list->tail->next = NULL;
    list->tail->data = NULL;
    list->length = length;

    return list;
}

void listDel(List *list)
{
    if(list != NULL)
        free(list);
}

void listAdd(List *list, void *data)
{
    if(list->head->data == NULL)
        list->head->data = data;
}

void *listRemove(List *list)
{

}

int listIsEmpty(List *list)
{

}

int listIsFull(List *list)
{

}
