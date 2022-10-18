// A00831133 Jorge Valdivia
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

long long maxF = 1e18;

// Esta estrcutura representa un Nodo
struct Edge{
    int v;                  // vertex
    long long flow;       // flujo 
    long long C;          // capacidad
    int rev ; 
};
 
// Estrctura del grafo
class Graph{
    int V;                  // numero de vertex
    int *level ;            // nivel donde se encuentra el nodo
    vector< Edge > *adj;
public :
    Graph(int V){
        adj = new vector<Edge>[V];
        this->V = V;
        level = new int[V];
    }
    // metodo para agregar un vertice
    void addEdge(int u, int v, long long C){
        int tam = adj[v].size();
        Edge a{v, 0, C, tam};   // primer nodo, con capacidad C
        tam = adj[u].size();
        Edge b{u, 0, 0, tam};   // segundo nodo al que se conecta
        adj[u].push_back(a);
        adj[v].push_back(b); // reverse edge
    }
    bool BFS(int s, int t);
    long long sendFlow(int s, long long flow, int t, int ptr[]);
    long long DinicMaxflow(int s, int t);
};
 
// Asignar los niveles dentro de el grafo
// Determina si puede haber flujo entre nodo s y nodo t
bool Graph::BFS(int s, int t){
    for (int i = 0 ; i < V ; i++)
        level[i] = -1;
    level[s] = 0;    // estipulamos el nivel del nodo s
    queue< int > q; // creamos una lista
    q.push(s);
 
    vector<Edge>::iterator i ;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (i = adj[u].begin(); i != adj[u].end(); i++){
            Edge &e = *i;
            if (level[e.v] < 0  && e.flow < e.C){

                level[e.v] = level[u] + 1; // se asigna el nivel del nodo actual, +1 al del nodo padre
                q.push(e.v);
            }
        }
    }
    return level[t] < 0 ? false : true ; //si no podemos llegar al punto entonces regresamos false, si no true
}

long long Graph::sendFlow(int u, long long flow, int t, int start[]){
    // Se llego al nodo t
    if (u == t){
        return flow;
    }
    for (  ; start[u] < adj[u].size(); start[u]++){ // checa todos los vertices adyacentes
        Edge &e = adj[u][start[u]];                 // selecciona el siguiente vertice adyacente                         
        if (level[e.v] == level[u]+1 && e.flow < e.C){
            long long curr_flow = min(flow, e.C - e.flow);            // encuentra el flujo minimo de u a t
            long long temp_flow = sendFlow(e.v, curr_flow, t, start);
            if (temp_flow > 0){             // si el flujo es mayor que cero, agrega el flujo al vertice actual 
                e.flow += temp_flow; 
                adj[e.v][e.rev].flow -= temp_flow;
                return temp_flow;
            }
        }
    }
    return 0;
}

// Complejidad O(EV^2)
// encunetra el flujo maximo dentro de un grafo
long long Graph::DinicMaxflow(int s, int t){
    // Corner case
    if (s == t)
        return -1;
 
    long long total = 0;   
    // mientas aun exista un camino de nodo s a nodo t
    while (BFS(s, t)){
        //almacena la cantidad de vertices visitadas
        int *start = new int[V+1] {0};
        while (long long flow = sendFlow(s, maxF, t, start)){  // manda el flujo
            total += flow;
        }
    }
    return total; // regresa el flujo maximo posible
}

// 
int main(){
    int n, m, s, t, a, b;
    long long c;
    // n = cantidad de nodos (vetex)
    // m = cantidad de arcos (edges)
    // s = tu nodo de salida (source)
    // t = tu nodo de llegada (target)
    cin >> n >> m;
    s = 1;
    t = n;
    Graph g(n);
    // se crea el grafo y sus nodos
    for (int i=0; i<m; i++){
        cin >> a >> b >> c;
        g.addEdge(a-1, b-1, c);
    }
    cout << "The maximum speed is " << g.DinicMaxflow(s-1, t-1) << "." << endl;
    return 0;
}
/*
4 5
1 2 3
2 4 2
1 3 4
3 4 5
4 1 3

7 11
1 2 10
1 3 15
1 4 20
2 3  5
2 5 10
3 4 10
3 5 12
4 5 10
4 6 10
5 7 50
6 7 10

7 11
1 2 2
1 3 4
1 4 6
2 3 2
2 5 6
3 4 1
3 5 3
4 5 2
4 6 3
5 7 5
6 7 4

*/