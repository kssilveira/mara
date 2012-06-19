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
#include <iomanip>
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
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()

#define pb push_back
#define mp make_pair
#define nl cout << endl
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

bool gone[60][60];
ld memo[60][60];

ld solve(int x, int val) {
  if (gone[x][val]) {
    return memo[x][val];
  }
  gone[x][val] = true;
  ld& res = memo[x][val];

  if (x == 0) {
    return res = val;
  }
  ld cur = 0;
  for (int i = 1; i <= 13; i++) {
    cur += 4 * solve(x - 1, i);
  }
  cur /= 52;
  return res = max(cur, (ld)val);
}
 
int main() {
  int T;
  cin >> T;
  while (T--) {
    memset(gone, 0, sizeof(gone));
    memset(memo, 0, sizeof(memo));
    int x;
    cin >> x;
    ld res = solve(x, 0);
    cout << fixed << showpoint << setprecision(12) << res << endl;
  }
} 

