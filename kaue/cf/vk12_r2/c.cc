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
 
int main() {
  int n, l, v1, v2;
  cin >> n >> l >> v1 >> v2;
  ld tend = l / ld (v1 + v2);
  //ppn(tend);
  ld dist = v2 * tend;
  //ppn(dist);

  ld a[300030];
  ri {
    cin >> a[i];
    //ppn(a[i]); ppn(delta);
    //ppn(dist);
    //ppn(a[i]);
    //ppn(a[i]);
    a[i + n] = a[i] + 2 * l;
    a[i + 2 * n] = a[i + n] + 2 * l;
    //ppn(a[i]);
  }
  ld res[100010];
  int first = 0;
  ld cur = max(ld(0), a[first] - dist);
  ld end = cur + 2 * l;
  rb(i, 1, 3 * n) {
    if (cur >= end) {
      break;
    }
    //ppn(i); ppn(a[i]); ppn(cur);
    if (a[i] - cur > dist) {
      ld other = a[i] - dist;
      //if (other > 2 * l) {
        //other = 2 * l;
      //}
      //ppn(other);
      if (other < a[first]) {
        res[i - first] += (min(other, ld(end)) - cur);
        cur = other;
      } else {
        //ppn(i - first);
        //if (first < n ) {
          res[i - first] += (min(a[first], ld(end)) - cur);
        //}
        if (min(other, ld(end)) >  a[first]) {
          res[i - first - 1] += (min(other, ld(end)) - a[first]);
        }
        cur = other;
        while (a[first] < other) {
          first++;
        }
      }
    }
    if (i < first) {
      i = first;
    }
  }
  r(i, n + 1) {
    cout << fixed << setprecision(20) << res[i] / (2 * l) << endl;
  }
  /*
  while (first < n) {
    res[n - first] += (a[first] - cur);
    cur = a[first];
  }//*/
} 
