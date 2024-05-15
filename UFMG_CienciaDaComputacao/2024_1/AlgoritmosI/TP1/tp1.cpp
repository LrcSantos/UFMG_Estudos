#include <iostream>
#include <cstdio>
#include <stack>
#include <list>
#include <vector>
#include <set>
#include <algorithm>

struct VertexData {
    int cor; // 0 = Branco, 1 = Cinza, 2 = Preto
    int pi; // Pai
    int d; // Tempo de descoberta
    int f; // Tempo de finalização
    int low; // Menor tempo de descoberta dos descendentes
    bool ap; // Ponto de articulação
};

class Grafo {
	private:
		int _V; // Número de vértices
		std::list<int> * adj; // Lista de adjacência
		void DFS_VisitAP(int u, std::vector<VertexData> &vertexData, int &tempo, std::stack<std::pair<int, int>> &pilha, std::list<std::set<int>>& conjuntos, int &articulationCount, int &conjuntosCount); // função DFS
		
	public:

		// Construtor
		Grafo(int V);
		// Destrutor
		~Grafo();

		// Adiciona arestas
		void adicionarAresta(int i, int j);

        // Função para pegar os pontos de articulação (liks) e biocomponentes (clusters)
		void getArticulationPoints();

};

    Grafo::Grafo(int V) {
		_V = V;
		adj = new std::list<int>[V + 1]; // Cria as listas
	}

	Grafo::~Grafo() {
		delete[] adj;
	}

	// Adiciona arestas
	void Grafo::adicionarAresta(int i, int j) {
		// Adiciona "j" à lista de adjacência de "i"
		adj[i].push_back(j);
        adj[j].push_back(i);
	}

	void Grafo::DFS_VisitAP(int u, std::vector<VertexData>& vertexData, int& tempo, std::stack<std::pair<int, int>>& pilha, std::list<std::set<int>>& conjuntos, int& articulationCount, int& conjuntosCount) {
		tempo++;
		vertexData[u].d = tempo;
		vertexData[u].cor = 1; // Cinza
		vertexData[u].low = vertexData[u].d;
		int filhos = 0;
		bool isArticulation = false;

		for(int v : adj[u]) {
			if(vertexData[v].cor == 0) {
				vertexData[v].pi = u;
				pilha.push(std::make_pair(u, v));
				DFS_VisitAP(v, vertexData, tempo, pilha, conjuntos, articulationCount, conjuntosCount);
				filhos++;
				if(vertexData[v].low >= vertexData[u].d) {
					isArticulation = true;
					conjuntosCount++;
					std::pair<int, int> p;
					std::set<int> conjunto;
					do {
						p = pilha.top();
						pilha.pop();
						conjunto.insert(p.first);
						conjunto.insert(p.second);
					} while(p != std::make_pair(u, v));
					conjuntos.push_back(conjunto);
				}
				vertexData[u].low = std::min(vertexData[u].low, vertexData[v].low);

			} else if(v != vertexData[u].pi) {
				vertexData[u].low = std::min(vertexData[u].low, vertexData[v].d);
			}
		}

		vertexData[u].cor = 2; // Preto
		tempo++;
		vertexData[u].f = tempo;

		if ((vertexData[u].pi == -1 && filhos > 1) || (vertexData[u].pi != -1 && isArticulation)) {
			vertexData[u].ap = true;
			articulationCount++;
		}
	}

	void Grafo::getArticulationPoints() {
		std::vector<VertexData> vertexData(_V + 1, {0, -1, 0, 0, 0, false});
		std::stack<std::pair<int, int>> pilha; // Pilha para armazenar as arestas
		std::list<std::set<int>> conjuntos; // Lista de conjuntos
		int articulationCount = 0; // Contador de pontos de articulação
		int conjuntosCount = 0; // Contador de conjuntos
		int tempo = 0; // Tempo

		for(int u = 1; u < _V + 1; u++) {
			if(vertexData[u].cor == 0) {
				DFS_VisitAP(u, vertexData, tempo, pilha, conjuntos, articulationCount, conjuntosCount);
			}
		}

		conjuntos.sort([](const std::set<int>& a, const std::set<int>& b) {
			auto it_a = a.begin();
			auto it_b = b.begin();

			// Percorre os conjuntos comparando os elementos em pares
			while (it_a != a.end() && it_b != b.end()) {
				if (*it_a < *it_b) {
					return true; // a vem antes de b
				} else if (*it_b < *it_a) {
					return false; // b vem antes de a
				}
				// Avança para o próximo par de elementos
				++it_a;
				++it_b;
			}

			// Se os conjuntos tiverem prefixos comuns, o menor é considerado primeiro
			return a.size() < b.size();
		});
		
		printf("%d\n", articulationCount); // Imprime o número de pontos de articulação

		std::vector<int> articulationPoints (articulationCount); // Vetor para armazenar os pontos de articulação

		int numArticulationPoints = 0; // Contador de pontos de articulação

		for (int u = 1; u < _V + 1; u++) {
			if (vertexData[u].ap == 1) {
				numArticulationPoints++;
			}
		}

		int j = 0; 
		for (int u = 1; u < _V + 1; u++) {
			if (vertexData[u].ap == 1) {
				printf("%d", u);
				articulationPoints[j] = u;
				j++;
				if (j < numArticulationPoints) {
					printf("\n");
				}
			}
		}

		if (articulationCount > 0) {
			printf("\n");
		}	

		printf("%d\n", conjuntosCount);

		std::vector<int> indices(conjuntos.size()); // Vetor para armazenar os índices dos conjuntos

		for (std::list<std::set<int>>::size_type i = 0; i < conjuntos.size(); i++) {
			indices[i] = _V + i + 1;
		}

		int num_arestas = 0;
		std::vector<std::pair<int, int>> arestas; // Vetor para armazenar as arestas

		// Imprime os conjuntos
		for (auto& conjunto : conjuntos) {
			printf("%d ", indices.front());
			printf("%ld ", conjunto.size());

			for (auto vertice : conjunto) {
				printf("%d ", vertice);
				for (auto& articulationPoint : articulationPoints) {
					if (articulationPoint == vertice) {
						arestas.push_back(std::make_pair(vertice, indices.front()));
						num_arestas++;
					}
				}
			}
			printf("\n");
			indices.erase(indices.begin());
		}

		printf("%d %d", articulationCount+conjuntosCount, num_arestas);

		if (num_arestas > 0) {
			printf("\n");
		}

		std::sort(arestas.begin(), arestas.end());

		size_t numArestas = arestas.size();
		for (size_t i = 0; i < numArestas; ++i) {
			printf("%d %d", arestas[i].first, arestas[i].second);
			if (i < numArestas - 1) {
				printf("\n");
			}
		}
	}


int main() {
    int n, m; //número de vértices e arestas
    if (scanf("%d %d", &n, &m) != 2 || n < 0 || m < 0) {
        std::cerr << "Entrada inválida para o número de vértices ou arestas.";
		printf("\n");
        return 1;
    }

    Grafo g(n);

    try {
        for (int i = 0; i < m; i++) {
            int u, v;
            if (scanf("%d %d", &u, &v) != 2) {
                throw std::runtime_error("Erro ao ler aresta.");
            }
            g.adicionarAresta(u, v);
        }

        g.getArticulationPoints();
    } catch (const std::exception& e) {
        std::cerr << "Exceção capturada: " << e.what();
		printf("\n");
        return 1;
    }

    return 0;
}
