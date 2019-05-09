#include <vector>

using std::vector;


class UnionFind {
  public:
    vector<int> id;
    vector<int> sz;
  public:
    UnionFind(const int n);
  public:
    int find(int i);
    void unify(const int p, const int q);
};
