#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
using namespace std;

vector <int> lookup(int n) {

    vector <int>  dp(n + 1);
    dp[0] = 0;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= n; i++) {
        int a = __INT_MAX__, b = __INT_MAX__, c = __INT_MAX__;
        if (i % 3 == 0) 
            a = dp[i / 3] + 1;
        if ((i & 1) == 0)
            b = dp[i / 2] + 1;
        c = dp[i - 1] + 1;
        dp[i] = min({a, b, c});
    
    }
    return dp; 

}




int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector <int> dp = lookup(n);
    cout << dp[n] << "\n";
    stack <int> elems;
    while(n > 1) {
        elems.emplace(n);
        int a = __INT_MAX__, b = __INT_MAX__, c;
        if (n % 3 == 0) {
            a = dp[n / 3] + 1;
        }
        if (n & 1 == 0) {
            b = dp[n / 2] + 1;
        }
        c = dp[n - 1] + 1; 
        if (a <= b and a <= c)
            n /= 3;
        else if ( b <= a && b <= c)
            n /= 2;
        else 
            n--;
    }
    cout << 1 << " ";
    while(!elems.empty()) {
        cout << elems.top() << " ";
        elems.pop();
    }
    
    

}