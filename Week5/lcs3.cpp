#include <iostream>
#include <algorithm>
using namespace std;

int solve(int n, int m, int o, int a[], int b[], int c[]) {
    int dp[n + 1][m + 1][o + 1] = {};

    for(int i = 1 ; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            for(int k = 1; k <= o; k++) {

                if(a[i-1] == b[j-1]  && b[j-1]== c[k-1])
                    dp[i][j][k] = dp[i-1][j-1][k-1] + 1;
                else
                    dp[i][j][k] = max({dp[i-1][j][k], dp[i][j-1][k], dp[i][j][k-1]});
                
            }
            
        }
    }
   
    return dp[n][m][o];
}


int main () {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, o;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++) 
        cin >> b[i];
    cin >> o;
    int c[o];
    for(int i = 0; i < o; i++) 
        cin >> c[i];

    cout << solve(n, m, o, a, b, c) << endl;
    
}