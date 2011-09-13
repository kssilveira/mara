#include <cstdio>
#include <iostream>
#include <bitset>
#include <cstring>

using namespace std;

bitset<1001> mat[1001];
int sum[1001][1001];
char str[10000];

int main() {
  int n, m;
  scanf(" %i %i", &n, &m);

  while (n != 0 || m != 0) {
    
    fgets(str, 10000, stdin);
    while ((int) strlen(str) != 2 * (m - 1) + 3) {
      fgets(str, 10000, stdin);
    }

    for (int i = 0; i < n; i++) {
      if (i) fgets(str, 10000, stdin);
      // printf("str[%i]: '%s'\n", i, str);
      for (int j = 0; j < m; j++) {
        mat[i][j] = str[2 * j] - '0';
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

    sum[0][0] = mat[0][0];
    for (int i = 1; i < n; i++) {
      sum[i][0] = sum[i - 1][0] + mat[i][0];
    }
    for (int j = 1; j < m; j++) {
      sum[0][j] = sum[0][j - 1] + mat[0][j];
    }
    for (int i = 1; i < n; i++) {
      for (int j = 1; j < m; j++) {
        sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] +
          mat[i][j];
      }
    }

    /*
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        printf("%5Li ", sum[i][j]);
      }
      printf("\n");
    }
    printf("\n");//*/

    int res = 0;

  int a = 1, b = min(n, m);

  while (a < b) {
    int k = a + (a + b) / 2;

    bool found = false;


    for (int i = 0; i + k < n; i++) {
          int j = 0;
          int ni = i + k,
              nj = j + k;
          if (ni >= n || nj >= m) break;
          // int val = sum[ni][nj] - sum[i - 1][nj];
          // printf("(%i, %i) to (%i, %i) = %i\n", i, j, ni, nj, val);
          if (sum[ni][nj] - sum[i - 1][nj] == (k + 1) * (k + 1)) {
            res = max(res, k + 1);
            found = true;
          }
    }

    //*
      for (int j = 0; j + k < m; j++) {
          int i = 0;
          int ni = i + k,
              nj = j + k;
          if (ni >= n || nj >= m) break;
          if (sum[ni][nj] - sum[ni][j - 1] == (k + 1) * (k + 1)) {
            found = true;
            res = max(res, k + 1);
          }
      }

    for (int i = 0; i + k < n; i++) {
      for (int j = 0; j + k < m; j++) {
          int ni = i + k,
              nj = j + k;
          if (ni >= n || nj >= m) break;
          if (sum[ni][nj] - sum[i - 1][nj] - sum[ni][j - 1] +
              sum[i - 1][j - 1] == (k + 1) * (k + 1)) {
            found = true;
            res = max(res, k + 1);
          }
      }
    }//*/

    if (found) {
      a = k + 1;
    } else {
      b = k - 1;
    }
    
  }
    
    printf("%i\n", res);

    scanf(" %i %i", &n, &m);
  }
}
