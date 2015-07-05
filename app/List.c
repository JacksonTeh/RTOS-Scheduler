#include <stdio.h>
#include <malloc.h>
#include "List.h"

ListElement *createListElement(void *data)
{
    ListElement *listElement = malloc(sizeof(ListElement));
    listElement->data = data;
    listElement->next = NULL;

    return listElement;
}

void destroyListElement(ListElement *listElement)
{
    if(listElement->next != NULL)
        destroyListElement(listElement->next);

    free(listElement);
}

List *listNew()
{
    List *list = malloc(sizeof(List));
    // list->head = malloc(sizeof(ListElement));
    // list->tail = malloc(sizeof(ListElement));
    // list->head->next = NULL;
    // list->head->data = NULL;
    // list->tail->next = NULL;
    // list->tail->data = NULL;
    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

void listDel(List *list)
{
    if(list != NULL)
    {
        if(isListEmpty(list))
            destroyListElement(list->head);

        if(list->tail != NULL)
            free(list->tail);

        free(list);
    }
}

int isListEmpty(List *list)
{
    if(list->head == NULL)
        return 0;

    return 1;
}

void listAddHead(List *list, void *data)
{
    ListElement *newElement = createListElement(data);

    if(!isListEmpty(list))
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

    list->length++;
}

void *listRemoveHead(List *list)
{
    ListElement *temp = NULL;

    if(!isListEmpty(list))
        return;

    if(list->head == list->tail)
        list->tail = list->tail->next;

    temp = list->head;
    list->head = list->head->next;

    list->length--;

    return temp->data;
}

void listAddTail(List *list, void *data)
{
    ListElement *newElement = createListElement(data);

    if(!isListEmpty(list))
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

    list->length++;
}

void *listRemoveTail(List *list)
{
    ListElement *del, *preDel = NULL, *temp = NULL;

    if(!isListEmpty(list))
        return;

    if(list->head == list->tail)
    {
        temp = list->head;
        list->head = list->head->next;
        list->tail = list->tail->next;
    }
    else
    {
        del = list->head;

        while(del->next != NULL)
        {
            preDel = del;
            del = del->next;
            temp = del;
        }

        list->tail = preDel;
        list->tail->next = NULL;
    }

    list->length--;

    return temp->data;
}
