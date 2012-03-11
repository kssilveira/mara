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

#define pb push_back
#define mp make_pair
#define nl cout << endl
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

vector<int> graph[50010];
int K;
ll res = 0;

ll dp[50010][510];
ll dpunion[510];

void solve(int cur, int last) {

  //printf("solve(%i, %i)\n", cur + 1, last);

  dp[cur][0] = 1;

  if (s(graph[cur]) == 1 && graph[cur][0] == last) {
    return;
  }

  r(i, s(graph[cur])) {
    int next = graph[cur][i];
    if (next == last) continue;
    solve(next, cur);

    /*
    cout << next + 1 << ": ";
    r(i, K + 1) {
      cout << dp[next][i] << ' ';
    }
    nl; //*/
  }

  memset(dpunion, 0, sizeof(dpunion));

  r(i, s(graph[cur])) {
    int ni = graph[cur][i];
    if (ni == last) continue;
    r(x, K + 1) {
      dpunion[x] += dp[ni][x];
    }
  }

  ll total = 0;
  r(i, s(graph[cur])) {
    int ni = graph[cur][i];
    if (ni == last) continue;
    //rb(j, i + 1, s(graph[cur])) {
      //int nj = graph[cur][j];
      //if (nj == last) continue;

      rb(x, 1, K) {
        total += dp[ni][x - 1] * (dpunion[K - x - 1] - dp[ni][K - x - 1]);
      }
    //}
  }

  res += total / 2;

  r(i, s(graph[cur])) {
    int ni = graph[cur][i];
    if (ni == last) continue;
    r(x, K) {
      dp[cur][x + 1] += dp[ni][x];
    }
  }

  res += dp[cur][K];
}
 
int main() {
  int n;
  cin >> n >> K;
  res = 0;
  r(i, n - 1) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  memset(dp, 0, sizeof(dp));
  solve(0, -1);

  cout << res << endl;
} 

