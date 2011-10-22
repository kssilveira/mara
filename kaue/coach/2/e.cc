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

    vi v;
    int change[510][510] = {{0}};
    int ind[510];
    int newind[510];

bool solve(int first, int second) {
  int a = v[first],
      b = v[second];
  bool invalid = false;
      while (first < second) {
        /*
        ri {
          if (i) cout << " ";
          cout << v[i];
        }
        cout << endl;//*/
        //ppn(first);
        //ppn(second);
        int next = v[first + 1];
        //ppn(next);
        if (change[a][next]) {
          //p("change\n");
          swap(v[first], v[first + 1]);
          ind[a] = first + 1;
          ind[next] = first;
          first++;
          change[a][next] = change[next][a] = 0;
          continue;
        }

        next = v[second - 1];
        if (change[next][b]) {
          swap(v[second - 1], v[second]);
          ind[b] = second - 1;
          ind[next] = second;
          second--;
          change[next][b] = change[b][next] = 0;
          continue;
        }

        if (solve(first + 1, second - 1)) {
          continue;
        }

        invalid = true;
        break;
      }
      if (first != second) {
        invalid = true;
      }
  return invalid;
}
 
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    memset(change, 0, sizeof(change));
    v.clear();
    ri {
      int t;
      cin >> t;
      ind[t] = i;
      newind[t] = i;
      v.push_back(t);
    }
    int m;
    cin >> m;
    vector<pair<int, pair<int, int> > > inv;
    r(i, m) {
      int a, b;
      cin >> a >> b;
      if (ind[a] > ind[b]) {
        newind[a]--;
        newind[b]++;
      } else {
        newind[a]++;
        newind[b]--;
      }
      change[a][b] = change[b][a] = 1;
      inv.push_back(make_pair(abs(ind[a] - ind[b]), make_pair(a, b)));
    }
    sort(all(inv));
    bool invalid = false;
    int res[510] = {0};
    rb(i, 1, n + 1) {
      //ppn(i);
      //ppn(newind[i]);
      if (res[newind[i]]) invalid = true;
      res[newind[i]] = i;
    }

    r(i, m) {
      int a = inv[i].second.first;
      int b = inv[i].second.second;

      //ppn(a);
      //ppn(b);
      //ppn(ind[a]);
      //ppn(ind[b]);
      //ppn(newind[a]);
      //ppn(newind[b]);

      if (
          ((newind[a] > newind[b]) != (ind[b] > ind[a]))) {
        invalid = true;
        break;
      }
    }

    if (!invalid) {
      ri {
        if (i) cout << " ";
        cout << res[i];
      }
      cout << endl;
    } else {
      cout << "IMPOSSIBLE" << endl;
    }
  }
} 

