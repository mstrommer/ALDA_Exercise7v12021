//
//  graph.cpp
//  ALDA_Exercise7v12021
//
//  Created by Michael Strommer on 10.06.21.
//

#include "graph.hpp"

int time;

// initialize graph
graph *initGraph() {
    int i, j;
    graph *g = (graph*)malloc(sizeof(graph));
    g->numNodes = 0;
    for (i = 0; i < MAX_NODES; i++) {
        g->nodes[i].name = NULL;
        g->nodes[i].color = WHITE;
        g->nodes[i].startTime = 0;
        g->nodes[i].endTime = 0;

        for (j = 0; j < MAX_NODES; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
    return g;
}

// reset the colors to white and clear all times
void resetGraph(graph *g) {
    int i;
    for (i = 0; i < g->numNodes; i++) {
        g->nodes[i].color = WHITE;
        g->nodes[i].startTime = 0;
        g->nodes[i].endTime = 0;
    }
}


// add a node to the graph if it does not exist yet and return the index of the node
int addNode(graph *g, char *name) {
    int i;
    
    for (i = 0; i < g->numNodes; i++) {
        // if we find a node with the name return the index
        if (strcmp(g->nodes[i].name, name) == 0) {
            return i;
        }
    }
    
    // reserve memory for the name of the node
    g->nodes[g->numNodes].name = (char *)malloc((strlen(name) + 1) *sizeof(char));
    strcpy(g->nodes[g->numNodes].name, name);
    
    // increase the number of nodes since we added a new node
    g->numNodes++;
    
    return g->numNodes - 1;
}

graph *readGraphFromFile(const char *filename){
    FILE *fp;
    char line[1000];
    char *pos;
    
    // our graph g
    graph *g;
    int source;
    int target;
    
    // initialize the new graph
    g = initGraph();
    
    // open the file
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Cannot open Makefile!!!\n");
        return NULL;
    }
    
    // loop through all lines of the file
    while (fgets(line, 1000, fp)) {
        // for debugging purposes:
        // printf("%s", line);
        
        line[strcspn(line, "\r\n")] = 0;
        
        // extract the first node name
        pos = strtok(line, " \n\r");
        // ignore any empty line
        if (pos == NULL) continue;
        
        // add the node to the graph
        target = addNode(g, pos);
        
        // ignore the colon
        pos = strtok(NULL, " \n\r");
        
        // read all dependencies of the target node stated on the same line
        while ((pos = strtok(NULL, " \n\r")) != NULL) {
            source = addNode(g, pos);
            
            // add an edge to the adjacency matrix
            g->adjMatrix[target][source] = 1;
            // for debugging purposes:
            // printf("[%d, %s] <- [%d, %s]\n", target, g->nodes[target].name, source, g->nodes[source].name);
        }
    }
    
    fclose(fp);
    return g;
}

list *topologySearch(graph *g) {
    // TODO: implement
    return NULL;
}

void dfs_visit(graph *g, int node, list *l) {
    // TODO: implement the recursive function here
}
