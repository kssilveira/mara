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

int f(int n, int d) {
  int res = 0;
  int v[][2] = {{1, 2}, {2, 2}, {2, 3}, {4, 0}};
  switch (n) {
    case 3:
      res += v[d][0];
    case 2:
      res += v[d][0];
    case 1:
      res += v[d][0];
      break;
    case 8:
      res += v[d][0];
    case 7:
      res += v[d][0];
    case 6:
    case 4:
      res += v[d][0];
    case 5:
      res += v[d][1];
      break;
    case 9:
      res += v[d][0];
      res += v[d + 1][0];
  }
  //printf("f(%d, %d) = %d\n", n, d, res);
  return res;
}
 
int main() {
  int n;
  while (cin >> n) {
    int i = 0;
    int res = 0;
    while (n) {
      res += f(n % 10, i);
      n /= 10;
      i++;
    }
    cout << res << endl;
  }
} 

