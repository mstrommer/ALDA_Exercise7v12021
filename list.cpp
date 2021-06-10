//
//  list.cpp
//  ALDA_Exercise7v12021
//
//  Created by Michael Strommer on 10.06.21.
//
#include "list.hpp"

list *l_init() {
    list * lst = (list *)malloc(sizeof(list));
    lst->head = NULL;
    lst->count = 0;
    
    return lst;
}

void l_insert(list *lst, node *node)
{
    element *new_data = (element *)malloc(sizeof(element));
    new_data->name = (char*) malloc(strlen(node->name) + 1);
    strcpy(new_data->name, node->name);
    new_data->color = node->color;
    new_data->startTime = node->startTime;
    new_data->endTime = node->endTime;
    new_data->next = lst->head;
    lst->head = new_data;
    lst->count++;
}

void l_print(list *lst) {
    element *tmp = lst->head;
    
    while (tmp != NULL) {
        printf("%s (%i)\n", tmp->name, tmp->endTime);
        tmp = tmp->next;
    }
}
