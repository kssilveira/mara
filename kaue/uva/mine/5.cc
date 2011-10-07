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

int res;
int board[20][20], col[20],
    diag[2][50];

void solve(int cur, int n) {
  if (cur == n) {
    res++;
    return;
  }
  int i = cur;
  for (int j = 0; j < n; j++) {
    if (!board[i][j] && !col[j] && !diag[0][i + j] &&
        !diag[1][i - j + n]) {
      board[i][j] = col[j] = diag[0][i + j] = 
        diag[1][i - j + n] = 1;
      solve(cur + 1, n);
      board[i][j] = col[j] = diag[0][i + j] = 
        diag[1][i - j + n] = 0;
    }
  }
}
 
int main() {
  int n;
  while (cin >> n && n != 0) {
    //memset(board, 0, sizeof(board));
    //memset(line, 0, sizeof(line));
    //memset(col, 0, sizeof(col));
    //memset(diag, 0, sizeof(diag));
    res = 0;
    ri {
      col[i] = 0;
      char s[20];
      scanf("%s", s);
      rj {
        diag[0][i + j] = diag[1][i - j + n] = 0;
        if (s[j] == '*') {
          board[i][j] = 1;
        } else {
          board[i][j] = 0;
        }
      }
    }

    solve(0, n);
    printf("%d\n", res);
    //cout << res << endl;
  }
} 

