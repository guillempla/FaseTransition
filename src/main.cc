#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <utility>
using std::pair;
using std::make_pair;

#include "graph.hh"
#include "unionfind.hh"

// ========================================================================== //

typedef vector<int> Row;
typedef vector<Row> Graph;
typedef pair<pair<Graph, bool>, pair<Graph, bool> > Percolation;

// ========================================================================== //

Percolation percolate(const Graph& graph, float q) {

  // Graph nPerc = nodePercolation();
  // Graph ePerc = edgePercolation();
  return make_pair(make_pair(graph, false), make_pair(graph, true));
}

// -------------------------------------------------------------------------- //

int main() {
  Graph graph = readGraph();
  cout << "Probabilitat de fallida: ";
  float q; cin >> q;
  Percolation perc = percolate(graph, q);
  cout << endl << "Matriu adjacències graf percolat per nodes:" << endl;
  printGraph(perc.first.first);
  perc.first.second ? cout << "Percola" : cout << "No percola";
  cout << endl << endl << "Matriu adjacències graf percolat per arestes:" << endl;
  printGraph(perc.second.first);
  perc.second.second ? cout << "Percola" : cout << "No percola";
  cout << endl;
}
