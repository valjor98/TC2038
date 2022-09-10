//#include <iostream>
#include <stdio.h>
//#include <algorithm>
#include <vector>
#include <string>

//using namespace std;

int road1[1005],road2[1005],road[2005];
int log[1005][1005];
int n,m;
int find;
int t;
vector<string> resultados;

using namespace std;

int In_Road(int r1,int r2,int r){
	if(n+m==r){
		find=1;
		return 1;
	}
	if(log[r1][r2]==1)
		return 0;
	if(r1<n&&road1[r1]==road[r])
		In_Road(r1+1,r2,r+1);
	if(r2<m&&road2[r2]==road[r])
		In_Road(r1,r2+1,r+1);
	log[r1][r2] = 1;
}

int main(){
	int i,j;
	while( scanf("%d%d",&n,&m) ) {
		if(n==0 && m==0){
            break;
        }
		for(i=0; i<n; i++){
            scanf("%d",&road1[i]);
        }
		for(i=0; i<m; i++){
            scanf("%d",&road2[i]);
        }
		for(i=0; i<n+m; i++){
            scanf("%d",&road[i]);
        }

		find=0;

		for (i=0; i<=n; i++){
			for (j=0; j<=m; j++){
				log[i][j]=0;
			}
		}

		In_Road(0,0,0);
        if(find==1){
            resultados.push_back("possible");
        }
        else {
            resultados.push_back("not possible");
        }                 
	}

    for(int i = 0; i < resultados.size(); i++){
        printf("%s\n", resultados[i].c_str());
    }

	return 0;
}