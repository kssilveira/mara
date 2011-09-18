#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

ull dp[11][11];

ull calc(ull i) {
  if (i % 2) {
    return i;
  }
  return (2 * i) % 10;
}

ull solve(ull x) {
  ull res = 0;
  vector<int> v;
  while(x) {
    v.push_back(x % 10);
    x /= 10;
  }
  reverse(v.begin(), v.end());
  int n = (int) v.size();
  
  /*
  cout << "v: ";
  for (int i = 0; i < n; i++) {
    cout << v[i] << " ";
  }
  cout << endl;//*/

  int extra = 0;
  for (int i = 0; i < n; i++) {
    for (int first = 0; first < v[i]; first++) {
      int delta = (extra + calc(first)) % 10;
      for (int alg = 0; alg < 10; alg++) {
        res += dp[n - i - 1][alg] * ((alg + delta) % 10);
      }
    }
    extra = (extra + calc(v[i])) % 10;
  }
  return res;
}

int main() {
  int T;
  cin >> T;

  memset(dp, 0, sizeof(dp));
  
  dp[0][0] = 1;
  for (int i = 0; i < 10; i++) {
    // dp[1][calc(i)]++;
  }
  for (int n = 1; n < 11; n++) {
    for (int first = 0; first < 10; first++) {
      for (int rest = 0; rest < 10; rest++) {
        dp[n][(calc(first) + rest) % 10] +=
          dp[n - 1][rest];
      }
    }
  }

  /*
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;//*/


  while (T--) {
    ull a, b;
    cin >> a >> b;
    cout << solve(b + 1) - solve(a) << endl;
  }
}
