#include <iostream>
#include <vector>
#include <ctime>
#include "graph.hh"
#include "unionfind.hh"
using namespace std;
// ========================================================================== //

Graph percolateVert(const Graph& graph, float q) {
	return graph.percolateVertices(q)
}

Graph percolateEdge(const Graph& graph, float q)  {
	return graph.percolateEdges(q);
}

bool connectaGraella(const Graph& graph, int N){
	list <int> entrada;
	for (int i = 0; i < N; ++i) entrada.push_back(i);
	list <int> sortida;
	for (int i = N*N - N; i < N*N; ++i ) sortida.push_back(i);
	return checkConnected(entrada, sortida);
}

double calcula_temps(double inici, double fi){
	return (1000*(fi-inici))/CLOCKS_PER_SEC;
}

// -------------------------------------------------------------------------- //

int main() {

  int nVert; cin >> nVert;	//nombre total de vertex del graf
  Graph graph(nVert);
  graph.read();

  int nombre_intervals = 20;													//nombre de punts en l'eix X que volem en el grafic (sense incloure q = 1)
  double increment = 1.0 / double(nombre_intervals);
  int nombre_experiments_per_q = 15;									//quants experiments realitzem per una determinada q

  vector <double> temps_vert (nombre_intervals,0);				//en ms
  vector <double> temps_edge (nombre_intervals,0);

  vector <double> propietat_vert (nombre_intervals,0);		//propietat[4] guarda la mitjana dels experiments amb q = (4 * increment), com que la propietat es cert/fals la mitjana pertany a [0,1]
  vector <double> propietat_edge (nombre_intervals,0);		//la propietat quan q = 1 no ens interessa quan mirem connectivitat perque una percolacio amb q = 1 es un graf sense arestes <-justificacio nombre elements dels vectors
  
  int id_interval = 0;
  clock_t inici;
  for (double q = 0; q < 1; q += 0.1) {
    for (int i = 0; i < nombre_experiments_per_q; ++i){
    	Graph graf_aux = percolateVert(graph, q);
    	//mesurem temps de trobar connexio en graf percolat per VERTEX
    	inici = clock();
    	bool esConnex = connectaGraella (graf_aux, int(sqrt(nVert)) );
    	if (esConnex)	propietat_vert[id_interval] += 1.0; 
    	temps_vert[id_interval] += calcula_temps(inici, clock());
    	//********************************
    	graf_aux = percolateEdge(graph, q);
			//mesurem temps de trobar connexio em graf percolat per EDGES
    	inici = clock();
    	esConnex = connectaGraella (graf_aux, int(sqrt(nVert)) );
    	if (esConnex)	propietat_edge[id_interval] += 1.0; 
    	temps_edge[id_interval] += calcula_temps(inici, clock());
			//********************************
    }
    id_interval++;
  }
  //fem la mitjana per cada q
  for (int i = 0; i < nombre_intervals; ++i){
  	temps_vert[i] /= nombre_experiments_per_q;
  	temps_edge[i] /= nombre_experiments_per_q;
  	propietat_vert[i] /= nombre_experiments_per_q;
  	propietat_edge[i] /= nombre_experiments_per_q;
  }
}
