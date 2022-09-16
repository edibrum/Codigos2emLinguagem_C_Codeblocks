/* Suponha que criamos uma estrutura para armazenar produtos de um supermercado. Implemente duas funções:
a) uma que devolve o vetor ordenado por preços: void ordenaPreco(struct Produto vet[], int n)
b) outra que devolve o vetor ordenado pela quantidade de itens no estoque: void ordenaQuant(struct Produto vet[], int n) */

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>

// CRIA A ESTRUTURA PARA ARMAZENAR OS PRODUTOS:
    struct Produto{
        char nome[80];
        double preco;
        int quantidade;
    };

// ÍNDICE DAS FUNÇÕES:
void cadastraProdutos (struct Produto vet[],int TAM);
void ordenaPreco(struct Produto vet[], int esq, int dir);
void ordenaQuant(struct Produto vet[], int esq, int dir);
void imprimeVetor (struct Produto vet[],int TAM);


// MAIN:
int main()
{

    setlocale(LC_ALL,"Portuguese");

// OBS.: COLOQUEI ESSA PARTE SÓ PARA APROVEITAR E TREINAR A ALTERAÇAO DE CORES NO LAYOUT!!!
    // *********************** Definindo o LAYOUT colorido *************************************
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    /* Salvando os atributos do console */
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    // OBS.: usar as cores: 3, 4, 6, ou 10:
    // 3 - fundo preto com letras azuis
    // 4 - fundo preto com letras vermelhas
    // 6 - fundo preto com letras amarelas
    // 10 - fundo preto com letras verdes

    SetConsoleTextAttribute(hConsole, 6); // Muda p/ fundo preto com letras amarelas

    int TAM = 5; // TAM será a quantidade de produtos a cadastrar
    int opcao;
    struct Produto vet[TAM];

    printf("Tamanho do Vetor: %d",TAM);

    SetConsoleTextAttribute(hConsole, 10); // Muda p/ fundo preto com letras verdes
    cadastraProdutos (vet, TAM);

    SetConsoleTextAttribute(hConsole, 3); // Muda p/ fundo preto com letras azuis
    printf("\n \n LISTA DE PRODUTOS CADASTRADOS... ");
    imprimeVetor (vet, TAM);

    SetConsoleTextAttribute(hConsole, 4); // Muda p/ fundo preto com letras vermelhas
    printf("\n COMO VOCÊ DESEJA REORDENAR OS PRODUTOS CADASTRADOS? \n 1 - POR PREÇO \n 2 - POR QUANTIDADE \n");
    scanf("%d",&opcao);

        if(opcao==1){
                SetConsoleTextAttribute(hConsole, 6); // Muda p/ fundo preto com letras amarelas
                printf("\n \n REORDENANDO POR PRECO... ");
                ordenaPreco(vet, 0, TAM-1);
        }

        else if(opcao==2){
                SetConsoleTextAttribute(hConsole, 6); // Muda p/ fundo preto com letras amarelas
                printf("\n \n REORDENANDO POR QUANTIDADE... ");
                ordenaQuant(vet, 0, TAM-1);
        }

    SetConsoleTextAttribute(hConsole, 6); // Muda p/ fundo preto com letras amarelas
    imprimeVetor (vet, TAM);

    SetConsoleTextAttribute(hConsole, 10); // Muda p/ fundo preto com letras verdes
    return 0;
}



// FUNÇÃO QUE ALOCA OS VALORES NO VETOR:
void cadastraProdutos (struct Produto vet[],int TAM){
    for(int i=0; i < TAM; i++){
        printf("\n Digite o nome do produto %d: ",i+1);
        fflush(stdin);
        gets(vet[i].nome);
        printf("\n Digite o preço (use ,) desse produto: ");
        scanf("%lf",&vet[i].preco);
        printf("\n Digite a quantidade desse produto: ");
        scanf("%d",&vet[i].quantidade);
    }
}


// FUNÇÃO QUE IMPRIME O VETOR:
void imprimeVetor (struct Produto vet[],int TAM){
    for(int i=0; i < TAM; i++){
        printf("\n PRODUTO: %d ",i);
        printf("   NOME: %s ",vet[i].nome);
        printf("   PRECO: %.2lf ",vet[i].preco);
        printf("   QUANTIDADE: %d ",vet[i].quantidade);
    }
}



// FUNÇÃO ordenaPreco USANDO O "QUICK-SORT":
void ordenaPreco(struct Produto vet[], int esq, int dir){

    int pivo = esq, i, j;
    struct Produto ch;

        for(i=esq+1;i<=dir;i++){
            j = i;

                if(vet[j].preco < vet[pivo].preco){
                    ch = vet[j];

                    while(j > pivo){
                        vet[j] = vet[j-1];
                        j--;
                    }

                vet[j] = ch;
                pivo++;
                }
        }

    if(pivo-1 >= esq){
        ordenaPreco(vet,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        ordenaPreco(vet,pivo+1,dir);
    }
 }


// FUNÇÃO ordenaQuant USANDO O "QUICK-SORT":
 void ordenaQuant(struct Produto vet[], int esq, int dir){

    int pivo = esq, i, j;
    struct Produto ch;

        for(i=esq+1;i<=dir;i++){
            j = i;

                if(vet[j].quantidade < vet[pivo].quantidade){
                    ch = vet[j];

                    while(j > pivo){
                        vet[j] = vet[j-1];
                        j--;
                    }

                vet[j] = ch;
                pivo++;
                }
        }

    if(pivo-1 >= esq){
        ordenaQuant(vet,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        ordenaQuant(vet,pivo+1,dir);
    }
 }
