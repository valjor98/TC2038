#include <iostream>
#include <algorithm>
#include <vector>
#include <cfloat>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point{
    float x, y;
    Point(){
        x = y = 0;
    }
    Point(float x, float y){
        this -> x = x;
        this -> y = y;
    }
};

// Comparador para Sort de X
bool compareX(const Point &p1, const Point &p2){
    return (p1.x < p2.x);
}


bool compareY(const Point &p1, const Point &p2){
    return (p1.y < p2.y);
}

//Funcion de la distancia
float dist(Point &p1, Point &p2){
    return sqrt((p1.x -p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

float bruteForce(vector<Point> &P, int ini, int fin){
    cout << "brute force" << endl;
    float minAux = FLT_MAX;
    for(int i = ini; i < fin; i++){
        cout << "brute force AAAAAAAAAAAAAAAAAA" << endl;
        for(int j = i+1; i < fin; j++){
            minAux = min(minAux, dist(P[i], P[j]));
            cout << "brute force BBBBB" << endl;
        }
    }
    return minAux;
}

float stripClosest(vector<Point> &strip, float dMenor){
    cout << "strip" << endl;
    float minStrip = dMenor;
    sort(strip.begin(), strip.end(), compareY);
    for(int i = 0; i < strip.size()-1 ; i++){
        for(int j = i+1; j < strip.size() && (strip[j].y - strip[i].y) < minStrip; j++  ){
            minStrip = min(minStrip, dist(strip[i], strip[j]));
        }
    }
    cout << "strip" << endl;
    return minStrip;
}

float closest_Helper(vector<Point> &P, int ini, int fin){
    // si en rango solo hay 3 o menos hacerlo por fuerza bruta
    if( fin-ini < 3){
        cout << "sexo 7" << endl;
        return bruteForce(P, ini, fin);
    }
    cout << "sexo 3" << endl;
    int mid = (ini+fin)/2;
    Point midPoint = P[mid];
    float dl = closest_Helper(P, ini, mid);
    float dr = closest_Helper(P, mid+1, fin);
    float dMenor = min(dl, dr);
    cout << "sexo 4" << endl;
    vector <Point> strip;
    for(int i = ini ; i < fin ; i++){
        if(abs(P[i].x - midPoint.x) < dMenor){
            strip.push_back(P[i]);
        }
    }
    cout << "sexo 5" << endl;
    float ds = stripClosest(strip, dMenor);
    dMenor = min(dMenor, ds);
    cout << "sexo 6" << endl;
    return dMenor;
}
// compledidad O(nlog(n) 
float closest(vector<Point> &P){
    //Ordenr con respeccto a X
    cout << "sexo 1" << endl;
    sort(P.begin(), P.end(), compareX);
    cout << "sexo 3" << endl;
    return closest_Helper(P, 0, P.size() - 1);
}

int main(){
    int n;
    float x, y;
    cin >> n;
    vector<Point> P(n);
    for( int i = 0; i < n; i++){
        cin >> x >> y;
        P[i].x = x;
        P[i].y = y;
    }
    float d = closest(P);
    cout.precision(2);
    cout << "La distancia minima es: " << fixed << d << endl;
    return 0;
}

/* 
5
5 10
2 30
1 15
10 2
20 5
 */