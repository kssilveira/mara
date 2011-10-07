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

void pot(int a, int x) {
  ppn(a); ppn(x);
  int res = 1;
  while (x) {
    if (x & 1) {
      res *= a;
    }
    a *= a;
    x >>= 1;
  }
  ppn(res); 
}
ull a[20][20] = {{0}};
ull res[20][20], sol[20][20];
int d;
int MOD;

void mat_pow(int x) {
  // res = 1;
  r(i, d) {
    r(j, d) {
      res[i][j] = 0;
    }
    res[i][i] = 1;
  }
  while(x) {
    if (x & 1) {
      // res *= a;
      r(i, d) {
        r(j, d) {
          sol[i][j] = 0;
          r(k, d) {
            sol[i][j] += res[i][k] * a[k][j];
            sol[i][j] %= MOD;
          }
        }
      }
      r(i, d) {
        r(j, d) {
          res[i][j] = sol[i][j];
        }
      }
    }
    // a *= a;
      r(i, d) {
        r(j, d) {
          sol[i][j] = 0;
          r(k, d) {
            sol[i][j] += a[i][k] * a[k][j];
            sol[i][j] %= MOD;
          }
        }
      }
      r(i, d) {
        r(j, d) {
          a[i][j] = sol[i][j];
        }
      }
    x >>= 1;
  }
}
 
int main() {
  int n, m;
  while (cin >> d >> n >> m && d) {
    MOD = m;
    ull f[20] = {0};
    r(i, d) {
      r(j, d) {
        a[i][j] = 0;
      }
    }
    r(i, d) {
      a[i + 1][i] = 1;
      cin >> a[0][i];
      a[0][i] %= MOD;
    }
    r(i, d) {
      cin >> f[i];
      f[i] %= MOD;
    }
    if (n < d) {
      cout << f[n - 1] % m << endl;
      continue;
    }
    mat_pow(n - d);
    // res * f
    int val = 0;
    r(i, d) {
      val += res[0][i] * f[d - i - 1];
      val %= MOD;
    }
    cout << val << endl;
  }
} 

