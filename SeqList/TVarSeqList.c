#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "TVarSeqList.h"

struct lista{
    int size; // tamanho atual da lista alocado (size * elementos)
    int fill; // quantidade de elementos preenchidos da lista
    int init; // quantidade inicial de elementos alocados
    aln *aluno; // ponteiro para a lista
};

list *create_list(int n_max){
    list *p_list = NULL;

    p_list = malloc(sizeof(list)); // aloca a lista
    if(p_list == NULL) return NULL;

    p_list->aluno = malloc(n_max * sizeof(aln)); // aloca os elementos da lista
    if(p_list->aluno == NULL) return NULL;

    p_list->size = n_max; // guarda o tamanho da lista alocada
    p_list->init = n_max; // guarda o numero de elementos alocados pela primeira vez
    p_list->fill = 0; // inicia a lista com nenhum elemento preenchido

    return p_list;
}

int free_list(list *p_list){
    if(p_list == NULL) return -1;

    free(p_list->aluno);
    free(p_list);

    return 0;
}

// FUNCAO QUE ALTERA TAMANHO

// funcao que aumenta o tamanho da lista
int realloc_list(list *p_list){
    if(p_list == NULL || p_list->aluno == NULL) return -1;

    p_list->aluno = realloc(p_list->aluno, ((p_list->size + p_list->init) * (sizeof(aln))) );
    if(p_list->aluno == NULL) return -1;

    p_list->size += p_list->init;

    return 0;
}
// funcao que verifica preenchimento
int ver_size(int list_size, int list_fill){
    if(list_size == list_fill){
        return -1;
    }else return 0;
}

// FIM ALTERA TAMANHO

int insert_end(list *p_list, aln al){
    if(p_list == NULL) return -1;

    // se a lista estiver toda preechida aumenta o tamanho;
    if(ver_size(p_list->size, p_list->fill)) realloc_list(p_list);

    p_list->fill++;
    p_list->aluno[p_list->fill] = al;

    return 0;
}

int insert_start(list *p_list, aln al){
    if(p_list == NULL || p_list->aluno == NULL) return -1;

    // se a lista estiver toda preechida aumenta o tamanho;
    if(ver_size(p_list->size, p_list->fill)) realloc_list(p_list);
    
    for(int i = p_list->fill; i >= 0; i--){
        p_list->aluno[i+1] = p_list->aluno[i];
    } 

    p_list->fill++;
    p_list->aluno[0] = al;

    return 0;
}

int insert_by_order(list *p_list, aln al){
    if(p_list == NULL || p_list->aluno == NULL) return -1;

    // se a lista estiver toda preechida aumenta o tamanho;
    if(ver_size(p_list->size, p_list->fill)) realloc_list(p_list);

    int pos = 0;
    while(pos < p_list->fill && p_list->aluno[pos].matricula < al.matricula){
        pos++;
    }

    for(int i = p_list->fill; i >= pos; i--){
        p_list->aluno[i+1] = p_list->aluno[i];
    }

    p_list->fill++;
    p_list->aluno[pos] = al;

    return 0;
}

int consult_by_pos(list *p_list, int pos, aln *al){
    if(p_list == NULL || p_list->aluno == NULL ||al == NULL) return -1;

    *al = p_list->aluno[pos-1];

    return 0;
}

int consult_by_mat(list *p_list, int mat, aln *al){
    if(p_list == NULL || p_list->aluno == NULL || al == NULL) return -1;

    int pos = 0;
    while((pos < p_list->fill) && (p_list->aluno[pos].matricula != mat)){
        pos++;
    }
    if(pos == p_list->fill) return -1; // se percorre a lista toda nao encontra a mat e retorna erro

    *al = p_list->aluno[pos];

    return 0;
}

int rm_list(list *p_list, int mat){
    if(p_list == NULL || p_list->aluno == NULL) return -1;

    int pos = 0;
    while((pos < p_list->fill) && (p_list->aluno[pos].matricula != mat)){
        pos++;
    }
    if(pos == p_list->fill) return -1; // se percorre a lista toda nao encontra a mat e retorna erro

    for(int i = pos; i >= (p_list->fill-1); i++){
        p_list->aluno[i] = p_list->aluno[i+1];
    }
    p_list->fill--;

    return 0;
}

int rm_end(list *p_list){
    if(p_list == NULL || p_list->aluno == NULL || p_list->fill == 0) return -1;

    p_list->fill--;

    return 0;
}

int rm_start(list *p_list){
    if(p_list == NULL || p_list->aluno == NULL || p_list->fill == 0) return -1;

    for(int i = 0; i < (p_list->fill-1); i++){
        p_list->aluno[i] = p_list->aluno[i+1];
    }
    p_list->fill--;

    return 0;
}

int rm_optmz(list *p_list, int mat){
    if(p_list == NULL || p_list->aluno == NULL || p_list->fill == 0) return -1;
    
    int pos = 0;
    while((pos < p_list->fill) && (p_list->aluno[pos].matricula != mat)){
        pos++;
    }
    if(pos == p_list->fill) return -1;

    p_list->fill--;
    p_list->aluno[pos] = p_list->aluno[p_list->fill];

    return 0;
}

int list_size(list *p_list){
    if(p_list == NULL) return -1;

   return p_list->fill;
}

int is_full(list *p_list){    
    if(p_list == NULL) return -1;
    return (p_list->fill == p_list->size);
}

int is_empty(list *p_list){
    if(p_list == NULL) return -1;
    return (p_list->fill == 0);
}

int compactar_lista(list *p_list){
    if(p_list == NULL || ver_size(p_list->size, p_list->fill)) return -1;

    float aloc = 0.0;
    aloc = ceil(p_list->fill/p_list->init)*p_list->init;

    if(aloc < p_list->size){
        p_list->aluno = realloc(p_list->aluno, (aloc * sizeof(aln)));
        if(p_list->aluno == NULL) return -1;
    }
    p_list->size = aloc;
    
    return 0;
}