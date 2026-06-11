
#include <stdio.h>
#include <stdlib.h>
#include "../include/fila.h"
#include "../include/pilha.h"
#include <limits.h>

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

// Busca em profundidade (DFS) - Utiliza pilha manualmente. Recursivo seria mais simples,
// mas aqui queremos praticar a pilha.
void dfs(int grafo[6][6], char* bairros[6], int inicio) {

    Pilha* pilha = criarPilha(6);
    int visitado[6] = {0};

    empilhar(pilha, inicio);

    printf("\nOrdem de visita (DFS com pilha):\n");

    while (!pilhaVazia(pilha)) {

        int atual = desempilhar(pilha);

        if (!visitado[atual]) {

            visitado[atual] = 1;
            printf("Visitando %s\n", bairros[atual]);
			
			//6 bairros, índices de 0 a 5. 
			//Para DFS, empilhamos os vizinhos na ordem inversa para visitar na ordem correta.
			//A inversão no loop garante que, ao usar uma estrutura LIFO (pilha), 
			//a ordem final de visita do DFS seja consistente com a lógica esperada de exploração.
			
            for (int i = 5; i >= 0; i--) {
                if (grafo[atual][i] != 0 && !visitado[i]) {
                    empilhar(pilha, i);
                }
            }
        }
    }

    destruirPilha(pilha);
}


// Algoritmo de Dijkstra para encontrar o menor caminho entre dois bairros
void dijkstra(int grafo[6][6], char* bairros[6], int origem, int destino) {

    // dist[i] armazena a menor distância conhecida da origem até o vértice i
    int dist[6];

    // visitado[i] indica se o vértice já foi "confirmado" (processado)
    int visitado[6];

    // anterior[i] guarda de qual vértice viemos para chegar em i (usado para reconstruir o caminho)
    int anterior[6];

    //Inicialização
    for (int i = 0; i < 6; i++) {
        dist[i] = INT_MAX;   // inicialmente, todos os caminhos são considerados "infinito"
        visitado[i] = 0;     // nenhum vértice foi visitado ainda
        anterior[i] = -1;    // ainda não sabemos o caminho
    }

    // A distância da origem até ela mesma é sempre 0
    dist[origem] = 0;

    // Processamento principal
    for (int i = 0; i < 6 - 1; i++) {

        int menor = -1;

        // Escolher o vértice não visitado com a menor distância atual
        for (int j = 0; j < 6; j++) {
            if (!visitado[j] && (menor == -1 || dist[j] < dist[menor])) {
                menor = j;
            }
        }

        // Marcar esse vértice como processado (definitivo)
        visitado[menor] = 1;

        //  Relaxamento das arestas
        // "Relaxar" significa tentar melhorar a distância dos vizinhos
        for (int v = 0; v < 6; v++) {

            // verifica se existe conexão entre os vértices
            if (grafo[menor][v] != 0 && !visitado[v]) {

                // calcula o custo de ir até v passando por "menor"
                int novoCusto = dist[menor] + grafo[menor][v];

                // se esse caminho for melhor, atualiza
                if (novoCusto < dist[v]) {
                    dist[v] = novoCusto;
                    anterior[v] = menor;
                }
            }
        }
    }

    //Resultado final

    printf("\n===== RESULTADO DIJKSTRA =====\n");

    printf("Menor distancia de %s ate %s: %d\n",
           bairros[origem],
           bairros[destino],
           dist[destino]);

    // Reconstrução do caminho
    // aqui voltamos do destino até a origem usando o vetor "anterior"

    int caminho[6];
    int count = 0;

    for (int i = destino; i != -1; i = anterior[i]) {
        caminho[count++] = i;
    }

    printf("Caminho percorrido: ");

    // imprime de trás para frente (origem → destino)
    for (int i = count - 1; i >= 0; i--) {
        printf("%s", bairros[caminho[i]]);

        if (i > 0) {
            printf(" -> ");
        }
    }

    printf("\n");
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
			dfs(grafo, bairros, 0); // Inicia DFS a partir do bairro A (index 0)
			break;

		case 4: {
			int origem, destino;

			printf("Digite o bairro de origem (0 a 5): ");
			scanf("%d", &origem);

			printf("Digite o bairro de destino (0 a 5): ");
			scanf("%d", &destino);

			limparTela();

			if (origem < 0 || origem > 5 || destino < 0 || destino > 5) {
				printf("Entrada invalida!\n");
				break;
			}

			dijkstra(grafo, bairros, origem, destino);
			break;
		}

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

