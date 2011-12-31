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

ull solve1(ull n, ld val) {
  ld res = 1;
  while (n) {
    if (n & 1) res *= val;
    val *= val;
    if (log10(res) > 9) return 0;
    n >>= 1;
  }
  if (log10((ull)(res + 0.5)) > 9) return 0;
  return res + 0.5;
}

void solve2(ull N, ld Val, ull& resa, ull& resb, ull& resc) {
  ull n = N;
  ld val = Val;
  ld res = 1;
  ld MAX = 1000000000;
  while (n) {
    if (n & 1) res *= val;
    val *= val;
    res -= ((ull)(res / MAX)) * MAX;
    val -= ((ull)(val / MAX)) * MAX;
    n >>= 1;
  }
  resa = res + 0.5;
  resa %= 1000;
  n = N;
  val = Val;
  res = 1;
  while (n) {
    res = max(res, (ld)1.);
    if (n & 1) res *= val;
    val *= val;
    while (log10(res) > 5 || log10(val) > 5) {
      res /= 10;
      val /= 10;
    }
    n >>= 1;
  }
  resb = res;
  resc = ceil(N * log10(Val));
}
 
int main() {
  ull n;
  char c;
  map<char, string> name;
  name['G'] = "Golden";
  name['S'] = "Silver";
  name['B'] = "Bronze";
  map<char, ld> val;
  val['G'] = (1 + sqrt(5)) / 2;
  val['S'] = (2 + sqrt(8)) / 2;
  val['B'] = (3 + sqrt(13)) / 2;
  while (cin >> n >> c) {
    printf("The %llu%s %s Power is ", n, n == 1 ? "st" : n == 2 ? "nd" :
        n == 3 ? "rd" : "th", name[c].c_str());
    ull res = solve1(n, val[c]);
    if (res == 0) {
      ull resa, resb, resc;
      solve2(n, val[c], resb, resa, resc);
      printf("%llu...%03llu(%llu digits)", resa, resb, resc);
    } else {
      printf("%llu", res);
    }

    printf(".\n");
  }
} 

