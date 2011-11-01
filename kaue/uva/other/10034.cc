#include <algorithm>
#include <iomanip>
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

ld v[110][2];

ld sqr(ld x) { return x * x; }

ld get_dist(int a, int b) {
  return sqrt(sqr(v[a][0] - v[b][0]) +
      sqr(v[a][1] - v[b][1]));
}
 
int main() {
  int T;
  cin >> T;
  bool second = false;
  while (T--) {
    if (second) cout << endl;
    second = true;
    int n;
    cin >> n;
    ri {
      cin >> v[i][0] >> v[i][1];
    }
    priority_queue<pair<ld, int> > q;
    q.push(make_pair(0.0, 0));
    bool gone[110] = {0};
    ld res = 0;
    while (!q.empty()) {
      ld dist = -q.top().first;
      int cur = q.top().second;
      q.pop();
      //ppn(cur);
      if (gone[cur]) continue;
      gone[cur] = true;
      res += dist;
      r(i, n) {
        if (!gone[i]) {
          q.push(make_pair(-get_dist(cur, i), i));
        }
      }
    }
    cout << fixed << setprecision(2) << res << endl;
  }
} 

