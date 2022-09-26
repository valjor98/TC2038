#include <iostream>
#include <climits>

using namespace std;

#define N 22

void InitMat(int Mat[N][N], int n){
  for(int i = 0; i < n; i++){
    Mat[i][i] = 0;
    for(int j = i+1; j < n; j++){
      Mat[i][j] = Mat[j][i] = INT_MAX;
    }
  }
}

void Dijkstra(int W[N][N], int L[N], int v){
	bool encontre[N];
	for (int i=0; i<N; i++){
		encontre[i] = false;
	}
	for (int i=0; i<v; i++){
		L[i] = W[0][i];
	}


	for (int i=1; i<v; i++){
		int min = INT_MAX;
		int imin;
		for (int j=1; j<v; j++){
			if (!encontre[j] && 0 < L[j] && L[j] < min){
				min = L[j];
				imin = j;
			}
		}

		for (int j=1; j<v; j++){
			if (W[imin][j] != INT_MAX && L[imin]+W[imin][j] < L[j]){
				L[j] =  L[imin]+W[imin][j];
			}
		}
		encontre[imin] = true;
	}
}

char Mayor(int L[N], int n){
  int Mayor = L[0]; // yo get the biggest path
  int Pos;
  for(int i = 1; i < n; i++){
    if(Mayor < L[i]){
      Mayor = L[i];
      Pos = i;
    }
  }
  return Pos+'A';
}

int main(){

  int Cases;
  cin >> Cases;
  int nodos, caminos; //numero de cuartos y de caminos
  int Mat[N][N];
  int L[N];
  char X, Y; //rooms
  int C; //metros
  for(int i = 0; i < Cases; i++){ //for the number of cases
    cin >> nodos >> caminos;
    InitMat(Mat, nodos); // to initialize the matrix
    for(int j = 0; j < caminos; j++){
      cin >> X >> Y >> C;
      Mat[X-'A'][Y-'A']= Mat[Y-'A'][X-'A'] = C;
    }

    Dijkstra(Mat, L, nodos);
    cout << "Case "<<i+1<<": " << Mayor(L, nodos) << endl;
  }

  return 0;
}