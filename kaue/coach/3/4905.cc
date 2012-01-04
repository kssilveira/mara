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
  int m, n;
  int Case = 0;
  while (cin >> m >> n && (m != 0 || n != 0)) {
    Case++;
    ld N[110], I[110], D[110];
    ri {
      cin >> N[i] >> I[i] >> D[i];
    }

    int dp[110][110] = {{0}};
    int val[110][110] = {{0}};
    int from[110][110] = {{0}};
    r(i, m + 1) {
      rj {
        ld Fcur = I[j] + (i / (10.1 + i)) * D[j];
        int vcur = (Fcur / 100.) * N[j] + 0.5;
        val[j][i] = vcur;
        //cout << val[j][i] << ' ';
      }
      //cout << endl;
    }
    //cout << endl;
    for(int i = n - 1; i >= 0; i--) {
      r(j, m + 1) {
        dp[n - 1][j] = val[n - 1][j];
        from[n - 1][j] = j;
        if (i == n - 1) {
          //cout << dp[i][j] << ' ';
          continue;
        }
        r(k, j + 1) {
          int next = val[i][k] + dp[i + 1][j - k];
          if (next >= dp[i][j] || false) {
              //(next == dp[i][j] && next == val[i][j])) {
            dp[i][j] = next;
            from[i][j] = k;
          }
        }
        //cout << dp[i][j] << "(" << from[i][j] << ") ";
      }
      //cout << endl;
    }
    //cout << endl;
    cout << "Case " << Case << ": ";
    cout << dp[0][m] << endl;
    int cur = 0;
    int curm = m;
    vi valval;
    while (cur < n) {
      valval.push_back(from[cur][curm]);
      curm = curm - from[cur][curm];
      cur++;
    }
    //reverse(all(valval));
    ri {
      if (i) cout << ' ';
      cout << i << ":" << valval[i];
    }
    cout << endl;

#if 0
    ld cur[110] = {0};
    int add = 0;
    r(i, m) {
      //ppn(i);
      /*
      rj {
        if (j) cout << ' ';
          cout << j << ":" << cur[j];
      }//*/
      add++;
      ld best = 0;
      int bestj = 0;
      rj {
        ld Fcur = I[j] + (cur[j] / (10.1 + cur[j])) * D[j];
        ld vcur = (Fcur / 100.) * N[j] + 0.5;
        ld Fnext = I[j] + ((cur[j] + add) / (10.1 + cur[j] + add)) * D[j];
        ld vnext = (Fnext / 100.) * N[j] + 0.5;
        ld gain = vnext - vcur;
        if (gain > best) {
          best = gain;
          bestj = j;
        }
      }
      if (best >= 1) {
        cur[bestj] += add;
        add = 0;
      }
    }
    int res = 0;
    rj {
        ld Fcur = I[j] + (cur[j] / (10.1 + cur[j])) * D[j];
        int vcur = (Fcur / 100.) * N[j] + 0.5;
        res += vcur;
    }
    cout << "Case " << Case << ": " << res << endl;
    rj {
      if (j) cout << ' ';
        cout << j << ":" << cur[j];
    }
    cout << endl;
#endif
  }
} 
