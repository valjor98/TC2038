/*
  Matricula: A00831133
  Nombre: Jorge Valdivia
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int maxValue(vector<int> &vec, int vec_size){
    int val_max = vec[0];
    int ind_max = 0;

    for(int i = 0; i < vec_size; ++i)
    {
        if(val_max < vec[i]){
            val_max = vec[i];
            ind_max = i;
        }
    }
    return ind_max;
}

// Complejidad:
string juego(vector<int> &d){
  // Aquí va tu código.

    bool bandera = true;
    int indexGreatest = d.size();
    int indexGreatestAux;
    int numTurnos = 0;
    while(bandera){
        indexGreatestAux = maxValue(d, indexGreatest);
        indexGreatest = indexGreatestAux;
        numTurnos++;
        if(indexGreatestAux == 0){
            bandera = false;
        }
    }

    if(numTurnos % 2 == 0){
		return "PEPE";
	}
	else{
		return "BETO";
	}

    //cout<<"uwu"<<endl;
	if(numTurnos % 2 == 0){
		return "PEPE";
	}
	else{
		return "BETO";
	}

//return
}


int main(){
	int n;
	cin >> n;
	vector<int> datos(n);
	for (int i=0; i<n; i++){
		cin>>datos[i];
	}
  cout << juego(datos)<<endl;
}

/*
Ejemplo 1
4
1 2 4 3

Ejemplo 2
4
1 4 3 2

Ejemplo 3
6
8 10 5 12 13 9

*/