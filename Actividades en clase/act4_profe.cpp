//Jorge Valdivia Padron
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

pair<int, int> solve(vector<int> &prices, int ini, int fin){
    if(ini == fin){
        pair<int, int> salida;
        salida.first = ini;
        salida.second = ini;
        return salida;
    }
    else{
        int mit = (ini + fin)/ 2;
        pair<int, int> izq = solve(prices, ini, mit);
        pair<int, int> der = solve(prices, mit+1, fin);
        pair<int, int> mix;
        mix.first = ini;
        for(int i = ini +1; i <= mit; i++){
            if(prices[mix.first] > prices[i]){
                mix.first = i;
            }
        }
        mix.second = mit + 1;
        for(int i = mit +1; i <= fin; i++){
            if(prices[mix.second] < prices[i]){
                mix.second = i;
            }
        }
        int proIzq = prices[izq.second] - prices[izq.first];
        int proDer = prices[der.second] - prices[der.first];
        int proMix = prices[mix.second] - prices[mix.first];
        if(proIzq > proDer && proIzq > proMix){
            return izq;
        }
        if(proDer > proMix){
            return der;
        }
        return mix;
    }
}

int main(){
    int t, n, dato;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> prices(n);
        for(int j = 0; j<n; j++){
            cin >> prices[j];
        }
    }
}