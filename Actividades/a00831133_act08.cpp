#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<bitset>
#include<algorithm>
#include<functional>
#include<deque>
// C
#include<cstdio>
#include<cstring>
#include<ctime>
#include<cctype>
#include<cmath>
// namespace
using namespace std;
// typedef
typedef long long lli;
typedef unsigned long long ull;
// const variable
#define MAX_N 105
#define MAX_M 1000
#define INF 1e9
#define NONE -1
#define MAX(x, y, z) {	return max(max(x,y),z);	}
#define MIN(x, y, z) {	return min(min(x,y),z);	}
#define EPS 1e-6
const double PI = 2.0 * acos(0.0);
const int mx[] = { 0, 1, 0, -1 };
const int my[] = { -1, 0, 1, 0 };
// main
int W[MAX_N][MAX_N];
int main(){
	int C, S, Q, c = 1;
	while (scanf("%d%d%d", &C, &S, &Q) == 3){
		if (C == 0 && S == 0 && Q == 0){
			break;
            }
		if (c > 1)	putchar('\n');
		for (int i = 0; i < MAX_N; i++){
			for (int j = 0; j < MAX_N; j++){
				W[i][j] = INF;
            }
        }
		for (int i = 0; i < S; i++){
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			W[a][b] = W[b][a] = w;
		}
		for (int k = 1; k <= C; k++){
			for (int i = 1; i <= C; i++){
				for (int j = 1; j <= C; j++){
                    W[i][j] = min(W[i][j], max(W[i][k], W[k][j]));
                }
            }
        }
					
		printf("Case #%d\n", c++);
		for (int i = 0; i < Q; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			if (W[a][b] == INF){
				puts("no path");
            }
			else{
				printf("%d\n", W[a][b]);
            }
		}
	}
	return 0;
}