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
  while (cin >> n && n > 0) {
    ll tab[1010][1010] = {{0}};
    ri {
      r(j, i + 1) {
        cin >> tab[i][j];
      }
    }
    ll res = 0;
    while (1) {
    cout << "tab:\n";
    ri {
      r(j, i + 1) {
        cout << tab[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl; //*/
      ll dp[1010][1010] = {{0}};
      ll best = -1;
      int besti = -1, bestj = -1;
      ri {
        r(j, i + 1) {
          dp[i][j] = tab[i][j];
          if (i > 0) {
            dp[i][j] += dp[i - 1][j];
            if (j > 0) {
              dp[i][j] += dp[i - 1][j - 1];
            }
            if (i > 1 && j != 0 && j != i) {
              dp[i][j] -= dp[i - 2][j - 1];
            }
          }
          if (dp[i][j] >= best) {
            best = dp[i][j];
            besti = i;
            bestj = j;
          }
          cout << dp[i][j] << ' ';
        }
        cout << endl;
      }
      cout << endl;
      ppn(best); ppn(besti); ppn(bestj);
      if (best > 0) {
        res += best;
        for (int i = besti; i >= 0; i--) {
          for (int j = max(0, bestj - (besti - i)); j <= bestj; j++) {
            tab[i][j] = 0;
          }
        }
      } else {
        break;
      }
    }
    ppn(res);
    cout << res << endl;
  }
} 

