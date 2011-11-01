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
#define ppp(x) p(pp(x))

#define in(x) cin >> x
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

ld sqr(ld x) { return x * x; }

ld dist(ld x1, ld y1, ld x2, ld y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}

#include <iomanip>
 
int main() {
  ld x1, x2, x3, y1, y2, y3;
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
    //ppn(ma);
    //ppn(mb);
    ld x = (ma * mb * (y1 - y3) + mb * (x1 + x2) - ma * (x2 + x3)) /
      (2 * (mb - ma));
    ld y;
    if (ma != 0) {
      y = (-1 / ma) * (x - (x1 + x2) / 2) + (y1 + y2) / 2;
    } else {
      y = (-1 / mb) * (x - (x2 + x3) / 2) + (y2 + y3) / 2;
    }
    ld r = dist(x, y, x1, y1);
    //ppn(x);
    //ppn(y);
    if (x != 0) {
      cout << "(x " << (x < 0 ? "+ " : "- ") << fixed << setprecision(3)
      << fabs(x) << ")^2 + ";
    } else {
      cout << "x^2 + ";
    }
    if (y != 0) {
      cout << "(y " << (y < 0 ? "+ " : "- ") << fixed << setprecision(3)
        << fabs(y) << ")^2 = ";
    } else {
      cout << "y^2 = ";
    }
    if (r != 0) {
      cout << fixed << setprecision(3) << r << "^2" << endl;
    } else {
      cout << "0" << endl;
    }

    ld c = -2 * x;
    ld d = -2 * y;
    ld e = x * x + y * y - r * r;
    cout << "x^2 + y^2 ";
    if (c != 0) {
      cout << (c < 0 ? "- " : "+ ") << fixed
        << setprecision(3) << fabs(c) << "x ";
    }
    if (d != 0) {
      cout << (d < 0 ? "- " : "+ ") << fixed
        << setprecision(3) << fabs(d) << "y ";
    }
    if (e != 0) {
      cout << (e < 0 ? "- " : "+ ") << fixed
        << setprecision(3) << fabs(e) << " = 0" << endl;
    }
    cout << endl;
  }
} 

