#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct nodo {
    int conteudo;
    struct nodo *prox;
} Celula;

                                                //O resultado "estranho" que dá é por conta dos ponteiros puxando valor de um lugar que virou inexistente, não consegui arrumar.
Celula *inserir(int valor, Celula *lista) {
    Celula *novo, *p;

    novo = (Celula *)malloc(sizeof(Celula));
    novo->conteudo = valor;
    novo->prox = novo;

    if (!lista) {
        return novo;
    }

    p = lista;
    while (p->prox != lista) {
        p = p->prox;
    }

    p->prox = novo;
    novo->prox = lista;

    return lista;
}

void exibir(Celula *lista) {
    if (!lista) {
        printf("Lista vazia.\n");
        return;
    }

    Celula *p = lista;
    do {
        printf("%d\t", p->conteudo);
        p = p->prox;
    } while (p != lista);
    printf("\n");
}

Celula *unirListas(Celula *lista1, Celula *lista2) {
    if (!lista1) return lista2;
    if (!lista2) return lista1;

    Celula *ultimo1 = lista1;
    while (ultimo1->prox != lista1) {
        ultimo1 = ultimo1->prox;
    }

    Celula *ultimo2 = lista2;
    while (ultimo2->prox != lista2) {
        ultimo2 = ultimo2->prox;
    }

    ultimo1->prox = lista2;

    ultimo2->prox = lista1;

    return lista1;
}

Celula *popular(Celula *lista, int quantidade, int seed) {
    srand(seed);
    int numero;

    for (int i = 0; i < quantidade; i++) {
        numero = rand() % 100;
        lista = inserir(numero, lista);
    }

    return lista;
}

void excluirTodos(Celula *lista) {
    if (!lista) {
        return;
    }

    Celula *p = lista;
    Celula *temp;

    do {
        temp = p;
        p = p->prox;
        free(temp);
    } while (p != lista);

    lista = NULL;
}

int main() {
    Celula *lista1 = NULL;
    Celula *lista2 = NULL;

    lista1 = popular(lista1, 5, time(NULL));
    lista2 = popular(lista2, 5, time(NULL) + 1);

    printf("Lista 1 antes da união:\n");
    exibir(lista1);

    printf("Lista 2 antes da união:\n");
    exibir(lista2);

    lista1 = unirListas(lista1, lista2);

    printf("\nLista unida (antes da exclusão):\n");
    exibir(lista1);

    excluirTodos(lista1);

    printf("\nLista após excluir todos os elementos:\n");
    exibir(lista1);

    return 0;
}
