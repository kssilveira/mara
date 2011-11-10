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

const ld EPS = 1e-300;
 
int main() {
  ll t1, t2, x1, x2, t0;
  cin >> t1 >> t2 >> x1 >> x2 >> t0;
  if (t1 == t0 && t2 == t0) {
    cout << x1 << ' ' << x2 << endl;
    return 0;
  }
  if (t2 == t0) {
    cout << 0 << ' ' << x2 << endl;
    return 0;
  }
  if (t1 == t0) {
    cout << x1 << ' ' << 0 << endl;
    return 0;
  }
  ll y1, y2;
  ld mindist = 1e200;
  ll maxvel = -1;
  ll best1 = 0, best2 = 1;
  ll best[2];
r(T, 2) {
  for (y1 = x1; y1 >= 0; y1--) {
    //ppn(y1);
    y2 = ceil((t0 * y1 - t1 * y1) / ld(t2 - t0));
    //ppn(y2);
    if (y1 == 0 && y2 == 0) continue;
    ld t = (t1 * y1 + t2 * y2) / ld(y1 + y2);
    //ppn(t);
    if (EPS < t0 - t || y2 < 0 || y2 > x2) {
      y2 = floor((t0 * y1 - t1 * y1) / ld(t2 - t0));
      if (y1 == 0 && y2 == 0) continue;
      t = (t1 * y1 + t2 * y2) / ld(y1 + y2);
      if (EPS < t0 - t || y2 < 0 || y2 > x2) continue;
    }
    //ppn(t);
    //ppn(t0);
    //ppn(t1);
    //ppn(t2);
    ld dist = t - t0;
    ll vel = y1 + y2;
    if (EPS < mindist - dist ||
        (fabs(dist - mindist) < EPS && vel > maxvel)) {
      //ppn(dist);
      //ppn(vel);
      //ppn(y1);
      //ppn(y2);
      mindist = dist;
      maxvel = vel;
      best[best1] = y1;
      best[best2] = y2;
    }
  }
  for (y1 = x1; y1 >= 0; y1--) {
    y2 = floor((t0 * y1 - t1 * y1) / ld(t2 - t0));
    if (y1 == 0 && y2 == 0) continue;
    ld t = (t1 * y1 + t2 * y2) / ld(y1 + y2);
    if (EPS < t0 - t || y2 < 0 || y2 > x2) {
      y2 = ceil((t0 * y1 - t1 * y1) / ld(t2 - t0));
      if (y1 == 0 && y2 == 0) continue;
      t = (t1 * y1 + t2 * y2) / ld(y1 + y2);
      if (EPS < t0 - t || y2 < 0 || y2 > x2) continue;
    }
    //ppn(t);
    //ppn(t0);
    //ppn(t1);
    //ppn(t2);
    ld dist = t - t0;
    ll vel = y1 + y2;
    if (EPS < mindist - dist ||
        (fabs(dist - mindist) < EPS && vel > maxvel)) {
      //ppn(dist);
      //ppn(vel);
      //ppn(y1);
      //ppn(y2);
      mindist = dist;
      maxvel = vel;
      best[best1] = y1;
      best[best2] = y2;
    }
  }

  swap(x1, x2);
  swap(y1, y2);
  swap(t1, t2);
  swap(best1, best2);
}
  cout << best[0] << ' ' << best[1] << endl;
} 

