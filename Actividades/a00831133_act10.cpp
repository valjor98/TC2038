#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

#define MAXOBJ 1005
#define MAXMOCH 1005

vector<int> resultados;
 
struct obj{
    int valor, peso;
    float valpeso;
};

// Mochila con Programacion Finamica
//Complejidad: O(PN)
int mochDP(vector<obj> &datos, int N, int PESO){
    int mat[MAXOBJ][MAXMOCH];
    for(int i=0; i < MAXOBJ; i++){
        mat[i][0] = 0;
    }
    for(int j =0; j < MAXMOCH; j++){
        mat[0][j] = 0;
    }
    for(int i=1; i <= N; i++){
        for(int j = 1; j <= PESO; j++){
            if(datos[i-1].peso > j){
                mat[i][j] = mat[i-1][j];    // No sabe el obj - i
            }
            else{
                mat[i][j] = max(mat[i-1][j],
                            datos[i-1].valor + mat[i-1] [j- datos[i-1].peso] );
            }
        }
    }
    return mat[N][PESO];
}


 int main(){
    //N 0 canitdadde Obj
    //PESO = Peso que soporta la mochila
    int T;
    cin >> T;
    for(int i = 0; i < T; T--){
        int v, p, N, G, g, x;
        float vp;
        int sumatoria = 0;
        cin >> N;
        vector<obj> datos(N);
        for(int i =0; i < N; i++){
            cin >> v >> p;
            vp = v*1.0/p;
            datos[i].valor = v;
            datos[i].peso = p;
            datos[i].valpeso = vp;
        }
        cin >> G;
        vector<int> PESO;
        for(int i = 0; i < G; i++){
            cin >> g;
            PESO.push_back(g);
        }
        for(int i = 0; i < G; i++){
            x = mochDP(datos, N, PESO[i]);
            sumatoria = x + sumatoria;
        }
        resultados.push_back(sumatoria);
    }
    for(int i = 0; i < resultados.size(); i++){
        cout << resultados[i] << endl;
    }
 }