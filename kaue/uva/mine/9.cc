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

int get(int x) {
  if (x == 2) return 1;
  return 2;
}

int main() {
  int v;
  while(cin >> v && v) {
    int a, b;
    vi graph[310];
    while (cin >> a >> b && a && b) {
      a--;
      b--;
      graph[a].push_back(b);
      graph[b].push_back(a);
    }

    int val[310] = {0};
    stack<int> q;
    q.push(0);
    val[0] = 1;
    bool found = false;
    while (!q.empty() && !found) {
      int cur = q.top(); q.pop();
      int nextcolor = get(val[cur]);
      //ppn(cur);
      //ppn(nextcolor);
      int n = s(graph[cur]);
      ri {
        int next = graph[cur][i];
        if (val[next]) {
          if (val[next] != nextcolor) {
            found = true;
            break;
          }
        } else {
          val[next] = nextcolor;
          q.push(next);
        }
      }
    }
    cout << (found ? "NO" : "YES") << endl;
  }
} 

