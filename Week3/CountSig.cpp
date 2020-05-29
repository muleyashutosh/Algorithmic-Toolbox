#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// define a structure to store a line object with a start point and end point
struct line {
    int start;
    int end;
    bool touch = false;
};

// sort the lines based on the end points
void sort_by_right(vector <line> &x) {
    vector <pair<int,int>> y;
    for(int i = 0 ; i < x.size(); i++) {
        y.push_back(make_pair(x[i].end,x[i].start));
    }
    
    sort(y.begin(),y.end());
    
    
    for(int i = 0 ; i < x.size(); i++) {
        x[i].start = y[i].second;
        x[i].end = y[i].first;
    }
    
}

// get the end point of the first line which is not already touched
int get_end_point(vector <line> x) {
    for(int i = 0; i < x.size(); i++) {
        if(!(x[i].touch))
            return x[i].end;
    }
    return -1;

}

//mark all lines containing the point as touched
void cover_lines_by_point(vector <line> &x, int point) {
  
    for(int i = 0; i < x.size(); i++) {
        if(point >= x[i].start && point <= x[i].end) {
            x[i].touch = true;
        }
    }
    
}

// get the minimum no of points required to touch all lines
vector <int> optimal_points(vector <line> &x) {
    vector <int> points;
    while(true) {
        int first_point = get_end_point(x);
        if(first_point == -1) {
            break;
        }
        points.push_back(first_point);
        cover_lines_by_point(x, first_point);
    }
    return points;
}

// main driver function
int main() {

    int n;
    cin >> n;
    vector <line> x;
    for (int i = 0; i < n; i++ ) {
        int s, e;
        cin >> s >> e;
        line l;
        l.start = s;
        l.end = e;
        x.push_back(l);
    }
    
    sort_by_right(x);
    
    vector <int> points = optimal_points(x);
    cout << points.size() << endl;
     for(int i = 0 ; i < points.size(); i++) {
        cout << points[i] << " ";
    }


	return 0;
}

