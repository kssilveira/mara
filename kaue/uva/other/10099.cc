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
  int n, r;
  int T = 0;
  while (cin >> n >> r && (n != 0 || r != 0)) {
    T++;
    int graph[110][110] = {{0}};
    bool gone[110] = {0};
    r(i, r) {
      int c1, c2, p;
      cin >> c1 >> c2 >> p;
      c1--;
      c2--;
      p--;
      graph[c1][c2] = graph[c2][c1] = p;
    }
    int s, d, t;
    cin >> s >> d >> t;
    s--;
    d--;
    priority_queue<pair<int, int> > q;
    q.push(make_pair(INT_MAX, s));
    while (!q.empty()) {
      int cost = q.top().first,
          ind = q.top().second;
      if (ind == d) {
        int res = (t + cost - 1) / cost;
        cout << "Scenario #" << T << endl
          << "Minimum Number of Trips = " << res << endl << endl;
        break;
      }
      q.pop();
      //ppn(cost);
      //ppn(ind);
      if (gone[ind]) continue;
      gone[ind] = true;
      ri {
        if (!gone[i] && graph[ind][i]) {
          q.push(make_pair(min(cost, graph[ind][i]), i));
        }
      }
    }
  }
} 

