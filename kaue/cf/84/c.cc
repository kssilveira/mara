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
  int n;
  cin >> n;
  string realres;
  int resi = -1;
  int resn = 0;
  for(int i = 0; 7 * i <= n; i++) {
    int rest = n - 7 * i;
    //ppn(rest);
    if (rest % 4 == 0 &&
        (resn == 0 || i + rest / 4 < resn)) {
      resi = i;
      resn = i + rest / 4;
    }
  }

  if (resn) {
    int i = resi;
    int rest = n - 7 * i;
    string res;
    for (int j = 0; j < rest / 4; j++) {
      res += '4';
    }
    for (int j = 0; j < i; j++) {
      res += '7';
    }
    //cout << res << endl;
    if (res.size() < realres.size() || realres.empty()) {
      realres = res;
    }
  }
  if (realres.empty()) {
    cout << "-1" << endl;
  } else {
    cout << realres << endl;
  }
} 

