//
//  graph.hpp
//  ALDA_Exercise7v12021
//
//  Created by Michael Strommer on 10.06.21.
//

#ifndef graph_hpp
#define graph_hpp

#include <stdio.h>
#include <stdlib.h>
#include "list.hpp"
#include "node.hpp"

#define MAX_NODES   30
#define WHITE       0
#define GRAY        1
#define BLACK       2


// structure for a grpah defined by an adjacency matrix
typedef struct _graph {
    int time;
    int numNodes;
    node nodes[MAX_NODES];
    int adjMatrix[MAX_NODES][MAX_NODES];
} graph;

// function prototypes
graph *initGraph();
graph *readGraphFromFile(const char *filename);
int addNode(graph *g, char *name);
void dfs_visit(graph *g, int node, list *l);
list *topologySearch(graph *g);

#endif /* graph_hpp */
