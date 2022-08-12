#include <iostream>
#include <vector>
#include <cstdlib> // Random

#define MAX 128
using namespace std;

void genera(int datos[MAX][MAX], int n){
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            datos[i][j] = rand()%1000+1;
        }
    }
}

void print(int datos[MAX][MAX], int n){
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            cout << datos[i][j] << " ";
        }
        cout << endl;
    }
}


//Complejidad: O(n^2)
int cuenta1000Iter(int datos[MAX][MAX], int n){
    int cont = 0;
    for(int i = 0; i<n; i++){
        for(int j=0; j<n; j++){
            if (datos[i][j] > 100){
                cont++;
            }
        }
    }
    return cont;
}

int cuenta100DyV(int datos[MAX][MAX], int ri, int rf, int ci, int cf){
    if(ri==rf && ci==cf){
        return (datos[ri][ci] > 100) ? 1 : 0;
    }
    else{
        int rm = (ri+rf)/2;
        int cm = (ci+cf)/2;
        return  cuenta100DyV(datos, ri, rm, ci, cm) + // Cuadrante 1
                cuenta100DyV(datos, ri, rm, cm+1, cf) + // Cuadrante 2
                cuenta100DyV(datos, rm+1, rf, ci, cm) + // Cuadrante 3
                cuenta100DyV(datos, rm+1, rf, cm+1, cf); // Cuadrante 4

    }
}

int main(){
    int n;
    int datos[MAX][MAX];
    cin >> n;
    genera(datos, n);
    //print(datos, n);
    cout<<"Iterativo: " << cuenta1000Iter(datos, n) << endl;
    cout<<"Div y Ven: " << cuenta100DyV(datos, 0, n-1, 0, n-1) <<  endl;
}