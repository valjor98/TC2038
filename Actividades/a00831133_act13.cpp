// Jorge Valdivia A00831133
#include <iostream>
#include <climits>
#include <vector>


using namespace std;

#define MAX 51
void inicMat(int D[MAX][MAX], int P[MAX][MAX]){
	for (int i=0; i<MAX; i++){
		for (int j=0; j<MAX; j++){
			D[i][j] = P[i][j] = 0;
		}
	}
}

void lee(int d[MAX], int &n, int &m){
	cin >> n; 	// 4
	d[0] = 0;	// 0	4 	5 	7 	8 	10
	for (int i=1; i<=n; i++){
		cin >> d[i];
	}
	d[n+1] = m;
}

// Complejidad: O(n^3)
void calcula(int D[MAX][MAX], int P[MAX][MAX], int d[MAX], int n){
	n++;
	for (int i=1; i<=n; i++){
		D[i][i] = 0;
	}
	for (int diag=1; diag<n; diag++){
		for (int i=1; i<=n-diag; i++){
			int j = i+diag;
			int min = INT_MAX, mink;
			for (int k=i; k<j; k++){
				int multEsc = D[i][k]+D[k+1][j] + (d[j] - d[i-1]);
				//int multEsc = D[i][k]+D[k+1][j]+d[i-1]*d[k]*d[j];
				if (multEsc < min){
					min = multEsc;
					mink = k;
				}
			}
			D[i][j] = min;
			P[i][j] = mink;
		}
	}
}

void recorre(int P[MAX][MAX], int ini, int fin){
	if (P[ini][fin] != 0){
		cout << "(";
		recorre(P, ini, P[ini][fin]);
		cout << ")x(";
		recorre(P, P[ini][fin]+1, fin);
		cout << ")";	
	}
	else{
		char ch = 'A'+ini-1;
		cout << ch;
	}
}

void despliega(int P[MAX][MAX], int n){
	recorre(P, 1, n);
	cout << endl;
}

void despM(int D[MAX][MAX], int P[MAX][MAX], int n){
	n++;
	cout << "-------------" << endl;
	for(int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cout << D[i][j] << "\t";
		}
		cout << endl;
	}
	cout << "-------------" << endl;
	for(int i=1; i<=n; i++){
		for (int j=1; j<=n; j++){
			cout << P[i][j] << "\t";
		}
		cout << endl;
	}
}


int main(){
	vector<string> resultados;
	int m;
	cin >> m;
	while(m != 0){
		int d[MAX]; // Las dimenciones de las matrices
		// D guarda las múltipicaciones minimas escalares desde la matriz i hasta la matriz j
		// P guarda la k que minimiza las MEM Mi...Mj
		int D[MAX][MAX], P[MAX][MAX];
		int n;
		inicMat(D,P); 	// Inicializar con 0's las matrices
		lee(d, n, m);		// Leer la n y las dimenciones de las matrices
		calcula(D, P, d, n);	// Calcular las matrices D y P
		string z = "The minimum cutting is " + to_string(D[1][n+1]) + ".";
		resultados.push_back(z);
		//despliega(P, n);		// Desplegar la asociatividad
		//despM(D,P,n);			// Deplegar matrices D y P
		cin >> m;
	}
	for(auto r:resultados){
		cout << r << endl;
	}
}