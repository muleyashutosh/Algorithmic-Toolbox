#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int rsearch(vector <int> end, int l, int h, int key) {
    int count = 0;
    if(l <= h) {
        int mid = l + (h - l) / 2;
        if(end[mid] < key) {
            
            if(l == h)
                return 1;
            count = (mid - l) + 1;
            count += rsearch(end, mid + 1, h, key);
        }
        else {
            count += rsearch(end, l, mid - 1, key);
        }
    }
    return count;
}


int lsearch(vector <int> start, int l, int h, int key) {
    int count = 0;
    if(l <= h) {
        int mid = l + (h - l) / 2;
        if(start[mid] > key) {
            if(l == h)
                return 1;
            count = (h - mid) + 1;
            count += lsearch(start, l, mid-1, key);
        }
        else {
            count += lsearch(start, mid+1, h, key);
        }   
    }
    return count;
}



int main() {
    int s, p;
    cin >> s >> p;
    vector <int> start(s), end(s);
    vector <int> points(p);
    for(int i = 0; i < s; i++) {
        cin >> start[i] >> end[i];
    }
    sort(start.begin(),start.end());
    sort(end.begin(), end.end());

    for(int i = 0; i < p; i++) {
        cin >> points[i];
        int lc = lsearch(start, 0, s-1, points[i]);
        int rc = rsearch(end, 0, s-1, points[i]);
        cout << s - lc - rc << " ";
    }
    return 0;
}
