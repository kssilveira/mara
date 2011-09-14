#include <cstdio>
#include <iostream>

using namespace std;

static int dp[1001][300001];

int main() {
  int n, k, l;
  scanf(" %d %d %d", &n, &k, &l);

  while (n != 0 || k != 0 || l != 0) {
    int fs[1001], ds[1001];
    for (int i = 0; i < n; i++) {
      int f, d;
      scanf(" %d %d", &d, &f);
      fs[i] = f;
      ds[i] = d;
    }

    for (int j = 0; j <= l; j++) {
      if (j + fs[0] <= l) {
        dp[0][j] = ds[0];
      } else {
        dp[0][j] = 0;
      }
    }

    for (int i = 1; i < n; i++) {
      for (int j = 0; j <= l; j++) {
        dp[i][j] = dp[i - 1][max(j - k, 0)];
        if (j + fs[i] <= l) {
          dp[i][j] = max(dp[i][j], ds[i] + dp[i - 1][j + fs[i]]);
        }
      }
    }

    /*
    for (int i = 0; i < min(n, 10); i++) {
      for (int j = 0; j < min(l, 10); j++) {
        printf("%i ", dp[i][j]);
      }
      printf("\n");
    }
    printf("\n");//*/

    printf("%i\n", dp[n - 1][0]);

    scanf(" %d %d %d", &n, &k, &l);
  }
}
