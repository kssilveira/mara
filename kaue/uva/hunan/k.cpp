#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

vector<int> e;
vector<int> vmin;

int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  e.resize(n);
  int bk = (int) sqrt(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &e[i]);
  }

  while (n % bk != 0) {
    n++;
    e.push_back(100100);
  }

  int s = n / bk;
  vmin.resize(s);

  for (int i = 0; i < s; i++) {
    int delta = i * bk;
    vmin[i] = e[delta];
    for (int j = 1; j < bk; j++) {
      vmin[i] = min(vmin[i], e[delta + j]);
    }
  }

  // operations
  for (int i = 0; i < q; i++) {

    /*
    printf("bk: %d, e: ", bk);
    for (int i = 0; i < n; i++) {
      printf("%d ", e[i]);
    }
    printf("\n");

    printf("vmin: ");
    for (int i = 0; i < s; i++) {
      printf("%d ", vmin[i]);
    }
    printf("\n");//*/

    int a, b;
    if (scanf(" query(%d,%d)", &a, &b)) {
      // printf("query(%d,%d)\n", a, b);
      a--;
      b--;
      //process query
      int res = 100100;
      for (int i = a; i <= b && i % bk != 0; i++) {
        res = min(res, e[i]);
      }
      for (int i = (a + bk - 1) / bk; i < b / bk; i++) {
        res = min(res, vmin[i]);
      }
      for (int i = max(a, (b / bk) * bk); i <= b; i++) {
        res = min(res, e[i]);
      }
      cout << res << endl;
    } else {
      scanf("shift(");
      vector<int> shift;
      int v;
      while(scanf("%d,", &v)) {
        shift.push_back(v);
      }
      shift.push_back(shift[0]);
      scanf(")");

      /*
      printf("shift(");
      for (int i = 0; i < (int) shift.size(); i++) {
        printf("%d,", shift[i]);
      }
      printf("\n");//*/

      // process shift
      int e0 = e[shift[0] - 1];
      for (int i = 1; i < (int) shift.size(); i++) {
        int& first = e[shift[i - 1] - 1],
            second = e[shift[i] - 1];
        if (i == ((int) shift.size()) - 1) {
          second = e0;
        }
        int ind = (shift[i - 1] - 1) / bk;
        if (first == vmin[ind]) {
          first = second;
          int nmin = second;
          for (int i = 0; i < bk; i++) {
            nmin = min(nmin, e[ind * bk + i]);
          }
          vmin[ind] = nmin;
        }
        if (second < vmin[ind]) {
          vmin[ind] = second;
        }
        first = second;
      }
    }
  }
}
