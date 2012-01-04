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
  int mat[310][310] = {{0}}, val[310][310];
  int res[310] = {0};
  r(i, n + 1) {
    rj {
      int v;
      cin >> v;
      val[i][j] = v;
      mat[i][v] = j + 1;
    }
  }
  priority_queue<pair<int, int> > q;
  ri {
    q.push(make_pair(-(mat[n][i + 1]), i + 1));
    int cur = q.top().second;
    //ppn(cur);
    rj {
      if (cur == j + 1) {
        continue;
      }
      if (mat[j][res[j]] == 0 ||
          mat[j][res[j]] > mat[j][cur]) {
        res[j] = cur;
      }
    }
    if (q.size() > 1) {
      int curv = q.top().first;
      q.pop();
      int next = q.top().second;
      //ppn(next);
      if (mat[cur - 1][res[cur - 1]] == 0 ||
          mat[cur - 1][res[cur - 1]] > mat[cur - 1][next]) {
        res[cur - 1] = next;
      }
      q.push(make_pair(curv, cur));
    }

    /*
  ri {
    if (i) cout << ' ';
    cout << res[i];
  }
  nl;//*/

  }
  ri {
    if (i) cout << ' ';
    cout << res[i];
  }
  nl;
} 

