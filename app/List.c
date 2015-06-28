#include <stdio.h>
#include <malloc.h>
#include "List.h"

ListElement *createListElement()
{
    ListElement *listElement = malloc(sizeof(ListElement));

    return listElement;
}

List *listNew(int length)
{
    List *list = malloc(sizeof(List));
    list->head = malloc(sizeof(ListElement));
    list->tail = malloc(sizeof(ListElement));
    list->head->next = NULL;
    list->head->data = NULL;
    list->tail->next = NULL;
    list->tail->data = NULL;
    // list->head = NULL;
    // list->tail = NULL;
    list->length = length;

    return list;
}

void destroyListElement(ListElement *listElement)
{
    if(listElement->next != NULL)
        destroyListElement(listElement->next);

    free(listElement);
}

void listDel(List *list)
{
    if(list != NULL)
    {
        if(list->head != NULL)
            destroyListElement(list->head);

        if(list->tail != NULL)
            free(list->tail);

        free(list);
    }
}

void listAddHead(List *list, void *data)
{
    ListElement *newElement = createListElement();
    newElement->data = data;
    newElement->next = NULL;

    if(list->head->data == NULL)
    {
        list->head = newElement;
        list->tail = newElement;
    }
    else
    {
        if(list->head->next != NULL)
        {
            newElement->next = list->head;
            list->head = newElement;
        }
        else
        {
            newElement->next = list->tail;
            list->head = newElement;
        }
    }
}

void *listRemoveHead(List *list)
{
    if(list->head->data != NULL && list->head->next == NULL)
    {
        list->head->data = NULL;
        list->tail->data = NULL;
    }
    else
        list->head = list->head->next;
}

void listAddTail(List *list, void *data)
{
    ListElement *newElement = createListElement();
    newElement->data = data;
    newElement->next = NULL;

    if(list->head->data == NULL)
    {
        list->head = newElement;
        list->tail = newElement;
    }
    else
    {
        if(list->head->next != NULL)
        {
            list->tail->next = newElement;
            list->tail = newElement;
        }
        else
        {
            list->tail = newElement;
            list->head->next = list->tail;
        }
    }
}

void *listRemoveTail(List *list)
{
    ListElement *del, *preDel;

    if(list->head->data != NULL && list->head->next == NULL)
    {
        list->head->data = NULL;
        list->tail->data = NULL;
    }
    else
    {
        del = list->head;

        while(del->next != NULL)
        {
            preDel = del;
            del = del->next;
        }

        list->tail = preDel;
        list->tail->next = NULL;
    }
}