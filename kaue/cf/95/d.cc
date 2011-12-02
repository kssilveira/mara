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
#include <iomanip>
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
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

void dfs() {
  int n;
  cin >> n;

  vector<int> graph[3010];
  ri {
    int x, y;
    cin >> x >> y;
    x--; y--;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }

  stack<pair<int, int> > s;
  s.push(make_pair(0, 0));
  bool gone[3010] = {0};
  int father[3010];
  ri {
    father[i] = -1;
  }
  bool inloop[3010] = {0};
  bool found = false;
  while (!s.empty() && !found) {
    int cur = s.top().first,
        i = s.top().second;
    s.pop();
    //ppn(cur);
    gone[cur] = true;
    for (; i < s(graph[cur]); i++) {
      int next = graph[cur][i];
      if (!gone[next]) {
        father[next] = cur;
        s.push(make_pair(cur, i + 1));
        s.push(make_pair(next, 0));
        break;
      } else if (next != father[cur]) {
        int j = cur;
        while (j != next) {
          //ppn(j);
          inloop[j] = true;
          j = father[j];
        }
        inloop[next] = true;
        found = true;
        break;
      }
    }
  }

  int dist[3010] = {0};
  memset(gone, 0, sizeof(gone));
  ri {
    if (!inloop[i]) continue;
    queue<int> q;
    q.push(i);
    //ppn(i);
    while (!q.empty()) {
      int cur = q.front();
      //ppn(cur);
      q.pop();
      gone[cur] = true;
      r(i, s(graph[cur])) {
        int next = graph[cur][i];
        if (inloop[next]) continue;
        if (!gone[next]) {
          gone[next] = true;
          dist[next] = dist[cur] + 1;
          q.push(next);
        }
      }
    }
  }

  ri {
    if (i) cout << ' ';
    cout << dist[i];
  }
  cout << endl;
}
 
int main() {
  dfs();
} 

