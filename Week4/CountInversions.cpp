#include <iostream>
#include <vector>
using namespace std;


int Merge(vector <int> &a, int l, int mid, int r) {

    int count = 0;
    for (int i = mid + 1; i <= r; i++) {
        for (int j = l; j <= mid; j++) {
            if(a[j] > a[i])
                count++;
        }
    }

    return count;
}



int counter(vector <int> &a, int l, int r) {

    int count = 0;
    if(l < r) {

        int mid = l + (r - l)/  2;
        count += counter(a, l, mid);
       
        count += counter(a, mid + 1, r);
        
        count += Merge(a, l, mid, r);
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    cout << counter(a, 0, n-1) << endl;
}