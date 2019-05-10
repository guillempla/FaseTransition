#include "graph.hh"


Graph::Graph(const int vert) {
  this->graph = vector<list<int> >(vert, list<int>());
}

Graph::~Graph() {}

vector<list<int> > Graph::getGraph() const {
  return this->graph;
}

void Graph::addEdge(const int vert0, const int vert1) {
  this->graph[vert0].push_back(vert1);
  this->graph[vert1].push_back(vert0);
}

void Graph::deleteEdge(int vert0, int vert1){
  this->graph[vert0].remove(vert1);
  this->graph[vert1].remove(vert0);
}

void Graph::deleteVert(int vert){
  for (list <int>::iterator it = this->graph[vert].begin(); it != this->graph[vert].end(); ++it){
    this->graph[*it].remove(vert);
  }
  this->graph[vert].clear();
}

void Graph::read() {
  //int nVerts; cin >> nVerts;
  int vert0, vert1;
  while (cin >> vert0 >> vert1) {
    this->addEdge(vert0, vert1);
  }
}
