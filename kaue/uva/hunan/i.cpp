// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=244&page=show_problem&problem=3718
// TODO: closed formula for the recursion.

#include <iostream>

using namespace std;

typedef long long ull;

#define MOD 1000000009

ull count(ull k, ull n, ull c) {
  // cout << "count(" << k << ", " << n << ", " << c << ")" << endl;
  if (n == 0) return 1;
  if (k > n || c < 0) return 0;
  ull res = 0;
  ull v[] = {1, 4, 6, 4, 1};
  for (int i = 0; i < 5 && n - i * k >= 0 && c - i >= 0; i++) {
    res += v[i] * count(k + 1, n - i * k, c - i);
    res %= MOD;
  }
  return res;
}

int main() {
  ull n, k;
  cin >> n >> k;
  while (n != 0 || k != 0) {
    cout << count(1, n, k) << endl;

    cin >> n >> k;
  }
}
