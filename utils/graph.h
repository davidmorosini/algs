#ifndef GRAPH_H
#define GRAPH_H

#include "linkedlist.h"

typedef lst graph;

typedef struct node_graph{
    int ID;
    //vertices ajacentes;
    graph * adj_ver;
}data_node;

graph * new_graph(data_node * d);

graph * add_vertex(graph * g, data_node * dn);
graph * add_edge(graph * g, int ID_vertex, data_node * vertex);
graph * add_new_edge(graph * g, int ID_vertex, int ID_incidence);

data_node * get_data(lst_node * l);
data_node * new_data_node(int id);

int search_vetexs(graph * g, int ID1, int ID2);

void print_edges(graph * g);
void print_vertexs(graph * g);
void print_graph(graph * g);





#endif