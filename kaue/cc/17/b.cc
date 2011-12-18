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
#include <iomanip>
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
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()

#define pb push_back
#define mp make_pair
#define nl cout << endl
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
 
int main() {
  string s;
  cin >> s;
  int n = s(s);
  //ppn(s);
  ll res = 0;
  ri {
    s[i] -= '0';
  }
  ri {
    if (s[i] == 0 || s[i] == 8) res++;
  }
  //ppn(res);
  ri {
    if (i + 1 >= n) break;
    if (s[i] == 0) continue;
    int val = s[i]*10 + s[i + 1];
    if (val % 8 == 0) res++;
  }
  //ppn(res);
  int cnt = 0;
  ri {
    if (i + 2 >= n) break;
    int val = s[i] * 100 + s[i + 1] * 10 + s[i + 2];
    if (s[i] == 0) {
      cnt++;
    }
    if (val % 8 == 0) {
      res += (i + 1) - cnt;
    }
  }
  cout << res << endl;
} 

