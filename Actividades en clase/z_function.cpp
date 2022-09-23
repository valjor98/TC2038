#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Pattern Matching Problem with Z-Function
//bacacabcaca
//aca

vector<int> z_Function(string texto){
	int n=texto.length();
	vector<int> z(n,0);
	// segmento [l,r]
	for (int i=1, l=0, r=0; i<n; i++){
		if (i <= r) { // La pos actual esta dentro de segmento [l,r]
			z[i] = min(r-i+1, z[i-1]);
		}
		while (i+z[i] < n && texto[z[i]] == texto[i+z[i]]){
			z[i]++;
		}
		if (i+z[i]-1 > r){
			l = i;
			r = i+z[i]-1;
		}
	}
	for (int i=0; i<n; i++){
		cout << z[i] << " ";
	}
	cout << endl;
	return z;
}

// Complejidad: O(n+m)
vector<int> PMT(string texto, string patron){
	vector<int> salida;
	string general = patron + "$" + texto;
	vector<int> zf = z_Function(general);
	for (int i=0; i<zf.size(); i++){
		if (zf[i] == patron.length()){
			salida.push_back(i);
		}
	}
	return salida;
}

int main(){
	string texto, patron;
	cin >> texto >> patron;
	vector<int> pos = PMT(texto, patron);
	for (int i=0; i<pos.size(); i++){
		cout << pos[i]-patron.length()-1 << " ";
	}
	cout << endl;
}