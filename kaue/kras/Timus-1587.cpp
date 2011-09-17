// http://acm.timus.ru/problem.aspx?space=1&num=1587
// wrong answer, possible reason: bignum

#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll v[50002];

int main() {
  int n;
  scanf("%d", &n);
  bool hasZero = false;
  for (int i = 0; i < n; i++) {
    scanf("%lld", &v[i]);
    if (v[i] == 0) {
      hasZero = true;
    }
  }
  v[n] = 0;
  int begin = -1, end = -1, firstNegative = -1, lastNegative = -1;
  ll prod = 1;
  ll res = v[0];
  for (int i = 0; i <= n; i++) {
    if (v[i] != 0 && begin == -1) {
      begin = i;
    }
    if (v[i] != 0) {
      prod *= v[i];
      res = max(prod, res);
    }
    if (v[i] < 0 && firstNegative == -1) {
      firstNegative = i;
    }
    if (v[i] < 0) {
      lastNegative = i;
    }
    if (v[i] == 0 && begin != -1) {
      int last = i;
      // solve begin, last
      if (prod < 0 && begin != i - 1) {
        ll temp = 1;
        for (int i = begin; i <= firstNegative; i++) {
          temp *= v[i];
        }
        res = max(res, prod / temp);
        if (firstNegative != begin) {
          res = max(res, temp / v[firstNegative]);
        }
        temp = 1;
        for (int i = lastNegative; i < last; i++) {
          temp *= v[i];
        }
        res = max(res, prod / temp);
        if (lastNegative != last - 1) {
          res = max(res, temp / v[lastNegative]);
        }
      }
      // end
      begin = end = firstNegative = lastNegative = -1;
      prod = 1;
    }
  }

  if (hasZero) {
    res = max(0LL, res);
  }

  printf("%lld\n", res);
}
