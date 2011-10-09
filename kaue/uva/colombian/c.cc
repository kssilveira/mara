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

int memo[1 << 17];
bitset<1 << 17> gone;
int m, n;
int whole;
int base[110];

int solve(int cur) {
  //printf("solve(%d)\n", cur);
  if (cur == 0) return 0;
  int &res = memo[cur];
  if (gone[cur]) {
    return res;
  }
  gone[cur] = 1;
  res = -1;
  r(i, m) {
    int next = cur & ~base[i];
    //ppn(whole);
    //ppn(base[i]);
    //ppn((whole | base[i]));
    if ((whole | base[i]) == whole &&
        next != cur) {
      int nextres = 1 + solve(next);
      //ppn(i);
      //ppn(nextres);
      if (nextres != 0 && (res == -1 || nextres < res)) {
        res = nextres;
      }
    }
  }
  return res;
}
 
int main() {
  while (cin >> m >> n && m > 0) {
    r(i, m + n) {
      int k;
      cin >> k;
      int cur = 0;
      r(j, k) {
        int t;
        cin >> t;
        cur |= 1 << (t - 1);
      }
      //ppn(i);
      //ppn(cur);
      if (i < m) {
        base[i] = (cur);
      } else {
        gone.reset();
        whole = cur;
        int res = solve(cur);
        if (res == -1) res = 0;
        if (i > m) {
          cout << ' ';
        }
        cout << res;
      }
    }
    cout << endl;
  }
} 

