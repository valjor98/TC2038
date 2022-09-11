// Jorge Valdivia A00831133
#include <iostream>
#include <vector>


using namespace std;

vector<string> resultados;

int subsequence(char *cUno, char *cDos, int m, int n){
    int MatA [m+1][n+1];
    
    for (int iR = 0; iR <= m; iR++){
        for (int iA = 0; iA <= n; iA++){
            if (iR == 0 || iA == 0){
                MatA[iR][iA] = 0;
            }
            else if (cUno[iR-1] == cDos[iA-1]){
                MatA[iR][iA] = MatA[iR-1][iA-1] + 1;
            }
            else{
                MatA[iR][iA] = ((MatA[iR-1][iA] > MatA[iR][iA-1]) ? MatA[iR-1][iA]: MatA[iR][iA-1]);
            }
        }
    }
    return MatA[m][n];
}

int main(){
    int numCasos = 0;
    int lineatam = 0, linea2tam =0;
    int iN = 0;
    string Linea = " ";
    string Linea2 = " ";
    char cUno [1000];
    char cDos [1000];
    
    cin >> numCasos;
    
    while (numCasos > iN){
        cin>> Linea;
        lineatam = Linea.length();
        
        for (int iR = 0; iR < lineatam; iR++){
            cUno[iR] = Linea[iR];
        }
        
        cin>>Linea2;
        linea2tam = Linea2.length();
        
        for (int iA = 0; iA < linea2tam; iA++){
            cDos[iA] = Linea2[iA];
        }
        string resul = "Case " + to_string(iN+1) + ": " +to_string(subsequence(cUno, cDos, lineatam, linea2tam)) ;
        resultados.push_back(resul);
        iN++;
        lineatam=0;
        linea2tam=0;
    }
    for(int i = 0; i < resultados.size(); i++){
        cout << resultados[i]<< endl;
    }
    return 0;
}