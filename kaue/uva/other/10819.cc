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

ull dp[110][10500] = {{0}};
 
int main() {
  int M, n;
  while (cin >> M >> n) {
    int p[110], f[110];
    ri {
      cin >> p[i] >> f[i];
    }
    int m = M;
    if (m >= 2000 - 200 + 1) m += 200;
    memset(dp, 0, sizeof(dp));
    ull res = 0;
    rb(i, 1, n + 1) {
      rb(j, 1, m + 1) {
        dp[i][j] = dp[i - 1][j];
        int next = j - p[i - 1];
        if (next >= 0 && (dp[i - 1][next] || next == 0)) {
          //ppn(i); ppn(j); ppn(next);
          dp[i][j] = max(dp[i][j], f[i - 1] + dp[i - 1][next]);
          if (dp[i][j] > res && (j <= M || j > 2000)) {
            //ppn(i); ppn(j); ppn(res); ppn(dp[i][j]);
            res = dp[i][j];
          }
        }
      }
    }
    /*
    r(i, n + 1) {
      r(j, m)  {
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;//*/

    //int nmin = m;
    //for (int i = m; i > 0 && dp[n][i] == dp[n][i - 1]; i--) nmin = i - 1;

    //ppn(nmin);
    //ppn(m);
    //ppn(M);
    //if (nmin <= 2000) m = M;

    //cout << dp[n][m] << endl;
    cout << res << endl;
  }
} 

