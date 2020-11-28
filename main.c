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
        /*
            else if (caso == 3) {
        //variaveis dos arquivos e o campo a ser utilizado
        char nomeArqPessoa[50];
        char nomeArqIndex[50];
        char campo[15]; //idPessoa,nomePessoa,idadePessoa ou twitterPessoa

        //leitura das variaveis 
        scanf("%[^ ]%*c", nomeArqPessoa);
        scanf("%[^ ]%*c", nomeArqIndex);
        scanf("%[^ ]%*c", campo);

        //vai abrir os dois arquivos necessarios e verificar se eles estao de acordo com o necessario
        FILE* arquivoPessoa = fopen(nomeArqPessoa, "rb");
        FILE* arquivoIndexaPessoa = fopen(nomeArqIndex, "rb");

        //verifica se existe um arquivo e se ele abre corretamente
        if(arquivoPessoa == NULL || arquivoIndexaPessoa == NULL){
            printf("Falha no processamento do arquivo.\n");
            return 0;
        }

        if(!verificaConsistencia(arquivoIndexaPessoa) || !verificaConsistencia(arquivoPessoa))
            return 0;

        //de novo, queria usar o switch case, mas parece que o compilador nao compila direito entao fiz com if else
        if(strcmp(campo, "idPessoa") == 0) {//verifica se o campo escolhido e' o do idPessoa
            int RRN = retornaRRN(arquivoIndexaPessoa);

            if(RRN != -1){
                fseek(arquivoPessoa, ((RRN+1)*64), SEEK_SET);
                imprimeRegistroNaTela(arquivoPessoa); //imprime o dado na tela
            } 
            else
                printf("Registro inexistente.\n");
            
            fclose(arquivoIndexaPessoa);
            fclose(arquivoPessoa);

        } else if (strcmp(campo, "idadePessoa") == 0) {
            int valor; //verifica a idade requerida para encontrar o campo 
            scanf("%d", &valor);

            fclose(arquivoIndexaPessoa); //nao sera necessario para esse modo

            int quantRegistros;
            
            fread(&quantRegistros, 4, 1, arquivoPessoa); //Le a quantidade de Registros do arquvo para o loop
            
            fseek(arquivoPessoa, 64, SEEK_SET); //posiciona o ponteiro para dps do cabecalho para comecar o loop
            
            int idade;
            char status;
            int QuantImprimida = 0;

            for(i = 0; i < quantRegistros; i++){
                fread(&status, sizeof(char), 1, arquivoPessoa);
                if(status == '1'){
                    fseek(arquivoPessoa, 44, SEEK_CUR); //posiciona o ponteiro para ler a idade
                    fread(&idade, sizeof(int), 1, arquivoPessoa);
                    
                    if(idade == valor){ //compara a idade
                        fseek(arquivoPessoa, -49, SEEK_CUR); //se a idade for igual ele volta para o comeco do registro para imprimir na tela
                        imprimeRegistroNaTela(arquivoPessoa);
                        QuantImprimida++;
                    }
                    else
                        fseek(arquivoPessoa, 15, SEEK_CUR); //pula para o proximo registro

                }
                else {
                    fseek(arquivoPessoa, 63, SEEK_CUR); //pula para proximo registro
                    quantRegistros++;                   //aumenta na quantidade o resgistro que nao foi contabilizado
                }
            }
            if(QuantImprimida == 0) //NAO possui nenhum arquivo
                printf("Registro inexistente.\n");

            fclose(arquivoPessoa);
        } else if (strcmp(campo, "nomePessoa") == 0) {
            char valor[60];

            scan_quote_string(valor);

            char nomePessoa[40];
            char status;
            int QuantImprimida = 0;

            fseek(arquivoPessoa, 64, SEEK_SET); //posiciona para o primeiro nome presente no arquivo

            while(fread(&status, 1, 1, arquivoPessoa) == 1){
                if(status == '0'){
                    fseek(arquivoPessoa, 63, SEEK_CUR); // pula para o proximo registro
                    continue;
                }
                    
                fseek(arquivoPessoa, 4, SEEK_CUR);

                fread(nomePessoa, 1, 40, arquivoPessoa);

                if(strcmp(nomePessoa, valor) == 0){ //compara a idade
                        fseek(arquivoPessoa, -45, SEEK_CUR); //se o nome for igual ele volta para o comeco do registro para imprimir na tela
                        imprimeRegistroNaTela(arquivoPessoa);
                        QuantImprimida++;
                    }
                else
                    fseek(arquivoPessoa, 19, SEEK_CUR); //pula para o proximo registro

            }
            if(QuantImprimida == 0) //NAO possui nenhum arquivo
                printf("Registro inexistente.\n");

            fclose(arquivoPessoa);

        } else if (strcmp(campo, "twitterPessoa") == 0){
            char valor[40];

            scan_quote_string(valor);

            char twitterPessoa[15];
            char status;
            int QuantImprimida = 0;

            fseek(arquivoPessoa, 64, SEEK_SET); //posiciona para o primeiro nome presente no arquivo

            while(fread(&status, 1, 1, arquivoPessoa) == 1){
                if(status == '0'){
                    fseek(arquivoPessoa, 63, SEEK_CUR); // pula para o proximo registro
                    continue;
                }
                    
                fseek(arquivoPessoa, 48, SEEK_CUR);

                fread(twitterPessoa, 1, 15, arquivoPessoa);

                if(strcmp(twitterPessoa, valor) == 0){ //compara a idade
                        fseek(arquivoPessoa, -64, SEEK_CUR); //se o nome for igual ele volta para o comeco do registro para imprimir na tela
                        imprimeRegistroNaTela(arquivoPessoa);
                        QuantImprimida++;
                    }
                else
                    continue; //pula para o proximo registro

            }
            if(QuantImprimida == 0) //NAO possui nenhum arquivo
                printf("Registro inexistente.\n");

            fclose(arquivoPessoa);
        }
        */

    }
    return 0;
}
