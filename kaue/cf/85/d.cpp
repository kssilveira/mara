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

#define rep(i, n) repb(i, 0, n)
#define repb(i, b, n) repbc(i, b, n, <)
#define repe(i, n) repbe(i, 0, n)
#define repbe(i, b, n) repbc(i, b, n, <=)
#define repbc(i, b, n, c) for(int i = b; i c n; i++)

using namespace std;

typedef long long ll;

#define MOD 1000000007

ll powmod(ll x, ll n) {
  ll res = 1, exp = x;
  while (n > 0LL) {
    if (n & 1) {
      res = (res * exp) % MOD;
    }
    exp = (exp * exp) % MOD;
    n >>= 1;
  }
  return res % MOD;
}

ll inverse(ll i) {
  return powmod(i, MOD - 2) % MOD;
}

vector<ll> fact, rfact;

ll comb(ll n, ll k) {
  if (k > n) return 0;
  return (((fact[n] * rfact[k]) % MOD) * rfact[n - k]) % MOD;
}

int main() {
  fact.push_back(1);
  rfact.push_back(1);
  for (int i = 1; i < 1000001; i++) {
    fact.push_back((fact.back() * (ll) i) % MOD);
    rfact.push_back((rfact.back() * inverse(i)) % MOD);
  }
  ll dp[1010][1010] = {{0}};
  dp[0][0] = 1;
  for (int i = 1; i < 1010; i++) {
    for (int j = 1; j < 1010; j++) {
      dp[i][j] = (((dp[i - 1][j] * (ll)j) % MOD) + dp[i - 1][j - 1]) % MOD;
    }
  }
  /*
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {
      // cout << comb(i, j) << " ";
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;//*/
  ll n, m, k;
  cin >> n >> m >> k;

  if (m == 1) {
    cout << powmod(k, n);
    return 0;
  }

  ll res = 0;
  for (ll y = 0; y <= n; y++) {
    ll p = powmod(y, n * (m - 2));
    for (ll x = y; x <= n; x++) {
      if (2 * x - y > k) continue;
      ll cur = comb(k, 2 * x - y) % MOD;
      cur *= comb(2 * x - y, x - y);
      cur %= MOD;
      cur *= comb(x, x - y);
      cur %= MOD;
      cur *= dp[n][x];
      cur %= MOD;
      cur *= dp[n][x];
      cur %= MOD;
      cur *= fact[x];
      cur %= MOD;
      cur *= fact[x];
      cur %= MOD;
      cur *= p;
      cur %= MOD;
      res += cur;
      res %= MOD;
    }
  }

  cout << res << endl;
}
