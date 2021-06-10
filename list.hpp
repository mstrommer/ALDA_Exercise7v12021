//
//  list.hpp
//  ALDA_Exercise7v12021
//
//  Created by Michael Strommer on 10.06.21.
//

#ifndef list_hpp
#define list_hpp

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "node.hpp"


struct _element {
    char *name;
    int color;
    int startTime;
    int endTime;
    struct _element *next;
};

typedef struct _element element;

struct _list
{
    element *head;
    int count;
};

typedef struct _list list;


list *l_init(void);
void l_insert(list *lst, node *node);
void l_print(list *lst);


#endif /* list_hpp */
