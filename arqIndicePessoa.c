#include "arqIndicePessoa.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista* cria_lista() {
    Lista* li = (Lista*) malloc(sizeof(Lista));

    if (li != NULL)
        *li = NULL;

    return li;
}



void libera_lista(Lista* li) {
    if (li != NULL) {
        Elem* no;

        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;

            free(no);
        }

        free(li);
    }
}


/*
int consulta_lista_pos(Lista* li, int pos, int *id, int *rrn ) {
    if (li == NULL || pos <= 0)
        return ERRO;

    Elem *no = *li;

    int i = 1;

    while (no != NULL && i < pos){
        no = no->prox;
        i++;
    }

    if (no == NULL)
        return ERRO;
    else {
        *id = no->idPessoa;
        *rrn = no->RRN;
        return OK;
    }
}
*/

/*
int consulta_lista_id(Lista* li, int id, Elem **el) {
    if (li == NULL)
        return 0;

    Elem *no = *li;

    while (no != NULL && no->idPessoa != id){
        no = no->prox;
    }

    if (no == NULL)
        return ERRO;
    else {
        *el = no;
        return OK;
    }
}
*/


int insere_lista_final(Lista* li,char removido,int idPessoaQueSegue, int idPessoaQueESeguida,char* grauAmizade,char* dataInicioQueSegue, char* dataFimQueSegue) {
    Elem *no;

    if (li == NULL) return ERRO;

    no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)  return ERRO;

    no->removido = removido;
    no->idPessoaQueSegue = idPessoaQueSegue;
    no->idPessoaQueESeguida = idPessoaQueESeguida;
    strcpy(no->grauAmizade , grauAmizade);
    strcpy(no->dataInicioQueSegue , dataInicioQueSegue);
    strcpy(no->dataFimQueSegue , dataFimQueSegue);
    no->prox = NULL;


	if ((*li) == NULL) {   //lista vazia: insere inicio
        no->ant = NULL;
        *li = no;
    } else {
        Elem *aux;
        aux = *li;

        while (aux->prox != NULL){
            aux = aux->prox;
        }

        aux->prox = no;
        no->ant = aux;
    }

    return OK;
}


int insere_lista_ordenada(Lista* li,char removido,int idPessoaQueSegue, int idPessoaQueESeguida,char* grauAmizade,char* dataInicioQueSegue, char* dataFimQueSegue) {

    if (li == NULL)
        return ERRO;

    Elem *no = (Elem*) malloc(sizeof(Elem));

    if (no == NULL)
        return ERRO;

    no->removido = removido;
    no->idPessoaQueSegue = idPessoaQueSegue;
    no->idPessoaQueESeguida = idPessoaQueESeguida;
    strcpy(no->grauAmizade , grauAmizade);
    strcpy(no->dataInicioQueSegue , dataInicioQueSegue);
    strcpy(no->dataFimQueSegue , dataFimQueSegue);

    if ((*li) == NULL) {  //lista vazia: insere in�cio
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return OK;
    }

    else{
        Elem *ante, *atual = *li;

        while ((atual != NULL) &&   ((idPessoaQueSegue > atual->idPessoaQueSegue)
                                    || ((idPessoaQueSegue == atual->idPessoaQueSegue) && (idPessoaQueESeguida > atual->idPessoaQueESeguida)) || ((idPessoaQueSegue == atual->idPessoaQueSegue) && (idPessoaQueESeguida == atual->idPessoaQueESeguida) && (strcmp(dataInicioQueSegue,atual->dataInicioQueSegue)) > 0)
                                    || ((idPessoaQueSegue == atual->idPessoaQueSegue) && (idPessoaQueESeguida == atual->idPessoaQueESeguida) && (strcmp(dataInicioQueSegue,atual->dataInicioQueSegue)) > 0)
                                    || ((idPessoaQueSegue == atual->idPessoaQueSegue) && (idPessoaQueESeguida == atual->idPessoaQueESeguida) && (strcmp(dataInicioQueSegue,atual->dataInicioQueSegue) == 0) && (strcmp(dataFimQueSegue,atual->dataFimQueSegue) >= 0))  )) {
            ante = atual;
            atual = atual->prox;
        }

        if (atual == *li) {   //insere in�cio
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        } else {
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;

            if (atual != NULL)
                atual->ant = no;
        }
        return OK;
    }
}

/*
int remove_lista(Lista* li, int dt) {   //TERMINAR
    if (li == NULL)
        return ERRO;

    if ((*li) == NULL)//lista vazia
        return ERRO;

    Elem *no = *li;

    while (no != NULL && no->idPessoa != dt){
        no = no->prox;
    }

    if (no == NULL)//n�o encontrado
        return ERRO;

    if (no->ant == NULL)//remover o primeiro?
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if (no->prox != NULL)//n�o � o �ltimo?
        no->prox->ant = no->ant;

    free(no);

    return OK;

}

int tamanho_lista(Lista* li) {
    if (li == NULL)
        return 0;

    int cont = 0;

    Elem* no = *li;

    while (no != NULL){
        cont++;
        no = no->prox;
    }

    return cont;
}
*/

void add_bin(Lista* li,FILE* arquivo, int numeroDeNos){
    Elem* no = *li;
    if(no == NULL)
        return ;


    for(int i = 0; i<numeroDeNos; i++){
        inserirArqSegue(no->idPessoaQueSegue,no->idPessoaQueESeguida,no->grauAmizade,no->dataInicioQueSegue,no->dataFimQueSegue,arquivo);
        no = no->prox;

    }
}

void imprime_lista(Lista* li) {
    Elem* no = *li;
    int count =1;
    if (li == NULL)
        return;

    while (no != NULL) {
        printf("%d\n",count);
        printf("removido: %c\n",no->removido);
        printf("idPessoaQueSegue: %5d \n",no->idPessoaQueSegue);
        printf("idPessoaQueESeguida: %5d \n",no->idPessoaQueESeguida);
        printf("grauAmizade: %s\n",no->grauAmizade);
        printf("dataInicioQueSegue: %s\n",no->dataInicioQueSegue);
        printf("dataFimQueSegue: %s\n",no->dataFimQueSegue);
        printf("\n");
        no = no->prox;
        count++;
    }
    printf("-------------- FIM LISTA -----------------\n");
}
