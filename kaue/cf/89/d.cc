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

const ull MOD = 1e8;

ull dp[101][101][11][11] = {{{{0}}}};
bool gone[101][101][11][11] = {{{{0}}}};

ull solve(ull n1, ull n2, ull k1, ull k2, ull t1, ull t2) {
  //printf("solve(%Lu, %Lu, %Lu, %Lu)\n", n1, n2, t1, t2);
  ull& res = dp[n1][n2][t1][t2];
  if (gone[n1][n2][t1][t2]) return res;
  gone[n1][n2][t1][t2] = 1;
  res = 0;

  if (n1 == 0 && n2 == 0) {
    return res = 1;
  }
  if (n1 > 0 && t1 < k1) {
    res += solve(n1 - 1, n2, k1, k2, t1 + 1, 0);
    res %= MOD;
  }
  if (n2 > 0 && t2 < k2) {
    res += solve(n1, n2 - 1, k1, k2, 0, t2 + 1);
    res %= MOD;
  }
  return res;
}
 
int main() {
  ull n1, n2, k1, k2;
  cin >> n1 >> n2 >> k1 >> k2;
  ull res = solve(n1, n2, k1, k2, 0, 0);
  res %= MOD;
  cout << res << endl;
} 

