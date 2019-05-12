#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include "graph.hh"
using namespace std;

const int INTERVALS = 1;
bool ZOOM_VERT = false;	//nomes fer zoom amb percolacio x vertex ??
const int num_ini = 0;	//numerador inici
const int den_ini = 39;	//denominador inici

const int num_fi = 30;	//numerador fi
const int den_fi = 39;	//denominador fi

const int EXPERIMENTS = 5;
int num_ret;
int den_ret;

// ========================================================================== //
void suma (int num_A, int den_A, int num_B, int den_B){
	den_ret = den_A * den_B;
	num_ret = den_B*num_A+den_A*num_B;
}

void mult(int num_A, int den_A, int num_B, int den_B){
	den_ret = den_A * den_B;
	num_ret = num_A * num_B;
}

Graph percolateVert(const Graph& graph, int numerador, int denominador)  {
	return graph.percolateVertices(numerador, denominador);
}

Graph percolateEdge(Graph& graph, int numerador, int denominador)  {
	return graph.percolateEdges(numerador, denominador);
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

  int nombre_intervals = INTERVALS;													//nombre de punts en l'eix X que volem en el grafic inclos q = 0 i 1

  //double increment = 1.0 / double(nombre_intervals);
  int denominador = nombre_intervals - 1;
  int nombre_experiments_per_q = EXPERIMENTS;									//quants experiments realitzem per una determinada q
/*
INTERVALS ==== 3
    INI         FI
  (2/3) + + + (3/3)
  		FI-INI
  (2/3)+(1/3)*(1/4) --> q0
  (2/3)+(1/3)*(2/4)	--> q1
  (2/3)+(1/3)*(3/4) --> q2*/
  suma (-num_ini,den_ini,num_fi,den_fi);	//fraccio increment = fraccio fi - fraccio inici
  int num_inc = num_ret;	//numerador increment
  int den_inc = den_ret;	//denominador increment

  int num_int = 1;	//numerador interval
  int den_int = INTERVALS + 1;	//denominador interval


  vector <double> temps_vert (nombre_intervals,0);				//en ms
  vector <double> temps_edge (nombre_intervals,0);

  vector <double> n_edge_vert (nombre_intervals,0);   //n edges percolacio per vertex
  vector <double> n_edge_edge (nombre_intervals,0);   //n edges percolacio per edges

  vector <double> propietat_vert (nombre_intervals,0);		//propietat[4] guarda la mitjana dels experiments amb q = (4 * increment), com que la propietat es cert/fals la mitjana pertany a [0,1]
  vector <double> propietat_edge (nombre_intervals,0);		//la propietat quan q = 1 no ens interessa quan mirem connectivitat perque una percolacio amb q = 1 es un graf sense arestes <-justificacio nombre elements dels vectors

  vector <double> q (nombre_intervals);

  
  clock_t inici;
  for (int id_interval = 0; id_interval < nombre_intervals; id_interval++) {
  	//cout << num_inc <<"/"<< den_inc << "*" << num_int << "/"<<  den_int<< endl;
  	mult(num_inc,den_inc,num_int, den_int);	//fraccio calculada = fraccio increment * fraccio interval
  	int num_aux,den_aux;
  	num_aux = num_ret;
  	den_aux = den_ret;
  	suma (num_aux, den_aux,num_ini,den_ini);//probabilitat = fraccio inici + fraccio calculada
  	num_aux = num_ret;
  	den_aux = den_ret;
  	q[id_interval] = double (num_aux)/den_aux;	//guardo fraccio probabilitat
  	cout << num_aux <<" / "<< den_aux <<" -> "<<id_interval+1<<"/"<< nombre_intervals << endl;
    for (int i = 0; i < nombre_experiments_per_q; ++i){
    	bool esConnex;
      Graph graf_aux;
      if (ZOOM_VERT){
	      //PERCOLACIO PER VERTICES
	      graf_aux = percolateVert(graph, num_aux, den_aux);
	    	//mesurem temps de trobar connexio en graf percolat per VERTEX
	    	inici = clock();
	    	esConnex = connectaGraella (graf_aux, int(sqrt(nVert)) );
	    	temps_vert[id_interval] += calcula_temps(inici, clock());
	      //********************************
	      if (esConnex) propietat_vert[id_interval] += 1.0;
	      n_edge_vert[id_interval] += double(graf_aux.getNedges());
		  }else{
	      //PERCOLACIO PER EDGES
	    	graf_aux = percolateEdge(graph, num_aux, den_aux);
				//mesurem temps de trobar connexio em graf percolat per EDGES
	    	inici = clock();
	    	esConnex = connectaGraella (graf_aux, int(sqrt(nVert)) );
	    	temps_edge[id_interval] += calcula_temps(inici, clock());
				//********************************
	      if (esConnex) propietat_edge[id_interval] += 1.0;
	      n_edge_edge[id_interval] += double(graf_aux.getNedges());
		  }
    }	
    num_int++;
  }

  for (int i = 0; i < nombre_intervals; ++i){
  	temps_vert[i] /= nombre_experiments_per_q;
  	temps_edge[i] /= nombre_experiments_per_q;
  	propietat_vert[i] /= nombre_experiments_per_q;
  	propietat_edge[i] /= nombre_experiments_per_q;
    n_edge_vert[i] /= nombre_experiments_per_q;
    n_edge_edge[i] /= nombre_experiments_per_q;
  }
  for (int i = 0; i < nombre_intervals; ++i){
  	cout <<"# "<< q[i];
  	if (ZOOM_VERT){
	  	cout <<" "<< propietat_vert[i] << " ";
			cout << temps_vert[i] <<" "<< n_edge_vert[i] + nVert << endl;
		}else{
    	cout <<" "<<propietat_edge[i] << " ";
    	cout << temps_edge[i] <<" "<<n_edge_edge[i] + nVert << endl;
    }
  }
}
