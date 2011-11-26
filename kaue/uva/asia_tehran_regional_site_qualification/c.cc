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

int deg[10010];
int graph[10010][10010];

void go(int cur, int father, int& dist, int& ind) {
  //printf("go(%d, %d)\n", cur, father);
  //ppn(deg[cur]);
  dist = 0;
  ind = cur;
  r(j, deg[cur]) {
    int next = graph[cur][j];
    if (next == father) continue;
    int ndist, nind;
    go(next, cur, ndist, nind);
    ndist++;
    if (ndist > dist) {
      dist = ndist;
      ind = nind;
    }
  }
}
 
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    scanf("%d", &n);
    ri {
      scanf("%d", &deg[i]);
      r(j, deg[i]) {
        scanf("%d", &graph[i][j]);
        graph[i][j]--;
      }
    }
    int dist, ind;
    go(0, -1, dist, ind);
    //ppn(dist); ppn(ind);
    go(ind, -1, dist, ind);
    //ppn(dist); ppn(ind);
    printf("%d\n", 2 * (n - 1) - dist);
  }
} 

