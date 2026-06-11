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

void enfileirar(Fila* f, int valor) {
    if (f->fim < f->tamanho) {
        f->dados[f->fim++] = valor;
    }
}

int desenfileirar(Fila* f) {
    if (f->inicio == f->fim) return -1;
    return f->dados[f->inicio++];
}

int filaVazia(Fila* f) {
    return f->inicio == f->fim;
}

void destruirFila(Fila* f) {
    free(f->dados);
    free(f);
}