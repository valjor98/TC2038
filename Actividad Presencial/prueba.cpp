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
	//int ptrL = 0;
	int ptrR = d.size();
    cout << "left:" << 0 << "   right: " << ptrR << endl;
    int auxIndex2;
	int auxIndex = ptrR;
	int numTurnos = 0;
    int seguir = 1;

	while(numTurnos < 10){
		auxIndex2 = maxValue(d, auxIndex-1);
        auxIndex = auxIndex2;
		ptrR = auxIndex;
		numTurnos++;
        cout << "turnos " << numTurnos << endl;
        cout << "left:" << 0 << "   right: " << ptrR << endl;
		if(ptrR == 0){
			seguir = 0;
		}
	}
    //cout<<"uwu"<<endl;
	if(numTurnos % 2 == 0){
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