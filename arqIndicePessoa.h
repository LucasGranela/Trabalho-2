#ifndef ARQINDICEPESSOA_H
#define ARQINDICEPESSOA_H

#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

struct elemento{
    struct elemento *ant;
    char removido;
    int idPessoaQueSegue;
    int idPessoaQueESeguida;
    char grauAmizade[3];
    char dataInicioQueSegue[11];
    char dataFimQueSegue[11];
    struct elemento *prox;
};

typedef struct elemento Elem;
typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
//int consulta_lista_pos(Lista* li, int pos, int *id, int *rrn );
//int consulta_lista_id(Lista* li, int id, Elem **el);
int insere_lista_final(Lista* li,char removido,int idPessoaQueSegue, int idPessoaQueESeguida,char* grauAmizade,char* dataInicioQueSegue, char* dataFimQueSegue);
int insere_lista_ordenada(Lista* li,char removido,int idPessoaQueSegue, int idPessoaQueESeguida,char* grauAmizade,char* dataInicioQueSegue, char* dataFimQueSegue);
//int remove_lista(Lista* li, int dt);
//int tamanho_lista(Lista* li);
void imprime_lista(Lista* li);

#endif
