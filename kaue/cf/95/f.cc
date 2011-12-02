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

ull go(int x, int y, int k) {
  if (x < 0 || x >= n || y < 0 || y >= n) return 0;
  if (k == 0) {
    if (x == 0) {
      ull next = go(x, y - 1, k);
      return 2 * next + 1;
    }
    if (y == 0) {
      ull next = go(x - 1, y, k);
      return 2 * next + 1;
    }
    ull a = go(x - 1, y - 1, k),
        b = go(x - 1, y, k),
        c = go(x, y - 1, k);
    if (tab[x][y]) return b + c - a;
    return b + c - a + (b + 1) / 2 + (c + 1) / 2 + 1;
  } else if (tab[x][y]) {
  }
}
 
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  int tab[510][510], other[510][510];
  ri {
    rjm {
      char c;
      cin >> c;
      tab[i][j] = c == '1';
    }
  }
  ri {
    rjm {
      int cnt = 0;
      r(d, 4) {
        int dx[] = {-1, 0, 1, 0},
            dy[] = {0, -1, 0, 1};
        int nx = i + dx[d],
            ny = j + dy[d];
        if (nx < 0 || nx >= n ||
            ny < 0 || ny >= m) continue;
        cnt += tab[nx][ny];
      }
      cnt += tab[i][j];
      if (cnt == 5) {
        other[i][j] = true;
      } else {
        other[i][j] = false;
      }
    }
  }
  memcpy(tab, other, sizeof(other));
  ri {
    rjm {
      cout << tab[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  go(n - 1, n - 1, k);
} 

