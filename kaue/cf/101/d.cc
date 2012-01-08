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
int memo[1000000];

  vector<pair<int, int> > v;
  int n, L;
  int x[100010], d[100010], t[100010], p[100010];
  int total[100010], jump[100010];

int solve(int cur) {
  int pos = v[cur].first, ind = v[cur].second;
  if (pos == L) return 0;
  int& res = memo[cur];
  if (res) return res;
  res = solve(cur + 1) + v[cur + 1].first - pos;
  total[cur] = total[cur + 1];
  jump[cur] = 0;
  if (pos < x[ind]) {
    int next = lower_bound(v.begin() + cur, v.end(), make_pair(x[ind] + d[ind], ind)) - v.begin();
    int nres = solve(next) + x[ind] - pos + t[ind];
    if (nres < res) {
      res = nres;
      total[cur] = 1 + total[next];
      jump[cur] = ind + 1;
    }
  }
  return res;
}

void output(int cur, bool space) {
  //ppn(cur);

  int pos = v[cur].first, ind = v[cur].second;

  if (pos == L) return;

  if (jump[cur] == 0) {
    output(cur + 1, space);
  } else {
    if (space) cout << ' ';
    cout << jump[cur];
    space = true;
    int next = lower_bound(v.begin() + cur, v.end(), make_pair(x[ind] + d[ind], ind)) - v.begin();
    output(next, space);
  }
}

 
int main() {
  cin >> n >> L;
  memset(memo, 0, sizeof(memo));
  memset(total, 0, sizeof(total));
  v.push_back(make_pair(L, -1));
  ri {
    cin >> x[i] >> d[i] >> t[i] >> p[i];
    if (t[i] > d[i]) continue;
    if (x[i] - p[i] >= 0) {
      v.push_back(make_pair(x[i] - p[i], i));
    }
    v.push_back(make_pair(x[i] + d[i], i));
  }
  sort(all(v));
  int res = solve(0) + v[0].first;
  cout << res << endl;
  cout << total[0] << endl;
  output(0, false);
  cout << endl;
} 

