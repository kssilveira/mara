#include <algorithm>
#include <iomanip>
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

const ld PI = 4 * atan(1);

inline ld sqr(ld x) { return x * x; }
 
int main() {
  int a, b;
  cout << "PI: " << PI << endl;
  int Case = 1;
  while (scanf("%d : %d", &a, &b) == 2) {
    ld low = 0, high = 400;
    //cout << "coef: " << coef << endl;
    while (high - low > 1e-10) {
      ld length = low + (high - low) / 2;
      ld width = length * b / ld(a);
      //length = 117.1858168913;
      //width = 78.123877927;
      //length = 107.2909560477;
      //width = 85.8327648381;
      ld coef = (width + width) / ld(width + width + length + length);
      //cout << "length: " << length << " width: " << width << endl;
      ld diag = sqrt(sqr(length) + sqr(width));
      ld radius = diag / 2;
      ld arc = 2 * PI * radius * coef;
      ld per = 2 * length + arc;
      per = 2 * length + 2 * width;
      //cout << "per: " << per << endl;
      if (per <= 400) {
        low = length;
      } else {
        high = length;
      }
    }
    ld length = low + (high - low) / 2;
    ld width = length * b / ld(a);
    cout << "Case " << Case << ": " << fixed << setprecision(10)
      << length << fixed << setprecision(10) << endl << width << endl;
    Case++;
  }
} 

