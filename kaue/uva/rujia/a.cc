#include <algorithm>
#include <iomanip>
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

inline ld sqr(ld x) { return x * x; }
 
int main() {
  int XA, YA, XB, YB, n;
  const ld PI = atan(1) * 4;
  //ppn(PI);
  while (cin >> XA >> YA >> XB >> YB >> n && n != 0) {
    ld xa = XA, ya = YA, xb = XB, yb = YB;
    //ld deltaalpha = PI / n;
    ld deltaalpha = 2 * PI / n;
    //ppn(n); ppn(deltaalpha);
    // ld alpha = deltaalpha;
    ld alpha = 0;
    ld co = sqrt(sqr(xa - xb) + sqr(ya - yb)) / 2;
    //ppn(co);
    ld res = 1e100;
    // rb(i, 1, 2 * n - 2) {
    rb(i, 1, n) {
      alpha += deltaalpha;
      //ppn(alpha);
      ld ralpha = min(alpha, 2 * PI - alpha);
      //ppn(ralpha);
      ld r = co / sin(ralpha / 2);
      //ppn(r);
      ld s = r * 2 * sin(PI / n);
      //ppn(s);
      ld a = n * s * s / (tan(PI / n) * 4);
      //ppn(a);
      if (a < res) res = a;
    }
    alpha += deltaalpha;
    //ppn(alpha);
    cout << showpoint << setprecision(10) << res << endl;
  }
} 

