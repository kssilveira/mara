#include <cstdio>
#include <iostream>

using namespace std;

int mat[1001][1001];
int sum[1001][1001];

int main() {
  int n, m;
  scanf(" %i %i", &n, &m);

  while (n != 0 || m != 0) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int v;
        scanf(" %d", &v);
        mat[i][j] = v;
      }
    }

    /*
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%i ", (int) mat[i][j]);
      }
      printf("\n");
    }
    printf("\n");//*/

    int res = 0;

    sum[0][0] = mat[0][0];
    res = max(res, sum[0][0]);
    for (int i = 1; i < n; i++) {
      sum[i][0] = mat[i][0];
      res = max(res, sum[i][0]);
    }
    for (int j = 1; j < m; j++) {
      sum[0][j] = mat[0][j];
      res = max(res, sum[0][j]);
    }

    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        if (mat[i][j] == 0) {
          sum[i][j] = 0;
        } else {
          sum[i][j] = min(sum[i][j - 1],
                      min(sum[i - 1][j], sum[i - 1][j - 1])) + 1;
          res = max(res, sum[i][j]);
        }
      }
    }

    /*
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%d ", sum[i][j]);
      }
      printf("\n");
    }
    printf("\n");//*/

    printf("%i\n", res);

    scanf(" %i %i", &n, &m);
  }
}
