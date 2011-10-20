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

int gone[110][110], memo[110][110];
int v[110];

int solve(int b, int e) {
  //printf("solve(%i, %i)\n", b, e);
  int &res = memo[b][e];
  if (gone[b][e]) return res;
  gone[b][e] = true;
  if (b == e) {
    return res = 0;
  }
  if (b + 1 == e) {
    return res = v[b];
  }
  int sum = 0;
  res = INT_MIN;
  for (int i = b; i < e; i++) {
    sum += v[i];
    res = max(res, sum - solve(i + 1, e));
  }
  sum = 0;
  for (int i = e - 1; i >= b; i--) {
    sum += v[i];
    res = max(res, sum - solve(b, i));
  }
  //printf("solve(%i, %i) = %i\n", b, e, res);
  return res;
}
 
int main() {
  int n;
  while (cin >> n && n) {
    ri {
      cin >> v[i];
    }
    memset(gone, 0, sizeof(gone));
    cout << solve(0, n) << endl;
  }
} 

