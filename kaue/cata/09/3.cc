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

bool compatible(int last_mask, int mask) {
  int masks[2] = {last_mask, mask};
  int mat[2][3] = {{0}};
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      mat[i][j] = masks[i] & (1 << j);
    }
  }
  /*
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      cout << mat[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;//*/

  bool good[3] = {0};
  for (int j = 0; j < 3; j++) {
    if (!mat[1][j]) continue;
    if (mat[0][j]) good[j] = true;
  }

  for (int j = 0; j < 3; j++) {
    if (!mat[1][j]) continue;
    if (good[j]) continue;
    bool found = false;
    if (j - 1 >= 0 && good[j - 1]) found = true;
    if (j + 1 < 3 && good[j + 1]) found = true;
    if (found) good[j] = true;
  }

  for (int j = 0; j < 3; j++) {
    if (!mat[1][j]) continue;
    if (good[j]) continue;
    bool found = false;
    if (j - 1 >= 0 && good[j - 1]) found = true;
    if (j + 1 < 3 && good[j + 1]) found = true;
    if (found) good[j] = true;
  }

  for (int j = 0; j < 3; j++) {
    if (!mat[1][j]) continue;
    if (good[j]) continue;
    bool found = false;
    if (j - 1 >= 0 && good[j - 1]) found = true;
    if (j + 1 < 3 && good[j + 1]) found = true;
    if (!found) return false;
  }

  return true;
}

int count(int mask) {
  int res = 0;
  while (mask > 0) {
    if (mask & 1) res++;
    mask >>= 1;
  }
  return res;
}

ull solve(int n, int last_mask) {
  //printf("solve(%i, %x, %x)\n", n, last_mask, this_mask);
  ull res = 0;
  if (n == 0) {
    if (last_mask == 7) {
      return res = 1;
    }
    return 0;
  }
  for (int mask = 1; mask < 8; mask++) {
    int d = count(mask);
    if (compatible(last_mask, mask) && n - d >= 0) {
      res += solve(n - d, mask);
    }
  }
  return res;
}
 
int main() {
  int n;
  //ppn(compatible(0, 7, 4));
  while (cin >> n && n) {
    ull res = 0;
    if (n >= 6)
      res = solve(n - 3, 7);
    cout << n << " : " << res << endl;
  }
} 

