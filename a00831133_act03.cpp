#include <iostream>
#include <vector>
using namespace std;


string findPoints(vector<int>& prices){
    int minprice = INT_MAX;
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
        }
    }
    return "Buy in " + to_string(indexMin) + ", sell in " + to_string(indexMax);
}


int main(){
    vector<string> resultados;
    int m, n, x;
    cin >> m;
    while(m--){
        vector<int> elementos;
        cin >> n;
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