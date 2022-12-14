// Jorge Valdivia Padron A00831133
// Actividad 01
#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstdio>
#include<map>
#include <cmath>
using namespace std;

void tokenize(string const &str, const char delim,
            vector<string> &out)
{
    // construct a stream from the string
    stringstream ss(str);
 
    string s;
    while (getline(ss, s, delim)) {
        out.push_back(s);
    }
}

int main(){

    int m;
    string n;
    string oracion, caso;
    getline(cin, n);
    getline(cin, oracion);
    m = stoi(n);
    vector<char> vectorCodigo;
    vector<string> vectorCasos1, vectorCasos2, vectorCasos3, resultt;
    vector<int> vectorCasos4;
    int counter = 0;
    for(int i = 0; i < 14; i++){
        vectorCodigo.push_back(oracion.at(counter));
        counter = counter + 2;
    }

    unordered_map<char, char> umap{
        {vectorCodigo[0], '0'}, {vectorCodigo[1], '1'}, {vectorCodigo[2], '2'}, {vectorCodigo[3], '3'},
        {vectorCodigo[4], '4'}, {vectorCodigo[5], '5'}, {vectorCodigo[6], '6'}, {vectorCodigo[7], '7'},
        {vectorCodigo[8], '8'}, {vectorCodigo[9], '9'}, {vectorCodigo[10], '+'}, {vectorCodigo[11], '-'},
        {vectorCodigo[12], '*'}, {vectorCodigo[13], '/'}, {' ', ' '}
        };

/*     for(int i = 0; i < vectorCodigo.size(); i++){
        cout << vectorCodigo[i] << endl;
    } */
        

    for(int i = 0; i < m; i++){
        getline(cin, caso);
        cout << caso << endl;
        for(int j = 0; j < caso.size(); j++){
            char xerr = caso[j];
            char yerr = umap[caso[j]];
            replace( caso.begin(), caso.end(), xerr, yerr);  
        }
        string parte1, parte3;
        string parte2;
        stringstream ss(caso);
        
        ss>>parte1>>parte2>>parte3;
        tokenize(caso, ' ', resultt);
        cout << resultt[2] << endl;;
        //cout << "UWw  " << parte1 << " " << parte2 << " " << parte3  << endl;
        
        int parte1INT = stoi(parte1);
        int parte3INT = stoi(parte3);
        int parte4INT = 69;

        if(parte2 == "+"){
            parte4INT = parte1INT + parte3INT;
        }
        else if(parte2 == "-"){
            parte4INT = parte1INT - parte3INT;
        }
        else if(parte2 == "*"){
            parte4INT = parte1INT * parte3INT;
        }
        else if(parte2 == "/"){
            parte4INT = parte1INT / parte3INT;
            parte4INT = round(parte4INT);
        }

        vectorCasos1.push_back(parte1);
        vectorCasos2.push_back(parte2);
        vectorCasos3.push_back(parte3);
        vectorCasos4.push_back(parte4INT);
    }


    for(int i = 0; i < m; i++){
        string juas = "("+vectorCasos1[i]+") "+ vectorCasos2[i] + " (" + vectorCasos3[i] + ") = " + to_string(vectorCasos4[i]);
        cout << juas << endl;
    }
    
    return 0;
}