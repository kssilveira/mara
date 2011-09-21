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

int v[100010];
char s[30];
 
int main() {
  int l, n;
  while(scanf("%d%d", &l, &n) && l != -1) {
    int minw = 0, maxw = 0;
    ri {
      scanf("%s", s);
      v[i] = strlen(s);
      minw = max(minw, v[i]);
      maxw += v[i] + 1;
    }
    // pv(v);
    // ppn(minw);
    // ppn(maxw);
    // minw = maxw;
    while (minw < maxw) {
      // ppn(minw);
      // ppn(maxw);
      int cur = minw + (maxw - minw) / 2;
      // ppn(cur);
      int sum = 0, cnt = 1;
      ri {
        if (sum + v[i] > cur) {
          cnt++;
          sum = 0;
        } 
        sum += v[i] + 1;
      }
      if (cnt <= l) {
        maxw = cur;
      } else {
        minw = cur + 1;
      }
    }
    cout << minw << endl;
  } 
}
