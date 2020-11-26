#include "Utilizadas.h"

void escreveCabArqSegue(FILE* arquivoSegue, int quantSeg, char status){
    int i;
    fseek(arquivoSegue, 0, SEEK_SET); //posicionando a escrita para escrever o cabecalho
        
    //como o fwrite pede um ponteiro foi necessario criar vetores de uma posicao
    char cabStatus1 = status;
    char cablixo[27];
    for(i = 0; i < 27; i++) //escre o vetor lixo inteiro
        cablixo[i] = '$';
    int quantSeguidores = quantSeg;

    //escrevendo o cabecalho
    fwrite(&cabStatus1, sizeof(char), 1, arquivoSegue);
    fwrite(&quantSeguidores, sizeof(int), 1, arquivoSegue);
    fwrite(cablixo, sizeof(char), 27, arquivoSegue);
}