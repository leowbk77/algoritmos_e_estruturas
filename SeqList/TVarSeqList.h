/*
    TIPOS
*/

typedef struct aluno aln; // tipo de dado da struct aluno
typedef struct lista list; // tipo de dado da struct lista

struct aluno
{
    int matricula;
    char nome[30];
    float n1;
    float n2;
    float n3;
};

/*
    FUNCOES
*/
// funcao que aloca o espaco para a lista | retorna ponteiro para a lista se alocado ou NULL se erro
list *create_list(int n_max);
// funcao que libera o espaco da lista | retorna 0 se sucesso ou -1 se erro
int free_list(list *p_list);
// funcao que insere elemento no fim da lista
int insert_end(list *p_list, aln al);
// funcao que insere elemento no inicio da lista
int insert_start(list *p_list, aln al);
// funcao que insere elemento na lista de acordo com a ordem de matricula | retorna 0 se sucesso, -1 se erro
int insert_by_order(list *p_list, aln al);
// funcao que pega dados atraves da posicao da lista(1o, 2o, 3o...) e guarda no ponteiro pra struct de aluno | retorna 0 se sucesso
int consult_by_pos(list *p_list, int pos, aln *al);
// funcao que pega dados atraves da matricula e guarda no ponteiro para struct aluno | retorna 0 se sucesso
int consult_by_mat(list *p_list, int mat, aln *al);
// funcao que remove elemento pela matricula
int rm_list(list *p_list, int mat);
// funcao que remove um elemento do fim da lista
int rm_end(list *p_list);
// funcao que remove um elemento do inicio da lista
int rm_start(list *p_list);
// funcao que remove um elemento de forma otimizada (joga o ultimo elemento para a posicao "deletada")
int rm_optmz(list *p_list, int mat);
// funcao que retorna o tamanho da lista
int list_size(list *p_list);
// funcao que retorna se a lista esta cheia | 1 se cheia
int is_full(list *p_list);
// funcao que retorna se a lista esta vazia | 1 se vazia
int is_empty(list *p_list);
// funcao compactadora
int compactar_lista(list *p_list);