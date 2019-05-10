#include "graph.hh"

Graph::Graph(){}

Graph::Graph(const int vert) {
  this->graph = vector<list<int> >(vert, list<int>());
}
/*
Graph::Graph(const Graph & graph){
	vector <list <int>> aux = graph.getGraph();
	this->graph = vector<list<int> >(aux.size(), list<int>());
	for (int i = 0; i < aux.size(); ++i){
		this->graph[i] = aux[i];
	}
}*/

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

Graph Graph::percolateVertices(int q) {
  Graph g = *this;
  for(int i = 0; i < graph.size(); ++i)
    if (rand()%1 < q)
      deleteVert(i);
  return g;
}

Graph Graph::percolateEdges(int q) {
  Graph aux = *this;
  Graph g(this->graph.size());
  for (int i = 0; i < this->graph.size(); ++i) {
    list<int>::iterator it;
    for (it = this->graph[i].begin(); it != this->graph[i].end(); it++) {
      if (!rand()%1 < q)
        g.addEdge(i, *it);
      deleteEdge(i, *it);
    }
  }
  *this = aux;
  return g;
}

bool Graph::checkConnected(const list<int>& top, const list<int>& bottom) {
  UnionFind uf(this->graph.size());
  uf.initializeTopBottom(top, bottom);
  for (int i = 0; i < this->graph.size(); ++i) {
    list<int>::iterator it;
    for (it = this->graph[i].begin(); it != this->graph[i].end(); it++)
      uf.unify(i, *it);
  }
  return uf.connected();
}

void Graph::read() {
  //int nVerts; cin >> nVerts;
  int vert0, vert1;
  while (cin >> vert0 >> vert1) {
    if (vert0 == -1 || vert1 == -1) break;
    this->addEdge(vert0, vert1);
  }
}

void Graph::print() const{
	int size = this->graph.size();
	if (size > 0){
		for (int i = 0; i < size ; ++i){
			cout << "(" << i << ") : ";
			for (list <int>::const_iterator it = this->graph[i].cbegin(); it != this->graph[i].cend(); ++it){
				cout << *it << " ";
			}
			cout << endl;
		}
	}else{
		cout << "empty graph" << endl;
	}
}
