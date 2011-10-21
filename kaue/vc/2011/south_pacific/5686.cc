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
  int K;
  cin >> K;
  while (K--) {
    ull a, b;
    cin >> a;
    scanf(" / ");
    cin >> b;
rb(b, 3, 20) {
  rb(a, 1, b) {
    //ppn(a), ppn(b);
    cout << a << "/" << b << " => ";
    ull resnum, resden;
    ld me = 10e100;
    for (ull d = b - 1; d > 1; d--) {
      ld num = a * d / (ld) b;
      //ppn(d), ppn(num);
      int rnum = num + 0.5;
      //ppn(rnum);
      ld cur = fabs(rnum / (ld) d - a / (ld) b);
      if (cur <= me) {
        me = cur;
        resnum = rnum;
        resden = d;
      }
    }
    cout << resnum << "/" << resden << endl;
  }
  cout << endl;
}
return 0; }}

