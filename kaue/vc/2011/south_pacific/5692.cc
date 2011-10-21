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

int count_bits(int mask) {
  int res = 0;
  while (mask > 0) {
    if (mask & 1) res++;
    mask >>= 1;
  }
  return res;
}
 
int main() {
  int t, n;
  while (cin >> t >> n && n) {
    ll v[7];
    ri {
      cin >> v[i];
      //ppn(v[i]);
    }
    ll nmin = -1;
    ll nres = 0;
    rb(mask, 1, 1 << n) {
      //ppn(mask);
      int perm[7] = {0, 1, 2, 3, 4, 5, 6};
      int ind = 0;
      ri {
        if (mask & (1 << i)) {
          perm[ind] = i;
          ind++;
        }
      }
      int nbits = ind;
      //ppn(nbits);
      do {
        ll val[7];
        r(i, nbits) {
          val[i] = v[perm[i]];
          //ppn(val[i]);
        }
        int noper = nbits - 1;
        r(oper_mask, 1 << (2 * noper)) {
          //ppn(oper_mask);
          ll res = val[0];
          r(i, noper) {
            int oper = (oper_mask & (3 << (2 * i))) >> (2 * i);
            //ppn(oper);
            if (oper == 0) {
              res += val[i + 1];
            }
            if (oper == 1) res -= val[i + 1];
            if (oper == 2) res *= val[i + 1];
            if (oper == 3) res /= val[i + 1];
          }
          //ppn(res);
          if (abs(res - t) < nmin || nmin == -1) {
            nmin = abs(res - t);
            nres = res;
            //ppn(nmin);
          }
        }
      } while(next_permutation(perm, perm + nbits));
    }
    //ppn(nres);
    cout << nres << endl;
  }
} 

