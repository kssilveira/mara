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
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;

const int MAX = 100010;
int x[MAX], y[MAX], nmin[4][2 * MAX], nmax[4][2 * MAX];
 
int main() {
  int n, m;
  cin >> m >> n;

  ri {
    cin >> x[i] >> y[i];
  }

  memset(nmin, 100, sizeof(nmin));
  memset(nmax, 0, sizeof(nmax));

  ri {
    //cnt[0][x[i]]++;
    //cnt[1][y[i]]++;
    //cnt[2][x[i] + y[i]]++;
    //cnt[3][x[i] - y[i] + m]++;

    nmin[0][x[i]] = min(nmin[0][x[i]], y[i]);
    nmin[1][y[i]] = min(nmin[1][y[i]], x[i]);
    nmin[2][x[i] + y[i]] = min(
        nmin[2][x[i] + y[i]], x[i]);
    nmin[3][x[i] - y[i] + m] = min(
        nmin[3][x[i] - y[i] + m], x[i]);

    nmax[0][x[i]] = max(nmax[0][x[i]], y[i]);
    nmax[1][y[i]] = max(nmax[1][y[i]], x[i]);
    nmax[2][x[i] + y[i]] = max(
        nmax[2][x[i] + y[i]], x[i]);
    nmax[3][x[i] - y[i] + m] = max(
        nmax[3][x[i] - y[i] + m], x[i]);
  }

  int res[10] = {0};
  ri {
    //ppn(i);
    //ppn(x[i]);
    //ppn(y[i]);

    //ppn(nmin[0][x[i]]);
    //ppn(nmax[0][x[i]]);

    int cnt = 0;
    if (y[i] != nmin[0][x[i]]) cnt++;
    if (x[i] != nmin[1][y[i]]) cnt++;
    if (x[i] != nmin[2][x[i] + y[i]]) cnt++;
    if (x[i] != nmin[3][x[i] - y[i] + m]) cnt++;

    if (y[i] != nmax[0][x[i]]) cnt++;
    if (x[i] != nmax[1][y[i]]) cnt++;
    if (x[i] != nmax[2][x[i] + y[i]]) cnt++;
    if (x[i] != nmax[3][x[i] - y[i] + m]) cnt++;

    res[cnt]++;
  }

  r(i, 9) {
    if (i) cout << ' ';
    cout << res[i];
  }
  cout << endl;
} 

