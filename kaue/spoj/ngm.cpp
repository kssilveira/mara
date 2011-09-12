#include <cstdio>
int main() {
  int n;
  scanf("%i", &n);
  int d = n % 10;
  if (d) {
    printf("1\n%i\n", d);
  } else {
    printf("2\n");
  }
}
