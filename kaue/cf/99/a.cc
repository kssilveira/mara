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
 
bool is_v(char c) {
  return
    c == 'a' ||
    c == 'e' ||
    c == 'i' ||
    c == 'o' ||
    c == 'u';
}
int main() {
  int N, k;
  cin >> N >> k;
  bool wrong = false;
  string res[] = {"aaaa", "aabb", "abab", "abba"};
  int lastind = 0;
  while(N--) {
    string s[4];
    r(i, 4) {
      cin >> s[i];
      reverse(all(s[i]));
      bool found = false;
      int cnt = 0;
      r(j, s(s[i])) {
        if (is_v(s[i][j])) {
          cnt++;
          if (cnt == k) {
            s[i] = s[i].substr(0, j + 1);
            reverse(all(s[i]));
            found = true;
            break;
          }
        }
      }
      //ppn(s[i]);
      if (!found) {
        wrong = true;
        break;
      }
    }
    int ind = 0;
    if (s[0] == s[1] && s[0] == s[2] && s[0] == s[3]) {
      ind = 0;
    } else if (s[0] == s[1] && s[2] == s[3]) {
      ind = 1;
    } else if (s[0] == s[2] && s[1] == s[3]) {
      ind = 2;
    } else if (s[0] == s[3] && s[1] == s[2]) {
      ind = 3;
    } else {
      wrong = true;
      break;
    }
    if (lastind && ind && ind != lastind) {
      wrong = true;
      break;
    }
    if (ind) 
      lastind = ind;
  }
  if (wrong) {
    cout << "NO" << endl;
  } else {
    cout << res[lastind] << endl;
  }
} 

