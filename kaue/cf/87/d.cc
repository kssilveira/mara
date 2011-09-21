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
#define pp(x) " "#x" " << x // NEW
#define ppn(x) pn(pp(x)) // NEW
#define ppp(x) p(pp(x)) // NEW

#define in(x) cin >> x // NEW
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
 
int main() {
  string s;
while (in(s)) {
  int n = s(s);
  bool digit = false, ok = true;
  int op = 0, un = 0;
  ri {
    // pn("i: " << i << " Si: " << s[i] << " is: " << digit << " op: " << op);
    if (isdigit(s[i])) {
      digit = true;
    } else if (digit) {
      digit = false;
      op++;
    } else if (s[i] != '+' && s[i] != '-') {
      ok = false;
      break;
    } else {
      // op++;
      un++;
    }
  }
  if (!ok || !digit) {
    pn(0);
    continue;
  }
  ppp(op);
  ppn(un);
  // pv(s);

  const ull MOD = 1e6 + 3;
  ull dp[2010] = {0};
  dp[0] = 1;
  {
    int n = 2010;
    ri {
      if (i) dp[i] = 0;
      r(j, i) {
        dp[i] += dp[j] * dp[i - j - 1];
        dp[i] %= MOD;
      }
    }
    n = 10;
    pv(dp);
  }
  cout << dp[op] << endl;
} 
}

