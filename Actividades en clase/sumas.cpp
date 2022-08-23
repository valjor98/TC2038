#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
// n = cantidad de objetos
// VALOR = valor a buscar
int n, VALOR;
// obj = vector con los valores de los objetos
vector<int> obj;
// include = vector que me dice si incluyo o no al obj i 
vector<bool> include;

void sum_of_subset(int i, int acum, int total){
    if (acum+total >= VALOR && 
        acum == VALOR || acum+obj[i+1] <= VALOR){
        if(acum == VALOR){
            for( int j = 0; j<n; j++){
                if (include[j]){
                    cout << obj[j] << " ";
                }
            }
            cout << endl;
        }
        else{
            //Si al sig. obj
            include[i+1] = true;
            sum_of_subset(i+1, acum+obj[i+1], total-obj[1]);
            //No al sig. obj
            include[i+1] = false;
            sum_of_subset(i+1, acum, total-obj[i]);
        }
    }
}

int main(){
    cin >> n >> VALOR;
    int dato, total = 0;
    for( int i = 0; i<n; i++){
        cin >> dato;
        obj.push_back(dato);
        total += dato;
        include.push_back(false);
    }
    sort(obj.begin(), obj.end());
    sum_of_subset(-1, 0, total);
}
