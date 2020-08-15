#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <limits>
#include <cstdlib>

using namespace std;

class Point {
    public:
    int x,y;
};

bool compX(Point a , Point b) {
    if(a.x == b.x) {
        return (a.y < b.y);
    }
    return (a.x < b.x);
}
bool compY(Point a, Point b) {
    if(a.y == b.y) {
        return (a.x < b.x);
    }
    return (a.y < b.y);
}
float dist(Point a, Point b) {
    float d = sqrt(pow((a.x - b.x),2) + pow((a.y - b.y),2));
    return d;
}
float bruteF(Point points[], int n) {

    float min = __FLT_MAX__;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            float d = dist(points[i], points[j]);
            if(d < min)
                min = d;
        }
    }
    return min;
}

float stripClosestFAST(Point strip[], int n, float min) {

    for(int i = 0 ; i < n; i++) {
        for(int j = i + 1; j < n && (strip[j].y - strip[i].y) < min; j++) {
            float d = dist(strip[i], strip[j]);
            if(d < min)
                min  = d;
        }
    }

    return min;
}

float stripClosestSLOW(Point strip[], int n, float min) {

    sort(strip, strip + n, compY);

    for(int i = 0 ; i < n; i++) {
        for(int j = i + 1; j < n && (strip[j].y - strip[i].y) < min; j++) {
            float d = dist(strip[i], strip[j]);
            if(d < min)
                min  = d;
        }
    }

    return min;
}

//FAST ALGORITHM 
float closestFAST(Point Px[], Point Py[], int n) {

    if (n <= 3) {
        return bruteF(Px, n);
    }

    int mid = n / 2;
    Point midPoint = Px[mid];

    Point Pyl[mid];
    Point Pyr[n - mid];
    
    
    int li = 0, ri = 0;
    for(int i = 0 ; i < n; i++) {
        if (Py[i].x <= midPoint.x && li < mid) 
            Pyl[li++] = Py[i];
        else 
            Pyr[ri++] = Py[i];
    }


    float dl = closestFAST(Px, Pyl, mid);
    float dr = closestFAST(Px + mid, Pyr, n - mid);

    float d = min(dl, dr);
    
    Point strip[n];
    int j = 0;
    for(int i = 0; i < n; i++) {
        if (abs(Py[i].x - midPoint.x) < d) 
            strip[j++] = Py[i];
    }

    return stripClosestFAST(strip, j, d);
}


//SLOW ALGORITHM 
float closestSLOW(Point P[], int n) {

    if (n <= 3) {
        return bruteF(P, n);
    }

    int mid = n / 2;
    Point midPoint = P[mid];

    float dl = closestSLOW(P, mid);
    float dr = closestSLOW(P + mid, n - mid);

    float d = min(dl, dr);
    
    Point strip[n];
    int j = 0;
    for(int i = 0; i < n; i++) {
        if (abs(P[i].x - midPoint.x) < d) 
            strip[j++] = P[i];
    }

    return stripClosestSLOW(strip, j, d);
}

int main () {
    int n;
    //cin >> n;
    while(true) {
        n = 1 + (rand() % 8);
        Point Px[n], Py[n];
        for(int i = 0; i < n; i++) {
            Point p;
            p.x = 1 + (rand()% 10);
            p.y = 1 + (rand()% 10);
            Px[i] = p;
            Py[i] = p;
        }

        sort(Px, Px + n, compX);
        sort(Py, Py + n, compY);
        float d1 = closestSLOW(Px,n);
        float d2 = closestFAST(Px,Py,n);
        cout << n << endl;
        for(Point p: Px) {
            cout << p.x << " " << p.y << endl;
        }
        if(d1 != d2) {
            cout <<"#######FAILED########" << endl;
            cout << d1 << " " << d2 << endl;
            break;
        }
        else {
            cout << "......OK......" << endl;
            cout << d1 << " " << d2 << endl;
        }
        //cout << fixed << setprecision(9) << closest(Px, Py, n);
    }   
}
