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
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<char, int> count;
  ri {
    count[s[i]]++;
  }
  int nmin = -1, ndest = -1;
  for(char dest = '0'; dest <= '9'; dest++) {
    int num = count[dest];
    int cost = 0;
    for (int delta = 1; delta < 10 && num < k; delta++) {
      if (dest + delta <= '9') {
        char ind = dest + delta;
        int cur = min(count[ind], k - num);
        num += cur;
        cost += delta * cur;
      }
      if (dest - delta >= '0') {
        char ind = dest - delta;
        int cur = min(count[ind], k - num);
        num += cur;
        cost += delta * cur;
      }
    }
    if (cost < nmin || nmin == -1) {
      nmin = cost;
      ndest = dest;
    }
  }

  string minres;
  for(char dest = '0'; dest <= '9'; dest++) {
    string res = s;
    int num = count[dest];
    int cost = 0;
    for (int delta = 1; delta < 10 && num < k; delta++) {
      if (dest + delta <= '9') {
        char ind = dest + delta;
        int cur = min(count[ind], k - num);
        num += cur;
        cost += delta * cur;
        int cnt = 0;
        for (int i = 0; cnt < cur; i++) {
          if (s[i] == ind) {
            res[i] = dest;
            cnt++;
          }
        }
      }
      if (dest - delta >= '0') {
        char ind = dest - delta;
        int cur = min(count[ind], k - num);
        num += cur;
        cost += delta * cur;
        int cnt = 0;
        for (int i = s(s) - 1; cnt < cur; i--) {
          if (s[i] == ind) {
            res[i] = dest;
            cnt++;
          }
        }
      }
    }
    if (cost == nmin && (res < minres || minres.empty())) {
      minres = res;
    }
  }
  cout << nmin << endl;
  cout << minres << endl;
} 

