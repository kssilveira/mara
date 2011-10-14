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

const int COL = 100 * 50 + 1;

  ull dp[51][COL][51] = {{{0}}};
  int what[51][COL][51];
  pair<int, int> from[51][COL][51];
 
int main() {
  ull n, m, K;
  cin >> n >> m >> K;
  vector< pair<int, pair< pair<ull, ull>, int> > > in;
  int curind = 1;
  map <ull, int> ind;
  r(i, m) {
    ull a, b, c;
    cin >> a >> b >> c;
    in.push_back(make_pair((int) c, make_pair(make_pair(a, b), i)));
    for (ull j = a; j <= b; j++) {
      if (!ind[j]) {
        ind[j] = curind;
        curind++;
      }
    }
  }

  sort(all(in));
  /*
  r(i, 3) {
    cout << in[i].first << ' ';
  }//*/

  ull res = 0;
  int bi, bj;
  r(i, s(in)) {
    //ppn(i);
    rb(len, 1, n + 1) {
      //ppn(len);
        ull a = in[i].second.first.first,
            b = in[i].second.first.second;
        //ppn(a); ppn(b);
        for (ull k = a; k <= b; k++) {
          //ppn(k);
          int index = ind[k];
          //ppn(index);
          if (len == 1 && index && k > dp[i][index][len]) {
            dp[i][index][len] = k;
            what[i][index][len] = in[i].second.second;
            from[i][index][len] = make_pair(-1, -1);
          }
          if (dp[i][index][n] > res) {
            res = dp[i][index][n];
            bi = i;
            bj = index;
          }
          if (len == 1) continue;
          if (k > K) {
            int other = ind[k - K];
            if (other) {
              for (int l = i - 1; l >= 0; l--) {
                if (in[l].first == in[i].first) continue;
                if (dp[l][other][len - 1] != 0 &&
                    dp[l][other][len - 1] + k > dp[i][index][len]) {
                  dp[i][index][len] = dp[l][other][len - 1] + k;
                  what[i][index][len] = in[i].second.second;
                  from[i][index][len] = make_pair(l, other);
                }
              }
            }
          }
          if (k % K == 0) {
            int other = ind[k / K];
            if (other) {
              for (int l = i - 1; l >= 0; l--) {
                if (in[l].first == in[i].first) continue;
                if (dp[l][other][len - 1] != 0 &&
                    dp[l][other][len - 1] + k > dp[i][index][len]) {
                  dp[i][index][len] = dp[l][other][len - 1] + k;
                  what[i][index][len] = in[i].second.second;
                  from[i][index][len] = make_pair(l, other);
                }
              }
            }
          }
          if (dp[i][index][n] > res) {
            res = dp[i][index][n];
            bi = i;
            bj = index;
          }
        }
    }
  } 
  if (res != 0) {
    cout << "YES" << endl;
    stack<pair<int, ull> > st;
    int len = n;
    while (len > 0) {
      st.push(make_pair(what[bi][bj][len], dp[bi][bj][len]));
      int nbi = from[bi][bj][len].first;
      int nbj = from[bi][bj][len].second;
      len--;
      bi = nbi;
      bj = nbj;
    }
    ull last = 0;
    while (!st.empty()) {
      pair<int, ull> cur = st.top(); st.pop();
      cout << cur.first + 1 << ' ' << cur.second - last << endl;
      last = cur.second;
    }
  } else {
    cout << "NO" << endl;
  }
  //cout << res << endl;
  /*
r(len, 10) {
  ppn(len);
  r(i, 10) {
    r(j, 25) {
      cout << dp[i][j][len] << ' ';
    }
    cout << endl;
  }
  cout << endl;
}
cout << endl;//*/
}

