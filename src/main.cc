#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "graph.hh"
using namespace std;

// ========================================================================== //

Graph percolateVert(const Graph& graph, float q)  {
	return graph.percolateVertices(q);
}

Graph percolateEdge(Graph& graph, float q)  {
	return graph.percolateEdges(q);
}

bool connectaGraella(const Graph& graph, int N){
	list <int> entrada;
	for (int i = 0; i < N; ++i) entrada.push_back(i);
	list <int> sortida;
	for (int i = N*N - N; i < N*N; ++i ) sortida.push_back(i);
	return graph.checkConnected(entrada, sortida);
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

  vector <double> n_edge_vert (nombre_intervals,0);   //n edges percolacio per vertex
  vector <double> n_edge_edge (nombre_intervals,0);   //n edges percolacio per edges

  vector <double> propietat_vert (nombre_intervals,0);		//propietat[4] guarda la mitjana dels experiments amb q = (4 * increment), com que la propietat es cert/fals la mitjana pertany a [0,1]
  vector <double> propietat_edge (nombre_intervals,0);		//la propietat quan q = 1 no ens interessa quan mirem connectivitat perque una percolacio amb q = 1 es un graf sense arestes <-justificacio nombre elements dels vectors

  int id_interval = 0;
  clock_t inici;
  for (double q = 0; q < 1; q += increment) {
    for (int i = 0; i < nombre_experiments_per_q; ++i){
    	bool esConnex;
      Graph graf_aux;




      //PERCOLACIO PER VERTICES
      graf_aux = percolateVert(graph, q);
    	//mesurem temps de trobar connexio en graf percolat per VERTEX
    	inici = clock();
    	esConnex = connectaGraella (graf_aux, int(sqrt(nVert)) );
    	temps_vert[id_interval] += calcula_temps(inici, clock());
      //********************************
      if (esConnex) propietat_vert[id_interval] += 1.0;
      n_edge_vert[id_interval] += double(graf_aux.getNedges());




      //PERCOLACIO PER EDGES
    	graf_aux = percolateEdge(graph, q);
			//mesurem temps de trobar connexio em graf percolat per EDGES
    	inici = clock();
    	esConnex = connectaGraella (graf_aux, int(sqrt(nVert)) );
    	temps_edge[id_interval] += calcula_temps(inici, clock());
			//********************************
      if (esConnex) propietat_edge[id_interval] += 1.0;
      n_edge_edge[id_interval] += double(graf_aux.getNedges());




    }
    id_interval++;
		system("clear");
    cout << id_interval <<"/"<< nombre_intervals << endl;
  }
	system("clear");
  for (int i = 0; i < nombre_intervals; ++i){
  	temps_vert[i] /= nombre_experiments_per_q;
  	temps_edge[i] /= nombre_experiments_per_q;
  	propietat_vert[i] /= nombre_experiments_per_q;
  	propietat_edge[i] /= nombre_experiments_per_q;
    n_edge_vert[i] /= nombre_experiments_per_q;
    n_edge_edge[i] /= nombre_experiments_per_q;
  }
  for (int i = 0; i < nombre_intervals; ++i){
  	cout << i*increment <<" "<< propietat_vert[i] << " ";
		cout << temps_vert[i] <<" "<< n_edge_vert[i] + nVert;

    cout << " || ";

    cout << i*increment <<" "<< propietat_vert[i] << " ";
    cout << temps_edge[i] <<" "<<n_edge_edge[i] + nVert << endl;
  }
}
