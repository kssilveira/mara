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

const int MAX = 50000;
int r[MAX + 10];
int mm[MAX + 10][18]; // n, log(n) + 1
int n = MAX;

void construct() {
  r(i, n) mm[i][0] = r[i];
  rb(i, 1, 18) {
    for (int j = 0; (j + (1 << i) - 1) < n; j += (1 << i)) {
      mm[j][i] = max(mm[j][i - 1], mm[j + (1 << (i - 1))][i - 1]);
    }
  }
}

int getmax(int a, int b) {
  if (a > b) return -1;
  for (int i = 17; i >= 0; i--) {
    if ((a % (1 << i)) == 0 && (a + (1 << i) - 1) <= b)
      return max(mm[a][i], getmax(a + (1 << i), b));
  }
  return -1;
}
 
int main() {
  srand(0xDEADBEEF);
  r(i, n) {
    r[i] = rand() % (999999 * n);
    //ppn(r[i]);
  }
  construct();
  //*
  r(t, 1000) {
    int a = rand() % n, b = rand() % n;
    if (a > b) swap(a, b);
    int res = -1;
    for (int i = a; i <= b; i++) {
      res = max(res, r[i]);
    }
    printf("(%d, %d) = %d\n", a, b, res);
    assert(res == getmax(a, b));
  }//*/
} 

