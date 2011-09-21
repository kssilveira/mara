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

ld v, h;

ld f(ld vy) {
  const ld g = 9.8;
  ld t = (vy + sqrt(vy * vy + 2 * g * h)) / g;
  ld vx = sqrt(v * v - vy * vy);
  return vx * t;
}
 
int main() {
  int vv, hh;
  while (scanf("%d%d", &vv, &hh) && vv != -1) {
    v = vv, h = hh;
    ld left = 0, right = v;
    // ppn(left);
    // ppn(right);
    while (right - left > 1e-7) {
      ld lthird = (2 * left + right) / 3;
      ld rthird = (left + 2 * right) / 3;
      // ppn(lthird);
      // ppn(rthird);
      // ppn(f(lthird));
      // ppn(f(rthird));
      if (f(lthird) < f(rthird)) {
        left = lthird;
      } else {
        right = rthird;
      }
    }
    printf("%.6Lf\n", f(left));
  }
} 

