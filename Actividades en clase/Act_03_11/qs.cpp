#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> &v){
	for (int i=0; i<v.size(); i++){
		cout << v[i]<<endl;
	}
}

// Regresa el índice de la mediana de ini,mid,fin
int median(vector<int> &v, int ini, int mid, int fin){
	if (v[ini] < v[mid] && v[mid] < v[fin]){
		return mid;
	}
	if (v[ini] < v[fin] && v[fin] < v[mid]){
		return fin;
	}
	return ini;
}

//Particiona con el valor de ini
void part1(vector<int> &v, int ini, int fin, int &piv){
	piv = ini;
	int temp;
	int j = ini; // es el ultimo de los menores
	for(int k = ini+1; k <= fin; k++){
		if(v[k] < v[piv]){
			temp = v[++j];
			v[j] = v[k];
			v[k] = temp;
		}
	}
	piv = j;
	temp = v[ini];
	v[ini] = v[piv];
	v[piv] = temp;
}

// Particiona con el valor fin
void part2(vector<int> &v, int ini, int fin, int &piv){
	piv = ini;
	int temp;
	int j = ini;
	temp = v[ini];
	v[ini]  = v [fin];
	v[fin] = temp;
	for(int k = ini+1; k <= fin; k++){
		if(v[k] < v[piv]){
			temp = v[++j];
			v[j] = v[k];
			v[k] = temp;
		}
	}
	piv = j;
	temp = v[ini];
	v[ini] = v[piv];
	v[piv] = temp;
}

// Particion con la mediana de ini, mid, fin;
void part3(vector<int> &v, int ini, int fin, int &piv){
	int mid = (fin-ini)/2;
	int temp;
	if(ini+1 != fin){
		mid = median(v, ini, mid, fin);
		temp = v[ini];
		v[ini] = v[mid];
		v[mid] = temp;
	}
	piv = ini;
	int j = ini;
	for(int k = ini+1; k <= fin; k++){
		if(v[k] < v[piv]){
			temp = v[++j];
			v[j] = v[k];
			v[k] = temp;
		}
	}
	piv = j;
	temp = v[ini];
	v[ini] = v[piv];
	v[piv] = temp;
}


void quicksort(vector<int> &v, int ini, int fin, long long &cont, int tipo){
	if(ini < fin){
		int piv;
		cont += (fin-ini);
		switch (tipo){
			case 1 : part1(v, ini, fin, piv);
				break;
			case 2 : part2(v, ini, fin, piv);
				break;
			case 3 : part3(v, ini, fin, piv);
				break;
		}
		quicksort(v, ini, piv-1, cont, tipo);
		quicksort(v, piv+1, fin, cont, tipo);
	}
}

int main(){
	// v1 ==> el pivote como valor de inicio
	// v2 ==> el pivote como valor de fin
	// v3 ==> el pivote como la mediana de ini, fin y medio
	vector<int> v1, v2, v3, v4;
	int dato;
	long long cont;
	while (cin>>dato){
		v1.push_back(dato);
		v2.push_back(dato);
		v3.push_back(dato);
	}
	cont = 0;
	quicksort(v1, 0, v1.size()-1, cont, 1); // Con elemPivote en Inicio
//	print(v1);
	cout << "Salida1: " <<cont<<endl;
	cont = 0;
	quicksort(v2, 0, v2.size()-1, cont, 2); // Con elemPivore al Final
//	print(v2);
	cout << "Salida2: " <<cont<<endl;
	cont = 0;
	quicksort(v3, 0, v3.size()-1, cont, 3); // Con elemPivote de la Mediana: ini-mid-fin
//	print(v3);
	cout << "Salida3: " <<cont<<endl;

}


/*

Salida1: 162085

Salida2: 164123

Salida3: 138382



*/
