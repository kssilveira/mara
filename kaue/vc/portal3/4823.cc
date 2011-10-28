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

int v[1010][1010];
int sum[2][1010][1010] = {{{0}}};
bool gone[1010][1010];
bool memo[1010][1010];
bool solve(int i, int j) {
  //if (i == 0 && j == 0) {
    //return !v[0][0];
  //}
  if (i < 0 || j < 0) {
    return false;
  }
  bool& res = memo[i][j];
  if (gone[i][j]) return res;
  gone[i][j] = true;
  res = true;
  if (!sum[0][i][j]) {
    res = res && solve(i, j - 1);
  }
  if (!sum[1][i][j]) {
    res = res && solve(i - 1, j);
  }
  return res = !res;
}
 
int main() {
  int n;
  while (cin >> n) {
    ri {
      rj {
        cin >> v[i][j];
        v[i][j] %= 2;
      }
    }

    //sum[0][0][0] = sum[1][0][0] = v[0][0];
    rj {
      sum[0][0][j] = v[0][j];
      sum[1][j][0] = v[j][0];
    }
    rb(i, 1, n) {
      rj {
        sum[0][i][j] = sum[0][i - 1][j] + v[i][j];
        sum[0][i][j] %= 2;
        sum[1][j][i] = sum[1][j][i - 1] + v[j][i];
        sum[1][j][i] %= 2;
      }
    }
    /*
    r(k, 2) {
      ppn(k);
      ri {
        rj {
          cout << sum[k][i][j] << ' ';
        }
        cout << endl;
      }
      cout << endl;
    }//*/
    memset(gone, 0, sizeof(gone));
    bool res = solve(n - 1, n - 1);
    cout << (!res ? 'L' : 'W') << endl;
  }
} 

