// Test definitions. Do NOT edit this file!

#include <tuple>

//#define CATCH_CONFIG_MAIN // defines main() automatically
#include "lib/catch.hpp"
#include "graph.hpp"

// =====================
// Graph Testcases
// ---------------------

TEST_CASE("Test1", "checkNodes")
{
    graph *g = readGraphFromFile("makefile_");
    REQUIRE(g != nullptr);
    topologySearch(g);
    INFO("Testing if nodes have been modified accordingly.");
    for(int i = 0; i < g->numNodes; i++){
        REQUIRE(g->nodes[i].color == BLACK);
        REQUIRE(g->nodes[i].startTime != 0);
        REQUIRE(g->nodes[i].endTime != 0);
    }
}

TEST_CASE("Test2", "checkEndTimes")
{
    graph *g = readGraphFromFile("makefile_");
    REQUIRE(g != nullptr);
    topologySearch(g);
    INFO("Testing if endTime is set accordingly.");
    for(int i = 0; i < g->numNodes; i++){
        if(strcmp(g->nodes[i].name,"treeApp") == 0){
            REQUIRE(g->nodes[i].endTime < 5);
        } else if(strcmp(g->nodes[i].name,"grammar.g") == 0){
            REQUIRE(g->nodes[i].endTime > 10);
        }
    }
}

TEST_CASE("Test3", "checkList")
{
    graph *g = readGraphFromFile("makefile_");
    REQUIRE(g != nullptr);
    list* list = topologySearch(g);
    INFO("Testing if list is not empty or not null.");
    REQUIRE(list != nullptr);
    REQUIRE(list->count != 0);
}

TEST_CASE("Test4", "checkListNodeCount")
{
    graph *g = readGraphFromFile("makefile_");
    REQUIRE(g != nullptr);
    list* list = topologySearch(g);
    INFO("(1) Testing if there is a valid list.");
    REQUIRE(list != nullptr);
    INFO("(2) Testing if list contains all elements.");
    REQUIRE(list->count == 17);
}

TEST_CASE("Test5", "checkIfTreeAppIsLast")
{
    graph *g = readGraphFromFile("makefile_");
    REQUIRE(g != nullptr);
    list* list = topologySearch(g);
    INFO("(1) Testing if there is a valid list.");
    REQUIRE(list != nullptr);
    INFO("(2) Testing if treeApp is the last element in the list.");
    element *tmp = list->head;
    while (tmp != NULL) {
        if(tmp->next == NULL)
            break;
        tmp = tmp->next;
    }
    REQUIRE(tmp != nullptr);
    REQUIRE(strcmp(tmp->name,"treeApp")==0);
}

TEST_CASE("Test6", "checkOrder")
{
    graph *g = readGraphFromFile("makefile_");
    REQUIRE(g != nullptr);
    list* list = topologySearch(g);
    INFO("(1) Testing if there is a valid list.");
    REQUIRE(list != nullptr);
    REQUIRE(list->head != nullptr);
    REQUIRE(list->count == 17);
    INFO("(2) Testing if the order is correct.");
    printf("Printing list:\n\n");
    l_print(list);
    element *current = list->head;
    while(current){
        element *tmp = current->next;
        while(tmp){
            INFO("'" << current->name << "' should have a larger end time than " << current->endTime);
            REQUIRE(tmp->endTime < current->endTime);
            tmp = tmp->next;
        }
        current = current->next;
    }
}
