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