#include <iostream>
#include <cstdio>

using namespace std;

int main() {
  string a, b;
  cin >> a >> b;
  while (a[0] != '*') {
    int dp[1010][1010];
    int n = (int) a.length(),
        m = (int) b.length();
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
      dp[i][0] = i;
    }
    for (int j = 1; j <= m; j++) {
      dp[0][j] = j;
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        dp[i][j] = 1 + min(dp[i - 1][j], dp[i][j - 1]);
        dp[i][j] = min(dp[i][j],
            !(a[i - 1] == b[j - 1]) + dp[i - 1][j - 1]);
        if (j > 1 && a[i - 1] == b[j - 2]) {
          for (int k = i - 2; k >= 0; k--) {
            if (a[k] == b[j - 1]) {
              dp[i][j] = min(dp[i][j],
                   1 + ((i - 2) - k) + dp[k][j - 2]);
            }
          }
        }
      }
    }

    /*
    cout << a << " vs " << b << endl;
    for (int j = 0; j <= m; j++) {
      if (j == 0) cout << "    ";
      else cout << b[j - 1] << " ";
    }
    cout << endl;
    for (int i = 0; i <= n; i++) {
      if (i == 0) cout << "  ";
      else cout << a[i - 1] << " ";
      for (int j = 0; j <= m; j++) {
        cout << dp[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl; //*/

    cout << dp[n][m] << endl;

    cin >> a >> b;
  }
}
