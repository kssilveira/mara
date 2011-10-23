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
 
int main() {
  int n;
  while (cin >> n) {
    //ppn(n);
    vector<pair<ll, pair<ll, ll> > > vert, horiz;
    ri {
      ll x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      if (x1 == x2) {
        vert.push_back(make_pair(x1, make_pair(
                min(y1, y2), max(y1, y2))));
      } else {
        horiz.push_back(make_pair(y1, make_pair(
                min(x1, x2), max(x1, x2))));
      }
    }
    sort(all(vert));
    sort(all(horiz));
    int nvert = s(vert);
    int nhoriz = s(horiz);

    /*/
    r(i, nvert) {
      cout << vert[i].first << ": " << 
        vert[i].second.first << ", " << vert[i].second.second << endl;
    }
    cout << endl;//*/

    /*/
    r(i, nhoriz) {
      cout << horiz[i].first << ": " << 
         horiz[i].second.first << ", " << horiz[i].second.second << endl;
    }
    cout << endl;//*/

    ll res = 0;
    r(i, nvert) {
      rb(j, i + 1, nvert) {
        ll cnt = 0;
        ll beg = max(vert[i].second.first, vert[j].second.first);
        ll end = min(vert[i].second.second, vert[j].second.second);
        if (beg >= end) continue;
        r(k, nhoriz) {
          if (horiz[k].first < beg || horiz[k].first > end)
            continue;
          if (horiz[k].second.first <= vert[i].first &&
              horiz[k].second.second >= vert[j].first) {
            cnt++;
          }
        }
        res += cnt * (cnt - 1) / 2;
      }
    }
    cout << res << endl;
  }
} 

