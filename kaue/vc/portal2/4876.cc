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
  int T;
  cin >> T;
  while (T--) {
    int t, b;
    cin >> t >> b;
    vi val;
    r(i, b) {
      int v;
      scanf("%2X", &v);
      val.push_back(v);
      //printf("%02X ", v);
    }
    vi res;
    r(i, b) {
      int cur = val[i];
      //printf("\ncur: %02X\n", cur);
      if (cur & (1 << 7)) {
        cur = cur & (~(1 << 7));
        i++;
        r(j, cur + 3) {
          //printf("%02X", val[i]);
          res.push_back(val[i]);
        }
      } else {
        r(j, cur + 1) {
          //printf("%02X", val[i + j + 1]);
          res.push_back(val[i + j + 1]);
        }
        i += cur + 1;
      }
    }
    int cnt = s(res);
    cout << t << ' ' << cnt << endl;
    r(i, cnt) {
      printf("%02X", res[i]);
      if ((i + 1) % 40 == 0 && i + 1 < cnt) cout << endl;
    }
    cout << endl;
  }
} 

