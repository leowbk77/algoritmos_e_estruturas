// .c
#include <stdio.h>
#include <stdlib.h>
#include "TSeqList.h"

struct lista
{
    int aln_num; // contador do numero de alunos da lista
    aln aluno[ALNMAX]; // vetor de alunos
};

list *create_list(){
    list *p_list = NULL;

    p_list = malloc(sizeof(struct lista));
    if(p_list == NULL) return NULL;
    
    p_list->aln_num = 0;

    return p_list;
}

int free_list(list *p_list){
    if(p_list == NULL) return -1;

    free(p_list);

    return 0;
}

int insert_end(list *p_list, aln al){
    if((p_list == NULL) || (p_list->aln_num == ALNMAX)) return -1;

    p_list->aluno[p_list->aln_num] = al;
    p_list->aln_num++;

    return 0;
}

int insert_start(list *p_list, aln al){
    if((p_list == NULL) || (p_list->aln_num == ALNMAX)) return -1;

    for(int i = p_list->aln_num; i >= 0; i--){
        p_list->aluno[i+1] = p_list->aluno[i];
    }
    p_list->aluno[0] = al;
    p_list->aln_num++;

    return 0;
}

int insert_by_order(list *p_list, aln al){
    if((p_list == NULL) || (p_list->aln_num == ALNMAX)) return -1;

    int pos = 0;

    // encontra a posicao que deve ser inserido o aluno
    while(pos < p_list->aln_num && p_list->aluno[pos].matricula < al.matricula){
        pos++;
    }

    // anda com a lista pra frente até a posicao que deve ser inserido
    for(int i = p_list->aln_num; i >= pos; i--){ 
        p_list->aluno[i+1] = p_list->aluno[i];
    }

    // insere o aluno na posicao
    p_list->aluno[pos] = al;
    p_list->aln_num++;

    return 0;
}

int consult_by_pos(list *p_list, int pos, aln *al){
    if((p_list == NULL) || (pos <= 0) || (pos > p_list->aln_num)) return -1;

    *al = p_list->aluno[pos-1];

    return 0;
}

int consult_by_mat(list *p_list, int mat, aln *al){
    if(p_list == NULL) return -1;

    int pos = 0;

    // percorre o vetor e encontra a posicao da matricula procurada
    while((pos < p_list->aln_num) && (p_list->aluno[pos].matricula != mat)){
        pos++;
    }
    if(pos == p_list->aln_num) return -1; // se percorre a lista toda nao encontra a mat e retorna erro

    *al = p_list->aluno[pos]; // armazena os dados do aluno da posicao da matricula buscada

    return 0;
}

int rm_list(list *p_list, int mat){
    if((p_list == NULL) || (p_list->aln_num == 0)) return -1;

    int pos = 0;

    // busca qual posicao esta o aluno a ser removido atraves da matricula
    while(pos < p_list->aln_num && p_list->aluno[pos].matricula != mat){
        pos++;
    }
    if(pos == p_list->aln_num) return 0; // se percorre todo o vetor retorna 0

    // coloca os elementos posteriores uma casa a menos no vetor (sobrescreve o elemento a ser removido)
    for(int i = pos; i < (p_list->aln_num-1); i++){ 
        p_list->aluno[i] = p_list->aluno[i+1];
    }
    p_list->aln_num--; // "retira" um elemento da lista

    return 0;
}

int rm_end(list *p_list){
    if((p_list == NULL) || (p_list->aln_num == 0)) return -1;
    p_list->aln_num--; // remove um elemento do contador 

    return 0;
}

int rm_start(list *p_list){
    if((p_list == NULL) || (p_list->aln_num == 0)) return -1;

    for(int i = 0; i < p_list->aln_num-1; i++){
        p_list->aluno[i] = p_list->aluno[i+1]; // move os alunos no vetor
    }

    p_list->aln_num--; // remove um aluno do contador

    return 0;
}

int rm_optmz(list *p_list, int mat){
    if((p_list == NULL) || (p_list->aln_num == 0)) return -1;

    int pos = 0;
    while(pos < p_list->aln_num && p_list->aluno[pos].matricula != mat){
        pos++;
    }
    if(pos == p_list->aln_num) return 0; // percorreu todo o vetor

    p_list->aln_num--; // remove um aluno do contador
    p_list->aluno[pos] = p_list->aluno[p_list->aln_num]; // move o ultimo aluno para a posicao a ser apagada

    return 0;
}

int list_size(list *p_list){
    if(p_list == NULL) return -1;

    return p_list->aln_num;
}

int is_full(list *p_list){
    if(p_list == NULL) return -1;

    return (p_list->aln_num == ALNMAX);
}   

int is_empty(list *p_list){
    if(p_list == NULL) return -1;

    return (p_list->aln_num == 0);
}