#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
    return a > b;
}

int optimal_weight(int W, vector<int> &w) {
  //write your code here
  int current_weight = 0;
  sort(w.begin(),w.end(),comp);
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int main() {
  int n, W;
  cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  cout << optimal_weight(W, w) << '\n';
}
