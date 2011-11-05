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

string tab[1010];

int dx[] = {-1, +0, +1, +0},
    dy[] = {+0, +1, +0, -1};
char ch[] = "CDEB";
int n, m;
bitset<1010> gone[1010];

void solve(int bx, int by) {
  queue<pair<int, int> > q;
  q.push(make_pair(bx, by));
  while (!q.empty()) {
    int cx = q.front().first,
        cy = q.front().second;
    q.pop();
    r(d, 4) {
      int nx = cx + dx[d],
          ny = cy + dy[d];
      if (nx < 0 || nx >= n ||
          ny < 0 || ny >= m) continue;
      char cur = tab[cx][cy],
           next = tab[nx][ny];
      if (cur != 'F' && cur != ch[d] && cur != ch[(d + 1) % 4]) continue;
      if (next != 'F' && next != ch[(d + 2) % 4] && next != ch[(d + 3) % 4])
        continue;
      if (gone[nx][ny]) continue;
      gone[nx][ny] = true;
      q.push(make_pair(nx, ny));
      //solve(nx, ny);
    }
  }
}
 
int main() {
  int Z;
  cin >> Z;
  while (Z--) {
    cin >> n >> m;
    ri {
      cin >> tab[i];
    }
    ll res = 0;
    ri {
      gone[i].reset();
    }
    ri {
      rjm {
        if (!gone[i][j] && tab[i][j] != 'A') {
          //ppn(i); ppn(j);
          res++;
          gone[i][j] = true;
          solve(i, j);

          /*
          r(k, n) {
            r(l, m) {
              cout << gone[k][l] << ' ';
            }
            cout << endl;
          }
          cout << endl;//*/
        }
      }
    }
    cout << res << endl;
  }
} 

