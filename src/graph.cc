#include "graph.hh"
//___________CONSTRUCTORES__________
Graph::Graph(){
	this->nVertices = 0;
	this->nEdges = 0;
}

Graph::Graph(const int vert) {
  this->graph = vector<list<int> >(vert, list<int>());
  this->nVertices = vert;
  this->nEdges = 0;
}

Graph::~Graph() {}

vector<list<int> > Graph::getGraph() const {
  return this->graph;
}
//___________MODIFICADORES__________

void Graph::addEdge(const int vert0, const int vert1) {
  this->graph[vert0].push_back(vert1);
  this->graph[vert1].push_back(vert0);
  this->nEdges += 2;
}

void Graph::deleteVert(int vert){
	this->nEdges -= 2 * (this->graph[vert].size() );
  for (list <int>::iterator it = this->graph[vert].begin(); it != this->graph[vert].end(); ++it){
    this->graph[*it].remove(vert);
  }
  this->graph[vert].clear();
}

void Graph::deleteEdge(int vert0, int vert1){
  this->graph[vert0].remove(vert1);
  this->graph[vert1].remove(vert0);
  this->nEdges -=2;
}

void Graph::read() {
  int vert0, vert1;
  while (cin >> vert0 >> vert1) {
    this->addEdge(vert0, vert1);
  }
}

bool Graph::probabilitat(int numerador, int denominador)const{
  bool ret = false;
  int valor = rand()%denominador;
  if (valor < numerador) ret = true;
  return ret;
}

bool Graph::probabilitat_complementaria(int numerador, int denominador) const{
  bool ret = false;
  numerador = denominador - numerador;
  int valor = rand()%denominador;
  if (valor < numerador) ret = true;
  return ret;
}




//__________CONSULTORES__________
Graph Graph::percolateVertices(int numerador, int denominador) const {
  Graph g = *this;
  double resta;
  for(int i = 0; i < graph.size(); ++i)
    if (probabilitat(numerador, denominador))
      g.deleteVert(i);
  return g;
}
Graph Graph::percolateEdges(int numerador, int denominador) {
  Graph aux = *this;
  Graph g(this->graph.size());
  for (int i = 0; i < this->graph.size(); ++i) {
    list<int>::iterator it = this->graph[i].begin();
    while (it != this->graph[i].end()) {
      if (probabilitat_complementaria(numerador, denominador)){
        g.addEdge(i, *it);
      }
      this->deleteEdge(i, *it);
      it = this->graph[i].begin();
    }
  }
  *this = aux;
  return g;
}

bool Graph::checkConnected(const list<int>& top, const list<int>& bottom) const{
  UnionFind uf(this->graph.size());
  uf.initializeTopBottom(top, bottom);
  for (int i = 0; i < this->graph.size(); ++i) {
    list<int>::const_iterator it;
    for (it = this->graph[i].cbegin(); it != this->graph[i].cend(); it++)
      uf.unify(i, *it);
  }
  return uf.connected();
}

bool Graph::checkCicles() {
	Graph aux = *this;
	UnionFind uf(this->graph.size());
	for (int i = 0; i < this->graph.size(); ++i) {
		list<int>::iterator it = this->graph[i].begin();
		while (it != this->graph[i].end()) {
			if (not uf.unify(i, *it)) {
				*this = aux;
				return true;
			}
			this->deleteEdge(i, *it);
			it = this->graph[i].begin();
		}
	}
	*this = aux;
	return false;
}

int Graph::getNedges() const{
	return this->nEdges;
}
int Graph::getNvertices() const{
	return this->nVertices;
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
