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
    float minAux = FLT_MAX;
    for(int i = ini; i < fin; i++){
        for(int j = i+1; i < fin; j++){
            minAux = min(minAux, dist(P[i], P[j]));
        }
    }
    return minAux;
}

float closest_Helper(vector<Point> &P, int ini, int fin){
    // si en rango solo hay 3 o menos hacerlo por fuerza bruta
    if( fin-ini < 3){
        return bruteForce(P, ini, fin);
    }
    int mid = (ini+fin)/2;
    Point midPoint = P[mid];
    float dl = closest_Helper(P, ini, mid);
    float dr = closest_Helper(P, mid+1, fin);
    float dMenor = min(dl, dr);
}

float closest(vector<Point> &P){
    //Ordenr con respeccto a X
    sort(P.begin(), P.end(), compareX);
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