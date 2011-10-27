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
  int TT = 0;
  while (cin >> n && n) {
    TT++;
    int s, t, c;
    cin >> s >> t >> c;
    s--; t--;
    int residual[110][110] = {{0}};
    int res = 0;
    r(l, c) {
      int i, j, k;
      cin >> i >> j >> k;
      i--; j--;
      residual[i][j] += k;
      residual[j][i] += k;
    }

    while (1) {
      queue<int> q;
      bool gone[110] = {0};
      q.push(s);
      int parent[110] = {0};
      parent[s] = -1;
      gone[s] = true;
      bool found = false;
      while (!q.empty()) {
        int cur = q.front();
        q.pop();
        //ppn(cur);
        if (cur == t) {
          found = true;
          break;
        }
        ri {
          if (residual[cur][i] && !gone[i]) {
            gone[i] = true;
            parent[i] = cur;
            q.push(i);
          }
        }
      }

      if (!found) break;

      int i = t;
      int other = parent[i];
      int add = INT_MAX;
      while (other != -1) {
        //ppn(i);
        add = min(add, residual[other][i]);
        i = other;
        other = parent[i];
      }
      //cout << endl;
      //ppn(add);

      res += add;

      if (add == 0) break;

      i = t;
      other = parent[i];
      while (other != -1) {
        residual[other][i] -= add;
        residual[i][other] += add;
        i = other;
        other = parent[i];
      }
    }

    cout << "Network " << TT << endl;
    cout << "The bandwidth is " << res << "." << endl;
    cout << endl;

    /*
    r(i, n) {
      r(j, n) {
        cout << flow[i][j] << ' ';
      }
      cout << endl;
    }
    cout << endl;//*/
  }
} 

