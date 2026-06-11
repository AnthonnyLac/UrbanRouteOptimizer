#ifndef PILHA_H
#define PILHA_H

// definição da struct
typedef struct {
    int* dados;
    int topo;
    int capacidade;
} Pilha;

// funções da pilha
Pilha* criarPilha(int capacidade);
void empilhar(Pilha* pilha, int valor);
int desempilhar(Pilha* pilha);
int pilhaVazia(Pilha* pilha);
void destruirPilha(Pilha* pilha);

#endif