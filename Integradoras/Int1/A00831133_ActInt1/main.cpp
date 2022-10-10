// Actividad Integradora 1
// Jorge Valdivia Padron

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int N = 3;

vector<int> lps(string pattern){
    int n = pattern.length();
    vector<int> lpsv(n,0);
    int j=0, i=1;
    while (i<n){
        if (pattern[i] == pattern[j]){
            lpsv[i] = j+1;
            j++;
            i++;
        } 
        else{
            if(j==0){
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

// Complejidad: O(n)
vector<int> kmp(string stringT, string pattern){
    vector<int> posMatch;
    vector<int> lpsv = lps(pattern);
    int j = 0;
    int i = 0;
    int n = stringT.length();
    int m = pattern.length();
    if (n < m) {
        return posMatch;
    }
    while (i < n) {
        if (stringT[i] == pattern[j]){
            i++;
            j++;
            if (j == m) {
                posMatch.push_back(i-m);
                j = lpsv[j-1];
            } 
        }
        else {
            if (j==0) {
                i++;
            } 
            else {
                j = lpsv[j-1];
            }
        }
    }
    return posMatch;
}

// Complejidad: O(n) 
void manacher(string stringT, string& palindromee, int& position){
    string T = "";
    int n = stringT.length();
    for (int i=0; i<n; i++){
        T += "|";
        T += stringT[i];
    }
    T += "|";
    n = T.length();
    vector<int> L(n);
    L[0] = 0;
    L[1] = 1;
    int maxLong = 0, maxCentro = 0;
    bool exp;
    for (int c=1, li=0, ri=2; ri<n; ri++){
        li = c-(ri-c);
        exp = false;
        if (c-maxLong <= ri && ri >= c+maxLong){
            if (L[li] < (c+L[c]-ri)){
                L[ri] = L[li];
            }
            else if(L[li] == (c + L[c]) - ri && (c + L[c]) == 2*n){
                L[ri] = L[li];
            }
            else if(L[li] == (c + L[c]) - ri && (c + L[c]) < 2*n){
                L[ri] = L[li];
                exp = true;
            }
            else if(L[li] > (c + L[c]) - ri && (c + L[c]) < 2*n){
                L[ri] = (c+L[c]) - ri;
                exp = true;
            }
        }
        else{
            L[ri] = 0;
            exp = true;
        }
        if (exp){
            while((ri + L[ri] < n) && (ri - L[ri] > 0) && (T[ri - L[ri] - 1] == T[ri + L[ri] + 1])){
                L[ri]++;
            }
        }
        c = ri;
        if (L[ri] > maxLong){
            maxLong = L[ri];
            maxCentro = ri;
        }
    }
    int ini = (maxCentro - maxLong) / 2;
    string endd = "";
    for (int i=ini; i < (ini + maxLong); i++){
        endd += stringT[i];
    }
    palindromee = endd;
    position = ini;
}

// Complejidad: O(n*m)
void longestSubString(string str1, string str2, string& subStr){
    int iN1 = str1.length();
    int iN2 = str2.length();
    int iMax = 0;
    vector <int> iAux(iN2);
    vector <string> sAux(iN2);
    vector<vector <int> > iLCS (iN1, iAux);
    vector<vector <string> > sLCS (iN1, sAux);

    for (int i=0; i<iN1; i++){
        if (str1[i] == str2[0]){
            iLCS[i][0] = 1;
            iMax = 1;
            
            sLCS[i][0] += str1[i];
            subStr = str1[i];
        } else {
            iLCS[i][0] = 0;
            sLCS[i][0] = "";
        }
    }

    for (int j=0; j<iN2; j++){
        if (str2[j] == str1[0]){
            iLCS[0][j] = 1;
            iMax = 1;

            sLCS[0][j] += str2[j];
            subStr = str2[j];
        } else {
            iLCS[0][j] = 0;
            sLCS[0][j] = "";
        }
    }

    for (int i=1; i < iN1; i++){
        for (int j=1; j<iN2; j++){
            if (str1[i] == str2[j]){
                iLCS[i][j] = iLCS[i-1][j-1] + 1;
                sLCS[i][j] = sLCS[i-1][j-1] + str1[i];
                if (iLCS[i][j] > iMax) {
                    iMax = iLCS[i][j];
                    subStr = sLCS[i][j];
                }
            } else {
                iLCS[i][j] = 0;
                sLCS[i][j] = "";
            }
        }
    }
}

// Complejidad O(n)
bool sequenceCheck(string pattern, string transmission){
    int s = 0;
    for (int i = 0; i< transmission.length(); i++){
        if (pattern[s] == transmission[i]){
            s++;
        }
        if (s == pattern.length()){
            return true;
        }
    }
    return false;
}

//Complejidad O(n^2)
void substringMost(string pattern, string transmission, string& result, int& amount){
    string code;
    int counter;
    amount = 0;
    if (pattern.length() != 1){
        for (int i = 0; i < pattern.length(); i++){
            code = pattern.substr(0,i) + pattern.substr(i+1);
            counter = 0;
            for (int j = 0; j < transmission.length(); j++){
                if (transmission[j] == code[0]){
                    if (sequenceCheck(code, transmission.substr(j))){ 
                        counter++;
                    }
                }
            }
            if (counter > amount){
                result = code;
                amount = counter;
            }
        }
    }
    result = code;
    amount = counter;
}


// Complejidad O(n)
vector<string> readMaliciousCode(){
    vector<string> maliciousCode;
    ifstream mcode("mcode.txt");
    if (mcode.fail()){
        throw runtime_error("Error con mcode.txt");
    }
    string stringM;
    while (getline(mcode, stringM)){
        if(stringM.size() > 0){
            maliciousCode.push_back(stringM);
        }
    }
    mcode.close();
    return maliciousCode;
}


// Complejidad O(1)
vector<string> readTransFiles(){
    vector<string> vectorTransmisions(3);
    for (int i=0; i < 3; i++){
        ifstream transmission_N;
        string fileN = "transmission" + to_string(i+1) + ".txt";
        transmission_N.open(fileN);
        if (transmission_N.fail()){ // Si falla, lanzar exepcion
            throw runtime_error("Error con transmission" + to_string(i+1) + ".txt");
        }
        string sLine;
        if (transmission_N.good()){
            getline(transmission_N, sLine);
            vectorTransmisions[i] = sLine;
        }
        transmission_N.close();
    }
    return vectorTransmisions;
}


// Complejidad O(n*m)
void findRepeated(ofstream& outputFile, vector<string> maliciousCode, vector<string> vectorTransmisions){
    for (int i = 0; i < maliciousCode.size(); i++){
        outputFile << "Código: " << maliciousCode[i] << endl;
        for (int j = 0; j < N; j++){
            vector<int> posMatch = kmp(vectorTransmisions[j], maliciousCode[i]);
            outputFile << "Transmission" << j+1 << ".txt ==> " << posMatch.size() << " veces" << endl;
            int x = posMatch.size();
            for (int k=0; k < x; k++){
                if(k == x-1){
                    outputFile << posMatch[k] << "";
                }
                else{
                    outputFile << posMatch[k] << ", ";
                }
            }
            outputFile << endl;
        }
        string sub1, sub2, sub3, maxS;
        int cant1, cant2, cant3, maxC;
        string fileM;
        substringMost(maliciousCode[i], vectorTransmisions[0], sub1, cant1);
        substringMost(maliciousCode[i], vectorTransmisions[1], sub2, cant2);
        substringMost(maliciousCode[i], vectorTransmisions[2], sub3, cant3);

        if (cant1 >= cant2){
            if (cant1 >= cant3){
                maxS = sub1;
                maxC = cant1;
                fileM = "transmission1.txt";
            }
            else{
                maxS = sub3;
                maxC = cant3;
                fileM = "transmission3.txt";
            }
        }
        else{
            if (cant2 >= cant3){
                maxS = sub2;
                maxC = cant2;
                fileM = "transmission2.txt";
            }
            else{
                maxS = sub3;
                maxC = cant3;
                fileM = "transmission3.txt";
            }
        }
        outputFile << "La subsecuencia más encontrada es: " << maxS << " con " << maxC << " veces en el archivo " + fileM << endl;
        if(i == (maliciousCode.size() - 1)){
            outputFile;
        }
        else{
            outputFile << "--------------" << endl;
        }
    }
    outputFile << "==============" << endl;
}


// Complejidad: O(n)
void palindromFunction(ofstream& outputFile, vector<string> vectorTransmisions){
    for (int i = 0; i < N; i++){
        int iPos;
        string sPalindromo;
        manacher(vectorTransmisions[i], sPalindromo, iPos);

        outputFile << "Transmission" << i+1 << ".txt ==> Posición: " << iPos << endl; 
        outputFile << sPalindromo << endl;

        if(i == N-1){
            outputFile;
        }
        else{
            outputFile << "----" << endl;
        }
    }
    outputFile << "============" << endl;
}


// Complejidad: O(n*m)
void substring(ofstream& outputFile, vector<string> vectorTransmisions){
    string subStr1, subStr2, subStr3;
    longestSubString(vectorTransmisions[0], vectorTransmisions[1], subStr1);
    longestSubString(vectorTransmisions[0], vectorTransmisions[2], subStr2);
    longestSubString(vectorTransmisions[1], vectorTransmisions[2], subStr3);
    outputFile << "Los Substring más largos son:" << endl;
    outputFile << "T1-T2 ==> " << subStr1 << endl;
    outputFile << "T1-T3 ==> " << subStr2 << endl;
    outputFile << "T2-T3 ==> " << subStr3 << endl;
}


int main(){
    vector<string> maliciousCode;
    vector<string> vectorTransmisions(N);
    ofstream outputFile;
    
    maliciousCode = readMaliciousCode();
    vectorTransmisions = readTransFiles();
    outputFile.open("checking.txt");
    

    findRepeated(outputFile, maliciousCode, vectorTransmisions);
    palindromFunction(outputFile, vectorTransmisions);
    substring(outputFile, vectorTransmisions);


    outputFile.close();
    cout << "Code executed succesfully" << endl;
    return 0;
}