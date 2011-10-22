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
  int T;
  cin >> T;
  while (T--) {
    vector<pair<int, int> > v;
    vi orig;
    int p, n;
    cin >> p >> n;
    int sum = 0;
    ri {
      int a;
      cin >> a;
      v.push_back(make_pair(a, -i));
      orig.push_back(a);
      sum += a;
    }
    sort(all(v));
    reverse(all(v));
    /*
    ri {
      cout << v[i].first <<  " => " << v[i].second << endl;
    }
    cout << endl;//*/
    if (sum < p) {
      cout << "IMPOSSIBLE" << endl;
      continue;
    }

    int live = n;
    sum = p;
    while (sum > 0) {
      int cur = sum / live;
      //ppn(sum);
      //ppn(live);
      //ppn(cur);
      if (cur == 0) {
        //ppn(cur);
        cur = 1;
      }
      ri {
        if (sum == 0) break;
        int val = min(cur, v[i].first);
        //ppn(i); ppn(val);
        if (val != 0 && v[i].first == val) {
          live--;
        }
        v[i].first -= val;
        sum -= val;
      }
    }
    ri {
      orig[-v[i].second] = orig[-v[i].second] - v[i].first;
    }

    ri {
      if (i) cout << " ";
      cout << orig[i];
    }
    cout << endl;
  }
} 

