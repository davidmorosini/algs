/*
    David Morosini de Assumpção
*/

#include "linkedlist.h"

/*Funções para inicialização das estruturas de dados*/
lst_node * new_node_(cell * data, lst_node * prox_node){
    lst_node * n = (lst_node *)malloc(sizeof(lst_node));
    assert(n != NULL);
    if(n != NULL){
        n -> data = data;
        n -> prox = prox_node;
    }
    return n;
}

lst_node * new_node(cell * data){
    lst_node * n = (lst_node *)malloc(sizeof(lst_node));
    assert(n != NULL);
    if(n != NULL){
        n -> data = data;
        n -> prox = NULL;
    }
    return n;
}


lst * new_lst(lst_node * start){
    lst * l = (lst *)malloc(sizeof(lst));
    assert(l != NULL);
    if(l != NULL){
        l -> start = start;
        l -> end = start;
    }
    return l;
}

lst * add_init(lst * l, lst_node * n){
    if(l == NULL || l -> start == NULL){
        l = new_lst(n);
    }else{
        n -> prox = l -> start;
        l -> start = n;
    }
    return l;
}

lst * add_end(lst * l, lst_node * n){
    if(l == NULL || l -> start == NULL){
        l = new_lst(n);
    }else{
        l -> end -> prox = n;
        l -> end = n;
    }
    return l;
}

cell * get_data_node(lst_node * l){
    cell * data;
    if(l != NULL){
        data = l -> data;
    }
    return data;
}

lst_node * get_prox_node(lst_node * l){
    lst_node * lp = NULL;
    assert(l != NULL);
    if(l != NULL){
        lp = l -> prox;
    }
    return lp;
}

lst_node * get_start_node(lst * l){
    lst_node * ls = NULL;
    if(l != NULL){
        ls = l -> start;
    }
    return ls;    
}

lst_node * get_end_node(lst * l){
    lst_node * le = NULL;
    if(l != NULL){
        le = l -> end;
    }
    return le;
}

int get_size_lst(lst * l){
    int size = 0;
    assert(l != NULL);
    if(l != NULL && l -> start != NULL){
        size = 1;
        //se o comeco for igual ao fim, significa que só tem um
        if(l -> start != l-> end){
            lst_node * aux = l -> start -> prox;
            while(aux != NULL){
                size++;
                aux = aux -> prox;
            }
        }
    }
    return size;
}
