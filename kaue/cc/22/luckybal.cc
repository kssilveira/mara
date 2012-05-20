// didn't pass

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
 
//using namespace std;
using std::string;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
//typedef vector<int> vi;
//typedef vector<string> vs;

using std::bitset;

string s;

int left[100010], right[100010];
static bitset<100010> memo[3];

bool valid(int b, int e) {
  int si = (e - b) % 3;
  if (b == e) {
    return memo[si][b] = (s[b] == '4');
  }
  if (left[e] - left[b] == (s[e] == '7')) {
    return memo[si][b] = true;
  }
  if (right[b] - right[e] == (s[b] == '4')) {
    return memo[si][b] = true;
  }

  if (s[b] == '7') {
    return memo[si][b] = memo[(si + 2) % 3][b + 1];
  }
  if (s[e] == '4') {
    return memo[si][b] = memo[(si + 2) % 3][b];
  }
  if (b == e + 1) {
    return memo[si][b] = true;
  }
  return memo[si][b] = memo[(si + 1) % 3][b + 1];
}

using std::cin;
using std::cout;
using std::endl;
 
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> s;
    int n = s(s);
    left[0] = 0;
    right[n] = 0;
    rb(i, 1, n) {
      left[i] = left[i - 1] + (s[i - 1] == '4');
    }
    for (int i = n - 1; i >= 0; i--) {
      right[i] = right[i + 1] + (s[i] == '7');
    }
    /*
    cout << s << endl;
    ri {
      cout << left[i] << ' ';
    }
    nl;
    ri {
      cout << right[i] << ' ';
    }
    nl;
    ri {
      if (left[i] == right[i]) {
        res++;
      }
    }
    //*/
    int res = 0;
    /*
    for (int l = 0; l < n; l++) {
      for (int r = l; r < n; r++) {
        int cnt = 0;
        for (int j = l; j <= r; j++) {
          cnt++;
          if (s[j] == '7') cnt -= 2;
          if (cnt < 0) cnt = 0;
          if (cnt > 0) {
            res += n - r;
            r = n;
            break;
          }
        }
      }
    }//*/
    for (int si = 0; si < n; si++) {
      memo[si % 3].reset();
      for (int l = 0; l + si < n; l++) {
        res += valid(l, l + si);
      }
    }

    cout << res << endl;
  }
} 

