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
  int T;
  cin >> T;
  bool second = false;
  while (T--) {
    if (second) cout << endl;
    second = true;
    int n, m;
    cin >> n >> m;
    char tab[60][60];
    ri {
      cin >> tab[i];
      //ppn(tab[i]);
    }
    int K;
    cin >> K;
    r(k, K) {
      string what;
      cin >> what;
      //ppn(what);
      bool solved = false;
      ri {
        //ppn(i);
        r(j, m) {
          if (tolower(tab[i][j]) != tolower(what[0])) continue;
          //ppn(j);
          r(d, 8) {
            bool invalid = false;
            rb(s, 1, s(what)) {
              int dx[8] = {-1, -1, +0, +1, +1, +1, +0, -1},
                  dy[8] = {+0, +1, +1, +1, +0, -1, -1, -1};
              int ni = i + s * dx[d],
                  nj = j + s * dy[d];
              if (ni < 0 || ni >= n ||
                  nj < 0 || nj >= m ||
                  tolower(tab[ni][nj]) != tolower(what[s])) {
                invalid = true;
                break;
              }
            }
            if (!invalid) {
              cout << i + 1 << ' ' << j + 1 << endl;
              solved = true;
              break;
            }
          }
          if (solved) break;
        }
        if (solved) break;
      }
    }
  }
} 

