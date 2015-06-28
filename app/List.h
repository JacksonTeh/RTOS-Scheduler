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

ListElement *createListElement();
void destroyListElement(ListElement *listElement);
List *listNew(int length);
void listDel(List *list);

void listAddHead(List *list, void *data);
void listAddTail(List *list, void *data);
void *listRemoveHead(List *list);
void *listRemoveTail(List *list);

#endif // List_H