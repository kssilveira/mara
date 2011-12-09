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

ll x[10], y[10];

ll sqr(ll x) { return x * x; }

ll dist(int i, int j) {
  return sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
}

ll ang(int i, int j, int k) {
  ll x1 = x[j] - x[i], x2 = x[k] - x[i];
  ll y1 = y[j] - y[i], y2 = y[k] - y[i];
  return x1 * x2 + y1 * y2;
}

int main() {
  int n = 8;
  ri {
    cin >> x[i] >> y[i];
  }
  int p[10];
  ri {
    p[i] = i;
  }
  do {
    //ri {
      //cout << p[i] << ' ';
    //}
    //nl;
    ll dist1[10], dist2[10];
    ll ang1[10], ang2[10];
    r(i, 4) {
      dist1[i] = dist(p[i], p[(i + 1) % 4]);
      ang1[i] = ang(p[i], p[(i + 1) % 4], p[(i + 3) % 4]);
      dist2[i] = dist(p[i + 4], p[(i + 1) % 4 + 4]);
      ang2[i] = ang(p[i + 4], p[(i + 1) % 4 + 4], p[(i + 3) % 4 + 4]);
    }
    if (dist1[0] == dist1[1] && dist1[1] == dist1[2] && dist1[2] == dist1[3]) {
      if (dist2[0] == dist2[2] && dist2[1] == dist2[3]) {
        bool found = false;
        r(i, 4) {
          if (ang1[i] != 0) found = true;
          if (ang2[i] != 0) found = true;
        }
        if (!found) {
          cout << "YES" << endl;
          r(i, 4) {
            if (i) cout << ' ';
            cout << p[i] + 1;
          }
          cout << endl;
          r(i, 4) {
            if (i) cout << ' ';
            cout << p[i + 4] + 1;
          }
          cout << endl;
          return 0;
        }
      }
    }
  } while (next_permutation(p, p + n));

  cout << "NO" << endl;
} 

