#include <stdio.h>
#include <stdlib.h>

#include "arqIndicePessoa.h"
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
        int quantPessoas = 0;

        scanf("%[^ ]%*c%s", nomeArquivo1, nomeArquivo2);

        if(!abreArquivo(&arquivoSegue, nomeArquivo2, "wb\0", 3) || !abreArquivo(&arquivoCSV, nomeArquivo1, "r\0", 4))
            return 0;

        escreveCabArqSegue(arquivoSegue, 0, '0');

        insereCSVparaSegue( arquivoCSV, arquivoSegue, &quantPessoas);

        escreveCabArqSegue(arquivoSegue, quantPessoas, '1');

        fclose(arquivoCSV);
        fclose(arquivoSegue);

        binarioNaTela2(nomeArquivo2);
    }
    else if(caso == 7) {
        FILE* arquivoSegueOrdenado;
        Lista* li = cria_lista();

        int quantPessoas = 0;
        char estavel;
        int numeroDeRegistros;

        scanf("%[^ ]%*c%s", nomeArquivo1, nomeArquivo2);

        if(!abreArquivo(&arquivoSegue, nomeArquivo1, "rb+\0", 3) || !abreArquivo(&arquivoSegueOrdenado, nomeArquivo2, "wb\0", 3))
            return 0;



        fseek(arquivoSegue, 0, SEEK_SET);
        fread(&estavel, sizeof(char), 1, arquivoSegue);
        fread(&numeroDeRegistros, sizeof(int), 1, arquivoSegue);
        fseek(arquivoSegue, 32, SEEK_SET);

        char removido;
        int idPessoaQueSegue;
        int idPessoaQueESeguida;
        char grauAmizade[4];
        char dataInicioQueSegue[11];
        char dataFimQueSegue[11];

        for(int i = 0; i<numeroDeRegistros;i++){

            fread(&removido, sizeof(char), 1, arquivoSegue);
            fread(&idPessoaQueSegue, sizeof(int), 1, arquivoSegue);
            fread(&idPessoaQueESeguida, sizeof(int), 1, arquivoSegue);
            fread(grauAmizade, sizeof(char), 3, arquivoSegue);
            grauAmizade[3] = '\0';
            fread(dataInicioQueSegue, sizeof(char), 10, arquivoSegue);
            dataInicioQueSegue[10] = '\0';
            fread(dataFimQueSegue, sizeof(char), 10, arquivoSegue);
            dataFimQueSegue[10] = '\0';

            insere_lista_ordenada(li,removido,idPessoaQueSegue,idPessoaQueESeguida,grauAmizade,dataInicioQueSegue,dataFimQueSegue);

        }

        escreveCabArqSegue(arquivoSegueOrdenado, 0, '0');

        fseek(arquivoSegueOrdenado, 32, SEEK_SET);
        add_bin(li ,arquivoSegueOrdenado, numeroDeRegistros);

        escreveCabArqSegue(arquivoSegueOrdenado, numeroDeRegistros, '1');

        fclose(arquivoSegueOrdenado);
        fclose(arquivoSegue);

        binarioNaTela2(nomeArquivo2);
    }
    else if (caso == 8) {
        

    }

    return 0;
}
