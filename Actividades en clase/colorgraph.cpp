// algortimo de Welsh Powell
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

#define MAX 100

struct color{
    int conex;  //cant conexiones
    int vtx;    // el numero de vertice
};
// Ordenamiento se adescendente en cant de conexiones y en empate rl menor nombre de vertice
bool my_cmp(const color& a, const color& b){
    if(a.conex == b.conex){
        return a.vtx <= b.vtx;
    }
    return a.conex > b.conex;
}

bool canColor(bool matAdj[MAX][MAX], unordered_set<int> &conj, int j){
    for(auto it:conj){
        if(matAdj[it][j]){
            return false;
        }
    }
    return true;
}

vector<int> colorGraph(bool matAdj[MAX][MAX], vector<color> &vtxColor){
    int colNum = 0;
    int n = vtxColor.size();
    vector<int> colored(n, 0);
    for(int a=0; a < n; a++){
        int i = vtxColor[a].vtx;
        if(!colored[i]){
            colored[i] = ++colNum;
            unordered_set<int> conj;    // todos los vertices coloreados con colNum
            conj.insert(i);
            for(int b=a=1; b<n; b++){
                int j = vtxColor[b].vtx;
                //verificar
                //      el vertice j no ha sido coloreado
                //      el vertice j no tienen adyacencia con i
                //      el vertic ej no tinene adyacencia con algun vertice que fue coloreado
                if(!colored[i] && !matAdj[i][j] && canColor(matAdj, conj, j)){
                    colored[j] = colNum;
                    conj.insert(j);
                }
            }
        }
    }
    return colored;
}

int main(){
    // n = numero de vertices o nodos
    // m = numero de arcos o edges
    int n, m, a, b;
    cin >> n >> m;
    bool matAdj[MAX][MAX];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            matAdj[i][j] = false;
        }
    }
    vector<color> vtxColor;     // vector de grados de los vertices
    color c;
    for(int i =0; i < n; i++){
        c.conex = 0;
        c.vtx = i;
        vtxColor.push_back(c);
    }
    for(int i=0; i<m; i++){
        cin >> a >> b;
        matAdj[a-1][b-1] = matAdj[b-1][a-1] = true;
        vtxColor[a-1].conex++;
        vtxColor[b-1].conex++;
    }
    cout << "-----------------" << endl;
    sort(vtxColor.begin(), vtxColor.end(), my_cmp);
    vector<int> colored = colorGraph(matAdj, vtxColor);
    for( int i = 0; i<n; i++){
        cout << (i-1) << " colored with color " << colored[i] << endl;
    }
}
/* 
7 11
1 2
1 3
1 4
2 3
2 5
3 4
3 5
4 5
4 6
5 7
6 7
 */