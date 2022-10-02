// Solución al Problema de la Mochila

 

#include <iostream>

#include <vector>

#include <algorithm>

#include <cmath>

#include <queue>


using namespace std;


#define MAXOBJ 11
#define MAXMOCH 101

 
struct obj{
    int valor, peso;
    float valpeso;

};

// Mochila con Programacion Finamica
//Complejidad: O(PN)
int mochDP(vector<obj> &datos, int N, int PESO, int &cantDP){
    int mat[MAXOBJ][MAXMOCH];
    for(int i=0; i < MAXOBJ; i++){
        mat[i][0] = 0;
    }
    for(int j =0; j < MAXMOCH; j++){
        mat[0][j] = 0;
    }
    for(int i=1; i <= N; i++){
        for(int j = 1; j <= PESO; j++){
            cantDP++;
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


// Mochila con Divide y Venceras
// Complejidad: O(2^N)
int mochDyV(vector<obj> &datos, int N, int PESO, int &cantDyV){
    cantDyV++;
    if(N== 0 || datos[N-1].peso > PESO){
        return 0;
    }
    return max(mochDyV(datos, N-1, PESO, cantDyV),   //no incuir al obj N
            datos[N-1].valor + mochDyV(datos, N-1, PESO-datos[N-1].peso, cantDyV  ));
}

 int main(){
    //N 0 canitdadde Obj
    //PESO = Peso que soporta la mochila
    int v, p, N, PESO;
    int cantDP = 0; 
    int cantDyV = 0;
    float vp;
    cin >> N >> PESO;
    vector<obj> datos(N);
    for(int i =0; i<N; i++){
        cin >> v >> p;
        vp = v*1.0/p;
        datos[i].valor = v;
        datos[i].peso = p;
        datos[i].valpeso = vp;
    }
    cout << "--------------------------------------------------------" << endl;
    cout << "La mochila con DyV es: " << mochDyV(datos, N, PESO, cantDyV) << " con operaciones " << cantDyV << endl;
    cout << "La mochila con DP  es: " << mochDP(datos, N, PESO, cantDP) << " con operaciones " << cantDP << endl;
 }

 

 

/*
4 16
10 5
40 2
50 10
30 5

3 30
50 5
60 10
140 20
 
6 89
64 26
85 22
52 4
99 18
39 13
54 9
*/