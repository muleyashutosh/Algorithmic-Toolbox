#include <iostream>
#include <vector>
using namespace std;


void Merge(vector <int> &a, int l, int mid, int r) {
    int i = 0, j = 0, k = l;
   vector <int> left,right;
   for(int i = l; i <= mid ; i++) {
       left.push_back(a[i]);
   }
   for(int i = mid + 1; i <= r ; i++) {
       right.push_back(a[i]);
   }
   int m = left.size(), n = right.size();
    // cout << endl << "l PART: " << endl;
    //     for(int i = 0 ; i < m; i++) {
    //         cout << left[i] << " ";
    //     }
    // cout << endl << "RIGHT PART: " << endl;
    //    for(int i = 0; i < n; i++) {
    //         cout << right[i] << " ";
    //     }

    while(i < m && j < n) {
        if( left[i] <= right[j]) {
            a[k++] = left[i];
            i++;
        }
        else {
            a[k++] = right[j++];
        }

    }
    while(i < m) {
        a[k++] = left[i];
        i++;
    }
    while(j < n) {
        a[k++] = right[j];
        j++;
    }
    // cout << endl << "MERGED PART: " << endl;
    // for(int i = l ; i <= r; i++) {
    //     cout << a[i] << " ";
    // }
    // cout << endl;
}



void merge_sort(vector <int> &a, int l, int r) {

    if(l < r) {

        int mid = l + (r - l)/  2;
        // cout << endl << "MID: " << mid << endl;
        merge_sort(a, l, mid);
       
        merge_sort(a, mid + 1, r);
        
        Merge(a, l, mid, r);
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> a(n);
    for(int i = 0 ; i < n; i++) {
        cin >> a[i];
    }

    merge_sort(a, 0, n-1);

    for(int i = 0 ; i < n; i++) {
        cout <<  a[i] << " ";
    }

    //cout << count << endl;
}