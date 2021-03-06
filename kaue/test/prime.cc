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

bool suspect(ll b, int t, ll u, ll n) {
  ll prod = 1;
  while (u) {
    if (u & 1) prod = ((prod * b) % n);
    b = (b * b) % n;
    u /= 2;
  }
  if (prod == 1) return 1;
  rb(i, 1, t + 1) {
    if (prod == n - 1) return 1;
    prod = (prod * prod) % n;
  }
  return 0;
}

bool isprime(int n) {
  if (n == 0 || n == 1) return 0;
  if (n == 2 || n == 7 || n == 61) return 1;
  ll k = n - 1;
  int t = 0;
  while (!(k % 2)) { t++; k /= 2; }
  if (n > 2 && n % 2 == 0) return 0;
  if (n > 3 && n % 3 == 0) return 0;
  if (n > 5 && n % 5 == 0) return 0;
  if (n > 7 && n % 7 == 0) return 0;
  if (suspect(61, t, k, n) && suspect(7, t, k, n) &&
      suspect(2, t, k, n)) {
    return 1;
  }
  return 0;
}
 
int main() {
  const int n = 10000;
  bitset<n + 10> isnotprime;
  isnotprime[0] = isnotprime[1] = 1;
  r(i, 100) {
    if (isprime(i)) {
      cout << i << ' ';
    }
  }
  rb(i, 2, n) {
    //ppn(i);
    assert(isprime(i) == !isnotprime[i]);
    if (isnotprime[i]) {
      continue;
    }
    for (int j = i + i; j < n; j += i) {
      isnotprime[j] = true;
    }
  }
}

