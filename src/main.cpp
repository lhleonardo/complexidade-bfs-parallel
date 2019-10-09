#include <iostream>
#include <list>
#include <fstream>

#include "graph/graph.cpp"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Utilização: " << argv[0] << " INPUT" << endl;
        cerr << "\t- INPUT: arquivo de mapeamento dos vértices" << endl;

        exit(EXIT_FAILURE);
    }
    string caminho = argv[1];

    // cout << "Informe o arquivo de entrada: ";
    // cin >> caminho;
    
    ifstream arquivo(caminho);

    if (not arquivo) {
        cerr << "Não foi possível abrir o arquivo!" << endl;
        exit(EXIT_FAILURE);
    }

    unsigned quantidade;
    arquivo >> quantidade;
    string leitura;

    Graph<string> grafo;

    for (unsigned i = 0; i < quantidade; i++) {
        arquivo >> leitura;
        grafo.add(leitura);
    }

    arquivo >> quantidade;

    string leitura2;
    for (unsigned i = 0; i < quantidade; i++) {
        arquivo >> leitura >> leitura2;
        grafo.buildEdge(leitura, leitura2, 1);
    }

    // primeiro elemento
    arquivo >> leitura;

    grafo.applyBFS(leitura);

    grafo.print();

    return 0;
}

