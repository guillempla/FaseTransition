#include <iostream>
#include <list>
#include <vector>

using namespace std;


class Graph {
  private:
    vector<list<int> > graph;
  public:
    Graph(const int vert);
    ~Graph();
  public:
    vector<list<int> > getGraph() const;
    void addEdge(const int vert0, const int vert1);
    void deleteEdge(int vert0, int vert1);
    void deleteVert(int vert);
  public:
    void read();
    void print() const;
};
