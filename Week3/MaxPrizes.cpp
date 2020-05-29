#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int z = 1;

int pick_no( int n, vector <int> &x, int &sum) {
    while(z <= n) {
        int y = sum + z;
        if(y <= n) {
            z++;
            return z-1;
        }
        if(y > n) {
            int l = x.back();
            x.pop_back();
            sum -= l;
            z++;
            return z-1;
        }
      z++;
    }
    return -1;
}



void max_prizes(int n) {
    vector <int> x;
    int sum = 0;
    while(true) {
        int no = pick_no(n, x, sum);
        sum += no;
        x.push_back(no);
        if(sum > n) {
            int l = x.back();
            x.pop_back();
            sum -= l;
        }
        if(sum == n || no == -1) {
            break;
        }
    }
    cout << x.size() << endl;
    for(int i = 0; i < x.size(); i++) {
            cout << x[i] << " ";
    }
}



int main() {
    int n;
    cin >> n;
    max_prizes(n);


}
