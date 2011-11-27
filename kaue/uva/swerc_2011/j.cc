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

const int MOD = 1000000007;
const int MAX = 5000100;

bitset<MAX> isnotprime;

ll pot(ll x, ll e) {
  ll res = 1;
  ll base = x;
  while (e) {
    if (e & 1) {
      res *= base;
      res %= MOD;
    }
    e /= 2;
    base *= base;
    base %= MOD;
  }
  return res % MOD;
}

vector<int> primes;

// TODO: SWERC 2011 J Remoteland
// UVa 12396 - Remoteland
// http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=278&problem=3818&mosmsg=Submission+received+with+ID+9511531
// Passed during the contest, but TLE after.

int main() {
  int n;
  primes.push_back(2);
  for (int i = 3; i / 2 < MAX; i += 2) {
    if (!isnotprime[i / 2]) {
      primes.push_back(i);
      for (int j = i + i; j / 2 < MAX; j += i) {
        if (j % 2) {
          isnotprime[j / 2] = 1;
        }
      }
    }
  }
  //ppn(s(primes));
  /*
  r(i, 10) {
    cout << primes[i] << ' ';
  }
  cout << endl;//*/
  while (scanf("%d", &n) && n > 0) {
    ll res = 1;
    for (int i = 0; n / primes[i] > 1; i++) {
      int cnt = 0;
      ll val = primes[i];
      while (val <= n) {
        cnt += n / val;
        val *= primes[i];
      }
      if (cnt % 2) {
        cnt--;
      }
      res *= pot(primes[i], cnt);
      res %= MOD;
    }
    printf("%lld\n", res);
  }
} 

