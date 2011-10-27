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
  int Case = 0;
  bool second = false;
  while (cin >> n && n) {
    Case++;
    if (second) cout << endl;
    second = true;
    int best[510][110] = {{0}},
        ind[510][110] = {{0}},
        side[510][110] = {{0}},
        from[510][110] = {{0}};
    rb(i, 1, n + 1) {
      r(j, 101) {
        best[i][j] = best[i - 1][j];
        ind[i][j] = ind[i - 1][j];
        side[i][j] = side[i - 1][j];
        from[i][j] = from[i - 1][j];
      }
      r(j, 3) {
        int a, b;
        cin >> a >> b;
        if (best[i - 1][a] + 1 > best[i][b]) {
          best[i][b] = best[i - 1][a] + 1;
          ind[i][b] = i;
          side[i][b] = 2 * j + 1;
          from[i][b] = a;
        }
        swap(a, b);
        if (best[i - 1][a] + 1 > best[i][b]) {
          best[i][b] = best[i - 1][a] + 1;
          ind[i][b] = i;
          side[i][b] = 2 * j;
          from[i][b] = a;
        }
      }
    }
    int jres = 0;
    r(j, 101) {
      if (best[n][j] > best[n][jres]) {
        jres = j;
      }
    }

    cout << "Case #" << Case << endl;
    cout << best[n][jres] << endl;
    int i = n;
    //string name[] = {"front", "back", "left", "right", "top", "bottom"};
    string name[] = {"back", "front", "right", "left", "bottom", "top"};
    stack<pair<int, string> > res;
    while (ind[i][jres] >= 1) {
      res.push(make_pair(ind[i][jres], name[side[i][jres]]));
      //cout << ind[i][jres] << ' ' << name[side[i][jres]] << endl;
      int nexti = ind[i][jres] - 1;
      jres = from[i][jres];
      i = nexti;
    }
    
    while (!res.empty()) {
      cout << res.top().first << ' ' << res.top().second << endl;
      res.pop();
    }
  }
} 

