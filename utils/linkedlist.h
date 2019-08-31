/*
    David Morosini de Assumpção
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


//trocando para um formato genérico
typedef void cell;
/*Célula de conteúdo para cada nó da lista*/
//typedef struct cell{
//    int num;
//}cell;

/*Estrutura de dados para um nó da lista*/
typedef struct node{
   cell * data;
   struct node * prox;
}lst_node;

/* Estrutura de dados para uma lista com centinela*/
typedef struct linkedlist{
    lst_node * start, * end;
}lst;

/*Funções para inicialização das estruturas de dados*/
lst_node * new_node_(cell * data, lst_node * prox_node);
lst_node * new_node(cell * data);
lst * new_lst(lst_node * start);

lst * add_init(lst * l, lst_node * n);
lst * add_end(lst * l, lst_node * n);
cell * get_data_node(lst_node * l);

lst_node * get_prox_node(lst_node * l);
lst_node * get_start_node(lst * l);
lst_node * get_end_node(lst * l);

int get_size_lst(lst * l);


#endif