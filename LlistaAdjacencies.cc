#include <iostream>
#include <list>
#include <vector>
#include <utility>
using namespace std;
const static int V = 10;	//#vertex de G
struct llista_adj {
	vector <list <int> > vertices;
};

int main(){
	llista_adj graf_percolat;
	graf_percolat.vertices = vector <list<int>> (V, list <int>());
	list<int>::iterator it = graf_percolat.vertices[0].begin();
	cout << graf_percolat.vertices[0].size() << endl;
}
