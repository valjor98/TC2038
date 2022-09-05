//Algoritmo Knuth-Morris-Pratt (KMP)
// Para encontrar un patron en un texto
#include <iostream>
#include <vector>
#include <string>

using namespace std;

// longest proper prefix which is also a sufix
// compleidad: 
vector<int> lps(string p){
    int n = p.length();
    vector<int> lpsv(n, 0);
    int j=0; 
    int i=1;
    while(i < n){
        if(p[i] == p[j]){
            lpsv[i++] = ++j;
            //lpsv[i] == j+1;
            //i++;
            //j++;
        }
        else{
            if(j==0){
                lpsv[i] = 0;
                i++;
            }
            else{
                j = lpsv[j-1];
            }
        }
    }
    return lpsv;
}


vector<int> kmp(string texto, string patron){
    vector<int> posMatch;
    vector<int> lpsv = lps(patron);
    int j = 0, i = 0;
    int n = texto.length();
    int m = patron.length();
    while(i <n){
        if(texto[i] == texto[j]){
            i++;
            j++;
            if(j== m){
                posMatch.push_back(i-m);
                j = lpsv[j-1];
            }
        }
        else{
            if(j == 0){
                i++;
            }
            else{
                j = lpsv[j-1];
            }
        }
    }
    return posMatch;
}


int main(){
    string texto, patron;
    cin >> texto >> patron;
    vector<int> posMatch = kmp(texto, patron);
    if(posMatch.size() == 0){
        cout << "No match" <<  endl;
    }
    else{
        for(int i =0; i < posMatch.size(); i++){
            cout << posMatch[i] << " ";
        }
        cout << endl;
    }
    return 0;

}