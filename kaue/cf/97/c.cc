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

string s;
bitset<100010> dead;

int main() {
  cin >> s;
  int n = s(s);
  int c0, c1, c2;
  c0 = c1 = c2 = 0;
  ri {
    if (s[i] == '0') {
      c0++;
    } else if (s[i] == '1') {
      c1++;
    } else {
      c2++;
    }
  }
  set<string> res;
  int ma = ((n - 2) + 1) / 2;
  int pe = (n - 2) - ma;
  //ppn(ma);
  //ppn(pe);
  //ppn(c1 + c2);
  //ppn(c0 + c2);
  if (ma >= c1 + c2) {
    if (c0 >= 2)
      res.insert("00");
  }
  if (ma == c1 + c2 - 1) {
    if (s[n - 1] == '1') {
      if (c0 || c2)
        res.insert("01");
    } else if (s[n - 1] == '?') {
      if (c0 || c2 > 1)
        res.insert("01");
    } else {
      if (c1 || c2)
        res.insert("10");
    }
  }

  if (pe >= c0 + c2) {
    if (c1 >= 2)
      res.insert("11");
  }
  if (pe == c0 + c2 - 1) {
    if (s[n - 1] == '0') {
      if (c1 || c2)
        res.insert("10");
    } else if (s[n - 1] == '?') {
      if (c1 || c2 > 1)
        res.insert("10");
    } else {
      if (c0 || c2)
        res.insert("01");
    }
  }

  for (set<string>::iterator it = res.begin();
      it != res.end(); ++it) {
    cout << *it << endl;
  }
}
