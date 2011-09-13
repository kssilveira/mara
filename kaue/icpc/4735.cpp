#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int a, b;
  scanf("%i %i", &a, &b);
  int T = 0;
  while (a != 0 || b != 0) {
    T++;
    int res1 = 0, res2 = 0;
    for (int i = 2; i <= a || i <= b; i++) {
      int va = 0, vb = 0;
      while (a % i == 0) {
        va++;
        a /= i;
      }
      while (b % i == 0) {
        vb++;
        b /= i;
      }
      if (va != 0 || vb != 0) {
        res1++;
        if (va >= vb) {
          res2 += va - vb;
        } else {
          res2 += vb - va;
        }
      }
    }
    printf("%i. %i:%i\n", T, res1, res2);
    scanf("%i %i", &a, &b);
  }
}
