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

int calc(const string& s, int* perm) {
  int n = s(s);
  int res = 0;
  ri {
    res *= 10;
    res += s[perm[i]] - '0';
  }
  return res;
}
 
int main() {
  int n, k;
  cin >> n >> k;
  vector<string> v(n);
  ri {
    cin >> v[i];
  }
  int perm[10];
  r(i, k) {
    perm[i] = i;
  }
  int res = INT_MAX;
  do {
    int nmin = INT_MAX, nmax = -1;
    ri {
      int cur = calc(v[i], perm);
      nmin = min(nmin, cur);
      nmax = max(nmax, cur);
    }
    int cost = nmax - nmin;
    res = min(res, cost);
  } while (next_permutation(perm, perm + k));
  cout << res << endl;
} 

