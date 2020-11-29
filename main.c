#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
        //Cria ponteiro do arquivo ordenado e a lista ordenada
        FILE* arquivoSegueOrdenado;
        Lista* li = cria_lista();

        //cria variáveis para analisar os cabeçalhos
        char estavel;
        int numeroDeRegistros;

        // Pega o nome dos arquivos
        scanf("%[^ ]%*c%s", nomeArquivo1, nomeArquivo2);

        //Verifica abertura e o cabecalho
        if(!abreArquivo(&arquivoSegue, nomeArquivo1, "rb+\0", 3) || !abreArquivo(&arquivoSegueOrdenado, nomeArquivo2, "wb\0", 3))
            return 0;


        //le o cabecalho
        fseek(arquivoSegue, 0, SEEK_SET);
        fread(&estavel, sizeof(char), 1, arquivoSegue);
        fread(&numeroDeRegistros, sizeof(int), 1, arquivoSegue);
        fseek(arquivoSegue, 32, SEEK_SET);

        //cria variaveis para armazenar os valores do arquivo
        char removido;
        int idPessoaQueSegue;
        int idPessoaQueESeguida;
        char grauAmizade[4];
        char dataInicioQueSegue[11];
        char dataFimQueSegue[11];

        //repetição para pegar todos os registros do arquivos
        for(int i = 0; i<numeroDeRegistros;i++){

            //Leitura dos registros
            fread(&removido, sizeof(char), 1, arquivoSegue);
            fread(&idPessoaQueSegue, sizeof(int), 1, arquivoSegue);
            fread(&idPessoaQueESeguida, sizeof(int), 1, arquivoSegue);
            fread(grauAmizade, sizeof(char), 3, arquivoSegue);
            grauAmizade[3] = '\0';
            fread(dataInicioQueSegue, sizeof(char), 10, arquivoSegue);
            dataInicioQueSegue[10] = '\0';
            fread(dataFimQueSegue, sizeof(char), 10, arquivoSegue);
            dataFimQueSegue[10] = '\0';

            //inserindo de forma organizada no arquivo
            insere_lista_ordenada(li,removido,idPessoaQueSegue,idPessoaQueESeguida,grauAmizade,dataInicioQueSegue,dataFimQueSegue);

        }

        //Como vamos conmeçar a escrever no arquivo ordenado, marcamos o cabecalho como instavel 0
        escreveCabArqSegue(arquivoSegueOrdenado, 0, '0');

        //Posicionando o cursor depois do cabecalho
        fseek(arquivoSegueOrdenado, 32, SEEK_SET);

        //adicionando os valores que estão na lisata, direto no arquivo binsorted
        add_bin(li ,arquivoSegueOrdenado, numeroDeRegistros);

        //marcando o cabecalho com estavel, ja que acabamos de escrever os registros
        escreveCabArqSegue(arquivoSegueOrdenado, numeroDeRegistros, '1');

        //fechandio os arquivos abertos
        fclose(arquivoSegueOrdenado);
        fclose(arquivoSegue);

        //imprime o binario na tela
        binarioNaTela2(nomeArquivo2);
    }
    else if (caso == 8) {


        //variaveis dos arquivos e o campo a ser utilizado
        char nomeArqPessoa[50];
        char nomeArqIndex[50];
        char campo[15]; //idPessoa,nomePessoa,idadePessoa ou twitterPessoa
        int idPessoa;


        //leitura das variaveis
        scanf("%[^ ]%*c", nomeArqPessoa);
        scanf("%[^ ]%*c", nomeArqIndex);
        scanf("%[^ ]%*c", campo);
        scanf("%d", &idPessoa);
        scanf("%s", nomeArquivo1);



        //vai abrir os dois arquivos necessarios e verificar se eles estao de acordo com o necessario
        FILE* arquivoPessoa = fopen(nomeArqPessoa, "rb");
        FILE* arquivoIndexaPessoa = fopen(nomeArqIndex, "rb");
        arquivoSegue = fopen(nomeArquivo1, "rb");

        //verifica se existe um arquivo e se ele abre corretamente
        if(arquivoPessoa == NULL || arquivoIndexaPessoa == NULL|| arquivoSegue == NULL){
            printf("Falha no processamento do arquivo.\n");
            return 0;
        }

        if(!verificaConsistenciaComAPalavraProcessamento(arquivoIndexaPessoa) || !verificaConsistenciaComAPalavraProcessamento(arquivoPessoa)|| !verificaConsistenciaComAPalavraProcessamento(arquivoSegue))
            return 0;

        //de novo, queria usar o switch case, mas parece que o compilador nao compila direito entao fiz com if else
        if(strcmp(campo, "idPessoa") == 0) {//verifica se o campo escolhido e' o do idPessoa
            int RRN = retornaRRNcomId(arquivoIndexaPessoa,idPessoa);

            if(RRN != -1){
                fseek(arquivoPessoa, ((RRN+1)*64), SEEK_SET);
                imprimeRegistroNaTela(arquivoPessoa); //imprime o dado na tela
            }
            else{
                //Se não encontrar nenhum registros, finaliza-se o programa
                printf("Registro inexistente.\n");
                fclose(arquivoIndexaPessoa);
                fclose(arquivoPessoa);
                return 0;
            }
            //fecha os arquivoscom os dados das pessoas
            fclose(arquivoIndexaPessoa);
            fclose(arquivoPessoa);

            //variavel para armazenar o numero de registros
            int numeroDeRegistros;

            //lendo o cabecalho
            fseek(arquivoSegue, sizeof(char), SEEK_SET);
            fread(&numeroDeRegistros, sizeof(int), 1, arquivoSegue);
            fseek(arquivoSegue, 32, SEEK_SET);

            //cria variaveis para armazenar os valores do arquivo
            char removido;
            int idPessoaQueSegue;
            int idPessoaQueESeguida;
            char grauAmizade[4];
            char dataInicioQueSegue[11];
            char dataFimQueSegue[11];

            //repetição para pegar todos os registros do arquivos
            for(int i = 0; i<numeroDeRegistros;i++){

                //Leitura dos registros
                fread(&removido, sizeof(char), 1, arquivoSegue);
                fread(&idPessoaQueSegue, sizeof(int), 1, arquivoSegue);
                fread(&idPessoaQueESeguida, sizeof(int), 1, arquivoSegue);
                fread(grauAmizade, sizeof(char), 3, arquivoSegue);
                grauAmizade[3] = '\0';
                fread(dataInicioQueSegue, sizeof(char), 10, arquivoSegue);
                dataInicioQueSegue[10] = '\0';
                fread(dataFimQueSegue, sizeof(char), 10, arquivoSegue);
                dataFimQueSegue[10] = '\0';

                // imprimindo apenas os que nao foram removidos e os que a pessoa com o ide requisitado segue
                if(removido =='1' && idPessoaQueSegue == idPessoa){
                    printf("Segue a pessoa de código: %d \n",idPessoaQueESeguida);
                    printf("Justificativa para seguir: %s\n",interpretadorDeGrau(grauAmizade));
                    printf("Começou a seguir em: %s\n",dataInicioQueSegue);
                    printf("Parou de seguir em: %s\n",dataFimQueSegue);
                    printf("\n");
                }

            }
        }
    }
    return 0;
}
