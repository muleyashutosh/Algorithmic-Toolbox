#include <iostream>
using namespace std;

int BinSearch(int arr[], int low ,int high, int key) {
    if(high < low)
        return -1;
    int mid = (low + high) / 2;
    int x;
    if(arr[mid] == key) {
        return mid;
    }
    else if (arr[mid] > key) {
        x = BinSearch(arr,low,mid-1,key);
    }
    else {
        x = BinSearch(arr,mid+1,high,key);
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int t;
    cin >> t;
    while(t--) {
        int key;
        cin >> key;
        int x = BinSearch(arr,0,n-1,key);
        cout << x << " ";
    }
}
