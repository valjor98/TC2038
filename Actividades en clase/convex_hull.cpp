// Convez hull
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
 using namespace std;

 struct Point{
    int x, y;
    Point(){
        x = y = 0;
    }
    Point(int x, int y){
        this-> x = x;
        this-> y = y;
    }
 };

Point p0;

int distSq(Point &p1, Point &p2){
    return  (p1.x - p2.x) * (p1.x - p2.x)  +
            (p1.y - p2.y) * (p1.y - p2.y);
}

int orientation(Point &p0, Point &p1, Point &p2){
    int v = (p1.y - p0.y) * (p2.x - p1.x)  -
            (p1.x - p0.x) * (p2.y - p1.y);
    if(v == 0){
        return 0;
    }
    return (v> 0) ? 1 : 2;
}

bool compare(Point &p1, Point &p2){
    int orien = orientation(p0, p1, p2);
    if(orien == 0){
        return (distSq(p0, p2) >= distSq(p0, p1));
    }
    return (orien == 2);
}

Point nextToTop(stack<Point> &s){
    Point p = s.top();
    s.pop();
    Point ans = s.top();
    s.push(p);
    return ans;
}

void convexHull(vector<Point> &points){
    int n = points.size();
    int yMin = points[0].y, minIdx = 0;
    for(int i = 1; i < n; i++){
        int x = points[i].x;
        int y = points[i].y;
        if(y < yMin || y == yMin && x < points[minIdx].x){
            yMin = y;
            minIdx = i;
        }
    }
    Point temp = points[0];
    points[0] = points[minIdx];
    points[minIdx] = temp;
    p0 = points[0];
    sort(points.begin()+1, points.end(), compare);
    int m = 1;
    for(int i = 1; i < n; i++){
        while(i<n-1 && orientation(p0, points[i], points[i+1]) == 0){
            i++;
        }
        points[m] = points[i];
        m++;
    }
    if(m < 3){
        return;
    }
    
    stack<Point> s;
    s.push(points[0]);
    s.push(points[1]);
    s.push(points[2]);
    for(int i = 3; i<m; i++){
        Point nTT = nextToTop(s);
        while(s.size() > 1 && orientation(nTT, s.top(), points[i]) != 2){
            s.pop();
            nTT = nextToTop(s);
        }
        s.push(points[i]);
    }
    while(!s.empty()){
        Point p = s.top();
        cout << "(" << p.x << ", " << p.y << ")" << endl;
        s.pop();
    }
}

int main(){
    vector<Point> points;
    int n, x, y;
    cin >> n;
    for(int i = 0; i< n; i++){
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    convexHull(points);
    return 0;
}
/* 
8
0 3
1 1
2 2
4 4
0 0
1 2
3 1
3 3
 */