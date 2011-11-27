#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <utility>
#include <vector>
 
#define r(i, n) rb(i, 0, n)
#define rb(i, b, n) rbc(i, b, n, <)
#define re(i, n) rbe(i, 0, n)
#define rbe(i, b, n) rbc(i, b, n, <=)
#define rbc(i, b, n, c) for(int i = (b); i c ((int)(n)); i++)
 
#define ri r(i, n)
#define rj r(j, n)
#define rk r(k, n)
#define rim r(i, m)
#define rjm r(j, m)
#define rkm r(k, m)

#define p(x) cout << x << " "
#define pl cout << endl
#define pn(x) cout << x << endl
#define pv(v) ri { p(v[i]); } pl;
#define pm(m) ri { rjm { p(m[i][j]); } pl; } pl;
#define pp(x) " "#x" " << x
#define ppn(x) pn(pp(x))
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

ld f(int n, int d, ld p) {
  if (n == 0) {
    if (d == 0) {
      return p * p / (1 - 2 * p * (1 - p));
    }
    if (d == 1 || d == -1) {
      return p * f(n, d + 1, p) +
        (1 - p) * f(n, d - 1, p);
    }
    if (d >= 2) {
      return 1;
    }
    if (d <= -2) {
      return 0;
    }
    assert(false);
    return 0;
  }
  if (d <= -max(n, 2)) {
    return 0;
  }
  return p * f(n - 1, d + 1, p) +
    (1 - p) * f(n, d - 1, p);
}
 
ld g(int n, int d, ld p, ld tie) {
  //printf("g(%d, %d)\n", n, d);
  if (n <= 0) {
    if (d == 0 && n == 0) {
      return tie;
    }
    if (d == 0 || d == 1 || d == -1) {
      return p * g(n - 1, d + 1, p, tie) +
        (1 - p) * g(n, d - 1, p, tie);
    }
    if (d >= 2) {
      return 1;
    }
    if (d <= -2) {
      return 0;
    }
    assert(false);
    return 0;
  }
  if (d <= -max(n, 2)) {
    return 0;
  }
  return p * g(n - 1, d + 1, p, tie) +
    (1 - p) * g(n, d - 1, p, tie);
}

ld ff(int a, int b, ld p, int k) {
  if (a == b && a >= k) {
    return p * p / (1 - 2 * p * (1 - p));
  }
  if (a >= k && a - b >= 2) return 1;
  if (b >= k && b - a >= 2) return 0;
  return p * ff(a + 1, b, p, k) +
    (1 - p) * ff(a, b + 1, p, k);
}

ld gg(int a, int b, ld p, ld tie) {
  if (a == 6 && b == 6) {
    return tie;
  }
  if (a >= 6 && a - b >= 2) return 1;
  if (b >= 6 && b - a >= 2) return 0;
  return p * gg(a + 1, b, p, tie) +
    (1 - p) * gg(a, b + 1, p, tie);
}
 
int main() {
  ld p;
  while (scanf("%Lf", &p) && p > -0.5) {
    //ppn(p);
    ld resa = f(4, 0, p);
    ld tiebreak = f(7, 0, p);
    ld resb = g(6, 0, resa, tiebreak);
    ld resc = resb * resb + resb * resb * (1 - resb) * 2;

    ld resaa = ff(0, 0, p, 4);
    ld tiee = ff(0, 0, p, 7);
    ld resbb = gg(0, 0, resaa, tiee);
    //printf("tie %.11Lf (%.11Lf)\n", tiebreak, tiee);
    printf("%.11Lf %.11Lf %.11Lf\n", resa, resb, resc);
    //printf("%.11Lf %.11Lf\n", resaa, resbb);
    
  }
} 

