#ifndef _linkedlisth_
#define _linkedlisth_

#define SUCCESS 0
#define INVALID_NULL_POINTER -1
#define OUT_OF_MEMORY -2
#define OUT_OF_RANGE -3
#define ELEM_NOT_FOUND -4

typedef struct data data;
typedef struct linkedlist linkedlist;

struct data{
    int placeholderInt;
    int placeholderVector[10];
    char placeholderString[10];
};

linkedlist *create_list();
int list_free(linkedlist *list);
int insert_front(data content, linkedlist *list);
int insert_back(data content, linkedlist *list);
int insert_in(int position, data content, linkedlist *list); // first pos is 0

#endif