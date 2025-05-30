#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

int excluirPares(int *listaA, int tamanhoA) {
    int i, j = 0;

    for (i = 0; i < tamanhoA; i++) {
        if (listaA[i] % 2 != 0) {
            listaA[j] = listaA[i];
            j++;
        }
    }

    return j;
}

int unirListas(int *listaA, int tamanhoA, int *listaB, int tamanhoB, int **listaUnida) {
    int i;

    *listaUnida = (int *)malloc((tamanhoA + tamanhoB) * sizeof(int));

    if (*listaUnida == NULL) {
        printf("Erro na alocação de memória.\n");
        return 0;
    }

    for (i = 0; i < tamanhoA; i++) {
        (*listaUnida)[i] = listaA[i];
    }

    for (i = 0; i < tamanhoB; i++) {
        (*listaUnida)[tamanhoA + i] = listaB[i];
    }

    return tamanhoA + tamanhoB;
}

void exibirLista(int *lista, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int tamanhoA, tamanhoB;

    srand(time(NULL));

    printf("Digite o tamanho da lista A (maior ou igual a 20): ");
    scanf("%d", &tamanhoA);

    if (tamanhoA < 20) {
        printf("A lista deve ter tamanho maior ou igual a 20.\n");
        return 1;
    }

    printf("Digite o tamanho da lista B (maior ou igual a 20): ");
    scanf("%d", &tamanhoB);

    if (tamanhoB < 20) {
        printf("A lista deve ter tamanho maior ou igual a 20.\n");
        return 1;
    }

    int *listaA = (int *)malloc(tamanhoA * sizeof(int));
    int *listaB = (int *)malloc(tamanhoB * sizeof(int));

    if (listaA == NULL || listaB == NULL) {
        printf("Erro na alocação de memória.\n");
        return 1;
    }

    for (int i = 0; i < tamanhoA; i++) {
        listaA[i] = rand() % MAX_NUM + 1;
    }

    for (int i = 0; i < tamanhoB; i++) {
        listaB[i] = rand() % MAX_NUM + 1;
    }

    printf("\nLista A: ");
    exibirLista(listaA, tamanhoA);
    printf("Lista B: ");
    exibirLista(listaB, tamanhoB);

    int *listaUnida = NULL;

    int novoTamanho = unirListas(listaA, tamanhoA, listaB, tamanhoB, &listaUnida);

    printf("\nLista Unida: ");
    exibirLista(listaUnida, novoTamanho);

    free(listaA);
    free(listaB);
    free(listaUnida);

    return 0;
}

