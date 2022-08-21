//Jorge Valdivia Padron
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

float median(float arr[], int n){
    if (n % 2 == 0)
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}

float getMedian(float ar1[], float ar2[], int n){
    if (n <= 0){
        return -1;
    }
    if (n == 1){
        return (ar1[0] + ar2[0]) / 2;
    }
    if (n == 2){
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;
    }
  
    float m1 = median(ar1, n); 
    float m2 = median(ar2, n); 
  
    if (m1 == m2){
        return m1;
    }
    if (m1 < m2){
        if (n % 2 == 0)
            return getMedian(ar1 + n / 2 - 1, ar2, n - n / 2 + 1);
        return getMedian(ar1 + n / 2,  ar2, n - n / 2);
    }
  
    if (n % 2 == 0)
        return getMedian(ar2 + n / 2 - 1, ar1, n - n / 2 + 1);
    return getMedian(ar2 + n / 2, ar1, n - n / 2);
}

  

int main(){
    vector<float> resultados;
    int m, n, x;
    cin >> m;
    while(m--){
        cin >> n;
        float ar1[n], ar2[n];
        for(int i = 0; i < n; i++){
            cin >> x;
            ar1[i] = x;
        }
        for(int i = 0; i < n; i++){
            cin >> x;
            ar2[i] = x;
        }
        resultados.push_back(  getMedian(ar1, ar2, n) );
    }

    for(int i = 0; i < resultados.size(); i++){
        cout << "Median case " << i+1 << ": " << setprecision(2) << fixed << resultados[i] << endl;
    }
    return 0;
}