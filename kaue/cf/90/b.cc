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
 
int main() {
  int n, K;
  cin >> n >> K;
  int k = n / K;
  int a[110];
  ri {
    cin >> a[i];
  }
  int q;
  cin >> q;
  bool taken[110] = {0};
  int resmin = -1, resmax = -1;
  r(i, q) {
    int sum = 0;
    r(j, k) {
      int v;
      cin >> v;
      v--;
      taken[v] = 1;
      sum += a[v];
    }
    if (resmin == -1 || resmin > sum) {
      resmin = sum;
    }
    if (resmax == -1 || resmax < sum) {
      resmax = sum;
    }
    //cout << resmin << ' ' << resmax << endl;;
  }
  int b[110];
  int bind = 0;
  ri {
    if (!taken[i]) {
      b[bind++] = a[i];
    }
  }

  if (bind >= k && bind > n - K * k) {
    sort(b, b + bind);
    int sum = 0;
    r(i, k) {
      sum += b[i];
    }
      if (resmin == -1 || resmin > sum) {
        resmin = sum;
      }
      if (resmax == -1 || resmax < sum) {
        resmax = sum;
      }

    reverse(b, b + bind);
    sum = 0;
    r(i, k) {
      sum += b[i];
    }
      if (resmin == -1 || resmin > sum) {
        resmin = sum;
      }
      if (resmax == -1 || resmax < sum) {
        resmax = sum;
      }
  }

  cout << fixed << setprecision(10) <<
    resmin / (double)k << ' ' << resmax / (double) k << endl;
} 

