#include "utils/graph.h"


//Implementar algoritmos das aulas aqui

int main(int argc, char * argv[]){
    
    graph * g = new_graph(new_data_node(1));
    g = add_vertex(g, new_data_node(2));
    g = add_vertex(g, new_data_node(3));
    g = add_vertex(g, new_data_node(4));

    g = add_new_edge(g, 1, 2);
    
    print_graph(g);




    return 0;
}
