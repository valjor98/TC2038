//
// Matricula: A00831133
// Nombre: Jorge Valdivia Padron
//
//

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <unordered_set>

using namespace std;

typedef pair<int,int> iPair;

struct groupOH{
    int numInicial;
    string secuenc;
    int grps;
    int Os;
    int Hs;


    bool operator<(const groupOH& b) const{
        if ((b.grps > this->grps) == true){
            return true;
        }
        else{
            return false;
        }
    }
    bool operator>(const groupOH& b) const{
        if ((b.grps < this->grps) == true){
            return true;
        }
        else{
            return false;
        }
    }
    groupOH(string secuenc, int grps, int numInicial){
        this-> secuenc = secuenc;
        this-> grps = grps;
        this-> numInicial = numInicial;
    }
};


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

//Complejidad: O(nk + mk)
vector<string> ordenaxPotencia(vector<string> &v){
    vector<string> resultados;
    vector<pair<int,int>> resGroups;
    vector<int> resultadosNum;
    for(int i = 0; i < v.size(); i++){  // O(k)
        int x = kmp(v[i], "O").size();  // O(n + m)
        int y = kmp(v[i], "H").size();  // O(n + m)
        int lesser;
        if(x > y ){
            lesser = y;
        }
        else{
            lesser = x;
        }
        // pairs(groups, numinicial)
        groupOH a = groupOH(v[i], lesser, i);
        resGroups.push_back({lesser, i});
    }
    sort(resGroups.begin(), resGroups.end(),  greater<pair<int,int>>()); // O(Nlog(N))
    //reverse(resGroups.begin(), resGroups.end());
    //cout << "------" << endl;
    for(int i = 0; i < v.size(); i++){   // O(k)
        resultados.push_back(v[resGroups[i].second]);
        //cout<< resGroups[i].first << endl;
    }
    return resultados;
}


int main() {
    
    int l, n;
    string adn;
    vector<string> v;
    cin >> l >> n;
    for(int i = 0; i < n; i++){
        cin >> adn;
        v.push_back(adn);
    }
    vector<string> sale = ordenaxPotencia(v);
    for(int i = 0; i < n; i++){
        cout << sale[i]<<  endl;
    }
    return 0;
}
/* 
10 6
HHHOOOOOHH
OHOOHHHHOO
HHHHOHHOOH
HOOHOHHHHH
HOHOHHOHOH
HHOOOOOOOH
 */