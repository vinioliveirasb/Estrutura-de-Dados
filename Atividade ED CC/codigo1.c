#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

int gerarNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void exibirNumerosComuns(int listaA[], int tamanhoA, int listaB[], int tamanhoB) {
    printf("Números comuns entre as duas listas: \n");

    for (int i = 0; i < tamanhoA; i++) {
        for (int j = 0; j < tamanhoB; j++) {
            if (listaA[i] == listaB[j]) {
                printf("%d ", listaA[i]);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int tamanhoA, tamanhoB;

    srand(time(NULL));

    printf("Digite numeros apenas maiores ou iguais a 20\n");
    printf("Digite o tamanho da lista A: ");
    scanf("%d", &tamanhoA);
    printf("Digite o tamanho da lista B: ");
    scanf("%d", &tamanhoB);


    int listaA[tamanhoA], listaB[tamanhoB];

    for (int i = 0; i < tamanhoA; i++) {
        listaA[i] = gerarNumeroAleatorio(1, MAX_NUM);
    }
    for (int i = 0; i < tamanhoB; i++) {
        listaB[i] = gerarNumeroAleatorio(1, MAX_NUM);
    }


    printf("\nLista A: ");
    for (int i = 0; i < tamanhoA; i++) {
        printf("%d ", listaA[i]);
    }

    printf("\nLista B: ");
    for (int i = 0; i < tamanhoB; i++) {
        printf("%d ", listaB[i]);
    }

    printf("\n");


    exibirNumerosComuns(listaA, tamanhoA, listaB, tamanhoB);

    return 0;
}


