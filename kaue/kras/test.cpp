//Timus-1587

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

int v[1000];

void generate(int cur, int n) {
  if (cur == n) {
    ll res = v[0];
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
        ll prod = 1;
        for (int k = i; k <= j; k++) {
          prod *= v[k];
        }
        res = max(res, prod);
      }
    }
    FILE *f = fopen("in.txt", "w");
    fprintf(f, "%d\n", n);
    for (int i = 0; i < n; i++) {
      fprintf(f, "%d ", v[i]);
    }
    fprintf(f, "\n");
    fflush(f);
    fclose(f);

    system("./Timus-1587 < in.txt > out.txt");
    
    f = fopen("out.txt", "r");
    ll given;
    fscanf(f, "%Ld", &given);
    fflush(f);
    fclose(f);

    if (given != res) {
      printf("ERRRRRRRRRRRRRRRRRRR\n");
      printf("generated: ");
      for (int i = 0; i < n; i++) {
        printf("%d ", v[i]);
      }
      printf("\n");
      printf("res: %Ld\n", res);
    }

    return;
  }
  for (int i = -2; i <= 2; i++) {
    v[cur] = i;
    if (cur == 0) {
      printf("%d\n", v[cur]);
    }
    generate(cur + 1, n);
  }
}

int main() {
  generate(0, 9);
}
