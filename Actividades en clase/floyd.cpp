#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

#define MAX 100

void leerArcos(int mat[MAX][MAX], int p[MAX][MAX], int m){
    int a,b,c; //voy de a <->b con costo c
    //iniciar la matrices
    for(int i=0; i<MAX; i++){
        mat[i][i] = 0;
        p[i][i] = -1; // -1 es conexion directa
        for (int j = i+1; j < MAX; j++){
            mat[i][j] = mat[j][i] = INT_MAX; //INT_MAX = inf
            p[i][j] = p[j][i] = -1;
        }
    }
    for(int i = 0; i < m ; i++){
        cin >> a>> b >> c;
        // usuario base1 y yo base 0
        mat[a-1][b-1] = mat[b-1][a-1] = c;
    }
}

void print(int mat[MAX][MAX], int p[MAX][MAX], int n){
    cout << "Matriz de Costos:" << endl;
    for(int i = 0; i < n ; i++){
        for(int j = 0; j < n; j++){
            if(mat[i][j] == INT_MAX){
                cout << "INF\t";
            }
            else{
                cout << mat[i][j] << "\t";
            }
        }
        cout << endl;
    }
    cout << "Matriz de Trayectorias: " << endl;
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            cout << p[i][j] << "\t";
        }
        cout << endl;
    }
}

void floyd(int mat[MAX][MAX], int p[MAX][MAX], int n){
    for(int k = 0; k < n ; k++){
        for(int i = 0; i < n; i++){
            for(int j =0; j < n; j++){
                if(mat[i][k] != INT_MAX && 
                    mat[k][j] != INT_MAX){
                    mat[i][k] + mat[k][i] < mat[k][j];
                }
            }
        }
    }
}
void checaTrayectoria(int p[MAX][MAX], int x, int y){
    if (p[x][y] != 1){
        checaTrayectoria(p, x, p[x][y]);
        cout << (p[x][y] + 1) << "-";
        checaTrayectoria(p, p[x][y], y);
    }
}


void consultas(int mat[MAX][MAX], int p[MAX][MAX], int q){
    int a, b;
    for(int i = 0; i < q; i++){
        cin >> a >> b;
        if(mat[a-1][b-1] == INT_MAX){
            cout << "no path" << endl;
        }
        else{
            cout << "Costo: " << mat[a-1][b-1]
            << " Trayectoria: "<< a << "-";
            checaTrayectoria(p, a-1, b-1);
            cout << b << endl;
        }
    }
}

int main(){

    int mat[MAX][MAX], p [MAX][MAX];
    int t, n, m, q;
    // t = numero de casos
    // n = cantidad de nodos
    // m = cantidad de arcos
    // q = cantidad de consultas
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> m >> q;
        leerArcos(mat, p, n);
        print(mat, p, n);
        // consultas (mat, p, q)
    }
    return 0;

}