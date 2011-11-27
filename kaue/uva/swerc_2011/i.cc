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

const ld PI = 4 * atan(1);

ld sqr(ld x) { return x * x; }

ld dist(ld xa, ld ya, ld xb, ld yb) {
  return sqrt(sqr(xa - xb) + sqr(ya - yb));
}

ld getdeg(ld xa, ld ya, ld xb, ld yb, ld xc, ld yc) {
  //ppn(xa); ppn(ya); ppn(xb); ppn(yb); ppn(xc); ppn(yc);
  ld vx = xb - xa, vy = yb - ya,
     wx = xc - xa, wy = yc - ya;
  ld vnorm = dist(0, 0, vx, vy);
  ld wnorm = dist(0, 0, wx, wy);
  vx /= vnorm; vy /= vnorm;
  wx /= wnorm; wy /= wnorm;
  ld res = vx * wx + vy * wy;
  res = acos(res);
  if (wy < 0) {
    res = -res;
  }
  if (res < 0) {
    res += 2 * PI;
  }
  return res;
}

const ld EPS = 1e-6;

bool ismult(ld a, ld b) {
  return (fabs(round(a / b) - a / b) <= EPS);
}
 
int main() {
  ld x1, x2, x3, y1, y2, y3;
  //ppn(PI);
  while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
    if (x2 == x1) {
      swap(x2, x3);
      swap(y2, y3);
    }
    if (x3 == x2) {
      swap(x2, x1);
      swap(y2, y1);
    }
    assert(x2 != x1 && x3 != x2);
    ld ma = (y2 - y1) / (x2 - x1);
    ld mb = (y3 - y2) / (x3 - x2);
    ld x = (ma * mb * (y1 - y3) + mb * (x1 + x2) - ma * (x2 + x3)) /
      (2 * (mb - ma));
    ld y;
    if (ma != 0) {
      y = (-1 / ma) * (x - (x1 + x2) / 2) + (y1 + y2) / 2;
    } else {
      y = (-1 / mb) * (x - (x2 + x3) / 2) + (y2 + y3) / 2;
    }
    ld r = dist(x, y, x1, y1);
    //ppn(x); ppn(y); ppn(r);
    ld a = getdeg(x, y, x + 1, y, x1, y1);
    ld b = getdeg(x, y, x + 1, y, x2, y2);
    ld c = getdeg(x, y, x + 1, y, x3, y3);
    //ppn(a); ppn(b); ppn(c);
    ld v[] = {a, b, c};
    sort(v, v + 3);
    for (int i = 3; ; i++) {
      ld delta = 2 * PI / i;
      if (ismult(v[1] - v[0], delta) &&
          ismult(v[2] - v[1], delta) &&
          ismult(v[0] - v[2] + 2 * PI, delta)) {
        printf("%d\n", i);
        break;
      }
    }
  }
} 

