// fila.h
#ifndef FILA_H
#define FILA_H

typedef struct {
    int* dados;
    int inicio;
    int fim;
    int tamanho;
} Fila;

// funções (tipo "service")
Fila* criarFila(int tamanho);
void enfileirar(Fila* fila, int valor);
int desenfileirar(Fila* fila);
int filaVazia(Fila* fila);
void destruirFila(Fila* fila);

#endif