//
//  sort.hpp
//  ALDA_Exercise5v12021_Solution
//
//  Created by Michael Strommer on 21.05.21.
//

#ifndef bintree_hpp
#define bintree_hpp

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node_ {
    int key;
    char *data; // darf nicht verändert werden!
    struct node_ *left;
    struct node_ *right;
} node;

typedef struct binTree_ {
    int size;
    node *root;
} binTree;

// Funktionsprototypen

binTree *t_init();
node *insertNode(node *, int, const char *);
node *insert(binTree *, int, const char *);
int evaluateExpression(node *);

#endif /* bintree_hpp */
