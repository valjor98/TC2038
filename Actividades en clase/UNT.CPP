//pattern matching problem
// bacacabcaca
// aca

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> z_function(string texto){
    int n = texto.size();
    vector<int> z(n, 0);
    // segmento [l, r]
    for (int i = 1, l = 0, r = 0; i < n; i++){
        cout << i << ": " << z[i] << " ";
        if (i <= r){ // la pos actual esta dentro de segmento [l, r]
            z[i] = min(r-i+1, z[i-1]);
        }
        cout << z[i] << " ";
        // voy actualizando z[i] hacia adelante
        while(i+z[i] < n && texto[z[i]] == texto[i+z[i]]){
            z[i]++;
        }
        cout << z[i] << endl;
        if (i + z[i] - 1 > r){
            l = i;
            r = i + z[i] - 1;
        }
    }
}


//Complejidad: O(n+m)
vector<int> pmp(string texto, string patron){
    string general = patron + "$" + texto;
    vector<int> zf = z_function(general);
    vector<int> salida;
    for(int i = 0; i < zf.size(); i++){
        if(zf[i] == patron.size()){
            salida.push_back(i - patron.size() - 1);
        }
    }
    return salida;
}

int main(){
    string texto, patron;
    cin >> texto >> patron;
    vector<int> pos = pmp(texto, patron);
    if(pos.size() == 0){
        cout << "No hay coincidencias" << endl;
    }
    else{
        for(int i = 0; i< pos.size(); i++){
            cout << pos[i] << " ";
        }
        cout << endl;
    }
}