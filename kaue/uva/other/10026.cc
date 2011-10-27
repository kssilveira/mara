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

bool comp(const pair<pair<int, int>, int>& r,
    const pair<pair<int, int>, int>& l) {
  int v1 = l.first.second * r.first.first,
    v2 = l.first.first * r.first.second;
  return v1 < v2 || (v1 == v2 && l.second > r.second);
}
 
int main() {
  int T;
  cin >> T;
  bool second = false;
  while (T--) {
    if (second) cout << endl;
    second = true;
    int n;
    cin >> n;
    vector<pair<pair<int, int>, int> > v;
    ri {
      int a, b;
      cin >> a >> b;
      v.push_back(make_pair(make_pair(a, b), i + 1));
    }
    sort(all(v), comp);
    //reverse(all(v));
    ri {
      if (i) cout << ' ';
      cout << v[i].second;
    }
    cout << endl;
  }
} 

