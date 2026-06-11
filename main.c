
#include <stdio.h>
#include <stdlib.h>


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

void limparTela() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
}


int main()
{
	int grafo[6][6] = {
		{0, 4, 2, 0, 0, 0}, // A
		{4, 0, 0, 3, 4, 0}, // B
		{2, 0, 0, 0, 1, 0}, // C
		{0, 3, 0, 0, 0, 5}, // D
		{0, 4, 1, 0, 0, 2}, // E
		{0, 0, 0, 5, 2, 0}  // F
	};

	char* bairros[6] = {
		"Centro",         // A
		"Guaraituba",     // B
		"Roça Grande",    // C
		"Maracanã",       // D
		"Campo Pequeno",  // E
		"Atuba"           // F
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
			printf("BFS ainda nao implementado.\n");
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

