#include <iostream>
#include <vector>
#include <cmath>
using namespace std;


int find_digits(int x) {
    int n = 0;
    while(x) {
        x = x / 10;
        n++;
    }
    return n;
}

bool is_better(int x, int y ) {
    if(y == -99999)
        return true;
    int d1 = find_digits(x);
    int d2 = find_digits(y);
    int n1 = (x * pow(10,d2)) + y;
    int n2 = (y * pow(10,d1)) + x;
    //cout << d1 << " " << d2 << " " << n1 << " " << n2 << endl;
    return n1 >= n2;
}



vector <int> findMaxSal(vector <int> Digits) {
    vector <int> answer; 
    while (!(Digits.empty())) {
        int maxDigit = -99999;
        auto i = Digits.begin(); 
        auto z = Digits.begin();
        for(i = Digits.begin() ; i != Digits.end(); i++) {
            if(is_better(*i,maxDigit)) {
                maxDigit = *i;
                z = i;
            }
        }
        answer.push_back(maxDigit);
        // for(int i = 0 ;i < Digits.size() ;i++ ) {
        // cout << Digits[i] << " ";
        // }cout << endl;
        Digits.erase(z);
        // for(int i = 0 ;i < Digits.size() ;i++ ) {
        //     cout << Digits[i];
        // }
    }
    return answer;
}


int main () {
    int n;
    cin >> n;
    vector <int> sal(n);
    for(int i = 0;i < n; i++) {
        cin >> sal[i];
    }
    vector <int> answer = findMaxSal(sal);
    for(int i = 0 ;i < n ;i++ ) {
        cout << answer[i];
    }

}
