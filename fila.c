// fila.c
#include <stdlib.h>
#include "fila.h"

Fila* criarFila(int tamanho) {
    Fila* f = malloc(sizeof(Fila));
    f->dados = malloc(tamanho * sizeof(int));
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = tamanho;
    return f;
}

void enfileirar(Fila* fila, int valor) {
    // verifica se a fila está cheia
    if (fila->fim >= fila->tamanho) {
        return;
    }

    // insere o valor na posição atual do fim
    fila->dados[fila->fim] = valor;

    // avança o fim da fila
    fila->fim++;
}

int desenfileirar(Fila* fila) {
    // verifica se a fila está vazia
    if (fila->inicio == fila->fim) {
        return -1;
    }

    // pega o valor no início da fila
    int valorRemovido = fila->dados[fila->inicio];

    // avança o início da fila
    fila->inicio++;

    // retorna o valor removido
    return valorRemovido;
}

int filaVazia(Fila* fila) {
    // a fila está vazia quando inicio == fim

    return fila->inicio == fila->fim;
}

void destruirFila(Fila* fila) {
    // libera o vetor interno
    free(fila->dados);

    // libera a struct da fila
    free(fila);
}