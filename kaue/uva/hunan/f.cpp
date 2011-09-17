#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long double dp[1001][101][10];

vector<int> p1, p2, t1, t2, w1, w2;

#define INF 10e7

long double calc(int n, int p) {
  if (p < p1[n]) {
    return INF;
  }
  if (p > p2[n]) {
    return t2[n];
  }
  return (((long double)p - p1[n]) / ((long double) p2[n] - p1[n])) *
    ((long double)t2[n] - t1[n]) + t1[n];
}

int main() {
  int n, p;
  cin >> n >> p;
  while (n != 0 || p != 0) {

    p1.resize(n);
    p2.resize(n);
    t1.resize(n);
    t2.resize(n);
    w1.resize(n);
    w2.resize(n);

    for (int i = 0; i < n; i++) {
      cin >> p1[i] >> p2[i] >> t1[i] >> t2[i] >> w1[i] >> w2[i];
    }

    for (int j = 1; j <= 100; j++) {
      for (int k = 0; k < 8; k++) {
        dp[n - 1][j][k] = calc(n - 1, j);
      }
    }

    for (int i = n - 2; i >= 0; i--) {
      for (int j = 1; j <= 100; j++) {
        for (int k = 0; k < 8; k++) {
          int np = j + w1[i];
          if (np > 100) {
            np = 100;
          }
          int nw = k + w2[i];
          if (nw > 7) {
            nw = 7;
          }
          long double nmin = INF;
          for (int w = 0; w <= nw; w++) {
            nmin = min(nmin, dp[i + 1][np][nw - w]);
            np *= 2;
            if (np > 100) {
              np = 100;
            }
          }
          if (nmin < INF - 1) {
            dp[i][j][k] = nmin + calc(i, j);
          } else {
            dp[i][j][k] = INF;
          }
        }
      }
    }

    /*
    for (int i = 0; i < n; i++) {
      printf("i: %d\n", i);
      for (int j = 1; j <= 100; j++) {
        for (int k = 0; k < 8; k++) {
          printf("%5.02Lf ", dp[i][j][k] != INF ? dp[i][j][k] : -1);
        }
        printf("\n");
      }
      printf("################\n");
    }//*/

    if (dp[0][p][0] < INF - 1) {
      // cout << dp[0][p][0] << endl;
      printf("%.2Lf\n", dp[0][p][0]);
    } else {
      cout << "Impossible" << endl;
    }

    cin >> n >> p;
  }
}
