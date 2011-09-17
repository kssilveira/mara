// http://acm.timus.ru/problem.aspx?space=1&num=1705

#include <cstdio>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>

using namespace std;

typedef long long ll;

const ll INF  = (ll)10e8;

int main() {
  int T;

  scanf("%d", &T);
  while (T--) {
    ll n;
    cin >> n;
    ll res = INF;
    ll resa = INF, resb = INF;

#if 0
    //*
    for (int n = 1; n < 200; n++) {
      printf("\n");
      for (int k = 1; k <= n; k++) {
        printf("%d / %d = %d --- %d\n", n, k, n / k, n % (k + 1));
        if (n / k == n / (k + 1)) {
          resa = k;
          // printf("%d: %d\n", n, k);
          // break;
        }
      }//*/
      for (int k = sqrt((double)n); ; k++) {
        if (n / k == n / (k + 1)) {
          resb = k;
          // printf("%d: %d\n", n, k);
          break;
        }
      }//*
      if (resa != resb) {
        printf("ERRRRRRRRRRR\n");
      }
    }//*/
#endif

    //*
    ll low = 1, high = n;
    while (low <= high) {
      ll cur = low + (high - low) / 2;
      // printf("low: %Ld, high: %Ld, cur: %Ld\n", low, high, cur);
      if (n / cur == n / (cur + 1)) {
        res = min(res, cur);
        high = cur - 1;
      } else if (n / cur > n / (cur + 1) + 1) {
        low = cur + 1;
      } else {
        high = cur - 1;
      }
    }//*/

    ll cur = low;
        for (ll i = cur; i >= 1; i--) {
          if (n / i > n / (i + 1) + 1) {
            break;
          } else if (n / i == n / (i + 1)) {
            res = min(res, i);
          }
        }
        for (ll i = cur + 1; i < res; i++) {
          if (n / i == n / (i + 1)) {
            res = min(res, i);
            break;
          }
        }

        resb = res;
    cout << resb << endl;
  }
}
