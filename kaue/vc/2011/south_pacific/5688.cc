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
 
int dp[210][3010][3010] = {{0}};
bitset<3010> can[210][3010] = {{0}};

int main() {
  int n, K;
  int T = 0;
  while (cin >> n >> K && n) {
    T++;
    int c[210], e[210];
    ri {
      //cin >> c[i] >> e[i];
      cin >> e[i] >> c[i];
    }
    r(j, (K + 1) / 2) {
      r(k, (K + 1) / 2) {
      if (c[0] <= j) {
        dp[0][j][j] = 1;
        can[0][j][j] = 1;
        val[0][j][j] = j;
      }
      if (e[0] <= j) {
        can[0][j][j] = 1;
        val[0][j][j] = e[0];
      }
    }
    rb(i, 1, n) {
      r(j, k + 1) {
        int next = j - c[i];
        if (next >= 0 && can[i - 1][next]
            && j + val[i - 1][next] <= k) {
          dp[i][j] = max(dp[i][j], 1 + dp[i - 1][next]);
          can[i][j] = true;
            val[i][j] = 
        }
        next = j - e[i];
        if (next >= 0 && can[i - 1][next]) {
          dp[i][j] = max(dp[i][j], dp[i - 1][next]);
          can[i][j] = true;
        }
      }
    }

    //*
    r(i, n) {
      r(j, k + 1) {
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;//*/

    cout << T << ": ";
    if (!can[n - 1][k]) {
      cout << "Mission Impossible" << endl;
    } else {
      cout << dp[n - 1][k] << endl;
    }
  }
} 

