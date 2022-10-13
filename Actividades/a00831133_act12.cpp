//Jorge Valdivia A00831133
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <climits>
#include <cmath>
#include <iomanip>
#include <fstream>

using namespace std;

typedef pair<int,int> iPair;

struct Nodo{
    double x, y, num;
    Nodo(){
        this-> num = num;
        this-> x = x;
        this-> y = y;
    }
    Nodo(double x, double y, double num){
        this-> num = num;
        this-> x = x;
        this-> y = y;
    }
};

struct UnionN{
    Nodo nodoA, nodoB;
    double costo;
    UnionN(Nodo nodoA, Nodo nodoB, double costo){
        this-> nodoA = nodoA;
        this-> nodoB = nodoB;
        this-> costo = costo;
    }
};

struct Graph {
	// V = Cantidad de nodos (Vertex)
	// E = Cantidaf de arcos (Edges)
	int V, E;
    double costMSTPrim, costMSTKruskal;
	vector< pair<double, pair<double,double>> > edges; 	// Utilizar en Krukal
	vector< vector< pair<double, double> > > adjList; 	// Se utilza en Prim
	vector< pair<double,double> > selectedEdgesK;		// Los arcos sel Kruskal
	vector< pair<double,double> > selectedEdgesP;		// Los arcos sel Prim;

    

	Graph(int V, int E){
		this->V = V;
		this->E = E;
		adjList.resize(V);
		costMSTKruskal = costMSTPrim = 0;
	}
	// u = salida del arco
	// v = llegada del arco
	// w = costo del arco
	void addEdge(double u, double v, double w){
		edges.push_back({w, {u, v}}); //First = costo, second conexión
		adjList[u].push_back({v, w});
	}

	void load();
	void print();
	void kruskalMST();
	void primMST();
	void printEdgesP();
	void printEdgesK();

    vector<Nodo> receive();
    vector<UnionN> getCost(vector<Nodo> inputsN);
};




// Disjont Sets (Union-Find)
struct DisjointSets{
	int *parent, *rnk;
	int n;
	DisjointSets(int n){
		this->n = n;
		parent = new int[n+1];
		rnk = new int[n+1];
		for (int i=0; i<=n; i++){
			rnk[i] = 0;
			parent[i] = i;
		}
	}
	// Para encontrar el parent de 'u'
	int find(int u){
		if (u != parent[u]){
			parent[u] = find(parent[u]);
		}
		return parent[u];
	}

	// Union por rank
	void merge(int x, int y){
		x = find(x);
		y = find(y);
		if (rnk[x] > rnk[y]){
			parent[y] = x;
		}
		else{
			parent[x] = y;
		}
		if (rnk[x] == rnk[y]){
			rnk[y]++;
		}
	}
};



vector<Nodo> Graph::receive(){
    vector<Nodo> inputsN;
    double x, y;
    for(int i=0; i<V; i++){
        cin >> x >> y;
        Nodo a(x, y, 0);
        a.num = i;
        inputsN.push_back(a);
    }
    return inputsN;
}

vector<UnionN> Graph::getCost(vector<Nodo> vectN){
    vector<UnionN> vectU;
    int counter = 1;
    for(int i=0; i<V; i++){
        for(int j = counter ; j < V; j++){
            double a = vectN[i].x - vectN[j].x;
            double b = vectN[i].y - vectN[j].y;
            double s = sqrt(pow(a, 2) + pow(b, 2));
            UnionN nod(vectN[i], vectN[j], s);
            vectU.push_back(nod);
        }
        counter++;
    }
    return vectU;
}

void Graph::load(){
    double x, y, costo;
    vector<Nodo> vectN = receive(); 
    vector<UnionN> vectU = getCost(vectN); 

	int a, b; 
    double c;
	for (int i=0; i<E; i++){
		a = vectU[i].nodoA.num;
        b = vectU[i].nodoB.num;
        c = vectU[i].costo;
        //cout <<"(" << a << "," << b << ") --- " << c << endl;
        //cout <<"(" << vectU[i].a.x << "," << vectU[i].a.y << ") - ("<< vectU[i].b.x << "," << vectU[i].b.y << ") --- " << c << endl;

		addEdge(a, b, c);
		addEdge(b, a, c);
	}
}

void Graph::print(){
	cout << "Adjacent List:" << endl;
	for (int i=0; i<V; i++){
		cout << " " << i << ": ";
		for (int j=0; j<adjList[i].size(); j++){
			//cout << "(" << adjList[i][j].first << "," << adjList[i][j].second << ") ";
		}
		cout << endl;
	}
}

// Complejidad: O(V^2)
void Graph::primMST(){
	costMSTPrim = 0;
	double selSource = 0;
	unordered_set<double> selected;
	unordered_set<double> missing;
	selected.insert(0);
	for(int i = 1; i < V; i++){
		missing.insert(i);
	}
	double connected = V-1, minCost, selVertex;
	while(connected){
		minCost = INT_MAX;
		for(auto it1:selected){			// por cada elemento del conj. selected
			for(auto it2:adjList[it1]){
				if(missing.find(it2.first) != missing.end() && it2.second < minCost){
					minCost = it2.second;
					selVertex = it2.first;
					selSource = it1;
				}
			}
		}
		costMSTPrim += minCost;
		selected.insert(selVertex);
		missing.erase(selVertex);
		selectedEdgesP.push_back({selSource, selVertex});
		connected--;
	}
}

void Graph::printEdgesP(){
	cout << "Selected Edges Prim: ";
	for (auto it:selectedEdgesP){
		cout << "(" << it.first << "," << it.second << ") ";
	}
	cout << endl;
}


// Complejidad: P(E logE)
void Graph::kruskalMST(){
	sort(edges.begin(), edges.end());
	DisjointSets ds(V);
	costMSTKruskal = 0;
	for (auto it:edges){
		double p1 = ds.find(it.second.first);
		double p2 = ds.find(it.second.second);
		if(p1 !=p2){
			costMSTKruskal += it.first;
			selectedEdgesK.push_back({it.second.first, it.second.second});
			ds.merge(it.second.first, it.second.second);
		}
	}
}

void Graph::printEdgesK(){
	cout << "Selected Edges Kruskal: ";
	for (auto it:selectedEdgesK){
		cout << "(" << it.first << "," << it.second << ") ";
	}
	cout << endl;
}

int main(){
	int V, E;
	cin >> V;
    E = V*(V-1) / 2;
	Graph g(V, E);
	g.load();
	//g.print();
	g.primMST();
	//cout << "El costo total del MST por Prim    es: " << g.costMSTPrim << endl;
	//g.printEdgesP();
	g.kruskalMST();
	//cout << "El costo total del MST por Kruskal es: " << setprecision (3) << g.costMSTKruskal << endl;
    cout << fixed  << setprecision (2) << g.costMSTKruskal << endl;
	//g.printEdgesK();
	return 0;
}
