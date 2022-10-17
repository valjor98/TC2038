// Dinics Algorithm
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int v;
    int flow;
    int C;
    int rev;
};


class Graph{
    int V;
    int *level;
    vector<Edge> *adj;
public:
    Graph(int V){
        adj = new vector<Edge>[V];
        this->V = V;
        level = new int[V];
    }
    
    void addEdge(int u, int v, int C){
        int tam = adj[v].size();
        Edge a{v, 0, C, tam};
        tam = adj[u].size();
        Edge b{u, 0, 0, tam};
        adj[u].push_back(a);
        adj[v].push_back(b);
    }
    bool BFS(int s, int t);
    int sendFlow(int s, int flow, int t, int ptr[]);
    int DinicMaxFlow(int s, int t);
};

bool Graph::BFS(int s, int t){
    //Corner case
    if(s == t){
        return -1;
    }
    int total = 0;
    while(BFS(s, t) == true){
        int *start = new int[V+1] {0};
        while(int flow = sendFlow(s, INT_MAX, t, start)){
            total += flow;
        }
    }
    return total;
}

int main(){
    int n, m, s, t, a, b, c;
    cin >> n >> m >> s >> t;
    Graph g(n);
    for(int i = 0; i < m; i++){
        cin >> a >> b >> c;
        g.addEdge(a-1, b-1, c);
    }
    cout << "Maximum flow " << g.DinicMaxFlow(s-1, t-1) << endl;
    return 0;
}