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
void enfileirar(Fila* f, int valor);
int desenfileirar(Fila* f);
int filaVazia(Fila* f);
void destruirFila(Fila* f);

#endif