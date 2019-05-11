#include <vector>
#include <list>

using namespace std;


class UnionFind {
  private:
    int n;
    vector<int> id;
    vector<int> sz;
  public:
    UnionFind(int n);
  public:
    int find(int i);
    void unify(const int p, const int q);
    void initializeTopBottom(const list<int>& top, const list<int>& bottom);
    bool connected();
};
