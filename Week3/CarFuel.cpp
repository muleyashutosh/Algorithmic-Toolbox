#include<iostream>
using namespace std;


int CarFuel(int d, int m, int n, int x[]) {
    int A, G = 0, i = 0, count = 0;
    if( d <= m) {
        return 0;
    }
    while(A < d) {
        A = G;
        while((i < n) && (x[i] - A <= m)) {
            G = x[i];
            i++;
        }
        if(A == G) {
            return -1;
        }
        if(i == n) {
            // if(d - G > m) {
            //     return -1;
            // }
            if(( d - A ) <= m){
                return count;
            }
            else {
                if(d - G <= m) {
                    count++;
                    return count;
                }  
                else {
                    return -1;
                }
            }
            
        }  
        if(i < n) {
            count++;
        }
       
    }
    return -1;
}

int main() {
    int d, m ,n;
    cin >> d >> m >> n;
    int x[n];
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }
    cout << CarFuel(d, m, n, x);
    
}

