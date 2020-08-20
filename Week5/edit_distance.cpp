#include <iostream>
#include <algorithm>
using namespace std;



int main()  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b;
    cin >> a >> b;
    int n = a.length(), m = b.length();
    int dp[n + 1][m + 1] = {0};
    dp[0][0] = 0;
    for(int i = 0; i <= n; i++) 
        dp[i][0] = i;
    for(int i = 0; i <= m; i++) 
        dp[0][i] = i;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int x = dp[i - 1][j] + 1;
            int y = dp[i][j - 1] + 1;
            int z = dp[i - 1][j -1] + (a[i-1] != b[j-1]);
            dp[i][j] = min({x, y, z});
        }
    }
    // for(int i = 0; i <= n; i++) {
    //     for(int j = 0 ; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[n][m];


    
}