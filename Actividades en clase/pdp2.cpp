#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 50

int solve(int n, int m){
    int mat[MAX][MAX] = {0};
    mat[0][0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m ; j++){
            if (i +2 < n && j+1 < m){
                mat[i+2][j+1] += mat[i][j];
            }
            if (i+1 < n && j+2 < m){
                mat[i+1][j+2] += mat[i][j];
            }
        }
    }
    return mat[n-1][m-1];
}

int main(){
    int n, m;
    cin >> n >> m;
    cout << solve(n, m) << endl;

}