// tad
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TMat2D.h"

struct Matrice2D // matriz 
{
    int nrows; // numero de linhas da matriz
    int ncolumns; // numero de colunas da matriz
    double *data; // ponteiro para os dados da matriz
};

Matr *create_mat(int nrw, int ncln){ // funcao que cria a matriz
    Matr *m = NULL;

    m = malloc(sizeof(Matr)); // aloca o espaco da matriz
    if(m == NULL){ // se erro return NULL
        return NULL;
    }

    m->nrows = nrw;
    m->ncolumns = ncln;
    m->data = malloc((nrw*ncln) * sizeof(double)); // aloca o espaco para os dados da matriz
    if(m->data == NULL){ // se erro libera a memoria da matriz e return NULL
        free(m);
        return NULL;
    }

    return m; // retorno da alocacao da matriz
}

void mat_set_value(Matr *p_matrice, int row, int col, double value){
    int pos = 0;

    pos = row * p_matrice->nrows + col;
    p_matrice->data[pos] = value;
}

void mat_get_value(Matr *p_matrice, int row, int col, double *value){
    int pos = 0;

    pos = row * p_matrice->nrows + col;
    *value = p_matrice->data[pos]; 
}

int mat_free(Matr *p_matrice){ // funcao que libera a memoria alocada

    if(p_matrice == NULL) return -1;// se já é ponteiro nulo retorna erro

    free(p_matrice->data);
    free(p_matrice);

    return 0; // execucao terminada retorna 0
}

void mat_show_value(Matr *p_matrice, int row, int col){ //funcao que exibe um valor especifico da matriz
    int pos = 0;

    pos = col * p_matrice->nrows + row;

    printf("%.1lf", p_matrice->data[pos]);
}

void mat_show_mat(Matr *p_matrice){ // funcao que exibe toda a matriz
    int pos = 0;

    for(int i = 0; i < p_matrice->nrows ; i++){
        for(int j = 0; j < p_matrice->ncolumns; j++){
            pos = j * p_matrice->nrows + i;
            printf("%.1lf\t", p_matrice->data[pos]);
        }
        printf("\n");
    }
}

int mat_add(Matr *p_mat1, Matr *p_mat2, Matr *p_soma){ // funcao que soma duas matrizes e devolve dentro de outra (necessário alocar as 3 antes);
    int ordem = p_mat1->ncolumns * p_mat1->nrows; // pega a ordem da primeira para as verificacoes;

    if((ordem) != (p_mat2->ncolumns * p_mat2->nrows) || (ordem) != (p_soma->ncolumns * p_soma->nrows)){
        return -1; // retorna -1 se as ordens das funcoes forem diferentes;
    }else{    
        for(int i = 0; i < ordem; i++){
            p_soma->data[i] = p_mat1->data[i] + p_mat2->data[i];
        }
        return 0; // retorna 0 se o processo foi concluido;
    }
}

int mat_random(Matr *p_matrice, int v_min, int v_max){ // funcao que preenche a matriz
    if(p_matrice == NULL) return -1; // retorna -1 se matriz NULL

    int ordem = p_matrice->ncolumns * p_matrice->nrows;

    srand(time(NULL));
    for(int i = 0; i < ordem; i++){
        p_matrice->data[i] = rand() % ((v_max +1) - v_min) + v_min;
    }

    return 0;
}

int mat_scale(Matr *p_matrice, int scale){
    if(p_matrice == NULL) return -1;

    int ordem = p_matrice->ncolumns * p_matrice->nrows;

    for(int i = 0; i < ordem; i++){
        p_matrice->data[i] *= scale;
    }

    return 0;
}

int mat_tr(Matr *p_matrice, double *tr){

    if(p_matrice == NULL) return -1;
    if(p_matrice->ncolumns != p_matrice->nrows) return -1;

    int pos = 0;
    *tr = 0;

    for(int i = 0; i < p_matrice->ncolumns; i++){
        pos = i * p_matrice->nrows + i;
        *tr += pos;
    }

    return 0;
}

double *mat_line_som(Matr *p_matrice){
    if(p_matrice == NULL) return NULL;

    double *vet = NULL;
    int pos = 0;

    vet = malloc(p_matrice->nrows * sizeof(double));
    if(vet == NULL) return NULL;

    for(int i = 0; i < p_matrice->nrows; i++){
        for(int j = 0; j < p_matrice->ncolumns; j++){
            pos = j * p_matrice->ncolumns + i;
            vet[i] += p_matrice->data[pos];
        }
    }

    return vet;
}

double *mat_col_som(Matr *p_matrice){
    if(p_matrice == NULL) return NULL;

    double *vet = NULL;
    int pos = 0;

    vet = malloc(p_matrice->ncolumns * sizeof(double));
    if(vet == NULL) return NULL;

    for(int i = 0; i < p_matrice->nrows; i++){
        for(int j = 0; j < p_matrice->ncolumns; j++){
            pos = i * p_matrice->ncolumns + j;
            vet[i] += p_matrice->data[pos];
        }
    }

    return vet;
}

int vet_free(double *p_som){
    if(p_som == NULL) return -1;

    free(p_som);

    return 0;
}

// TERMINAR FUNCAO ABAIXO

Matr *mat_multiply(Matr *p_mat1, Matr *p_mat2){
    if(p_mat1->ncolumns != p_mat2->nrows){ // verifica se o numero de colunas da primeira é diferente do numero de linhas da segunda;
        return NULL; // se diferentes retorna NULL;
    }

    Matr *m_mult = NULL;

    m_mult = create_mat(p_mat1->nrows, p_mat2->ncolumns); // cria espaço da matriz resultante;
    if(m_mult == NULL) return NULL; // se nao alocar retorna NULL;

    int pos = 0; // percorrer a matriz
    int pos1 = 0;
    int pos2 = 0; 

    for(int i = 0; i < p_mat1->nrows; i++){

        for(int j = 0; j < p_mat1->ncolumns; j++){
            
            for(int k = 0; k < p_mat2->ncolumns; k++){
                pos = j * m_mult->nrows + i; 
                pos1 = k * p_mat1->nrows + i;
                pos2 = j * p_mat2->nrows + k;
                m_mult->data[pos] += p_mat1->data[pos1] * p_mat2->data[pos2]; // multiplica valor 1 e valor 2
            }

        }
    }

    return m_mult;
}


// pos = j * nrows + i    | percorre por linhas;
// pos = i * ncolumns + j | percorre por colunas;