#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

void swap(int &a, int &b) {
    int t = a;
    a = b;
    b = t;
}


vector <int> partition(int low, int high, int a[]) {
    int pivot = a[low];
    int i = low + 1;
    int m1 = low;
    int m2 = low;
    // cout << "pivot: " << pivot <<endl;
    while(i <= high) {
        if(a[i] < pivot) {
            m1++;
            m2 = m1;
            swap(a[i], a[m1]);
        }
        if(a[i] == pivot) {
            m2++;
            swap(a[i], a[m2]);
        }
        i++;
    }
    swap(a[m1], a[low]);
    return {m1, m2};
}


void quicksort(int low,int high,int a[]) {
    if( low < high) {
        int k = low + rand() % (high - low + 1);
        // cout << endl << "k: " << k << endl ;
        swap(a[low], a[k]);
        vector <int> m = partition(low, high, a);
        // cout << "p: " << p << endl;
        // for(int i = 0; i <= high; i++) {
        //     cout << a[i] << " ";
        // }
        quicksort(low, m[0] - 1, a);
        quicksort(m[1] + 1, high, a);
    }
}

int main () {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    quicksort(0, n-1 , a);
    cout << endl;
    for(int i = 0; i < n; i++) {
       cout << a[i] << " ";
    }
}