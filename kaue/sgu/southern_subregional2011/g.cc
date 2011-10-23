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


int get_type(char c) {
  if (c == 'K') return 0;
  if (c == 'B') return 1;
  if (c == 'R') return 2;
  assert(false);
  return -100000;
}

bool isdead[20];
bool gone[20][20][20];
vector<pair<int, pair<int, int> > > pctotab;
             // K  B  R
int incdir[] = {1, 2, 2};
int bdir[] =   {0, 1, 0};
int ns[] =     {2, 8, 8};
int dx[3][8] = {
  {-2, -1, +1, +2, +2, +1, -1, -2}, {-1, -1, +0, +1, +1, +1, +0, -1},
                                    {-1, -1, +0, +1, +1, +1, +0, -1}};
int dy[3][8] = {
  {+1, +2, +2, +1, -1, -2, -2, -1}, {+0, +1, +1, +1, +0, -1, -1, -1},
                                    {+0, +1, +1, +1, +0, -1, -1, -1}};
int n, m;
bool ispc[20][20];
int tabtopc[20][20];

int solve(int cx, int cy, int live, bool first = false) {
  //printf("solve(%d, %d, %d, %d)\n", cx, cy, live, first);
  if (live == 0) return 0;
  if (first) {
    //memset(&gone[live], 0, sizeof(gone[live]));
    r(i, n) {
      r(j, m) {
        gone[live][i][j] = 0;
      }
    }
    r(i, s(pctotab)) {
      if (isdead[i]) continue;
      int type = pctotab[i].first,
          x = pctotab[i].second.first,
          y = pctotab[i].second.second;
      for (int d = bdir[type]; d < 8; d += incdir[type]) {
        rb(s, 1, ns[type]) {
          int nx = x + s * dx[type][d],
              ny = y + s * dy[type][d];
          if (nx < 0 || nx >= n ||
              ny < 0 || ny >= m) continue;
          gone[live][nx][ny] = 1;
          if (ispc[nx][ny] && !isdead[tabtopc[nx][ny]]) break;
        }
      }
    }

    /*/
    r(i, n) {
      r(j, m) {
        cout << gone[live][i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;//*/
  }
  int res = INT_MAX;
  //if (gone[live][cx][cy]) return res;

  queue<pair<pair<int, int>, int> > q;
  q.push(make_pair(make_pair(cx, cy), 0));
  while (!q.empty()) {
    cx = q.front().first.first;
    cy = q.front().first.second;
    int dist = q.front().second;
    q.pop();
    if (gone[live][cx][cy]) continue;

    //printf("%d: (%d, %d) => %d\n", live, cx, cy, dist);
    gone[live][cx][cy] = 1;

    r(d, 8) {
      int nx = cx + dx[1][d],
          ny = cy + dy[1][d];
      if (nx < 0 || nx >= n ||
          ny < 0 || ny >= m || gone[live][nx][ny]) continue;
      int next;
      if (ispc[nx][ny] && !isdead[tabtopc[nx][ny]]) {
        isdead[tabtopc[nx][ny]] = true;
        next =  solve(nx, ny, live - 1, true);
        if (next != INT_MAX) {
          //return dist + next + 1;
          res = min(res, dist + next + 1);
        }
        isdead[tabtopc[nx][ny]] = false;
      } else {
        q.push(make_pair(make_pair(nx, ny), dist + 1));
        //next = solve(nx, ny, live);
        //if (next != INT_MAX && next + 1 < res) {
          //res = next + 1;
        //}
      }
    }
  }
  return res;
}
 
int main() {
  while (cin >> n >> m) {
    pctotab.clear();
    memset(isdead, 1, sizeof(isdead));
    memset(ispc, 0, sizeof(ispc));
    memset(tabtopc, 0, sizeof(tabtopc));
    int bx, by;
    ri {
      string s;
      cin >> s;
      r(j, m) {
        char c = s[j];
        if (c == '*') {
          bx = i;
          by = j;
        } else if (c != '.') {
          pctotab.push_back(make_pair(get_type(c), make_pair(i, j)));
          tabtopc[i][j] = s(pctotab) - 1;
          isdead[tabtopc[i][j]] = false;
          ispc[i][j] = true;
        }
      }
    }
    int live = s(pctotab);
    //ppn(live);
    int res = solve(bx, by, live, true);
    if (res == INT_MAX) res = -1;
    cout << res << endl;
    //break;
  }
} 

