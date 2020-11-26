#include <stdio.h>
#include <stdlib.h>

#include "fornecido.h"
#include "Utilizadas.h"

int main () {

    /*Registros do dado de Seguidores*/
    /***
     *  removido - 1 byte
     *  idPessoaQueSegue - 4 bytes
     *  idPessoaQueESeguida - 4 bytes
     *  grauAmizade - 3 bytes
     *  dataInicioQueSegue - 10 bytes
     *  dataFimQueSegue - 10 bytes
    ***/

    int caso;

    //todo caso vai usar pelo menos dois arquivos
    char nomeArquivo1[50]; 
    char nomeArquivo2[50];

    //FILE arquivo segue que também tem em todos os casos
    FILE* arquivoSegue;

    scanf("%d%*c", &caso);
    if(caso == 6) {
        FILE* arquivoCSV;

        scanf("%[^ ]%*c%s", nomeArquivo1, nomeArquivo2);

        if(!abreArquivo(&arquivoSegue, nomeArquivo2, "wb\0", 3) || !abreArquivo(&arquivoCSV, nomeArquivo1, "rt\0", 4))
            return 0;

    }

    return 0;
}