#include "graph.cc"

int main(){
	
	//creacio de graf buit
	cout <<"< TEST 0 >" << endl;
	Graph G0;
	G0.print();
	cout << endl;

	//creacio de graf amb 10 vertex sense arestes
	cout <<"< TEST 1 >" << endl;
	Graph G2(10);
	G2.print();
	cout << endl;

	//creacio triangle
	cout <<"< TEST 2 >" << endl;
	Graph G4(3);
	G4.addEdge(0,1);
	G4.addEdge(1,2);
	G4.addEdge(2,0);
	G4.print();
	cout << endl;

	Graph G6 = G4;
	G4 = Graph();
	G4.print();

	G6.print();

}