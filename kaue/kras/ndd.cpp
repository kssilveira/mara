#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int T;
  scanf("%i", &T);

  unsigned long long pd[65][10];

  for (int i = 0; i < 10; i++) {
    pd[0][i] = 1;
  }

  for (int i = 1; i < 65; i++) {
    for (int j = 0; j < 10; j++) {
      pd[i][j] = 0;
      for (int k = j; k < 10; k++) {
        pd[i][j] += pd[i - 1][k];
      }
    }
  }

  /*
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      printf("%Lu ", pd[i][j]);
    }
    printf("\n");
  }
  printf("\n");//*/

  while (T--) {
    int t, n;
    scanf(" %d %d", &t, &n);
    printf("%d %Lu\n", t, pd[n][0]);
  }
}

