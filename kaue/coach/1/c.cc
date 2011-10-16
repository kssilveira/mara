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

int tab[110][110];
bool gone[110][110];

int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1},
    dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
int res = 0;
int n, m;

void solve(int cx, int cy) {
  //printf("solve(%d, %d)\n", cx, cy);
  gone[cx][cy] = 1;
  res++;
  r(d, 8) {
    int nx = cx + dx[d],
        ny = cy + dy[d];
    if (nx < 0 || nx >= n ||
        ny < 0 || ny >= m || gone[nx][ny]
        || abs(tab[cx][cy] - tab[nx][ny]) > 1) continue;
    solve(nx, ny);
  }
}
 
int main() {
  int T;
  cin >> T;
  r(t, T) {
    cin >> n >> m;
    int bi, bj;
    r(i, n) {
      string s;
      cin >> s;
      r(j, m) {
        tab[i][j] = s[j] - '0';
        if (s[j] == '*') {
          tab[i][j] = 0;
          bi = i;
          bj = j;
        }
      }
    }
    //ppn(bi);
    //ppn(bj);
    memset(gone, 0, sizeof(gone));
    res = 0;
    solve(bi, bj);

    if (t) cout << endl;
    cout << "Map #" << t + 1 << ":" << endl;
    cout << "     Cara can hike up to " << res << " acres." << endl;
  }
} 

