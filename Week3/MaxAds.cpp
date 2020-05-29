#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long MaxProd(vector <int> a, vector <int> b) {
    int n = a.size();
    long long prod = 0;
    while (n--) {
        prod += (long long) a.back() * b.back();
        a.pop_back();
        b.pop_back();
    }
    return prod;

}



int main() {
    int n;
    cin >> n;
    vector <int> a(n),b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(a.begin(),a.end());
    sort(b.begin(), b.end());

    cout << MaxProd(a,b);
}