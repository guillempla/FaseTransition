#include "unionfind.hh"


UnionFind::UnionFind(const int n) {
  this->n = n+2;
  this->id = vector<int>(this->n);
  this->sz = vector<int>(this->n);
  for (int i = 0; i < this->n; i++) {
    id[i] = i;
    sz[i] = 1;
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
  int i = find(p);
  int j = find(q);
  if (i == j) return;
  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  }
  else {
    id[j] = i;
    sz[i] += sz[j];
  }
}

void UnionFind::initializeTopBottom(const list<int>& top, const list<int>& bottom) {
  list<int>::const_iterator it;
  for (it = top.begin(); it != top.end(); it++)
    unify(n-2, *it);
  list<int>::const_iterator it2;
  for (it2 = bottom.begin(); it2 != bottom.end(); it2++)
    unify(n-1, *it2);
}

bool UnionFind::connected() {
  return find(n-2) == find(n-1);
}
