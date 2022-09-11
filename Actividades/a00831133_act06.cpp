// Jorge Valdivia A00831133
#include <iostream>
#include <string.h>
#include <vector>


using namespace std;

vector<string> resultados;

int Substring (char *cUno, char *cDos, int m, int n){
    int iMatA [m+1][n+1];
    int iMax = 0;
    
    for (int iR = 0; iR <= m; iR++){
        for (int iA = 0; iA <= n; iA++){
            if (iR == 0 || iA == 0){
                iMatA[iR][iA] = 0;
            }
            else if (cUno[iR-1] == cDos[iA-1]){
                
                iMatA[iR][iA] = iMatA[iR-1][iA-1] + 1;
                
                iMax = (iMax > iMatA[iR][iA]) ? iMax : iMatA[iR][iA];
            }
            else{
                 iMatA[iR][iA] = 0;
            }
        }
    }
    return iMax;
}

int main(){
    int iCasos = 0;
    int slineatam = 0, slinea2tam = 0;
    int iN = 0;
    string sLinea = "";
    string sLinea2 = "";
    char cUno [1000];
    char cDos [1000];
    
    cin >> iCasos;
    
    while (iCasos > iN){
        cin >> sLinea;
        slineatam = sLinea.length();
        
        for (int iR = 0; iR < slineatam; iR++){
            cUno[iR] = sLinea[iR];
        }
        
        cin>> sLinea2;
        slinea2tam = sLinea2.length();
        
        for (int iA = 0; iA < slinea2tam; iA++){
            cDos[iA] = sLinea2[iA];
        }
        

        string resul = "Case " + to_string(iN+1) + ": " +to_string(Substring(cUno, cDos, slineatam, slinea2tam)) ;
        resultados.push_back(resul);
        iN++;
    }

    for(int i = 0; i < resultados.size(); i++){
        cout << resultados[i]<< endl;
    }

    
    return 0;
}