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

vi tree[100001];
vector<bool> edge[100001];
int child[100001], lucky[100001];
int N;

void go(int cur, int par) {
  //p("go\n");
  //ppn(cur);
  //ppn(par);
  int n = s(tree[cur]);
  child[cur] = 0;
  lucky[cur] = 0;
  ri {
    int next = tree[cur][i];
    if (next != par) {
      go(next, cur);
      child[cur] += child[next] + 1;
      if (edge[cur][i]) {
        lucky[cur] += child[next] + 1;
      } else {
        lucky[cur] += lucky[next];
      }
    }
  }
  //ppn(cur);
  //ppn(child[cur]);
  //ppn(lucky[cur]);
}

void go2(int cur, int par, bool isl) {
  //p("go2\n");
  //ppn(cur);
  //ppn(par);
  int n = s(tree[cur]);
  //ppn(cur);
  //ppn(child[cur]);
  //ppn(lucky[cur]);
  if (par != -1) {
    if (isl) {
      lucky[cur] += N - child[cur] - 1;
    } else {
      lucky[cur] = lucky[par];
    }
  }
  ri {
    int next = tree[cur][i];
    if (next != par) {
      go2(next, cur, edge[cur][i]);
    }
  }
  //ppn(cur);
  //ppn(child[cur]);
  //ppn(lucky[cur]);
}

bool islucky(int x) {
  if (x == 0) return false;
  while (x > 0) {
    int d = x % 10;
    if (d != 4 && d != 7) {
      return false;
    }
    x /= 10;
  }
  return true;
}
 
int main() {
  int n;
  cin >> n;
  N = n;
  n--;
  ri {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    tree[u].push_back(v);
    tree[v].push_back(u);
    bool yes = islucky(w);
    edge[u].push_back(yes);
    edge[v].push_back(yes);
  }
  n++;
  go(0, -1);
  go2(0, -1, false);
  ri {
    tree[i].clear();
    edge[i].clear();
  }
  //pv(lucky);
  ull res = 0;
  ri {
    if (lucky[i] > 1)
      res += lucky[i] * ull (lucky[i] - 1);
  }
  cout << res << endl;
} 

