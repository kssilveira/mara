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
  string line;
  bool isend = false;
  vector<pair<int, int> > graph[10010];
  while (!isend) {
    isend = !getline(cin, line);
    int start = 0;
    if (line.empty() || isend) {
      queue<pair<int, pair<int, int> > > q;
      q.push(make_pair(start, make_pair(0, -1)));
      int nmax = 0, imax = 0;
      while (!q.empty()) {
        int cur = q.front().first,
            dist = q.front().second.first,
            father = q.front().second.second;
        if (dist > nmax) {
          nmax = dist;
          imax = cur;
        }
        q.pop();
        //ppn(cur); ppn(dist); ppn(father);
        r(i, s(graph[cur])) {
          int next = graph[cur][i].first,
              nextdist = graph[cur][i].second;
          if (next != father) {
            q.push(make_pair(next, make_pair(dist + nextdist, cur)));
          }
        }
      }
      //ppn(nmax); ppn(imax);

      start = imax;
      nmax = imax = 0;
      q.push(make_pair(start, make_pair(0, -1)));
      while (!q.empty()) {
        int cur = q.front().first,
            dist = q.front().second.first,
            father = q.front().second.second;
        if (dist > nmax) {
          nmax = dist;
          imax = cur;
        }
        q.pop();
        //ppn(cur); ppn(dist); ppn(father);
        r(i, s(graph[cur])) {
          int next = graph[cur][i].first,
              nextdist = graph[cur][i].second;
          if (next != father) {
            q.push(make_pair(next, make_pair(dist + nextdist, cur)));
          }
        }
      }
      //ppn(nmax); ppn(imax);

      cout << nmax << endl;

      r(i, 10010) {
        graph[i].clear();
      }
    } else {
      istringstream input(line);
      int i, j, k;
      input >> i >> j >> k;
      i--;
      j--;
      graph[i].push_back(make_pair(j, k));
      graph[j].push_back(make_pair(i, k));
      start = i;
      //ppn(i); ppn(j); ppn(k);
    }
  }
} 

