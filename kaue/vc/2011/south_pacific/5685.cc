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

int pt[10010][3];

ld sqr(ld x) { return x * x; }

ld get_dist(int a, int b) {
  return sqrt(sqr(pt[a][0] - pt[b][0]) +
      sqr(pt[a][1] - pt[b][1]) + sqr(pt[a][2] - pt[b][2]));
}

ld get_dist2(int a, int b) {
  return sqrt(sqr(pt[a][0] - pt[b][0]) +
      sqr(pt[a][1] - pt[b][1]));
}

int level(int a, int b) {
  if (pt[a][2] >= pt[b][2]) return 0;
  ld rise = pt[b][2] - pt[a][2];
  ld run = get_dist2(a, b); // ERROR!
  return 100 * rise / run;
}
 
int main() {
  int n = 0, m;
  while (cin >> n >> m && n) {
    vector<pair<int, ld> > graph[10010];
    ri {
      cin >> pt[i][0] >> pt[i][1] >> pt[i][2];
    }
    r(i, m) {
      int a, b;
      cin >> a >> b;
      a--; b--;
      ld dist = get_dist(a, b);
      graph[a].push_back(make_pair(b, dist));
      graph[b].push_back(make_pair(a, dist));
    }
    int s, t, D;
    cin >> s >> t >> D;
    s--;
    t--;

    // dijkstra
    priority_queue<pair<ld, int> > q;
    q.push(make_pair(0, s));
    bitset<10010> gone;
    ld distance[2][10010] = {{0}};
    bool cango[2][10010] = {{0}};
    while (!q.empty()) {
      ld curdist = -q.top().first;
      int cur = q.top().second;
      q.pop();
      if (gone[cur]) continue;
      //ppn(cur); ppn(curdist);
      gone[cur] = true;
      distance[0][cur] = curdist;
      cango[0][cur] = true;
      r(i, s(graph[cur])) {
        int next = graph[cur][i].first;
        ld nextdist = graph[cur][i].second;
        if (!gone[next] && level(cur, next) <= D) {
          q.push(make_pair(-(curdist + nextdist), next));
        }
      }
    }

    // dijkstra
    q.push(make_pair(0, t));
    gone.reset();
    while (!q.empty()) {
      ld curdist = -q.top().first;
      int cur = q.top().second;
      q.pop();
      if (gone[cur]) continue;
      //ppn(cur); ppn(curdist);
      gone[cur] = true;
      distance[1][cur] = curdist;
      cango[1][cur] = true;
      r(i, s(graph[cur])) {
        int next = graph[cur][i].first;
        ld nextdist = graph[cur][i].second;
        if (!gone[next] && level(next, cur) <= D) {
          q.push(make_pair(-(curdist + nextdist), next));
        }
      }
    }

    /*
    r(i, n) {
      cout << distance[0][i] << " ";
    }
    cout << endl;

    r(i, n) {
      cout << distance[1][i] << " ";
    }
    cout << endl;//*/

    ld nmin = 1e100;
    bool found = false;
    ri {
      r(j, s(graph[i])) {
        int next = graph[i][j].first;
        ld dist_next = graph[i][j].second;
        if (level(i, next) == D &&
            cango[0][i] && cango[1][next]) {
          found = true;
          //ppn(i); ppn(next); ppn(distance[0][i]);
          //ppn(dist_next); ppn(distance[1][next]);
          ld cur = distance[0][i] + dist_next +
            distance[1][next];
          if (cur < nmin) {
            nmin = cur;
          }
        }
      }
    }
    if (!found) {
      cout << "None" << endl;
    } else {
      cout << fixed << setprecision(3) << nmin << endl;
    }
  }
} 

