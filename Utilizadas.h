#ifndef UTILIZADAS_H
#define UTILIZADAS_H

    #include <stdio.h>
    #include <stdlib.h>

    void escreveCabArqSegue(FILE* arquivoSegue, int quantSeg, char status);
    int imprimeRegistroNaTela(FILE* arquivo); //recebe um arquivo e imprime no modo desejado pelos casos 2 e 3
    void escreveCabcArqPessoa(FILE* arquivo, int quantReg, char status);
    void escreveCabcArqIndexa(FILE* arquivo, char status);
    void inserirArqPessoas(int idPessoa, char nomePessoa[60], int idadePessoa, char twitterPessoa[40], FILE* arquivoPessoa);
    int verificaConsistencia(FILE* arquivo);
    int retornaRRN(FILE* arquivo);
    int abreArquivo(FILE** arq, char* nome, char* modo, int tipo); //nome = nome do arquivo, modo = modo de abertura, tipo = qual dos arquivos (1 - Pessoa, 2 - Indexa, 3 - Segue, 4 - CSV)

#endif