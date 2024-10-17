// tad
/*
    TIPOS
*/

typedef struct Matrice2D Matr;

/*
    FUNÇÕES
*/

// funcao de criacao da matriz | retorna ponteiro se sucesso; NULL se erro ;
Matr *create_mat(int nrw, int ncln); 

// funcao de remocao da matriz | retorna 0 se sucesso; -1 se erro;
int mat_free(Matr *p_matrice); 

// funcao que seta um valor em uma posicao na data da matriz;
void mat_set_value(Matr *p_matrice, int row, int col, double value); 

// funcao que pega um valor em uma posicao na data da matriz;
void mat_get_value(Matr *p_matrice, int row, int col, double *value); 

// funcao que exibe alguma posicao da matriz;
void mat_show_value(Matr *p_matrice, int row, int col);

// funcao que exibe toda a matriz;
void mat_show_mat(Matr *p_matrice);

// fncao que soma duas matrizes e guarda em uma terceira | retorna -1 se matrizes de ordem diferentes; 0 se sucesso;
int mat_add(Matr *p_mat1, Matr *p_mat2, Matr *p_soma); // nao testada;

// funcao que preenche a matriz com numeros aleatórios | retorna -1 se matriz apontar para NULL ou 0 se sucesso;
int mat_random(Matr *p_matrice, int v_min, int v_max);

// funcao que multiplica uma matriz por outra | retorna ponteiro para a matriz resultante ou NULL caso erro;
Matr *mat_multiply(Matr *p_mat1, Matr *p_mat2);

// funcao que multiplica uma matriz por um valor escalar
int mat_scale(Matr *p_matrice, int scale);

// funcao que calcula o traco da matriz
int mat_tr(Matr *p_matrice, double *tr);

// funcao que retorna um vetor com a soma das linhas
double *mat_line_som(Matr *p_matrice); // nao testada

// funcao que retorna um vetor com a soma das colunas
double *mat_col_som(Matr *p_matrice); // nao testada

// libera o vetor
int vet_free(double *p_som);