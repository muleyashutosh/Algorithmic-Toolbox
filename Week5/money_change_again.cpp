#include <iostream>
#include <limits>
using namespace std;


int dpChange(int money, int coins[]) {
    int minNumCoins[money+1] = {0};
    for (int i = 1; i <= money; i++) {
        minNumCoins[i] = __INT_MAX__;
        for (int x = 0; x < 3; x++) {
            int coin = coins[x];
            if (i >= coin) {
                if (minNumCoins[i - coin] + 1 < minNumCoins[i]) {
                    minNumCoins[i] = minNumCoins[i - coin] + 1;
                }
                
            }
        }
    }
    return minNumCoins[money];
}



int main() {
    int money;
    cin >> money;
    int coins[] = {1, 3, 4};
    int minNumCoins[5] = {0};
    cout << dpChange(money,coins);
}