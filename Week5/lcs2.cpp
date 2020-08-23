#include<iostream>
using namespace std;

int solve(int n, int m, int a[], int b[]) {
    int dp[n + 1][m + 1] = {0};
    
    for(int i = 1 ; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int high = -1;
            if(a[i-1] == b[j-1])
                high = dp[i-1][j-1] + 1;
            else
                high = max(dp[i-1][j], dp[i][j-1]);
            dp[i][j] = high;
        }
    }
    for(int i = 0 ; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
            cout << dp[i][j];
        }
        cout << "\n";
    }
    return dp[n][m];
}


int main () {
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++)
        cin >> a[i];
    cin >> m;
    int b[m];
    for(int i = 0; i < m; i++) 
        cin >> b[i];
    cout << solve(n, m, a, b) << endl;
    
}