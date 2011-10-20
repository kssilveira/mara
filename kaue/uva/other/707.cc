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
  int w, h, T;
  int TEST = 0;
  while (cin >> w >> h >> T && w) {
    TEST++;
    int n;
    cin >> n;
    bitset<110> can[110][110];
    r(t, 110) {
      r(x, w) {
        r(y, h) {
          can[t][x][y] = 1;
        }
      }
    }

    /*
    r(t, T + 1) {
      ppn(t);
      r(x, w) {
        r(y, h) {
          cout << can[t][x][y];
        }
        cout << endl;
      }
      cout << endl;
    }
    cout << endl;//*/


    ri {
      int t, bx, by, ex, ey;
      cin >> t >> bx >> by >> ex >> ey;
      bx--; by--; ex--; ey--;
      //ppn(t); ppn(bx); ppn(by); ppn(ex); ppn(ey);
      for (int x = bx; x <= ex; x++) {
        for (int y = by; y <= ey; y++) {
          can[t][x][y] = false;
        }
      }
    }
    
    string res;
    int opt[110] = {0},
        canx[110] = {0},
        cany[110] = {0};
    rb(t, 1, T + 1) {
      r(x, w) {
        r(y, h) {
          if (!can[t][x][y]) continue;
          //ppn(x);
          //ppn(y);
          int dx[] = {0, -1,  0,  1,  0},
              dy[] = {0,  0, +1,  0, -1};
          int last = false;
          //if (t == 1) last = true;
          r(d, 5) {
            if (last) break;
            int nx = x + dx[d],
                ny = y + dy[d];
            if (nx < 0 || nx >= w ||
                ny < 0 || ny >= h) continue;
            last = last || can[t - 1][nx][ny];
          }
          can[t][x][y] = last;
          if (last) {
            opt[t]++;
            canx[t] = x;
            cany[t] = y;
          }
        }
      }
    }

    for (int t = T - 1; t >= 0; t--) {
      r(x, w) {
        r(y, h) {
          if (!can[t][x][y]) continue;
          //ppn(x);
          //ppn(y);
          int dx[] = {0, -1,  0,  1,  0},
              dy[] = {0,  0, +1,  0, -1};
          int last = false;
          r(d, 5) {
            if (last) break;
            int nx = x + dx[d],
                ny = y + dy[d];
            if (nx < 0 || nx >= w ||
                ny < 0 || ny >= h) continue;
            last = last || can[t + 1][nx][ny];
          }
          if (!last) opt[t]--;
          can[t][x][y] = last;
          if (last) {
            canx[t] = x;
            cany[t] = y;
          }
        }
      }
    }
    /*
    r(t, T + 1) {
      ppn(t);
      r(x, w) {
        r(y, h) {
          cout << can[t][x][y];
        }
        cout << endl;
      }
      cout << endl;
    }
    cout << endl;//*/

    rb(t, 1, T + 1) {
      //ppn(t); ppn(opt[t]);
      if (opt[t] == 0) {
        res = "The robber has escaped.\n";
        break;
      } else if (opt[t] == 1) {
        char temp[10000];
        sprintf(temp, "Time step %d: The robber has been at %d,%d.\n",
            t, canx[t] + 1, cany[t] + 1);
        res += temp;  // n square!!
      }//*/
    }

    if (res.empty()) {
      res = "Nothing known.\n";
    }
    
    /*
    r(t, T + 1) {
      ppn(t);
      r(x, w) {
        r(y, h) {
          cout << can[t][x][y];
        }
        cout << endl;
      }
      cout << endl;
    }
    cout << endl;//*/

    cout << "Robbery #" << TEST << ":" << endl << res << endl;
  }
} 

