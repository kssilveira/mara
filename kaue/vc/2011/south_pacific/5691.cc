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
  int K;
  cin >> K;
  r(T, K) {
    int n;
    cin >> n;
    int tab[610][610] = {{0}};
    ri {
      string s;
      cin >> s;
      rj {
        tab[i + 1][j + 1] = s[j] == '#';
      }
    }
    int dp[610][610] = {{0}};
    rb(i, 1, n + 1) {
      rb(j, 1, n + 1) {
        dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1];
        if (i > 1) {
          dp[i][j] = max(dp[i][j],
              (!!(tab[i][j] && tab[i - 1][j]))
              + dp[i - 2][j] + dp[i][j - 1] - dp[i - 2][j - 1]);
        }
        if (j > 1) {
          dp[i][j] = max(dp[i][j],
              (!!(tab[i][j] && tab[i][j - 1]))
              + dp[i][j - 2] + dp[i - 1][j] - dp[i - 1][j - 2]);
        }
      }
    }

    //*
    r(i, n + 1) {
      r(j, n + 1) {
        cout << dp[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl; //*/
    cout << "Case " << T + 1 << ": " << dp[n][n] << endl;
  }
} 

