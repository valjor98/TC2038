// Jorge Valdivia A00831133
#include <iostream>
#include <climits>
#include <queue>

#define MAX 21

using namespace std;

struct Nodo{
	int nivel; 			    // Nivel del Nodo
	int costoAcum;	  	// Costo Real Acumulado hasta ese nodo
	int costoPos;		     // Costo Posible por esa trayectoria
	int verticeAnterior;
	int verticeActual;
	bool visitados[MAX] = { false };
	bool operator<(const Nodo &otro) const{	  // Para que la fila priorizada tenga priodad
		return costoPos > otro.costoPos;	      // Costo Posible menor.
	}
};


void calculaCostoPosible(Nodo &nodoActual, int matAdj[MAX][MAX], int n){
	nodoActual.costoPos = nodoActual.costoAcum;
	int costoObtenido;
	for (int i=1; i<=n; i++){
		costoObtenido = INT_MAX;
		// No he visitado al nodo i o es el último que visite,
		if (!nodoActual.visitados[i] || i == nodoActual.verticeActual){
			if (!nodoActual.visitados[i]){ // Al nodo i no lo he visitado
				for (int j=1; j<=n; j++){
					if (i!=j && (!nodoActual.visitados[j] || j == 1)){
						costoObtenido = min(costoObtenido, matAdj[i][j]); 
					}
				}
			}
			else{	// El nodo i es el último visitado
				for (int j=1; j<=n; j++){
					if (!nodoActual.visitados[j]){
						costoObtenido = min(costoObtenido, matAdj[i][j]);
					}
				}
			}
			if (costoObtenido != INT_MAX){
				nodoActual.costoPos += costoObtenido;
			}
			else{
				nodoActual.costoPos = INT_MAX;
			}
		}
	}
}


int tsp(int matAdj[MAX][MAX], int n){
	int costoOptimo = INT_MAX;
	Nodo raiz;
	raiz.nivel = 0;
	raiz.costoAcum = 0;
	raiz.verticeActual = 1;
	raiz.verticeAnterior = 0;
	raiz.visitados[1] = true;
	calculaCostoPosible(raiz, matAdj, n);
	priority_queue<Nodo> pq;
	pq.push(raiz);
	while (!pq.empty()){
		// Sacar de pq;
		Nodo nodoPadre = pq.top();
		if (nodoPadre.costoPos < costoOptimo){    // Ver si el CostoPos < Costo Optimo
			for (int i = 1; i <= n; i++){           // Si si, generar todos los posibles hijos de este nodo
				if (!nodoPadre.visitados[i]){ 
					Nodo nodoHijo;                      // Para cada hijo generar un nuevo nodo, actualizar los datos
					nodoHijo.nivel = nodoPadre.nivel + 1;
					nodoHijo.costoAcum = nodoPadre.costoAcum + matAdj[nodoPadre.verticeActual][i];
					nodoHijo.verticeActual = i;
					nodoHijo.verticeAnterior = nodoPadre.verticeActual;

          int t = sizeof(nodoPadre.visitados) / sizeof(bool);
          for (int i=0; i < t ; i++){
              nodoHijo.visitados[i] = nodoPadre.visitados[i];
          }
					nodoHijo.visitados[i] = true;

					if (nodoHijo.costoAcum < 0){
						nodoHijo.costoAcum = INT_MAX;
					}

					calculaCostoPosible(nodoHijo, matAdj, n);

					if (nodoHijo.costoPos < 0){
						nodoHijo.costoPos = INT_MAX;
					}
					if (nodoHijo.nivel == n - 2 && nodoHijo.costoPos < costoOptimo){  // y cuando el nivel == n-2 calcular el costo real, y si este
						costoOptimo = nodoHijo.costoPos;                                // mejora el costo optimo ==> actualizarlo
					}
          else if(nodoHijo.nivel < n - 2 && nodoHijo.costoPos<costoOptimo){ // Si el nivel < n-2 .... checar si el costo posible es mejor
						pq.push(nodoHijo);                                              // que el costo optimo y lo metes a la pq.
					}
				}
			}
			pq.pop();
		}
    else{
			pq.pop();
		}
  }
	return costoOptimo;
}


void iniciaMat(int matAdj[MAX][MAX]){
	for (int i=0; i<MAX; i++){
		matAdj[i][i] = 0;
		for (int j=i+1; j<MAX; j++){
			matAdj[i][j] = matAdj[j][i] = INT_MAX;
		}
	}
}


void leeArcos(int matAdj[MAX][MAX], int m){
	char a, b; 	// De dónde a dónde en la trayectoria
	int c; 		// Costo de la trayectoria
	for (int i=0; i<m; i++){
		cin >> a >> b >> c;
		matAdj[a-'A'+1][b-'A'+1] = matAdj[b-'A'+1][a-'A'+1] = c;
	}
}

int main(){
	// n = Cantidad de nodos
	// m = Cantidad de arcos
	int n, m;
	cin >> n >> m;
	int matAdj[MAX][MAX];
	iniciaMat(matAdj);
	leeArcos(matAdj, m);
	int x = tsp(matAdj, n);
	if (x == INT_MAX){
		cout << "INF" << endl;
	}
  else{
		cout<< x << endl;
	}
	
}