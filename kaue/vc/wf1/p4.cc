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
#define nl cout << endl
#define mp make_pair
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
 
int main() {
  int n, v;
  cin >> n >> v;
  ld alpha[10010];
  vector<pair<ld, int> > vetalpha;
  ri {
    cin >> alpha[i];
    vetalpha.pb(mp(alpha[i], i));
  }
  sort(alpha, alpha + n);
  sort(all(vetalpha));
  int m;
  cin >> m;
  ld x[100010], y[100010];
  vector<pair<ld, ld> > vet;
  rim {
    cin >> x[i] >> y[i];
    vet.pb(mp(x[i], y[i]));
  }
  sort(all(vet));
  rim {
    x[i] = vet[i].first;
    y[i] = vet[i].second;
  }
  const ld g = 9.8;

  int L = 0, R = n - 1;
  ld resx[10010] = {0}, resy[10010] = {0};
  rjm {
    for (; L <= R; L++) {
      int i = L;
      ld t = x[j] / (v * cos(alpha[i]));
      ld yt = v * sin(alpha[i]) * t - g * t * t / 2;
      if (y[j] > yt) {
        resx[vetalpha[i].second] = x[j];
        resy[vetalpha[i].second] = yt;
        if (yt < 0.0) {
          t = v * sin(alpha[i]) * 2 / g;
          ld xt = v * cos(alpha[i]) * t;
          resx[vetalpha[i].second] = xt;
          resy[vetalpha[i].second] = 0.0;
        }
        //cout << fixed << setprecision(9) << x[j] << ' '
          //<< yt << endl;
      } else break;
    }
    for (; L <= R; R--) {
      int i = R;
      ld t = x[j] / (v * cos(alpha[i]));
      ld yt = v * sin(alpha[i]) * t - g * t * t / 2;
      if (y[j] > yt) {
        resx[vetalpha[i].second] = x[j];
        resy[vetalpha[i].second] = yt;
        if (yt < 0.0) {
          t = v * sin(alpha[i]) * 2 / g;
          ld xt = v * cos(alpha[i]) * t;
          resx[vetalpha[i].second] = xt;
          resy[vetalpha[i].second] = 0.0;
        }
        //cout << fixed << setprecision(9) << x[j] << ' '
          //<< yt << endl;
      } else break;
    }
  }
  for ( ; L <= R; L++) {
    int i = L;
      ld t = v * sin(alpha[i]) * 2 / g;
      ld xt = v * cos(alpha[i]) * t;
        resx[vetalpha[i].second] = xt;
        resy[vetalpha[i].second] = 0.0;
      //cout << fixed << setprecision(9) << xt << ' ' << 0.0 << endl;
  }
  ri {
    cout << fixed << setprecision(9) << resx[i] << ' ' << resy[i] << endl;
  }
  /*
  ri {
    bool found = false;
    rjm {
      ld t = x[j] / (v * cos(alpha[i]));
      ld yt = v * sin(alpha[i]) * t - g * t * t / 2;
      //if (yt <= y[j]) {
      if (yt >= EPS && y[j] - yt >= EPS) {
        found = true;
        cout << fixed << setprecision(9) << x[j] << ' '
          << yt << endl;
        break;
      }
      if (yt <= EPS) {
        break;
      }
    }
    if (!found) {
      ld t = v * sin(alpha[i]) * 2 / g;
      ld xt = v * cos(alpha[i]) * t;
      cout << fixed << setprecision(9) << xt << ' ' << 0.0 << endl;
    }
  }//*/
} 

