#include <stdio.h>
#include "utils/linkedlist.h"

#define type_name(expr) \
    (_Generic((expr), \
              char: "char", unsigned char: "unsigned char", signed char: "signed char", \
              short: "short", unsigned short: "unsigned short", \
              int: "int", unsigned int: "unsigned int", \
              long: "long", unsigned long: "unsigned long", \
              long long: "long long", unsigned long long: "unsigned long long", \
              float: "float", \
              double: "double", \
              long double: "long double", \
              void*: "void*", \
              default: "?"))


/*
    Arquivo para testes das estruturas de dados
*/

/*
    Estruturas de dados e Funções disponíveis

    typedef struct cell{
        int num;
    }cell;

    typedef struct node{
        cell * data;
        struct node * prox;
    }lst_node;

    typedef struct linkedlist{
        lst_node * start, * end;
    }lst;

    //FUNÇÕES
    cell * new_cell(int num);
    lst_node * new_node(cell * data, lst_node * prox_node);
    lst * new_lst(lst_node * start);

    lst * add_init(lst * l, lst_node * n);
    lst * add_end(lst * l, lst_node * n);
    lst * add_ordened(lst * l, lst_node * n);

*/

//Testando com ED genérica (definida aqui)
typedef struct celll{
    int num;
}celll;

/* PULO DO GATO AQUI*/
celll * get_data(lst_node * l);

celll * new_cell(int num);
void print_lst(lst * l);


int main(int argc, char * argv[]){

    printf("Arquivo de teste\n");
    printf("Criando uma nova lista..");
    int num = 5;
    lst * l = new_lst(new_node(new_cell(num)));
    assert((get_data(get_start_node(l)) -> num) == num);
    printf("\nCriado com sucesso, valor do no criado = %i\n",(get_data(get_start_node(l)) -> num));

    l = add_init(l, new_node(new_cell(3)));
    l = add_end(l, new_node(new_cell(9)));
    l = add_end(l, new_node(new_cell(67)));

    printf("Lista final (deve ser): 3 -> 5 -> 9 -> 67 -> null\n");
    printf("Resultado da Execucao: ");
    print_lst(l);
    printf("\n");

    printf("TAMANHO DA LISTA: %i\n", get_size_lst(l));


    return 0;
}

celll * get_data(lst_node * l){
    celll * data = (celll *)get_data_node(l);
    return data;
}

celll * new_cell(int num){
    celll * c = (celll *)malloc(sizeof(celll));
    assert(c != NULL);
    if(c != NULL){
        c -> num = num;
    }
    return c;
}

void print_lst(lst * l){
    if(l != NULL && l -> start != NULL){
        lst_node * aux = l -> start;
        while(aux != NULL){
            printf("%i -> ", ((celll *)(aux -> data)) -> num);
            aux = aux -> prox;
        }
        printf("null");
    }
}