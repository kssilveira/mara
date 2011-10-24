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
 
int v[5010];

int main() {
  int T;
  cin >> T;
  while (T--) {
    int t, n;
    cin >> t >> n;
    ri {
      scanf("%2X", &v[i]);
      //printf("%2X ", v[i]);
    }
    //cout << endl;

    int cntdif = 0;
    //if (n == 1) cntdif = 1;
    vi res;
    int i;
    for(i = 0; i < n - 1; i++) {
      //ppn(i);
      //ppn(v[i]);
      //ppn(s(res));
      if (v[i] == v[i + 1]) {
        int cnt = 1;
        while (i + cnt < n && v[i] == v[i + cnt]) cnt++;

        //ppn(cnt);

        if (cnt >= 3 && cntdif > 0) {
          //ppn(cntdif);
          int where = i - cntdif;
          //ppn(where);
          while (cntdif > 128) {
            int val = 128 - 1;
            res.push_back(val);
            rb(j, where, where + 128) {
              res.push_back(v[j]);
            }
            where += 128;
            cntdif -= 128;
          }
          if (cntdif > 0) {
            int val = cntdif - 1;
            res.push_back(val);
            rb(j, where, where + cntdif) {
              res.push_back(v[j]);
            }
            where += cntdif;
            //assert(where == i);
            cntdif = 0;
          }
        }

        int total = cnt;

        while (cnt > 130) {
          int val = 130 - 3;
          val = val | (1 << 7);
          res.push_back(val);
          res.push_back(v[i]);
          cnt -= 130;
        }
        if (cnt >= 3) {
          int val = cnt - 3;
          val = val | (1 << 7);
          res.push_back(val);
          res.push_back(v[i]);
        } else {
          cntdif += cnt;
        }
        
        i += total - 1;
      } else {
        cntdif++;
      }
    }

    if (i == n - 1) cntdif++;

    if (cntdif > 0) {
      //ppn(cntdif);
      int i = n;
      int where = i - cntdif;
      while (cntdif > 128) {
        int val =  128 - 1;
        res.push_back(val);
        rb(j, where, where + 128) {
          res.push_back(v[j]);
        }
        where += 128;
        cntdif -= 128;
      }
      if (cntdif > 0) {
        int val = cntdif - 1;
        res.push_back(val);
        rb(j, where, where + cntdif) {
          res.push_back(v[j]);
        }
        where += cntdif;
        //assert(where == i);
      }
    }

    cout << t << ' ' << s(res) << endl;
    r(i, s(res)) {
      printf("%02X", res[i]);
      if ((i + 1) % 40 == 0 && i + 1 < s(res)) cout << endl;
    }
    cout << endl;
  }
} 

