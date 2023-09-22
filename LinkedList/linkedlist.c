#include <stdlib.h>
#include "linkedlist.h"

typedef struct linked_list_node llist_node;

struct linked_list_node{
    data nodeData;
    llist_node *next;
};

struct linkedlist{
    llist_node *head;
    int size;
};

linkedlist *create_list(){
    linkedlist *list;
    if(list = malloc(sizeof(linkedlist))){
        list->head = NULL;
        list->size = 0;
    }
    return list;
}

int insert_front(data content, linkedlist *list){
    if(list == NULL){
        return INVALID_NULL_POINTER;
    } else {
        llist_node *node = malloc(sizeof(llist_node));
        if(node == NULL) return OUT_OF_MEMORY;
        node->nodeData = content;
        node->next = list->head;
        list->head = node;
        list->size++;
        return SUCCESS;
    }
}

int insert_back(data content, linkedlist *list){

}

int insert_in(int position, data content, linkedlist *list){

}