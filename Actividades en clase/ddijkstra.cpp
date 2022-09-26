#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include<utility>

using namespace std;

#define INF INT_MAX
#define Edge pair<int, int> // A donde llego y su costo
#define Graph vector< vector<Edge> > // Grafo rep. en un alista de adjacencia
#define Vertex pair<int, int> //Distancia 

void print(Graph &G){
    for (int i=0; i< G.size(); i++){
        cout<< (i+1) << " ==> " ;
        for(int j = 0; j < G[i].size(); j++){
            cout << "(" <<(G[i][j].first) + 1 << "," <<
                    G[i][j].second << ") ";    
        }
        cout << endl;
    }
}

vector<int> dijkstra(Graph &G, int source){
    vector<int> dist(G.size(), INF);
    dis[source] = 0;
    priority_queue<Vertex, vector<Vertex>, greater<Vertex> queue;
    Vertex vs(0, source);
    queue.push(vs);
    while(!queue.empty()){
        int u = queue.top().second;
        queue.pop()
        for(int i = 0; i < G[u].size(); i++){
            Edge e = G[u][i];
            int v = e.second;
            int w = e.first;
            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                Vertex vtx(dist[v], v);
                queue.push(vtx);
            }
        }
    }
    return dist;
}

int main(){
       int nodes, edges, source, u, v, w;
       cin >> nodes >> edges >> source;
       Graph G(nodes);

       for (int i=0; i<edges; i++){
             cin >> u >> v >> w;
             // Arco de u->v con un costo w
             Edge edge1(v-1, w);
             G[u-1].push_back(edge1);
             // Arco de v->u con un costo w
             Edge edge2(u-1, w);
             G[v-1].push_back(edge2);
       }

       //print(G);

       vector<int> distances = dijkstra(G, source-1);
       cout << "Distancias: " << endl;
       for (int i=0; i<nodes; i++){
             if (i != source-1){
                    cout << source << "-->" << (i+1) << " : ";
                    if (distances[i] == INF){
                           cout << "INF" << endl;
                    }
                    else{
                           cout << distances[i] << endl;
                    }
             }
       }
}

 

// Cantidad de nodos, cantidad de arcos, nodo origen

// arcos punto origen punto destino y costo.

/*
5 8 1
1 2 2
1 3 12
1 4 10
2 3 9
2 5 5
3 4 6
3 5 3
4 5 7
*/