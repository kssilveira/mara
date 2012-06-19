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

//map<int, map<int, int> > memo;

ll MOD = 1000000007;
ll fat[100010], invfat[100010];
ll comb(ll n, ll k) {
  return (((fat[n] * invfat[k]) % MOD) * invfat[n - k]) % MOD;
  /*
  if (n - k < k) {
    return comb(n, n - k);
  }
  if (memo[n][k]) return memo[n][k];
  ll res = 1;
  for (ll i = n - k + 1; i <= n; i++) {
    res *= i;
    res %= MOD;
  }
  for (ll i = 2; i <= k; i++) {
    res *= inv[i];
    res %= MOD;
  }
  memo[n][k] = res;
  return res;//*/
}

ll pot(ll b, ll e) {
  ll res = 1;
  while (e) {
    if (e & 1) {
      res *= b;
      res %= MOD;
    }
    e /= 2;
    b *= b;
    b %= MOD;
  }
  return res;
}
 
int cnt[100010], val[100010], memo[100010];
map<int, int> agg, valgg;
typedef map<int, int>::const_iterator It;

int main() {
  fat[0] = invfat[0] = 1;
  for (int i = 1; i < 100010; i++) {
    fat[i] = (fat[i - 1] * i) % MOD;
    invfat[i] = pot(fat[i], MOD - 2);
  }
  
  /*
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j <= i; j++) {
      cout << comb(i, j) << ' ';
    }
    nl;
  }
  nl;//*/

  int n;
  cin >> n;
  agg.clear();
  int nmax = 0;
  ri {
    cin >> cnt[i];
    nmax = max(nmax, cnt[i]);
    agg[cnt[i]]++;
  }
  int Q;
  cin >> Q;
  memset(memo, 0, sizeof(memo));
  r(qq, Q) {
    int s;
    cin >> s;
    //ppn(s);
    if (s > nmax) s = nmax;
    if (memo[s]) {
      //cout << "IN!!!" << endl;
      cout << memo[s] << endl;
      continue;
    }
    int total = 0;
    int odd = 0;
    valgg.clear();
    for (It it = agg.begin(); it != agg.end(); ++it) {
      valgg[(it->first + s - 1) / s] += it->second;
    }
    for (It it = valgg.begin(); it != valgg.end(); ++it) {
      total += it->first * it->second;
      odd += (it->first % 2) * it->second;
    }
    ll res = fat[total];
    for (It it = valgg.begin(); it != valgg.end(); ++it) {
      res *= pot(invfat[it->first], it->second);
      res %= MOD;
    }
    res /= 2;
    //ppn(res);
    if (odd < 2) {
      int cur = 0;
      for (It it = valgg.begin(); it != valgg.end(); ++it) {
        cur += (it->first / 2) * it->second;
      }
      ll other = fat[cur];
      for (It it = valgg.begin(); it != valgg.end(); ++it) {
        //other *= (it->second * comb(cur, it->first / 2)) % MOD;
        //other *= pot(comb(cur, it->first / 2), it->second);
        other *= pot(invfat[it->first / 2], it->second);
        other %= MOD;
      }
      res += (other + 1) / 2;
      res %= MOD;
    }
    cout << res << endl;
    memo[s] = res;
  }
} 
