#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10

// Complejidad:
int solve(int n){
    int mat[MAX][MAX];
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i ; j++){
            cin >> mat[i][j];
        }
    }
    for(int i = n-2; i>=0; i--){
        for(int j=0; i <= i; j++){
            mat[i][j] += max(mat[i+1][j], mat[i+1][j+1]);
        }
    }
    return mat[0][0];
}

 int main(){
    int t, n;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n;
        cout << solve(n) << endl;
    }
 }