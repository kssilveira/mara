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

bool used[10010][10010];
bitset<10010> gone;
int graph[10010][10010];
int deg[10010];

bool dfs(int s, int t) {
  //printf("dfs(%d, %d)\n", s, t);
  if (s == t) return true;
  r(i, deg[s]) {
    int next = graph[s][i];
    if (!gone[next]) {
      gone[next] = true;
      used[s][next] = used[next][s] = true;
      if (dfs(next, t)) {
        return true;
      }
      used[s][next] = used[next][s] = false;
    }
  }
  return false;
}

ull inf;

ull dijkstra(int s, int t) {
  priority_queue<pair<ull, int> > q;
  q.push(make_pair(0, s));
  while (!q.empty()) {
    ull dist = -q.top().first;
    int cur = q.top().second;
    q.pop();
    //ppn(cur);
    //ppn(dist);
    if (gone[cur]) continue;
    if (cur == t) return dist;
    gone[cur] = true;
    r(i, (deg[cur])) {
      int next = graph[cur][i];
      if (!gone[next]) {
        if (used[cur][next]) {
          q.push(make_pair(-(dist + inf), next));
        } else {
          q.push(make_pair(-(dist + 1), next));
        }
      }
    }
  }
  return 0;
}
 
int main() {
  int r, c, q;
  while (cin >> r >> c >> q && r > 0) {
    memset(deg, 0, sizeof(deg));
    r(i, c) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      //graph[a].push_back(b);
      //graph[b].push_back(a);
      graph[a][deg[a]++] = b;
      graph[b][deg[b]++] = a;
    }
    r(i, q) {
      int s, t;
      cin >> s >> t;
      s--; t--;

      //ppn(s); ppn(t);
      gone.reset();
      memset(used, 0, sizeof(used));

      gone[s] = true;
      bool first = dfs(s, t);
      bool solved = false;
      if (first) {
        /*
        cout << "used" << endl;
        r(i, r) {
          r(j, r) {
            cout << used[i][j] << ' ';
          }
          cout << endl;
        }
        cout << endl;//*/
        gone.reset();
        inf = r + 1;
        //ppn(inf);
        ull cost = dijkstra(s, t);
        //ppn(cost);
        if (cost % inf == 0) {
          solved = true;
        }
      }

      cout << (solved ? 'Y' : 'N') << endl;

    }
    //r(i, r) {
      //graph[i].clear();
    //}
    cout << "-" << endl;
  }
} 

