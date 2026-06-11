#include <stdlib.h>
#include "../include/pilha.h"

// cria a pilha
Pilha* criarPilha(int capacidade) {
 
    // Aloca memória para o vetor que vai armazenar os dados da pilha
    Pilha* pilha = malloc(sizeof(Pilha));

    // Aloca memória para o vetor que vai armazenar os dados da pilha
    pilha->dados = malloc(capacidade * sizeof(int));
    
    // Inicializa o topo como -1
    // Isso indica que a pilha está vazia (nenhum elemento inserido ainda)
    pilha->topo = -1;

    // Define a capacidade máxima da pilha
    pilha->capacidade = capacidade;

    // Retorna a pilha criada e pronta para uso
    return pilha;
}

// empilha (push)
void empilhar(Pilha* pilha, int valor) {
    // verifica se está cheia
    if (pilha->topo >= pilha->capacidade - 1) {
        return;
    }
    // Se ainda houver espaço na pilha, avançamos o topo para a próxima posição livre
    pilha->topo++;

    // Armazenamos o valor no topo da pilha
    pilha->dados[pilha->topo] = valor;
}

// desempilha (pop)
int desempilhar(Pilha* pilha) {
    // verifica se está vazia
    if (pilha->topo < 0) {
        return -1;
    }

    //Salvamos o valor que está atualmente no topo da pilha
    int valorRemovido = pilha->dados[pilha->topo];

    // “Removemos” logicamente o elemento diminuindo o topo
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