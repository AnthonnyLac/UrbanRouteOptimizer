#include <stdlib.h>
#include "../include/pilha.h"

// cria a pilha
Pilha* criarPilha(int capacidade) {
    Pilha* pilha = malloc(sizeof(Pilha));

    pilha->dados = malloc(capacidade * sizeof(int));
    pilha->topo = -1;
    pilha->capacidade = capacidade;

    return pilha;
}

// empilha (push)
void empilhar(Pilha* pilha, int valor) {
    // verifica se está cheia
    if (pilha->topo >= pilha->capacidade - 1) {
        return;
    }

    pilha->topo++;
    pilha->dados[pilha->topo] = valor;
}

// desempilha (pop)
int desempilhar(Pilha* pilha) {
    // verifica se está vazia
    if (pilha->topo < 0) {
        return -1;
    }

    int valorRemovido = pilha->dados[pilha->topo];
    pilha->topo--;

    return valorRemovido;
}

// verifica se está vazia
int pilhaVazia(Pilha* pilha) {
    return pilha->topo < 0;
}

// libera memória
void destruirPilha(Pilha* pilha) {
    if (pilha == NULL) return;

    free(pilha->dados);
    free(pilha);
}