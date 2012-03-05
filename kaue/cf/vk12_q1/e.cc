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
 
ll end[4010][4010];

int main() {
  int n, k;
  cin >> n >> k;
  //if (!n || n <= k) {
     //cout << 86400 << endl;
     //return 0;
  //}
  vector<pair<ll, ll> > v;
  ri {
    ll t, d;
    cin >> t >> d;
    v.push_back(make_pair(t, d));
  }
  sort(all(v));
  /*
  ri {
    cout << '(' << v[i].first << ' ' << v[i].second << ')' << ' ';
  }
  nl;//*/

  r(i, n + 1) {
    end[0][i] = 1;
  }
  ri {
    end[i + 1][0] = max(v[i].first, end[i][0]) + v[i].second;
    rb(j, 1, k + 1) {
      end[i + 1][j] = min(end[i][j - 1],
          max(end[i][j], v[i].first) + v[i].second);
    }
  }
  /*
  r(i, n + 1) {
    r(j, k + 1) {
      printf("%10Li ", end[i][j]);
    }
    cout << endl;
  }
  nl;//*/
  ll res = 0;
  ri {
    for (int j = i; j >= 0; j--) {
      int rest = k - (i - j);
      if (rest < 0) break;
      ll cur = v[i].first - end[j][rest];

        //ppn(i); ppn(v[i].first);
        //ppn(j);
        //ppn(rest); ppn(end[j][rest]);
        //ppn(cur);

      if (cur > res) {
        res = cur;
      }
    }
  }
  res = max(res, 86401 - end[n][k]);
  cout << res << endl;
} 

