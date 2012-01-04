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

#define pb push_back
#define mp make_pair
#define nl cout << endl
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

ld sqr(ld x) { return x * x; }

const ld PI = 4 * atan(1);
 
int main() {
  int n, r, R;
  cin >> n >> R >> r;
  int rest = R - r;
  bool wrong = false;
  /*
  if (rest <= 1) {
    if (rest == 0 && n == 1) {
      cout << "YES" << endl;
      return 0;
    } else {
      wrong = true;
    }
  }
  ld ang = 2 * PI / n;
  ld x0 = rest, y0 = 0;
  ld x1 = cos(ang) * x0;
  ld y1 = -sin(ang) * x0;
  //ppn(x0); ppn(y0);
  //ppn(x1); ppn(y1); ppn(ang);
  //ppn(PI);
  ld dist = (sqr(x0 - x1) + sqr(y0 - y1));
  ld rr = 2 * r * 2 * r;
  //ppn(dist);
  //if (dist - 2 * r > -1e-15) {
  //if (dist > 2 * r || fabs(dist - 2 * r) <= 1e200) {
  if (dist > rr || fabs(dist - rr) <= 1e-10) {
  } else {
    wrong = true;
  }//*/
  ld radius = 2 * r / ld(2 * sin(PI / n));
  if (radius - rest > 1e-10) wrong = true;
  if (2 * r > R) wrong = true;
  if (rest >= 0 && n == 1) { wrong = false; }
  cout << (wrong ? "NO" : "YES") << endl;
} 

