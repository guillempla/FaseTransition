#include <iostream>

#include "unionfind.hh"

using std::cin;
using std::cout;
using std::endl;

void printVecInt(const vector<int>& v) {
  cout << v[0];
  uint size = v.size();
  for (uint i = 1; i < size; i++) {
    cout << ", " << v[i];
  }
  cout << endl;
}

int main() {
  cout << endl << "Introdueix la N del graf: ";
  int n; cin >> n;
  UnionFind uF(n * n);
  cout << endl << "Vector incial: ";
  printVecInt(uF.id);
  cout << endl;
  cout << "Introdueix l'element a buscar: ";
  cin >> n;
  cout << endl << "L'element pertany al grup: " << uF.find(n) << endl;
  int aux;
  while (1) {
    cout << endl << "Introdueix els dos elements a unir: ";
    cin >> n >> aux;
    uF.unify(n, aux);
    cout << endl << "Vector actual: ";
    printVecInt(uF.id);
    cout << endl;
  }
}
