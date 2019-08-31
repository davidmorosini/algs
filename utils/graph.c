#include "graph.h"

data_node * get_data(lst_node * l){
    data_node * data = (data_node *)get_data_node(l);
    return data;
}

data_node * new_data_node(int id){
    data_node * d = (data_node *)malloc(sizeof(data_node));
    assert(d != NULL);
    if(d != NULL){
        d -> ID = id;
        d -> adj_ver = NULL;
    }
    return d;
}

graph * new_graph(data_node * d){
    graph * g = new_lst(new_node(d));
    return g;
}

graph * add_vertex(graph * g, data_node * dn){
    if(g == NULL){
        g = new_graph(dn);
    }
    //colocar aqui inclusão ordenada
    g = add_end(g, new_node(dn));

    return g;
}

int search_vetexs(graph * g, int ID1, int ID2){
    int result = 0;
    lst_node * aux = get_start_node(g);
    if(aux != NULL){
        while(aux != NULL){
            int id = get_data(aux) -> ID;
            if(id == ID1 || id == ID2){
                result++;
            } 
            aux = get_prox_node(aux);
        }
    }
    return result;
}

graph * add_edge(graph * g, int ID_vertex, data_node * vertex){
    lst_node * aux = get_start_node(g);
    if(aux != NULL){
        while(aux != NULL && get_data(aux) -> ID != ID_vertex){
            aux = get_prox_node(aux);
        }

        if(aux != NULL){
            data_node * d_adj = get_data(aux);
            d_adj -> adj_ver = add_end(d_adj -> adj_ver, new_node(vertex));
        }
    }
    return g;
}

graph * add_new_edge(graph * g, int ID_vertex, int ID_incidence){
    lst_node * aux = get_start_node(g);
    if(aux != NULL && search_vetexs(g, ID_vertex, ID_incidence) == 2){
        g = add_edge(g, ID_vertex, new_data_node(ID_incidence));
        g = add_edge(g, ID_incidence, new_data_node(ID_vertex));
    }
    return g;
}

void print_edges(graph * g){

}

void print_vertexs(graph * g){
    if(g != NULL){
        printf("Exibindo os Vertices do Grafo:\n");
        lst_node * aux = get_start_node(g);
        while(aux != NULL){
            printf("(%i)\n", get_data(aux) -> ID);
            aux = get_prox_node(aux);
        }
    }else{
        printf("Grafo Vazio\n");
    }
}

void print_graph(graph * g){
    lst_node * aux = get_start_node(g);
    if(aux != NULL){
        printf("Exibindo o Grafo:\n");
        while(aux != NULL){
            printf("Vertex (%i) : incidence in -> ", get_data(aux) -> ID);
            graph * adj = get_data(aux) -> adj_ver;
            if(adj != NULL){
                lst_node * var = get_start_node(adj);
                while(var != NULL){
                    printf("(%i) ", get_data(var) -> ID);
                    var = get_prox_node(var);
                }
                printf("\n");
            }else{
                printf("[no edges]\n");
            }
            
            aux = get_prox_node(aux);
        }
    }else{
        printf("Grafo Vazio\n");
    }
}