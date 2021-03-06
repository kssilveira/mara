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
    int n;
    cin >> n;
    int v[1010];
    ri {
      cin >> v[i];
    }
    sort(v, v + n);
    //reverse(v + 2, v + n);
    int a = v[0], b = v[1];
    int res = 0;
    ostringstream out;
    if (n == 0) {
    } else if (n == 1) {
      res += a;
      out << a << endl;
    } else {
      //res += b;
      //out << a << ' ' << b << endl;
      int cur = n - 2;
      while (cur >= 1) {
        //res += a;
        //out << a << endl;
        int c = v[cur], d = v[cur + 1];
        if (cur == 1) {
          c = d;
          res += c;
          out << a << ' ' << c << endl;
          res += a;
          out << a << endl;
        } else if (a + c <= b + b) {
          res += c;
          out << a << ' ' << c << endl;
          res += a;
          out << a << endl;
          res += d;
          out << a << ' ' << d << endl;
          res += a;
          out << a << endl;
        } else {
          res += b;
          out << a << ' ' << b << endl;
          res += a;
          out << a << endl;
          res += d;
          out << c << ' ' << d << endl;
          res += b;
          out << b << endl;
          //res += b;
          //out << a << ' ' << b << endl;
        }
        cur -= 2;
      }
      res += b;
      out << a << ' ' << b << endl;
    }
    cout << res << endl;
    cout << out.str();
  }
} 

