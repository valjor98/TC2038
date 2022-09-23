// Algoritmo de Knuth-Morris-Pratt (KMP)
// Coincidencia de patón en un texto

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Preprocesamiento del patrón: longest proper prefix which is also a suffix
// Complejidad: O(m) m = longitud del patrón
vector<int> lps(string p){
	int n = p.size();
	vector<int> lpsv(n, 0);
	int j=0, i=1;
	while (i < n){
		if (p[i] == p[j]){
			lpsv[i++] = ++j;
		}
		else{
			if (j==0){
				lpsv[i] = 0;
				i++;
			}
			else{
				j = lpsv[j-1];
			}
		}
	}
	return lpsv;
}

// Complejidad: O(n + m) // n = long texto y m = long patrón
vector<int> kmp(string texto, string patron){
	vector<int> posMatch;
	vector<int> lpsv = lps(patron);
	int j = 0, i = 0;
	int n = texto.length();
	int m = patron.length();
	for (int a=0; a<lpsv.size(); a++){
		cout << "[" << a << "] = " << lpsv[a] << endl;
	}
	while (i < n){
		if (texto[i] == patron[j]){
			i++;
			j++;
			if (j == m){
				posMatch.push_back(i-m);
				j = lpsv[j-1];
			}
		}
		else{
			if (j == 0){
				i++;
			}
			else{
				j = lpsv[j-1];
			}
		}
	}
	return posMatch;
}

int main(){
	string texto, patron;
	cin >> texto >> patron;
	vector<int> posMatch = kmp(texto, patron);
	if (posMatch.size() == 0){
		cout << "No match" << endl;
	}
	else{
		for (int i=0; i<posMatch.size(); i++){
			cout << posMatch[i] << " ";
		}
		cout << endl;
	}
	return 0;
}

// bacacabcaca
// aca