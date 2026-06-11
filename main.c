
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

void limparTela() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}

void exibirGrafo(int grafo[6][6], char* bairros[6]) {
	printf("\nMatriz de Adjacência:\n");

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			printf("%d ", grafo[i][j]);
		}
		printf("\n");
	}

	printf("\nArestas do grafo:\n");

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (grafo[i][j] != 0) {
				printf("%s -> %s (distancia %d)\n", bairros[i], bairros[j], grafo[i][j]);
			}
		}
	}

}

//Busca em largura (BFS)
void bfs(int grafo[6][6], char* bairros[6], int inicio) {

    // cria a fila com capacidade 6 (um para cada bairro)
    Fila* fila = criarFila(6);

	// vetor que controla quais bairros já foram visitados
    // começa tudo com 0 (não visitado)
    int visitado[6] = {0};

    // marca o bairro inicial como visitado
    visitado[inicio] = 1;

	// coloca o bairro inicial na fila
    enfileirar(fila, inicio);

   printf("\nOrdem de visita (BFS):\n");

    // enquanto ainda houver bairros na fila
	while (!filaVazia(fila)) {

        // remove o primeiro da fila (ordem FIFO)
        int atual = desenfileirar(fila);

		// mostra qual bairro estamos visitando
		printf("Visitando %s\n", bairros[atual]);
	
        // agora vamos olhar TODOS os possíveis vizinhos
        for (int i = 0; i < 6; i++) {

			// condição:
            // 1. existe caminho (peso != 0)
            // 2. ainda não foi visitado
            if (grafo[atual][i] != 0 && !visitado[i]) {
 				// marca como visitado (pra não repetir depois)
                visitado[i] = 1;     

				// adiciona esse vizinho na fila
                enfileirar(fila, i);  
            }
        }
	}

	// libera memória da fila após o uso
    destruirFila(fila);
}

int main()
{
	int grafo[6][6] = {
		{0, 4, 2, 0, 0, 9}, // A
		{4, 0, 0, 3, 4, 0}, // B
		{2, 0, 0, 0, 1, 0}, // C
		{0, 3, 0, 0, 0, 5}, // D
		{0, 4, 1, 0, 0, 2}, // E
		{9, 0, 0, 5, 2, 0}  // F
	};

	char* bairros[6] = {
		"Arkham Asylum", // A
		"Wayne Tower",   // B
		"Metropolis",    // C
		"Daily Planet",  // D
		"LexCorp",       // E
		"Gotham Docks"   // F
	};

	int opcao;
	do {
		limparTela();
		printf("\n===== MENU =====\n");
		printf("1 - Exibir grafo\n");
		printf("2 - Executar BFS\n");
		printf("3 - Executar DFS\n");
		printf("4 - Menor caminho (Dijkstra)\n");
		printf("5 - Sair\n");
		printf("Escolha: ");
		scanf("%d", &opcao);
		limparTela();

		switch (opcao) {
		case 1:
			exibirGrafo(grafo, bairros);
			break;

		case 2:
			bfs(grafo, bairros, 0); // Inicia BFS a partir do bairro A (index 0)
			break;

		case 3:
			printf("DFS ainda nao implementado.\n");
			break;

		case 4:
			printf("Dijkstra ainda nao implementado.\n");
			break;

		case 5:
			printf("Saindo...\n");
			break;

		default:
			printf("Opcao invalida!\n");
		}

		printf("\nPressione ENTER para voltar ao menu...");
		while (getchar() != '\n'); // limpa
		getchar();

	} while (opcao != 5);

	return 0;
}

