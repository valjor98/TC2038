#include <iostream>
#include <vector>
#include <cstdlib> // Random

using namespace std;

vector<int> genera(int n){
    vector <int> resul;
    for (int i=0; i<n; i++){
        resul.push_back(rand() % 1000+1);
    }
    return resul;
}

void print(vector<int> &datos){
    for(int i = 0; i <datos.size(); i++){
        cout << datos[i] << " ";
    }
    cout << endl;
}

int cuantos100Iter(vector<int> &datos){
    int cont = 0;
    for(int i = 0; i<datos.size(); i++){
        if (datos[i] > 100){
            cont++;
        }
    }
    return cont;
}

//Complejidad O(n)
int cuantos100DyV(vector<int> &datos, int ini, int fin){
    if (ini == fin){
        return (datos[ini] < 100) ? 1 : 0;
    }
    else{
        int mit = (ini+fin)/2;
        return (cuantos100DyV(datos, ini, mit) + cuantos100DyV(datos, mit+1, fin)) ;
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> datos = genera(n) ; 
    //print(datos);
    cout << "iterativa: " << cuantos100Iter(datos) << endl;
    cout << "Div y ven: " << cuantos100DyV(datos, 0, n-1) << endl;
}