#ifndef UTILIZADAS_H
#define UTILIZADAS_H

    #include <stdio.h>
    #include <stdlib.h>

    //Funcoes do Trabalho 1
    int imprimeRegistroNaTela(FILE* arquivo); //recebe um arquivo e imprime no modo desejado pelos casos 2 e 3
    void escreveCabcArqPessoa(FILE* arquivo, int quantReg, char status);
    void escreveCabcArqIndexa(FILE* arquivo, char status);
    void inserirArqPessoas(int idPessoa, char nomePessoa[60], int idadePessoa, char twitterPessoa[40], FILE* arquivoPessoa);
    int verificaConsistencia(FILE* arquivo);
    int retornaRRN(FILE* arquivo);

    //funcoes novas para o Trabalho 2
    void escreveCabArqSegue(FILE* arquivoSegue, int quantSeg, char status);
    //nome = nome do arquivo, modo = modo de abertura, tipo = qual dos arquivos (1 - Pessoa, 2 - Indexa, 3 - Segue, 4 - CSV)
    int abreArquivo(FILE** arq, char* nome, char* modo, int tipo); 
    void insereCSVparaSegue(FILE* arqCSV, FILE* arqSegue, int* quantPessoas);
    void inserirArqSegue(int idPessoaQueSegue, int idPessoaQueESeguida, char graAmizade[3], char dataInicio[10], char dataFim[10],  FILE* arquivoSegue);

#endif