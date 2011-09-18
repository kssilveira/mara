#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

typedef long double ld;

ld l, s, r;

ld last[19][1 << 18];

ld solve(int n, int mask, int depth) {
  ld res = 0;
  if (depth > 2 * n) return 0;
  if (n == 1) {
    // return 1./ max(l, max(s, r));
    return max(l, max(s, r));
  }
  for (int i = 0; i < n; i++) {
    ld& cur = last[n][mask];
    int maskl = mask;
    int dl = 0;
    int masks = mask;
    int ds = 0;
    int maskr = mask;
    int dr = 0;

    if (i > 0) {
      if (mask & (1 << (i - 1))) dl = 1;
      maskl = mask & ~(1 << (i - 1));
    }
    if (mask & (1 << i)) {
      ds = 1;
    }
    masks = mask & ~(1 << i);
    if (i < n - 1) {
      if (mask & (1 << (i + 1))) {
        dr = 1;
      }
      maskr = mask & ~(1 << (i + 1));
    }

    cur += 1./ (l * solve(n - dl, maskl, depth + 1));
     // cur += (l * solve(n - dl, maskl, depth + 1));
    cur += 1./ (s * solve(n - ds, masks, depth + 1));
     // cur += (s * solve(n - ds, masks, depth + 1));
    cur += 1. / (r * solve(n - dr, maskr, depth + 1));
     // cur += (r * solve(n - dr, maskr, depth + 1));

    res = max(res, cur);
  }
  return res;
}

int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(last, 0, sizeof(last));
    int n;
    cin >> n >> l >> s >> r;
    l /= 100;
    s /= 100;
    r /= 100;
    for (int i = 0; i < 100; i++) {
      ld res = solve(n, (1 << n) - 1, 0);
      cout << res << endl;
      cout << 1 / res << endl;
      cout << endl;
    }
  }
}
