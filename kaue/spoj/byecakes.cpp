#include <cstdio>
#include <algorithm>

using namespace std;

int main() {
  int v[2][4];
  while (1) {
    for (int i = 0; i < 2; i++) {
      for (int j = 0; j < 4; j++) {
        scanf("%i", &v[i][j]);
      }
    }

    if (v[0][0] == -1) break;

    int n = 0;
    for (int i = 0; i < 4; i++) {
      n = max(n, (v[0][i] + v[1][i] - 1) / v[1][i]);
    }
    for (int i = 0; i < 4; i++) {
      if (i) { printf(" "); }
      printf("%i", n * v[1][i] - v[0][i]);
    }
    printf("\n");
  }
}
