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
  int n, m;
  cin >> n >> m;
  ri {
    int s, f, t;
    scanf("%d%d%d", &s, &f, &t);
    if (s == f) {
      cout << t << endl;
      continue;
    }
    s--;
    f--;
    //ppn(s);
    //ppn(f);
    //ppn(t);
    int v = t % (m + m - 2);
    //ppn(v);
    int S = s;
    if (S < v) S = (m - 1) + (m - 1) - s;
    if (S < v) S = m + m - 2 + s;
    //ppn(S);
    int res = t + S - v;
    v = S;
    int F = f;
    if (F < v) F = (m - 1) + (m - 1) - f;
    if (F < v) F = m + m - 2 + f;
    if (F < v) F = F + (m - 1) - f + (m - 1) - f;
    if (F < v) F = 2 * (m + m - 2 + f);
    //ppn(F);
    cout << res + F - v << endl;
  }
} 

