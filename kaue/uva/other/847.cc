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
 
const unsigned int MAXX = 10000, MAXY = 90000;
bitset<MAXY> dp[MAXX], gone[MAXX];

bool solve(ull cur, ull n) {
  bool res = false;
  if (cur < MAXX && n < MAXY && gone[cur][n]) return dp[cur][n];
  if (cur * 9 >= n) {
    res = true;
    goto end;
  }
  for (int i = 9; i >= 2; i--) {
    if (!solve(cur * i, n)) {
      res = true;
      break;
    }
  }
end:
  if (cur < MAXX && n < MAXY) {
    gone[cur][n] = true;
    dp[cur][n] = res;
  }
  return res;
}

int main() {

  /*
  rb(i, 2, 1000) {
    dp[i] = solve(1, i);
    //cout << i << ": " << dp[1][i] << endl;
  }
  cout << endl;//*/

  ull n;
  while (cin >> n) {
    bool res = solve(1, n);
    cout << (res % 2 ? "Stan" : "Ollie") << " wins.\n";
  }
} 

