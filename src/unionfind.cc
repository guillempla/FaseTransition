#include "unionfind.hh"


UnionFind::UnionFind(const int n) {
  this->id = vector<int>(n);
  for (int i = 0; i < n; i++) {
    id[i] = i;
  }
}

int UnionFind::find(int i) {
  while (i != id[i]) {
    id[i] = id[id[i]];
    i = id[i];
  }
  return i;
}

void UnionFind::unify(const int p, const int q) {
  id[find(p)] = find(q);
}
