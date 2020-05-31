#include <iostream>
#include <algorithm>
using namespace std;

bool majElement(int a[], int n) {
    int count = 0;
    int prev = -1;
    int half = n / 2;
    int i = 0;
    while (i < n) {
        if(a[i] != prev) {
            count = 1;
        }
        else {
            count++;
        }
        //cout << count << " " << a[i] << " " << prev << endl;
        if(count > half) {
            return true;
        }
        prev = a[i];
        i++;
    }
    return false;
}



int main () {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a, a+n);
    // for(int i = 0; i < n; i++) {
    //     cout << a[i];
    // }
    cout << majElement(a,n);
}