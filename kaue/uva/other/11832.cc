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

const int MAX = 41010;
 
int main() {
  int n, f;
  int v[100], vv[100];
  pair<int, int> vvv[100];
  while (cin >> n >> f && n) {
    ri {
      cin >> vv[i];
      vvv[i] = make_pair(vv[i], i);
    }
    sort(vvv, vvv + n);
    ri {
      v[i] = vvv[i].first;
    }
    int begin = 0, end = 0;
    bitset<MAX + MAX + 1> dp[100];
    ri {
      //ppn(end - begin);
      //dp[2 * i][MAX] = dp[2 * i + 1][MAX] = 1;
      if (i == 0) {
        dp[2 * i][MAX - v[i]] = 1;
        dp[2 * i + 1][MAX + v[i]] = 1;
        begin = MAX - v[i];
        end = MAX + v[i];
        continue;
      }
      for (int j = end; j >= begin; j--) {
        if (dp[2 * i - 1][j] || dp[2 * i - 2][j]) {
          dp[2 * i + 1][j + v[i]] = 1;
          end = max(end, j + v[i]);
        }
      }
      for (int j = begin; j <= end; j++) {
        if (dp[2 * i - 1][j] || dp[2 * i - 2][j]) {
          dp[2 * i][j - v[i]] = 1;
          begin = min(begin, j - v[i]);
        }
      }
    }
    if (!dp[2 * (n - 1)][MAX + f] &&
        !dp[2 * (n - 1) + 1][MAX + f]) {
      cout << "*" << endl;
      continue;
    }

    vi valid[2];
    valid[(n - 1) % 2].push_back(f);
    char sres[50] = {0};
    for (int i = n - 1; i >= 0; i--) {
      valid[(i + 1) % 2].clear();
      bool right = false, left = false;

      /*
      cout << "valid:\n";
      r(k, s(valid[i % 2])) {
        cout << valid[i % 2][k] << " ";
      }
      cout << endl;//*/

      for (int j = 0; j < (int) valid[i % 2].size(); j++) {
        if (valid[i % 2][j] < -MAX ||
            valid[i % 2][j] >  MAX) continue;

        if (dp[2 * i][MAX + valid[i % 2][j]]) {
          left = true;
          valid[(i + 1) % 2].push_back(valid[i % 2][j] + v[i]);
        }
        if (dp[2 * i + 1][MAX + valid[i % 2][j]]) {
          right = true;
          valid[(i + 1) % 2].push_back(valid[i % 2][j] - v[i]);
        }
      }
      if (left && right) {
        sres[vvv[i].second] = '?';
      } else if (left) {
        sres[vvv[i].second] = '-';
      } else {  // right?
        sres[vvv[i].second] = '+';
      }
    }

    /*
    ri {
      ppn(i);
      rb(j, -10, 11) {
        cout << dp[2 * i][MAX + j] << " ";
      }
      cout << endl;
      rb(j, -10, 11) {
        cout << dp[2 * i + 1][MAX + j] << " ";
      }
      cout << endl;
    }
    cout << endl;//*/

    //cout << "bla" << endl;
    cout << sres << endl;
  }
} 

