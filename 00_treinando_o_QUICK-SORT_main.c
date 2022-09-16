// C�DIGO PARA ENTENDER UMA REORDENA��O USANDO UM "QUICK-SORT":
#include <stdio.h>
#include <stdlib.h>

// OBS.: � feito em forma de uma fun��o porque utiliza recurs�o - a pr�pria fun��o "se chama" l� nas �ltimas linhas...
void funcao_quick_sort (int vet[],int esq,int dir);

int main()
{

// CRIA O VETOR INICIAL:
    int vet[9] = {1,2,3,7,4,5,6,9,0};


// IMPRIME O VETOR INICIAL:
    printf("\n [");
    for(int i=0; i < 9; i++){
        printf("   %d  ",vet[i]);
        }
    printf("] \n");


// CHAMA E EXECUTA A FUNCAO COM O CODIGO DE "QUICK-SORT":
    funcao_quick_sort (vet,0,8);
            // aqui passamos como parametros: vet que � o vetor a ser reordenado, 0 que � o indice da posi��o inicial do vetor, e 8 que � o �ndice da �ltima posi��o do vetor


// IMPRIME O VETOR REORDENADO:
    printf("\n [");
    for(int i=0; i < 9; i++){
        printf("   %d  ",vet[i]);
    }
    printf("] \n");
}


// FUNCAO COM O CODIGO DE "QUICK-SORT":
void funcao_quick_sort (int vet[],int esq,int dir){

    int pivo = esq;
    int i, j;
    int ch;

        for(i=esq+1;i<=dir;i++){
            j = i;

                if(vet[j] < vet[pivo]){
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
        funcao_quick_sort(vet,esq,pivo-1);
    }
    if(pivo+1 <= dir){
        funcao_quick_sort(vet,pivo+1,dir);
    }



}
