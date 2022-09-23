/*
  Matricula: A00831133
  Nombre: Jorge Valdivia
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


// Complejidad:
string juego(vector<int> &d){
  // Aquí va tu código.
	int ptrL = 0;
	int ptrR = d.size() - 1;
	int auxIndex = d[d.size()-1];
	int numTurnos = 0;
	while(1){
		auxIndex = max_element(d[0], d[auxIndex]);
		ptrR = auxIndex;
		numTurnos++;
		if(ptrL == ptrR){
			break;
		}
	}
	if(numTurnos%2 == 0){
		return "PEPE";
	}
	else{
		return "BETO";
	}

//retur
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