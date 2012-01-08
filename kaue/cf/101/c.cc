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
 
int main() {
  int n;
  cin >> n;
  string name[3010];
  int a[3010];
  vector<pair<int, int> > v, w;
  ri {
    cin >> name[i] >> a[i];
    v.push_back(make_pair(a[i], i));
  }
  sort(all(v));
  priority_queue<pair<int, int> > q;
  bool wrong = false;
  int res[3010];
  ri {
    int cur = v[i].first;
    //ppn(cur);
    w.clear();
    r(j, cur) {
      if (q.empty()) {
        wrong = true;
        break;
      }
      w.push_back(make_pair(q.top().first + 1, q.top().second));
      q.pop();
    }
    int add;
    if (q.empty()) {
      add = 0;
    } else {
      add = q.top().first + 1;
    }
    if (wrong) break;
    res[v[i].second] = add;

    //ppn(v[i].second); ppn(res[v[i].second]);

    q.push(make_pair(add, v[i].second));
    r(j, cur) {
      q.push(make_pair(w[j].first, w[j].second));
      res[w[j].second] = w[j].first;
    }
  }
  if (wrong) {
    cout << -1 << endl;
  } else {
    ri {
      cout << name[v[i].second] << ' ' << res[v[i].second] + 1 << endl;
    }
  }
} 

