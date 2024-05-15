#include <iostream>
#include <stack>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

#define INF 0x3f3f3f3f // Definindo o valor de infinito

struct ResultadoDijkstra {
    std::stack<int> caminhoFinal;
    int CUSTO; // Custo final
    int TURNOS; // Turnos final
    int RESULTADO; // Resultado final
};

typedef std::pair<int, int> no;
struct Aresta {
    int _custo; // Custo da aresta
    int _dest; // Vértice de destino
    int _turno; // Turno em que a aresta foi percorrida

    bool operator<(const Aresta& other) const {
        return _custo < other._custo; 
    }
};

struct compareAresta {
    bool operator()(Aresta const& t1, Aresta const& t2)
    {   
        if (t1._custo != t2._custo) {
            return t1._custo > t2._custo;} 
        else if (t1._turno != t2._turno) {
            return t1._turno < t2._turno;
      } else {
        return t1._dest > t2._dest;
      };
    }
};

class Grafo {
	private:
		int _V; // Número de vértices
		std::vector<std::vector<no>> adj; // Lista de adjacência
        std::vector<std::vector<no>> transposto; // Lista de adjacência
		std::vector<int> monstros; // Vértices onde os monstros estão presentes

	public:
		// Construtor
		Grafo(int V);
		// Destrutor
		~Grafo();

		// Adiciona arestas
		void adicionarAresta(int i, int j, int w); // Adiciona aresta
		void adicionarMonstro(int v_monstro); // Adiciona monstro
 
        void adicionarLaco(); // Adiciona laço com custo 1

		std::vector<int> BFS(Grafo &g, int s); // Algoritmo de busca em largura que retorna os predecessores
		std::vector<std::vector<int>> getCaminhoMonstros(std::vector<int>& predecessors); // Obtém o caminho dos monstros
		std::vector<std::vector<bool>> localizacaoMonstros(std::vector<std::vector<int>>& caminhosMonstros, int n, int j, int t); // Verifica a localização dos monstros
        ResultadoDijkstra Dijkstra(Grafo &g, int s, int t, int k, std::vector<std::vector<bool>> localizacaoMonstros); // Algoritmo de Dijkstra modificado para o problema

        void printResultado(int RESULTADO); // Imprime o resultado
        void printCaminhoMonstros(std::vector<std::vector<int>>& caminhosMonstros); // Imprime os caminhos dos monstros
        void printCustoTurnos(int CUSTO, int TURNOS); // Imprime o custo e os turnos
        void printCaminhoFinal(std::stack<int> caminhoFinal); // Improme o caminho final
};

    Grafo::Grafo(int V) : _V(V), adj(V), transposto(V) {}

	Grafo::~Grafo() {}

	// Adiciona arestas
	void Grafo::adicionarAresta(int i, int j, int w) {
		adj[i-1].push_back(std::make_pair(j-1, w));
        transposto[j-1].push_back(std::make_pair(i-1, w));
	}

    void Grafo::adicionarLaco() {
        for (int i = 0; i < _V; ++i) {
            adicionarAresta(i + 1, i + 1, 1);
        }
    }

	void Grafo::adicionarMonstro(int v_monstro) {
		monstros.push_back(v_monstro);
	}

	std::vector<int> Grafo::BFS(Grafo &g, int s) {
        std::vector<int> pi(_V, -1);
        std::vector<int> d(_V + 1, 0);
        std::vector<bool> cor(_V, 0);
        std::queue<int> Q;

        cor[s] = 1;
        d[s] = 0;
        pi[s] = -1;
        Q.push(s);

        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();

            for (auto& a : g.transposto[u]) {
                if (cor[a.first] == 0) {
                    cor[a.first] = 1;
                    d[a.first] = d[u] + 1;
                    pi[a.first] = u;
                    Q.push(a.first);
                }
                else if (d[a.first] == d[u] + 1 && pi[a.first] > u) {
                    pi[a.first] = u;
                }
            }
            cor[u] = 2;
        }
        return pi;
	}

	std::vector<std::vector<int>> Grafo::getCaminhoMonstros(std::vector<int>& predecessors) {
		std::vector<std::vector<int>> caminhos;

		for (size_t i = 0; i < monstros.size(); i++) {
            std::vector<int> caminho;
            int v = monstros[i];
            while (v != -1) {
                caminho.push_back(v + 1);
                v = predecessors[v];
            }
            caminhos.push_back(caminho);
        }

        return caminhos;
	}

	std::vector<std::vector<bool>> Grafo::localizacaoMonstros(std::vector<std::vector<int>>& caminhosMonstros, int n, int j, int t) {
		std::vector<std::vector<bool>> localizacao(t + 1, std::vector<bool>(n, false));

        for (int i = 0; i < j; i++) {
            int tamanho = caminhosMonstros[i].size();

            if (tamanho == 1) {
                int v = caminhosMonstros[i][0] - 1;
                for (int turno = 0; turno < t+1; turno++) {
                    localizacao[turno][v] = true;
                }
                continue;
            }

            for (int turno = 0; turno < tamanho; turno++) {
                int prox = caminhosMonstros[i][turno] - 1;
                localizacao[turno][prox] = true;
            }

            for (int turno = tamanho; turno < t+1; turno++) {
                localizacao[turno][0] = true;
            }
        }

        return localizacao;
	}

    ResultadoDijkstra Grafo::Dijkstra(Grafo &g, int s, int t, int k, std::vector<std::vector<bool>> localizacaoMonstros) {
        std::priority_queue<Aresta, std::vector<Aresta>, compareAresta> Q;

        std::vector<std::vector<int>> d(_V, std::vector<int>(t+1, INF)); // Distância
        std::vector<std::vector<int>> pi(_V, std::vector<int>(t+1, -1)); // Predecessores
        std::vector<std::vector<int>> cor(_V, std::vector<int>(t+1, 0)); // Visitados
        std::vector<std::vector<bool>> locMonstros = localizacaoMonstros; // Localização dos monstros
        ResultadoDijkstra resultado;

        d[s][0] = 0;
        pi[s][0] = -1;
        Q.push(Aresta{0, s, 0});
        cor[s][0] = 1;

        Aresta melhorCaminho = {0, s, 0};
        Aresta destino = {0, s, 0};

        while(!Q.empty()) {

            Aresta tupla = Q.top();
            Q.pop();

            int u = tupla._dest;
            int custo = tupla._custo;
            int turno = tupla._turno;

            if (custo > d[u][turno]) {
                continue;
            }
            
            bool conditions = turno > melhorCaminho._turno 
            || (turno == melhorCaminho._turno && custo < melhorCaminho._custo) 
            || (turno == melhorCaminho._turno) && (custo == melhorCaminho._custo) && (u < melhorCaminho._dest);

            if (conditions) {
                melhorCaminho = tupla;
            }

            if (u == _V - 1) {
                destino = tupla;
                break;
            }

            if (turno == t) {
                continue;
            }

            cor[u][turno] = 2;

            for (no a : g.adj[u]) {
                int v = a.first;
                int w = a.second;

                if (cor[v][turno+1] == 2) {
                    continue;
                }

                if (locMonstros[turno][v] || locMonstros[turno+1][v]) {
                    continue;
                }

                int distAtual = d[v][turno+1];
                int distNova = d[u][turno] + w;
                int recursos = (turno + 1) * k;

                if (distAtual > distNova && distNova <= recursos) {
                    d[v][turno+1] = distNova;
                    pi[v][turno+1] = u;
                    Q.push({d[v][turno+1], v, turno+1});
                }
            }
        }

        int vertice, turnos;
        if (destino._turno > 0) {
            resultado.RESULTADO = 1;
            turnos = resultado.TURNOS = destino._turno; 
            vertice = destino._dest;
        } 

        else {
            resultado.RESULTADO = 0;
            turnos = resultado.TURNOS = melhorCaminho._turno;
            vertice = melhorCaminho._dest;
        }

        resultado.CUSTO = d[vertice][turnos];

        resultado.caminhoFinal.push(vertice + 1);

        for (int i = 0; i < turnos; i++) {
            vertice = pi[vertice][turnos-i];
            resultado.caminhoFinal.push(vertice+1);
        }

        return resultado;
    }

    void Grafo::printResultado(int RESULTADO) {
        printf("%d\n", RESULTADO);
    }

    void Grafo::printCaminhoMonstros(std::vector<std::vector<int>>& caminhosMonstros) {
        for (size_t i = 0; i < caminhosMonstros.size(); ++i) {
            printf("%ld ", caminhosMonstros[i].size());
            for (size_t j = 0; j < caminhosMonstros[i].size(); ++j) {
                printf("%d", caminhosMonstros[i][j]);
                if (j != caminhosMonstros[i].size() - 1)
                    printf(" ");
            }
            printf("\n");
        }
    }

    void Grafo::printCustoTurnos(int CUSTO, int TURNOS) {
        printf("%d %d\n", CUSTO, TURNOS);
    }

    void Grafo::printCaminhoFinal(std::stack<int> caminhoFinal) {
        while (!caminhoFinal.empty()) {
            printf("%d ", caminhoFinal.top());
            caminhoFinal.pop();
        }
        printf("\n");
    }

int main() {
    int n, m, j, t, k; //número de vértices, arestas, monstros, turnos e recursos
    if (scanf("%d %d %d %d %d", &n, &m, &j, &t, &k) != 5 || n < 0 || m < 0 || j < 0 || t < 0 || k < 0) {
        std::cerr << "Entrada inválida para o número de vértices ou arestas.";
		printf("\n");
        return 1;
    }

    Grafo g(n);
    g.adicionarLaco();

    for (int i = 0; i < j; i++) {
        int v_monstro;
        if (scanf("%d", &v_monstro) != 1 || v_monstro < 0 || v_monstro > n) {
            std::cerr << "Entrada inválida para o vértice do monstro.";
            printf("\n");
            return 1;
        }

        g.adicionarMonstro(v_monstro - 1);
    }

    try {
        for (int i = 0; i < m; i++) {
            int u, v, w;
            if (scanf("%d %d %d", &u, &v, &w) != 3) {
                throw std::runtime_error("Erro ao ler aresta.");
            }
            g.adicionarAresta(u, v, w);
        }
    } catch (const std::exception& e) {
        std::cerr << "Exceção capturada: " << e.what();
		printf("\n");
        return 1;
    }

    std::vector<int> predecessors = g.BFS(g, 0);

    std::vector<std::vector<int>> caminhosMonstros = g.getCaminhoMonstros(predecessors);

    std::vector<std::vector<bool>> locMonstros = g.localizacaoMonstros(caminhosMonstros, n, j, t);

    ResultadoDijkstra resultado = g.Dijkstra(g, 0, t, k, locMonstros);

    g.printResultado(resultado.RESULTADO);

    g.printCaminhoMonstros(caminhosMonstros);

    g.printCustoTurnos(resultado.CUSTO, resultado.TURNOS);

    g.printCaminhoFinal(resultado.caminhoFinal);

    return 0;
}
