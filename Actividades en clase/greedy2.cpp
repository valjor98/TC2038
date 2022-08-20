#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;


bool solve(string st,  int n){
    vector<int> Ts, Ms;
    for(int i = 0; i<n; i++){
        if(st[i] == 'T'){
            Ts.push_back(i);
        }
        else{
            Ms.push_back(i);
        }
    }
    if(Ts.size() != Ms.size()*2){
        return false;
    }
    for(int i=0; i < Ms.size(); i++){
        if(Ts[i] > Ms[i] || Ts[Ms.size() + 1] < Ms[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int t, n;
    string st;
    cin >> t;
    for(int i = 0; i<t; i++){
        cin >> n;
        cin >> st;
        cout << (solve(st, n) ? "YES" : "NO") << endl;
    }
}