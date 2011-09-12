#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

  typedef unsigned long long ULL;
  vector<ULL> sum;
  ULL dp[2001][2001];

int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int v;
    cin >> v;
    sum.push_back(v);
  }
  reverse(sum.begin(), sum.end());
  for (int i = 1; i < n; i++) {
    sum[i] += sum[i - 1];
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = 0;
    for (int j = 1; j <= i; j++) {
      dp[i][j] = max(dp[i][j - 1],
                     sum[i - 1] - dp[i - j][min(2 * j, i - j)]);
    }
  }

  /*
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= i; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;//*/

  cout << max(dp[n][1], dp[n][2]) << endl;
}
