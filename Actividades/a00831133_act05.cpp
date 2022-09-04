#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int maxn = 1002;
int aa[maxn], bb[maxn], cc[maxn << 1];
int mat[maxn][maxn];
int n1, n2;
bool flag;
vector<string> resultados;

void dfs(int lena, int lenb, int lenc){
    if(lena == n1+1 && lenb == n2+1){
            flag=1;
        return;
    }
    if(mat[lena][lenb]){
        return; 
    }
    if(!flag && aa[lena] == cc[lenc]){
        mat[lena][lenb] = 1;
        dfs(lena+1, lenb, lenc+1);
    }
    if(!flag && bb[lenb] == cc[lenc]){
        mat[lena][lenb] = 1;
        dfs(lena,lenb+1, lenc+1);
    }
}

void input(int n,int a[]){
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);
    }
    return;
}

int main(){
    while(scanf("%d%d", &n1, &n2) && n1+n2!=0) {
        input(n1, aa);
        aa[n1+1] = -1;
        input(n2, bb);
        bb[n2+1] = -1;
        input(n1+n2, cc);
        flag=0;
        memset(mat, 0, sizeof(mat));
        dfs(1,1,1);
        if(flag){
            resultados.push_back("possible");
        }
        else {
            resultados.push_back("not possible");
        }
    }
    for(int i = 0; i < resultados.size(); i++){
        cout << resultados[i] << endl;
    }
    return 0;
}