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
  int a, b, c;
  while (cin >> a >> b >> c && a) {
    int resa, resb, resc;
    resa = resb = resc = 0;
    if (a == b && b == c) {
      if (a != 13) {
        resa = resb = resc = a + 1;
      }
    } else {
      if (a == c) {
        swap(b, c);
      } else if (b == c) {
        swap(a, c);
      }
      if (a == b) {
        resa = a; resb = b; resc = c + 1;
        if (resc == resa) {
          resc++;
        }
        if (resc > 13) {
          resc = 1;
          resa = ++resb;
          if (resa > 13) {
            resa = resb = resc = 1;
          }
        }
      } else {
        resa = 1; resb = 1; resc = 2;
      }
    }
    int v[] = {resa, resb, resc};
    sort(v, v + 3);
    if (v[0] == 0) {
      cout << '*' << endl;
    } else {
      cout << v[0] << ' ' << v[1] << ' ' << v[2] << endl;
    }
  }
} 

