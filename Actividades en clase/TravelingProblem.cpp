#include <iostream>
#include <climits>
#include <queue>

#define MAX 21

using namespace std;

struct Nodo{
    int nivel;                // Nivel del Nodo
    int costoAcum;          // Costo Real Acumulado hasta ese nodo
    int costoPos;           // Costo Posible por esa trayectoria
    int verticeAnterior;
    int verticeActual;
    bool visitados[MAX] = {false};
    bool operator<(const Nodo &otro) const{     // Para que la fila priorizada tenga prioridad
        return costoPos >= otro.costoPos;       // Costo Posible menor
    }
};



void iniciaMat(int matAdj[MAX][MAX]){
    for(int i = 0; i<MAX; i++){
        matAdj[i][i] = 0;
        for(int j = i + 1; i < MAX; j++){
            matAdj[i][j] = matAdj[j][i] = INT_MAX;
        }
    }
}

void calculaCostoPosible(Nodo nodoActual, int matAdj[MAX][MAX], int n){
    nodoActual.costoPos = nodoActual.costoAcum;
    int costoObtenido;
    for(int i = 1; i <= n; i++){
        costoObtenido = INT_MAX;
        if(!nodoActual.visitados[i] || i == nodoActual.verticeActual){
            if(!nodoActual.visitados[i]){
                for(int j=1; j <= n ; j++){
                    if(i != j && (!nodoActual.visitados[j] || j == 1)){
                        costoObtenido = min(costoObtenido, matAdj[i][j]);
                    }
                }
            }
            else{
                for(int j = 1; j <= n; j++){
                    if(!nodoActual.visitados[j]){
                        costoObtenido = min(costoObtenido, matAdj[i][j]);
                    }
                }
            }
            nodoActual.costoPos += costoObtenido;
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
    while(!pq.empty()){
        // Sacar de pq
        // Ver si el CostoPos < Costo Optimo
        // Si si, generar todos los posibles hijos de este nodo
        // Para cada hijo generar un nuevo nodo, actualizar los datos
        // y cuando el nivel == n-2 calcular el costo
        // mejora el costo optimo ==> actualizarlo
        // si el nivel < n - 1 ... checar si el costo posible es mejor
		Nodo parent = pq.top();
		if (parent.costoPos < costoOptimo){
			for (int i = 1; i <= n; i++){
				if (!parent.visitados[i]){
					Nodo child;
					child.nivel = parent.nivel + 1;
					child.costoAcum = parent.costoAcum + matAdj[parent.verticeActual][i];
					child.verticeActual = i;
					child.verticeAnterior = parent.verticeActual;
					copy(begin(parent.visitados), end(parent.visitados), begin(child.visitados));
					child.visitados[i] = true;

					if (child.costoAcum<0){
						child.costoAcum = INT_MAX;
					}

					calculaCostoPosible(child, matAdj, n);

					if (child.costoPos<0){
						child.costoPos = INT_MAX;
					}

					if (child.nivel == n-2 && child.costoPos<costoOptimo){
						costoOptimo = child.costoPos;
					}else if(child.nivel < n-2 && child.costoPos<costoOptimo){
						pq.push(child);
					}
				}
			}
			pq.pop();
		}else{
			pq.pop();
		}
    }
    return costoOptimo;
}

void leerArcos(int matAdj[MAX][MAX], int m){
    char a, b;  // De donde a donde en la trayectoria
    int c;      //costo de l atrayectoria
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        matAdj[a-'A'+1][b-'A'+1] = matAdj[b-'A'+1][a-'A'+1] = c;
    }
}

int main(){
    // n = cantidad de nodos
    // m = cantidad de arcos
    int n, m;
    cin >> n >> m;
    int matAdj[MAX][MAX];
    iniciaMat(matAdj);
    leerArcos(matAdj, m);
    cout << tsp(matAdj, n) << endl;
}