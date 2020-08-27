#include <iostream>
#include <vector>
using namespace std;


int main() { 
    int W,n;
    cin >> W >> n;
    int weights[n];
    for(int i = 0; i < n; i++) {
        cin >> weights[i];
    }
    vector <vector <int>> dp(n+1,vector<int> (W+1, 0) );
    
    for(int i = 1; i <= n; i++) {
        for(int w = 1; w <= W; w++) {
            if (weights[i-1] > w)
                dp[i][w] = dp[i-1][w];
            else 
                dp[i][w] = max(weights[i-1] + dp[i-1][w - weights[i-1]], dp[i-1][w]);
        }
    }
    // for(int i = 0; i <= n; i++) {
    //     for(int w = 0; w <= W; w++) {
    //         cout << dp[i][w] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << dp[n][W] << "\n";
    


}