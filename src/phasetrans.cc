#include <iostream>
#include <vector>
#include <utility>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::pair;
using std::make_pair;

typedef vector<int> Row;
typedef vector<Row> Graph;


pair<bool, pair<Graph, Graph> > percolate(const Graph& graph, float q) {

  Graph nPerc = nodePercolation();
  Graph ePerc = edgePercolation();
  return make_pair(false, make_pair(graph, graph));
}

inline Graph readGraph() {
  cout << "Mida del graf n x n: ";
  int n; cin >> n;
  cout << "Matriu d'adjacències del graf:" << endl;
  Graph graph(n, Row(n));
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j)
      cin >> graph[i][j];
  return graph;
}

inline void printGraph(const Graph& graph) {
  int row = graph.size();
  int cols = graph[0].size();
  for (int i = 0; i < row; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << graph[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  Graph graph = readGraph();
  cout << "Probabilitat de fallida: ";
  float q; cin >> q;
  pair<bool, pair<Graph, Graph> > p = percolate(graph, q);
  p.first ? cout << "Percola" : cout << "No percola";
  cout << endl << "Matriu adjacències graf percolat per nodes:" << endl;
  printGraph(graph);
  cout << endl << "Matriu adjacències graf percolat per arestes:" << endl;
  printGraph(graph);
}
