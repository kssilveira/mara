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

const int MOD = 12 * 60;
 
int main() {
  int T;
  cin >> T;
  while (T--) {
    int v[3];
    int ho[3], mo[3];
    r(i, 3) {
      int h, m;
      scanf("%d:%d", &h, &m);
      ho[i] = h;
      mo[i] = m;
      v[i] = h * 60 + m;
      v[i] %= MOD;
      //ppn(h); ppn(m); ppn(v[i]);
    }

    int perm[] = {0, 1, 2};
    int cnt = 0;
    int res = -1;
    do {
      int v0 = v[perm[0]],
          v1 = v[perm[1]],
          v2 = v[perm[2]];
      r(i, 481) {
        if ((v0 + i) % MOD == v1 &&
            (v0 - i + MOD) % MOD == v2) {
          if (res != perm[0]) cnt++;
          //ppn(cnt);
          //ppn(i);
          //ppn(perm[0]);
          res = perm[0];
        }
      }
    } while(next_permutation(perm, perm + 3));
    //ppn(cnt);
    if (cnt == 1) {
      printf("The correct time is %d:%02d\n", ho[res], mo[res]);
    } else {
      printf("Look at the sun\n");
    }
  }
} 

