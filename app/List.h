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

List *listNew(int length);
void listDel(List *list);
void listAdd(List *list, void *data);
void *listRemove(List *list);
int listIsEmpty(List *list);
int listIsFull(List *list);

#endif // List_H