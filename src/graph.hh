#ifndef GRAPH_HH
#define GRAPH_HH

#include <iostream>
#include <list>
#include <vector>
#include "unionfind.hh"

using namespace std;


class Graph {
  private:
    vector<list<int> > graph;
    int nEdges;
    int nVertices;
  public:
    //___________CONSTRUCTORES__________
    Graph();
    Graph(const int vert);
    //Graph(const Graph & graph);
    ~Graph();
    //___________MODIFICADORES__________
    void addEdge(const int vert0, const int vert1);
    void deleteEdge(int vert0, int vert1);
    void deleteVert(int vert);
    void read();
    
  public:
    //__________CONSULTORES__________
    vector<list<int> > getGraph() const;
    int getNedges() const;
    int getNvertices() const;
    Graph percolateVertices(int numerador, int denominador) const;
    Graph percolateEdges(int numerador, int denominador);
    bool checkConnected(const list<int>& top, const list<int>& bottom) const;
    void print() const;

    //ALTRES
    bool probabilitat(int numerador, int denominador) const;
    bool probabilitat_complementaria(int numerador, int denominador) const;
};
#endif
