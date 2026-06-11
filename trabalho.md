📘 Atividade: Sistema de Rotas Inteligentes para Entregas Urbanas


Atividade a ser realizado em grupo até 3 pessoas.

Deve ser entregue o código postado no Blackboard e a nota será concedida mediante defesa de código em sala de aula.



🎯 Objetivo
Desenvolver, em linguagem C, um sistema simples de planejamento de rotas para entregas em uma cidade, utilizando:

Representação de grafos com matriz de adjacência
Algoritmos de busca em largura (BFS) e busca em profundidade (DFS)
Algoritmo de Dijkstra para caminho mínimo


🧩 Contextualização (Cenário Prático)
Uma empresa de logística precisa otimizar suas rotas de entrega em um bairro. Os pontos de entrega e cruzamentos são representados como vértices, e as ruas como arestas, com pesos que indicam distância ou tempo de deslocamento.

O sistema deve permitir:

Explorar a rede de ruas
Verificar conectividade
Encontrar o melhor caminho entre dois pontos

📌 Descrição da Atividade
🧱 Etapa 1 — Modelagem do Grafo
Representar o mapa como um grafo ponderado
Usar matriz de adjacência
Permitir:
Definir número de vértices (mínimo: 6)
Inserir arestas com pesos (distância)
🔍 Etapa 2 — Implementar BFS
Função para percorrer o grafo a partir de um vértice inicial
Mostrar a ordem de visita
Aplicação prática: verificar alcance de regiões (ex: entregas possíveis a partir de um ponto)
🌳 Etapa 3 — Implementar DFS
Função recursiva ou com pilha
Mostrar a ordem de visita
Aplicação prática: explorar todas as rotas possíveis (ex: análise de cobertura)
🚀 Etapa 4 — Algoritmo de Dijkstra
Implementar cálculo do menor caminho
Entrada:
Vértice de origem
Vértice de destino
Saída:
Distância mínima
Caminho percorrido (ex: A → B → C)
💻 Etapa 5 — Interface Simples (Terminal)
Criar um menu interativo:

1 - Exibir matriz de adjacência
2 - Executar BFS
3 - Executar DFS
4 - Encontrar menor caminho (Dijkstra)
5 - Sair
 


✅ Entrega
Código-fonte completo (.c ou .zip)