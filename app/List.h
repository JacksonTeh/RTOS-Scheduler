#ifndef List_H
#define List_H

typedef struct ListElement_t ListElement;
struct ListElement_t
{
  ListElement *next;
  void *data;
};

typedef struct
{
  ListElement *head;
  ListElement *tail;
  int length;
} List;

ListElement *createListElement(void *data);
void destroyListElement(ListElement *listElement);
List *listNew();
void listDel(List *list);

void listAddHead(List *list, void *data);
void listAddTail(List *list, void *data);
void *listRemoveHead(List *list);
void *listRemoveTail(List *list);
int isListEmpty(List *list);

void listInit(List *list);
void listElementInit(ListElement *listElement, void *data);

#endif // List_H