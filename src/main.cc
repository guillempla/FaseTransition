#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <set>
using std::set;

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
typedef pair<Graph, Graph> Percolation;

// ========================================================================== //

Percolation percolate(const Graph& graph, float q) {
  // Graph gPv = vertPercolation();
  // Graph gPe = edgePercolation();
}

// -------------------------------------------------------------------------- //

int main() {
  int nVert; cin >> nVert;
  Graph graph(nVert);
  graph.read();
  for (int q = 0; q <= 1; q += 0.1) {
    
  }
}
