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

int main(){

    int m;
    string n;
    string oracion, caso;
    getline(cin, n);
    getline(cin, oracion);
    m = stoi(n);
    vector<char> vectorCodigo;
    vector<string> vectorCasos1, vectorCasos2, vectorCasos3;
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


    for(int i = 0; i < m; i++){
        getline(cin, caso);
        for(int j = 0; j < caso.size(); j++){
            char x = caso[j];
            char y = umap[x];
            replace( caso.begin(), caso.end(), x, y);  
        }
        string parte1, parte3;
        string parte2;
        stringstream s(caso);
        s>>parte1>>parte2>>parte3;
        
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