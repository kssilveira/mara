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
 
int main() {
  int n;
  ull d;
  ull x[200010], w[200010], nmax[200010], emax[200010];
  cin >> n >> d;
  ri {
    cin >> x[i] >> w[i];
  }
  nmax[n - 1] = w[n - 1];
  emax[n - 1] = n - 1;
  for (int i = n - 2; i >= 0; i--) {
    nmax[i] = w[i];
    emax[i] = i;
    if (nmax[i + 1] > nmax[i]) {
      nmax[i] = nmax[i + 1];
      emax[i] = emax[i + 1];
    }
  }
  /*
  ri {
    cout << nmax[i] << ' ';
  }
  cout << endl;//*/

  int beg = 0;
  int end = 1;
  ull res = 0;
  int resb = -2, rese = -2;
  while (beg < n - 1) {
    while (end < n && x[end] - x[beg] < d) end++;
    if (end < n) {
      ull cur = w[beg] + nmax[end];
      if (cur > res) {
        res = cur;
        resb = beg;
        rese = emax[end];
      }
    }
    beg++;
  }
  cout << resb + 1 << ' ' << rese + 1 << endl;
} 

