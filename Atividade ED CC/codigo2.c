#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUM 100

int excluirPares(int listaA[], int tamanhoA) {
    int i, j = 0;

    for (i = 0; i < tamanhoA; i++) {
        if (listaA[i] % 2 != 0) {
            listaA[j] = listaA[i];
            j++;
        }
    }

    return j;
}

void exibirLista(int lista[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", lista[i]);
    }
    printf("\n");
}

int main() {
    int tamanhoA;

    srand(time(NULL));

    printf("Digite o tamanho da lista A (maior ou igual a 20): ");
    scanf("%d", &tamanhoA);

    if (tamanhoA < 20) {
        printf("A lista deve ter tamanho maior ou igual a 20.\n");
        return 1;
    }

    int listaA[tamanhoA];

    for (int i = 0; i < tamanhoA; i++) {
        listaA[i] = rand() % MAX_NUM + 1;
    }

    printf("\nLista A original: ");
    exibirLista(listaA, tamanhoA);

    int novoTamanho = excluirPares(listaA, tamanhoA);

    printf("Lista A apos excluir os numeros pares: ");
    exibirLista(listaA, novoTamanho);

    return 0;
}
