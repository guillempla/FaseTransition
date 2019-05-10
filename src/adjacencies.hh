#include <iostream>
#include <list>
#include <vector>

using namespace std;


class Graph {
  private:
    vector <list <int> > graph;
  public:
    Graph();
    ~Graph();
  public:
    getGraph();
    readGraph();
    printGraph();
    deleteEdge(int vert0, int vert1);
    deleteVertice(int vertice)
};
