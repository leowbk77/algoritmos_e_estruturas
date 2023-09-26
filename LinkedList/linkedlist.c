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

int list_free(linkedlist *list){
    return SUCCESS;
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
    if(list == NULL){
        return INVALID_NULL_POINTER;
    } else {
        llist_node *node = malloc(sizeof(llist_node));
        if(node == NULL) return OUT_OF_MEMORY;

        node->nodeData = content;
        node->next = NULL;

        if(list->head == NULL){
            list->head = node;
        } else {
            llist_node *auxNode = list->head;
            while(auxNode->next != NULL){
                auxNode = auxNode->next;
            }
            auxNode->next = node;
        }
        list->size++;
        return SUCCESS;
    }
}

int insert_in(int position, data content, linkedlist *list){
    if(list == NULL){
        return INVALID_NULL_POINTER;
    } else {
        if(position > list->size) return OUT_OF_RANGE;

        llist_node *node = malloc(sizeof(llist_node));
        if(node == NULL) return OUT_OF_MEMORY;

        node->nodeData = content;

        if(position == 0){
            node->next = list->head;
            list->head = node;
        } else {
            llist_node *auxNodeOne = list->head;
            llist_node *auxNodeTwo = list->head->next;
            int i = 1;
            while(i < position){
                auxNodeOne = auxNodeOne->next;
                auxNodeTwo = auxNodeTwo->next;
                i++;
            }
            auxNodeOne->next = node;
            node->next = auxNodeTwo;
            list->size++;
        }
        return SUCCESS;
    }
}