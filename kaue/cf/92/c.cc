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

char str[222] = {0};
int N;

bool gone[222][222];
ll memo[222][222];
const ll inf = ll(2e18);
ll count(int n, int k) {
  //printf("count(%d, %d)\n", n, k);
  if (n < k || k < 0) return 0;
  ll& res = memo[n][k];
  if (gone[n][k]) return res;
  res = 0;
  if (n == k) {
    if (k == 0) {
      return res = 1;
    }
    if (str[N - n] != '(') {
      return res = count(n - 1, k - 1);
    }
    return res = 0;
  }
  if (str[N - n] != ')') {
    res += count(n - 1, k + 1);
    if (res > inf) res = inf;
  }
  if (str[N - n] != '(') {
    res += count(n - 1, k - 1);
    if (res > inf) res = inf;
  }
  gone[n][k] = true;
  return res;
}
 
int main() {
  int n, m;
  ll k;
  cin >> n >> m >> k;
  int val[222] = {0};
  int tab[110][110] = {{0}};
  ri {
    rjm {
      cin >> tab[i][j];
      int ind = i + j;
      if (val[ind] == 0) {
        val[ind] = tab[i][j];
      }
      val[ind] = min(val[ind], tab[i][j]);
    }
  }
  int nval = (n - 1) + (m - 1) + 1;
  N = nval;
  //ppn(nval);
  vector<pair<int, int> > v;
  r(i, nval) {
    v.push_back(make_pair(val[i], i));
  }
  sort(all(v));
  /*
  r(i, nval) {
    //cout << val[i] << ' ';
    printf("(%d, %d) ", v[i].first, v[i].second);
  }
  cout << endl;//*/
  memset(str, 0, sizeof(str));
  ll total = k;
  r(i, nval) {
    str[v[i].second] = '(';
    memset(gone, 0, sizeof(gone));
    ll cur = count(nval, 0);
    //ppn(i);
    //ppn(v[i].second);
    //ppn(cur);
    //ppn(total);
    if (cur < total) {
      str[v[i].second] = ')';
      //memset(gone, 0, sizeof(gone));
      //ll next = count(nval, 0);
      //ppn(next);
      //if (next > 0) {
        total -= cur;
      //} else {
        //str[v[i].second] = '(';
      //}
    }
  }
  //ppn(total);
  //char mat[110][110] = {{0}};
  ri {
    rjm {
      //mat[i][j] = str[i + j];
      cout << str[i + j];
    }
    cout << endl;
  }
} 

