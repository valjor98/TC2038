#include<iostream> 
#include<cstdio>
#include <cstring>
#include<map>
#define N 200005
using namespace std;
char str[N];
int pos[30], ch[30];

int main(){
    int m;
    scanf("%d%s", &m, str);
    getchar();
    for(int i=0; i<26; ++i)
        pos[i] = ch[i] = i;
    char s[4];
    while(m--){
        gets(s);
        if(s[0] == s[2]) continue;
        swap(ch[pos[s[0]-'a']], ch[pos[s[2]-'a']]);
        swap(pos[s[0]-'a'], pos[s[2]-'a']);
    }
    int n = strlen(str);
    for(int i=0; i< n ; ++i)
        printf("%c", ch[str[i]-'a']+'a');
    printf("\n");
    return 0;
}