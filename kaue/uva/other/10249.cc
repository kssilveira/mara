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
  int m, n;
  while (cin >> m >> n && m && n) {
    vector<pair<int, int> > team, table;
    vector<int> res[110];
    r(i, m) {
      int v;
      cin >> v;
      team.push_back(make_pair(v, i));
    }
    r(i, n) {
      int v;
      cin >> v;
      table.push_back(make_pair(v, i));
    }
    sort(all(team));
    reverse(all(team));
    sort(all(table));
    reverse(all(table));
    r(i, n) {
      r(j, m) {
        if (team[j].first) {
          team[j].first--;
          res[team[j].second].push_back(table[i].second);
          table[i].first--;
          if (!table[i].first) break;
        }
      }
    }
    bool found = false;
    r(j, m) {
      if (team[j].first) {
        found = true;
        break;
      }
    }
    if (!found) {
      cout << "1" << endl;
      r(i, m) {
        sort(all(res[i]));
        r(j, s(res[i])) {
          if (j) cout << ' ';
          cout << res[i][j] + 1;
        }
        cout << endl;
      }
    } else {
      cout << "0" << endl;
    }
  }
} 

