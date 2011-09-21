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
#define pv(v) ri { p(v[i]); } pl;
#define pm(m) ri { rjm { p(m[i][j]); } pl; } pl;
 
#define p(x) cout << x << " "
#define pl cout << endl
#define pn(x) cout << x << endl
 
#define s(v) ((int) v.size())
#define all(v) v.begin(), v.end()
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
 
int main() {
  int n, m;
while(cin >> n >> m) {
  int tab[155][155] = {{0}};
  ri {
    rjm {
      char c;
      cin >> c;
      if (c == 'W') {
        tab[i][j] = 1;
      }
    }
  }
  // pm(tab);
  int minj[155], maxj[155], last = 0;
  ri {
    minj[i] = 155;
    maxj[i] = -1;
    rjm {
      if (tab[i][j]) {
        minj[i] = min(minj[i], j);
        maxj[i] = max(maxj[i], j);
      }
      if (minj[i] != 155) last = i;
    }
  }
  minj[n] = minj[n - 1];
  maxj[n] = maxj[n - 1];
  // pv(minj);
  // pv(maxj);
  int cur = 0, res = 0;
  ri {
    if (i > last) break;
    if (i % 2 == 0) {
      int end = max(maxj[i], maxj[i + 1]);
      if (end == -1) end = cur;
      res += abs(end - cur);
      cur = end;
    } else {
      int end = min(minj[i], minj[i + 1]);
      if (end == 155) end = cur;
      res += abs(cur - end);
      cur = end;
    }
    // p(res);
  }
  cout << res + last << endl;
}
} 

