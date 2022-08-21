//Jorge Valdivia Padron
#include <iostream>
#include <vector>
#include <string>
using namespace std;


string findPoints(vector<int>& prices){
    vector<int> mejoresDias, mejoresPrecios;
    int minprice = 1000;
    int indexMin, indexMax;
    int maxprofit = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minprice){
            minprice = prices[i];
            indexMin = i+1;
        }
        else if (prices[i] - minprice > maxprofit){
            indexMax = i+1;
            maxprofit = prices[i] - minprice;
            mejoresPrecios.push_back(minprice);
            mejoresPrecios.push_back(prices[i]);
            mejoresDias.push_back(indexMin);
            mejoresDias.push_back(i+1);
        }
    }
    int mejorComprar, mejorVender;

    for(int i = mejoresPrecios.size(); i --> 0; ){
        if(mejoresPrecios[i] - mejoresPrecios[i-1] == maxprofit){
            mejorComprar = mejoresDias[i-1];
            mejorVender = mejoresDias[i];
        }
        i--;
    }

    return "Buy in " + to_string(mejorComprar) + ", sell in " + to_string(mejorVender);
}


int main(){
    vector<string> resultados;
    int m, n, x;
    cin >> m;
    while(m--){
        vector<int> elementos;
        cin >> n;
        if ((1 < n <= 50) == false) {
            continue;
        }
        for(int i = 0; i < n; i++){
            cin >> x;
            elementos.push_back(x);
        }
        resultados.push_back(findPoints(elementos));
    }
    for(int i = 0; i < resultados.size(); i++){
        cout << resultados[i]<< endl;
    }

    return 0;
}