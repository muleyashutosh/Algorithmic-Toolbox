#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int start_bin(vector <int> arr, int n, int key) {
    int l = 0, r = n;
    int mid; 
    while(l < r) {
        int mid = (l + r) / 2; 
        if(arr[mid] > key) {
            while(mid - 1 >= 0 && arr[mid - 1] > key)
                mid--;
            return mid;
        }
        else {
            l = mid+1;
        }
    }
    return -1;
}

int end_bin(vector <int> arr, int n, int key) {
    int l = 0, r = n;
    int mid; 
    while(l < r) {
        int mid = (l + r) / 2; 
        if(arr[mid] < key) {
            while(mid + 1 < n && arr[mid + 1] < key)
                mid++;
            return mid;
        }
        else {
            r = mid;
        }
    }
    return -1;
}




int main() { 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL); 
    int s, p;
    cin >> s >> p;
    vector <int> start(s);
    vector <int> end(s);
    for(int i = 0 ; i < s; i++) 
        cin >> start[i] >> end[i];
    sort(start.begin(),start.end());
    sort(end.begin(), end.end());

    for(int i = 0; i < p; i++) {
        int p;
        cin >> p;
        int x = start_bin(start,s,p);
        int count1;
        if(x == -1) {
            count1 = 0;
        }
        else {
            count1 = s - x;
        }
        
        int y = end_bin(end,s,p);
        int count2;
        if( y == -1) {
            count2 = 0;
        }
        else {
            count2 = y + 1;
        }
        cout << s - (count1 + count2) << " ";
    }
}