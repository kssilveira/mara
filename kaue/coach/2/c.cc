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
  while (T--) {
    string s;
    cin >> s;
    int res = 0;
    vector<int> v;
    r(i, s(s)) {
      int cur = min(s[i] - 'A', 'Z' - s[i] + 1);
      //ppn(s[i]);
      //ppn(cur);
      res += cur;
      v.push_back(0);
      if (s[i] != 'A') {
        v[i] = 1;
      }
    }
    //ppn(res);
    int n = s(s);
    /*
    ri {
      cout << v[i] << ' ';
    }
    cout << endl;//*/
    int i = 0;
    int nmin = n - 1;
    while (1) {
      //ppn(nmin);
      while (i < n && v[i] != 0) i++;
      if (i == n) break;
      int first = max(i - 1, 0);
      i++;
      while (i < n && v[i] == 0) i++;
      int second = i;
      //ppn(first);
      //ppn(second);
      int c1 = 2 * first + n - second;
      //ppn(c1);
      nmin = min(nmin, c1);
      int c2 = 2 * (n - second) + first;
      //ppn(c2);
      nmin = min(nmin, c2);
    }
    cout << nmin + res << endl;
  }
} 

